/*[
header:
	코스콤 Tr 전문 정의
name:
	tradest.h
synopsis:
	헤더화일
return:
	없음
description:
	헤더화일
remarks:
	12/04/12    dhkim   SONAT002F(GTS의 SONAT002와 같지만, 국내 현물과 전문이름이 같아 GIS에서 수정)
date:
	11/02/28
author:
	김동환
]*/

#ifndef _TRADE_ST_H_
#define _TRADE_ST_H_

///////////////////////////////////////////////////////////////
typedef struct
{
char In[5];
char InptTp[1];	//입력구분              
char BaseDt[8];	//기준일                
char FundOpAcntNo[20];	//펀드운용계좌번호
char SetupSeqno[10];	//설정일련번호      
char MnyCnfTp[1];	//자금확인구분        
char MnyTp[1];	//자금구분                
char SbrwTp[1];	//대차구분              
char QryTp[1];	//조회구분
char DpartNo[3];	//부서번호

} SSEBQ649_IN,   * lpSSEBQ649_IN;
#define SZ_SSEBQ649_IN    sizeof(SSEBQ649_IN)

//////////////////////////////////////////////////////////////////
typedef struct
{
	char TotOut              [  5]; //
    char FundOpAcntNo        [ 20]; // 펀드운용계좌번호 X(20)
    char FundNm              [ 40]; // 펀드명 X(40)
    char MnyCnfTpNm          [ 20]; // 자금확인구분 X(20)
    char TpNm1               [ 40]; // 구분명1 X(40)
    char TpNm2               [ 40]; // 구분명2 X(40)
    char BuyAmt              [ 16]; // 매수금액 S9(15)
    char SellAmt             [ 16]; // 매도금액 S9(15)
    char CsgnBuyAmt          [ 16]; // 위탁매수금액 S9(15)
    char CsgnSellAmt         [ 16]; // 위탁매도금액 S9(15)
    char ThdayBndBuyAmt      [ 16]; // 당일채권매수금액 S9(15)
    char ThdayBndSellAmt     [ 16]; // 당일채권매도금액 S9(15)
    char Amt1                [ 16]; // 금액1 S9(15)
    char Amt2                [ 16]; // 금액2 S9(15)
    char BndBuyAmt           [ 16]; // 채권매수금액 S9(15)
    char BndSellAmt          [ 16]; // 채권매도금액 S9(15)
    char Out2                [  5]; //  
}SSEBQ649_OUT,   * lpSSEBQ649_OUT;
#define SZ_SSEBQ649_OUT  sizeof(SSEBQ649_OUT) 

typedef struct
{
	char DlngPrdtTp          [  1]; // 딜링상품구분 X(1)
    char SetupSeqno          [ 10]; // 설정일련번호 S9(9)
    char MnyCnfTpNm          [ 20]; // 자금확인구분 X(20)
    char MnySeqno            [ 10]; // 자금일련번호 S9(9)
    char MnyTpNm             [ 40]; // 자금구분 X(40)
    char TrdTpNm             [ 20]; // 거래구분 X(20)
    char AfirTpNm            [ 40]; // 업무구분 X(40)
    char OppTrdAcntNo        [ 20]; // 상대거래계좌번호 X(20)
    char AcntNm              [ 40]; // 계좌명 X(40)
    char BnsAmt              [ 16]; // 매매금액 S9(15)
    char DpsNm               [ 50]; // 예금명 X(50)
    char MnySettIttNo        [ 20]; // 자금결제기관번호 X(20)
    char BrnNm               [ 40]; // 지점명 X(40)
    char SettTpNm            [ 41]; // 결제구분명 X(41)
    char SettDt              [  8]; // 결제일 X(8)
    char FundOpAcntNo        [ 20]; // 펀드운용계좌번호 X(20)
} SSEBQ649_Sub, * lpSSEBQ649_Sub;
#define SZ_SSEBQ649_Sub  sizeof(SSEBQ649_Sub)

typedef struct
{
    char MnySeqno            [ 10]; // 자금일련번호 S9(9)
    char MnyTpNm             [ 40]; // 자금구분 X(40)
    char TrdTpNm             [ 20]; // 거래구분 X(20)
    char AfirTpNm            [ 40]; // 업무구분 X(40)
    char OppTrdAcntNo        [ 20]; // 상대거래계좌번호 X(20)
    char AcntNm              [ 40]; // 계좌명 X(40)
    char BnsAmt              [ 16]; // 매매금액 S9(15)
    char DpsNm               [ 50]; // 예금명 X(50)
    char MnySettIttNo        [ 20]; // 자금결제기관번호 X(20)
    char BrnNm               [ 40]; // 지점명 X(40)
    char SettTpNm            [ 41]; // 결제구분명 X(41)
    char SettDt              [  8]; // 결제일 X(8)
} SSEBQ649_Sub2, * lpSSEBQ649_Sub2;
#define SZ_SSEBQ649_Sub2  sizeof(SSEBQ649_Sub2)
///////////////////////////////////////////////////////////////
typedef struct
{
char In[5];
char TrxTp[1];//	처리구분          
char BrnNo[3];//	지점번호          
char BrnTp[1];//	지점구분          
char BaseDt[8];//	기준일            
char PdGrpCode[2];//	상품군코드    
char ClssGrpCode[3];//	기초자산코드

} SSLAQ728_IN,   * lpSSLAQ728_IN;
#define SZ_SSLAQ728_IN    sizeof(SSLAQ728_IN)

typedef struct
{
	char Out                 [  5]; //  
    char BrnNm               [ 40]; // 지점명 X(40)
    char Amt1                [ 16]; // 금액1 S9(15)
    char Amt2                [ 16]; // 금액2 S9(15)
    char Amt3                [ 16]; // 금액3 S9(15)
    char CodeNm01            [ 40]; // 코드명 X(40)
    char CodeNm02            [ 40]; // 코드명 X(40)
    char CmsnAmt             [ 16]; // 수수료 S9(15)
    char OutList2            [  5]; // X(5) 
} SSLAQ728_OUT,   * lpSSLAQ728_OUT;
#define SZ_SSLAQ728_OUT  sizeof(SSLAQ728_OUT)

typedef struct
{
	char BrnNm               [ 40]; // 지점명 X(40)
    char FutsAdjstDfamt      [ 16]; // 선물정산차금 S9(15)
    char FutsThdayDfamt      [ 16]; // 선물당일차금 S9(15)
    char FutsUdamt           [ 16]; // 선물갱신차금 S9(15)
    char OptSettDfamt        [ 16]; // 옵션결제차금 S9(15)
    char SettDfamtSum        [ 17]; // 결제차금합 S9(16)
    char FxdratMbrfee        [ 16]; // 정률회비 S9(15)
    char AsFee               [ 16]; // 협회비 S9(15)
    char ReprFund            [ 16]; // 배상기금 S9(15)
} SSLAQ728_Sub, * lpSSLAQ728_Sub;
#define SZ_SSLAQ728_Sub  sizeof(SSLAQ728_Sub)

///////////////////////////////////////////////////////////////
typedef struct
{
char In[5];
char ActgBrnNo[3]; //	회계지점번호  
char BaseDt[8]; //	기준일          
char SrtAccCode[9]; //	시작계정코드
char EndAccCode[9]; //	종료계정코드
char ActgBaseTp[1]; //	회계기준구분
} SIAGQ115_IN,   * lpSIAGQ115_IN;
#define SZ_SIAGQ115_IN    sizeof(SIAGQ115_IN)

typedef struct
{
	char Out                 [  5]; //  
    char ActgBrnNm           [ 40]; // 회계지점명 X(40)
    char OutLst              [  5]; //  
} SIAGQ115_OUT,   * lpSIAGQ115_OUT;
#define SZ_SIAGQ115_OUT  sizeof(SIAGQ115_OUT)

typedef struct
{
    char AccCode             [  9]; // 계정코드 X(9)
    char AccNm               [ 50]; // 계정명 X(50)
    char FncustNm            [ 50]; // 금융거래처명 X(50)
    char DpsMgmtNo           [ 20]; // 예금관리번호 X(20)
    char AccBfbalAmt         [ 16]; // 계정전잔금액 S9(15)
    char MnyinAmt            [ 16]; // 입금금액 S9(15)
    char MnyoutAmt           [ 16]; // 출금금액 S9(15)
    char AccCrbalAmt         [ 16]; // 계정금잔금액 S9(15)
    char NmonPldgPrvdCnts2   [100]; // 차월담보제공내용2 X(100)
    char OwnPrdtCode         [ 20]; // 자체상품코드 X(20)
    char OpenDt              [  8]; // 개설일 X(8)
    char DueDt               [  8]; // 만기일 X(8)
    char Intrat              [  7]; // 이자율 S9.9(4)
    char RcvblIntrstAmt      [ 16]; // 미수이자금액 S9(15)
    char DueIntrstAmt        [ 16]; // 만기이자금액 S9(15)
    char PassDays            [  6]; // 경과일수 S9(5)  
} SIAGQ115_Sub, * lpSIAGQ115_Sub;
#define SZ_SIAGQ115_Sub  sizeof(SIAGQ115_Sub)	

///////////////////////////////////////////////////////////////
typedef struct
{
char In[5];
char FundOpAcntNo[20];
char TrdPtnCode[2];
char CreBaseCode[2];
char QrySrtDt[8];
char QryEndDt[8];
char BalQty1[16];
char BalQty2[16];
} SSESQ102_IN,   * lpSSESQ102_IN;
#define SZ_SSESQ102_IN    sizeof(SSESQ102_IN)

typedef struct
{
	char Out                 [  5]; //  
    char FundNm              [ 40]; // 펀드명 X(40)
    char DtCfTrd             [  5]; //  
} SSESQ102_OUT,   * lpSSESQ102_OUT;
#define SZ_SSESQ102_OUT  sizeof(SSESQ102_OUT)

typedef struct
{
    char TrdDt               [  8]; // 거래일 X(8)
    char TrdNo               [ 10]; // 거래번호 S9(9)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char IsuNm               [ 40]; // 종목명 X(40)
    char TrdPtnTpNm          [ 20]; // 거래유형구분 X(20)
    char SmryNm              [ 40]; // 적요명 X(40)
    char BnsTpNm             [ 10]; // 매매구분 X(10)
    char CancYnNm            [ 10]; // 취소여부명 X(10)
    char BnsUprc             [ 20]; // 매매단가 S9(14).9(4)
    char BookUprc            [ 15]; // 장부단가 S9(9).9(4)
    char BnsQty              [ 16]; // 매매수량 S9(15)
    char BnsAmt              [ 16]; // 매매금액 S9(15)
    char SecBfbalQty         [ 16]; // 유가증권전잔수량 S9(15)
    char SecCrbalQty         [ 16]; // 유가증권금잔수량 S9(15)
    char BookAmtBfbalAmt     [ 16]; // 장부금전잔금액 S9(15)
    char BookAmtCrbalAmt     [ 16]; // 장부금금잔금액 S9(15)
    char Trtax               [ 16]; // 거래세 S9(15)
    char Fstax               [ 16]; // 농특세 S9(15)
    char BnsplAmt            [ 16]; // 매매손익금액 S9(15)
    char YearAcmBnsplAmt     [ 16]; // 년누적매매손익금액 S9(15)
    char LowAcntNo           [ 20]; // 하위계좌번호 X(20)
    char AcntNm              [ 40]; // 계좌명 X(40)
    char SettCostAmt         [ 16]; // 예탁결제비용금액 S9(15)
    char AsfeeAmt            [ 16]; // 협회비금액 S9(15)
    char AscAdminBrfee       [ 16]; // 정율회비금액 S9(15)
    char SettStblAmt         [ 16]; // 협회비금액 S9(15)
    char CmsnAmt1            [ 17]; // 수수료1 S9(11).9(4)
    char CmsnAmt2            [ 17]; // 수수료2 S9(11).9(4)
    char TrdAmt              [ 16]; // 거래금액 S9(15)
    char Ictax               [ 16]; // 소득세 S9(15)
} SSESQ102_Sub, * lpSSESQ102_Sub;
#define SZ_SSESQ102_Sub  sizeof(SSESQ102_Sub)

///////////////////////////////////////////////////////////////
typedef struct
{
char In[5];
char TrxTp[1];//	처리구분
char BrnNo[3];//	지점번호
char BrnTp[1];//	지점구분
char BaseDt[8];//	기준일
char PdGrpCode[2];//	상품군코드
char ClssGrpCode[3];//	기초자산코드
} SBPGQ776_IN,   * lpSBPGQ776_IN;
#define SZ_SBPGQ776_IN    sizeof(SBPGQ776_IN)

/*
    char OutList             [  5]; //  
    char BrnNm               [ 40]; // 지점명 X(40)
    char BrnNo               [  3]; // 지점번호 X(3)
    char FutsAdjstDfamt      [ 16]; // 선물정산차금 S9(15)
    char FutsThdayDfamt      [ 16]; // 선물당일차금 S9(15)
    char FutsUdamt           [ 16]; // 선물갱신차금 S9(15)
    char FutsLastSettDfamt   [ 16]; // 선물최종결제차금 S9(15)
    char OptSettDfamt        [ 16]; // 옵션결제차금 S9(15)
    char OptSellAmt          [ 16]; // 옵션매도금액 S9(15)
    char OptBuyAmt           [ 16]; // 옵션매수금액 S9(15)
    char OptXrcDfamt         [ 16]; // 옵션행사차금 S9(15)
    char OptAsgnDfamt        [ 16]; // 옵션배정차금 S9(15)
    char SettDiffAmt         [ 17]; // 결제차금 S9(16)
    char FutsFxdratMbrfee    [ 16]; // 선물정률회비 S9(15)
    char OptFxdratMbrfee     [ 16]; // 옵션정률회비 S9(15)
    char FutsAsfee           [ 16]; // 선물협회비 S9(15)
    char OptAsfee            [ 16]; // 옵션협회비 S9(15)
    char FutsDpstgOrgCmsnAmt [ 16]; // 선물예탁원수수료 S9(15)
    char OptDpstgOrgCmsnAmt  [ 16]; // 옵션예탁원수수료 S9(15)
    char FutsReprAlrdyAmt    [ 16]; // 선물배상기금액 S9(15)
    char OptReprAlrdyAmt     [ 16]; // 옵션배상기금액 S9(15)
*/
typedef struct
{
	char Out                 [  5]; //
    char BrnNm               [ 40]; // 지점명 X(40)
    char Amt1                [ 16]; // 금액1 S9(15)
    char Amt2                [ 16]; // 금액2 S9(15)
    char Amt3                [ 16]; // 금액3 S9(15)
    char CodeNm01            [ 40]; // 코드명 X(40)
    char CodeNm02            [ 40]; // 코드명 X(40)
    char CmsnAmt             [ 16]; // 수수료 S9(15)
    char OutList2            [  5]; // X(5)
} SBPGQ776_OUT,   * lpSBPGQ776_OUT;
#define SZ_SBPGQ776_OUT  sizeof(SBPGQ776_OUT)

typedef struct
{
	char BrnNm               [ 40]; // 지점명 X(40)
    char FutsAdjstDfamt      [ 16]; // 선물정산차금 S9(15)
    char FutsThdayDfamt      [ 16]; // 선물당일차금 S9(15)
    char FutsUdamt           [ 16]; // 선물갱신차금 S9(15)
    char OptSettDfamt        [ 16]; // 옵션결제차금 S9(15)
    char SettDfamtSum        [ 17]; // 결제차금합 S9(16)
    char FxdratMbrfee        [ 16]; // 정률회비 S9(15)
    char AsFee               [ 16]; // 협회비 S9(15)
    char ReprFund            [ 16]; // 배상기금 S9(15)	
} SBPGQ776_Sub, * lpSBPGQ776_Sub;
#define SZ_SBPGQ776_Sub  sizeof(SBPGQ776_Sub)
///////////////////////////////////////////////////////////////
typedef struct
{
char In[5];
char RptOtptTp[1];
char ActgBaseTp[1];
char ActgBrnNo[3];
char AccCode[9];
char QrySrtDt[8];
char QryEndDt[8];

} SIAGQ035_IN,   * lpSIAGQ035_IN;
#define SZ_SIAGQ035_IN    sizeof(SIAGQ035_IN)

typedef struct
{
	char Out                 [  5]; //  
    char ActgBrnNm           [ 40]; // 회계지점명 X(40)
    char AccNm               [ 50]; // 계정명 X(50)
    char BalAmt              [ 16]; // 잔고금액 S9(15)
    char Totamt1             [ 16]; // 합계금액 S9(15)
    char Totamt2             [ 16]; // 합계금액 S9(15)
    char Totamt3             [ 16]; // 합계금액 S9(15)
    char Totamt4             [ 16]; // 합계금액 S9(15)
    char TrxTpNm1            [ 20]; // 처리구분명1 X(20)
    char OutLst              [  5]; //  
} SIAGQ035_OUT,   * lpSIAGQ035_OUT;
#define SZ_SIAGQ035_OUT  sizeof(SIAGQ035_OUT)

typedef struct
{
	char SlpAprvDt           [  8]; // 전표결재일 X(8)
    char SlpNo               [ 10]; // 전표번호 S9(9)
    char SlpSeqno            [ 10]; // 전표일련번호 S9(9)
    char SlpBrnNo            [  3]; // 전표지점번호 X(3)
    char FirstSmryDtlCnts    [100]; // 제1적요상세내용 X(100)
    char CrdtCardNo          [ 20]; // 신용카드번호 X(20)
    char EmpNo               [  9]; // 사원번호 X(9)
    char DncTpNm             [ 10]; // 차대구분명 X(10)
    char FncustNm            [ 50]; // 금융거래처명 X(50)
    char DebitAmt            [ 16]; // 차변금액 S9(15)
    char CrdsdAmt            [ 16]; // 대변금액 S9(15)
} SIAGQ035_Sub, * lpSIAGQ035_Sub;
#define SZ_SIAGQ035_Sub  sizeof(SIAGQ035_Sub)

///////////////////////////////////////////////////////////////
typedef struct
{
char In[5];
char FundOpAcntNo[20];
char QryDt[8];
char IsuNo[12];
char CreBaseCode[2];
char TrxTp[1];

} SSESQ008_IN,   * lpSSESQ008_IN;
#define SZ_SSESQ008_IN    sizeof(SSESQ008_IN)

typedef struct
{
	char Out                 [  5]; //  
    char FundNm              [ 40]; // 펀드명 X(40)
    char FundStkCfBal        [  5]; //  
} SSESQ008_OUT,   * lpSSESQ008_OUT;
#define SZ_SSESQ008_OUT  sizeof(SSESQ008_OUT)

typedef struct
{
    char IsuNo               [ 12]; // 종목번호 X(12)
    char IsuNm               [ 40]; // 종목명 X(40)
    char RegMktNm            [ 40]; // 등록시장명 X(40)
    char HldQty              [ 16]; // 보유수량 S9(15)
    char BookAmt             [ 16]; // 장부금액 S9(15)
    char BookUprc            [ 15]; // 장부단가 S9(9).9(4)
    char BrwQty              [ 16]; // 차입수량 S9(15)
    char BrwSellQty          [ 16]; // 차입매도수량 S9(15)
    char BrwSellAmt          [ 16]; // 차입매도금액 S9(15)
    char SellUprc            [ 15]; // 매도단가 S9(9).9(4)
    char SbrwSellQty         [ 16]; // 대차매도수량 S9(15)
    char SbrwSellAmt         [ 16]; // 대차매도금액 S9(15)
    char BnsPrftAmt          [ 16]; // 매매이익금액 S9(15)
    char BnsLossAmt          [ 16]; // 매매손실금액 S9(15)
    char BnsplAmt            [ 16]; // 매매손익금액 S9(15)
    char EvalPnlAmt          [ 16]; // 평가손익금액 S9(15)
    char AddPldgAbleQty      [ 16]; // 추가담보가능수량 S9(15)
} SSESQ008_Sub, * lpSSESQ008_Sub;
#define SZ_SSESQ008_Sub  sizeof(SSESQ008_Sub)


///////////////////////////////////////////////////////////////
// 단말정보조회
///////////////////////////////////////////////////////////////
typedef struct
{
	char In                  [  5]; //  
    char BrnNo               [  3]; // 지점번호 X(3)
    char QryTp               [  1]; // 조회구분 X(1)
    char QryCndi             [ 40]; // 조회조건 X(40)
    char FirmNo              [  3]; // 이용사번호 X(3)
} SBPGQ253_IN,   * lpSBPGQ253_IN;
#define SZ_SBPGQ253_IN    sizeof(SBPGQ253_IN)

typedef struct
{
    char Out                 [  5]; //  
    char BrnNm               [ 40]; // 지점명 X(40)
    char TotTermCnt          [  6]; // 총단말수 S9(5)
    char BrnTermCnt          [  6]; // 지점단말수 S9(5)
    char TotConnTermCnt      [  6]; // 총접속단말수 S9(5)
    char BrnConnTermCnt      [  6]; // 지점접속단말수 S9(5)
    char List                [  5]; //  
} SBPGQ253_OUT, * lpSBPGQ253_OUT;
#define SZ_SBPGQ253_OUT  sizeof(SBPGQ253_OUT)

typedef struct
{
    char BrnNo               [  3]; // 지점번호 X(3)
    char BrnNm               [ 40]; // 지점명 X(40)
    char TermNo              [  3]; // 단말번호 X(3)
    char TermIp              [ 12]; // 단말IP X(12)
    char IpStmntCode         [  2]; // IP신고코드 X(2)
    char SrcIp               [ 12]; // IP주소 X(12)
    char UseAfirCode         [  2]; // 사용업무코드 X(2)
    char ConnYn              [  1]; // 접속여부 X(1)
    char ConnUserId          [ 16]; // 접속사용자ID X(16)
    char ConnUserNm          [ 40]; // 접속사용자명 X(40)
    char LoginDttm           [ 17]; // 로그인일시 X(17)
    char LogotDttm           [ 17]; // 로그아웃일시 X(17)
    char NmdUserId           [ 16]; // 지정사용자ID X(16)
    char NmdUserNm           [ 40]; // 지정사용자명 X(40)
    char PrntBrnNo           [  3]; // 모지점번호 X(3)
    char LoginPrhbtYn        [  1]; // 로그인금지여부 X(1)
    char TermPtnTp           [  1]; // 단말유형구분 X(1)
    char TermUsageTp         [  1]; // 단말용도구분 X(1)
    char BrnChkYn            [  1]; // 지점확인여부 X(1)
    char PayAuthVal          [ 10]; // 유료권한값 X(10)
    char MgrBrnNo            [  3]; // 관리지점번호 X(3)
    char TermNm              [ 40]; // 단말명 X(40)
    char RegUserId           [ 16]; // 등록사용자ID X(16)
	char RegDttm             [ 17]; // 등록일시 X(17)
    char ChgUserId           [ 16]; // 변경사용자ID X(16)
    char ChgDttm             [ 17]; // 변경일시 X(17)
    char TermDescr           [100]; // 단말설명 X(100)
    char MenuAuthCode        [  4]; // 메뉴권한코드 X(4)
    char MenuAuthNm          [ 40]; // 메뉴권한명 X(40)
    char EmpNo               [  9]; // 사원번호 X(9)
} SBPGQ253_Sub, * lpSBPGQ253_Sub;
#define SZ_SBPGQ253_Sub  sizeof(SBPGQ253_Sub)

/////////////////////////////////////////////////////////////////////////////
typedef struct _SIAGT195I_
{
	char In                  [  5]; //  
    char ActgBrnNo           [  3]; // 회계지점번호 X(3)
    char RslnDt              [  8]; // 결의일 X(8)
    char RslnSeqno           [ 10]; // 결의서일련번호 S9(9)
    char TrxTp               [  1]; // 처리구분 X(1)
    char ActgBaseTp          [  1]; // 회계기준구분 X(1)
    char AccCode             [  9]; // 계정코드 X(9)
    char BdgtCode            [  9]; // 예산코드 X(9)
    char CnfrDt              [  8]; // 품의일 X(8)
    char EmpNo               [  9]; // 사원번호 X(9)
    char RslnAmt             [ 16]; // 결의서금액 S9(15)
    char HanglAmtNm          [ 50]; // 한글금액명 X(50)
    char FcurrAmt            [ 17]; // 외화금액 S9(11).9(4)
    char CrcyCode            [  3]; // 통화코드 X(3)
    char GivTp               [  1]; // 지급구분 X(1)
    char GivAccCode          [  9]; // 지급계정코드 X(9)
    char ActgTrdPtnCode      [  6]; // 회계거래유형코드 X(6)
    char SmryDtlCnts1        [100]; // 적요상세내용1 X(100)
    char SmryDtlCnts2        [100]; // 적요상세내용2 X(100)
    char SmryDtlCnts3        [100]; // 적요상세내용3 X(100)
    char SmryDtlCnts4        [100]; // 적요상세내용4 X(100)
    char SmryDtlCnts5        [100]; // 적요상세내용5 X(100)
    char FncustCode          [  7]; // 금융거래처코드 X(7)
    char EvdnTp              [  1]; // 증빙구분 X(1)
    char DpsMgmtNo           [ 20]; // 예금관리번호 X(20)
    char BncNo               [ 20]; // 어음수표번호 X(20)
    char CrdtCardNo          [ 20]; // 신용카드번호 X(20)
    char MnyoutPreargDt      [  8]; // 출금예정일 X(8)
    char GivPlcNm            [ 50]; // 지급처명 X(50)
    char DrftrNm             [ 40]; // 기안자명 X(40)
    char ExpnsTp             [  1]; // 경비구분 X(1)
    char AcptPsnNm           [ 40]; // 수령자명 X(40)
    char GivPlcDpsMgmtNo     [ 20]; // 지급처예금관리번호 X(20)
    char MtrsfBrnNo          [  3]; // 이체지점번호 X(3)
    char MtrsfAccCode        [  9]; // 이체계정코드 X(9)
    char JrnAccCode          [  9]; // 분개계정코드 X(9)
    char ComeqpPtnCode       [  2]; // 전산장비유형코드 X(2)
} SIAGT195I_st,   * lpSIAGT195I_st;
#define SZ_SIAGT195I    sizeof(SIAGT195I_st)

typedef struct _SIAGT195O_
{
    char Out                 [  5]; //  
} SIAGT195O_st,   * lpSIAGT195O_st;
#define SZ_SIAGT195O    sizeof(SIAGT195O_st)

typedef struct _SIAGT195Sub_
{
    char ActgBrnNm           [ 40]; // 회계지점명 X(40)
    char DebitAccNm          [ 50]; // 차변계정명 X(50)
    char BdgtNm              [ 50]; // 예산명 X(50)
    char EmpNm               [ 40]; // 사원명 X(40)
    char OppAccNm            [ 50]; // 상대계정명 X(50)
    char ActgTrdPtnNm        [ 50]; // 회계거래유형명 X(50)
    char FncustNm            [ 50]; // 금융거래처명 X(50)
    char FmtnAmt             [ 16]; // 편성금액 S9(15)
    char AsgnAmt             [ 16]; // 배정금액 S9(15)
    char EnfcAmt             [ 16]; // 집행금액 S9(15)
    char BalAmt              [ 16]; // 잔고금액 S9(15)
    char UserNm              [ 40]; // 사용자명 X(40)
} SIAGT195Sub_st,   * lpSIAGT195Sub_st;
#define SZ_SIAGT195Sub    sizeof(SIAGT195Sub_st)

/////////////////////////////////////////////////////////////////////////////
typedef struct _SIAGR122I_
{
	char In                  [  5]; //  
    char SrtDt               [  8]; // 시작일 X(8)
    char EndDt               [  8]; // 종료일 X(8)
    char SrtAccCode          [  9]; // 시작계정코드 X(9)
    char EndAccCode          [  9]; // 종료계정코드 X(9)
    char SrtBrnNo            [  3]; // 시작지점번호 X(3)
    char EndBrnNo            [  3]; // 종료지점번호 X(3)
    char RptKind             [  1]; // 보고서종류 X(1)
    char BrnTp               [  1]; // 지점구분 X(1)
} SIAGR122I_st,   * lpSIAGR122I_st;
#define SZ_SIAGR122I    sizeof(SIAGR122I_st)

typedef struct _SIAGR122O_
{
	char Body                [  5]; //
} SIAGR122O_st,   * lpSIAGR122O_st;
#define SZ_SIAGR122O    sizeof(SIAGR122O_st)


typedef struct _SIAGR122Sub_
{
    char BrnNo               [  3]; // 지점번호 X(3)
    char AccCode             [  9]; // 계정코드 X(9)
    char AccNm               [ 50]; // 계정명 X(50)
    char ActgTrdPtnCode      [  6]; // 회계거래유형코드 X(6)
    char FirstSmryCnts       [100]; // 제1적요내용 X(100)
    char SecondSmryCnts      [100]; // 제2적요내용 X(100)
    char AllocBrnNo          [  3]; // 배분지점번호 X(3)
    char EmpNo               [  9]; // 사원번호 X(9)
    char AprvDt              [  8]; // 결재일 X(8)
    char SlpNo               [ 10]; // 전표번호 S9(9)
    char SlpSeqno            [ 10]; // 전표일련번호 S9(9)
    char PnlAllocBaseNm      [ 50]; // 손익배분기준명 X(50)
    char ErrorYn             [  1]; // 오류여부 X(1)
    char SmryCnts            [100]; // 적요내용 X(100)
    char AllocAmt            [ 16]; // 배분금액 S9(15)
    char RslnDt              [  8]; // 결의일 X(8)
    char RslnSeqno           [ 10]; // 결의서일련번호 S9(9)
    char TpNm1               [ 40]; // 구분명1 X(40)
} SIAGR122Sub_st,   * lpSIAGR122Sub_st;
#define SZ_SIAGR122Sub    sizeof(SIAGR122Sub_st)



///////////////////////////////////////////////////////////////
// 예산분기배정
///////////////////////////////////////////////////////////////
typedef struct _SFABT004I_
{
    char In                  [  5]; //  
    char BdgtFmtnYear        [  4]; // 예산편성연도 X(4)
    char SrtBrnNo            [  3]; // 시작지점번호 X(3)
    char SrtBdgtCode         [  9]; // 시작예산코드 X(9)
    char BrnNo               [  3]; // 지점번호 X(3)
    char BdgtCode            [  9]; // 예산코드 X(9)
    char Amt                 [ 16]; // 금액 S9(15)
    char SmryCnts            [100]; // 적요내용 X(100)
    char Amt1                [ 16]; // 금액1 S9(15)
    char SmryCnts1           [100]; // 적요내용 X(100)
    char Amt2                [ 16]; // 금액2 S9(15)
    char SmryCnts2           [100]; // 적요내용2 X(100)
    char Amt3                [ 16]; // 금액3 S9(15)
    char SmryCnts3           [100]; // 적요내용 X(100)
    char Amt4                [ 16]; // 금액4 S9(15)
    char SmryCnts4           [100]; // 적요내용 X(100)
    char Amt5                [ 16]; // 금액5 S9(15)
} SFABT004I_st,   * lpSFABT004I_st;
#define SZ_SFABT004I    sizeof(SFABT004I_st)

typedef struct _SFABT004O_
{
    char Out                 [  5]; //  
    char BrnNm               [ 40]; // 지점명 X(40)
    char BdgtNm              [ 50]; // 예산명 X(50)
    char OutLst              [  5]; // X(5) 
} SFABT004O_st,   * lpSFABT004O_st;
#define SZ_SFABT004O    sizeof(SFABT004O_st)

typedef struct _SFABT004Sub_
{
    char BrnNo               [  3]; // 지점번호 X(3)
    char BrnNm               [ 40]; // 지점명 X(40)
    char BdgtCode            [  9]; // 예산코드 X(9)
    char BdgtNm              [ 50]; // 예산명 X(50)
    char Amt                 [ 16]; // 금액 S9(15)
    char SmryCnts            [100]; // 적요내용 X(100)
    char Amt1                [ 16]; // 금액1 S9(15)
    char SmryCnts1           [100]; // 적요내용 X(100)
    char Amt2                [ 16]; // 금액2 S9(15)
    char SmryCnts2           [100]; // 적요내용2 X(100)
    char Amt3                [ 16]; // 금액3 S9(15)
    char SmryCnts3           [100]; // 적요내용 X(100)
    char Amt4                [ 16]; // 금액4 S9(15)
    char SmryCnts4           [100]; // 적요내용 X(100)
    char Amt5                [ 16]; // 금액5 S9(15)
} SFABT004Sub_st,   * lpSFABT004Sub_st;
#define SZ_SFABT004Sub    sizeof(SFABT004Sub_st)
///////////////////////////////////////////////////////////////

typedef struct _SACMQ550I_
{
    char	In	[5];	//	
    char	ClntNo	[20];	//	고객번호
    char	TrxTp	[1];	//	처리구분
    char	QryTp	[1];	//	조회구분
    char	BrnNo	[3];	//	지점번호
    char	SrtDt	[8];	//	시작일
    char	EndDt	[8];	//	종료일
} SACMQ550I_st,   * lpSACMQ550I_st;
#define SZ_SACMQ550I    sizeof(SACMQ550I_st)

typedef struct _SACMQ550O_
{
    char	Out	[5];	//	
} SACMQ550O_st,   * lpSACMQ550O_st;
#define SZ_SACMQ550O    sizeof(SACMQ550O_st)

typedef struct _SACMQ550Sub_
{
	char    TrxDt		[8];	//  처리일
    char	TrxSeqno	[10];	//	처리일련번호
    char	PrslRmnno	[13];	//	신청인주민번호
    char	TrxTpNm1	[20];	//	처리구분명1
    char	YnNm1	[10];	//	여부명
    char	TrxResltMsg	[40];	//	처리결과메세지
    char	RcptDt	[8];	//	접수일
    char	RcptTime	[9];	//	접수시각
    char	PrslNm	[40];	//	신청인성명
    char	PrslHpNo	[30];	//	신청인휴대전화번호
    char	PrslEmail	[50];	//	신청인이메일
    char	HomeAddrChgYn	[1];	//	자택주소변경여부
    char	HomePostNo	[6];	//	자택우편번호
    char	HomeAbdngAddr	[100];	//	자택동이상주소
    char	HomeBlwdngAddr2	[100];	//	자택동이하주소2
    char	WkplcAddrChgYn	[1];	//	직장주소변경여부
    char	WkplcPostNo	[6];	//	직장우편번호
    char	WkplcAbdngAddr	[100];	//	직장동이상주소
    char	WkplcBlwdngAddr	[100];	//	직장동이하주소
    char	SndIttNm	[40];	//	송신기관명
    char	SndIttBrnNm	[40];	//	송신지점명
    char	TrxBrnNm	[40];	//	처리지점명
    char	TrxDttm	[17];	//	처리일시
    char	TrxUserId	[16];	//	처리사용자ID
    char	TrxTermNo	[3];	//	처리단말번호
    char	ClntNo	[20];	//	고객번호
} SACMQ550Sub_st,   * lpSACMQ550Sub_st;
#define SZ_SACMQ550Sub    sizeof(SACMQ550Sub_st)

//////////////////////////////////////////////////////////////////
typedef struct _SACMQ217I_
{
    char    In  [5];    //
    char    Accno  [20];   //  고객번호
    char    Pwd   [8];    //  처리구분
} SACMQ217I_st,   * lpSACMQ217I_st;
#define SZ_SACMQ217I    sizeof(SACMQ217I_st)

typedef struct _SACMQ217O_
{
    char    Out [5];    //
} SACMQ217O_st,   * lpSACMQ217O_st;
#define SZ_SACMQ217O    sizeof(SACMQ217O_st)

typedef struct _SACMQ217Sub_
{
    char PostNo              [  6]; // 우편번호 X(6)
    char Addr                [100]; // 주소 X(100)
    char AbdngAddr           [100]; // 동이상주소 X(100)
    char BlwdngAddr          [100]; // 동이하주소 X(100)
    char TelRgno             [  4]; // 전화지역번호 X(4)
    char TelExno             [  4]; // 전화국번호 X(4)
    char TelSeqno            [  4]; // 전화일련번호 X(4)
    char FaxRgno             [  4]; // 팩스지역번호 X(4)
    char FaxExno             [  4]; // 팩스국번호 X(4)
    char FaxSeqno            [  4]; // 팩스일련번호 X(4)
    char Out2                [  5]; // X(5) 
    char PostNo1              [  6]; // 우편번호 X(6)
    char Addr1                [100]; // 주소 X(100)
    char AbdngAddr1           [100]; // 동이상주소 X(100)
    char BlwdngAddr1          [100]; // 동이하주소 X(100)
    char TelRgno1             [  4]; // 전화지역번호 X(4)
    char TelExno1             [  4]; // 전화국번호 X(4)
    char TelSeqno1            [  4]; // 전화일련번호 X(4)
    char FaxRgno1             [  4]; // 팩스지역번호 X(4)
    char FaxExno1             [  4]; // 팩스국번호 X(4)
    char FaxSeqno1            [  4]; // 팩스일련번호 X(4)
    char WkplcNm             [ 40]; // 직장명 X(40)
    char Out3                [  5]; // X(5) 
    char PostNo2              [  6]; // 우편번호 X(6)
    char Addr2                [100]; // 주소 X(100)
    char AbdngAddr2           [100]; // 동이상주소 X(100)
    char BlwdngAddr2          [100]; // 동이하주소 X(100)
    char TelRgno2             [  4]; // 전화지역번호 X(4)
    char TelExno2             [  4]; // 전화국번호 X(4)
    char TelSeqno2            [  4]; // 전화일련번호 X(4)
    char FaxRgno2             [  4]; // 팩스지역번호 X(4)
    char FaxExno2             [  4]; // 팩스국번호 X(4)
    char FaxSeqno2            [  4]; // 팩스일련번호 X(4)
    char Out4                [  5]; // X(5) 
    char EmailAddr           [100]; // 이메일주소 X(100)
    char MoveTelIdfyNo       [  4]; // 이동전화식별번호 X(4)
    char MoveTelExno         [  4]; // 이동전화국번호 X(4)
    char MoveTelSeqno        [  4]; // 이동전화일련번호 X(4)
    char HpRgno              [  4]; // 휴대폰지역번호 X(4)
    char HpExno              [  4]; // 휴대폰국번호 X(4)
    char HpSeqno             [  4]; // 휴대폰일련번호 X(4)
    char Out5                [  5]; // X(5) 
    char AcntNm              [ 40]; // 계좌명 X(40)
} SACMQ217Sub_st,   * lpSACMQ217Sub_st;
#define SZ_SACMQ217Sub    sizeof(SACMQ217Sub_st)
    
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
// 지출결의서 내역  
///////////////////////////////////////////////////////////////
typedef struct _SIAGQ045I_
{
	char In                  [  5]; //  
    char ActgBrnNo           [  3]; // 회계지점번호 X(3)
    char AccCode             [  9]; // 계정코드 X(9)
    char BdgtCode            [  9]; // 예산코드 X(9)
    char SrtDt               [  8]; // 시작일 X(8)
    char EndDt               [  8]; // 종료일 X(8)
    char QryTp               [  1]; // 조회구분 X(1)
    char ActgBaseTp          [  1]; // 회계기준구분 X(1)
} SIAGQ045I_st,   * lpSIAGQ045I_st;
#define SZ_SIAGQ045I    sizeof(SIAGQ045I_st)

typedef struct _SIAGQ045O_
{
    char Out                 [  5]; //  
    char ActgBrnNm           [ 40]; // 회계지점명 X(40)
    char AccNm               [ 50]; // 계정명 X(50)
    char BdgtNm              [ 50]; // 예산명 X(50)
    char SumAmt              [ 16]; // 합계금액 S9(15)
    char OutLst              [  5]; //  
} SIAGQ045O_st,   * lpSIAGQ045O_st;
#define SZ_SIAGQ045O    sizeof(SIAGQ045O_st)

typedef struct _SIAGQ045Sub_
{
    char RslnDt              [  8]; // 결의일 X(8)
    char RslnSeqno           [ 10]; // 결의서일련번호 S9(9)
    char RslnBrnNo           [  3]; // 결의서지점번호 X(3)
    char RslnBrnNm           [ 40]; // 결의서지점명 X(40)
    char SmryDtlCnts1        [100]; // 적요상세내용1 X(100)
    char SmryDtlCnts2        [100]; // 적요상세내용2 X(100)
    char RslnAmt             [ 16]; // 결의서금액 S9(15)
    char CnfrDt              [  8]; // 품의일 X(8)
    char AgrmDt              [  8]; // 승인일 X(8)
    char SlpAprvDt           [  8]; // 전표결재일 X(8)
    char SlpNo               [ 10]; // 전표번호 S9(9)
    char EmpNo               [  9]; // 사원번호 X(9)
    char TrdTpNm1            [ 20]; // 거래구분명1 X(20)
    char AccNm1              [ 50]; // 계정명1 X(50)
    char TpNm1               [ 40]; // 구분명1 X(40)
    char ActgBaseTp          [  1]; // 회계기준구분 X(1)
} SIAGQ045Sub_st,   * lpSIAGQ045Sub_st;
#define SZ_SIAGQ045Sub    sizeof(SIAGQ045Sub_st)

///////////////////////////////////////////////////////////////
// 자기채권 체결기준 매매내역
///////////////////////////////////////////////////////////////
typedef struct _SSEBQ311I_
{
	char In                  [  5]; //  
    char QrySrtDt            [  8]; // 조회시작일 X(8)
    char QryEndDt            [  8]; // 조회종료일 X(8)
    char FundOpAcntNo        [ 20]; // 펀드운용계좌번호 X(20)
    char SettDays            [  6]; // 결제일수 S9(5)
    char BnsTp               [  1]; // 매매구분 X(1)
    char CreBaseCode         [  2]; // 생성기준코드 X(2)
    char BnsCharTp           [  1]; // 매매성격구분 X(1)
    char QryTp               [  1]; // 조회구분 X(1)
    char BrnNo               [  3]; // 지점번호 X(3)
} SSEBQ311I_st,   * lpSSEBQ311I_st;
#define SZ_SSEBQ311I    sizeof(SSEBQ311I_st)

typedef struct _SSEBQ311O_
{
	char In                  [  5]; //
    char QrySrtDt            [  8]; // 조회시작일 X(8)
    char QryEndDt            [  8]; // 조회종료일 X(8)
    char FundOpAcntNo        [ 20]; // 펀드운용계좌번호 X(20)
    char SettDays            [  6]; // 결제일수 S9(5)
    char BnsTp               [  1]; // 매매구분 X(1)
    char CreBaseCode         [  2]; // 생성기준코드 X(2)
    char BnsCharTp           [  1]; // 매매성격구분 X(1)
    char QryTp               [  1]; // 조회구분 X(1)
    char BrnNo               [  3]; // 지점번호 X(3)
    char Out                 [  5]; // X(5) 
    char FirmNm              [ 50]; // 이용사명 X(50)
    char NowDt               [  8]; // 현재일 X(8)
    char FundOpAcntNo2        [ 20]; // 펀드운용계좌번호 X(20)
    char FundNm              [ 40]; // 펀드명 X(40)
    char BnsTpNm             [ 10]; // 매매구분 X(10)
    char SettTpNm            [ 41]; // 결제구분명 X(41)
    char CreBaseNm           [ 40]; // 생성기준명 X(40)
	char Tot				 [  5];
	char Qty1                [ 16]; // 수량1 S9(15)
    char Qty2                [ 16]; // 수량2 S9(15)
    char SellBookAmt         [ 16]; // 매도장부금액 S9(15)
    char BuyBookAmt          [ 16]; // 매수장부금액 S9(15)
    char BuyAmt              [ 16]; // 매수금액 S9(15)
    char SellAmt             [ 16]; // 매도금액 S9(15)
    char PassIntrstAmt1      [ 16]; // 경과이자1 S9(15)
    char PassIntrstAmt2      [ 16]; // 경과이자2 S9(15)
    char PassIntrstAmt3      [ 16]; // 경과이자3 S9(15)
    char PassIntrstAmt4      [ 16]; // 경과이자4 S9(15)
    char RpPrcvAmt           [ 16]; // RP선수금액 S9(15)
    char AcmRpPrcvAmt        [ 16]; // 누적RP선수금액 S9(15)
    char RpSellLossAmt       [ 16]; // RP매도손실금액 S9(15)
    char RpBuyAmt            [ 16]; // RP매수금액 S9(15)
    char BndIntrstAmt        [ 16]; // 채권이자금액 S9(15)
    char AcmBndIntrstAmt     [ 16]; // 누적채권이자금액 S9(15)
    char RcvblBndIntrstAmt   [ 16]; // 미수채권이자금액 S9(15)
    char AcmRcvblIntrstAmt   [ 16]; // 누적미수이자금액 S9(15)
    char PrepayCorpTax       [ 16]; // 선급법인세 S9(15)
    char AcmPrepayCorpTax    [ 16]; // 누적선급법인세 S9(15)
    char Corptax1            [ 16]; // 법인세 S9(15)
    char Corptax2            [ 16]; // 법인세 S9(15)
    char Taxwtd              [ 16]; // 제세예수금 S9(15)
    char AcmTaxwtd           [ 16]; // 누적제세예수금 S9(15)
    char RfundLossAmt        [ 16]; // 상환손실금액 S9(15)
    char AcmRfundLossAmt     [ 16]; // 누적상환손실금액 S9(15)
    char RfundPrftAmt        [ 16]; // 상환이익금액 S9(15)
    char AcmRfundPrftAmt     [ 16]; // 누적상환이익금액 S9(15)
    char SbrwAmt             [ 16]; // 대차금액 S9(15)
    char PassIntrstAmt5      [ 16]; // 경과이자5 S9(15)
    char TotIntrstAmt        [ 16]; // 총이자금액 S9(15)
    char IntrstAmt           [ 16]; // 이자금액 S9(15)
    char IntrstAmt2          [ 16]; // 이자금액2 S9(15)
    char Ihtax1              [ 16]; // 주민세 S9(15)
    char Ihtax2              [ 16]; // 주민세 S9(15)
	char Out2				 [  5];

} SSEBQ311O_st,   * lpSSEBQ311O_st;
#define SZ_SSEBQ311O    sizeof(SSEBQ311O_st)

typedef struct _SSEBQ311Sub1_
{
    char Qty1                [ 16]; // 수량1 S9(15)
    char Qty2                [ 16]; // 수량2 S9(15)
    char SellBookAmt         [ 16]; // 매도장부금액 S9(15)
    char BuyBookAmt          [ 16]; // 매수장부금액 S9(15)
    char BuyAmt              [ 16]; // 매수금액 S9(15)
    char SellAmt             [ 16]; // 매도금액 S9(15)
    char PassIntrstAmt1      [ 16]; // 경과이자1 S9(15)
    char PassIntrstAmt2      [ 16]; // 경과이자2 S9(15)
    char PassIntrstAmt3      [ 16]; // 경과이자3 S9(15)
    char PassIntrstAmt4      [ 16]; // 경과이자4 S9(15)
    char RpPrcvAmt           [ 16]; // RP선수금액 S9(15)
    char AcmRpPrcvAmt        [ 16]; // 누적RP선수금액 S9(15)
    char RpSellLossAmt       [ 16]; // RP매도손실금액 S9(15)
    char RpBuyAmt            [ 16]; // RP매수금액 S9(15)
    char BndIntrstAmt        [ 16]; // 채권이자금액 S9(15)
    char AcmBndIntrstAmt     [ 16]; // 누적채권이자금액 S9(15)
    char RcvblBndIntrstAmt   [ 16]; // 미수채권이자금액 S9(15)
    char AcmRcvblIntrstAmt   [ 16]; // 누적미수이자금액 S9(15)
    char PrepayCorpTax       [ 16]; // 선급법인세 S9(15)
    char AcmPrepayCorpTax    [ 16]; // 누적선급법인세 S9(15)
    char Corptax1            [ 16]; // 법인세 S9(15)
    char Corptax2            [ 16]; // 법인세 S9(15)
    char Taxwtd              [ 16]; // 제세예수금 S9(15)
    char AcmTaxwtd           [ 16]; // 누적제세예수금 S9(15)
    char RfundLossAmt        [ 16]; // 상환손실금액 S9(15)
    char AcmRfundLossAmt     [ 16]; // 누적상환손실금액 S9(15)
    char RfundPrftAmt        [ 16]; // 상환이익금액 S9(15)
    char AcmRfundPrftAmt     [ 16]; // 누적상환이익금액 S9(15)
    char SbrwAmt             [ 16]; // 대차금액 S9(15)
    char PassIntrstAmt5      [ 16]; // 경과이자5 S9(15)
    char TotIntrstAmt        [ 16]; // 총이자금액 S9(15)
    char IntrstAmt           [ 16]; // 이자금액 S9(15)
    char IntrstAmt2          [ 16]; // 이자금액2 S9(15)
    char Ihtax1              [ 16]; // 주민세 S9(15)
    char Ihtax2              [ 16]; // 주민세 S9(15)
} SSEBQ311Sub1_st,   * lpSSEBQ311Sub1_st;
#define SZ_SSEBQ311Sub1    sizeof(SSEBQ311Sub1_st)


typedef struct _SSEBQ311Sub2_
{
    char TrdDt               [  8]; // 거래일 X(8)
    char SmryNm              [ 40]; // 적요명 X(40)
    char BnsTpNm             [ 10]; // 매매구분 X(10)
    char SettTpNm            [ 41]; // 결제구분명 X(41)
    char TpNm1               [ 40]; // 구분명1 X(40)
    char IsuNm               [ 40]; // 종목명 X(40)
    char BndTpNm             [ 20]; // 채권구분 X(20)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char BnsQty              [ 16]; // 매매수량 S9(15)
    char BnsBndErnrat        [ 12]; // 매매채권수익률 S9(4).9(6)
    char ExecTime            [  9]; // 체결시각 X(9)
    char BookUprc            [ 15]; // 장부단가 S9(9).9(4)
    char BnsUprc             [ 20]; // 매매단가 S9(14).9(4)
    char BookAmt             [ 16]; // 장부금액 S9(15)
    char BnsAmt              [ 16]; // 매매금액 S9(15)
    char PassIntrstAmt       [ 16]; // 경과이자금액 S9(15)
    char RpPassIntrstAmt     [ 16]; // RP경과이자금액 S9(15)
    char RpPrcvAmt           [ 16]; // RP선수금액 S9(15)
    char RpSellLossAmt       [ 16]; // RP매도손실금액 S9(15)
    char BndIntrstAmt        [ 16]; // 채권이자금액 S9(15)
    char RcvblIntrstAmt      [ 16]; // 미수이자금액 S9(15)
    char PrepayCorpTax       [ 16]; // 선급법인세 S9(15)
    char CorpTaxDps          [ 16]; // 법인세예수금 S9(15)
    char Taxwtd              [ 16]; // 제세예수금 S9(15)
    char UprcTpNm            [ 20]; // 단가구분 X(20)
    char RfundPrftAmt        [ 16]; // 상환이익금액 S9(15)
    char RfundLossAmt        [ 16]; // 상환손실금액 S9(15)
    char OppTrdAcntNm        [ 40]; // 상대거래계좌명 X(40)
    char CmsnAmt             [ 16]; // 수수료 S9(15)
    char EvalUprc            [ 15]; // 평가단가 S9(9).9(4)
    char RemnDays            [  6]; // 잔존일수 S9(5)
    char EvalAmt             [ 16]; // 평가금액 S9(15)
    char SbrwAmt             [ 16]; // 대차금액 S9(15)
    char PassIntrstAmt5      [ 16]; // 경과이자5 S9(15)
    char TotIntrstAmt        [ 16]; // 총이자금액 S9(15)
    char BuyDt               [  8]; // 매수일 X(8)
    char BuyUprc             [ 15]; // 매수단가 S9(9).9(4)
    char TaxchrIntrstAmt1    [ 16]; // 과세이자금액1 S9(15)
    char EvalErnrat          [ 12]; // 평가수익률 S9(4).9(6)
    char BnsCharTp           [  1]; // 매매성격구분 X(1)
    char BnsCharTpNm         [ 20]; // 매매성격구분 X(20)
    char FundOpAcntNo        [ 20]; // 펀드운용계좌번호 X(20)
    char Ihtax               [ 16]; // 주민세 S9(15)
} SSEBQ311Sub2_st,   * lpSSEBQ311Sub2_st;
#define SZ_SSEBQ311Sub2    sizeof(SSEBQ311Sub2_st)



/////////////////////////////////////////////////////////////////
// 편익 제공내역 
/////////////////////////////////////////////////////////////////
typedef struct _SADNQ062I_
{
	char In                  [  5]; //  
    char BrnNo               [  3]; // 지점번호 X(3)
    char QrySrtDt            [  8]; // 조회시작일 X(8)
    char QryEndDt            [  8]; // 조회종료일 X(8)
    char QryTp               [  1]; // 조회구분 X(1)
    char MgempNo             [  9]; // 관리사원번호 X(9)
    char AcptPsnNm           [ 40]; // 수령자명 X(40)
    char OtptTp              [  1]; // 출력구분 X(1)
    char SumAmt1             [ 16]; // 합계금액1 S9(15)
    char Tp                  [  1]; // 구분 X(1)
    char EmpTp               [  1]; // 사원구분 X(1)
} SADNQ062I_st,   * lpSADNQ062I_st;
#define SZ_SADNQ062I    sizeof(SADNQ062I_st)

typedef struct _SADNQ062M_
{
	char In                  [  5]; //
    char BrnNo               [  3]; // 지점번호 X(3)
    char QrySrtDt            [  8]; // 조회시작일 X(8)
    char QryEndDt            [  8]; // 조회종료일 X(8)
    char QryTp               [  1]; // 조회구분 X(1)
    char MgempNo             [  9]; // 관리사원번호 X(9)
    char AcptPsnNm           [ 40]; // 수령자명 X(40)
    char OtptTp              [  1]; // 출력구분 X(1)
    char SumAmt1             [ 16]; // 합계금액1 S9(15)
    char Tp                  [  1]; // 구분 X(1)
    char EmpTp               [  1]; // 사원구분 X(1)
	char Out                 [  5]; //
    char BrnNm               [ 40]; // 지점명 X(40)
    char OutLst              [  5]; //

}   SADNQ062M_st,   * lpSADNQ062M_st;
#define SZ_SADNQ062M    sizeof(SADNQ062M_st)

typedef struct _SADNQ062O_
{
    char AcptPsnNm           [ 40]; // 수령자명 X(40)
    char AcptPsnCoNm         [ 40]; // 수령자회사명 X(40)
    char AcptPsnSubAtgrp     [ 40]; // 수령자부서명 X(40)
    char EntmtPsnNm          [ 50]; // 접대자명 X(50)
    char EntmtCustNm         [ 50]; // 접대거래처명 X(50)
    char EntmtPsnSubAtgrp    [ 50]; // 접대자부서명 X(50)
    char CardEntmtAmt        [ 16]; // 카드접대금액 S9(15)
    char MnyEntmtAmt         [ 16]; // 현금접대금액 S9(15)
    char SumAmt              [ 16]; // 합계금액 S9(15)
    char RslnDt              [  8]; // 결의일 X(8)
    char RslnNo              [ 10]; // 결의서번호 S9(9)
    char PrvdRsn             [100]; // 제공사유 X(100)
    char UseIndtpNm          [ 40]; // 사용업종명 X(40)
    char CrdtCardNo          [ 20]; // 신용카드번호 X(20)
    char OthprtyNm           [ 40]; // 상대방명 X(40)
    char PrvdDt              [  8]; // 제공일 X(8)
    char Rmk                 [100]; // 비고 X(100)
    char MobilNo             [ 16]; // 핸드폰번호 X(16)
    char AdtRealCnfYn        [  1]; // 감사실확인여부 X(1)
    char AgrmPsnId           [ 16]; // 승인자ID X(16)
    char GongjikTp           [  2]; // 공직자구분 X(2)
    char LmtAmt              [ 16]; // 한도금액 S9(15)
    char YearAcmAmt          [ 16]; // 년간금액 S9(15)
}   SADNQ062O_st,   * lpSADNQ062O_st;
#define SZ_SADNQ062O    sizeof(SADNQ062O_st)
/////////////////////////////////////////////////////////////////
// 계좌 정보 변경
/////////////////////////////////////////////////////////////////
typedef struct _SACMT205I_
{
	char In                  [  5]; //  
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char InptPwd             [  8]; // 입력비밀번호 X(8)
    char PdptnCode           [  2]; // 상품유형코드 X(2)
    char AcntNm              [ 40]; // 계좌명 X(40)
    char AcntHanglAlias      [ 40]; // 계좌한글부기명 X(40)
    char AcntEngAlias        [ 40]; // 계좌영문부기명 X(40)
    char WthldEntruYn        [  1]; // 원천징수위임여부 X(1)
    char LedgSdinfAddrPtnCode[  2]; // 원장통보주소유형코드 X(2)
    char BnsSdinfAddrPtnCode [  2]; // 매매통보주소유형코드 X(2)
    char EtcPtmtrSdinfAddrPtnCode[  2]; // 기타우편물통보주소유형코드 X(2)
    char AgrmReqstDt         [  8]; // 승인요청일 X(8)
    char AgrmAddMsg          [100]; // 승인자추가메시지 X(100)
    char AgrmUserNm          [ 40]; // 승인사용자명 X(40)
    char AgrmTrxId           [  8]; // 승인처리ID X(8)
    char LastAgrmUserId      [ 16]; // 최종승인자ID X(16)
    char TrxObjTp            [  1]; // 처리대상구분 X(1)
    char csgn                [  5]; //  
    char UnuslAcntClssCode   [  2]; // 특이계좌분류코드 X(2)
    char TrdSecPtnCode       [  2]; // 거래유가증권유형코드 X(2)
    char MgnLevyPtnCode      [  2]; // 증거금징수유형코드 X(2)
    char TrtaxLevyYn         [  1]; // 거래세징수여부 X(1)
    char CsgnInvstrClssCode  [  4]; // 위탁투자자분류코드 X(4)
    char secSav              [  5]; //  
    char PayMthdCode         [  2]; // 납입방법코드 X(2)
    char CvntTermMthQty      [  6]; // 계약기간월수 S9(5)
    char UnitPayAmt          [ 16]; // 단위납입금액 S9(15)
    char TrdSecPtnCode2      [  2]; // 거래유가증권유형코드 X(2)
    char LhfrmJoinCode       [  2]; // 생계형가입코드 X(2)
    char fno                 [  5]; //  
    char RegMktCode          [  2]; // 등록시장코드 X(2)
    char CsgnSfaccCode       [  2]; // 위탁자기코드 X(2)
    char FnoAcntAfmgnCode    [  2]; // 선물옵션계좌사후증거금코드 X(2)
    char KfxInvstrClssCode   [  3]; // 코펙스투자자분류코드 X(3)
    char KfxRglmbNo          [  3]; // 코펙스정회원번호 X(3)
    char TrtaxLevyYn2        [  1]; // 거래세징수여부 X(1)
    char ivtrst              [  5]; //  
    char IvtrstInvstrClssCode[  4]; // 투자신탁투자자분류코드 X(4)
}   SACMT205I_st,   * lpSACMT205I_st;
#define SZ_SACMT205I    sizeof(SACMT205I_st)

typedef struct _SACMT205O_
{
    char Out                 [  5]; //  
    char PrdtDtlNm           [ 40]; // 상품상세명 X(40)
    char IntaccNo            [ 20]; // 종합계좌번호 X(20)
    char DueDt               [  8]; // 만기일 X(8)
    char CvntAmt             [ 16]; // 계약금액 S9(15)
    char KfxAcntNo           [ 20]; // 코펙스계좌번호 X(20)
    char AgrmMthdCode        [  2]; // 승인방식코드 X(2)
}   SACMT205O_st,   * lpSACMT205O_st;
#define SZ_SACMT205O    sizeof(SACMT205O_st)

/////////////////////////////////////////////////////////////////
// 계좌 비밀번호 검증
/////////////////////////////////////////////////////////////////
typedef struct _SACMQ226I_
{
    char    In                  [ 5];   // 레코드갯수
    char    AcntNo              [20];   // 계좌번호
    char    AcntClssTp          [ 1];   // 계좌계층구분
    char    InptPwd             [ 8];   // 입력비밀번호
}   SACMQ226I_st,   * lpSACMQ226I_st;
#define SZ_SACMQ226I    sizeof(SACMQ226I_st)

typedef struct _SACMQ226O_
{
    char    In                  [ 5];   // 레코드갯수
    char    AcntNo              [20];   // 계좌번호
    char    AcntClssTp          [ 1];   // 계좌계층구분
    char    InptPwd             [ 8];   // 입력비밀번호

    char    Out                 [ 5];   // 레코드갯수
    char    AcntNm              [40];   // 계좌명
    char    AvalYn              [ 1];   // 유효여부
    char    ClntNo              [20];   // 고객번호
    char    AppCnt              [ 6];   // 적용횟수
    char    PwdContErrcnt       [10];   // 비밀번호연속오류횟수
}   SACMQ226O_st,   * lpSACMQ226O_st;
#define SZ_SACMQ226O    sizeof(SACMQ226O_st)

/***********************************************************************
* 주문가능금액상세
 ***********************************************************************/
typedef struct
{
	char In                  [  5]; // X(5) 
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char Pwd                 [  8]; // 비밀번호 X(8)
} SONAQ225_IN, * lpSONAQ225_IN;
#define SZ_SONAQ225_IN  sizeof(SONAQ225_IN)

typedef struct
{
	char Out                 [  5]; // X(5) 
    char AcntNm              [ 40]; // 계좌명 X(40)
    char MnyMgnRat           [  7]; // 현금증거금률 S9.9(4)
    char SubstMgnRat         [ 11]; // 대용증거금률 S9.9(8)
    char MgnLevyPtnCode      [  2]; // 증거금징수유형코드 X(2)
    char MgnLevyPtnNm        [ 40]; // 증거금징수유형명 X(40)
    char SellTrdStopYn       [  1]; // 매도거래정지여부 X(1)
    char BuyTrdStopYn        [  1]; // 매수거래정지여부 X(1)
    char CtinfoPrvdAgrmYn    [  1]; // 신용정보제공동의여부 X(1)
    char RcsecCnt            [ 10]; // 미수유가횟수 S9(9)
    char Dps                 [ 16]; // 예수금 S9(15)
    char SubstAmt            [ 16]; // 대용금액 S9(15)
    char MnyMgn              [ 16]; // 현금증거금액 S9(15)
    char SubstMgn            [ 16]; // 대용증거금액 S9(15)
    char OrdCms              [ 16]; // 주문수수료 S9(15)
    char MnyOrdAbleAmt       [ 16]; // 현금주문가능금액 S9(15)
    char SubstOrdAbleAmt     [ 16]; // 대용주문가능금액 S9(15)
    char CrdtPldgMnyRuseAmt  [ 16]; // 신용담보현금재사용금액 S9(15)
    char UnercBuyOrdAmt      [ 16]; // 미체결매수주문금액 S9(15)
    char SellSubstOfstAmt    [ 16]; // 매도대용차감금액 S9(15)
    char SellAdjstAmt        [ 16]; // 매도정산금액 S9(15)
    char BuyAdjstAmt         [ 16]; // 매수정산금액 S9(15)
    char D2ordAbleAmt        [ 16]; // D2주문가능금액 S9(15)
    char CrdayCrdtPldgMny    [ 16]; // 금일신용담보현금 S9(15)
    char PrdayCrdtPldgMny    [ 16]; // 전일신용담보현금 S9(15)
    char PldgSubstAmt        [ 16]; // 담보대용금액 S9(15)
    char MnyRuseObjAmt       [ 16]; // 현금재사용대상금액 S9(15)
    char SubstRuseObjAmt     [ 16]; // 대용재사용대상금액 S9(15)
    char RcvblTotamt         [ 16]; // 미수총액 S9(15)
    char SpotSellTnovrDt     [  8]; // 실물매도전환일 X(8)
    char RuseSpotTnovrAmt    [ 16]; // 재사용실물전환금액 S9(15)
    char MnySpotTnovrAmt     [ 16]; // 현금실물전환금액 S9(15)
    char SubstSpotTnovrAmt   [ 16]; // 대용실물전환금액 S9(15)
    char MnyRuseUseAmt       [ 16]; // 현금재사용사용금액 S9(15)
    char SubstRuseUseAmt     [ 16]; // 대용재사용사용금액 S9(15)
    char PrdayBuyExecAmt     [ 16]; // 전일매수체결금액 S9(15)
    char PrdaySellExecAmt    [ 16]; // 전일매도체결금액 S9(15)
    char CrdayBuyExecAmt     [ 16]; // 금일매수체결금액 S9(15)
    char CrdaySellExecAmt    [ 16]; // 금일매도체결금액 S9(15)
    char SubstOrdAmt         [ 16]; // 대용주문금액 S9(15)
    char SeOrdAbleAmt        [ 16]; // 거래소금액 S9(15)
    char KdqOrdAbleAmt       [ 16]; // 코스닥금액 S9(15)
    char HtsOrdAbleAmt       [ 16]; // HTS주문가능금액 S9(15)
    char MgnRat100pctOrdAbleAmt[ 16]; // 증거금률100퍼센트주문가능금액 S9(15)
    char D1dps               [ 16]; // D1예수금 S9(15)
    char D2dps               [ 16]; // D2예수금 S9(15)
    char D1SubstAmt          [ 16]; // D1대용금 S9(15)
    char D2SubstAmt          [ 16]; // D2대용금 S9(15)
    char EvalAmt             [ 16]; // 평가금액 S9(15)
    char DpsastTotamt        [ 16]; // 예탁자산총액 S9(15)
    char Amt1                [ 16]; // 금액1 S9(15)
    char Amt2                [ 16]; // 금액2 S9(15)
    char Amt3                [ 16]; // 금액3 S9(15)
    char Amt4                [ 16]; // 금액4 S9(15)
    char Amt5                [ 16]; // 금액5 S9(15)
    char Amt6                [ 16]; // 금액6 S9(15)
    char CprcEvalAmt         [ 16]; // 종가평가금액 S9(15)
    char Amt7                [ 16]; // 금액7 S9(15)
    char Amt8                [ 16]; // 금액8 S9(15)
    char Amt9                [ 16]; // 금액9 S9(15)
    char Amt10               [ 16]; // 금액10 S9(15)
    char Amt11               [ 16]; // 금액11 S9(15)	
} SONAQ225_OUT, * lpSONAQ225_OUT;
#define SZ_SONAQ225_OUT  sizeof(SONAQ225_OUT)


/***********************************************************************
 * 현물계좌별 DT 주문체결
 ***********************************************************************/
typedef struct
{
	char In                  [  5]; //  
    char ExecYn              [  1]; // 체결여부 X(1)
    char BnsTp               [  1]; // 매매구분 X(1)
    char IsuTp               [  1]; // 종목구분 X(1)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char InptPwd             [  8]; // 입력비밀번호 X(8)
    char QryTp               [  1]; // 조회구분 X(1)
} SONAQ051_IN, * lpSONAQ051_IN;
#define SZ_SONAQ051_IN  sizeof(SONAQ051_IN)

typedef struct
{
	char In                  [  5]; //
    char ExecYn              [  1]; // 체결여부 X(1)
    char BnsTp               [  1]; // 매매구분 X(1)
    char IsuTp               [  1]; // 종목구분 X(1)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char InptPwd             [  8]; // 입력비밀번호 X(8)
    char QryTp               [  1]; // 조회구분 X(1)
    char Out                 [  5]; //  
    char SellExecQty         [ 16]; // 매도체결수량 S9(15)
    char BuyExecQty          [ 16]; // 매수체결수량 S9(15)
    char SellExecAmt         [ 16]; // 매도체결금액 S9(15)
    char BuyExecAmt          [ 16]; // 매수체결금액 S9(15)
    char ST_OUT              [  5]; //  
}	SONAQ051_OUT, * lpSONAQ051_OUT;
#define SZ_SONAQ051_OUT  sizeof(SONAQ051_OUT)

typedef struct
{
    char OrdNo               [ 10]; // 주문번호 S9(9)
    char OrgOrdNo            [ 10]; // 원주문번호 S9(9)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char OrdMktCode          [  2]; // 주문시장코드 X(2)
    char BnsTp               [  1]; // 매매구분 X(1)
    char OrdPtnCode          [  2]; // 주문유형코드 X(2)
    char OrdprcPtnCode       [  2]; // 호가유형코드 X(2)
    char OrdQty              [ 16]; // 주문수량 S9(15)
    char OrdPrc              [ 13]; // 주문가 S9(9).99
    char AllExecQty          [ 16]; // 전체체결수량 S9(15)
    char MrcAbleQty          [ 16]; // 정정취소가능수량 S9(15)
    char AvrExecPrc          [ 13]; // 평균체결가 S9(9).99
    char MrcQty              [ 16]; // 정정취소수량 S9(15)
    char MgntrnCode          [  3]; // 신용거래코드 X(3)
    char LoanDt              [  8]; // 대출일 X(8)
    char OrdTrxPtnCode       [  9]; // 주문처리유형코드 S9(8)
    char TrxTime             [  9]; // 처리시각 X(9)
    char UserId              [ 16]; // 사용자ID X(16)
    char OrdCndiTp           [  1]; // 주문조건구분 X(1)
    char CommdaCode          [  2]; // 통신매체코드 X(2)
    char MgempNo             [  9]; // 관리사원번호 X(9)
    char ConnClssCode        [  2]; // 접속분류코드 X(2)
    char MtiordSeqno         [ 10]; // 복수주문일련번호 S9(9)
    char GrpNo               [ 20]; // 그룹번호 X(20)
} SONAQ051_Sub, * lpSONAQ051_Sub;
#define SZ_SONAQ051_Sub  sizeof(SONAQ051_Sub)


/***********************************************************************
 * 현물계좌별 주문체결
 ***********************************************************************/
typedef struct
{
    char In                  [  5]; //  
    char MgmtBrnNo           [  3]; // 관리지점번호 X(3)
    char OrdMktCode          [  2]; // 주문시장코드 X(2)
    char OrdNo               [ 10]; // 주문번호 S9(9)
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char OrdDt               [  8]; // 주문일 X(8)
    char OrdTrxPtnCode       [  9]; // 주문처리유형코드 S9(8)
    char IsuNo               [ 12]; // 종목번호 X(12)
} SONAQ010_IN, * lpSONAQ010_IN;
#define SZ_SONAQ010_IN  sizeof(SONAQ010_IN)

typedef struct
{
	char In                  [  5]; //
    char MgmtBrnNo           [  3]; // 관리지점번호 X(3)
    char OrdMktCode          [  2]; // 주문시장코드 X(2)
    char OrdNo               [ 10]; // 주문번호 S9(9)
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char OrdDt               [  8]; // 주문일 X(8)
    char OrdTrxPtnCode       [  9]; // 주문처리유형코드 S9(8)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char Out         		 [  5]; //  
} SONAQ010_OUT, * lpSONAQ010_OUT;
#define SZ_SONAQ010_OUT  sizeof(SONAQ010_OUT)

typedef struct
{
    char OrdNo               [ 10]; // 주문번호 S9(9)
    char OrgOrdNo            [ 10]; // 원주문번호 S9(9)
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char AcntNm              [ 40]; // 계좌명 X(40)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char IsuNm               [ 40]; // 종목명 X(40)
    char OrdPtnNm            [ 40]; // 주문유형명 X(40)
    char OrdQty              [ 16]; // 주문수량 S9(15)
    char OrdPrc              [ 13]; // 주문가 S9(9).99
    char OrdTrxPtnCode       [  9]; // 주문처리유형코드 S9(8)
    char OrdTrxPtnNm         [ 50]; // 주문처리유형명 X(50)
    char CommdaCode          [  2]; // 통신매체코드 X(2)
    char CommdaNm            [ 40]; // 통신매체명 X(40)
    char Rmk                 [100]; // 비고 X(100)
    char BnsTpNm             [ 10]; // 매매구분 X(10)
    char MrcNm               [ 20]; // 정정취소명 X(20)
    char RjtRsn              [100]; // 거부사유 X(100)
    char OrdprcPtnNm         [ 40]; // 호가유형명 X(40)
    char OrdDt               [  8]; // 주문일 X(8)
} SONAQ010_Sub, * lpSONAQ010_Sub;
#define SZ_SONAQ010_Sub  sizeof(SONAQ010_Sub)
/***********************************************************************
 * 현물계좌별 주문체결 
 ***********************************************************************/
typedef struct
{
	char In                  [  5]; //  
	char AcntNo              [ 20]; // 계좌번호 X(20)
    char InptPwd             [  8]; // 입력비밀번호 X(8)
    char OrdMktCode          [  2]; // 주문시장코드 X(2)
    char BnsTp               [  1]; // 매매구분 X(1)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char ExecYn              [  1]; // 체결여부 X(1)
    char OrdDt               [  8]; // 주문일 X(8)
    char SrtOrdNo2           [ 10]; // 시작주문번호2 S9(9)
    char BkseqTp             [  1]; // 역순구분 X(1)
    char OrdPtnCode          [  2]; // 주문유형코드 X(2)
} SONAQ001_IN, * lpSONAQ001_IN;
#define SZ_SONAQ001_IN  sizeof(SONAQ001_IN)

typedef struct
{
	char In                  [  5]; //
	char AcntNo              [ 20]; // 계좌번호 X(20)
    char InptPwd             [  8]; // 입력비밀번호 X(8)
    char OrdMktCode          [  2]; // 주문시장코드 X(2)
    char BnsTp               [  1]; // 매매구분 X(1)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char ExecYn              [  1]; // 체결여부 X(1)
    char OrdDt               [  8]; // 주문일 X(8)
    char SrtOrdNo2           [ 10]; // 시작주문번호2 S9(9)
    char BkseqTp             [  1]; // 역순구분 X(1)
    char OrdPtnCode          [  2]; // 주문유형코드 X(2)
    char OUT1                [  5]; // X(5)
    char SellExecAmt         [ 16]; // 매도체결금액 S9(15)
    char BuyExecAmt          [ 16]; // 매수체결금액 S9(15)
    char SellExecQty         [ 16]; // 매도체결수량 S9(15)
    char BuyExecQty          [ 16]; // 매수체결수량 S9(15)
    char SellOrdQty          [ 16]; // 매도주문수량 S9(15)
    char BuyOrdQty           [ 16]; // 매수주문수량 S9(15)
    char OUT                 [  5]; //
} SONAQ001_OUT, * lpSONAQ001_OUT;
#define SZ_SONAQ001_OUT  sizeof(SONAQ001_OUT)

typedef struct
{
    char OrdDt               [  8]; // 주문일 X(8)
    char MgmtBrnNo           [  3]; // 관리지점번호 X(3)
    char OrdMktCode          [  2]; // 주문시장코드 X(2)
    char OrdNo               [ 10]; // 주문번호 S9(9)
    char OrgOrdNo            [ 10]; // 원주문번호 S9(9)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char IsuNm               [ 40]; // 종목명 X(40)
    char BnsTp               [  1]; // 매매구분 X(1)
    char BnsTpNm             [ 10]; // 매매구분 X(10)
    char OrdPtnCode          [  2]; // 주문유형코드 X(2)
    char OrdPtnNm            [ 40]; // 주문유형명 X(40)
    char OrdTrxPtnCode       [  9]; // 주문처리유형코드 S9(8)
    char OrdTrxPtnNm         [ 50]; // 주문처리유형명 X(50)
    char MrcTp               [  1]; // 정정취소구분 X(1)
    char MrcTpNm             [ 10]; // 정정취소구분명 X(10)
    char MrcQty              [ 16]; // 정정취소수량 S9(15)
    char MrcAbleQty          [ 16]; // 정정취소가능수량 S9(15)
    char OrdQty              [ 16]; // 주문수량 S9(15)
    char OrdPrc              [ 13]; // 주문가 S9(9).99
    char ExecQty             [ 16]; // 체결수량 S9(15)
    char ExecPrc             [ 13]; // 체결가 S9(9).99
    char ExecTrxTime         [  9]; // 체결처리시각 X(9)
    char LastExecTime        [  9]; // 최종체결시각 X(9)
    char OrdprcPtnCode       [  2]; // 호가유형코드 X(2)
    char OrdprcPtnNm         [ 40]; // 호가유형명 X(40)
    char OrdCndiTp           [  1]; // 주문조건구분 X(1)
    char AllExecQty          [ 16]; // 전체체결수량 S9(15)
    char CommdaCode          [  2]; // 통신매체코드 X(2)
    char CommdaNm            [ 40]; // 통신매체명 X(40)
    char MbrNo               [  3]; // 회원번호 X(3)
    char RsvOrdYn            [  1]; // 예약주문여부 X(1)
    char LoanDt              [  8]; // 대출일 X(8)
    char OrdTime             [  9]; // 주문시각 X(9)
    char OpDrtnNo            [ 12]; // 운용지시번호 X(12)
} SONAQ001_SUB, * lpSONAQ001_SUB;
#define SZ_SONAQ001_SUB  sizeof(SONAQ001_SUB)
	
/***********************************************************************
 * 현물계좌별 미결제잔고 
 ***********************************************************************/
typedef struct
{
	char In                  [  5]; //  
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char Pwd                 [  8]; // 비밀번호 X(8)
    char BalCreTp            [  1]; // 잔고생성구분 X(1)
    char CmsnAmtAppTp        [  1]; // 수수료적용구분 X(1)
    char D2balBaseQryTp      [  1]; // D2잔고기준조회구분 X(1)
} SONAQ102_IN, * lpSONAQ102_IN;
#define SZ_SONAQ102_IN  sizeof(SONAQ102_IN)

typedef struct
{
	char In                  [  5]; //
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char Pwd                 [  8]; // 비밀번호 X(8)
    char BalCreTp            [  1]; // 잔고생성구분 X(1)
    char CmsnAmtAppTp        [  1]; // 수수료적용구분 X(1)
    char D2balBaseQryTp      [  1]; // D2잔고기준조회구분 X(1)
	char Out                 [  5]; //  
    char BrnNm               [ 40]; // 지점명 X(40)
    char AcntNm              [ 40]; // 계좌명 X(40)
    char MnyOrdAbleAmt       [ 16]; // 현금주문가능금액 S9(15)
    char MnyoutAbleAmt       [ 16]; // 출금가능금액 S9(15)
    char SeOrdAbleAmt        [ 16]; // 거래소금액 S9(15)
    char KdqOrdAbleAmt       [ 16]; // 코스닥금액 S9(15)
    char HtsOrdAbleAmt       [ 16]; // HTS주문가능금액 S9(15)
    char MgnRat100pctOrdAbleAmt[ 16]; // 증거금률100퍼센트주문가능금액 S9(15)
    char EvalAmt             [ 16]; // 평가금액 S9(15)
    char PchsAmt             [ 16]; // 매입금액 S9(15)
    char RcvblAmt            [ 16]; // 미수금액 S9(15)
    char MnyrclAmt           [ 16]; // 현금미수금액 S9(15)
    char PnlRat              [ 12]; // 손익률 S9(4).9(6)
    char InvstOrgAmt         [ 20]; // 투자원금 S9(19)
    char InvstPlAmt          [ 16]; // 투자손익금액 S9(15)
    char PldgMnyAmt          [ 16]; // 담보현금금액 S9(15)
    char PldgSubstAmt        [ 16]; // 담보대용금액 S9(15)
    char CrdtPldgOrdAmt      [ 16]; // 신용담보주문금액 S9(15)
    char Dps                 [ 16]; // 예수금 S9(15)
    char D1dps               [ 16]; // D1예수금 S9(15)
    char D2Dps               [ 16]; // D2예수금 S9(15)
    char OrdDt               [  8]; // 주문일 X(8)
    char MnyMgn              [ 16]; // 현금증거금액 S9(15)
    char SubstMgn            [ 16]; // 대용증거금액 S9(15)
    char SubstAmt            [ 16]; // 대용금액 S9(15)
    char PrdayBuyExecAmt     [ 16]; // 전일매수체결금액 S9(15)
    char PrdaySellExecAmt    [ 16]; // 전일매도체결금액 S9(15)
    char CrdayBuyExecAmt     [ 16]; // 금일매수체결금액 S9(15)
    char CrdaySellExecAmt    [ 16]; // 금일매도체결금액 S9(15)
    char EvalPnlSum          [ 15]; // 평가손익합계 S9(14)
    char DpsastTotamt        [ 16]; // 예탁자산총액 S9(15)
    char Evrprc              [ 19]; // 제비용 S9(18)
    char RuseAmt             [ 16]; // 재사용금액 S9(15)
    char EtclndAmt           [ 16]; // 기타대여금액 S9(15)
    char PrcAdjstAmt         [ 16]; // 가정산금액 S9(15)
    char D1CmsnAmt           [ 16]; // D1수수료 S9(15)
    char D2CmsnAmt           [ 16]; // D2수수료 S9(15)
    char D1EvrTax            [ 16]; // D1제세금 S9(15)
    char D2EvrTax            [ 16]; // D2제세금 S9(15)
    char D1SettPrergAmt      [ 16]; // D1결제예정금액 S9(15)
    char D2SettPrergAmt      [ 16]; // D2결제예정금액 S9(15)
    char PrdayKseMnyMgn      [ 16]; // 전일KSE현금증거금 S9(15)
    char PrdayKseSubstMgn    [ 16]; // 전일KSE대용증거금 S9(15)
    char PrdayKseCrdtMnyMgn  [ 16]; // 전일KSE신용현금증거금 S9(15)
    char PrdayKseCrdtSubstMgn[ 16]; // 전일KSE신용대용증거금 S9(15)
    char CrdayKseMnyMgn      [ 16]; // 금일KSE현금증거금 S9(15)
    char CrdayKseSubstMgn    [ 16]; // 금일KSE대용증거금 S9(15)
    char CrdayKseCrdtMnyMgn  [ 16]; // 금일KSE신용현금증거금 S9(15)
    char CrdayKseCrdtSubstMgn[ 16]; // 금일KSE신용대용증거금 S9(15)
    char PrdayKdqMnyMgn      [ 16]; // 전일코스닥현금증거금 S9(15)
    char PrdayKdqSubstMgn    [ 16]; // 전일코스닥대용증거금 S9(15)
    char PrdayKdqCrdtMnyMgn  [ 16]; // 전일코스닥신용현금증거금 S9(15)
    char PrdayKdqCrdtSubstMgn[ 16]; // 전일코스닥신용대용증거금 S9(15)
    char CrdayKdqMnyMgn      [ 16]; // 금일코스닥현금증거금 S9(15)
    char CrdayKdqSubstMgn    [ 16]; // 금일코스닥대용증거금 S9(15)
    char CrdayKdqCrdtMnyMgn  [ 16]; // 금일코스닥신용현금증거금 S9(15)
    char CrdayKdqCrdtSubstMgn[ 16]; // 금일코스닥신용대용증거금 S9(15)
    char PrdayFrbrdMnyMgn    [ 16]; // 전일프리보드현금증거금 S9(15)
    char PrdayFrbrdSubstMgn  [ 16]; // 전일프리보드대용증거금 S9(15)
    char CrdayFrbrdMnyMgn    [ 16]; // 금일프리보드현금증거금 S9(15)
    char CrdayFrbrdSubstMgn  [ 16]; // 금일프리보드대용증거금 S9(15)
    char PrdayCrbmkMnyMgn    [ 16]; // 전일장외현금증거금 S9(15)
    char PrdayCrbmkSubstMgn  [ 16]; // 전일장외대용증거금 S9(15)
    char CrdayCrbmkMnyMgn    [ 16]; // 금일장외현금증거금 S9(15)
    char CrdayCrbmkSubstMgn  [ 16]; // 금일장외대용증거금 S9(15)
    char DpspdgQty           [ 16]; // 예탁담보수량 S9(15)
    char D1SubstAmt          [ 16]; // D1대용금 S9(15)
    char D2SubstAmt          [ 16]; // D2대용금 S9(15)
    char D1MnyoutAbleAmt     [ 16]; // D1출금가능금액 S9(15)
    char D2MnyoutAbleAmt     [ 16]; // D2출금가능금액 S9(15)
    char AddPldgMny          [ 16]; // 추가담보현금 S9(15)
    char AddCrdtPldgSubst    [ 16]; // 추가신용담보대용 S9(15)
    char ST_OUT              [  5]; //  
} SONAQ102_OUT, * lpSONAQ102_OUT;
#define SZ_SONAQ102_OUT  sizeof(SONAQ102_OUT)

typedef struct
{
    char IsuNo               [ 12]; // 종목번호 X(12)
    char IsuNm               [ 40]; // 종목명 X(40)
    char SecBalPtnCode       [  2]; // 유가증권잔고유형코드 X(2)
    char SecBalPtnNm         [ 40]; // 유가증권잔고유형명 X(40)
    char BalQty              [ 16]; // 잔고수량 S9(15)
    char BnsBaseBalQty       [ 16]; // 매매기준잔고수량 S9(15)  --
    char CrdayBuyExecQty     [ 16]; // 금일매수체결수량 S9(15)
    char CrdaySellExecQty    [ 16]; // 금일매도체결수량 S9(15)
    char CrdaySellExecPrc    [ 11]; // 금일매도체결가 S9(7).99
    char BuyPrc              [ 13]; // 매수가 S9(9).99
    char SellPnlAmt          [ 16]; // 매도손익금액 S9(15)
    char PnlRat              [ 12]; // 손익률 S9(4).9(6)
    char NowPrc              [ 13]; // 현재가 S9(9).99
    char CrdtAmt             [ 16]; // 신용금액 S9(15)
    char DueDt               [  8]; // 만기일 X(8)
    char PrdaySellExecPrc    [ 13]; // 전일매도체결가 S9(9).99
    char PrdaySellQty        [ 16]; // 전일매도수량 S9(15)
    char PrdayBuyExecPrc     [ 13]; // 전일매수체결가 S9(9).99
    char PrdayBuyQty         [ 16]; // 전일매수수량 S9(15)
    char LoanDt              [  8]; // 대출일 X(8)
    char AvrUprc2            [ 15]; // 평균단가2 S9(11).99  -- 
    char SellAbleQty         [ 16]; // 매도가능수량 S9(15)
    char SellOrdQty          [ 16]; // 매도주문수량 S9(15)
    char CrdayBuyExecAmt     [ 16]; // 금일매수체결금액 S9(15)
    char CrdaySellExecAmt    [ 16]; // 금일매도체결금액 S9(15)
    char PrdayBuyExecAmt     [ 16]; // 전일매수체결금액 S9(15)
    char PrdaySellExecAmt    [ 16]; // 전일매도체결금액 S9(15)
    char EvalAmt             [ 16]; // 평가금액 S9(15)
    char EvalPnl             [ 16]; // 평가손익 S9(15) ---
    char MnyOrdAbleAmt       [ 16]; // 현금주문가능금액 S9(15)
    char OrdAbleAmt          [ 16]; // 주문가능금액 S9(15)
    char SellUnercQty        [ 16]; // 매도미체결수량 S9(15)
    char SellUnsttQty        [ 16]; // 매도미결제수량 S9(15)
    char BuyUnsttQty         [ 16]; // 매수미결제수량 S9(15)
    char UnsttQty            [ 16]; // 미결제수량 S9(15)
    char PrdayCprc           [ 13]; // 전일종가 S9(9).99
    char PchsAmt             [ 16]; // 매입금액 S9(15)  ---
    char RegMktCode          [  2]; // 등록시장코드 X(2)
    char LoanDtlClssCode     [  2]; // 대출상세분류코드 X(2)
    char DpspdgLoanQty       [ 16]; // 예탁담보대출수량 S9(15)
    char RopSetupVal         [ 18]; // 질권설정수량 S9(17)
/*
    char ST_OUT1             [  5]; //  
    char SubstDsgnPtnCode    [  2]; // 대용지정유형코드 X(2)
    char SetupPtnNm          [ 40]; // 설정유형명 X(40)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char IsuNm               [ 40]; // 종목명 X(40)
    char FutsAcntNo          [ 20]; // 선물계좌번호 X(20)
    char PdptnCode           [  2]; // 상품유형코드 X(2)
    char PdptnNm             [ 40]; // 상품유형명 X(40)
    char FnoSubstDsgnQty     [ 16]; // 선물옵션대용지정수량 S9(15)
    char FnoSubstSellOrdQty  [ 16]; // 선물옵션대용매도주문수량 S9(15)
    char FnoSubstSellExecQty [ 16]; // 선물옵션대용매도체결수량 S9(15)
    char FnoSubstSellExecAmt [ 16]; // 선물옵션대용매도체결금액 S9(15)
    char CrdayKpiFtsubtSellExecAmt[ 16]; // 금일코스피선물대용매도체결금액 S9(15)
    char CrdayKpiFtsubtSellExecQty[ 16]; // 금일코스피선물대용매도체결수량 S9(15)
    char RegMktCode          [  2]; // 등록시장코드 X(2)
*/
} SONAQ102_SUB, * lpSONAQ102_SUB;
#define SZ_SONAQ102_SUB  sizeof(SONAQ102_SUB)

/***********************************************************************
 * 계좌 기타약정
 ***********************************************************************/
typedef struct
{
	char In			[5];	
	char TrxTp		[1];	
	char SvcPtnCode	[2];	
	char AcntNo		[20];	
	char Pwd		[8];	
	char RegDt		[8];	
	char AbndDt		[8];	
	char SndDt		[8];	
	char WthdwDt	[8];	

	char DateCfm	[8];	
	char IdSawonCfmMsg	[100];	
	char NameSawonCfm	[40];	
	char IdSawonCfm	[8];	
	char IdSawonCfmLast	[16];	

} SACAT510_IN, * lpSACAT510_IN;
#define SZ_SACAT510_IN              sizeof(SACAT510_IN)

typedef struct
{
	char In			[5];	
	char TrxTp		[1];	
	char SvcPtnCode	[2];	
	char AcntNo		[20];	
	char Pwd		[8];	
	char RegDt		[8];	
	char AbndDt		[8];	
	char SndDt		[8];	
	char WthdwDt	[8];	

	char DateCfm	[8];	
	char IdSawonCfmMsg	[100];	
	char NameSawonCfm	[40];	
	char IdSawonCfm	[8];	
	char IdSawonCfmLast	[16];	
	
	char Out		[5];	
	char AcntNm		[40];	
	char Rmnno		[13];	
	char MnyoutBnkCode		[2];	
	char MnyoutAcntNo		[20];	
	char TrxStatNm		[20];	
}SACAT510_OUT, * lpSACAT510_OUT;
#define SZ_SACAT510_OUT         sizeof(SACAT510_OUT)

/***********************************************************************
 * 사원정보등록 TR
 ***********************************************************************/
typedef struct
{
char	In	[	5	];	/*		*/
char	EmpNo	[	9	];	/*	사원번호	*/
char	TrxTp	[	1	];	/*	처리구분	*/
char	EmpPwd	[	8	];	/*	사원비밀번호	*/
char	EmpNm	[	40	];	/*	사원명	*/
char	WrkBrnNo	[	3	];	/*	근무지점번호	*/
char	JpstnCode	[	3	];	/*	직위코드	*/
char	BrnNo	[	3	];	/*	지점번호	*/
char	EmpTp	[	1	];	/*	사원구분	*/
char	SrlstCode	[	2	];	/*	호봉코드	*/
char	JrnkCode	[	3	];	/*	직급코드	*/
char	DtpstiCode	[	3	];	/*	직책코드	*/
char	RnkNo	[	7	];	/*	서열번호	*/
char	IntraTelSeqno	[	4	];	/*	사내전화일련번호	*/
char	TelRgno	[	4	];	/*	전화지역번호	*/
char	TelExno	[	4	];	/*	전화국번호	*/
char	TelSeqno	[	4	];	/*	전화일련번호	*/
char	HpRgno	[	4	];	/*	휴대폰지역번호	*/
char	HpExno	[	4	];	/*	휴대폰국번호	*/
char	HpSeqno	[	4	];	/*	휴대폰일련번호	*/
char	Rrno	[	13	];	/*	주민등록번호	*/
char	JncoDt	[	8	];	/*	입사일	*/
char	RetirDt	[	8	];	/*	퇴직일	*/
char	WrkGfordDt	[	8	];	/*	근무발령일	*/
char	EmailAddr	[	100	];	/*	이메일주소	*/
char	PostNo	[	6	];	/*	우편번호	*/
char	Addr	[	100	];	/*	주소	*/
char	EmpMgmtCode	[	3	];	/*	사원관리코드	*/
char	EmpMgmtCode01	[	3	];	/*	사원관리코드01	*/
char	EmpMgmtCode02	[	3	];	/*	사원관리코드02	*/
char	EmpMgmtCode03	[	3	];	/*	사원관리코드03	*/
char	InLcns01	[	5	];	/*		*/
char	Tp01	[	1	];	/*	구분	*/
char	InLcns02	[	5	];	/*		*/
char	Tp02	[	1	];	/*	구분	*/
char	InLcns03	[	5	];	/*		*/
char	Tp03	[	1	];	/*	구분	*/
char	InLcns04	[	5	];	/*		*/
char	Tp04	[	1	];	/*	구분	*/
char	InLcns05	[	5	];	/*		*/
char	Tp05	[	1	];	/*	구분	*/
char	InLcns06	[	5	];	/*		*/
char	Tp06	[	1	];	/*	구분	*/
char	InLcns07	[	5	];	/*		*/
char	Tp07	[	1	];	/*	구분	*/
char	InLcns08	[	5	];	/*		*/
char	Tp08	[	1	];	/*	구분	*/
char	InLcns09	[	5	];	/*		*/
char	Tp09	[	1	];	/*	구분	*/
char	InLcns10	[	5	];	/*		*/
char	Tp10	[	1	];	/*	구분	*/
char	InLcns11	[	5	];	/*		*/
char	Tp11	[	1	];	/*	구분	*/
char	InLcns12	[	5	];	/*		*/
char	Tp12	[	1	];	/*	구분	*/
char	InLcns13	[	5	];	/*		*/
char	Tp13	[	1	];	/*	구분	*/
char	InLcns14	[	5	];	/*		*/
char	Tp14	[	1	];	/*	구분	*/
char	InLcns15	[	5	];	/*		*/
char	Tp15	[	1	];	/*	구분	*/
char	InLcns16	[	5	];	/*		*/
char	Tp16	[	1	];	/*	구분	*/
} SSLDT028_IN, * lpSSLDT028_IN;
#define SZ_SSLDT028_IN              sizeof(SSLDT028_IN)

typedef struct
{
char	In	[	5	];	/*		*/
char	EmpNo	[	9	];	/*	사원번호	*/
char	TrxTp	[	1	];	/*	처리구분	*/
char	EmpPwd	[	8	];	/*	사원비밀번호	*/
char	EmpNm	[	40	];	/*	사원명	*/
char	WrkBrnNo	[	3	];	/*	근무지점번호	*/
char	JpstnCode	[	3	];	/*	직위코드	*/
char	BrnNo	[	3	];	/*	지점번호	*/
char	EmpTp	[	1	];	/*	사원구분	*/
char	SrlstCode	[	2	];	/*	호봉코드	*/
char	JrnkCode	[	3	];	/*	직급코드	*/
char	DtpstiCode	[	3	];	/*	직책코드	*/
char	RnkNo	[	7	];	/*	서열번호	*/
char	IntraTelSeqno	[	4	];	/*	사내전화일련번호	*/
char	TelRgno	[	4	];	/*	전화지역번호	*/
char	TelExno	[	4	];	/*	전화국번호	*/
char	TelSeqno	[	4	];	/*	전화일련번호	*/
char	HpRgno	[	4	];	/*	휴대폰지역번호	*/
char	HpExno	[	4	];	/*	휴대폰국번호	*/
char	HpSeqno	[	4	];	/*	휴대폰일련번호	*/
char	Rrno	[	13	];	/*	주민등록번호	*/
char	JncoDt	[	8	];	/*	입사일	*/
char	RetirDt	[	8	];	/*	퇴직일	*/
char	WrkGfordDt	[	8	];	/*	근무발령일	*/
char	EmailAddr	[	100	];	/*	이메일주소	*/
char	PostNo	[	6	];	/*	우편번호	*/
char	Addr	[	100	];	/*	주소	*/
char	EmpMgmtCode	[	3	];	/*	사원관리코드	*/
char	EmpMgmtCode01	[	3	];	/*	사원관리코드01	*/
char	EmpMgmtCode02	[	3	];	/*	사원관리코드02	*/
char	EmpMgmtCode03	[	3	];	/*	사원관리코드03	*/
char	InLcns01	[	5	];	/*		*/
char	Tp01	[	1	];	/*	구분	*/
char	InLcns02	[	5	];	/*		*/
char	Tp02	[	1	];	/*	구분	*/
char	InLcns03	[	5	];	/*		*/
char	Tp03	[	1	];	/*	구분	*/
char	InLcns04	[	5	];	/*		*/
char	Tp04	[	1	];	/*	구분	*/
char	InLcns05	[	5	];	/*		*/
char	Tp05	[	1	];	/*	구분	*/
char	InLcns06	[	5	];	/*		*/
char	Tp06	[	1	];	/*	구분	*/
char	InLcns07	[	5	];	/*		*/
char	Tp07	[	1	];	/*	구분	*/
char	InLcns08	[	5	];	/*		*/
char	Tp08	[	1	];	/*	구분	*/
char	InLcns09	[	5	];	/*		*/
char	Tp09	[	1	];	/*	구분	*/
char	InLcns10	[	5	];	/*		*/
char	Tp10	[	1	];	/*	구분	*/
char	InLcns11	[	5	];	/*		*/
char	Tp11	[	1	];	/*	구분	*/
char	InLcns12	[	5	];	/*		*/
char	Tp12	[	1	];	/*	구분	*/
char	InLcns13	[	5	];	/*		*/
char	Tp13	[	1	];	/*	구분	*/
char	InLcns14	[	5	];	/*		*/
char	Tp14	[	1	];	/*	구분	*/
char	InLcns15	[	5	];	/*		*/
char	Tp15	[	1	];	/*	구분	*/
char	InLcns16	[	5	];	/*		*/
char	Tp16	[	1	];	/*	구분	*/
char	OutWrkBrn	[	5	];	/*		*/
char	BrnNm	[	40	];	/*	지점명	*/
char	OutTeam	[	5	];	/*		*/
char	BrnNm_Out	[	40	];	/*	지점명	*/
char	OutHr	[	5	];	/*		*/
char	JpstnNm	[	40	];	/*	직위명	*/
char	JrnkNm	[	40	];	/*	직급	*/
char	DtpstiNm	[	40	];	/*	직책명	*/
char	OutDate	[	5	];	/*		*/
char	RegDt	[	8	];	/*	등록일	*/
char	ChgDt	[	8	];	/*	변경일	*/

}SSLDT028_OUT, * lpSSLDT028_OUT;
#define SZ_SSLDT028_OUT         sizeof(SSLDT028_OUT)


/***********************************************************************
 * 출금TR 
 ***********************************************************************/
typedef struct
{
char	In		[	5	];	/*		*/
char	CardFirmNo		[	3	];	/*	카드회사번호	*/
char	CardAcntNo		[	20	];	/*	카드계좌번호	*/
char	CardIssCnt		[	10	];	/*	카드발급건수	*/
char	CardPtnCode		[	2	];	/*	카드유형코드	*/
char	MgrCardFirmNo		[	3	];	/*	책임자카드회사번호	*/
char	MgrCardAcntNo		[	20	];	/*	책임자카드계좌번호	*/
char	MgrCardPtnCode		[	2	];	/*	책임자카드유형코드	*/
char	MgrCardIssCnt		[	10	];	/*	책임자카드발급횟수	*/
char	AgrmReqstDt		[	8	];	/*	승인요청일	*/
char	AgrmTrxId		[	8	];	/*	승인처리ID	*/
char	LastAgrmUserId		[	16	];	/*	최종승인자ID	*/
char	AgrmUserNm		[	40	];	/*	승인사용자명	*/
char	AgrmAddMsg		[	100	];	/*	승인자추가메시지	*/
char	ClntCardMsdata		[	23	];	/*	고객카드MSDATA	*/
char	AgrmCardMsdata		[	23	];	/*	승인카드번호	*/
char	TrxSlctBrnNo		[	3	];	/*	처리의뢰지점번호	*/
char	PdptnCode		[	2	];	/*	상품유형코드	*/
char	AcntNo		[	20	];	/*	계좌번호	*/
char	MnyMgmtNo		[	20	];	/*	자금관리번호	*/
char	Pwd		[	8	];	/*	비밀번호	*/
char	SmryNo		[	4	];	/*	적요번호	*/
char	MnyAmt		[	16	];	/*	현금금액	*/
char	ChckAmt		[	16	];	/*	수표금액	*/
char	AskpsnNm		[	40	];	/*	의뢰인명	*/
char	IsuNo		[	12	];	/*	종목번호	*/
char	MnyoutTotamt		[	16	];	/*	출금총액	*/

} SDPDT003_IN, * lpSDPDT003_IN;
#define SZ_SDPDT003_IN              sizeof(SDPDT003_IN)

typedef struct
{
char	In		[	5	];	/*		*/
char	CardFirmNo		[	3	];	/*	카드회사번호	*/
char	CardAcntNo		[	20	];	/*	카드계좌번호	*/
char	CardIssCnt		[	10	];	/*	카드발급건수	*/
char	CardPtnCode		[	2	];	/*	카드유형코드	*/
char	MgrCardFirmNo		[	3	];	/*	책임자카드회사번호	*/
char	MgrCardAcntNo		[	20	];	/*	책임자카드계좌번호	*/
char	MgrCardPtnCode		[	2	];	/*	책임자카드유형코드	*/
char	MgrCardIssCnt		[	10	];	/*	책임자카드발급횟수	*/
char	AgrmReqstDt		[	8	];	/*	승인요청일	*/
char	AgrmTrxId		[	8	];	/*	승인처리ID	*/
char	LastAgrmUserId		[	16	];	/*	최종승인자ID	*/
char	AgrmUserNm		[	40	];	/*	승인사용자명	*/
char	AgrmAddMsg		[	100	];	/*	승인자추가메시지	*/
char	ClntCardMsdata		[	23	];	/*	고객카드MSDATA	*/
char	AgrmCardMsdata		[	23	];	/*	승인카드번호	*/
char	TrxSlctBrnNo		[	3	];	/*	처리의뢰지점번호	*/
char	PdptnCode		[	2	];	/*	상품유형코드	*/
char	AcntNo		[	20	];	/*	계좌번호	*/
char	MnyMgmtNo		[	20	];	/*	자금관리번호	*/
char	Pwd		[	8	];	/*	비밀번호	*/
char	SmryNo		[	4	];	/*	적요번호	*/
char	MnyAmt		[	16	];	/*	현금금액	*/
char	ChckAmt		[	16	];	/*	수표금액	*/
char	AskpsnNm		[	40	];	/*	의뢰인명	*/
char	IsuNo		[	12	];	/*	종목번호	*/
char	MnyoutTotamt		[	16	];	/*	출금총액	*/
char	Out		[	5	];	/*		*/
char	Inouno		[	10	];	/*	출납번호	*/
char	RcvblOcrAmt		[	16	];	/*	미수발생금액	*/
char	DpsBfbalAmt		[	16	];	/*	예수금전잔금액	*/
char	DpsCrbalAmt		[	16	];	/*	예수금금잔금액	*/
char	NSavBfbalAmt		[	16	];	/*	비저축전잔금액	*/
char	NSavCrbalAmt		[	16	];	/*	비저축금잔금액	*/
char	AcntNm		[	40	];	/*	계좌명	*/
char	SmryNm		[	40	];	/*	적요명	*/
char	IsuNm		[	40	];	/*	종목명	*/
char	AgrmTrxStep		[	1	];	/*	승인처리단계	*/ 
char	AgrmMthdCode		[	2	];	/*	승인방식코드	*/

}SDPDT003_OUT, * lpSDPDT003_OUT;
#define SZ_SDPDT003_OUT         sizeof(SDPDT003_OUT)

/***********************************************************************
 * 선물옵션 예탁금 상세TR 
 ***********************************************************************/
typedef struct
{
	char In[5];
	char AcntNo[20];
	char InptPwd[8];
} SONBQ026_IN, * lpSONBQ026_IN;
#define SZ_SONBQ026_IN sizeof(SONBQ026_IN)

typedef struct
{
	char Out[5];
	char AcntNm[40];
	char Totamt[15];
} SONBQ026_OUT, * lpSONBQ026_OUT;
#define SZ_SONBQ026_OUT sizeof(SONBQ026_OUT)

/***********************************************************************
 * 외화출금TR 
 ***********************************************************************/
typedef struct
{
	char In[5];
	char CardFirmNo[3];
	char CardAcntNo[20];
	char CardPtnCode[2];
	char CardIssCnt[10];
	char MgrCardFirmNo[3];
	char MgrCardAcntNo[20];
	char MgrCardPtnCode[2];
	char MgrCardIssCnt[10];
	char ClntCardMsdata[23];
	char AgrmCardMsdata[23];
	char TrxSlctBrnNo[3];
	char AcntNo[20];
	char Pwd[8];
	char SmryCode[4];
	char CrcyCode[3];
	char FcurrAmt[17];
	char AgrmReqstDt[8];
	char AgrmTrxId[8];
	char LastAgrmUserId[16];
	char AgrmUserNm[40];
	char AgrmAddMsg[100];
} SDPDT011_IN, *lpSDPDT011_IN;
#define SZ_SDPDT011_IN sizeof(SDPDT011_IN)

typedef struct
{
	char Out[5];
	char AcntNm[40];
	char SmryNm[40];
	char CrcyCodeNm[40];
	char Inouno[10];
	char FcurrDpsBfbalAmt[17];
	char FcurrDpsCrbalAmt[17];
	char SubstBfAmt[16];
	char SubstAfAmt[16];
	char FcurrSubstBfAmt[16];
	char FcurrSubstAfAmt[16];
	char AgrmMthdCode[2];
	char AgrmTrxStep[10];
} SDPDT011_OUT, *lpSDPDT011_OUT;
#define SZ_SDPDT011_OUT sizeof(SDPDT011_OUT)

/***********************************************************************
 * 외화입금TR
 ***********************************************************************/
typedef struct
{
    char In[5];
    char CardFirmNo[3];
    char CardAcntNo[20];
    char CardPtnCode[2];
    char CardIssCnt[10];
    char MgrCardFirmNo[3];
    char MgrCardAcntNo[20];
    char MgrCardPtnCode[2];
    char MgrCardIssCnt[10];
    char ClntCardMsdata[23];
    char AgrmCardMsdata[23];
    char TrxSlctBrnNo[3];
    char AcntNo[20];
    char SmryCode[4];
    char CrcyCode[3];
    char FcurrAmt[17];
	char MnyinAskpsnNm[40];
    char AgrmReqstDt[8];
    char AgrmTrxId[8];
    char LastAgrmUserId[16];
    char AgrmUserNm[40];
    char AgrmAddMsg[100];
} SDPDT009_IN, *lpSDPDT009_IN;
#define SZ_SDPDT009_IN sizeof(SDPDT009_IN)

typedef struct
{
	char Out[5];
	char AcntNm[40];
	char SmryNo[4];
	char SmryNm[40];
	char CrcyCode[3];
	char CrcyNm[40];
	char FcurrTrdAmt[17];
	char Inouno[10];
	char FcurrBfbalAmt[17];
	char FcurrCrbalAmt[17];
	char SubstBfAmt[16];
	char SubstAfAmt[16];
	char FcurrSubstBfAmt[16];
	char FcurrSubstAfAmt[16];
	char AgrmMthdCode[2];
	char AgrmTrxStep[10];
} SDPDT009_OUT, *lpSDPDT009_OUT;
#define SZ_SDPDT009_OUT sizeof(SDPDT009_OUT)

/***********************************************************************
 * 펀드 계좌보유펀드 조회
 ***********************************************************************/
typedef struct
{
char	In		[	5	];			
char	AcntNo	[	20	];	/*	계좌번호	*/
char	Pwd		[	8	];	/*	비밀번호	*/
char	BaseDt	[	8	];	/*	기준일	*/
char	BnsTp	[	1	];	/*	매매구분	*/
char	FundOrdTp	[	1	];	/*	펀드주문구분	*/
char	SubAcntNo	[	20	];	/*	서브계좌번호	*/
char	RpPtnCode	[	2	];	/*	환매유형코드	*/
} SOFFQ141_IN, *lpSOFFQ141_IN;
#define SZ_SOFFQ141_IN sizeof(SOFFQ141_IN)

typedef struct
{
char	IndrcInvstCode	[	2	];	/*	간접투자코드	*/
char	SubAcntNo2	[	20	];	/*	서브계좌번호	*/
char	SubAcntSeqno	[	3	];	/*	계좌일련번호	*/
char	IvstfndCode	[	12	];	/*	투신펀드코드	*/
char	FundSeq	[	10	];	/*	펀드일련번호	*/
char	HanglIvstfndNm	[	40	];	/*	한글투신펀드명	*/
char	BasePrc	[	13	];	/*	기준가	*/
char	FundBalQty	[	20	];	/*	펀드잔고수량	*/
char	OpnDt	[	8	];	/*	개설일	*/
char	EvalAmt	[	16	];	/*	평가금액	*/
char	AdjstAmt	[	16	];	/*	정산금액	*/
char	BuyPtnCode	[	2	];	/*	매수유형코드	*/
char	PayMthdCode	[	2	];	/*	납입방법코드	*/
char	CvntTermMthQty	[	6	];	/*	계약기간월수	*/
char	CvntAmt	[	16	];	/*	계약금액	*/
char	RpPtnCode2	[	2	];	/*	환매유형코드	*/
char	OpfirmCode	[	3	];	/*	운용사코드	*/
char	OpfirmNm	[	50	];	/*	운용사명	*/
char	IndrcInvstNm	[	40	];	/*	간접투자명	*/
char	PayMthdNm	[	40	];	/*	납입방법명	*/
char	Dps	[	16	];	/*	예수금	*/
char	MthPayDt	[	2	];	/*	월납입일	*/
char	IvtrstDtlCode	[	2	];	/*	투신상세코드	*/
char	IvtrstDtlNm	[	40	];	/*	투신상세명	*/
char	BuyPramt	[	16	];	/*	매수원금	*/
char	BoaBasePrc	[	20	];	/*	과표기준가	*/
char	BaseTimeBnsType	[	1	];	/*	기준시간매매구분	*/
char	TotRwrdRat	[	17	];	/*	총보수율	*/
char	MchndRwrdRat	[	17	];	/*	판매보수율	*/
char	MchndCmsnAmtRat	[	11	];	/*	판매수수료율	*/
} SOFFQ141_OUT_SUB, *lpSOFFQ141_OUT_SUB;
#define SZ_SOFFQ141_OUT_SUB sizeof(SOFFQ141_OUT_SUB)

typedef struct
{
char	In		[	5	];			
char	AcntNo	[	20	];	/*	계좌번호	*/
char	Pwd		[	8	];	/*	비밀번호	*/
char	BaseDt	[	8	];	/*	기준일	*/
char	BnsTp	[	1	];	/*	매매구분	*/
char	FundOrdTp	[	1	];	/*	펀드주문구분	*/
char	SubAcntNo	[	20	];	/*	서브계좌번호	*/
char	RpPtnCode	[	2	];	/*	환매유형코드	*/

char	Out			[	5	];	/* 		*/
char	AcntNm		[	40	];	/*	계좌명	*/

char	OutCnt		[	5	];	/*	출력건수	*/

SOFFQ141_OUT_SUB		SOFFQ141_OUTSUB [30]; 

} SOFFQ141_OUT, *lpSOFFQ141_OUT;
#define SZ_SOFFQ141_OUT sizeof(SOFFQ141_OUT)

/***********************************************************************
 * 펀드 매도
 ***********************************************************************/
typedef struct
{
char	In	[	5	];			
char	AcntNo	[	20	];	/*	계좌번호	*/
char	Pwd				[	8	];	/*	비밀번호	*/
char	RpPrslPtnTp		[	1	];	/*	환매신청유형구분	*/
char	SellOrdAmt		[	16	];	/*	매도주문금액	*/
char	IvstfndCode		[	12	];	/*	투신펀드코드	*/
char	SpclMidwRpYn	[	1	];	/*	특별중도환매여부	*/
char	FndtdTrxTp		[	1	];	/*	펀드매매처리구분	*/
char	OppAcntNo		[	20	];	/*	상대계좌번호	*/
char	CnvsTp			[	1	];	/*	권유구분	*/
} SOFFT130_IN, *lpSOFFT130_IN;
#define SZ_SOFFT130_IN sizeof(SOFFT130_IN)

typedef struct
{
char	In		[	5	];			
char	AcntNo	 [	20	];	/*	계좌번호	*/
char	Pwd	[	8	];	/*	비밀번호	*/
char	RpPrslPtnTp	[	1	];	/*	환매신청유형구분	*/
char	SellOrdAmt	[	16	];	/*	매도주문금액	*/
char	IvstfndCode	[	12	];	/*	투신펀드코드	*/
char	SpclMidwRpYn	[	1	];	/*	특별중도환매여부	*/
char	FndtdTrxTp	[	1	];	/*	펀드매매처리구분	*/
char	OppAcntNo	[	20	];	/*	상대계좌번호	*/
char	CnvsTp	[	1	];	/*	권유구분	*/
char	Out	[	5	];	/*		*/
char	OrdNo	[	10	];	/*	주문번호	*/
char	BncertSellUnit	[	16	];	/*	수익증권매도좌수	*/
char	BalUnit	[	16	];	/*	잔고좌수	*/
char	SellAmt	[	16	];	/*	매도금액	*/
char	RpCmsnAmt	[	16	];	/*	환매수수료	*/
char	HldbkCmsnAmt	[	16	];	/*	유보수수료	*/
char	Ictax	[	16	];	/*	소득세	*/
char	Ihtax	[	16	];	/*	주민세	*/
char	BasePrc	[	12	];	/*	기준가	*/
char	BoaBasePrc	[	20	];	/*	과표기준가	*/
char	BasePrcAppDt	[	8	];	/*	기준가적용일	*/
char	SettDt	[	8	];	/*	결제일	*/
char	FundNm	[	40	];	/*	펀드명	*/

} SOFFT130_OUT, *lpSOFFT130_OUT;
#define SZ_SOFFT130_OUT sizeof(SOFFT130_OUT)

/***********************************************************************
 * 펀드 매매취소
 ***********************************************************************/
typedef struct
{
char	In	[	5	];	/*		*/
char	AcntNo	[	20	];	/*	계좌번호	*/
char	Pwd	[	8	];	/*	비밀번호	*/
char	TrdTp	[	1	];	/*	거래구분	*/
char	TrxBrnNo	[	3	];	/*	처리지점번호	*/
char	IvtrstIadTp	[	1	];	/*	투신국내외구분	*/
char	OrdDt	[	8	];	/*	주문일	*/
char	OrdNo	[	10	];	/*	주문번호	*/
char	FndtdTrxTp	[	1	];	/*	펀드매매처리구분	*/
char	OppAcntNo	[	20	];	/*	상대계좌번호	*/
} SOFFT131_IN, *lpSOFFT131_IN;
#define SZ_SOFFT131_IN sizeof(SOFFT131_IN)

typedef struct
{
char	In	[	5	];	/*		*/
char	AcntNo	[	20	];	/*	계좌번호	*/
char	Pwd	[	8	];	/*	비밀번호	*/
char	TrdTp	[	1	];	/*	거래구분	*/
char	TrxBrnNo	[	3	];	/*	처리지점번호	*/
char	IvtrstIadTp	[	1	];	/*	투신국내외구분	*/
char	OrdDt	[	8	];	/*	주문일	*/
char	OrdNo	[	10	];	/*	주문번호	*/
char	FndtdTrxTp	[	1	];	/*	펀드매매처리구분	*/
char	OppAcntNo	[	20	];	/*	상대계좌번호	*/
char	Out	[	5	];	/*		*/
char	AcntNo2	[	20	];	/*	계좌번호	*/
char	TrdDate	[	8	];	/*	거래일자	*/
char	TrdNo	[	10	];	/*	거래번호	*/
char	Inouno	[	10	];	/*	출납번호	*/
char	BuyAmt	[	16	];	/*	매수금액	*/
char	BuyQty	[	16	];	/*	매수수량	*/
char	SecBfbalQty	[	16	];	/*	유가증권전잔수량	*/
char	SecCrbalQty	[	16	];	/*	유가증권금잔수량	*/
char	BasePrcAppDt	[	8	];	/*	기준가적용일	*/
char	SettDt	[	8	];	/*	결제일	*/
char	MchndCmsnAmt	[	16	];	/*	판매수수료	*/
char	BnsBasePrc	[	19	];	/*	매매기준가	*/
char	BoaBasePrc	[	19	];	/*	과표기준가	*/
char	IvstfndCode	[	12	];	/*	투신펀드코드	*/
char	HanglIvstfndNm	[	40	];	/*	한글투신펀드명	*/
char	IvstfndSeqno	[	10	];	/*	투신펀드일련번호	*/
} SOFFT131_OUT, *lpSOFFT131_OUT;
#define SZ_SOFFT131_OUT sizeof(SOFFT131_OUT)

/***********************************************************************
 * 은행예금주성명조회 - SDPKT120
 ***********************************************************************/
typedef struct
{
char	In	[	5	];	/*		*/
char	BnkCode	[	3	];	/*	은행코드	*/
char	BnkAcntNo	[	20	];	/*	은행계좌번호	*/
} SDPKT120_IN, *lpSDPKT120_IN;
#define SZ_SDPKT120_IN sizeof(SDPKT120_IN)

typedef struct
{
char	In	[	5	];	/*		*/
char	BnkCode	[	3	];	/*	은행코드	*/
char	BnkAcntNo	[	20	];	/*	은행계좌번호	*/
char	Out	[	5	];	/*		*/
char	BnkNm	[	40	];	/*	은행명	*/
char	BnkBrnNm	[	40	];	/*	은행지점명	*/
char	DpsPsnNm	[	40	];	/*	예금주명	*/
char	BnkRspnsCode	[	4	];	/*	은행응답코드	*/
} SDPKT120_OUT, *lpSDPKT120_OUT;
#define SZ_SDPKT120_OUT sizeof(SDPKT120_OUT)

/***********************************************************************
 *
 *	object name : SOFAT331 전문 (외화증권 온라인 체결 처리 코스콤 전문)
 *	prgram id	: GIS - Tr2009.pc
 *	description	: SOFAT331 전문 구조체
 *
 ***********************************************************************/
typedef struct
{
    char 	In         			[ 5];
	char    zTrxTp              [ 1];   // 처리구분
    char    lIttCode            [ 9];   // 기관코드
    char    zTrxDt              [ 8];   // 처리일
    char    zAcntNo             [20];   // 계좌번호
    char    zPwd                [ 8];   // 비밀번호
    char    zExecDt             [ 8];   // 체결일
    char    lFileTrdNo          [10];   // 파일거래번호
    char    zClntNo             [20];   // 고객번호
    char    zFileAcntNo         [20];   // 파일계좌번호
    char    zClmDt              [ 8];   // 청구일
    char    zBnsCode            [ 2];   // 매매코드
    char    zIsuNo              [12];   // 종목번호
    char    zFileCntryCode      [ 2];   // 파일국가코드
    char    lIttNp              [ 6];   // 기관번호
    char    zOwnTp              [ 1];   // 소유구분
    char    lTrdQty             [16];   // 거래수량
    char    dUprc               [15];   // 단가
    char    zCrcyCode           [ 3];   // 통화코드
    char    dFcurrSettAmt       [17];   // 외화결제금액
    char    dFcurrTrdAmt        [17];   // 외화거래금액
    char    dSecCmsnAmt         [17];   // SEC수수료
    char    dFcurrEtcTax        [17];   // 외화기타세금
    char    dStk2000CmsnAmt     [17];   // 2000주수수료
    char    zBloterCode         [ 2];   // BLOTER 코드
    char    zOppPrdtTp          [ 1];   // 상대상품구분
    char    zOppClntNo          [20];   // 상대고객번호
    char    zOppAcntNo          [20];   // 상대계좌번호
    char    zAgnt               [24];   // 대리인
    char    zTrdMkt             [24];   // 거래시장
    char    zOthprty            [20];   // 상대방
    char    zOthprtyNm          [40];   // 상대방명
    char    zLclTrdNo           [12];   // 현지거래번호
    char    zFileTrdDt          [ 8];   // 파일거래일
    char    zSettPreargDt       [ 8];   // 결제예정일
    char    zCsgnAcntNo         [20];   // 위탁계좌번호
    char    dCmsnAmt1           [17];   // 수수료1
    char    dCmsnAmt2           [17];   // 수수료2
    char    dCmsnAmt3           [17];   // 수수료3
    char    dCmsnAmt4           [17];   // 수수료4
    char    dCmsnAmt5           [17];   // 수수료5

} SOFAT331_IN, * lpSOFAT331_IN;
#define SZ_SOFAT331_IN              sizeof(SOFAT331_IN)

typedef struct
{
    char sTrxTp          [  1]; /* 처리구분     */
    char sIttCode        [  8]; /* 기관코드     */
    char sTrxDt          [  8]; /* 처리일       */
    char sAcntNo         [ 20]; /* 계좌번호     */
    char sPwd            [ 32]; /* 비밀번호     */
    char sExecDt         [  8]; /* 체결일       */
    char sFileTrdNo      [  9]; /* 파일거래번호 */
    char sClntNo         [ 20]; /* 고객번호     */
    char sFileAcntNo     [ 20]; /* 파일계좌번호 */
    char sClmDt          [  8]; /* 청구일       */
    char sBnsCode        [  2]; /* 매매코드     */
    char sIsuNo          [ 12]; /* 종목번호     */
    char sFileCntryCode  [  2]; /* 파일국가코드 */
    char sIttNo          [  5]; /* 기관번호     */
    char sOwnTp          [  1]; /* 소유구분     */
    char sTrdQty         [ 15]; /* 거래수량     */
    char sUprc           [ 13]; /* 단가         */
    char sCrcyCode       [  3]; /* 통화코드     */
    char sFcurrSettAmt   [ 15]; /* 외화결제금액 */
    char sFcurrTrdAmt    [ 15]; /* 외화거래금액 */
    char sSecCmsnAmt     [ 15]; /* SEC수수료    */
    char sFcurrEtcTax    [ 15]; /* 외화기타세금 */
    char sStk2000CmsnAmt [ 15]; /* 2000주수수료 */
    char sBloterCode     [  2]; /* BLOTER 코드  */
    char sOppPrdtTp      [  1]; /* 상대상품구분 */
    char sOppClntNo      [ 20]; /* 상대고객번호 */
    char sOppAcntNo      [ 20]; /* 상대계좌번호 */
    char sAgnt           [ 24]; /* 대리인       */
    char sTrdMkt         [ 24]; /* 거래시장     */
    char sOthprty        [ 20]; /* 상대방       */
    char sOthprtyNm      [ 40]; /* 상대방명     */
    char sLclTrdNo       [ 12]; /* 현지거래번호 */
    char sFileTrdDt      [  8]; /* 파일거래일   */
    char sSettPreargDt   [  8]; /* 결제예정일   */
    char sCsgnAcntNo     [ 20]; /* 위탁계좌번호 */
    char sCmsnAmt1       [ 15]; /* 수수료1      */
    char sCmsnAmt2       [ 15]; /* 수수료2      */
    char sCmsnAmt3       [ 15]; /* 수수료3      */
    char sCmsnAmt4       [ 15]; /* 수수료4      */
    char sCmsnAmt5       [ 15]; /* 수수료5      */
}   SOFAT331_OUT, * lpSOFAT331_OUT;
#define SZ_SOFAT331_OUT     sizeof(SOFAT331_OUT)

/***********************************************************************
 *
 *	object name : SOFAQ239 전문 (외화증권종목별유가잔고현황)
 *	prgram id	: GIS - Tr2022.pc
 *	description	: SOFAQ239 전문 구조체
 *
 ***********************************************************************/
typedef struct
{
char	In	[	5	];	/*		*/
char	BrnNo	[	3	];	/*	지점번호	*/
char	SrtIsuNo	[	12	];	/*	시작종목번호	*/
char	BaseDt	[	8	];	/*	기준일	*/
char	QryTp	[	1	];	/*	조회구분	*/
char	IttCode	[	9	];	/*	기관코드	*/
char	MktCode	[	2	];	/*	시장코드	*/
char	FcstckPtnCode	[	2	];	/*	외화증권유형코드	*/
} SOFAQ239_IN, * lpSOFAQ239_IN;
#define SZ_SOFAQ239_IN              sizeof(SOFAQ239_IN)

typedef struct
{
char    BrnNm   [   40  ];  /*  지점명  */
char    SumQty  [   16  ];  /*  합계수량    */
char    FcurrTotamt1    [   17  ];  /*  외화합계금액1   */
} SOFAQ239_Sub1_OUT, *lpSOFAQ239_Sub1_OUT;
#define SZ_SOFAQ239_Sub1_OUT sizeof(SOFAQ239_Sub1_OUT)

typedef struct
{
char    IsuNo   [   12  ];  /*  종목번호    */
char    IsuNm   [   40  ];  /*  종목명  */
char    CrcyCode    [   3   ];  /*  통화코드    */
char    HldQty  [   16  ];  /*  보유수량    */
char    FcurrBookAmt    [   17  ];  /*  외화장부금액    */
char    MktTpNm [   20  ];  /*  시장구분    */
char    Xchrat  [   11  ];  /*  환율    */
char    GdCprc  [   19  ];  /*  종가    */
char    FcurrEvalAmt    [   17  ];  /*  외화평가금액    */
char    WonEvalAmt  [   16  ];  /*  원화평가금액    */
} SOFAQ239_Sub2_OUT, *lpSOFAQ239_Sub2_OUT;
#define SZ_SOFAQ239_Sub2_OUT sizeof(SOFAQ239_Sub2_OUT)

typedef struct
{
    char Out    [5];
} SOFAQ239_Sub_OUT, *lpSOFAQ239_Sub_OUT;
#define SZ_SOFAQ239_Sub_OUT sizeof(SOFAQ239_Sub_OUT)
typedef struct
{
    SOFAQ239_IN in;
    SOFAQ239_Sub_OUT out;
} SOFAQ239_OUT, *lpSOFAQ239_OUT;
#define SZ_SOFAQ239_OUT sizeof(SOFAQ239_OUT)


typedef struct _SSEAT308I_
{
    char In                 [ 5];
    char OrdDt              [ 8]; /*주문일                */
    char TrdDt              [ 8]; /*거래일                */
    char SettPreargDt       [ 8]; /*결제예정일            */
    char DpartNm            [40]; /*부서명                */
    char FundOpAcntNo       [20]; /*펀드운용계좌번호      */
    char Pwd                [ 8]; /*비밀번호              */
    char IsuNo              [12]; /*종목번호              */
    char FcstckTrdPtnCode   [ 2]; /*외화증권거래유형코드  */
    char OrdXchrat          [11]; /*주문환율              */
    char UprcAutoCompYn     [ 1]; /*단가자동계산여부      */
    char OrdUprc            [15]; /*주문단가              */
    char OrdQty             [16]; /*주문수량              */
    char BuyDtInptYn        [ 1]; /*매수일입력여부        */
    char BndBuyDt           [ 8]; /*채권매수일            */
    char FcurrOrdAmt        [17]; /*외화주문금액          */
    char TrdOthprtyNm       [40]; /*거래상대방명          */
    char SettIttNm          [40]; /*결제기관명            */
    char ThcoCstdyIttNm     [40]; /*당사보관기관명        */
    char OppCstdyIttNm      [40]; /*상대보관기관명        */
    char OppBrkNm           [40]; /*상대중개인명          */
    char IntrstFcurrAmt     [17]; /*채권이자외화금액      */
    char PremFcurrAmt       [17]; /*프리미엄외화금액      */
    char AbrdFcurrCmsnAmt   [17]; /*국외외화수수료        */
    char AbrdEvrprcFcurrAmt [17]; /*국외제비용외화금액    */
    char CorpTaxRat         [ 7]; /*법인세율              */
    char WonCorpTax         [16]; /*원화법인세            */
    char TrtaxRat           [7]; /*거래세율              */
    char WonTrtax           [16]; /*원화거래세            */
    char BnsRsn             [100]; /*매매사유              */
    char OpPlan             [100]; /*운용계획              */
}   SSEAT308I_st,   * lpSSEAT308I_st;
#define SZ_SSEAT308I    sizeof(SSEAT308I_st)

typedef struct _SSEAT309I_
{
    char In                  [ 5];
    char OrdDt               [ 8];    /*주문일                */
    char SettPreargDt        [ 8];    /*결제예정일            */
    char TrdDt               [ 8];    /*거래일                */
    char DpartNm             [40];    /*부서명                */
    char FundOpAcntNo        [20];    /*펀드운용계좌번호      */
    char Pwd                 [ 8];    /*비밀번호              */
    char IsuNo               [12];    /*종목번호              */
    char FcstckTrdPtnCode    [ 2];    /*외화증권거래유형코드  */
    char OrdXchrat           [11];    /*주문환율              */
    char UprcAutoCompYn      [ 1];    /*단가자동계산여부      */
    char OrdUprc             [15];    /*주문단가              */
    char OrdQty              [16];    /*주문수량              */
    char BuyDtInptYn         [ 1];    /*매수일입력여부        */
    char BndBuyDt            [ 8];    /*채권매수일            */
    char FcurrOrdAmt         [17];    /*외화주문금액          */
    char TrdOthprtyNm        [40];    /*거래상대방명          */
    char SettIttNm           [40];    /*결제기관명            */
    char ThcoCstdyIttNm      [40];    /*당사보관기관명        */
    char OppCstdyIttNm       [40];    /*상대보관기관명        */
    char OppBrkNm            [40];    /*상대중개인명          */
    char IntrstFcurrAmt      [17];    /*경과이자외화금액      */
    char PremFcurrAmt        [17];    /*프리미엄외화금액      */
    char AbrdFcurrCmsnAmt    [17];    /*국외외화수수료        */
    char AbrdEvrprcFcurrAmt  [17];    /*국외제비용외화금액    */
    char BnsRsn              [100];    /*매매사유              */
    char OpPlan              [100];    /*운용계획              */
}   SSEAT309I_st,   * lpSSEAT309I_st;
#define SZ_SSEAT309I    sizeof(SSEAT309I_st)

/***********************************************************************
 *
 *	object name : SOFAQ215 입력 전문 (외화증권 AHTS거래내역 코스콤 입력전문)
 *	prgram id	: GIS - Tr2009.pc
 *	description	: SOFAQ215 전문 입력 구조체
 *
 ***********************************************************************/
typedef struct SOFAQ215_IN_ST
{
    char In       [  5]; /* 레코드갯수 */
    char sAcntNo  [ 20]; /* 계좌번호 */
    char sSrtDt   [  8]; /* 시작일   */
    char sEndDt   [  8]; /* 종료일   */
    char sQryTp   [  1]; /* 조회구분 */
    char sBnsCode [  2]; /* 매매코드 */
    char sIttCode [  8+1]; /* 기관코드 */
    char sBaseDtTp[  1]; /* 기준일 구분 */
}   SOFAQ215_IN, * lpSOFAQ215_IN;
#define SZ_SOFAQ215_IN     sizeof(SOFAQ215_IN)

/***********************************************************************
 *
 *	object name : SOFAQ215 출력 전문 (외화증권 AHTS거래내역 코스콤 출력전문)
 *	prgram id	: GIS - Tr2009.pc
 *	description	: SOFAQ215 전문 출력 구조체
 *
 ***********************************************************************/
typedef struct _SOFAQ215Occ_sub_
{
    char sTrdDt        [ 8    ];    /* 거래일       */
    char sSettDt       [ 8    ];    /* 결제일       */
    char sIsuNm        [40    ];    /* 종목명       */
    char sTrdNo        [ 9 + 1];    /* 거래번호     */
    char sAcntNo       [20    ];    /* 계좌번호     */
    char sBnsTpNm      [10    ];    /* 매매구분     */
    char sTrdQty       [15 + 1];    /* 거래수량     */
    char sUprc         [13 + 2];    /* 단가         */
    char sFcurrTrdAmt  [15 + 2];    /* 외화거래금액 */
    char sFcurrSettAmt [15 + 2];    /* 외화결제금액 */
    char sCmsnAmt1     [15 + 2];    /* 수수료1      */
    char sCmsnAmt2     [15 + 2];    /* 수수료2      */
    char sCmsnAmt3     [15 + 2];    /* 수수료3      */
    char sBrkCmsnAmt   [15 + 2];    /* BROKER수수료 */
    char sCmsnAmt4     [15 + 2];    /* 수수료4      */
    char sCmsnAmt5     [15 + 2];    /* 수수료5      */
    char sAbrdMktIdNm  [50    ];    /* 해외거래소명 */
    char sIsuNo        [12    ];    /* 종목번호     */
    char sFileCntryCode[ 2    ];    /* 파일국가번호 */
    char sCrcyCode     [ 3    ];    /* 통화코드     */
	char OwnTp         [ 1    ];
    char TpNm21        [10    ];
}   SOFAQ215Occ_Sub_st, * lpSOFAQ215Occ_Sub_st;
#define SZ_SOFAQ215Occ_sub  sizeof(SOFAQ215Occ_Sub_st)

typedef struct _SOFAQ215Occ_
{
    SOFAQ215_IN         icc;
    char Out            [ 5    ];    /* 레코드갯수 */
}   SOFAQ215Occ_st, * lpSOFAQ215Occ_st;
#define SZ_SOFAQ215Occ_st   sizeof(SOFAQ215Occ_st)


#if 0
typedef struct SOFAQ215_OUT_ST
{
    char sTrdDt        [ 8];    /* 거래일       */
    char sSettDt       [ 8];    /* 결제일       */
    char sIsuNm        [40];    /* 종목명       */
    char sTrdNo        [ 9];    /* 거래번호     */
    char sAcntNo       [20];    /* 계좌번호     */
    char sBnsTpNm      [10];    /* 매매구분     */
    char sTrdQty       [15];    /* 거래수량     */
    char sUprc         [13];    /* 단가         */
    char sFcurrTrdAmt  [15];    /* 외화거래금액 */
    char sFcurrSettAmt [15];    /* 외화결제금액 */
    char sCmsnAmt1     [15];    /* 수수료1      */
    char sCmsnAmt2     [15];    /* 수수료2      */
    char sCmsnAmt3     [15];    /* 수수료3      */
    char sBrkCmsnAmt   [15];    /* BROKER수수료 */
    char sCmsnAmt4     [15];    /* 수수료4      */
    char sCmsnAmt5     [15];    /* 수수료5      */
    char sAbrdMktIdNm  [50];    /* 해외거래소명 */
}   SOFAQ215_OUT, * lpSOFAQ215_OUT;
#define SZ_SOFAQ215_OUT     sizeof(SOFAQ215_OUT)
#endif

/***********************************************************************
 * 외화증권결제내역 - SOFAQ211
 ***********************************************************************/
typedef struct
{
    char    In          [ 5];   /*      */
	char 	AcntNo		[20];
	char	IsuNo		[12];
	char	QryTp		[1];
	char	QrySrtDt	[8];
	char	QryEndDt	[8];
	char	BrnNo		[3];
	char 	BnsTp		[1];
	char	CntryCode	[3];
	char	IttCode		[9];
	char	QryObjTp	[1];
	char	EmpNo		[9];
} SOFAQ211_IN, *lpSOFAQ211_IN;
#define SZ_SOFAQ211_IN sizeof(SOFAQ211_IN)

typedef struct
{
    char  Out[5];	
    char  EmpNm[40];	      /*사원명*/
    char  IsuNm[40];	      /*종목명*/
    char  BrnNm[40];	      /*지점명*/
    char  BnsTpNm[10];	      /*매매구분*/
    char  CntryNm[40];	      /*국가명*/
    char  TrdMkt[24];  	      /*거래시장*/
    char  BuyCnt[10];	      /*매수건수*/
    char  FcurrBuyAmt[17];	  /*외화매수금액*/
    char  SellCnt[10];	      /*매도건수*/
    char  FcurrSellAmt[17];	  /*외화매도금액*/
    char  AppyCnt[10];	      /*청약건수*/
    char  FcstckAppyAmt[17];	/*외화증권청약금액*/
    char  BuySecCmsnAmt[17];	/*매수SEC수수료*/
    char  SellSecCmsnAmt[17];	/*매도SEC수수료*/
    char  BuyFcurrEtcTax[17];	/*매수외화기타세금*/
    char  SellFcurrEtcTax[17];	/*매도외화기타세금*/
    char  BuyBrkCmsnAmt[17];	/*매수BROKER수수료*/
    char  SellBrkCmsnAmt[17];	/*매도BROKER수수료*/
    char  BuyKsdCmsnAmt[17];	/*매수KSD수수료*/
    char  SellKsdCmsnAmt[17];	/*매도KSD수수료*/
    char  BuyOtherFee[17];	    /*매수Other Fee*/
    char  SellOtherFee[17];	    /*매도Other Fee*/
    char  CmsnAmt1[17];	/*수수료1*/
    char  CmsnAmt2[17];	/*수수료2*/
    char  CmsnAmt3[17];	/*수수료3*/
    char  CmsnAmt4[17];	/*수수료4*/
    char  CmsnAmt5[17];	/*수수료5*/
    char  CmsnAmt6[17];	/*수수료6*/
} SOFAQ211_OUT, *lpSOFAQ211_OUT;
#define SZ_SOFAQ211_OUT sizeof(SOFAQ211_OUT)




/***********************************************************************
 * 외화증권예탁금변동내역 - SOFAQ238
 ***********************************************************************/
typedef struct
{
	char    In  		[ 5];	/*      */
	char 	BrnNo		[ 3];	/* 지점번호 */
	char	QryDt		[ 8];	/* 조회일 */
	char	PdptnCode	[ 2];	/* 상품유형코드 */
	char	CrcyCode	[ 3];	/* 통화코드 */
} SOFAQ238_IN, *lpSOFAQ238_IN;
#define SZ_SOFAQ238_IN sizeof(SOFAQ238_IN)

typedef struct
{
    char    BrnNm[40];          /*지점명            */
    char    CrcyCode[3];        /*통화코드          */
    char    CrcyNm[40];         /*통화명            */
    char    FcurrDpsBfbal[17];  /*외화예수금전잔    */
    char    FcurrDpsCrbal[17];  /*외화예수금금잔    */
    char    FcurrDpsIncamt[17]; /*와화예수금증가금액*/
    char    FcurrDpsDeamt[17];  /*외화예수금감소금액*/
} SOFAQ238_Sub1_OUT, *lpSOFAQ238_Sub1_OUT;
#define SZ_SOFAQ238_Sub1_OUT sizeof(SOFAQ238_Sub1_OUT)

typedef struct
{
    char    SmryNo[ 4];             /*적요번호        */
    char    SmryNm[40];             /*적요명          */
    char    RealMnyinFcurrAmt[17];  /*실입금액(외화)  */
    char    RealMnyioFcurrAmt[17];  /*실입출금외화금액*/
    char    FcurrOrgAmt[17];        /*외화원금액      */
    char    SecCmsnAmt[17];         /*SEC수수료       */
    char    KsdCmsnAmt[17];         /*KSD수수료       */
    char    BrkCmsnAmt[17];         /*BROKER수수료    */
    char    FcurrEtcTax[17];        /*외화기타세금    */
    char    FcurrEtcCmsnAmt[17];    /*외화기타수수료  */
    char    CmsnAmt1[17];           /*수수료1         */
    char    CmsnAmt2[17];           /*수수료2         */
    char    CmsnAmt3[17];           /*수수료3         */
    char    CmsnAmt4[17];           /*수수료4         */
    char    CrcyCode[ 3];           /*통화코드        */
} SOFAQ238_Sub2_OUT, *lpSOFAQ238_Sub2_OUT;
#define SZ_SOFAQ238_Sub2_OUT sizeof(SOFAQ238_Sub2_OUT)	                

typedef struct
{
	char Out	[5];
} SOFAQ238_Sub_OUT, *lpSOFAQ238_Sub_OUT;
#define SZ_SOFAQ238_Sub_OUT sizeof(SOFAQ238_Sub_OUT)
typedef struct
{
	SOFAQ238_IN in; 
	SOFAQ238_Sub_OUT out;
} SOFAQ238_OUT, *lpSOFAQ238_OUT;
#define SZ_SOFAQ238_OUT sizeof(SOFAQ238_OUT)

/***********************************************************************
 * 현물 주문 - SONAT000
 ***********************************************************************/
typedef struct
{
char  In                  [5 ];
char  AcntNo              [20];  //계좌번호
char  InptPwd             [8 ];  //비밀번호
char  IsuNo               [12];  //종목번호
char  OrdQty              [16];  //주문수량
char  OrdPrc              [13];  //주문가격
char  BnsTp               [1 ];  //매매구분 1:매도 2:매수
char  OrdprcPtnCode       [2 ];  //호가유형코드 00:지정가 03:시장가
char  PrgmOrdprcPtnCode   [2 ];  //프로그램호가유형코드 00:일반
char  StslAbleYn          [1 ];  //공매도가능여부  0:불가
char  StslOrdprcTp        [1 ];  //공매도호가구분  0:일반
char  CommdaCode          [2 ];  //통신매체코드
char  MgntrnCode          [3 ];  //신용거래코드  000:보통
char  LoanDt              [8 ];  //대출일
char  MbrNo               [3 ];  //회원번호  052:리딩
char  OrdCndiTp           [1 ];  //주문조건구분  0:없음 1:IOC 2:FOK
char  StrtgCode           [6 ];  //전략코드
char  GrpId               [20];  //그룹ID
char  OrdSeqNo            [10];  //주문회차
char  PtflNo              [10];  //포트폴리오번호
char  BskNo               [10];  //바스켓번호
char  TrchNo              [10];  //트렌치번호
char  ItemNo              [10];  //아이템번호
char  OpDrtnNo            [12];  //운용지사번호
char  LpYn                [1 ];  //유동성공급자여부 0:일반
char  CvrgTp              [1 ];  //반대매매구분  0:일반
} SONAT000_IN, *lpSONAT000_IN;
#define SZ_SONAT000_IN sizeof(SONAT000_IN)

typedef struct
{
char    In  [   5   ]   ;   /*      */
char    AcntNo  [   20  ]   ;   /*  계좌번호    */
char    InptPwd [   8   ]   ;   /*  입력비밀번호    */
char    IsuNo   [   12  ]   ;   /*  종목번호    */
char    OrdQty  [   16  ]   ;   /*  주문수량    */
char    OrdPrc  [   13  ]   ;   /*  주문가  */
char    BnsTp   [   1   ]   ;   /*  매매구분    */
char    OrdprcPtnCode   [   2   ]   ;   /*  호가유형코드    */
char    PrgmOrdprcPtnCode   [   2   ]   ;   /*  프로그램호가유형코드    */
char    StslAbleYn  [   1   ]   ;   /*  공매도가능여부  */
char    StslOrdprcTp    [   1   ]   ;   /*  공매도호가구분  */
char    CommdaCode  [   2   ]   ;   /*  통신매체코드    */
char    MgntrnCode  [   3   ]   ;   /*  신용거래코드    */
char    LoanDt  [   8   ]   ;   /*  대출일  */
char    MbrNo   [   3   ]   ;   /*  회원번호    */
char    OrdCndiTp   [   1   ]   ;   /*  주문조건구분    */
char    StrtgCode   [   6   ]   ;   /*  전략코드    */
char    GrpId   [   20  ]   ;   /*  그룹ID  */
char    OrdSeqNo    [   10  ]   ;   /*  주문회차    */
char    PtflNo  [   10  ]   ;   /*  포트폴리오번호  */
char    BskNo   [   10  ]   ;   /*  바스켓번호  */
char    TrchNo  [   10  ]   ;   /*  트렌치번호  */
char    ItemNo  [   10  ]   ;   /*  아이템번호  */
char    OpDrtnNo    [   12  ]   ;   /*  운용지시번호    */
char    LpYn    [   1   ]   ;   /*  유동성공급자여부    */
char    CvrgTp  [   1   ]   ;   /*  반대매매구분    */
char    Out [   5   ]   ;   /*      */
char    OrdNo   [   10  ]   ;   /*  주문번호    */
char    OrdTime [   9   ]   ;   /*  주문시각    */
char    OrdMktCode  [   2   ]   ;   /*  주문시장코드    */
char    OrdPtnCode  [   2   ]   ;   /*  주문유형코드    */
char    ShtnIsuNo   [   9   ]   ;   /*  단축종목번호    */
char    MgempNo [   9   ]   ;   /*  관리사원번호    */
char    OrdAmt  [   16  ]   ;   /*  주문금액    */
char    SpareOrdNo  [   10  ]   ;   /*  예비주문번호    */
char    CvrgSeqno   [   10  ]   ;   /*  반대매매일련번호    */
char    RsvOrdNo    [   10  ]   ;   /*  예약주문번호    */
char    SpotOrdQty  [   16  ]   ;   /*  실물주문수량    */
char    RuseOrdQty  [   16  ]   ;   /*  재사용주문수량  */
char    MnyOrdAmt   [   16  ]   ;   /*  현금주문금액    */
char    SubstOrdAmt [   16  ]   ;   /*  대용주문금액    */
char    RuseOrdAmt  [   16  ]   ;   /*  재사용주문금액  */
char    AcntNm  [   40  ]   ;   /*  계좌명  */
char    IsuNm   [   40  ]   ;   /*  종목명  */

} SONAT000_OUT, *lpSONAT000_OUT;
#define SZ_SONAT000_OUT sizeof(SONAT000_OUT)

/***********************************************************************
 * 현물 정정 주문 - SONAT001
 ***********************************************************************/
typedef struct
{
char    In  [   5   ]   ;   /*      */
char    OrgOrdNo  [   10  ]   ;   /* 주문번호 */
char    AcntNo  [   20  ]   ;   /*  계좌번호    */
char    InptPwd [   8   ]   ;   /*  입력비밀번호    */
char    IsuNo   [   12  ]   ;   /*  종목번호    */
char    OrdQty  [   16  ]   ;   /*  주문수량    */
char    OrdprcPtnCode  [   2   ]   ;   /* 호가유형코드 */
char    OrdCndiTp  [   1   ]   ;   /* 주문조건구분 */
char    OrdPrc  [   13   ]   ;   /* 주문가 */
char    CommdaCode  [   2   ]   ;   /*  통신매체코드    */
char    StrtgCode   [   6  ]   ;   /* 전략코드 */
char    GrpId   [   20  ]   ;   /*  그룹ID  */
char    OrdSeqNo    [   10  ]   ;   /*  주문회차    */
char    PtflNo  [   10  ]   ;   /*  포트폴리오번호  */
char    BskNo   [   10  ]   ;   /*  바스켓번호  */
char    TrchNo  [   10  ]   ;   /*  트렌치번호  */
char    ItemNo  [   10  ]   ;   /*  아이템번호  */

} SONAT001_IN, *lpSONAT001_IN;
#define SZ_SONAT001_IN sizeof(SONAT001_IN)

typedef struct
{
char    In  [   5   ]   ;   /*      */
char    OrgOrdNo  [   10  ]   ;   /* 주문번호 */
char    AcntNo  [   20  ]   ;   /*  계좌번호    */
char    InptPwd [   8   ]   ;   /*  입력비밀번호    */
char    IsuNo   [   12  ]   ;   /*  종목번호    */
char    OrdQty  [   16  ]   ;   /*  주문수량    */
char    OrdprcPtnCode  [   2   ]   ;   /* 호가유형코드 */
char    OrdCndiTp  [   1   ]   ;   /* 주문조건구분 */
char    OrdPrc  [   13   ]   ;   /* 주문가 */
char    CommdaCode  [   2   ]   ;   /*  통신매체코드    */
char    StrtgCode   [   6  ]   ;   /* 전략코드 */
char    GrpId   [   20  ]   ;   /*  그룹ID  */
char    OrdSeqNo    [   10  ]   ;   /*  주문회차    */
char    PtflNo  [   10  ]   ;   /*  포트폴리오번호  */
char    BskNo   [   10  ]   ;   /*  바스켓번호  */
char    TrchNo  [   10  ]   ;   /*  트렌치번호  */
char    ItemNo  [   10  ]   ;   /*  아이템번호  */

char    Out [   5   ]   ;   /*      */
char    OrdNo   [   10  ]   ;   /*  주문번호    */
char    PrntOrdNo   [   10  ]   ;   /* 모주문번호 */
char    OrdTime [   9   ]   ;   /*  주문시각    */
char    OrdMktCode  [   2   ]   ;   /*  주문시장코드    */
char    OrdPtnCode  [   2   ]   ;   /*  주문유형코드    */
char    ShtnIsuNo   [   9   ]   ;   /*  단축종목번호    */
char    PrgmOrdprcPtnCode   [   2   ]   ;   /* 프로그램호가유형코드 */
char    StslOrdprcTp   [   1   ]   ;   /* 공매도호가구분 */
char    StslAbleYn   [   1   ]   ;   /* 공매도가능여부 */
char    MgntrnCode   [   3   ]   ;   /*신용거래코드*/
char    LoanDt  [   8   ]   ;   /*  대출일  */
char    CvrgOrdTp  [   1   ]   ;   /*  반대매매구분    */
char    LpYn    [   1   ]   ;   /*  유동성공급자여부    */
char    MgempNo [   9   ]   ;   /*  관리사원번호    */
char    OrdAmt [   16   ]   ;   /* 주문금액*/
char    BnsTp [   1   ]   ;   /* 매매구분 */
char    SpareOrdNo  [   10  ]   ;   /*  예비주문번호    */
char    CvrgSeqno   [   10  ]   ;   /*  반대매매일련번호    */
char    RsvOrdNo    [   10  ]   ;   /*  예약주문번호    */
char    MnyOrdAmt    [   16  ]   ;   /* 현금주문금액 */
char    SubstOrdAmt    [   16  ]   ;   /* 대용용주문금액 */
char    RuseOrdAmt    [   16  ]   ;   /* 재사용주문금액 */
char    AcntNm    [   40  ]   ;   /* 계좌명 */
char    IsuNm   [   40  ]   ;   /*  종목명  */

} SONAT001_OUT, *lpSONAT001_OUT;
#define SZ_SONAT001_OUT sizeof(SONAT001_OUT)


/***********************************************************************
 * 현물 취소 주문 - SONAT002
 ***********************************************************************/
typedef struct
{
char    In  [   5   ]   ;   /*      */
char    OrgOrdNo  [   10  ]   ;   /* 주문번호 */
char    AcntNo  [   20  ]   ;   /*  계좌번호    */
char    InptPwd [   8   ]   ;   /*  입력비밀번호    */
char    IsuNo   [   12  ]   ;   /*  종목번호    */
char    OrdQty  [   16  ]   ;   /*  주문수량    */
char    CommdaCode  [   2   ]   ;   /*  통신매체코드    */
char    GrpId   [   20  ]   ;   /*  그룹ID  */
char    StrtgCode   [   6  ]   ;   /* 전략코드 */
char    OrdSeqNo    [   10  ]   ;   /*  주문회차    */
char    PtflNo  [   10  ]   ;   /*  포트폴리오번호  */
char    BskNo   [   10  ]   ;   /*  바스켓번호  */
char    TrchNo  [   10  ]   ;   /*  트렌치번호  */
char    ItemNo  [   10  ]   ;   /*  아이템번호  */

} SONAT002_IN, *lpSONAT002_IN;
#define SZ_SONAT002_IN sizeof(SONAT002_IN)

typedef struct
{
char    In  [   5   ]   ;   /*      */
char    OrgOrdNo  [   10  ]   ;   /* 주문번호 */
char    AcntNo  [   20  ]   ;   /*  계좌번호    */
char    InptPwd [   8   ]   ;   /*  입력비밀번호    */
char    IsuNo   [   12  ]   ;   /*  종목번호    */
char    OrdQty  [   16  ]   ;   /*  주문수량    */
char    CommdaCode  [   2   ]   ;   /*  통신매체코드    */
char    GrpId   [   20  ]   ;   /*  그룹ID  */
char    StrtgCode   [   6  ]   ;   /* 전략코드 */
char    OrdSeqNo    [   10  ]   ;   /*  주문회차    */
char    PtflNo  [   10  ]   ;   /*  포트폴리오번호  */
char    BskNo   [   10  ]   ;   /*  바스켓번호  */
char    TrchNo  [   10  ]   ;   /*  트렌치번호  */
char    ItemNo  [   10  ]   ;   /*  아이템번호  */

char    Out [   5   ]   ;   /*      */
char    OrdNo   [   10  ]   ;   /*  주문번호    */
char    PrntOrdNo   [   10  ]   ;   /* 모주문번호 */
char    OrdTime [   9   ]   ;   /*  주문시각    */
char    OrdMktCode  [   2   ]   ;   /*  주문시장코드    */
char    OrdPtnCode  [   2   ]   ;   /*  주문유형코드    */
char    ShtnIsuNo   [   9   ]   ;   /*  단축종목번호    */
char    PrgmOrdprcPtnCode   [   2   ]   ;   /* 프로그램호가유형코드 */
char    StslOrdprcTp   [   1   ]   ;   /* 공매도호가구분 */
char    StslAbleYn   [   1   ]   ;   /* 공매도가능여부 */
char    MgntrnCode   [   3   ]   ;   /*신용거래코드*/
char    LoanDt  [   8   ]   ;   /*  대출일  */
char    CvrgOrdTp  [   1   ]   ;   /*  반대매매구분    */
char    LpYn    [   1   ]   ;   /*  유동성공급자여부    */
char    MgempNo [   9   ]   ;   /*  관리사원번호    */
char    BnsTp [   1   ]   ;   /* 매매구분 */
char    SpareOrdNo  [   10  ]   ;   /*  예비주문번호    */
char    CvrgSeqno   [   10  ]   ;   /*  반대매매일련번호    */
char    RsvOrdNo    [   10  ]   ;   /*  예약주문번호    */
char    AcntNm    [   40  ]   ;   /* 계좌명 */
char    IsuNm   [   40  ]   ;   /*  종목명  */

} SONAT002_OUT, *lpSONAT002_OUT;
#define SZ_SONAT002_OUT sizeof(SONAT002_OUT)

/***********************************************************************
 * 결제예정예수금상세 - SONCQ021
 ***********************************************************************/
typedef struct
{
	char In          [ 5]; /*            */
	char AcntNo      [20]; /*계좌번호    */
	char Pwd         [ 8]; /*비밀번호    */
} SONCQ021_IN, *lpSONCQ021_IN;
#define SZ_SONCQ021_IN sizeof(SONCQ021_IN)

typedef struct 
{
	char BuyAmt        [16]; /*매수금액    */
    char BuyCmsnAmt    [16]; /*매수수수료  */
    char BuyAdjstAmt   [16]; /*매수정산금액*/
    char SellAmt       [16]; /*매도금액    */
    char SellCmsnAmt   [16]; /*매도수수료  */
    char SellEvrTax    [16]; /*매도제세금  */
    char SellAdjstAmt  [16]; /*매도정산금액*/
    char BnsAmt        [16]; /*매매금액    */
    char BnsCmsnAmt    [16]; /*매매수수료  */
    char EvrTax        [16]; /*제세금      */
} SONCQ021_OUT_Sub, *lpSONCQ021_OUT_Sub;
#define SZ_SONCQ021_OUT_Sub sizeof(SONCQ021_OUT_Sub)

typedef struct 
{
	char Dps           [16]; /*예수금      */
    char RepayRqrdAmt  [16]; /*변제소요금  */
    char D1dps         [16]; /*D1예수금    */
    char D2dps         [16]; /*D2예수금    */
} SONCQ021_OUT_Sub2, *lpSONCQ021_OUT_Sub2;
#define SZ_SONCQ021_OUT_Sub2 sizeof(SONCQ021_OUT_Sub2)


typedef struct
{
	char Out1           [ 5];
	lpSONCQ021_OUT_Sub  data1;	
	char Out2		    [ 5];
	lpSONCQ021_OUT_Sub  data2;
	char Out3          	[ 5]; 
	lpSONCQ021_OUT_Sub2 data3; 
} SONCQ021_OUT, *lpSONCQ021_OUT;
#define SZ_SONCQ021_OUT sizeof(SONCQ021_OUT)

typedef struct
{
    char In            [5]; //               
    char AcntNo        [20]; //계좌번호      
    char Pwd           [8]; //비밀번호       
} SDPAQ013_IN, *lpSDPAQ013_IN;
#define SZ_SDPAQ013_IN sizeof(SDPAQ013_IN)


///////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char In                  [  5]; //  
    char FundOpAcntNo        [ 20]; // 펀드운용계좌번호 X(20)
    char BookQty             [ 16]; // 장부수량 S9(15)
    char ExecDt              [  8]; // 체결일 X(8)
    char OpLmtAmt            [ 16]; // 운용한도금액 S9(15)
    char BuyLmtAmt           [ 16]; // 매수한도금액 S9(15)
    char CrdayHldRat         [ 12]; // 금일보유비율 S9(4).9(6)
    char FundErnrat          [ 12]; // 펀드수익률 S9(4).9(6)
    char HldQty              [ 16]; // 보유수량 S9(15)
    char HldAmt              [ 16]; // 보유금액 S9(15)
    char EvalAmt             [ 16]; // 평가금액 S9(15)
    char EvalPnlAmt          [ 16]; // 평가손익금액 S9(15)
    char DtBnsplAmt          [ 17]; // 일매매손익금액 S9(16)
    char MthBnsplAmt         [ 17]; // 월매매손익금액 S9(16)
    char BnsplAmt            [ 16]; // 매매손익금액 S9(15)
    char AllPnlSum           [ 16]; // 전체손익합계 S9(15)
    char PrdayCmpPnlAmt      [ 16]; // 전일대비손익금액 S9(15)
} SSESQ110_IN, *lpSSESQ110_IN;
#define SZ_SSESQ110_IN sizeof(SSESQ110_IN)

typedef struct
{
	char In                  [  5]; //
    char FundOpAcntNoi        [ 20]; // 펀드운용계좌번호 X(20)
    char BookQtyi             [ 16]; // 장부수량 S9(15)
    char ExecDti              [  8]; // 체결일 X(8)
    char OpLmtAmti            [ 16]; // 운용한도금액 S9(15)
    char BuyLmtAmti           [ 16]; // 매수한도금액 S9(15)
    char CrdayHldRati         [ 12]; // 금일보유비율 S9(4).9(6)
    char FundErnrati          [ 12]; // 펀드수익률 S9(4).9(6)
    char HldQtyi              [ 16]; // 보유수량 S9(15)
    char HldAmti              [ 16]; // 보유금액 S9(15)
    char EvalAmti             [ 16]; // 평가금액 S9(15)
    char EvalPnlAmti          [ 16]; // 평가손익금액 S9(15)
    char DtBnsplAmti          [ 17]; // 일매매손익금액 S9(16)
    char MthBnsplAmti         [ 17]; // 월매매손익금액 S9(16)
    char BnsplAmti            [ 16]; // 매매손익금액 S9(15)
    char AllPnlSumi           [ 16]; // 전체손익합계 S9(15)
    char PrdayCmpPnlAmti      [ 16]; // 전일대비손익금액 S9(15)
    char Out                 [  5]; //  
    char FundNm              [ 40]; // 펀드명 X(40)
    char OpLmtAmt            [ 16]; // 운용한도금액 S9(15)
    char BuyLmtAmt           [ 16]; // 매수한도금액 S9(15)
    char CrdayHldRat         [ 12]; // 금일보유비율 S9(4).9(6)
    char FundErnrat          [ 12]; // 펀드수익률 S9(4).9(6)
    char HldQty              [ 16]; // 보유수량 S9(15)
    char HldAmt              [ 16]; // 보유금액 S9(15)
    char EvalAmt             [ 16]; // 평가금액 S9(15)
    char EvalPnlAmt          [ 16]; // 평가손익금액 S9(15)
    char DtBnsplAmt          [ 17]; // 일매매손익금액 S9(16)
    char MthBnsplAmt         [ 17]; // 월매매손익금액 S9(16)
    char BnsplAmt            [ 16]; // 매매손익금액 S9(15)
    char AllPnlSum           [ 16]; // 전체손익합계 S9(15)
    char PrdayCmpPnlAmt      [ 16]; // 전일대비손익금액 S9(15)
    char BalStat             [  5]; //  
} SSESQ110_OUT, *lpSSESQ110_OUT;
#define SZ_SSESQ110_OUT sizeof(SSESQ110_OUT)

typedef struct
{
    char RegMktNm            [ 40]; // 등록시장명 X(40)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char IsuNm               [ 40]; // 종목명 X(40)
    char PrdayHldQty         [ 16]; // 전일보유수량 S9(15)
    char SellQty             [ 16]; // 매도수량 S9(15)
    char BuyQty              [ 16]; // 매수수량 S9(15)
    char CrdayHldQty         [ 16]; // 금일보유수량 S9(15)
    char Curprc              [ 13]; // 현재가 S9(9).99
    char BookUprc            [ 15]; // 장부단가 S9(9).9(4)
    char BookAmt             [ 16]; // 장부금액 S9(15)
    char EvalAmt             [ 16]; // 평가금액 S9(15)
    char ErnRat              [ 12]; // 수익률 S9(4).9(6)
    char CrdayHldRat         [ 12]; // 금일보유비율 S9(4).9(6)
    char BnsPnlAmt           [ 16]; // 매매손익금액 S9(15)
    char EvalPnlAmt          [ 16]; // 평가손익금액 S9(15)
    char TrdCostAmt          [ 16]; // 거래비용금액 S9(15)
    char BnsCostAmt          [ 16]; // 매매비용금액 S9(15)
} SSESQ110_SUB, *lpSSESQ110_SUB;
#define SZ_SSESQ110_SUB sizeof(SSESQ110_SUB)
//////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char In                  [  5]; //  
    char ClrgTp              [  1]; // 결산구분 X(1)
    char IvstfndCode         [ 12]; // 투신펀드코드 X(12)
    char ClrgDt              [  8]; // 결산일 X(8)
    char ClrgTrxTp           [  1]; // 결산처리구분 X(1)
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char MgmtPsnEmpNo        [  9]; // 관리자사원번호 X(9)
} SOFFQ174_IN, *lpSOFFQ174_IN;
#define SZ_SOFFQ174_IN sizeof(SOFFQ174_IN)

typedef struct
{
    char Out                 [  5]; // X(5) 
    char OtptDt              [  8]; // 출력일자 X(8)
    char TrnsrcvTme          [  9]; // 송수신시간 X(9)
    char HanglIvstfndNm      [ 40]; // 한글투신펀드명 X(40)
    char RmndLoanAmt         [ 16]; // 잔여대출금액 S9(15)
    char DstbBfCostAmt       [ 16]; // 분배전비용금액 S9(15)
	char Hang				 [100];
    char stAsClrg            [  5]; //  
} SOFFQ174_OUT, *lpSOFFQ174_OUT;
#define SZ_SOFFQ174_OUT sizeof(SOFFQ174_OUT)

typedef struct
{
    char BrnNo               [  3]; // 지점번호 X(3)
    char BrnNm               [ 40]; // 지점명 X(40)
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char AcntNm              [ 40]; // 계좌명 X(40)
    char ClrgBnsPrc          [ 20]; // 결산매매가 S9(8).9(10)
    char ClrgBoaPrc          [ 20]; // 결산과표가 S9(8).9(10)
    char TrdAmt              [ 16]; // 거래금액 S9(15)
    char TrdQty              [ 16]; // 거래수량 S9(15)
    char BoaAmt              [ 16]; // 과표금액 S9(15)
    char TrdNo               [ 10]; // 거래번호 S9(9)
    char Ictax               [ 16]; // 소득세 S9(15)
    char Ihtax               [ 16]; // 주민세 S9(15)
    char BalUnit             [ 16]; // 잔고좌수 S9(15)
    char TaxBfAmt            [ 16]; // 세전금액 S9(15)
    char TaxAfAmt            [ 16]; // 세후금액 S9(15)
    char BalQty              [ 16]; // 잔고수량 S9(15)
    char IvstfndCode2        [ 12]; // 투신펀드코드2 X(12)
    char FundNm              [ 40]; // 펀드명 X(40)
    char DecBoaAmt2010       [ 16]; // 해외펀드 2010년
    char OfstMchndCmsnAmt    [ 16]; // 차감판매수수료 S9(15)
    char OfstCdscHldbkBoaAmt [ 16]; // 차감CDSC유보과표금액 S9(15)
    char OfstBoaHldbkAmt     [ 16]; // 차감과표유보금액 S9(15)
    char OfstLossCrovrBoaAmt [ 16]; // 차감손실이월과표금액 S9(15)
    char AddLossCrovrBoaAmt  [ 16]; // 가산손실이월과표금액 S9(15)
    char AddBoaHldbkAmt      [ 16]; // 가산과표유보금액 S9(15)
    char OpfirmCmsnAmt       [ 16]; // 운용사수수료 S9(15)
    char CmsnAmt             [ 16]; // 수수료 S9(15)
    char TrxTpNm1            [ 20]; // 처리구분명1 X(20)
    char TrdTpNm1            [ 20]; // 거래구분명1 X(20)
    char MgmtPsnEmpNo        [  9]; // 관리자사원번호 X(9)
    char MgmtPsnNm           [ 40]; // 관리자명 X(40) 
	char CnvsEmpNo 			 [  9];
	char CnvsEmpNm			 [ 40]; 
	char PeclFundTp			 [  1];

} SOFFQ174_SUB, *lpSOFFQ174_SUB;
#define SZ_SOFFQ174_SUB sizeof(SOFFQ174_SUB)
/////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char In                  [  5]; //  
    char BaseDt              [  8]; // 기준일 X(8)
    char CpnTp               [  1]; // 이표구분 X(1)
    char FundOpAcntNo        [ 20]; // 펀드운용계좌번호 X(20)
    char ClrgPtnTp           [  1]; // 결산유형구분 X(1)
    char NewOldTp            [  1]; // 신구구분 X(1)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char SettTp              [  1]; // 결제구분 X(1)
    char QryTp               [  1]; // 조회구분 X(1)
} SSEBQ412_IN, *lpSSEBQ412_IN;
#define SZ_SSEBQ412_IN sizeof(SSEBQ412_IN)

typedef struct
{
    char Out                 [  5]; //  
    char CoNm                [ 40]; // 회사명 X(40)
    char BaseDt              [  8]; // 기준일 X(8)
    char FundOpAcntNo        [ 20]; // 펀드운용계좌번호 X(20)
    char FundNm              [ 40]; // 펀드명 X(40)
    char ClntMthAvrQty       [ 20]; // 고객월평균수량 S9(13).9(5)
    char Drtn                [ 17]; // 듀레이션 S9(5).9(10)
    char Drtn1               [ 17]; // 듀레이션1 S9(5).9(10)
    char Crtdr               [ 17]; // 수정듀레이션 S9(5).9(10)
    char SettTpNm            [ 41]; // 결제구분명 X(41)
    char CouponRat           [ 18]; // 표면이율 S9.9(15)
    char PchsErnrat          [ 12]; // 매입수익률 S99.9(8)
    char Out2                [  5]; //  
} SSEBQ412_OUT, *lpSSEBQ412_OUT;
#define SZ_SSEBQ412_OUT sizeof(SSEBQ412_OUT)

typedef struct
{
    char TpNm2               [ 40]; // 구분명2 X(40)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char IsuNm               [ 40]; // 종목명 X(40)
    char IssuDt              [  8]; // 발행일 X(8)
    char DueDt               [  8]; // 만기일 X(8)
    char RemnTerm            [  6]; // 잔존기간 S9(5)
    char BndClssNm           [ 40]; // 채권분류명 X(40)
    char BndKindCodeNm       [ 40]; // 채권종류코드명 X(40)
    char SmbndKindNm         [ 40]; // 소액채권종류명 X(40)
    char BalQty              [ 16]; // 잔고수량 S9(15)
    char EvalErnrat1         [ 12]; // 평가수익률1 S9(4).9(6)
    char EvalUprc1           [ 15]; // 평가단가1 S9(9).9(4)
    char EvalAmt             [ 16]; // 평가금액 S9(15)
    char BookUprc            [ 15]; // 장부단가 S9(9).9(4)
    char BookAmt             [ 16]; // 장부금액 S9(15)
    char PassIntrstAmt       [ 16]; // 경과이자금액 S9(15)
    char CorpTaxDps          [ 16]; // 법인세예수금 S9(15)
    char BpUprc              [ 15]; // BP단가 S9(9).9(4)
    char BpErnrat            [ 12]; // BP수익률 S9(4).9(6)
    char RcvblIntrstAmt      [ 16]; // 미수이자금액 S9(15)
    char AcmBookAmt          [ 16]; // 누적장부금액 S9(15)
    char EvalPnlAmt          [ 16]; // 평가손익금액 S9(15)
    char BuyErnrat           [ 12]; // 매수수익률 S9(4).9(6)
    char Drtn                [ 17]; // 듀레이션 S9(5).9(10)
    char ModDrtn             [ 17]; // 수정듀레이션 S9(5).9(10)
    char Convexity           [ 17]; // 컨벡시티 S9(5).9(10)
    char TpNm1               [ 40]; // 구분명1 X(40)
    char Tax                 [ 16]; // 세금 S9(15)
    char Amt1                [ 16]; // 금액1 S9(15)
    char Amt2                [ 16]; // 금액2 S9(15)
    char CouponRat           [ 18]; // 표면이율 S9.9(15)
    char PchsErnrat          [ 12]; // 매입수익률 S99.9(8)
    char SoptQty             [ 16]; // 실물수량 S9(15)
    char PldgQty             [ 16]; // 담보수량 S9(15)
    char CodeNm01            [ 40]; // 코드명 X(40)
    char CodeNm02            [ 40]; // 코드명 X(40)
    char CodeNm03            [ 40]; // 코드명 X(40)
    char CodeNm04            [ 40]; // 코드명 X(40)
    char RcvblAsmAmt         [ 16]; // 미수이자누계액 S9(15)
    char BuyUprc             [ 15]; // 매수단가 S9(9).9(4)
    char BuyDt               [  8]; // 매수일 X(8)
    char Amt3                [ 16]; // 금액3 S9(15)
    char Amt4                [ 16]; // 금액4 S9(15)
    char UndYn               [  1]; // 인수도여부 X(1)
    char UndDsgnNm           [ 40]; // 인수도지정 X(40)
    char PassDays            [  6]; // 경과일수 S9(5)
    char AdmisAstTp          [  1]; // 편입자산구분 X(1)
    char UndTpNm             [  4]; // 인수도구분명 X(4)
    char DpslTpNm            [ 20]; // 처분구분명 X(20)
    char IttNm               [ 40]; // 기관명 X(40)
} SSEBQ412_SUB, *lpSSEBQ412_SUB;
#define SZ_SSEBQ412_SUB sizeof(SSEBQ412_SUB)
/////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char In                  [  5]; // X(5) 
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char BaseDt              [  8]; // 기준일 X(8)
    char QryTp               [  1]; // 조회구분 X(1)
    char IsuLgclssCode       [  2]; // 종목대분류코드 X(2)
    char IsuMdclssCode       [  2]; // 종목중분류코드 X(2)
    char IsuSmclssCode       [  3]; // 종목소분류코드 X(3)
    char HanglEngTp          [  1]; // 한영구분 X(1)
    char TrxTp               [  1]; // 처리구분 X(1)
} SSEOQ103_IN, *lpSSEOQ103_IN;
#define SZ_SSEOQ103_IN sizeof(SSEOQ103_IN)

typedef struct
{
    char Tot                 [  5]; // X(5) 
    char FutsSellQty         [ 16]; // 선물매도수량 S9(15)
    char FutsSellPnl         [ 16]; // 선물매도손익 S9(15)
    char FutsBuyQty          [ 16]; // 선물매수수량 S9(15)
    char FutsBuyPnl          [ 16]; // 선물매수손익 S9(15)
    char CallSellQty         [ 16]; // 콜매도수량 S9(15)
    char CallSellPnl         [ 16]; // 콜매도손익 S9(15)
    char CallBuyQty          [ 16]; // 콜매수수량 S9(15)
    char CallBuyPnl          [ 16]; // 콜매수손익 S9(15)
    char PutSellQty          [ 16]; // 풋매도수량 S9(15)
    char PutSellPnl          [ 16]; // 풋매도손익 S9(15)
    char PutBuyQty           [ 16]; // 풋매수수량 S9(15)
    char PutBuyPnl           [ 16]; // 풋매수손익 S9(15)
    char FutsUnsttQty        [ 16]; // 선물미결제수량 S9(15)
    char FutsPnlSum          [ 16]; // 선물손익합계 S9(15)
    char OptUnsttQty         [ 16]; // 옵션미결제수량 S9(15)
    char OptPnlSum           [ 16]; // 옵션손익합계 S9(15)
    char EvalPnlSum          [ 15]; // 평가손익합계 S9(14)
    char FutsCtrctAmt        [ 16]; // 선물약정금액 S9(15)
    char CalloptCtrctAmt     [ 16]; // 콜옵션약정금액 S9(15)
    char PutoptCtrctAmt      [ 16]; // 풋옵션약정금액 S9(15)
    char AllCtrctAmt         [ 16]; // 전체약정금액 S9(15)
    char Out                 [  5]; // X(5) 
} SSEOQ103_OUT, *lpSSEOQ103_OUT;
#define SZ_SSEOQ103_OUT sizeof(SSEOQ103_OUT)

typedef struct
{
    char FnoIsuNo            [ 32]; // 선물옵션종목번호 X(32)
    char ShtnHanglIsuNm      [ 40]; // 단축한글종목명 X(40)
    char BnsTp               [  1]; // 매매구분 X(1)
    char TpNm1               [ 40]; // 구분명1 X(40)
    char BalQty              [ 16]; // 잔고수량 S9(15)
    char FnoAvrPrc           [ 19]; // 평균가 S9(9).9(8)
    char BookAmt             [ 16]; // 장부금액 S9(15)
    char LqdtQty             [ 16]; // 청산수량 S9(15)
    char Curprc              [ 13]; // 현재가 S9(9).99
    char BalEvalAmt          [ 16]; // 잔고평가금액 S9(15)
    char BalEvalPnlAmt       [ 16]; // 잔고평가손익금액 S9(15)
} SSEOQ103_SUB, *lpSSEOQ103_SUB;
#define SZ_SSEOQ103_SUB sizeof(SSEOQ103_SUB)

//////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    char In                  [  5]; // X(5)
    char QryTp               [  1]; // 조회구분 X(1)
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char Pwd                 [  8]; // 비밀번호 X(8)
    char QrySrtDt            [  8]; // 조회시작일 X(8)
    char QryEndDt            [  8]; // 조회종료일 X(8)
    char SrtNo               [ 10]; // 시작번호 S9(9)
    char PdptnCode           [  2]; // 상품유형코드 X(2)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char StnlnSeqTp          [  1]; // 정렬순서구분 X(1)
} SDPBQ001_IN, *lpSDPBQ001_IN;
#define SZ_SDPBQ001_IN sizeof(SDPBQ001_IN)

typedef struct
{
    char Out                 [  5]; // X(5)
    char AcntNm              [ 40]; // 계좌명 X(40)
    char Out2                [  5]; // X(5)
} SDPBQ001_OUT, *lpSDPBQ001_OUT;
#define SZ_SDPBQ001_OUT sizeof(SDPBQ001_OUT)

typedef struct
{
    char TrdDate             [  8]; // 거래일자 X(8)
    char TrdNo               [ 10]; // 거래번호 S9(9)
    char TrdAcntNo           [ 20]; // 거래계좌번호 X(20)
    char TrdTpNm             [ 20]; // 거래구분 X(20)
    char SmryNo              [  4]; // 적요번호 X(4)
    char SmryNm              [ 40]; // 적요명 X(40)
    char CancTpNm            [ 20]; // 취소구분 X(20)
    char TrdQty              [ 16]; // 거래수량 S9(15)
    char Trtax               [ 16]; // 거래세 S9(15)
    char AdjstAmt            [ 16]; // 정산금액 S9(15)
    char OvdSum              [ 16]; // 연체합 S9(15)
    char DpsBfbalAmt         [ 16]; // 예수금전잔금액 S9(15)
    char SellPldgRfundAmt    [ 16]; // 매도담보상환금 S9(15)
    char DpspdgLoanBfbalAmt  [ 16]; // 예탁담보대출전잔금액 S9(15)
    char TrdmdaNm            [ 40]; // 거래매체명 X(40)
    char OrgTrdNo            [ 10]; // 원거래번호 S9(9)
    char IsuNm               [ 40]; // 종목명 X(40)
    char TrdUprc             [ 13]; // 거래단가 S9(9).99
    char CmsnAmt             [ 16]; // 수수료 S9(15)
    char RfundDiffAmt        [ 16]; // 상환차이금액 S9(15)
    char RepayAmtSum         [ 16]; // 변제금합계 S9(15)
    char SecCrbalQty         [ 16]; // 유가증권금잔수량 S9(15)
    char CslLoanRfundIntrstAmt[ 16]; // 매도대금담보대출상환이자금액 S9(15)
    char DpspdgLoanCrbalAmt  [ 16]; // 예탁담보대출금잔금액 S9(15)
    char TrxTime             [  9]; // 처리시각 X(9)
    char Inouno              [ 10]; // 출납번호 S9(9)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char TrdAmt              [ 16]; // 거래금액 S9(15)
    char TaxSumAmt           [ 16]; // 세금합계금액 S9(15)
    char IntrstUtlfee        [ 16]; // 이자이용료 S9(15)
    char DvdAmt              [ 16]; // 배당금액 S9(15)
    char RcvblOcrAmt         [ 16]; // 미수발생금액 S9(15)
    char TrxBrnNo            [  3]; // 처리지점번호 X(3)
    char TrxBrnNm            [ 40]; // 처리지점명 X(40)
    char DpspdgLoanAmt       [ 16]; // 예탁담보대출금액 S9(15)
    char DpspdgLoanRfundAmt  [ 16]; // 예탁담보대출상환금액 S9(15)
    char BasePrc             [ 13]; // 기준가 S9(9).99
    char DpsCrbalAmt         [ 16]; // 예수금금잔금액 S9(15)
    char Boa                 [ 16]; // 과표 S9(15)
    char MnyoutAbleAmt       [ 16]; // 출금가능금액 S9(15)
    char BcrLoanOcrAmt       [ 16]; // 수익증권담보대출발생금 S9(15)
    char BcrLoanBfbalAmt     [ 16]; // 수익증권담보대출전잔금 S9(15)
    char BnsBasePrc          [ 20]; // 매매기준가 S9(8).9(10)
    char TaxchrBasePrc       [ 20]; // 과세기준가 S9(8).9(10)
    char TrdUnit             [ 16]; // 거래좌수 S9(15)
    char BalUnit             [ 16]; // 잔고좌수 S9(15)
    char EvrTax              [ 16]; // 제세금 S9(15)
    char EvalAmt             [ 16]; // 평가금액 S9(15)
    char BcrLoanRfundAmt     [ 16]; // 수익증권담보대출상환금 S9(15)
    char BcrLoanCrbalAmt     [ 16]; // 수익증권담보대출금잔금 S9(15)
    char AddMgnOcrTotamt     [ 16]; // 추가증거금발생총액 S9(15)
    char AddMnyMgnOcrAmt     [ 16]; // 추가현금증거금발생금액 S9(15)
    char AddMgnDfryTotamt    [ 16]; // 추가증거금납부총액 S9(15)
    char AddMnyMgnDfryAmt    [ 16]; // 추가현금증거금납부금액 S9(15)
    char BnsplAmt            [ 16]; // 매매손익금액 S9(15)
    char Ictax               [ 16]; // 소득세 S9(15)
    char Ihtax               [ 16]; // 주민세 S9(15)
    char LoanDt              [  8]; // 대출일 X(8)
    char EtcBndInfo          [100]; // 기타채권정보 X(100)
    char CrdtGrdVal          [ 40]; // 신용등급값 X(40)
} SDPBQ001_SUB, *lpSDPBQ001_SUB;
#define SZ_SDPBQ001_SUB sizeof(SDPBQ001_SUB)
//////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char In                  [  5]; //  
    char BaseDt              [  8]; // 기준일 X(8)
    char FundOpAcntNo        [ 20]; // 펀드운용계좌번호 X(20)
    char ClrgTp              [  1]; // 결산구분 X(1)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char ExecTp              [  1]; // 체결구분 X(1)
    char SbrwTp              [  1]; // 대차구분 X(1)
} SSEBQ414_IN, *lpSSEBQ414_IN;
#define SZ_SSEBQ414_IN sizeof(SSEBQ414_IN)

typedef struct
{
    char Out                 [  5]; //  
    char CoNm                [ 40]; // 회사명 X(40)
    char TrxDt               [  8]; // 처리일 X(8)
    char FundOpAcntNo        [ 20]; // 펀드운용계좌번호 X(20)
    char TpNm1               [ 40]; // 구분명1 X(40)
    char Out2                [  5]; //  
} SSEBQ414_OUT, *lpSSEBQ414_OUT;
#define SZ_SSEBQ414_OUT sizeof(SSEBQ414_OUT)

typedef struct
{
    char TpNm1               [ 40]; // 구분명1 X(40)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char IsuNm               [ 40]; // 종목명 X(40)
    char RfundDt             [  8]; // 상환일 X(8)
    char RemnDays            [  6]; // 잔존일수 S9(5)
    char BndKindCodeNm       [ 40]; // 채권종류코드명 X(40)
    char BalQty              [ 16]; // 잔고수량 S9(15)
    char EvalErnrat          [ 12]; // 평가수익률 S9(4).9(6)
    char EvalUprc            [ 15]; // 평가단가 S9(9).9(4)
    char EvalAmt             [ 16]; // 평가금액 S9(15)
    char BookAmt             [ 16]; // 장부금액 S9(15)
    char EvalPnlAmt          [ 16]; // 평가손익금액 S9(15)
    char SbrwBrwQty          [ 16]; // 대차차입수량 S9(15)
    char SbrwSellQty         [ 16]; // 대차매도수량 S9(15)
    char SbrwSecEvalAmt      [ 16]; // 대차증권평가금액 S9(15)
    char StslTrdAmt          [ 16]; // 대차거래금액 S9(15)
    char StslBnsplAmt        [ 16]; // 대차매매손익금액 S9(15)
    char CouponRat           [ 18]; // 표면이율 S9.9(15)
    char BuyDt               [  8]; // 매수일 X(8)
    char BuyUprc             [ 15]; // 매수단가 S9(9).9(4)
    char RpBalQty            [ 16]; // RP잔고수량 S9(15)
    char RpSellAmt           [ 16]; // RP매도금액 S9(15)
    char RpEvalAmt           [ 16]; // RP평가금액 S9(15)
    char RpErnAmt            [ 16]; // RP수익금액 S9(15)
    char Drtn                [ 17]; // 듀레이션 S9(5).9(10)
    char ModDrtn             [ 17]; // 수정듀레이션 S9(5).9(10)
    char FundOpAcntNo        [ 20]; // 펀드운용계좌번호 X(20)
    char Convexity           [ 17]; // 컨벡시티 S9(5).9(10)
    char Amt                 [ 16]; // 금액 S9(15)
	char Rcv				 [ 16];
} SSEBQ414_SUB, *lpSSEBQ414_SUB;
#define SZ_SSEBQ414_SUB sizeof(SSEBQ414_SUB)
//////////////////////////////////////////////////////////////////////////////////

typedef struct
{
	char In                  [  5]; //  
    char TrxTp               [  1]; // 처리구분 X(1)
    char IsuNo               [ 12]; // 종목번호 X(12)
    char FcstckIsuNm         [ 60]; // 외화증권종목명 X(60)
    char FcstckWarrantIsuNm  [ 60]; // 외화증권워런트종목명 X(60)
    char FcstckPtnCode       [  2]; // 외화증권유형코드 X(2)
    char LstdYn              [  1]; // 상장여부 X(1)
    char CncrnDomIsuNo       [ 12]; // 관련국내종목번호 X(12)
    char FltnDt              [  8]; // 발행일 X(8)
    char DueDt               [  8]; // 만기일 X(8)
    char StkXchgRat          [ 15]; // 주식교환비율 S9(9).9(4)
    char DrXchgRat           [ 15]; // 예탁증서교환비율 S9(9).9(4)
    char MinTrdAbleAmt       [ 16]; // 최소거래가능금액 S9(15)
    char FcstckXrcPrc        [ 15]; // 외화증권행사가 S9(9).9(4)
    char FcurrFxdXchrat      [ 11]; // 외화고정환율 S9(5).9(4)
    char WonFxdXchrat        [ 11]; // 원화고정환율 S9(5).9(4)
    char CntryNo             [  3]; // 국가번호 X(3)
    char CrcyCode            [  3]; // 통화코드 X(3)
    char IsuTrdTp            [  1]; // 종목거래구분 X(1)
    char FcstckFltnPrc       [ 15]; // 외화증권발행가 S9(9).9(4)
    char FcstckParprc        [ 15]; // 외화증권액면가 S9(9).9(4)
    char FltnPsnLgclssCode   [  2]; // 발행자대분류코드 X(2)
    char FltnPsnNm           [ 40]; // 발행자명 X(40)
    char FcstckMprc          [ 15]; // 외화증권시가 S9(9).9(4)
    char IttCode             [  9]; // 기관코드 S9(8)
    char CstdyIttCode        [  9]; // 보관기관코드 S9(8)
    char SeCode              [  3]; // 증권거래소코드 X(3)
    char CmnCode             [ 12]; // 공통코드 X(12)
    char MjorIsuTp           [  1]; // 주요종목구분 X(1)
    char EvalPtn             [  1]; // 신주인수권부사채평가유형 X(1)
    char TrdUnitQty          [ 16]; // 거래단위수량 S9(15)
    char RsnTp               [  1]; // 사유구분 X(1)
    char MktCode4            [  4]; // 시장코드 X(4)
} SOFAT310_IN, *lpSOFAT310_IN;
#define SZ_SOFAT310_IN sizeof(SOFAT310_IN)

typedef struct
{
    char Out                 [  5]; //  
    char InptPsnId           [ 16]; // 입력자ID X(16)
    char TrxDate             [  8]; // 처리일자 X(8)
} SOFAT310_OUT, *lpSOFAT310_OUT;
#define SZ_SOFAT310_OUT sizeof(SOFAT310_OUT)
//////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    char In                  [  5]; // X(5)
	char AcntNo	[20]; //계좌번호	X(20)
	char BaseDt	[8]; //기준일	X(8)
	char IsuLgclssCode[2]; //	종목대분류코드	X(2)
	char IsuMdclssCode[2]; //	종목중분류코드	X(2)
} SSEOQ137_IN, *lpSSEOQ137_IN;
#define SZ_SSEOQ137_IN sizeof(SSEOQ137_IN)

typedef struct
{
	char Tot                 [  5]; // X(5) 
    char Amt11               [ 16]; // 금액11 S9(15)
    char Amt12               [ 16]; // 금액12 S9(15)
    char Amt13               [ 16]; // 금액13 S9(15)
    char Amt21               [ 16]; // 금액21 S9(15)
    char Amt22               [ 16]; // 금액22 S9(15)
    char Amt23               [ 16]; // 금액23 S9(15)
    char Amt31               [ 16]; // 금액31 S9(15)
    char Amt32               [ 16]; // 금액32 S9(15)
    char Amt33               [ 16]; // 금액33 S9(15)
    char Amt41               [ 16]; // 금액41 S9(15)
    char Amt42               [ 16]; // 금액42 S9(15)
    char Amt43               [ 16]; // 금액43 S9(15)
    char Amt51               [ 16]; // 금액51 S9(15)
    char Amt52               [ 16]; // 금액52 S9(15)
    char Amt53               [ 16]; // 금액53 S9(15)
    char Amt61               [ 16]; // 금액61 S9(15)
    char Amt62               [ 16]; // 금액62 S9(15)
    char Amt63               [ 16]; // 금액63 S9(15)
    char Amt71               [ 16]; // 금액71 S9(15)
    char Amt72               [ 16]; // 금액72 S9(15)
    char Amt73               [ 16]; // 금액73 S9(15)
    char Amt81               [ 16]; // 금액81 S9(15)
    char Amt83               [ 16]; // 금액83 S9(15)
    char Out                 [  5]; // X(5) 
} SSEOQ137_OUT, *lpSSEOQ137_OUT;
#define SZ_SSEOQ137_OUT sizeof(SSEOQ137_OUT)

typedef struct
{
    char FnoIsuNo            [ 32]; // 선물옵션종목번호 X(32)
    char IsuNm               [ 40]; // 종목명 X(40)
    char BnsTp               [  1]; // 매매구분 X(1)
    char BnsTpNm             [ 10]; // 매매구분 X(10)
    char BalQty              [ 16]; // 잔고수량 S9(15)
    char LqdtOrdAbleQty      [ 16]; // 청산주문가능수량 S9(15)
    char AvrUprc             [ 13]; // 평균단가 S9(9).99
    char CurPrc              [ 13]; // 현재가 S9(9).99
    char CtrctAmt            [ 16]; // 약정금액 S9(15)
    char EvalAmt             [ 16]; // 평가금액 S9(15)
    char EvalPnlAmt          [ 16]; // 평가손익금액 S9(15)
    char DeltaLmt            [ 16]; // 델타한도 S9(15)
    char GmmaLmt             [ 16]; // 감마한도 S9(15)
    char DeltaRisk           [ 16]; // 델타리스크 S9(15)
    char GmmaRisk            [ 16]; // 감마리스크 S9(15)
    char VagaRisk            [ 16]; // 베가리스크 S9(15)
    char DeepOTM             [ 16]; // 깊은외가격옵션매도위험액 S9(15)
    char RiskAmt             [ 16]; // 위험금액 S9(15)
} SSEOQ137_SUB, *lpSSEOQ137_SUB;
#define SZ_SSEOQ137_SUB sizeof(SSEOQ137_SUB)
////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    char In                  [  5]; // X(5)
    char QryDt [8]; //기준일   X(8)
} SONBQ708_IN, *lpSONBQ708_IN;
#define SZ_SONBQ708_IN sizeof(SONBQ708_IN)

typedef struct
{
    char Out2                [  5]; //  
    char DpstgMnyAsmAmt      [ 16]; // 예탁현금누계금액 S9(15)
    char DpstgSubstAsmAmt    [ 16]; // 예탁대용누계금액 S9(15)
    char CsgnMgnTotamt       [ 16]; // 위탁증거금총액 S9(15)
    char BnsMgn              [ 16]; // 매매증거금액 S9(15)
    char Out3                [  5]; // X(5) 
    char DpstgMnyAsmAmt2      [ 16]; // 예탁현금누계금액 S9(15)
    char DpstgSubstAsmAmt2    [ 16]; // 예탁대용누계금액 S9(15)
    char CsgnMgnTotamt2       [ 16]; // 위탁증거금총액 S9(15)
    char BnsMgn2              [ 16]; // 매매증거금액 S9(15)
    char Out4                [  5]; //  
    char DpstgMnyAsmAmt3      [ 16]; // 예탁현금누계금액 S9(15)
    char DpstgSubstAsmAmt3    [ 16]; // 예탁대용누계금액 S9(15)
    char CsgnMgnTotamt3       [ 16]; // 위탁증거금총액 S9(15)
    char BnsMgn3              [ 16]; // 매매증거금액 S9(15)
    char Out                 [  5]; //     
} SONBQ708_OUT, *lpSONBQ708_OUT;
#define SZ_SONBQ708_OUT sizeof(SONBQ708_OUT)

typedef struct
{
    char AcntNo              [ 20]; // 계좌번호 X(20)
    char AcntNm              [ 40]; // 계좌명 X(40)
    char DpstgMny            [ 16]; // 예탁현금 S9(15)
    char DpstgSubst          [ 16]; // 예탁대용 S9(15)
    char CsgnMgn             [ 16]; // 위탁증거금액 S9(15)
    char BnsMgn              [ 16]; // 매매증거금액 S9(15)
} SONBQ708_SUB, *lpSONBQ708_SUB;
#define SZ_SONBQ708_SUB sizeof(SONBQ708_SUB)

/////////////////////////////////////////////////////////////////////
typedef struct
{
    char In                  [  5]; // X(5)
    char    zAcntNo             [20];   // 계좌번호
    char    zPwd                [ 8];   // 비밀번호
    char    zQryDt              [ 8];   // 일자
} SOFAQ229_IN, *lpSOFAQ229_IN;
#define SZ_SOFAQ229_IN sizeof(SOFAQ229_IN)

typedef struct
{
    char    Out1                [ 5];   // 레코드갯수
    char    lWonDpsBalAmt       [16];   // 원화예수금잔고금액
    char    lWonMgn             [16];   // 원화증거금액
    char    lPsnOutAbleAmt      [16];   // 인출가능금액
    char    Out                 [ 5];   // 레코드갯수
} SOFAQ229_OUT, *lpSOFAQ229_OUT;
#define SZ_SOFAQ229_OUT sizeof(SOFAQ229_OUT)

typedef struct
{
    char    zCrcyCode           [ 3];   // 통화코드
    char    dFcurrDpsBalAmt     [17];   // 외화예수금잔고금액
    char    dFcurrMgn           [17];   // 외화증거금액
    char    dBaseXchrat         [11];   // 기준환율
    char    lWonDpsBalAmt       [16];   // 원화예수금잔고금액
    char    lWonMgn             [16];   // 원화증거금액
    char    dFcurrExecAmt       [17];   // 매도체결금액
    char    lSellExecAmt        [16];   // 매도체결금액(원화)
} SOFAQ229_SUB, *lpSOFAQ229_SUB;
#define SZ_SOFAQ229_SUB sizeof(SOFAQ229_SUB)
/////////////////////////////////////////////////////////////////////

/***********************************************************************
 *
 *	object name : SONAT002F(GTS의 SONAT002와 같지만, 국내 현물과 전문이름이 같아 GIS에서 수정)
 *	prgram id	: 
 *	tr code		: 2503
 *	description	: 해외주식 현물 취소주문
 *
 ***********************************************************************/

#if 0
typedef struct	
{
	char	In[5];							/* 레코드갯수 */
	char	lOrgOrdNo[9];					/* 원주문번호 */
	char	zAcntNo[20];					/* 계좌번호 */
	char	zInptPwd[8];					/* 입력비밀번호 */
	char	zCntryCode[3];					// 국가코드
	char	zMarketCode[4];					// 시장코드
	char	zEcnID[10];						// ECN
	char	zIsuNo[12];						/* 종목번호 */
	char	lOrdQty[16];					/* 주문수량 */
	char	zCommdaCode[2];					/* 통신매체코드 */
	char    CrcyCode[3];       				/* 08.10.27 : 통화코드 */
}   SONAT002F_IN, * lpSONAT002F_IN;
#define SZ_SONAT002F_IN				sizeof(SONAT002F_IN)

// SONAT002F_IN에 대한 응답
typedef	struct	
{
	char	In[5];							/* 레코드갯수 */
	char	lOrgOrdNo[9];					/* 원주문번호 */
	char	zAcntNo[20];					/* 계좌번호 */
	char	zInptPwd[8];					/* 입력비밀번호 */
	char	zCntryCode[3];					// 국가코드
	char	zMarketCode[4];					// 시장코드
	char	zEcnID[10];						// ECN
	char	zIsuNo[12];						/* 종목번호 */
	char	lOrdQty[16];					/* 주문수량 */
	char	zCommdaCode[2];					/* 통신매체코드 */
	char    CrcyCode[3];       				/* 08.10.27 : 통화코드 */
	char	Out[5];							/* 레코드갯수  */
	char	lOrdNo[9];						/* 주문번호 */
	char	lPrntOrdNo[9];					/* 모주문번호 */
	char	zOrdTime[9];					/* 주문시각 */
	char	zOrdMktCode[2];					/* 주문시장코드 */
	char	zOrdPtnCode[2];					/* 주문유형코드 */
	char	zShtnIsuNo[9];					/* 단축종목번호 */
	char	zPrgmOrdprcPtnCode[2];			/* 프로그램호가유형코드 */
	char	zMgempNo[9];					/* 관리사원번호 */
	char	zBnsTp[1];						/* 매매구분 */
	char	zAcntNm[40];					/* 계좌명 */
	char	zIsuNm[40];						/* 종목명 */
}   SONAT002F_OUT, * lpSONAT002F_OUT;
#define SZ_SONAT002F_OUT				sizeof(SONAT002F_OUT)

// 취소 대한 응답
typedef	struct	
{
	char	sOrdxctPtnCode[2];				/* 주문체결유형코드 */
	char	zCntryCode[3];					// 국가코드
	char	zMarketCode[4];					// 시장코드
	char	zEcnID[10];						// ECN
	char	zOrdPtnCode[2];					/* 주문유형코드 */
	char	zAcntNo[20];					/* 계좌번호 */
	char	zIsuNo[12];						/* 종목번호 */
	char	zIsuNm[40];						/* 종목명 */
	char	lOrdNo[9];						/* 주문번호 */
	char	lPrntOrdNo[9];					/* 모주문번호 */
	char	lOrdQty[16];					/* 주문수량 */
	char	dOrdPrc[17];					/* 주문가 */
	char	zOrdprcPtnCode[2];				/* 호가유형코드 */
	char	sOrgOrdUnercQty[16];			/* 원주문미체결수량 */
	char	sOrgOrdMdfyQty[16];				/* 원주문정정수량 */
	char	sOrgOrdCancQty[16];				/* 원주문취소수량 */
	char	lOrdAmt[17];					/* 주문금액 */
	char	zOrdTime[9];					/* 주문시각 */
}   SONAT002F_RES, * lpSONAT002F_RES;
#define SZ_SONAT002F_RES				sizeof(SONAT002F_RES)
#endif




/***********************************************************************
 *	DATE        : 2020-07-14
 *	prgram id	: SSESQ201
 *	tr code		: 3984
 *  주식일별펀드 손익현황
 ***********************************************************************/
typedef struct	
{
	char	In           [5 ]; 
	char	FundOpAcntNo [20]; /*  펀드운용계좌번호*/
	char	QrySrtDt     [8 ]; /*  조회시작일      */
	char	QryEndDt     [8 ]; /*  조회종료일      */
	char	CreBaseCode  [2 ]; /*  생성기준코드    */
	char	IsuNo        [12]; /*  종목번호        */
}   SSESQ201_IN, * lpSSESQ201_IN;
#define SZ_SSESQ201_IN				sizeof(SSESQ201_IN)

typedef	struct	
{
	char  Out           [5 ];   /*                */
	char  FundNm        [40];   /*  펀드명        */
	char  FundDtCfBnspl [5 ];   /*                */
}   SSESQ201_OUT, * lpSSESQ201_OUT;
#define SZ_SSESQ201_OUT				sizeof(SSESQ201_OUT)

typedef	struct	
{
	char  ExecDt        [8 ];   /*  체결일        */
	char  BookQty       [16];   /*  장부수량      */
	char  BookAmt       [16];   /*  장부금액      */
	char  EvalAmt       [16];   /*  평가금액      */
	char  DtBnsplAmt    [17];   /*  일매매손익금액*/
	char  DtEvalPnlAmt  [17];   /*  일평가손익금액*/
	char  DtTotPnlAmt   [17];   /*  일총손익금액  */
	char  YearBnsplAmt  [17];   /*  년매매손익금액*/
	char  YearEvalPnlAmt[17];   /*  년평가손익금액*/
	char  YearTotPnlAmt [17];   /*  년총손익금액  */
}   SSESQ201_OUT_OCCR1, * lpSSESQ201_OUT_OCCR1;
#define SZ_SSESQ201_OUT_OCCR1				sizeof(SSESQ201_OUT_OCCR1)



/***********************************************************************
 *	DATE        : 2020-07-14
 *	prgram id	: SSESQ119
 *	tr code		: 7179
 *  자기주식펀드잔고및손익현황
 ***********************************************************************/
typedef struct	
{
    char    In              [5   ]; /*                  */
    char    FundOpAcntNo    [20  ]; /* 펀드운용계좌번호 */
    char    SrtVal          [17+1]; /* 시작값           */
    char    OpLmtAmt        [15+1]; /* 운용한도금액     */
    char    BfDtBnsPnlamt   [15+1]; /* 전일매매손익금액 */
    char    BfDtEvalPnlAmt  [15+1]; /* 전일평가손익금액 */
    char    PrdayCmpMktAmt  [15+1]; /* 전일대비         */
    char    HldQty          [15+1]; /* 보유수량         */
    char    DtBnsplAmt      [16+1]; /* 일매매손익금액   */
    char    MthBnsplAmt     [16+1]; /* 월매매손익금액   */
    char    BnsplAmt        [15+1]; /* 매매손익금액     */
    char    HldAmt          [15+1]; /* 보유금액         */
    char    EvalAmt         [15+1]; /* 평가금액         */
    char    EvalPnlAmt      [15+1]; /* 평가손익금액     */
    char    EvalErnrat      [10+2]; /* 평가수익률       */
    char    BuyLmtAmt       [15+1]; /* 매수한도금액     */
    char    PnlSumAmt       [15+1]; /* 손익합계금액     */
}   SSESQ119_IN, * lpSSESQ119_IN;
#define SZ_SSESQ119_IN				sizeof(SSESQ119_IN)

typedef struct	
{
    char    Out             [5   ]; /*                  */
    char    FundNm          [40  ]; /* 펀드명           */
    char    OpLmtAmt        [15+1]; /* 운용한도금액     */
    char    BfDtBnsPnlamt   [15+1]; /* 전일매매손익금액 */
    char    BfDtEvalPnlAmt  [15+1]; /* 전일평가손익금액 */
    char    PrdayCmpMktAmt  [15+1]; /* 전일대비         */
    char    HldQty          [15+1]; /* 보유수량         */
    char    DtBnsplAmt      [16+1]; /* 일매매손익금액   */
    char    MthBnsplAmt     [16+1]; /* 월매매손익금액   */
    char    BnsplAmt        [15+1]; /* 매매손익금액     */
    char    HldAmt          [15+1]; /* 보유금액         */
    char    EvalAmt         [15+1]; /* 평가금액         */
    char    EvalPnlAmt      [15+1]; /* 평가손익금액     */
    char    EvalErnrat      [10+2]; /* 평가수익률       */
    char    BuyLmtAmt       [15+1]; /* 매수한도금액     */
    char    PnlSumAmt       [15+1]; /* 손익합계금액     */
    char    BalPnlSt        [5   ]; /*                  */
}   SSESQ119_OUT, * lpSSESQ119_OUT;
#define SZ_SSESQ119_OUT				sizeof(SSESQ119_OUT)

typedef struct	
{
    char    IsuNo           [12  ]; /* 종목번호         */
    char    IsuNm           [40  ]; /* 종목명           */
    char    PrdayHldQty     [15+1]; /* 전일보유수량     */
    char    CrdayHldQty     [15+1]; /* 금일보유수량     */
    char    CrdayBuyExecQty [15+1]; /* 금일매수체결수량 */
    char    CrdaySellExecQty[15+1]; /* 금일매도체결수량 */
    char    OrdAbleQty      [15+1]; /* 주문가능수량     */
    char    BookUprc        [13+2]; /* 장부단가         */
    char    Curprc          [11+2]; /* 현재가           */
    char    SellUprc        [13+2]; /* 매도단가         */
    char    BuyUprc         [13+2]; /* 매수단가         */
    char    BnsplAmt        [15+1]; /* 매매손익금액     */
    char    EvalErnrat      [10+2]; /* 평가수익률       */
    char    EvalPnlAmt      [15+1]; /* 평가손익금액     */
    char    CrdayHldRat     [10+2]; /* 금일보유비율     */
    char    OpRat           [9 +1]; /* 운용비율         */
    char    EvalAmt         [15+1]; /* 평가금액         */
    char    BookAmt         [15+1]; /* 장부금액         */
}   SSESQ119_OUT_OCCR1, * lpSSESQ119_OUT_OCCR1;
#define SZ_SSESQ119_OUT_OCCR1				sizeof(SSESQ119_OUT_OCCR1)

typedef struct	
{
    char      FundNm        [40+1];
    double    OpLmtAmt      ;
    double    BfDtBnsPnlamt ;
    double    BfDtEvalPnlAmt;
    double    PrdayCmpMktAmt;
    double    HldQty        ;
    double    DtBnsplAmt    ;
    double    MthBnsplAmt   ;
    double    BnsplAmt      ;
    double    HldAmt        ;
    double    EvalAmt       ;
    double    EvalPnlAmt    ;
    double    EvalErnrat    ;
    double    BuyLmtAmt     ;
    double    PnlSumAmt     ;
    double    BalPnlSt      ;
}   SSESQ119_OUT_DB;
#define SZ_SSESQ119_OUT_DB sizeof(SSESQ119_OUT_DB)

typedef struct	
{
    char    IsuNo           [12 +1]; /* 종목번호         */
    char    IsuNm           [40 +1]; /* 종목명           */
    double    PrdayHldQty     ; /* 전일보유수량     */
    double    CrdayHldQty     ; /* 금일보유수량     */
    double    CrdayBuyExecQty ; /* 금일매수체결수량 */
    double    CrdaySellExecQty; /* 금일매도체결수량 */
    double    OrdAbleQty      ; /* 주문가능수량     */
    double    BookUprc        ; /* 장부단가         */
    double    Curprc          ; /* 현재가           */
    double    SellUprc        ; /* 매도단가         */
    double    BuyUprc         ; /* 매수단가         */
    double    BnsplAmt        ; /* 매매손익금액     */
    double    EvalErnrat      ; /* 평가수익률       */
    double    EvalPnlAmt      ; /* 평가손익금액     */
    double    CrdayHldRat     ; /* 금일보유비율     */
    double    OpRat           ; /* 운용비율         */
    double    EvalAmt         ; /* 평가금액         */
    double    BookAmt         ; /* 장부금액         */
}   SSESQ119_OUT_OCCR1_DB;
#define SZ_SSESQ119_OUT_OCCR1_DB sizeof(SSESQ119_OUT_OCCR1_DB)


#endif
