. /home/leading/.bash_profile

TODATE=`date +%y%m%d`
PROGRAM_NM=`basename $0`

BF1WDATE=`date +%y%m%d -d '1week ago'`

LOG_PATH=$ITMS_LOG/
LOG_BAK_PATH=$ITMS_LOG/backup
LOG_FILE=$LOG_PATH$PROGRAM_NM.log.$TODATE

echo [`date +%H:%M:%S`] -----------------SHELL START----------------- >> $LOG_FILE

cd $LOG_PATH
LOG_CNT=`ls *$BF1WDATE | wc -l`

echo [`date +%H:%M:%S`] [$BF1WDATE] LOG FILE COUNT [$LOG_CNT] >> $LOG_FILE

if [ ${LOG_CNT} -eq 0 ] ;
then 
	echo [`date +%H:%M:%S`] Log file not found  >> $LOG_FILE
else
	tar cvf $LOG_BAK_PATH/log_$BF1WDATE.tar *$BF1WDATE
	gzip $LOG_BAK_PATH/log_$BF1WDATE.tar
	echo [`date +%H:%M:%S`] log backup done [$BF1WDATE] >> $LOG_FILE

	rm -rf *$BF1WDATE
	rm -rf $LOG_BAK_PATH/log_$BF1WDATE.tar
	echo [`date +%H:%M:%S`] delete log [$BF1WDATE] >> $LOG_FILE
fi 

echo [`date +%H:%M:%S`] -----------------SHELL END----------------- >> $LOG_FILE
