#ifndef   __DSAMDEF_H__
#define   __DSAMDEF_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define DSAM_RDONLY 1 
/* Open for reading only. */

#define DSAM_RDWT   2 
/* Open for reading and writing.                               *
 * The result is  undefined if this flag is applied to a FIFO. */

#define DSAM_RWA    3 

#define LT          1
#define LE          2
#define EQ          3
#define GE          4
#define GT          5

typedef struct {
	char   date[8];
	int    indexsize;
	int    indexblocksize;
	int    lmtreclen;
	int    indexmaxcnt;
	int    indexcurrcnt;
	off_t  indexlastoffset;
	off_t  datastartoffset;
} fhead;

typedef struct {
	int    keylen;
	off_t  recoffset;
	int    reclen;
	char   key[1];
} findex;

struct _DSAM_HANDLE {
	int               id;
	char              name[512];
	int               fd;
	struct stat       sbuf;
	void             *fmp;
};
typedef struct _DSAM_HANDLE* DSAM_HANDLE;

int record_lock(int);
int record_unlock(int);
DSAM_HANDLE dsam_init(int, char *);
void dsam_destroy(DSAM_HANDLE);
int dsam_create(DSAM_HANDLE, int, int, int);
int dsam_remove(char *);
int dsam_getfileinfo(char *, struct stat *);
int dsam_getinfo(char *, fhead *);
int dsam_malloc(char *, char *);
int dsam_realloc(int, char *);
void dsam_free(char *);
int dsam_open(DSAM_HANDLE, int);
int dsam_close(DSAM_HANDLE);
int dsam_remapping(DSAM_HANDLE, int);
int dsam_read(DSAM_HANDLE, char *, int, int, char *, char *);
int dsam_indexcomp(const void *, const void *);
int dsam_write(DSAM_HANDLE, char *, int, char *, int);
int dsam_update(DSAM_HANDLE, char *, int, char *, int);














#endif
