/*[
header:
		fep�� ����ϱ����� ���ȭ�� 
name:
		fep_header.h
synopsis:
		���ȭ��
return:
		����
description:

remarks:

date:
		09/11/08
]*/



enum {SEND, RECV};

#define		COMPANY_NO		"052" 	// �̿���ȣ
#define		SZ_SEQ			8 		// FEP��� �Ϸù�ȣ����

#define		FEP_FIRST_READ	1 + 5	// STX + LENGTH
#define		FEP_SYS_TYPE	"E004"

#define		BASE_BP_NO_POS	9 		// ���¹�ȣ �� 2�ڸ���ġ
#define		BASE_BP_NO_LEN	2 		// 2�ڸ�


typedef struct {
    char    DataLen[6];         /* ��������              */
    char    TrGubun[1];         /* ��������              */
                                /* B:������, I:������, F:���ϼۼ���, N:Notice */
    char    ComGubun[1];        /* ���౸�� 0:���� 1:LZO */
    char    SecGubun[1];        /* ��ȣȭ���� 0:���� 1:SEED-CBC */
    char    DataSeek[3];        /* ������ �ɼ�           */
    char    ServCode[8];        /* ���� �ڵ�           */
    char    CompanyNo[3];       /* �̿���ȣ            */
    char    UserId[16];         /* ����� ID             */
    char    ConnectCode[2];     /* ���Ӻз��ڵ�          */
    char    ConnectCh[3];       /* ����ä�ι�ȣ          */
    char    TrSeq[9];           /* Ʈ����Ǽ�����ȣ      */
    char    TrChId[16];         /* Ʈ���������ID        */
    char    PuIP[12];           /* ����IP                */
    char    PvIP[12];           /* �缳IP                */
    char    ProBrNo[3];         /* ó��������ȣ          */
    char    BrNo[3];            /* ������ȣ              */
    char    TermNo[8];          /* �ܸ���ȣ              */
    char    LanCode[1];         /* ����              */
    char    APProTime[9];       /* APó���ð�            */
    char    MessageCode[4];     /* �޽����ڵ�            */
    char    OutMessCode[1];     /* ��¸޽�������        */
    char    ComRequest[1];      /* �����û����          */
    char    FunKey[4];          /* ���Ű���            */
    char    RequestRecord[4];   /* ��û ���ڵ� ����      */
    char    ExPro[2];           /* ����ó��              */
    char    Filler[4];          /* ���񿵿�              */
    char    ContinueYn[1];      /* ���ӿ���              */
    char    ContinueKey[18];    /* ����Ű                */
    char    VariLen[2];         /* �����ý�����������    */
    char    VariHead[2];        /* ���������������      */
    char    VariMes[2];         /* �����޽�������        */
}   BASE_HEADER, * lpBASE_HEADER;
#define		SZ_BASE_HEADER	sizeof (BASE_HEADER)


typedef struct {
	/***************** FEP ���� ���� **************************/
	char	ShmIndex[3];		/* POWER_BASE �۽� key */
	char	BpDevNo[11];		/* FEP���� ( BP������ space ) */ 
	char	MarketType[2];		/* ���屸��
					 * ���� 1�ڸ��� ���� , ���� ���� 
					 * ( 1: ����, 2: ����, 3: ����, 4: ��������, 0: ��Ÿ )
					 * ���� 1�ڸ��� �ֹ�, ��ȸ ����
					 * ( 1: �ֹ�, 2: ��ȸ, 0: ��Ÿ )
					 * BP���� ä��� FEP���� ���
					 */
	char	BaseBpNo[2];		/* ���¹�ȣ�� �� 2�ڸ� �Է� */
	// �����忡�� ���Ӱ� ����..
	char	Qkey[11];			// �����忡�� ťŰ�� ��.

	/***************** BP ���� ���� **************************/
	/* BP���� ���������� ����� �����͵���
	 * �ڿ��� ���� ä���� 
	 */
	char	user_data[4];		/* BP���� �����ϴ� �޸������� seqno */ 

	/* ������ client���� �������� ����ؾ��� �κ�
	 * �ֹ��� ü��ÿ� �ʿ� 
	 */
	char	Ord_SeqNo[6];	/* ü������� �ʿ��� �ֹ����μ����� SeqNo */
	char	machine_gbn[2]; /* HTS�� WTS�� �����ϱ� ���� ��񱸺��� ��
			  	 * WTS�� ���� WTS��� ������� �ʰ� HTS���� �ٴµ�
				 * �̸� �����ϱ� ���� ������ ���� ��.
				 * "07" : WTS, �׿ܴ� ��� HTS 
				 */

	char	hostgbn[2];	/* �ٸ� ��� ������ ���������ڵ鿡�� ü�ᵥ���͸� �����ֱ����� 
				 * ��� ������ ��
				 */

	char	trnum[4];	/* �ٸ� ��� ������ ���������ڵ鿡�� 
				 * �ֹ����������� �����ֱ� ���� trnum 
				 */
	char	filler_2[7];	
}   BASE_USER_HEADER, * lpBASE_USER_HEADER;
#define		SZ_BASE_USER_HEADER	sizeof (BASE_USER_HEADER)

typedef struct {
    char            Stx[1];         /* start of text (0x02)             */
    char            Length[5];      /* Packet���� (Header����+Data����) */
    char            ApType[6];      /* �������нĺ��� (process type)    */
    char            SysType[4];     /* ������񱸺нĺ��� (system type) */
    char            MsgType[4];     /* ��ڵ�                         */
    char            ResponseCode[2];/* �����ڵ�                         */
    char            Date[8];        /* �������� (YYYYMMDD)              */
    char            Time[9];        /* �ð� (HHMMSSmmm; mmm in millisec)*/
    char            SeqNo[8];       /* �Ϸù�ȣ; TCP port (��������)    */
    char            Filler[14];     /* reservation area                 */
} FEP_HEADER, * lpFEP_HEADER;
#define		SZ_FEP_HEADER	sizeof (FEP_HEADER)

#define		SZ_FEPBASE_HEADER	SZ_FEP_HEADER+SZ_BASE_HEADER

typedef struct	{
	FEP_HEADER					Fep;		// FEP���
	BASE_HEADER					BaseHead;	// Base���
	BASE_USER_HEADER			UserHead;	// Base User���
} GTS_HEADER, * lpGTS_HEADER;

#define		SZ_TOT_HEADER	sizeof (GTS_HEADER)
