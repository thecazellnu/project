CREATE TABLESPACE DEV_DAT
DATAFILE '/home/oracle/base/oradata/ORCL/dev_dat.dbf' size 1G
AUTOEXTEND ON NEXT 100M;

CREATE TABLESPACE DEV_IDX
DATAFILE '/home/oracle/base/oradata/ORCL/dev_idx.dbf' size 100M
AUTOEXTEND ON NEXT 10M;

