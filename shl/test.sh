#!/bin/sh
TODATE=`date +%y%m%d`
LOG_DIR=/prj/log
echo [`date +%H:%M:%S`] "START TEST SHELL [$1]" >> /prj/log/shell.'20'$TODATE
sleep 60
echo [`date +%H:%M:%S`] "STEP A[$1]" >> /prj/log/shell.'20'$TODATE
sleep 60
echo [`date +%H:%M:%S`] "STEP B[$1]" >> /prj/log/shell.'20'$TODATE
sleep 60
echo [`date +%H:%M:%S`] "END TEST SHELL [$1]" >> /prj/log/shell.'20'$TODATE
