#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>
#include <errno.h>

#include "dsamdef.h"

#define PERM 0666

int record_lock(int fd)
{
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_start = 0;
	lock.l_whence = SEEK_SET;
	lock.l_len = 1;
	return fcntl(fd, F_SETLKW, &lock);
}

int record_unlock(int fd)
{
	struct flock lock;
	lock.l_type = F_UNLCK;
	lock.l_start = 0;
	lock.l_whence = SEEK_SET;
	lock.l_len = 1;
	return fcntl(fd, F_SETLK, &lock);
}

DSAM_HANDLE dsam_init(int id, char *name)
{
	DSAM_HANDLE dHandle;
	
	dHandle = (DSAM_HANDLE)calloc(1, sizeof(struct _DSAM_HANDLE));	
	if (dHandle == NULL) return NULL;

	dHandle->id = id;
	memcpy(dHandle->name, name, strlen(name));
	dHandle->fd = -1;
	/*
	memset(&(dHandle->sbuf), 0x00, sizeof(struct stat));
	*/
	dHandle->fmp = NULL;

	return dHandle;
}

void dsam_destroy(DSAM_HANDLE dHandle)
{
	if (dHandle) 
	{
		if (dHandle->fd > 0) dsam_close(dHandle);
		//if (dHandle->fmp) free(dHandle->fmp);
		free(dHandle);
	}
}

int dsam_create(DSAM_HANDLE dHandle, int keylen, int reclen, int recnt)
{
	struct tm *tp;
	time_t tvalue;
	fhead  head;
	findex index;
	char   buff[1024];
	int    frtn;
	int    indexsize=0;
	int    indexblocksize=0;
	int    intsize;
	int    fd;
	int    rtn;
	int empty;

	fd = open(dHandle->name, O_RDWR|O_CREAT|O_EXCL, PERM);
	if (fd <= 0) 
	{
		printf(" file create error\n"); return -1;
	}

	record_lock(fd);

	time(&tvalue);
	tp=localtime(&tvalue);
	if(tp != NULL) 
	{
		sprintf(buff, "%04d%02d%02d",
			tp->tm_year+1900, tp->tm_mon+1, tp->tm_mday);
	}

	intsize = sizeof(int);
	keylen = (keylen%intsize == 0) ? keylen : keylen+(intsize-keylen%intsize);
	indexblocksize = (sizeof(index)-intsize) + keylen;
	indexsize = ((sizeof(index)-intsize) + keylen) * recnt;

	memcpy(head.date, buff, 8);
	head.indexsize       = indexsize;
	head.indexblocksize  = indexblocksize;
	head.lmtreclen       = reclen;
	head.indexmaxcnt     = recnt;
	head.indexcurrcnt    = 0;
	head.indexlastoffset = sizeof(head);
	head.datastartoffset = indexsize+sizeof(head);

	rtn = write(fd, (char *)&head, sizeof(head));

	if (rtn != sizeof(head)) 
	{
		printf("head write errno[%d]\n", errno);
		record_unlock(fd);
		close(fd); return -1;
	}

	/*
	if (lseek(fd, sizeof(head), SEEK_SET) == -1) 
	{
		printf("head seek_set errno[%d]\n", errno);
		record_unlock(fd);
		close(fd);
	}
	*/

	memset(buff, 0x00, sizeof(buff));

	int i;
	i = indexsize;
	while(i >= sizeof(buff))
	{
		rtn = write(fd, buff, sizeof(buff));
		if (rtn <= 0) 
		{
			printf("A fwrite error[%d]\n", errno);
			record_unlock(fd);
			close(fd); return -1;
		}
		i -= sizeof(buff);
	}

	//if(indexsize > 0) 
	if(i > 0) 
	{
		rtn = write(fd, buff, indexsize%sizeof(buff));
		if (rtn <= 0) 
		{
			printf("B fwrite error[%d]\n", errno);
			record_unlock(fd);
			close(fd); return -1;
		}
	}	
	buff[0] = '\n';
	write(fd, buff, 1);
	record_unlock(fd);
	close(fd);

	return 1;
}

int dsam_remove(char *name)
{
	if (unlink(name) == 0) return 1;
	else return -1;
}

int dsam_getfileinfo(char *name, struct stat *sbuf)
{
	if (stat(name, sbuf) < 0) 
	{
		return -1 * errno;
	}

	return 1;
}

int dsam_getinfo(char *name, fhead *hp)
{
	int fd;
	int rtn;

	fd = open(name, O_RDONLY);
	if (fd <= 0) 
	{
		printf("open error[%d]\n", errno);
		close(fd);
	}

	rtn = read(fd, (char *)hp, sizeof(fhead));
	if (rtn <= 0) 
	{
		printf("read errno[%d]\n", errno);
		return -1;
	}

	close(fd);

	return sizeof(fhead);
}

int dsam_malloc(char *name, char *p)
{
	struct stat sbuf;

	if (stat(name, &sbuf) < 0) 
	{
		return -1 * errno;
	}

	p = (char *)malloc(sbuf.st_size);
	if (p == NULL) return -1;

	return sbuf.st_size;
}

int dsam_realloc(int fd, char *p)
{
	struct stat sbuf;

	if (fstat(fd, &sbuf) < 0) 
	{
		return -1 * errno;
	}

//	p = (char *)realloc(p, sbuf.st_size);
	p = (char *)malloc(sbuf.st_size);
	if (p == NULL) return -1;

	return sbuf.st_size;
}

void dsam_free(char *p)
{
	if (p != NULL) free(p);
}

int dsam_open(DSAM_HANDLE dHandle, int flag)
{
	struct stat  sbuf;
	char        *p;
	int          fd;
	int          fileflag, memflag;
	int          size;

	if (dHandle->fd != -1) 
	   return 300;

	switch (flag)
   	{
		case DSAM_RDONLY:
			fileflag = O_RDONLY;
			memflag  = PROT_READ;
			break;
		case DSAM_RDWT:
			fileflag = O_RDWR;
			memflag  = PROT_READ|PROT_WRITE;
			break;
		case DSAM_RWA:
			fileflag =  O_RDWR|O_APPEND;
			memflag  = PROT_READ|PROT_WRITE;
			break;
		default:
			printf("flag error[Open]\n");
			return -1;
	}

	fd = open(dHandle->name, fileflag);

	if (fd <= 0) 
	{
		printf("open error[%d]\n", errno);
		close(fd);
	}

	if (stat(dHandle->name, &(dHandle->sbuf)) < 0) 
	{
		return -1 * errno;
	}

//	p = (char *)malloc(dHandle->sbuf.st_size);
//	if (p == NULL) return -1;

	p = (char *)mmap(0, dHandle->sbuf.st_size, memflag, MAP_SHARED,
		   			    fd, (off_t)0);

	if (p == MAP_FAILED) 
	{
		close(fd);		
		return -1;
	}
	
	dHandle->fd = fd;
	dHandle->fmp = p;

	return fd;
}

int dsam_close(DSAM_HANDLE dHandle)
{
	munmap((char *)dHandle->fmp, dHandle->sbuf.st_size);
	close(dHandle->fd);
	dHandle->fd = -1;
    dHandle->fmp = NULL;
	return 1;
}

int dsam_remapping(DSAM_HANDLE dHandle, int flag)
{
	struct stat sbuf;
	char        *mp;
	int          memflag;
	int          nsize;

	switch (flag)
   	{
		case DSAM_RDONLY: /* 1 */
			memflag  = PROT_READ;
			break;

		case DSAM_RDWT:   /* 2 */
			memflag  = PROT_READ|PROT_WRITE;
			break;

		default:
			printf("flag error[Remapping]\n");
			return -1;
	}

	munmap((char *)dHandle->fmp, dHandle->sbuf.st_size);

	if (fstat(dHandle->fd, &(dHandle->sbuf)) < 0) 
	{
		return -1 * errno;
	}

	//dHandle->fmp = (char *)realloc(dHandle->fmp, dHandle->sbuf.st_size);
/*
	dHandle->sbuf.st_size = dsam_realloc(dHandle->fd,(char *)dHandle->fmp);

	if (dHandle->fmp == NULL) return -1;
*/

	dHandle->fmp = mmap(0, dHandle->sbuf.st_size, memflag,
		   						    MAP_SHARED, dHandle->fd, (off_t)0);
	if (dHandle->fmp == MAP_FAILED) 
	{
		close(dHandle->fd);		
		return -1;
	}

	return dHandle->fd;
}

int dsam_read(DSAM_HANDLE dHandle, char *key, int keylen, int flag,
	   		      char *data, char *outkey)
{
	fhead   *head;
	findex  *sindex, kindex;
	char    *pidx, *pdata, *p;
	int      rtn;
	int      spos, lpos, cpos, bsize;

	if (dHandle == NULL) return -1;

	p     = (char *)dHandle->fmp;
	head  = (fhead *)p;
	pidx  = p+sizeof(fhead);

	spos  = 0;
	lpos  = head->indexcurrcnt;
	bsize = head->indexblocksize;

	while(1) 
	{
		cpos = (spos + lpos)/2;

		sindex = (findex *)(pidx+bsize*cpos);
		rtn = memcmp(sindex->key, key, keylen);

		if(lpos - spos < 2) break;

		if (rtn == 0) break;
		else if(rtn > 0) 
			lpos = cpos;
		else spos = cpos;
		
	}

	sindex = NULL;
	switch(flag)
	{
		case LT:
			if(cpos > 0)
			{
				if(rtn) sindex = (findex *)(pidx+bsize*cpos);
				else sindex = (findex *)(pidx+bsize*(cpos - 1));
			}
			else
			{
				if(rtn < 0) sindex = (findex *)(pidx+bsize*cpos);
			}
			break;

		case EQ:
			if(rtn) return -100;
			sindex = (findex *)(pidx+bsize*cpos);
			break;

		case GT:
			if(lpos < head->indexcurrcnt)
			{
				if(rtn) 
				{
					if(cpos > 0) sindex = (findex *)(pidx+bsize*lpos);
					else         sindex = (findex *)(pidx+bsize*cpos);
				}

				else sindex = (findex *)(pidx+bsize*(lpos + 1));
			}
			else
			{
				if(rtn > 0) sindex = (findex *)(pidx+bsize*lpos);
			}
			break;
	}

	if(sindex == NULL)  return -100;

	pdata = p + sindex->recoffset;
	memcpy(data, pdata, sindex->reclen);
	memcpy(outkey, sindex->key, sindex->keylen);

	return sindex->reclen;
}

int dsam_indexcomp(const void *x, const void *y)
{
	findex   *px;
	findex   *py;

	px = (findex *)x;
	py = (findex *)y;

	return (memcmp(px->key, py->key, py->keylen));
}

int dsam_write(DSAM_HANDLE dHandle, char *key, int keylen,
		char *data, int datalen)
{
	struct stat  sbuf;
	fhead       *head;
	findex      *sindex, kindex;
	char        *pidx, *spidx;
	off_t        offset;
	int          rtn;
	int			empty, i;

	record_lock(dHandle->fd);

	memcpy(kindex.key, key, keylen);

	head = (fhead *)(dHandle->fmp);
	spidx = (char *)(dHandle->fmp)+sizeof(fhead);

	sindex = (findex *)bsearch((const void *)&kindex, spidx, head->indexcurrcnt,
		   					   head->indexblocksize, dsam_indexcomp);
	if (sindex != NULL)
	{
		record_unlock(dHandle->fd); 
		return -100;
	}

	if (head->indexmaxcnt < head->indexcurrcnt + 1) 
	{
		record_unlock(dHandle->fd); 
		return -1;
	}

	if (fstat(dHandle->fd, &(dHandle->sbuf)) < 0) 
	{
		record_unlock(dHandle->fd); 
		return -1;
	}

	if(head->lmtreclen < datalen)
	{
		printf("data length overflow limit[%d] data[%d]\n", 
			head->lmtreclen, datalen);
		record_unlock(dHandle->fd); 
		return -1;
	}
	else empty = head->lmtreclen - datalen;


	if ((offset=lseek(dHandle->fd, dHandle->sbuf.st_size, SEEK_SET)) == -1) 
	{
		printf("head seek_set errno[%d]\n", errno);
		record_unlock(dHandle->fd); 
		return -1;
	}

	rtn = write(dHandle->fd, data, datalen);
	if (rtn != datalen) 
	{
		printf("data write errno[%d]\n", errno);
		record_unlock(dHandle->fd);
		return -1;
	}

	if(empty)
	{
		for(i=0 ; i<empty; i++)
		{
			if(write(dHandle->fd, " ", 1) != 1)
			{
				printf("empty write errno[%d] cnt[%d]\n", errno, i);
				record_unlock(dHandle->fd);
				return -1;
			}
		}
	}

	rtn = write(dHandle->fd, "\n", 1);
	if (rtn != 1) 
	{
		printf("개행 write 오류\n");
		record_unlock(dHandle->fd); return -1;
	}
		
	pidx = (char *)dHandle->fmp + head->indexlastoffset;
	((findex *)pidx)->keylen = keylen;
	((findex *)pidx)->recoffset = offset;
	((findex *)pidx)->reclen = datalen;
	memcpy(((findex *)pidx)->key, key, keylen);

	head->indexcurrcnt++;
	head->indexlastoffset += head->indexblocksize;

	qsort(spidx, head->indexcurrcnt, head->indexblocksize, dsam_indexcomp);

	dsam_remapping(dHandle, DSAM_RDWT);

	//rtn = msync(pidx, head->indexblocksize, MS_SYNC); 
	rtn = msync((char *)dHandle->fmp, head->indexlastoffset, MS_SYNC); 
	if (rtn < 0)
	{
		printf("msync error[%d] msyncRtnValue[%d]\n", errno,rtn);
		record_unlock(dHandle->fd);
		return -1;
	}

	record_unlock(dHandle->fd);

	return 1;
}

int dsam_update(DSAM_HANDLE dHandle, char *key, int keylen,
		char *data, int datalen)
{
	int empty;
	fhead  *head;
	findex *sindex, kindex;
	char   *pidx, *pdata, *p;

	record_lock(dHandle->fd);

	memcpy(kindex.key, key, keylen);

	p = (char *)dHandle->fmp;
	head = (fhead *)p;
	pidx = p+sizeof(fhead);

	sindex = (findex *)bsearch((const void *)&kindex, pidx, head->indexcurrcnt,
		   					   head->indexblocksize, dsam_indexcomp);
	if (sindex == NULL)
		return -200;

	pdata = p + sindex->recoffset;

	if(datalen > head->lmtreclen)
	{
		printf("DataLength Error lmt[%d] in[%d]\n", head->lmtreclen, datalen);
		record_unlock(dHandle->fd);
		return -1;
	}

	empty = head->lmtreclen - datalen;

	memcpy(pdata, data, datalen);
	if(empty) memset(pdata + datalen, 0x20, empty);
	sindex->reclen = datalen;
	record_unlock(dHandle->fd);

	return 1;
}
