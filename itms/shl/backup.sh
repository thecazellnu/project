SHELL=/usr/bash
. $HOME/.bash_profile

TODATE=`date +%y%m%d`
PGMNM=`basename $0`

tar cvf $HOME/backup/itms_$TODATE.tar $ITMS_HOME
gzip $HOME/backup/itms_$TODATE.tar

echo "Backup Done.. $HOME/backup/itms_$TODATE.tar"

