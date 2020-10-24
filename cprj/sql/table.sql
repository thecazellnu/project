DROP TABLE "DEVUSR"."CRON_TAB" ;
  CREATE TABLE "DEVUSR"."CRON_TAB" 
   (	
    "NAME" VARCHAR2(128 BYTE), 
	"MONTH" VARCHAR2(16 BYTE), 
	"WEEK" VARCHAR2(16 BYTE), 
	"BIZDAY" VARCHAR2(16 BYTE), 
	"EXECDATE" VARCHAR2(8 BYTE), 
	"ATTRIBUTE" VARCHAR2(8 BYTE), 
	"BINTYPE" VARCHAR2(8 BYTE) DEFAULT 'BINARY', 
	"STTIME" VARCHAR2(6 BYTE), 
	"EDTIME" VARCHAR2(6 BYTE), 
	"PATH" VARCHAR2(256 BYTE), 
	"ARGV" VARCHAR2(256 BYTE) DEFAULT ' ', 
	"DESCRIPT" VARCHAR2(256 BYTE) DEFAULT ' ', 
	"USEYN" VARCHAR2(1),
	"LAST" VARCHAR2(14) DEFAULT ' ',
	"PID" NUMBER(20,0) DEFAULT -1, 
	"RUNCNT" NUMBER(10,0) DEFAULT 0,
	"LASTUPDATE" VARCHAR2(14) DEFAULT TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 
 NOCOMPRESS LOGGING
  TABLESPACE "DEV_DAT" ;

   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."NAME" IS '���μ��� �̸�';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."MONTH" IS '1:ù�� 0:�������� -1:������ ';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."WEEK" IS '1:SUN 2:MON 3:TUE 4:WED ...';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."BIZDAY" IS 'BIZ:������ HOL:�񿵾��Ͻ���';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."EXECDATE" IS 'Ư����������';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."ATTRIBUTE" IS 'ONCE, FOREVER';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."BINTYPE" IS 'BINARY,SHELL';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."STTIME" IS 'hhmmss';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."EDTIME" IS 'hhmmss';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."PATH" IS '���μ�����ġ';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."ARGV" IS '����';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."DESCRIPT" IS '����';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."PID" IS 'Process ID';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."RUNCNT" IS 'Run count';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."USEYN" IS '��뿩�� Y/N';
   COMMENT ON COLUMN "DEVUSR"."CRON_TAB"."LAST" IS '����������ð�';
   COMMENT ON TABLE "DEVUSR"."CRON_TAB"  IS 'CRON_TABLE';

--DROP SYNONYM "EBN_USER"."CRON_TAB";
--REATE SYNONYM "EBN_USER"."CRON_TAB" FOR "DEVUSR"."CRON_TAB";
