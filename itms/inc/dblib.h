#ifndef __DBLIB_H__
#define __DBLIB_H__

int MDBConnect();
int MDBQuery(char *);
int MDBClose();
int MDBCommit();
int MDBRollback();

#endif
