SHELL=/usr/bash
. $HOME/.bash_profile

TODATE=`date +%y%m%d`
PGMNM=`basename $0`

CFG_PATH=$ITMS_HOME/cfg/
CFG_FILE=db.cfg

#echo $CFG_PATH$CFG_FILE

export DB_IP=`awk '$1 !~ "#" { print $1 }' $CFG_PATH$CFG_FILE`
export DB_PORT=`awk '$1 !~ "#" { print $2 }' $CFG_PATH$CFG_FILE`
export DB_SOCK=`awk '$1 !~ "#" { print $3 }' $CFG_PATH$CFG_FILE`
export DB_USER=`awk '$1 !~ "#" { print $4 }' $CFG_PATH$CFG_FILE`
export DB_PASS=`awk '$1 !~ "#" { print $5 }' $CFG_PATH$CFG_FILE`

#echo $DB_IP $DB_PORT $DB_SOCK $DB_USER $DB_PASS
