###############################################################
# Makefile
###############################################################
_OSTYPE_		= 

OLDNAME			= _`date '+%Y%m%d_%H%M%S'`

PROC			= proc
CC				= g++

PRJ_HOME   		= $(ITMS_HOME)
PRJ_INC_DIR		= $(PRJ_HOME)/inc

LIB_NAME		= libitms.a
LIB_SRC_DIR 	= $(PRJ_HOME)/libsc

BINDIR			= $(PRJ_HOME)/bin
LIBDIR			= $(PRJ_HOME)/lib

LIBNAME			= $(LIBDIR)/$(LIB_NAME)

LIB_PCSRC		= 
LIB_PC2CC		= $(LIB_PCSRC:.pc=.cc)
LIB_SRC			= $(LIB_PC2CC) socklib.cc log.cc common.cc
LIB_OBJS		= $(LIB_SRC:.cc=.o)

SYSTEM_INCL		=
LOCAL_INCL		=	-I $(PRJ_INC_DIR)
RDB_INCL        =	-I $(MDB_HOME)include/mariadb \
					-I $(MDB_HOME)include/mariadb/mysql 
#RDB_INCL        =	-I $(ORACLE_HOME)/precomp/public \
					-I $(ORACLE_HOME)/rdbms/public   \
					-I $(ORACLE_HOME)/rdbms/demo     \
					-I $(ORACLE_HOME)/plsql/public   \
					-I $(ORACLE_HOME)/network/public 
INCLUDE			= $(SYSTEM_INCL) $(LOCAL_INCL) $(RDB_INCL)

SYSTEM_LIB_PATH =
COMMON_LIB_PATH = -L$(LIBDIR)
#RDB_LIB_PATH    = -L$(ORACLE_HOME)/lib
RDB_LIB_PATH    = -L$(MDB_HOME)lib/mariadb
LIB_PATH        = $(SYSTEM_LIB_PATH) $(COMMON_LIB_PATH) $(RDB_LIB_PATH)

OSF1_LIBLIST    = -pthread
LINUX_LIBLIST	= -lpthread -lnsl -lm -ldl
HPUX_LIBLIST	= -lpthread -lnsl -lm 
SOLARIS_LIBLIST	= -lnsl -lpthread -lm -ldl 
AIX_LIBLIST		= -lnsl -lpthread -lm -ldl 
AIX_4_2_LIBLIST	= -lnsl -lpthreads  -lm -ldl 
AIX_5_LIBLIST	= -lnsl -lpthreads  -lm -ldl -lC
FREEBSD_LIBLIST	= -lc_r

SYSTEM_LIBS     = 
COMMON_LIBS     = -litms
#RDB_LIBS        = -lclntsh
RDB_LIBS        = -lmariadb
LIBS            = $(SYSTEM_LIBS) $(COMMON_LIBS) $(LINUX_LIBLIST) $(RDB_LIBS)

CFLAGS          = -c -g -D_REENTRANT $(INCLUDE)
PROCFLAGS       = sqlcheck=full userid=$(DBUSR)/$(DBPSWD)@$(DBTNS) \
				  CHAR_MAP=STRING CODE=CPP CPP_SUFFIX=cc \
				  SYS_INCLUDE=/usr/include \
				  include=$(ORACLE_HOME)/precomp/public \
				  include=$(ORACLE_HOME)/rdbms/public   \
				  include=$(ORACLE_HOME)/rdbms/demo     \
				  include=$(ORACLE_HOME)/plsql/include  \
                  include=$(PRJ_INC_DIR) \
                  include=$(LIB_SRC_DIR)

.SUFFIXES : .c .o .pc .cc
.pc.cc  :
	$(PROC) $(PROCFLAGS) iname=$*
.pc.o   :
	$(PROC) $(PROCFLAGS) iname=$*
	$(CC) $(CFLAGS) $*.cc
.cc.o   :
	$(CC) $(CFLAGS) $*.cc
.c.o    :
	$(CC) $(CFLAGS) $*.c

lib : $(LIB_OBJS)
	ar rc $(LIBNAME) $(LIB_OBJS)
	rm -f core *.out *.lis *.ln *.o

clean:
	rm -f *.o core *.lis $(LIB_PC2CC) 
