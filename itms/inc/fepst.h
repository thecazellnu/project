/*[
header:
		fep와 통신하기위한 헤더화일 
name:
		fep_header.h
synopsis:
		헤더화일
return:
		없음
description:

remarks:

date:
		09/11/08
]*/



enum {SEND, RECV};

#define		COMPANY_NO		"052" 	// 이용사번호
#define		SZ_SEQ			8 		// FEP헤더 일련번호길이

#define		FEP_FIRST_READ	1 + 5	// STX + LENGTH
#define		FEP_SYS_TYPE	"E004"

#define		BASE_BP_NO_POS	9 		// 계좌번호 뒤 2자리위치
#define		BASE_BP_NO_LEN	2 		// 2자리


typedef struct {
    char    DataLen[6];         /* 전문길이              */
    char    TrGubun[1];         /* 전문구분              */
                                /* B:계정계, I:정보계, F:파일송수신, N:Notice */
    char    ComGubun[1];        /* 압축구분 0:안함 1:LZO */
    char    SecGubun[1];        /* 암호화구분 0:안함 1:SEED-CBC */
    char    DataSeek[3];        /* 데이터 옵셋           */
    char    ServCode[8];        /* 서비스 코드           */
    char    CompanyNo[3];       /* 이용사번호            */
    char    UserId[16];         /* 사용자 ID             */
    char    ConnectCode[2];     /* 접속분류코드          */
    char    ConnectCh[3];       /* 접속채널번호          */
    char    TrSeq[9];           /* 트랜잭션순차번호      */
    char    TrChId[16];         /* 트랜잭션추적ID        */
    char    PuIP[12];           /* 공인IP                */
    char    PvIP[12];           /* 사설IP                */
    char    ProBrNo[3];         /* 처리지점번호          */
    char    BrNo[3];            /* 지점번호              */
    char    TermNo[8];          /* 단말번호              */
    char    LanCode[1];         /* 언어구분              */
    char    APProTime[9];       /* AP처리시각            */
    char    MessageCode[4];     /* 메시지코드            */
    char    OutMessCode[1];     /* 출력메시지구분        */
    char    ComRequest[1];      /* 압축요청구분          */
    char    FunKey[4];          /* 기능키목록            */
    char    RequestRecord[4];   /* 요청 레코드 개수      */
    char    ExPro[2];           /* 예외처리              */
    char    Filler[4];          /* 예비영역              */
    char    ContinueYn[1];      /* 연속여부              */
    char    ContinueKey[18];    /* 연속키                */
    char    VariLen[2];         /* 가변시스템정보길이    */
    char    VariHead[2];        /* 가변헤더정보길이      */
    char    VariMes[2];         /* 가변메시지길이        */
}   BASE_HEADER, * lpBASE_HEADER;
#define		SZ_BASE_HEADER	sizeof (BASE_HEADER)


typedef struct {
	/***************** FEP 전용 영역 **************************/
	char	ShmIndex[3];		/* POWER_BASE 송신 key */
	char	BpDevNo[11];		/* FEP전용 ( BP에서는 space ) */ 
	char	MarketType[2];		/* 시장구분
					 * 앞의 1자리는 현물 , 선물 구분 
					 * ( 1: 현물, 2: 선물, 3: 저축, 4: 수익증권, 0: 기타 )
					 * 뒤의 1자리는 주문, 조회 구분
					 * ( 1: 주문, 2: 조회, 0: 기타 )
					 * BP에서 채우면 FEP에서 사용
					 */
	char	BaseBpNo[2];		/* 계좌번호의 뒤 2자리 입력 */
	// 가원장에서 새롭게 쓰임..
	char	Qkey[11];			// 가원장에서 큐키로 씀.

	/***************** BP 전용 영역 **************************/
	/* BP에서 개별적으로 사용할 데이터들은
	 * 뒤에서 부터 채워짐 
	 */
	char	user_data[4];		/* BP에서 관리하는 메모리정보의 seqno */ 

	/* 증전과 client에서 공통으로 사용해야할 부분
	 * 주문과 체결시에 필요 
	 */
	char	Ord_SeqNo[6];	/* 체결응답시 필요한 주문프로세스의 SeqNo */
	char	machine_gbn[2]; /* HTS와 WTS를 구분하기 위한 장비구분자 값
			  	 * WTS가 현재 WTS장비를 사용하지 않고 HTS장비로 붙는데
				 * 이를 구분하기 위해 구분자 값을 둠.
				 * "07" : WTS, 그외는 모두 HTS 
				 */

	char	hostgbn[2];	/* 다른 장비에 접속한 동시접속자들에게 체결데이터를 내려주기위한 
				 * 장비 구분자 값
				 */

	char	trnum[4];	/* 다른 장비에 접속한 동시접속자들에게 
				 * 주문접수응답을 내려주기 위한 trnum 
				 */
	char	filler_2[7];	
}   BASE_USER_HEADER, * lpBASE_USER_HEADER;
#define		SZ_BASE_USER_HEADER	sizeof (BASE_USER_HEADER)

typedef struct {
    char            Stx[1];         /* start of text (0x02)             */
    char            Length[5];      /* Packet길이 (Header길이+Data길이) */
    char            ApType[6];      /* 업무구분식별자 (process type)    */
    char            SysType[4];     /* 업무장비구분식별자 (system type) */
    char            MsgType[4];     /* 운영코드                         */
    char            ResponseCode[2];/* 응답코드                         */
    char            Date[8];        /* 영업일자 (YYYYMMDD)              */
    char            Time[9];        /* 시각 (HHMMSSmmm; mmm in millisec)*/
    char            SeqNo[8];       /* 일련번호; TCP port (접속응답)    */
    char            Filler[14];     /* reservation area                 */
} FEP_HEADER, * lpFEP_HEADER;
#define		SZ_FEP_HEADER	sizeof (FEP_HEADER)

#define		SZ_FEPBASE_HEADER	SZ_FEP_HEADER+SZ_BASE_HEADER

typedef struct	{
	FEP_HEADER					Fep;		// FEP헤더
	BASE_HEADER					BaseHead;	// Base헤더
	BASE_USER_HEADER			UserHead;	// Base User헤더
} GTS_HEADER, * lpGTS_HEADER;

#define		SZ_TOT_HEADER	sizeof (GTS_HEADER)
