#!/bin/sh
TODATE=`date +%y%m%d`
NAS_DOMAIN=cazellnu.iptime.org
FTP_PORT=7021
NAS_USER=cazellnu
NAS_PASS=rhshakak
NAS_PATH=/DATA/10.Cazellnu/Job/current
BAK_PATH=$HOME/back

FILE_NM=$1_20$TODATE

tar cvf $HOME/back/$FILE_NM.tar /prj/$1
gzip $HOME/back/$FILE_NM.tar

echo "Backup $TODATE.."

ftp -i -n -v << [EOF]
    open $NAS_DOMAIN $FTP_PORT
    user $NAS_USER $NAS_PASS
    lcd  $BAK_PATH
    cd   $NAS_PATH
    bi
    put  $FILE_NM.tar.gz
    close
    bye
[EOF]
echo "Send FTP OK $TODATE.."
