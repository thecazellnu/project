. /home/leading/.bash_profile

TODATE=`date +%y%m%d`
PROGRAM_NM=`basename $0`

LOG_PATH=$ITMS_LOG/
LOG_FILE=$LOG_PATH$PROGRAM_NM.log.$TODATE
QRY_FILE=$LOG_PATH$PROGRAM_NM.list

RUN_PATH=$ITMS_BIN
RUN_FILE=itms1001

echo $LOG_FILE

CFG_PATH=$ITMS_CFG/
CFG_FILE=db.cfg

DB_USER=`awk '$1 !~ "#" { print $4 }' $CFG_PATH$CFG_FILE`
DB_PASS=`awk '$1 !~ "#" { print $5 }' $CFG_PATH$CFG_FILE`
DB_CONN=`awk '$1 !~ "#" { print $1 }' $CFG_PATH$CFG_FILE`
DB_NAME=itms

echo [`date +%H:%M:%S`] -----------------SHELL START----------------- >> $LOG_FILE
echo [`date +%H:%M:%S`] $DB_USER $DB_PASS $DB_CONN >> $LOG_FILE
echo [`date +%H:%M:%S`] -----------------SHELL START-----------------
echo [`date +%H:%M:%S`] $DB_USER $DB_PASS $DB_CONN

#=========================================================================
echo [`date +%H:%M:%S`] DELETE TABLE ITMS0110, ITMS0120
echo [`date +%H:%M:%S`] DELETE TABLE ITMS0110, ITMS0120 >> $LOG_FILE
mysql -N -h$DB_CONN  -u$DB_USER -p$DB_PASS $DB_NAME -e "DELETE FROM ITMS0110 WHERE DATE = CURDATE()"
mysql -N -h$DB_CONN  -u$DB_USER -p$DB_PASS $DB_NAME -e "DELETE FROM ITMS0120 WHERE DATE = CURDATE()"

echo [`date +%H:%M:%S`] DELETE DONE >> $LOG_FILE
echo [`date +%H:%M:%S`] DELETE DONE

LIST=`mysql -N -h$DB_CONN  -u$DB_USER -p$DB_PASS $DB_NAME -e \
"
SELECT  FUND_CD,      \
        USER_ID,      \
        USER_BRCHNO   \
FROM    ITMS0100      \
WHERE   USE_YN='Y'    \
"`

cd $RUN_PATH
echo $LIST 

CNT=0
for RD in $LIST
do
	CNT=$((CNT+1))
	case ${CNT} in 
	1)
		FUNDCD=$RD	
		;;
	2)
		USERID=$RD	
		;;
	3)
		BRCHNO=$RD	
		echo [`date +%H:%M:%S`] RUN  : [$RUN_FILE $FUNDCD $BRCHNO $USERID] >> $LOG_FILE
		echo [`date +%H:%M:%S`] RUN  : [$RUN_FILE $FUNDCD $BRCHNO $USERID]
		$RUN_FILE $FUNDCD $BRCHNO $USERID
		echo [`date +%H:%M:%S`] DONE >> $LOG_FILE
		echo [`date +%H:%M:%S`] DONE

		CNT=0
		;;
	esac
done
