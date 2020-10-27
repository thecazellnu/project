#!/bin/sh
TODATE=`date +%y%m%d`
LOG_DIR=$CPRJ_HOME/log
LOG_FILE=$LOG_DIR/shell
echo [`date +%H:%M:%S`] "START TEST SHELL [$1]" >> $LOG_FILE.'20'$TODATE
sleep 60
echo [`date +%H:%M:%S`] "STEP A[$1]" >> $LOG_FILE.'20'$TODATE
sleep 60
echo [`date +%H:%M:%S`] "STEP B[$1]" >> $LOG_FILE.'20'$TODATE
sleep 60
echo [`date +%H:%M:%S`] "END TEST SHELL [$1]" >> $LOG_FILE.'20'$TODATE
