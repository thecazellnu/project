# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# User specific environment
PATH="$HOME/.local/bin:$HOME/bin:$PATH"
export PATH

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=

# User specific aliases and functions
ulimit -c unlimited >/dev/null 2>&1

export LANG=ko_KR.euckr
export DBUSR=DEVUSR
export DBPSWD=DEVUSR
export DBTNS=ORCL

export PRJ_HOME=/prj

export MDB_HOME=${PRJ_HOME}/marialib

export CPRJ_HOME=${PRJ_HOME}/cprj
export CPRJ_INC=${CPRJ_HOME}/inc

export ITMS_HOME=${PRJ_HOME}/itms
export ITMS_INC=${ITMS_HOME}/inc

export DEV_LOG_PATH=${CPRJ_HOME}/log

alias prj='cd ${PRJ_HOME}'
alias shl='cd ${PRJ_HOME}/shl'
alias ref='cd ${PRJ_HOME}/ref'

alias cprj='cd ${CPRJ_HOME}'
alias cbin='cd ${CPRJ_HOME}/bin'
alias csrc='cd ${CPRJ_HOME}/src'
alias clibsrc='cd ${CPRJ_HOME}/src/libsrc'
alias cinc='cd ${CPRJ_HOME}/inc'
alias clog='cd ${CPRJ_HOME}/log'
alias cshl='cd ${CPRJ_HOME}/shl'
alias csql='cd ${CPRJ_HOME}/sql'

alias itms='cd ${ITMS_HOME}'

alias sqlp='sqlplus ${DBUSR}/${DBPSWD}@${DBTNS}'
