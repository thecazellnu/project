###############################################################
# Makefile
###############################################################
_OSTYPE_		= 

OLDNAME			= _`date '+%Y%m%d_%H%M%S'`

PROC			= proc
CC				= g++

PRJ_INC_DIR  	= $(CPRJ_HOME)/inc
PRJ_SRC_DIR  	= $(CPRJ_HOME)/src
PRJ_LINC_DIR  	= $(PRJ_SRC_DIR)/libsrc

TEST_NAME		= testcli
CRON_NAME		= cron
LIB_NAME		= libcazellnu.a

BINDIR			= $(CPRJ_HOME)/bin
LIBDIR			= $(CPRJ_HOME)/lib

LIBNAME			= $(LIBDIR)/$(LIB_NAME)

TEST_PCSRC		= test.pc
TEST_PC2CC		= $(TEST_PCSRC:.pc=.cc)
TEST_SRC		= $(TEST_PC2CC) 
TEST_OBJS		= $(TEST_SRC:.cc=.o)

CRON_PCSRC		= cron.pc
CRON_PC2CC		= $(CRON_PCSRC:.pc=.cc)
CRON_SRC		= $(CRON_PC2CC) 
CRON_OBJS		= $(CRON_SRC:.cc=.o)

LIB_PCSRC		= 
LIB_PC2CC		= $(LIB_PCSRC:.pc=.cc)
LIB_SRC			= $(LIB_PC2CC) socklib.cc log.cc common.cc
LIB_OBJS		= $(LIB_SRC:.cc=.o)

SYSTEM_INCL		=
LOCAL_INCL		=	-I $(PRJ_INC_DIR) -I $(PRJ_LINC_DIR)
RDB_INCL        =	-I $(ORACLE_INCLUDE)
INCLUDE			= $(SYSTEM_INCL) $(RDB_INCL) $(LOCAL_INCL)

SYSTEM_LIB_PATH =
COMMON_LIB_PATH = -L$(LIBDIR)
RDB_LIB_PATH    = -L$(ORACLE_HOME)
LIB_PATH        = $(SYSTEM_LIB_PATH) $(COMMON_LIB_PATH) $(RDB_LIB_PATH)

OSF1_LIBLIST    = -pthread
LINUX_LIBLIST	= -lpthread -lm -ldl
#LINUX_LIBLIST	= -lpthread -lnsl -lm -ldl
HPUX_LIBLIST	= -lpthread -lnsl -lm 
SOLARIS_LIBLIST	= -lnsl -lpthread -lm -ldl 
AIX_LIBLIST		= -lnsl -lpthread -lm -ldl 
AIX_4_2_LIBLIST	= -lnsl -lpthreads  -lm -ldl 
AIX_5_LIBLIST	= -lnsl -lpthreads  -lm -ldl -lC
FREEBSD_LIBLIST	= -lc_r

SYSTEM_LIBS     = 
COMMON_LIBS     = -lcazellnu
RDB_LIBS        = -lclntsh
LIBS            = $(SYSTEM_LIBS) $(COMMON_LIBS) $(LINUX_LIBLIST) $(RDB_LIBS)

CFLAGS          = -c -g -D_REENTRANT $(INCLUDE)
PROCFLAGS       = sqlcheck=full userid=$(DBUSR)/$(DBPSWD)@$(DBTNS) \
				  CHAR_MAP=STRING CODE=CPP CPP_SUFFIX=cc \
				  SYS_INCLUDE=/usr/include \
				  include=$(ORACLE_INCLUDE) \
                  include=$(PRJ_INC_DIR)	\
                  include=$(PRJ_LINC_DIR)	\
                  include=$(PRJ_SRC_DIR)

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
	rm -f core *.out *.lis *.ln

test : test.o
	$(CC) -o $(TEST_NAME) $(TEST_OBJS) $(LIB_PATH) $(LIBS)
	strip $(TEST_NAME)
	rm -rf *.o core *.lis $(TEST_PC2CC)
	mv $(TEST_NAME) $(BINDIR)

cron : cron.o
	$(CC) -o $(CRON_NAME) $(CRON_OBJS) $(LIB_PATH) $(LIBS)
	strip $(CRON_NAME)
	rm -rf *.o core *.lis $(CRON_PC2CC)
	mv $(CRON_NAME) $(BINDIR)

clean:
	rm -f *.o core *.lis $(TEST_PC2CC) $(CRON_PC2CC)
