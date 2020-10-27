###############################################################
# Makefile
###############################################################
_OSTYPE_		= 

OLDNAME			= _`date '+%Y%m%d_%H%M%S'`

PROC			= proc
CC				= g++

PRJ_HOME   		= $(ITMS_HOME)
PRJ_INC_DIR		= $(PRJ_HOME)/inc

FEPCLI			= fepcli

BINDIR			= $(PRJ_HOME)/bin
LIBDIR			= $(PRJ_HOME)/lib

LIBNAME			= $(LIBDIR)/$(LIB_NAME)

PCSRC			= 
PC2CC			= $(PCSRC:.pc=.cc)
SRC				= $(PC2CC) fepcli.cc
OBJS			= $(SRC:.cc=.o)

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

SYSTEM_LIBS     = -lstdc++
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

fepcli : $(OBJS)
	$(CC) -o $(FEPCLI) $(OBJS) $(LIB_PATH) $(LIBS)
	strip $(FEPCLI)
	rm -rf *.o core *.lis $(PC2CC)
	mv $(FEPCLI) $(BINDIR)
clean:
	rm -f *.o core *.lis $(PC2CC) 
