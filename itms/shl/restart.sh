. /home/leading/.bash_profile

TODATE=`date +%y%m%d`
PROGRAM_NM=`basename $0`

LOG_PATH=$ITMS_LOG/
LOCK_FILE=$LOG_PATH$PROGRAM_NM.$TODATE
LOG_FILE=$LOG_PATH$PROGRAM_NM.log.$TODATE

RUN_PATH=$ITMS_BIN
RUN_FILE=$1

echo $LOG_FILE

if [ -z $1 ]; then
	echo usage : restart.sh [PSNAME] 
	exit
fi

#if [ -e $LOCK_FILE ]; then
#	echo Duplicate Execution
#	exit
#else
#	echo `date` >> $LOCK_FILE
#	echo Shell Lock
#fi

echo [`date +%H:%M:%S`] -----------------SHELL START----------------- >> $LOG_FILE
echo [`date +%H:%M:%S`] `ps -ef | grep "leading" | grep -vE 'tail|'$0'|vi|grep|ksh|make|client|proc' | grep $1` >>  $LOG_FILE

pid=`ps -ef | grep "leading" | grep -vE 'tail|'$0'|vi|grep|ksh|make|client|proc' | grep $1 | awk '{print $2}'`

echo [`date +%H:%M:%S`] $1 pid : $pid >> $LOG_FILE

if [ -z $pid ]; then
	echo [`date +%H:%M:%S`] Execute $1 >> $LOG_FILE
	echo [`date +%H:%M:%S`] cd $RUN_PATH >> $LOG_FILE
	cd $RUN_PATH
	echo [`date +%H:%M:%S`] $RUN_FILE >> $LOG_FILE
	$RUN_FILE
else
	echo [`date +%H:%M:%S`] Kill $1 pid : $pid >> $LOG_FILE
	kill -15 $pid
	echo [`date +%H:%M:%S`] sleep10 >> $LOG_FILE
	sleep 10

	pid=`ps -ef | grep "leading" | grep -vE 'tail|'$0'|vi|grep|ksh|make|client|proc' | grep $1 | awk '{print $2}'`
	if [ -z $pid ]; then
		echo [`date +%H:%M:%S`] Execute $1 >> $LOG_FILE
		echo [`date +%H:%M:%S`] cd $RUN_PATH >> $LOG_FILE
		cd $RUN_PATH
		echo [`date +%H:%M:%S`] $RUN_FILE >> $LOG_FILE
		$RUN_FILE
	else
		echo [`date +%H:%M:%S`] Kill Failed $1 pid : $pid >> $LOG_FILE
	fi
fi

echo [`date +%H:%M:%S`] -----------------SHELL END ----------------- >> $LOG_FILE

#rm -rf $LOCK_FILE
