#ifndef __SEQFILE_H__
#define __SEQFILE_H__

int InitialSeqFile(char *, int);
long GetCurSeq(char *, int);
long GetNextSeq(char *, int);
long WriteSeqno(char *, int, long);

#endif
