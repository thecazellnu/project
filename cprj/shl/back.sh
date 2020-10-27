#!/bin/sh
TODATE=`date +%y%m%d`
NAS_DOMAIN=cazellnu.ipdisk.co.kr
NAS_USER=cazellnu
NAS_PASS=rhshakak
NAS_PATH=/VOL1/10.Cazellnu/Job/current
BAK_PATH=$HOME/back

tar cvf $HOME/back/prj_$TODATE.tar /prj
gzip $HOME/back/prj_$TODATE.tar
echo "Backup $TODATE.."

ftp -i -n -v << [EOF]
    open $NAS_DOMAIN
    user $NAS_USER $NAS_PASS
    lcd  $BAK_PATH
    cd   $NAS_PATH
    bi
    put  prj_$TODATE.tar.gz
    close
    bye
[EOF]
echo "Send FTP OK $TODATE.."
