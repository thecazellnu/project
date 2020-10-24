/*[
header:
	�ڽ��� Tr ���� ����
name:
	tradest.h
synopsis:
	���ȭ��
return:
	����
description:
	���ȭ��
remarks:
	12/04/12    dhkim   SONAT002F(GTS�� SONAT002�� ������, ���� ������ �����̸��� ���� GIS���� ����)
date:
	11/02/28
author:
	�赿ȯ
]*/

#ifndef _TRADE_ST_H_
#define _TRADE_ST_H_

///////////////////////////////////////////////////////////////
typedef struct
{
char In[5];
char InptTp[1];	//�Է±���              
char BaseDt[8];	//������                
char FundOpAcntNo[20];	//�ݵ�����¹�ȣ
char SetupSeqno[10];	//�����Ϸù�ȣ      
char MnyCnfTp[1];	//�ڱ�Ȯ�α���        
char MnyTp[1];	//�ڱݱ���                
char SbrwTp[1];	//��������              
char QryTp[1];	//��ȸ����
char DpartNo[3];	//�μ���ȣ

} SSEBQ649_IN,   * lpSSEBQ649_IN;
#define SZ_SSEBQ649_IN    sizeof(SSEBQ649_IN)

//////////////////////////////////////////////////////////////////
typedef struct
{
	char TotOut              [  5]; //
    char FundOpAcntNo        [ 20]; // �ݵ�����¹�ȣ X(20)
    char FundNm              [ 40]; // �ݵ�� X(40)
    char MnyCnfTpNm          [ 20]; // �ڱ�Ȯ�α��� X(20)
    char TpNm1               [ 40]; // ���и�1 X(40)
    char TpNm2               [ 40]; // ���и�2 X(40)
    char BuyAmt              [ 16]; // �ż��ݾ� S9(15)
    char SellAmt             [ 16]; // �ŵ��ݾ� S9(15)
    char CsgnBuyAmt          [ 16]; // ��Ź�ż��ݾ� S9(15)
    char CsgnSellAmt         [ 16]; // ��Ź�ŵ��ݾ� S9(15)
    char ThdayBndBuyAmt      [ 16]; // ����ä�Ǹż��ݾ� S9(15)
    char ThdayBndSellAmt     [ 16]; // ����ä�Ǹŵ��ݾ� S9(15)
    char Amt1                [ 16]; // �ݾ�1 S9(15)
    char Amt2                [ 16]; // �ݾ�2 S9(15)
    char BndBuyAmt           [ 16]; // ä�Ǹż��ݾ� S9(15)
    char BndSellAmt          [ 16]; // ä�Ǹŵ��ݾ� S9(15)
    char Out2                [  5]; //  
}SSEBQ649_OUT,   * lpSSEBQ649_OUT;
#define SZ_SSEBQ649_OUT  sizeof(SSEBQ649_OUT) 

typedef struct
{
	char DlngPrdtTp          [  1]; // ������ǰ���� X(1)
    char SetupSeqno          [ 10]; // �����Ϸù�ȣ S9(9)
    char MnyCnfTpNm          [ 20]; // �ڱ�Ȯ�α��� X(20)
    char MnySeqno            [ 10]; // �ڱ��Ϸù�ȣ S9(9)
    char MnyTpNm             [ 40]; // �ڱݱ��� X(40)
    char TrdTpNm             [ 20]; // �ŷ����� X(20)
    char AfirTpNm            [ 40]; // �������� X(40)
    char OppTrdAcntNo        [ 20]; // ���ŷ����¹�ȣ X(20)
    char AcntNm              [ 40]; // ���¸� X(40)
    char BnsAmt              [ 16]; // �Ÿűݾ� S9(15)
    char DpsNm               [ 50]; // ���ݸ� X(50)
    char MnySettIttNo        [ 20]; // �ڱݰ��������ȣ X(20)
    char BrnNm               [ 40]; // ������ X(40)
    char SettTpNm            [ 41]; // �������и� X(41)
    char SettDt              [  8]; // ������ X(8)
    char FundOpAcntNo        [ 20]; // �ݵ�����¹�ȣ X(20)
} SSEBQ649_Sub, * lpSSEBQ649_Sub;
#define SZ_SSEBQ649_Sub  sizeof(SSEBQ649_Sub)

typedef struct
{
    char MnySeqno            [ 10]; // �ڱ��Ϸù�ȣ S9(9)
    char MnyTpNm             [ 40]; // �ڱݱ��� X(40)
    char TrdTpNm             [ 20]; // �ŷ����� X(20)
    char AfirTpNm            [ 40]; // �������� X(40)
    char OppTrdAcntNo        [ 20]; // ���ŷ����¹�ȣ X(20)
    char AcntNm              [ 40]; // ���¸� X(40)
    char BnsAmt              [ 16]; // �Ÿűݾ� S9(15)
    char DpsNm               [ 50]; // ���ݸ� X(50)
    char MnySettIttNo        [ 20]; // �ڱݰ��������ȣ X(20)
    char BrnNm               [ 40]; // ������ X(40)
    char SettTpNm            [ 41]; // �������и� X(41)
    char SettDt              [  8]; // ������ X(8)
} SSEBQ649_Sub2, * lpSSEBQ649_Sub2;
#define SZ_SSEBQ649_Sub2  sizeof(SSEBQ649_Sub2)
///////////////////////////////////////////////////////////////
typedef struct
{
char In[5];
char TrxTp[1];//	ó������          
char BrnNo[3];//	������ȣ          
char BrnTp[1];//	��������          
char BaseDt[8];//	������            
char PdGrpCode[2];//	��ǰ���ڵ�    
char ClssGrpCode[3];//	�����ڻ��ڵ�

} SSLAQ728_IN,   * lpSSLAQ728_IN;
#define SZ_SSLAQ728_IN    sizeof(SSLAQ728_IN)

typedef struct
{
	char Out                 [  5]; //  
    char BrnNm               [ 40]; // ������ X(40)
    char Amt1                [ 16]; // �ݾ�1 S9(15)
    char Amt2                [ 16]; // �ݾ�2 S9(15)
    char Amt3                [ 16]; // �ݾ�3 S9(15)
    char CodeNm01            [ 40]; // �ڵ�� X(40)
    char CodeNm02            [ 40]; // �ڵ�� X(40)
    char CmsnAmt             [ 16]; // ������ S9(15)
    char OutList2            [  5]; // X(5) 
} SSLAQ728_OUT,   * lpSSLAQ728_OUT;
#define SZ_SSLAQ728_OUT  sizeof(SSLAQ728_OUT)

typedef struct
{
	char BrnNm               [ 40]; // ������ X(40)
    char FutsAdjstDfamt      [ 16]; // ������������ S9(15)
    char FutsThdayDfamt      [ 16]; // ������������ S9(15)
    char FutsUdamt           [ 16]; // ������������ S9(15)
    char OptSettDfamt        [ 16]; // �ɼǰ������� S9(15)
    char SettDfamtSum        [ 17]; // ���������� S9(16)
    char FxdratMbrfee        [ 16]; // ����ȸ�� S9(15)
    char AsFee               [ 16]; // ��ȸ�� S9(15)
    char ReprFund            [ 16]; // ����� S9(15)
} SSLAQ728_Sub, * lpSSLAQ728_Sub;
#define SZ_SSLAQ728_Sub  sizeof(SSLAQ728_Sub)

///////////////////////////////////////////////////////////////
typedef struct
{
char In[5];
char ActgBrnNo[3]; //	ȸ��������ȣ  
char BaseDt[8]; //	������          
char SrtAccCode[9]; //	���۰����ڵ�
char EndAccCode[9]; //	��������ڵ�
char ActgBaseTp[1]; //	ȸ����ر���
} SIAGQ115_IN,   * lpSIAGQ115_IN;
#define SZ_SIAGQ115_IN    sizeof(SIAGQ115_IN)

typedef struct
{
	char Out                 [  5]; //  
    char ActgBrnNm           [ 40]; // ȸ�������� X(40)
    char OutLst              [  5]; //  
} SIAGQ115_OUT,   * lpSIAGQ115_OUT;
#define SZ_SIAGQ115_OUT  sizeof(SIAGQ115_OUT)

typedef struct
{
    char AccCode             [  9]; // �����ڵ� X(9)
    char AccNm               [ 50]; // ������ X(50)
    char FncustNm            [ 50]; // �����ŷ�ó�� X(50)
    char DpsMgmtNo           [ 20]; // ���ݰ�����ȣ X(20)
    char AccBfbalAmt         [ 16]; // �������ܱݾ� S9(15)
    char MnyinAmt            [ 16]; // �Աݱݾ� S9(15)
    char MnyoutAmt           [ 16]; // ��ݱݾ� S9(15)
    char AccCrbalAmt         [ 16]; // �������ܱݾ� S9(15)
    char NmonPldgPrvdCnts2   [100]; // �����㺸��������2 X(100)
    char OwnPrdtCode         [ 20]; // ��ü��ǰ�ڵ� X(20)
    char OpenDt              [  8]; // ������ X(8)
    char DueDt               [  8]; // ������ X(8)
    char Intrat              [  7]; // ������ S9.9(4)
    char RcvblIntrstAmt      [ 16]; // �̼����ڱݾ� S9(15)
    char DueIntrstAmt        [ 16]; // �������ڱݾ� S9(15)
    char PassDays            [  6]; // ����ϼ� S9(5)  
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
    char FundNm              [ 40]; // �ݵ�� X(40)
    char DtCfTrd             [  5]; //  
} SSESQ102_OUT,   * lpSSESQ102_OUT;
#define SZ_SSESQ102_OUT  sizeof(SSESQ102_OUT)

typedef struct
{
    char TrdDt               [  8]; // �ŷ��� X(8)
    char TrdNo               [ 10]; // �ŷ���ȣ S9(9)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char IsuNm               [ 40]; // ����� X(40)
    char TrdPtnTpNm          [ 20]; // �ŷ��������� X(20)
    char SmryNm              [ 40]; // ����� X(40)
    char BnsTpNm             [ 10]; // �Ÿű��� X(10)
    char CancYnNm            [ 10]; // ��ҿ��θ� X(10)
    char BnsUprc             [ 20]; // �ŸŴܰ� S9(14).9(4)
    char BookUprc            [ 15]; // ��δܰ� S9(9).9(4)
    char BnsQty              [ 16]; // �Ÿż��� S9(15)
    char BnsAmt              [ 16]; // �Ÿűݾ� S9(15)
    char SecBfbalQty         [ 16]; // �����������ܼ��� S9(15)
    char SecCrbalQty         [ 16]; // �������Ǳ��ܼ��� S9(15)
    char BookAmtBfbalAmt     [ 16]; // ��α����ܱݾ� S9(15)
    char BookAmtCrbalAmt     [ 16]; // ��αݱ��ܱݾ� S9(15)
    char Trtax               [ 16]; // �ŷ��� S9(15)
    char Fstax               [ 16]; // ��Ư�� S9(15)
    char BnsplAmt            [ 16]; // �Ÿż��ͱݾ� S9(15)
    char YearAcmBnsplAmt     [ 16]; // �⴩���Ÿż��ͱݾ� S9(15)
    char LowAcntNo           [ 20]; // �������¹�ȣ X(20)
    char AcntNm              [ 40]; // ���¸� X(40)
    char SettCostAmt         [ 16]; // ��Ź�������ݾ� S9(15)
    char AsfeeAmt            [ 16]; // ��ȸ��ݾ� S9(15)
    char AscAdminBrfee       [ 16]; // ����ȸ��ݾ� S9(15)
    char SettStblAmt         [ 16]; // ��ȸ��ݾ� S9(15)
    char CmsnAmt1            [ 17]; // ������1 S9(11).9(4)
    char CmsnAmt2            [ 17]; // ������2 S9(11).9(4)
    char TrdAmt              [ 16]; // �ŷ��ݾ� S9(15)
    char Ictax               [ 16]; // �ҵ漼 S9(15)
} SSESQ102_Sub, * lpSSESQ102_Sub;
#define SZ_SSESQ102_Sub  sizeof(SSESQ102_Sub)

///////////////////////////////////////////////////////////////
typedef struct
{
char In[5];
char TrxTp[1];//	ó������
char BrnNo[3];//	������ȣ
char BrnTp[1];//	��������
char BaseDt[8];//	������
char PdGrpCode[2];//	��ǰ���ڵ�
char ClssGrpCode[3];//	�����ڻ��ڵ�
} SBPGQ776_IN,   * lpSBPGQ776_IN;
#define SZ_SBPGQ776_IN    sizeof(SBPGQ776_IN)

/*
    char OutList             [  5]; //  
    char BrnNm               [ 40]; // ������ X(40)
    char BrnNo               [  3]; // ������ȣ X(3)
    char FutsAdjstDfamt      [ 16]; // ������������ S9(15)
    char FutsThdayDfamt      [ 16]; // ������������ S9(15)
    char FutsUdamt           [ 16]; // ������������ S9(15)
    char FutsLastSettDfamt   [ 16]; // ���������������� S9(15)
    char OptSettDfamt        [ 16]; // �ɼǰ������� S9(15)
    char OptSellAmt          [ 16]; // �ɼǸŵ��ݾ� S9(15)
    char OptBuyAmt           [ 16]; // �ɼǸż��ݾ� S9(15)
    char OptXrcDfamt         [ 16]; // �ɼ�������� S9(15)
    char OptAsgnDfamt        [ 16]; // �ɼǹ������� S9(15)
    char SettDiffAmt         [ 17]; // �������� S9(16)
    char FutsFxdratMbrfee    [ 16]; // ��������ȸ�� S9(15)
    char OptFxdratMbrfee     [ 16]; // �ɼ�����ȸ�� S9(15)
    char FutsAsfee           [ 16]; // ������ȸ�� S9(15)
    char OptAsfee            [ 16]; // �ɼ���ȸ�� S9(15)
    char FutsDpstgOrgCmsnAmt [ 16]; // ������Ź�������� S9(15)
    char OptDpstgOrgCmsnAmt  [ 16]; // �ɼǿ�Ź�������� S9(15)
    char FutsReprAlrdyAmt    [ 16]; // ��������ݾ� S9(15)
    char OptReprAlrdyAmt     [ 16]; // �ɼǹ���ݾ� S9(15)
*/
typedef struct
{
	char Out                 [  5]; //
    char BrnNm               [ 40]; // ������ X(40)
    char Amt1                [ 16]; // �ݾ�1 S9(15)
    char Amt2                [ 16]; // �ݾ�2 S9(15)
    char Amt3                [ 16]; // �ݾ�3 S9(15)
    char CodeNm01            [ 40]; // �ڵ�� X(40)
    char CodeNm02            [ 40]; // �ڵ�� X(40)
    char CmsnAmt             [ 16]; // ������ S9(15)
    char OutList2            [  5]; // X(5)
} SBPGQ776_OUT,   * lpSBPGQ776_OUT;
#define SZ_SBPGQ776_OUT  sizeof(SBPGQ776_OUT)

typedef struct
{
	char BrnNm               [ 40]; // ������ X(40)
    char FutsAdjstDfamt      [ 16]; // ������������ S9(15)
    char FutsThdayDfamt      [ 16]; // ������������ S9(15)
    char FutsUdamt           [ 16]; // ������������ S9(15)
    char OptSettDfamt        [ 16]; // �ɼǰ������� S9(15)
    char SettDfamtSum        [ 17]; // ���������� S9(16)
    char FxdratMbrfee        [ 16]; // ����ȸ�� S9(15)
    char AsFee               [ 16]; // ��ȸ�� S9(15)
    char ReprFund            [ 16]; // ����� S9(15)	
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
    char ActgBrnNm           [ 40]; // ȸ�������� X(40)
    char AccNm               [ 50]; // ������ X(50)
    char BalAmt              [ 16]; // �ܰ�ݾ� S9(15)
    char Totamt1             [ 16]; // �հ�ݾ� S9(15)
    char Totamt2             [ 16]; // �հ�ݾ� S9(15)
    char Totamt3             [ 16]; // �հ�ݾ� S9(15)
    char Totamt4             [ 16]; // �հ�ݾ� S9(15)
    char TrxTpNm1            [ 20]; // ó�����и�1 X(20)
    char OutLst              [  5]; //  
} SIAGQ035_OUT,   * lpSIAGQ035_OUT;
#define SZ_SIAGQ035_OUT  sizeof(SIAGQ035_OUT)

typedef struct
{
	char SlpAprvDt           [  8]; // ��ǥ������ X(8)
    char SlpNo               [ 10]; // ��ǥ��ȣ S9(9)
    char SlpSeqno            [ 10]; // ��ǥ�Ϸù�ȣ S9(9)
    char SlpBrnNo            [  3]; // ��ǥ������ȣ X(3)
    char FirstSmryDtlCnts    [100]; // ��1����󼼳��� X(100)
    char CrdtCardNo          [ 20]; // �ſ�ī���ȣ X(20)
    char EmpNo               [  9]; // �����ȣ X(9)
    char DncTpNm             [ 10]; // ���뱸�и� X(10)
    char FncustNm            [ 50]; // �����ŷ�ó�� X(50)
    char DebitAmt            [ 16]; // �����ݾ� S9(15)
    char CrdsdAmt            [ 16]; // �뺯�ݾ� S9(15)
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
    char FundNm              [ 40]; // �ݵ�� X(40)
    char FundStkCfBal        [  5]; //  
} SSESQ008_OUT,   * lpSSESQ008_OUT;
#define SZ_SSESQ008_OUT  sizeof(SSESQ008_OUT)

typedef struct
{
    char IsuNo               [ 12]; // �����ȣ X(12)
    char IsuNm               [ 40]; // ����� X(40)
    char RegMktNm            [ 40]; // ��Ͻ���� X(40)
    char HldQty              [ 16]; // �������� S9(15)
    char BookAmt             [ 16]; // ��αݾ� S9(15)
    char BookUprc            [ 15]; // ��δܰ� S9(9).9(4)
    char BrwQty              [ 16]; // ���Լ��� S9(15)
    char BrwSellQty          [ 16]; // ���Ըŵ����� S9(15)
    char BrwSellAmt          [ 16]; // ���Ըŵ��ݾ� S9(15)
    char SellUprc            [ 15]; // �ŵ��ܰ� S9(9).9(4)
    char SbrwSellQty         [ 16]; // �����ŵ����� S9(15)
    char SbrwSellAmt         [ 16]; // �����ŵ��ݾ� S9(15)
    char BnsPrftAmt          [ 16]; // �Ÿ����ͱݾ� S9(15)
    char BnsLossAmt          [ 16]; // �ŸżսǱݾ� S9(15)
    char BnsplAmt            [ 16]; // �Ÿż��ͱݾ� S9(15)
    char EvalPnlAmt          [ 16]; // �򰡼��ͱݾ� S9(15)
    char AddPldgAbleQty      [ 16]; // �߰��㺸���ɼ��� S9(15)
} SSESQ008_Sub, * lpSSESQ008_Sub;
#define SZ_SSESQ008_Sub  sizeof(SSESQ008_Sub)


///////////////////////////////////////////////////////////////
// �ܸ�������ȸ
///////////////////////////////////////////////////////////////
typedef struct
{
	char In                  [  5]; //  
    char BrnNo               [  3]; // ������ȣ X(3)
    char QryTp               [  1]; // ��ȸ���� X(1)
    char QryCndi             [ 40]; // ��ȸ���� X(40)
    char FirmNo              [  3]; // �̿���ȣ X(3)
} SBPGQ253_IN,   * lpSBPGQ253_IN;
#define SZ_SBPGQ253_IN    sizeof(SBPGQ253_IN)

typedef struct
{
    char Out                 [  5]; //  
    char BrnNm               [ 40]; // ������ X(40)
    char TotTermCnt          [  6]; // �Ѵܸ��� S9(5)
    char BrnTermCnt          [  6]; // �����ܸ��� S9(5)
    char TotConnTermCnt      [  6]; // �����Ӵܸ��� S9(5)
    char BrnConnTermCnt      [  6]; // �������Ӵܸ��� S9(5)
    char List                [  5]; //  
} SBPGQ253_OUT, * lpSBPGQ253_OUT;
#define SZ_SBPGQ253_OUT  sizeof(SBPGQ253_OUT)

typedef struct
{
    char BrnNo               [  3]; // ������ȣ X(3)
    char BrnNm               [ 40]; // ������ X(40)
    char TermNo              [  3]; // �ܸ���ȣ X(3)
    char TermIp              [ 12]; // �ܸ�IP X(12)
    char IpStmntCode         [  2]; // IP�Ű��ڵ� X(2)
    char SrcIp               [ 12]; // IP�ּ� X(12)
    char UseAfirCode         [  2]; // �������ڵ� X(2)
    char ConnYn              [  1]; // ���ӿ��� X(1)
    char ConnUserId          [ 16]; // ���ӻ����ID X(16)
    char ConnUserNm          [ 40]; // ���ӻ���ڸ� X(40)
    char LoginDttm           [ 17]; // �α����Ͻ� X(17)
    char LogotDttm           [ 17]; // �α׾ƿ��Ͻ� X(17)
    char NmdUserId           [ 16]; // ���������ID X(16)
    char NmdUserNm           [ 40]; // ��������ڸ� X(40)
    char PrntBrnNo           [  3]; // ��������ȣ X(3)
    char LoginPrhbtYn        [  1]; // �α��α������� X(1)
    char TermPtnTp           [  1]; // �ܸ��������� X(1)
    char TermUsageTp         [  1]; // �ܸ��뵵���� X(1)
    char BrnChkYn            [  1]; // ����Ȯ�ο��� X(1)
    char PayAuthVal          [ 10]; // ������Ѱ� X(10)
    char MgrBrnNo            [  3]; // ����������ȣ X(3)
    char TermNm              [ 40]; // �ܸ��� X(40)
    char RegUserId           [ 16]; // ��ϻ����ID X(16)
	char RegDttm             [ 17]; // ����Ͻ� X(17)
    char ChgUserId           [ 16]; // ��������ID X(16)
    char ChgDttm             [ 17]; // �����Ͻ� X(17)
    char TermDescr           [100]; // �ܸ����� X(100)
    char MenuAuthCode        [  4]; // �޴������ڵ� X(4)
    char MenuAuthNm          [ 40]; // �޴����Ѹ� X(40)
    char EmpNo               [  9]; // �����ȣ X(9)
} SBPGQ253_Sub, * lpSBPGQ253_Sub;
#define SZ_SBPGQ253_Sub  sizeof(SBPGQ253_Sub)

/////////////////////////////////////////////////////////////////////////////
typedef struct _SIAGT195I_
{
	char In                  [  5]; //  
    char ActgBrnNo           [  3]; // ȸ��������ȣ X(3)
    char RslnDt              [  8]; // ������ X(8)
    char RslnSeqno           [ 10]; // ���Ǽ��Ϸù�ȣ S9(9)
    char TrxTp               [  1]; // ó������ X(1)
    char ActgBaseTp          [  1]; // ȸ����ر��� X(1)
    char AccCode             [  9]; // �����ڵ� X(9)
    char BdgtCode            [  9]; // �����ڵ� X(9)
    char CnfrDt              [  8]; // ǰ���� X(8)
    char EmpNo               [  9]; // �����ȣ X(9)
    char RslnAmt             [ 16]; // ���Ǽ��ݾ� S9(15)
    char HanglAmtNm          [ 50]; // �ѱ۱ݾ׸� X(50)
    char FcurrAmt            [ 17]; // ��ȭ�ݾ� S9(11).9(4)
    char CrcyCode            [  3]; // ��ȭ�ڵ� X(3)
    char GivTp               [  1]; // ���ޱ��� X(1)
    char GivAccCode          [  9]; // ���ް����ڵ� X(9)
    char ActgTrdPtnCode      [  6]; // ȸ��ŷ������ڵ� X(6)
    char SmryDtlCnts1        [100]; // ����󼼳���1 X(100)
    char SmryDtlCnts2        [100]; // ����󼼳���2 X(100)
    char SmryDtlCnts3        [100]; // ����󼼳���3 X(100)
    char SmryDtlCnts4        [100]; // ����󼼳���4 X(100)
    char SmryDtlCnts5        [100]; // ����󼼳���5 X(100)
    char FncustCode          [  7]; // �����ŷ�ó�ڵ� X(7)
    char EvdnTp              [  1]; // �������� X(1)
    char DpsMgmtNo           [ 20]; // ���ݰ�����ȣ X(20)
    char BncNo               [ 20]; // ������ǥ��ȣ X(20)
    char CrdtCardNo          [ 20]; // �ſ�ī���ȣ X(20)
    char MnyoutPreargDt      [  8]; // ��ݿ����� X(8)
    char GivPlcNm            [ 50]; // ����ó�� X(50)
    char DrftrNm             [ 40]; // ����ڸ� X(40)
    char ExpnsTp             [  1]; // ��񱸺� X(1)
    char AcptPsnNm           [ 40]; // �����ڸ� X(40)
    char GivPlcDpsMgmtNo     [ 20]; // ����ó���ݰ�����ȣ X(20)
    char MtrsfBrnNo          [  3]; // ��ü������ȣ X(3)
    char MtrsfAccCode        [  9]; // ��ü�����ڵ� X(9)
    char JrnAccCode          [  9]; // �а������ڵ� X(9)
    char ComeqpPtnCode       [  2]; // ������������ڵ� X(2)
} SIAGT195I_st,   * lpSIAGT195I_st;
#define SZ_SIAGT195I    sizeof(SIAGT195I_st)

typedef struct _SIAGT195O_
{
    char Out                 [  5]; //  
} SIAGT195O_st,   * lpSIAGT195O_st;
#define SZ_SIAGT195O    sizeof(SIAGT195O_st)

typedef struct _SIAGT195Sub_
{
    char ActgBrnNm           [ 40]; // ȸ�������� X(40)
    char DebitAccNm          [ 50]; // ���������� X(50)
    char BdgtNm              [ 50]; // ����� X(50)
    char EmpNm               [ 40]; // ����� X(40)
    char OppAccNm            [ 50]; // �������� X(50)
    char ActgTrdPtnNm        [ 50]; // ȸ��ŷ������� X(50)
    char FncustNm            [ 50]; // �����ŷ�ó�� X(50)
    char FmtnAmt             [ 16]; // ���ݾ� S9(15)
    char AsgnAmt             [ 16]; // �����ݾ� S9(15)
    char EnfcAmt             [ 16]; // ����ݾ� S9(15)
    char BalAmt              [ 16]; // �ܰ�ݾ� S9(15)
    char UserNm              [ 40]; // ����ڸ� X(40)
} SIAGT195Sub_st,   * lpSIAGT195Sub_st;
#define SZ_SIAGT195Sub    sizeof(SIAGT195Sub_st)

/////////////////////////////////////////////////////////////////////////////
typedef struct _SIAGR122I_
{
	char In                  [  5]; //  
    char SrtDt               [  8]; // ������ X(8)
    char EndDt               [  8]; // ������ X(8)
    char SrtAccCode          [  9]; // ���۰����ڵ� X(9)
    char EndAccCode          [  9]; // ��������ڵ� X(9)
    char SrtBrnNo            [  3]; // ����������ȣ X(3)
    char EndBrnNo            [  3]; // ����������ȣ X(3)
    char RptKind             [  1]; // �������� X(1)
    char BrnTp               [  1]; // �������� X(1)
} SIAGR122I_st,   * lpSIAGR122I_st;
#define SZ_SIAGR122I    sizeof(SIAGR122I_st)

typedef struct _SIAGR122O_
{
	char Body                [  5]; //
} SIAGR122O_st,   * lpSIAGR122O_st;
#define SZ_SIAGR122O    sizeof(SIAGR122O_st)


typedef struct _SIAGR122Sub_
{
    char BrnNo               [  3]; // ������ȣ X(3)
    char AccCode             [  9]; // �����ڵ� X(9)
    char AccNm               [ 50]; // ������ X(50)
    char ActgTrdPtnCode      [  6]; // ȸ��ŷ������ڵ� X(6)
    char FirstSmryCnts       [100]; // ��1���䳻�� X(100)
    char SecondSmryCnts      [100]; // ��2���䳻�� X(100)
    char AllocBrnNo          [  3]; // ���������ȣ X(3)
    char EmpNo               [  9]; // �����ȣ X(9)
    char AprvDt              [  8]; // ������ X(8)
    char SlpNo               [ 10]; // ��ǥ��ȣ S9(9)
    char SlpSeqno            [ 10]; // ��ǥ�Ϸù�ȣ S9(9)
    char PnlAllocBaseNm      [ 50]; // ���͹�б��ظ� X(50)
    char ErrorYn             [  1]; // �������� X(1)
    char SmryCnts            [100]; // ���䳻�� X(100)
    char AllocAmt            [ 16]; // ��бݾ� S9(15)
    char RslnDt              [  8]; // ������ X(8)
    char RslnSeqno           [ 10]; // ���Ǽ��Ϸù�ȣ S9(9)
    char TpNm1               [ 40]; // ���и�1 X(40)
} SIAGR122Sub_st,   * lpSIAGR122Sub_st;
#define SZ_SIAGR122Sub    sizeof(SIAGR122Sub_st)



///////////////////////////////////////////////////////////////
// ����б����
///////////////////////////////////////////////////////////////
typedef struct _SFABT004I_
{
    char In                  [  5]; //  
    char BdgtFmtnYear        [  4]; // ���������� X(4)
    char SrtBrnNo            [  3]; // ����������ȣ X(3)
    char SrtBdgtCode         [  9]; // ���ۿ����ڵ� X(9)
    char BrnNo               [  3]; // ������ȣ X(3)
    char BdgtCode            [  9]; // �����ڵ� X(9)
    char Amt                 [ 16]; // �ݾ� S9(15)
    char SmryCnts            [100]; // ���䳻�� X(100)
    char Amt1                [ 16]; // �ݾ�1 S9(15)
    char SmryCnts1           [100]; // ���䳻�� X(100)
    char Amt2                [ 16]; // �ݾ�2 S9(15)
    char SmryCnts2           [100]; // ���䳻��2 X(100)
    char Amt3                [ 16]; // �ݾ�3 S9(15)
    char SmryCnts3           [100]; // ���䳻�� X(100)
    char Amt4                [ 16]; // �ݾ�4 S9(15)
    char SmryCnts4           [100]; // ���䳻�� X(100)
    char Amt5                [ 16]; // �ݾ�5 S9(15)
} SFABT004I_st,   * lpSFABT004I_st;
#define SZ_SFABT004I    sizeof(SFABT004I_st)

typedef struct _SFABT004O_
{
    char Out                 [  5]; //  
    char BrnNm               [ 40]; // ������ X(40)
    char BdgtNm              [ 50]; // ����� X(50)
    char OutLst              [  5]; // X(5) 
} SFABT004O_st,   * lpSFABT004O_st;
#define SZ_SFABT004O    sizeof(SFABT004O_st)

typedef struct _SFABT004Sub_
{
    char BrnNo               [  3]; // ������ȣ X(3)
    char BrnNm               [ 40]; // ������ X(40)
    char BdgtCode            [  9]; // �����ڵ� X(9)
    char BdgtNm              [ 50]; // ����� X(50)
    char Amt                 [ 16]; // �ݾ� S9(15)
    char SmryCnts            [100]; // ���䳻�� X(100)
    char Amt1                [ 16]; // �ݾ�1 S9(15)
    char SmryCnts1           [100]; // ���䳻�� X(100)
    char Amt2                [ 16]; // �ݾ�2 S9(15)
    char SmryCnts2           [100]; // ���䳻��2 X(100)
    char Amt3                [ 16]; // �ݾ�3 S9(15)
    char SmryCnts3           [100]; // ���䳻�� X(100)
    char Amt4                [ 16]; // �ݾ�4 S9(15)
    char SmryCnts4           [100]; // ���䳻�� X(100)
    char Amt5                [ 16]; // �ݾ�5 S9(15)
} SFABT004Sub_st,   * lpSFABT004Sub_st;
#define SZ_SFABT004Sub    sizeof(SFABT004Sub_st)
///////////////////////////////////////////////////////////////

typedef struct _SACMQ550I_
{
    char	In	[5];	//	
    char	ClntNo	[20];	//	����ȣ
    char	TrxTp	[1];	//	ó������
    char	QryTp	[1];	//	��ȸ����
    char	BrnNo	[3];	//	������ȣ
    char	SrtDt	[8];	//	������
    char	EndDt	[8];	//	������
} SACMQ550I_st,   * lpSACMQ550I_st;
#define SZ_SACMQ550I    sizeof(SACMQ550I_st)

typedef struct _SACMQ550O_
{
    char	Out	[5];	//	
} SACMQ550O_st,   * lpSACMQ550O_st;
#define SZ_SACMQ550O    sizeof(SACMQ550O_st)

typedef struct _SACMQ550Sub_
{
	char    TrxDt		[8];	//  ó����
    char	TrxSeqno	[10];	//	ó���Ϸù�ȣ
    char	PrslRmnno	[13];	//	��û���ֹι�ȣ
    char	TrxTpNm1	[20];	//	ó�����и�1
    char	YnNm1	[10];	//	���θ�
    char	TrxResltMsg	[40];	//	ó������޼���
    char	RcptDt	[8];	//	������
    char	RcptTime	[9];	//	�����ð�
    char	PrslNm	[40];	//	��û�μ���
    char	PrslHpNo	[30];	//	��û���޴���ȭ��ȣ
    char	PrslEmail	[50];	//	��û���̸���
    char	HomeAddrChgYn	[1];	//	�����ּҺ��濩��
    char	HomePostNo	[6];	//	���ÿ����ȣ
    char	HomeAbdngAddr	[100];	//	���õ��̻��ּ�
    char	HomeBlwdngAddr2	[100];	//	���õ������ּ�2
    char	WkplcAddrChgYn	[1];	//	�����ּҺ��濩��
    char	WkplcPostNo	[6];	//	��������ȣ
    char	WkplcAbdngAddr	[100];	//	���嵿�̻��ּ�
    char	WkplcBlwdngAddr	[100];	//	���嵿�����ּ�
    char	SndIttNm	[40];	//	�۽ű����
    char	SndIttBrnNm	[40];	//	�۽�������
    char	TrxBrnNm	[40];	//	ó��������
    char	TrxDttm	[17];	//	ó���Ͻ�
    char	TrxUserId	[16];	//	ó�������ID
    char	TrxTermNo	[3];	//	ó���ܸ���ȣ
    char	ClntNo	[20];	//	����ȣ
} SACMQ550Sub_st,   * lpSACMQ550Sub_st;
#define SZ_SACMQ550Sub    sizeof(SACMQ550Sub_st)

//////////////////////////////////////////////////////////////////
typedef struct _SACMQ217I_
{
    char    In  [5];    //
    char    Accno  [20];   //  ����ȣ
    char    Pwd   [8];    //  ó������
} SACMQ217I_st,   * lpSACMQ217I_st;
#define SZ_SACMQ217I    sizeof(SACMQ217I_st)

typedef struct _SACMQ217O_
{
    char    Out [5];    //
} SACMQ217O_st,   * lpSACMQ217O_st;
#define SZ_SACMQ217O    sizeof(SACMQ217O_st)

typedef struct _SACMQ217Sub_
{
    char PostNo              [  6]; // �����ȣ X(6)
    char Addr                [100]; // �ּ� X(100)
    char AbdngAddr           [100]; // ���̻��ּ� X(100)
    char BlwdngAddr          [100]; // �������ּ� X(100)
    char TelRgno             [  4]; // ��ȭ������ȣ X(4)
    char TelExno             [  4]; // ��ȭ����ȣ X(4)
    char TelSeqno            [  4]; // ��ȭ�Ϸù�ȣ X(4)
    char FaxRgno             [  4]; // �ѽ�������ȣ X(4)
    char FaxExno             [  4]; // �ѽ�����ȣ X(4)
    char FaxSeqno            [  4]; // �ѽ��Ϸù�ȣ X(4)
    char Out2                [  5]; // X(5) 
    char PostNo1              [  6]; // �����ȣ X(6)
    char Addr1                [100]; // �ּ� X(100)
    char AbdngAddr1           [100]; // ���̻��ּ� X(100)
    char BlwdngAddr1          [100]; // �������ּ� X(100)
    char TelRgno1             [  4]; // ��ȭ������ȣ X(4)
    char TelExno1             [  4]; // ��ȭ����ȣ X(4)
    char TelSeqno1            [  4]; // ��ȭ�Ϸù�ȣ X(4)
    char FaxRgno1             [  4]; // �ѽ�������ȣ X(4)
    char FaxExno1             [  4]; // �ѽ�����ȣ X(4)
    char FaxSeqno1            [  4]; // �ѽ��Ϸù�ȣ X(4)
    char WkplcNm             [ 40]; // ����� X(40)
    char Out3                [  5]; // X(5) 
    char PostNo2              [  6]; // �����ȣ X(6)
    char Addr2                [100]; // �ּ� X(100)
    char AbdngAddr2           [100]; // ���̻��ּ� X(100)
    char BlwdngAddr2          [100]; // �������ּ� X(100)
    char TelRgno2             [  4]; // ��ȭ������ȣ X(4)
    char TelExno2             [  4]; // ��ȭ����ȣ X(4)
    char TelSeqno2            [  4]; // ��ȭ�Ϸù�ȣ X(4)
    char FaxRgno2             [  4]; // �ѽ�������ȣ X(4)
    char FaxExno2             [  4]; // �ѽ�����ȣ X(4)
    char FaxSeqno2            [  4]; // �ѽ��Ϸù�ȣ X(4)
    char Out4                [  5]; // X(5) 
    char EmailAddr           [100]; // �̸����ּ� X(100)
    char MoveTelIdfyNo       [  4]; // �̵���ȭ�ĺ���ȣ X(4)
    char MoveTelExno         [  4]; // �̵���ȭ����ȣ X(4)
    char MoveTelSeqno        [  4]; // �̵���ȭ�Ϸù�ȣ X(4)
    char HpRgno              [  4]; // �޴���������ȣ X(4)
    char HpExno              [  4]; // �޴�������ȣ X(4)
    char HpSeqno             [  4]; // �޴����Ϸù�ȣ X(4)
    char Out5                [  5]; // X(5) 
    char AcntNm              [ 40]; // ���¸� X(40)
} SACMQ217Sub_st,   * lpSACMQ217Sub_st;
#define SZ_SACMQ217Sub    sizeof(SACMQ217Sub_st)
    
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
// ������Ǽ� ����  
///////////////////////////////////////////////////////////////
typedef struct _SIAGQ045I_
{
	char In                  [  5]; //  
    char ActgBrnNo           [  3]; // ȸ��������ȣ X(3)
    char AccCode             [  9]; // �����ڵ� X(9)
    char BdgtCode            [  9]; // �����ڵ� X(9)
    char SrtDt               [  8]; // ������ X(8)
    char EndDt               [  8]; // ������ X(8)
    char QryTp               [  1]; // ��ȸ���� X(1)
    char ActgBaseTp          [  1]; // ȸ����ر��� X(1)
} SIAGQ045I_st,   * lpSIAGQ045I_st;
#define SZ_SIAGQ045I    sizeof(SIAGQ045I_st)

typedef struct _SIAGQ045O_
{
    char Out                 [  5]; //  
    char ActgBrnNm           [ 40]; // ȸ�������� X(40)
    char AccNm               [ 50]; // ������ X(50)
    char BdgtNm              [ 50]; // ����� X(50)
    char SumAmt              [ 16]; // �հ�ݾ� S9(15)
    char OutLst              [  5]; //  
} SIAGQ045O_st,   * lpSIAGQ045O_st;
#define SZ_SIAGQ045O    sizeof(SIAGQ045O_st)

typedef struct _SIAGQ045Sub_
{
    char RslnDt              [  8]; // ������ X(8)
    char RslnSeqno           [ 10]; // ���Ǽ��Ϸù�ȣ S9(9)
    char RslnBrnNo           [  3]; // ���Ǽ�������ȣ X(3)
    char RslnBrnNm           [ 40]; // ���Ǽ������� X(40)
    char SmryDtlCnts1        [100]; // ����󼼳���1 X(100)
    char SmryDtlCnts2        [100]; // ����󼼳���2 X(100)
    char RslnAmt             [ 16]; // ���Ǽ��ݾ� S9(15)
    char CnfrDt              [  8]; // ǰ���� X(8)
    char AgrmDt              [  8]; // ������ X(8)
    char SlpAprvDt           [  8]; // ��ǥ������ X(8)
    char SlpNo               [ 10]; // ��ǥ��ȣ S9(9)
    char EmpNo               [  9]; // �����ȣ X(9)
    char TrdTpNm1            [ 20]; // �ŷ����и�1 X(20)
    char AccNm1              [ 50]; // ������1 X(50)
    char TpNm1               [ 40]; // ���и�1 X(40)
    char ActgBaseTp          [  1]; // ȸ����ر��� X(1)
} SIAGQ045Sub_st,   * lpSIAGQ045Sub_st;
#define SZ_SIAGQ045Sub    sizeof(SIAGQ045Sub_st)

///////////////////////////////////////////////////////////////
// �ڱ�ä�� ü����� �Ÿų���
///////////////////////////////////////////////////////////////
typedef struct _SSEBQ311I_
{
	char In                  [  5]; //  
    char QrySrtDt            [  8]; // ��ȸ������ X(8)
    char QryEndDt            [  8]; // ��ȸ������ X(8)
    char FundOpAcntNo        [ 20]; // �ݵ�����¹�ȣ X(20)
    char SettDays            [  6]; // �����ϼ� S9(5)
    char BnsTp               [  1]; // �Ÿű��� X(1)
    char CreBaseCode         [  2]; // ���������ڵ� X(2)
    char BnsCharTp           [  1]; // �Ÿż��ݱ��� X(1)
    char QryTp               [  1]; // ��ȸ���� X(1)
    char BrnNo               [  3]; // ������ȣ X(3)
} SSEBQ311I_st,   * lpSSEBQ311I_st;
#define SZ_SSEBQ311I    sizeof(SSEBQ311I_st)

typedef struct _SSEBQ311O_
{
	char In                  [  5]; //
    char QrySrtDt            [  8]; // ��ȸ������ X(8)
    char QryEndDt            [  8]; // ��ȸ������ X(8)
    char FundOpAcntNo        [ 20]; // �ݵ�����¹�ȣ X(20)
    char SettDays            [  6]; // �����ϼ� S9(5)
    char BnsTp               [  1]; // �Ÿű��� X(1)
    char CreBaseCode         [  2]; // ���������ڵ� X(2)
    char BnsCharTp           [  1]; // �Ÿż��ݱ��� X(1)
    char QryTp               [  1]; // ��ȸ���� X(1)
    char BrnNo               [  3]; // ������ȣ X(3)
    char Out                 [  5]; // X(5) 
    char FirmNm              [ 50]; // �̿��� X(50)
    char NowDt               [  8]; // ������ X(8)
    char FundOpAcntNo2        [ 20]; // �ݵ�����¹�ȣ X(20)
    char FundNm              [ 40]; // �ݵ�� X(40)
    char BnsTpNm             [ 10]; // �Ÿű��� X(10)
    char SettTpNm            [ 41]; // �������и� X(41)
    char CreBaseNm           [ 40]; // �������ظ� X(40)
	char Tot				 [  5];
	char Qty1                [ 16]; // ����1 S9(15)
    char Qty2                [ 16]; // ����2 S9(15)
    char SellBookAmt         [ 16]; // �ŵ���αݾ� S9(15)
    char BuyBookAmt          [ 16]; // �ż���αݾ� S9(15)
    char BuyAmt              [ 16]; // �ż��ݾ� S9(15)
    char SellAmt             [ 16]; // �ŵ��ݾ� S9(15)
    char PassIntrstAmt1      [ 16]; // �������1 S9(15)
    char PassIntrstAmt2      [ 16]; // �������2 S9(15)
    char PassIntrstAmt3      [ 16]; // �������3 S9(15)
    char PassIntrstAmt4      [ 16]; // �������4 S9(15)
    char RpPrcvAmt           [ 16]; // RP�����ݾ� S9(15)
    char AcmRpPrcvAmt        [ 16]; // ����RP�����ݾ� S9(15)
    char RpSellLossAmt       [ 16]; // RP�ŵ��սǱݾ� S9(15)
    char RpBuyAmt            [ 16]; // RP�ż��ݾ� S9(15)
    char BndIntrstAmt        [ 16]; // ä�����ڱݾ� S9(15)
    char AcmBndIntrstAmt     [ 16]; // ����ä�����ڱݾ� S9(15)
    char RcvblBndIntrstAmt   [ 16]; // �̼�ä�����ڱݾ� S9(15)
    char AcmRcvblIntrstAmt   [ 16]; // �����̼����ڱݾ� S9(15)
    char PrepayCorpTax       [ 16]; // ���޹��μ� S9(15)
    char AcmPrepayCorpTax    [ 16]; // �������޹��μ� S9(15)
    char Corptax1            [ 16]; // ���μ� S9(15)
    char Corptax2            [ 16]; // ���μ� S9(15)
    char Taxwtd              [ 16]; // ���������� S9(15)
    char AcmTaxwtd           [ 16]; // �������������� S9(15)
    char RfundLossAmt        [ 16]; // ��ȯ�սǱݾ� S9(15)
    char AcmRfundLossAmt     [ 16]; // ������ȯ�սǱݾ� S9(15)
    char RfundPrftAmt        [ 16]; // ��ȯ���ͱݾ� S9(15)
    char AcmRfundPrftAmt     [ 16]; // ������ȯ���ͱݾ� S9(15)
    char SbrwAmt             [ 16]; // �����ݾ� S9(15)
    char PassIntrstAmt5      [ 16]; // �������5 S9(15)
    char TotIntrstAmt        [ 16]; // �����ڱݾ� S9(15)
    char IntrstAmt           [ 16]; // ���ڱݾ� S9(15)
    char IntrstAmt2          [ 16]; // ���ڱݾ�2 S9(15)
    char Ihtax1              [ 16]; // �ֹμ� S9(15)
    char Ihtax2              [ 16]; // �ֹμ� S9(15)
	char Out2				 [  5];

} SSEBQ311O_st,   * lpSSEBQ311O_st;
#define SZ_SSEBQ311O    sizeof(SSEBQ311O_st)

typedef struct _SSEBQ311Sub1_
{
    char Qty1                [ 16]; // ����1 S9(15)
    char Qty2                [ 16]; // ����2 S9(15)
    char SellBookAmt         [ 16]; // �ŵ���αݾ� S9(15)
    char BuyBookAmt          [ 16]; // �ż���αݾ� S9(15)
    char BuyAmt              [ 16]; // �ż��ݾ� S9(15)
    char SellAmt             [ 16]; // �ŵ��ݾ� S9(15)
    char PassIntrstAmt1      [ 16]; // �������1 S9(15)
    char PassIntrstAmt2      [ 16]; // �������2 S9(15)
    char PassIntrstAmt3      [ 16]; // �������3 S9(15)
    char PassIntrstAmt4      [ 16]; // �������4 S9(15)
    char RpPrcvAmt           [ 16]; // RP�����ݾ� S9(15)
    char AcmRpPrcvAmt        [ 16]; // ����RP�����ݾ� S9(15)
    char RpSellLossAmt       [ 16]; // RP�ŵ��սǱݾ� S9(15)
    char RpBuyAmt            [ 16]; // RP�ż��ݾ� S9(15)
    char BndIntrstAmt        [ 16]; // ä�����ڱݾ� S9(15)
    char AcmBndIntrstAmt     [ 16]; // ����ä�����ڱݾ� S9(15)
    char RcvblBndIntrstAmt   [ 16]; // �̼�ä�����ڱݾ� S9(15)
    char AcmRcvblIntrstAmt   [ 16]; // �����̼����ڱݾ� S9(15)
    char PrepayCorpTax       [ 16]; // ���޹��μ� S9(15)
    char AcmPrepayCorpTax    [ 16]; // �������޹��μ� S9(15)
    char Corptax1            [ 16]; // ���μ� S9(15)
    char Corptax2            [ 16]; // ���μ� S9(15)
    char Taxwtd              [ 16]; // ���������� S9(15)
    char AcmTaxwtd           [ 16]; // �������������� S9(15)
    char RfundLossAmt        [ 16]; // ��ȯ�սǱݾ� S9(15)
    char AcmRfundLossAmt     [ 16]; // ������ȯ�սǱݾ� S9(15)
    char RfundPrftAmt        [ 16]; // ��ȯ���ͱݾ� S9(15)
    char AcmRfundPrftAmt     [ 16]; // ������ȯ���ͱݾ� S9(15)
    char SbrwAmt             [ 16]; // �����ݾ� S9(15)
    char PassIntrstAmt5      [ 16]; // �������5 S9(15)
    char TotIntrstAmt        [ 16]; // �����ڱݾ� S9(15)
    char IntrstAmt           [ 16]; // ���ڱݾ� S9(15)
    char IntrstAmt2          [ 16]; // ���ڱݾ�2 S9(15)
    char Ihtax1              [ 16]; // �ֹμ� S9(15)
    char Ihtax2              [ 16]; // �ֹμ� S9(15)
} SSEBQ311Sub1_st,   * lpSSEBQ311Sub1_st;
#define SZ_SSEBQ311Sub1    sizeof(SSEBQ311Sub1_st)


typedef struct _SSEBQ311Sub2_
{
    char TrdDt               [  8]; // �ŷ��� X(8)
    char SmryNm              [ 40]; // ����� X(40)
    char BnsTpNm             [ 10]; // �Ÿű��� X(10)
    char SettTpNm            [ 41]; // �������и� X(41)
    char TpNm1               [ 40]; // ���и�1 X(40)
    char IsuNm               [ 40]; // ����� X(40)
    char BndTpNm             [ 20]; // ä�Ǳ��� X(20)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char BnsQty              [ 16]; // �Ÿż��� S9(15)
    char BnsBndErnrat        [ 12]; // �Ÿ�ä�Ǽ��ͷ� S9(4).9(6)
    char ExecTime            [  9]; // ü��ð� X(9)
    char BookUprc            [ 15]; // ��δܰ� S9(9).9(4)
    char BnsUprc             [ 20]; // �ŸŴܰ� S9(14).9(4)
    char BookAmt             [ 16]; // ��αݾ� S9(15)
    char BnsAmt              [ 16]; // �Ÿűݾ� S9(15)
    char PassIntrstAmt       [ 16]; // ������ڱݾ� S9(15)
    char RpPassIntrstAmt     [ 16]; // RP������ڱݾ� S9(15)
    char RpPrcvAmt           [ 16]; // RP�����ݾ� S9(15)
    char RpSellLossAmt       [ 16]; // RP�ŵ��սǱݾ� S9(15)
    char BndIntrstAmt        [ 16]; // ä�����ڱݾ� S9(15)
    char RcvblIntrstAmt      [ 16]; // �̼����ڱݾ� S9(15)
    char PrepayCorpTax       [ 16]; // ���޹��μ� S9(15)
    char CorpTaxDps          [ 16]; // ���μ������� S9(15)
    char Taxwtd              [ 16]; // ���������� S9(15)
    char UprcTpNm            [ 20]; // �ܰ����� X(20)
    char RfundPrftAmt        [ 16]; // ��ȯ���ͱݾ� S9(15)
    char RfundLossAmt        [ 16]; // ��ȯ�սǱݾ� S9(15)
    char OppTrdAcntNm        [ 40]; // ���ŷ����¸� X(40)
    char CmsnAmt             [ 16]; // ������ S9(15)
    char EvalUprc            [ 15]; // �򰡴ܰ� S9(9).9(4)
    char RemnDays            [  6]; // �����ϼ� S9(5)
    char EvalAmt             [ 16]; // �򰡱ݾ� S9(15)
    char SbrwAmt             [ 16]; // �����ݾ� S9(15)
    char PassIntrstAmt5      [ 16]; // �������5 S9(15)
    char TotIntrstAmt        [ 16]; // �����ڱݾ� S9(15)
    char BuyDt               [  8]; // �ż��� X(8)
    char BuyUprc             [ 15]; // �ż��ܰ� S9(9).9(4)
    char TaxchrIntrstAmt1    [ 16]; // �������ڱݾ�1 S9(15)
    char EvalErnrat          [ 12]; // �򰡼��ͷ� S9(4).9(6)
    char BnsCharTp           [  1]; // �Ÿż��ݱ��� X(1)
    char BnsCharTpNm         [ 20]; // �Ÿż��ݱ��� X(20)
    char FundOpAcntNo        [ 20]; // �ݵ�����¹�ȣ X(20)
    char Ihtax               [ 16]; // �ֹμ� S9(15)
} SSEBQ311Sub2_st,   * lpSSEBQ311Sub2_st;
#define SZ_SSEBQ311Sub2    sizeof(SSEBQ311Sub2_st)



/////////////////////////////////////////////////////////////////
// ���� �������� 
/////////////////////////////////////////////////////////////////
typedef struct _SADNQ062I_
{
	char In                  [  5]; //  
    char BrnNo               [  3]; // ������ȣ X(3)
    char QrySrtDt            [  8]; // ��ȸ������ X(8)
    char QryEndDt            [  8]; // ��ȸ������ X(8)
    char QryTp               [  1]; // ��ȸ���� X(1)
    char MgempNo             [  9]; // ���������ȣ X(9)
    char AcptPsnNm           [ 40]; // �����ڸ� X(40)
    char OtptTp              [  1]; // ��±��� X(1)
    char SumAmt1             [ 16]; // �հ�ݾ�1 S9(15)
    char Tp                  [  1]; // ���� X(1)
    char EmpTp               [  1]; // ������� X(1)
} SADNQ062I_st,   * lpSADNQ062I_st;
#define SZ_SADNQ062I    sizeof(SADNQ062I_st)

typedef struct _SADNQ062M_
{
	char In                  [  5]; //
    char BrnNo               [  3]; // ������ȣ X(3)
    char QrySrtDt            [  8]; // ��ȸ������ X(8)
    char QryEndDt            [  8]; // ��ȸ������ X(8)
    char QryTp               [  1]; // ��ȸ���� X(1)
    char MgempNo             [  9]; // ���������ȣ X(9)
    char AcptPsnNm           [ 40]; // �����ڸ� X(40)
    char OtptTp              [  1]; // ��±��� X(1)
    char SumAmt1             [ 16]; // �հ�ݾ�1 S9(15)
    char Tp                  [  1]; // ���� X(1)
    char EmpTp               [  1]; // ������� X(1)
	char Out                 [  5]; //
    char BrnNm               [ 40]; // ������ X(40)
    char OutLst              [  5]; //

}   SADNQ062M_st,   * lpSADNQ062M_st;
#define SZ_SADNQ062M    sizeof(SADNQ062M_st)

typedef struct _SADNQ062O_
{
    char AcptPsnNm           [ 40]; // �����ڸ� X(40)
    char AcptPsnCoNm         [ 40]; // ������ȸ��� X(40)
    char AcptPsnSubAtgrp     [ 40]; // �����ںμ��� X(40)
    char EntmtPsnNm          [ 50]; // �����ڸ� X(50)
    char EntmtCustNm         [ 50]; // ����ŷ�ó�� X(50)
    char EntmtPsnSubAtgrp    [ 50]; // �����ںμ��� X(50)
    char CardEntmtAmt        [ 16]; // ī������ݾ� S9(15)
    char MnyEntmtAmt         [ 16]; // ��������ݾ� S9(15)
    char SumAmt              [ 16]; // �հ�ݾ� S9(15)
    char RslnDt              [  8]; // ������ X(8)
    char RslnNo              [ 10]; // ���Ǽ���ȣ S9(9)
    char PrvdRsn             [100]; // �������� X(100)
    char UseIndtpNm          [ 40]; // �������� X(40)
    char CrdtCardNo          [ 20]; // �ſ�ī���ȣ X(20)
    char OthprtyNm           [ 40]; // ����� X(40)
    char PrvdDt              [  8]; // ������ X(8)
    char Rmk                 [100]; // ��� X(100)
    char MobilNo             [ 16]; // �ڵ�����ȣ X(16)
    char AdtRealCnfYn        [  1]; // �����Ȯ�ο��� X(1)
    char AgrmPsnId           [ 16]; // ������ID X(16)
    char GongjikTp           [  2]; // �����ڱ��� X(2)
    char LmtAmt              [ 16]; // �ѵ��ݾ� S9(15)
    char YearAcmAmt          [ 16]; // �Ⱓ�ݾ� S9(15)
}   SADNQ062O_st,   * lpSADNQ062O_st;
#define SZ_SADNQ062O    sizeof(SADNQ062O_st)
/////////////////////////////////////////////////////////////////
// ���� ���� ����
/////////////////////////////////////////////////////////////////
typedef struct _SACMT205I_
{
	char In                  [  5]; //  
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char InptPwd             [  8]; // �Էº�й�ȣ X(8)
    char PdptnCode           [  2]; // ��ǰ�����ڵ� X(2)
    char AcntNm              [ 40]; // ���¸� X(40)
    char AcntHanglAlias      [ 40]; // �����ѱۺα�� X(40)
    char AcntEngAlias        [ 40]; // ���¿����α�� X(40)
    char WthldEntruYn        [  1]; // ��õ¡�����ӿ��� X(1)
    char LedgSdinfAddrPtnCode[  2]; // �����뺸�ּ������ڵ� X(2)
    char BnsSdinfAddrPtnCode [  2]; // �Ÿ��뺸�ּ������ڵ� X(2)
    char EtcPtmtrSdinfAddrPtnCode[  2]; // ��Ÿ�����뺸�ּ������ڵ� X(2)
    char AgrmReqstDt         [  8]; // ���ο�û�� X(8)
    char AgrmAddMsg          [100]; // �������߰��޽��� X(100)
    char AgrmUserNm          [ 40]; // ���λ���ڸ� X(40)
    char AgrmTrxId           [  8]; // ����ó��ID X(8)
    char LastAgrmUserId      [ 16]; // ����������ID X(16)
    char TrxObjTp            [  1]; // ó����󱸺� X(1)
    char csgn                [  5]; //  
    char UnuslAcntClssCode   [  2]; // Ư�̰��ºз��ڵ� X(2)
    char TrdSecPtnCode       [  2]; // �ŷ��������������ڵ� X(2)
    char MgnLevyPtnCode      [  2]; // ���ű�¡�������ڵ� X(2)
    char TrtaxLevyYn         [  1]; // �ŷ���¡������ X(1)
    char CsgnInvstrClssCode  [  4]; // ��Ź�����ںз��ڵ� X(4)
    char secSav              [  5]; //  
    char PayMthdCode         [  2]; // ���Թ���ڵ� X(2)
    char CvntTermMthQty      [  6]; // ���Ⱓ���� S9(5)
    char UnitPayAmt          [ 16]; // �������Աݾ� S9(15)
    char TrdSecPtnCode2      [  2]; // �ŷ��������������ڵ� X(2)
    char LhfrmJoinCode       [  2]; // �����������ڵ� X(2)
    char fno                 [  5]; //  
    char RegMktCode          [  2]; // ��Ͻ����ڵ� X(2)
    char CsgnSfaccCode       [  2]; // ��Ź�ڱ��ڵ� X(2)
    char FnoAcntAfmgnCode    [  2]; // �����ɼǰ��»������ű��ڵ� X(2)
    char KfxInvstrClssCode   [  3]; // ���彺�����ںз��ڵ� X(3)
    char KfxRglmbNo          [  3]; // ���彺��ȸ����ȣ X(3)
    char TrtaxLevyYn2        [  1]; // �ŷ���¡������ X(1)
    char ivtrst              [  5]; //  
    char IvtrstInvstrClssCode[  4]; // ���ڽ�Ź�����ںз��ڵ� X(4)
}   SACMT205I_st,   * lpSACMT205I_st;
#define SZ_SACMT205I    sizeof(SACMT205I_st)

typedef struct _SACMT205O_
{
    char Out                 [  5]; //  
    char PrdtDtlNm           [ 40]; // ��ǰ�󼼸� X(40)
    char IntaccNo            [ 20]; // ���հ��¹�ȣ X(20)
    char DueDt               [  8]; // ������ X(8)
    char CvntAmt             [ 16]; // ���ݾ� S9(15)
    char KfxAcntNo           [ 20]; // ���彺���¹�ȣ X(20)
    char AgrmMthdCode        [  2]; // ���ι���ڵ� X(2)
}   SACMT205O_st,   * lpSACMT205O_st;
#define SZ_SACMT205O    sizeof(SACMT205O_st)

/////////////////////////////////////////////////////////////////
// ���� ��й�ȣ ����
/////////////////////////////////////////////////////////////////
typedef struct _SACMQ226I_
{
    char    In                  [ 5];   // ���ڵ尹��
    char    AcntNo              [20];   // ���¹�ȣ
    char    AcntClssTp          [ 1];   // ���°�������
    char    InptPwd             [ 8];   // �Էº�й�ȣ
}   SACMQ226I_st,   * lpSACMQ226I_st;
#define SZ_SACMQ226I    sizeof(SACMQ226I_st)

typedef struct _SACMQ226O_
{
    char    In                  [ 5];   // ���ڵ尹��
    char    AcntNo              [20];   // ���¹�ȣ
    char    AcntClssTp          [ 1];   // ���°�������
    char    InptPwd             [ 8];   // �Էº�й�ȣ

    char    Out                 [ 5];   // ���ڵ尹��
    char    AcntNm              [40];   // ���¸�
    char    AvalYn              [ 1];   // ��ȿ����
    char    ClntNo              [20];   // ����ȣ
    char    AppCnt              [ 6];   // ����Ƚ��
    char    PwdContErrcnt       [10];   // ��й�ȣ���ӿ���Ƚ��
}   SACMQ226O_st,   * lpSACMQ226O_st;
#define SZ_SACMQ226O    sizeof(SACMQ226O_st)

/***********************************************************************
* �ֹ����ɱݾ׻�
 ***********************************************************************/
typedef struct
{
	char In                  [  5]; // X(5) 
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char Pwd                 [  8]; // ��й�ȣ X(8)
} SONAQ225_IN, * lpSONAQ225_IN;
#define SZ_SONAQ225_IN  sizeof(SONAQ225_IN)

typedef struct
{
	char Out                 [  5]; // X(5) 
    char AcntNm              [ 40]; // ���¸� X(40)
    char MnyMgnRat           [  7]; // �������űݷ� S9.9(4)
    char SubstMgnRat         [ 11]; // ������űݷ� S9.9(8)
    char MgnLevyPtnCode      [  2]; // ���ű�¡�������ڵ� X(2)
    char MgnLevyPtnNm        [ 40]; // ���ű�¡�������� X(40)
    char SellTrdStopYn       [  1]; // �ŵ��ŷ��������� X(1)
    char BuyTrdStopYn        [  1]; // �ż��ŷ��������� X(1)
    char CtinfoPrvdAgrmYn    [  1]; // �ſ������������ǿ��� X(1)
    char RcsecCnt            [ 10]; // �̼�����Ƚ�� S9(9)
    char Dps                 [ 16]; // ������ S9(15)
    char SubstAmt            [ 16]; // ���ݾ� S9(15)
    char MnyMgn              [ 16]; // �������űݾ� S9(15)
    char SubstMgn            [ 16]; // ������űݾ� S9(15)
    char OrdCms              [ 16]; // �ֹ������� S9(15)
    char MnyOrdAbleAmt       [ 16]; // �����ֹ����ɱݾ� S9(15)
    char SubstOrdAbleAmt     [ 16]; // ����ֹ����ɱݾ� S9(15)
    char CrdtPldgMnyRuseAmt  [ 16]; // �ſ�㺸��������ݾ� S9(15)
    char UnercBuyOrdAmt      [ 16]; // ��ü��ż��ֹ��ݾ� S9(15)
    char SellSubstOfstAmt    [ 16]; // �ŵ���������ݾ� S9(15)
    char SellAdjstAmt        [ 16]; // �ŵ�����ݾ� S9(15)
    char BuyAdjstAmt         [ 16]; // �ż�����ݾ� S9(15)
    char D2ordAbleAmt        [ 16]; // D2�ֹ����ɱݾ� S9(15)
    char CrdayCrdtPldgMny    [ 16]; // ���Ͻſ�㺸���� S9(15)
    char PrdayCrdtPldgMny    [ 16]; // ���Ͻſ�㺸���� S9(15)
    char PldgSubstAmt        [ 16]; // �㺸���ݾ� S9(15)
    char MnyRuseObjAmt       [ 16]; // ����������ݾ� S9(15)
    char SubstRuseObjAmt     [ 16]; // ���������ݾ� S9(15)
    char RcvblTotamt         [ 16]; // �̼��Ѿ� S9(15)
    char SpotSellTnovrDt     [  8]; // �ǹ��ŵ���ȯ�� X(8)
    char RuseSpotTnovrAmt    [ 16]; // ����ǹ���ȯ�ݾ� S9(15)
    char MnySpotTnovrAmt     [ 16]; // ���ݽǹ���ȯ�ݾ� S9(15)
    char SubstSpotTnovrAmt   [ 16]; // ���ǹ���ȯ�ݾ� S9(15)
    char MnyRuseUseAmt       [ 16]; // ����������ݾ� S9(15)
    char SubstRuseUseAmt     [ 16]; // ���������ݾ� S9(15)
    char PrdayBuyExecAmt     [ 16]; // ���ϸż�ü��ݾ� S9(15)
    char PrdaySellExecAmt    [ 16]; // ���ϸŵ�ü��ݾ� S9(15)
    char CrdayBuyExecAmt     [ 16]; // ���ϸż�ü��ݾ� S9(15)
    char CrdaySellExecAmt    [ 16]; // ���ϸŵ�ü��ݾ� S9(15)
    char SubstOrdAmt         [ 16]; // ����ֹ��ݾ� S9(15)
    char SeOrdAbleAmt        [ 16]; // �ŷ��ұݾ� S9(15)
    char KdqOrdAbleAmt       [ 16]; // �ڽ��ڱݾ� S9(15)
    char HtsOrdAbleAmt       [ 16]; // HTS�ֹ����ɱݾ� S9(15)
    char MgnRat100pctOrdAbleAmt[ 16]; // ���űݷ�100�ۼ�Ʈ�ֹ����ɱݾ� S9(15)
    char D1dps               [ 16]; // D1������ S9(15)
    char D2dps               [ 16]; // D2������ S9(15)
    char D1SubstAmt          [ 16]; // D1���� S9(15)
    char D2SubstAmt          [ 16]; // D2���� S9(15)
    char EvalAmt             [ 16]; // �򰡱ݾ� S9(15)
    char DpsastTotamt        [ 16]; // ��Ź�ڻ��Ѿ� S9(15)
    char Amt1                [ 16]; // �ݾ�1 S9(15)
    char Amt2                [ 16]; // �ݾ�2 S9(15)
    char Amt3                [ 16]; // �ݾ�3 S9(15)
    char Amt4                [ 16]; // �ݾ�4 S9(15)
    char Amt5                [ 16]; // �ݾ�5 S9(15)
    char Amt6                [ 16]; // �ݾ�6 S9(15)
    char CprcEvalAmt         [ 16]; // �����򰡱ݾ� S9(15)
    char Amt7                [ 16]; // �ݾ�7 S9(15)
    char Amt8                [ 16]; // �ݾ�8 S9(15)
    char Amt9                [ 16]; // �ݾ�9 S9(15)
    char Amt10               [ 16]; // �ݾ�10 S9(15)
    char Amt11               [ 16]; // �ݾ�11 S9(15)	
} SONAQ225_OUT, * lpSONAQ225_OUT;
#define SZ_SONAQ225_OUT  sizeof(SONAQ225_OUT)


/***********************************************************************
 * �������º� DT �ֹ�ü��
 ***********************************************************************/
typedef struct
{
	char In                  [  5]; //  
    char ExecYn              [  1]; // ü�Ῡ�� X(1)
    char BnsTp               [  1]; // �Ÿű��� X(1)
    char IsuTp               [  1]; // ���񱸺� X(1)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char InptPwd             [  8]; // �Էº�й�ȣ X(8)
    char QryTp               [  1]; // ��ȸ���� X(1)
} SONAQ051_IN, * lpSONAQ051_IN;
#define SZ_SONAQ051_IN  sizeof(SONAQ051_IN)

typedef struct
{
	char In                  [  5]; //
    char ExecYn              [  1]; // ü�Ῡ�� X(1)
    char BnsTp               [  1]; // �Ÿű��� X(1)
    char IsuTp               [  1]; // ���񱸺� X(1)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char InptPwd             [  8]; // �Էº�й�ȣ X(8)
    char QryTp               [  1]; // ��ȸ���� X(1)
    char Out                 [  5]; //  
    char SellExecQty         [ 16]; // �ŵ�ü����� S9(15)
    char BuyExecQty          [ 16]; // �ż�ü����� S9(15)
    char SellExecAmt         [ 16]; // �ŵ�ü��ݾ� S9(15)
    char BuyExecAmt          [ 16]; // �ż�ü��ݾ� S9(15)
    char ST_OUT              [  5]; //  
}	SONAQ051_OUT, * lpSONAQ051_OUT;
#define SZ_SONAQ051_OUT  sizeof(SONAQ051_OUT)

typedef struct
{
    char OrdNo               [ 10]; // �ֹ���ȣ S9(9)
    char OrgOrdNo            [ 10]; // ���ֹ���ȣ S9(9)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char OrdMktCode          [  2]; // �ֹ������ڵ� X(2)
    char BnsTp               [  1]; // �Ÿű��� X(1)
    char OrdPtnCode          [  2]; // �ֹ������ڵ� X(2)
    char OrdprcPtnCode       [  2]; // ȣ�������ڵ� X(2)
    char OrdQty              [ 16]; // �ֹ����� S9(15)
    char OrdPrc              [ 13]; // �ֹ��� S9(9).99
    char AllExecQty          [ 16]; // ��üü����� S9(15)
    char MrcAbleQty          [ 16]; // ������Ұ��ɼ��� S9(15)
    char AvrExecPrc          [ 13]; // ���ü�ᰡ S9(9).99
    char MrcQty              [ 16]; // ������Ҽ��� S9(15)
    char MgntrnCode          [  3]; // �ſ�ŷ��ڵ� X(3)
    char LoanDt              [  8]; // ������ X(8)
    char OrdTrxPtnCode       [  9]; // �ֹ�ó�������ڵ� S9(8)
    char TrxTime             [  9]; // ó���ð� X(9)
    char UserId              [ 16]; // �����ID X(16)
    char OrdCndiTp           [  1]; // �ֹ����Ǳ��� X(1)
    char CommdaCode          [  2]; // ��Ÿ�ü�ڵ� X(2)
    char MgempNo             [  9]; // ���������ȣ X(9)
    char ConnClssCode        [  2]; // ���Ӻз��ڵ� X(2)
    char MtiordSeqno         [ 10]; // �����ֹ��Ϸù�ȣ S9(9)
    char GrpNo               [ 20]; // �׷��ȣ X(20)
} SONAQ051_Sub, * lpSONAQ051_Sub;
#define SZ_SONAQ051_Sub  sizeof(SONAQ051_Sub)


/***********************************************************************
 * �������º� �ֹ�ü��
 ***********************************************************************/
typedef struct
{
    char In                  [  5]; //  
    char MgmtBrnNo           [  3]; // ����������ȣ X(3)
    char OrdMktCode          [  2]; // �ֹ������ڵ� X(2)
    char OrdNo               [ 10]; // �ֹ���ȣ S9(9)
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char OrdDt               [  8]; // �ֹ��� X(8)
    char OrdTrxPtnCode       [  9]; // �ֹ�ó�������ڵ� S9(8)
    char IsuNo               [ 12]; // �����ȣ X(12)
} SONAQ010_IN, * lpSONAQ010_IN;
#define SZ_SONAQ010_IN  sizeof(SONAQ010_IN)

typedef struct
{
	char In                  [  5]; //
    char MgmtBrnNo           [  3]; // ����������ȣ X(3)
    char OrdMktCode          [  2]; // �ֹ������ڵ� X(2)
    char OrdNo               [ 10]; // �ֹ���ȣ S9(9)
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char OrdDt               [  8]; // �ֹ��� X(8)
    char OrdTrxPtnCode       [  9]; // �ֹ�ó�������ڵ� S9(8)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char Out         		 [  5]; //  
} SONAQ010_OUT, * lpSONAQ010_OUT;
#define SZ_SONAQ010_OUT  sizeof(SONAQ010_OUT)

typedef struct
{
    char OrdNo               [ 10]; // �ֹ���ȣ S9(9)
    char OrgOrdNo            [ 10]; // ���ֹ���ȣ S9(9)
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char AcntNm              [ 40]; // ���¸� X(40)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char IsuNm               [ 40]; // ����� X(40)
    char OrdPtnNm            [ 40]; // �ֹ������� X(40)
    char OrdQty              [ 16]; // �ֹ����� S9(15)
    char OrdPrc              [ 13]; // �ֹ��� S9(9).99
    char OrdTrxPtnCode       [  9]; // �ֹ�ó�������ڵ� S9(8)
    char OrdTrxPtnNm         [ 50]; // �ֹ�ó�������� X(50)
    char CommdaCode          [  2]; // ��Ÿ�ü�ڵ� X(2)
    char CommdaNm            [ 40]; // ��Ÿ�ü�� X(40)
    char Rmk                 [100]; // ��� X(100)
    char BnsTpNm             [ 10]; // �Ÿű��� X(10)
    char MrcNm               [ 20]; // ������Ҹ� X(20)
    char RjtRsn              [100]; // �źλ��� X(100)
    char OrdprcPtnNm         [ 40]; // ȣ�������� X(40)
    char OrdDt               [  8]; // �ֹ��� X(8)
} SONAQ010_Sub, * lpSONAQ010_Sub;
#define SZ_SONAQ010_Sub  sizeof(SONAQ010_Sub)
/***********************************************************************
 * �������º� �ֹ�ü�� 
 ***********************************************************************/
typedef struct
{
	char In                  [  5]; //  
	char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char InptPwd             [  8]; // �Էº�й�ȣ X(8)
    char OrdMktCode          [  2]; // �ֹ������ڵ� X(2)
    char BnsTp               [  1]; // �Ÿű��� X(1)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char ExecYn              [  1]; // ü�Ῡ�� X(1)
    char OrdDt               [  8]; // �ֹ��� X(8)
    char SrtOrdNo2           [ 10]; // �����ֹ���ȣ2 S9(9)
    char BkseqTp             [  1]; // �������� X(1)
    char OrdPtnCode          [  2]; // �ֹ������ڵ� X(2)
} SONAQ001_IN, * lpSONAQ001_IN;
#define SZ_SONAQ001_IN  sizeof(SONAQ001_IN)

typedef struct
{
	char In                  [  5]; //
	char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char InptPwd             [  8]; // �Էº�й�ȣ X(8)
    char OrdMktCode          [  2]; // �ֹ������ڵ� X(2)
    char BnsTp               [  1]; // �Ÿű��� X(1)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char ExecYn              [  1]; // ü�Ῡ�� X(1)
    char OrdDt               [  8]; // �ֹ��� X(8)
    char SrtOrdNo2           [ 10]; // �����ֹ���ȣ2 S9(9)
    char BkseqTp             [  1]; // �������� X(1)
    char OrdPtnCode          [  2]; // �ֹ������ڵ� X(2)
    char OUT1                [  5]; // X(5)
    char SellExecAmt         [ 16]; // �ŵ�ü��ݾ� S9(15)
    char BuyExecAmt          [ 16]; // �ż�ü��ݾ� S9(15)
    char SellExecQty         [ 16]; // �ŵ�ü����� S9(15)
    char BuyExecQty          [ 16]; // �ż�ü����� S9(15)
    char SellOrdQty          [ 16]; // �ŵ��ֹ����� S9(15)
    char BuyOrdQty           [ 16]; // �ż��ֹ����� S9(15)
    char OUT                 [  5]; //
} SONAQ001_OUT, * lpSONAQ001_OUT;
#define SZ_SONAQ001_OUT  sizeof(SONAQ001_OUT)

typedef struct
{
    char OrdDt               [  8]; // �ֹ��� X(8)
    char MgmtBrnNo           [  3]; // ����������ȣ X(3)
    char OrdMktCode          [  2]; // �ֹ������ڵ� X(2)
    char OrdNo               [ 10]; // �ֹ���ȣ S9(9)
    char OrgOrdNo            [ 10]; // ���ֹ���ȣ S9(9)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char IsuNm               [ 40]; // ����� X(40)
    char BnsTp               [  1]; // �Ÿű��� X(1)
    char BnsTpNm             [ 10]; // �Ÿű��� X(10)
    char OrdPtnCode          [  2]; // �ֹ������ڵ� X(2)
    char OrdPtnNm            [ 40]; // �ֹ������� X(40)
    char OrdTrxPtnCode       [  9]; // �ֹ�ó�������ڵ� S9(8)
    char OrdTrxPtnNm         [ 50]; // �ֹ�ó�������� X(50)
    char MrcTp               [  1]; // ������ұ��� X(1)
    char MrcTpNm             [ 10]; // ������ұ��и� X(10)
    char MrcQty              [ 16]; // ������Ҽ��� S9(15)
    char MrcAbleQty          [ 16]; // ������Ұ��ɼ��� S9(15)
    char OrdQty              [ 16]; // �ֹ����� S9(15)
    char OrdPrc              [ 13]; // �ֹ��� S9(9).99
    char ExecQty             [ 16]; // ü����� S9(15)
    char ExecPrc             [ 13]; // ü�ᰡ S9(9).99
    char ExecTrxTime         [  9]; // ü��ó���ð� X(9)
    char LastExecTime        [  9]; // ����ü��ð� X(9)
    char OrdprcPtnCode       [  2]; // ȣ�������ڵ� X(2)
    char OrdprcPtnNm         [ 40]; // ȣ�������� X(40)
    char OrdCndiTp           [  1]; // �ֹ����Ǳ��� X(1)
    char AllExecQty          [ 16]; // ��üü����� S9(15)
    char CommdaCode          [  2]; // ��Ÿ�ü�ڵ� X(2)
    char CommdaNm            [ 40]; // ��Ÿ�ü�� X(40)
    char MbrNo               [  3]; // ȸ����ȣ X(3)
    char RsvOrdYn            [  1]; // �����ֹ����� X(1)
    char LoanDt              [  8]; // ������ X(8)
    char OrdTime             [  9]; // �ֹ��ð� X(9)
    char OpDrtnNo            [ 12]; // ������ù�ȣ X(12)
} SONAQ001_SUB, * lpSONAQ001_SUB;
#define SZ_SONAQ001_SUB  sizeof(SONAQ001_SUB)
	
/***********************************************************************
 * �������º� �̰����ܰ� 
 ***********************************************************************/
typedef struct
{
	char In                  [  5]; //  
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char Pwd                 [  8]; // ��й�ȣ X(8)
    char BalCreTp            [  1]; // �ܰ�������� X(1)
    char CmsnAmtAppTp        [  1]; // ���������뱸�� X(1)
    char D2balBaseQryTp      [  1]; // D2�ܰ������ȸ���� X(1)
} SONAQ102_IN, * lpSONAQ102_IN;
#define SZ_SONAQ102_IN  sizeof(SONAQ102_IN)

typedef struct
{
	char In                  [  5]; //
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char Pwd                 [  8]; // ��й�ȣ X(8)
    char BalCreTp            [  1]; // �ܰ�������� X(1)
    char CmsnAmtAppTp        [  1]; // ���������뱸�� X(1)
    char D2balBaseQryTp      [  1]; // D2�ܰ������ȸ���� X(1)
	char Out                 [  5]; //  
    char BrnNm               [ 40]; // ������ X(40)
    char AcntNm              [ 40]; // ���¸� X(40)
    char MnyOrdAbleAmt       [ 16]; // �����ֹ����ɱݾ� S9(15)
    char MnyoutAbleAmt       [ 16]; // ��ݰ��ɱݾ� S9(15)
    char SeOrdAbleAmt        [ 16]; // �ŷ��ұݾ� S9(15)
    char KdqOrdAbleAmt       [ 16]; // �ڽ��ڱݾ� S9(15)
    char HtsOrdAbleAmt       [ 16]; // HTS�ֹ����ɱݾ� S9(15)
    char MgnRat100pctOrdAbleAmt[ 16]; // ���űݷ�100�ۼ�Ʈ�ֹ����ɱݾ� S9(15)
    char EvalAmt             [ 16]; // �򰡱ݾ� S9(15)
    char PchsAmt             [ 16]; // ���Աݾ� S9(15)
    char RcvblAmt            [ 16]; // �̼��ݾ� S9(15)
    char MnyrclAmt           [ 16]; // ���ݹ̼��ݾ� S9(15)
    char PnlRat              [ 12]; // ���ͷ� S9(4).9(6)
    char InvstOrgAmt         [ 20]; // ���ڿ��� S9(19)
    char InvstPlAmt          [ 16]; // ���ڼ��ͱݾ� S9(15)
    char PldgMnyAmt          [ 16]; // �㺸���ݱݾ� S9(15)
    char PldgSubstAmt        [ 16]; // �㺸���ݾ� S9(15)
    char CrdtPldgOrdAmt      [ 16]; // �ſ�㺸�ֹ��ݾ� S9(15)
    char Dps                 [ 16]; // ������ S9(15)
    char D1dps               [ 16]; // D1������ S9(15)
    char D2Dps               [ 16]; // D2������ S9(15)
    char OrdDt               [  8]; // �ֹ��� X(8)
    char MnyMgn              [ 16]; // �������űݾ� S9(15)
    char SubstMgn            [ 16]; // ������űݾ� S9(15)
    char SubstAmt            [ 16]; // ���ݾ� S9(15)
    char PrdayBuyExecAmt     [ 16]; // ���ϸż�ü��ݾ� S9(15)
    char PrdaySellExecAmt    [ 16]; // ���ϸŵ�ü��ݾ� S9(15)
    char CrdayBuyExecAmt     [ 16]; // ���ϸż�ü��ݾ� S9(15)
    char CrdaySellExecAmt    [ 16]; // ���ϸŵ�ü��ݾ� S9(15)
    char EvalPnlSum          [ 15]; // �򰡼����հ� S9(14)
    char DpsastTotamt        [ 16]; // ��Ź�ڻ��Ѿ� S9(15)
    char Evrprc              [ 19]; // ����� S9(18)
    char RuseAmt             [ 16]; // ����ݾ� S9(15)
    char EtclndAmt           [ 16]; // ��Ÿ�뿩�ݾ� S9(15)
    char PrcAdjstAmt         [ 16]; // ������ݾ� S9(15)
    char D1CmsnAmt           [ 16]; // D1������ S9(15)
    char D2CmsnAmt           [ 16]; // D2������ S9(15)
    char D1EvrTax            [ 16]; // D1������ S9(15)
    char D2EvrTax            [ 16]; // D2������ S9(15)
    char D1SettPrergAmt      [ 16]; // D1���������ݾ� S9(15)
    char D2SettPrergAmt      [ 16]; // D2���������ݾ� S9(15)
    char PrdayKseMnyMgn      [ 16]; // ����KSE�������ű� S9(15)
    char PrdayKseSubstMgn    [ 16]; // ����KSE������ű� S9(15)
    char PrdayKseCrdtMnyMgn  [ 16]; // ����KSE�ſ��������ű� S9(15)
    char PrdayKseCrdtSubstMgn[ 16]; // ����KSE�ſ������ű� S9(15)
    char CrdayKseMnyMgn      [ 16]; // ����KSE�������ű� S9(15)
    char CrdayKseSubstMgn    [ 16]; // ����KSE������ű� S9(15)
    char CrdayKseCrdtMnyMgn  [ 16]; // ����KSE�ſ��������ű� S9(15)
    char CrdayKseCrdtSubstMgn[ 16]; // ����KSE�ſ������ű� S9(15)
    char PrdayKdqMnyMgn      [ 16]; // �����ڽ����������ű� S9(15)
    char PrdayKdqSubstMgn    [ 16]; // �����ڽ��ڴ�����ű� S9(15)
    char PrdayKdqCrdtMnyMgn  [ 16]; // �����ڽ��ڽſ��������ű� S9(15)
    char PrdayKdqCrdtSubstMgn[ 16]; // �����ڽ��ڽſ������ű� S9(15)
    char CrdayKdqMnyMgn      [ 16]; // �����ڽ����������ű� S9(15)
    char CrdayKdqSubstMgn    [ 16]; // �����ڽ��ڴ�����ű� S9(15)
    char CrdayKdqCrdtMnyMgn  [ 16]; // �����ڽ��ڽſ��������ű� S9(15)
    char CrdayKdqCrdtSubstMgn[ 16]; // �����ڽ��ڽſ������ű� S9(15)
    char PrdayFrbrdMnyMgn    [ 16]; // �������������������ű� S9(15)
    char PrdayFrbrdSubstMgn  [ 16]; // �����������������ű� S9(15)
    char CrdayFrbrdMnyMgn    [ 16]; // �������������������ű� S9(15)
    char CrdayFrbrdSubstMgn  [ 16]; // �����������������ű� S9(15)
    char PrdayCrbmkMnyMgn    [ 16]; // ��������������ű� S9(15)
    char PrdayCrbmkSubstMgn  [ 16]; // ������ܴ�����ű� S9(15)
    char CrdayCrbmkMnyMgn    [ 16]; // ��������������ű� S9(15)
    char CrdayCrbmkSubstMgn  [ 16]; // ������ܴ�����ű� S9(15)
    char DpspdgQty           [ 16]; // ��Ź�㺸���� S9(15)
    char D1SubstAmt          [ 16]; // D1���� S9(15)
    char D2SubstAmt          [ 16]; // D2���� S9(15)
    char D1MnyoutAbleAmt     [ 16]; // D1��ݰ��ɱݾ� S9(15)
    char D2MnyoutAbleAmt     [ 16]; // D2��ݰ��ɱݾ� S9(15)
    char AddPldgMny          [ 16]; // �߰��㺸���� S9(15)
    char AddCrdtPldgSubst    [ 16]; // �߰��ſ�㺸��� S9(15)
    char ST_OUT              [  5]; //  
} SONAQ102_OUT, * lpSONAQ102_OUT;
#define SZ_SONAQ102_OUT  sizeof(SONAQ102_OUT)

typedef struct
{
    char IsuNo               [ 12]; // �����ȣ X(12)
    char IsuNm               [ 40]; // ����� X(40)
    char SecBalPtnCode       [  2]; // ���������ܰ������ڵ� X(2)
    char SecBalPtnNm         [ 40]; // ���������ܰ������� X(40)
    char BalQty              [ 16]; // �ܰ���� S9(15)
    char BnsBaseBalQty       [ 16]; // �Ÿű����ܰ���� S9(15)  --
    char CrdayBuyExecQty     [ 16]; // ���ϸż�ü����� S9(15)
    char CrdaySellExecQty    [ 16]; // ���ϸŵ�ü����� S9(15)
    char CrdaySellExecPrc    [ 11]; // ���ϸŵ�ü�ᰡ S9(7).99
    char BuyPrc              [ 13]; // �ż��� S9(9).99
    char SellPnlAmt          [ 16]; // �ŵ����ͱݾ� S9(15)
    char PnlRat              [ 12]; // ���ͷ� S9(4).9(6)
    char NowPrc              [ 13]; // ���簡 S9(9).99
    char CrdtAmt             [ 16]; // �ſ�ݾ� S9(15)
    char DueDt               [  8]; // ������ X(8)
    char PrdaySellExecPrc    [ 13]; // ���ϸŵ�ü�ᰡ S9(9).99
    char PrdaySellQty        [ 16]; // ���ϸŵ����� S9(15)
    char PrdayBuyExecPrc     [ 13]; // ���ϸż�ü�ᰡ S9(9).99
    char PrdayBuyQty         [ 16]; // ���ϸż����� S9(15)
    char LoanDt              [  8]; // ������ X(8)
    char AvrUprc2            [ 15]; // ��մܰ�2 S9(11).99  -- 
    char SellAbleQty         [ 16]; // �ŵ����ɼ��� S9(15)
    char SellOrdQty          [ 16]; // �ŵ��ֹ����� S9(15)
    char CrdayBuyExecAmt     [ 16]; // ���ϸż�ü��ݾ� S9(15)
    char CrdaySellExecAmt    [ 16]; // ���ϸŵ�ü��ݾ� S9(15)
    char PrdayBuyExecAmt     [ 16]; // ���ϸż�ü��ݾ� S9(15)
    char PrdaySellExecAmt    [ 16]; // ���ϸŵ�ü��ݾ� S9(15)
    char EvalAmt             [ 16]; // �򰡱ݾ� S9(15)
    char EvalPnl             [ 16]; // �򰡼��� S9(15) ---
    char MnyOrdAbleAmt       [ 16]; // �����ֹ����ɱݾ� S9(15)
    char OrdAbleAmt          [ 16]; // �ֹ����ɱݾ� S9(15)
    char SellUnercQty        [ 16]; // �ŵ���ü����� S9(15)
    char SellUnsttQty        [ 16]; // �ŵ��̰������� S9(15)
    char BuyUnsttQty         [ 16]; // �ż��̰������� S9(15)
    char UnsttQty            [ 16]; // �̰������� S9(15)
    char PrdayCprc           [ 13]; // �������� S9(9).99
    char PchsAmt             [ 16]; // ���Աݾ� S9(15)  ---
    char RegMktCode          [  2]; // ��Ͻ����ڵ� X(2)
    char LoanDtlClssCode     [  2]; // ����󼼺з��ڵ� X(2)
    char DpspdgLoanQty       [ 16]; // ��Ź�㺸������� S9(15)
    char RopSetupVal         [ 18]; // ���Ǽ������� S9(17)
/*
    char ST_OUT1             [  5]; //  
    char SubstDsgnPtnCode    [  2]; // ������������ڵ� X(2)
    char SetupPtnNm          [ 40]; // ���������� X(40)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char IsuNm               [ 40]; // ����� X(40)
    char FutsAcntNo          [ 20]; // �������¹�ȣ X(20)
    char PdptnCode           [  2]; // ��ǰ�����ڵ� X(2)
    char PdptnNm             [ 40]; // ��ǰ������ X(40)
    char FnoSubstDsgnQty     [ 16]; // �����ɼǴ���������� S9(15)
    char FnoSubstSellOrdQty  [ 16]; // �����ɼǴ��ŵ��ֹ����� S9(15)
    char FnoSubstSellExecQty [ 16]; // �����ɼǴ��ŵ�ü����� S9(15)
    char FnoSubstSellExecAmt [ 16]; // �����ɼǴ��ŵ�ü��ݾ� S9(15)
    char CrdayKpiFtsubtSellExecAmt[ 16]; // �����ڽ��Ǽ������ŵ�ü��ݾ� S9(15)
    char CrdayKpiFtsubtSellExecQty[ 16]; // �����ڽ��Ǽ������ŵ�ü����� S9(15)
    char RegMktCode          [  2]; // ��Ͻ����ڵ� X(2)
*/
} SONAQ102_SUB, * lpSONAQ102_SUB;
#define SZ_SONAQ102_SUB  sizeof(SONAQ102_SUB)

/***********************************************************************
 * ���� ��Ÿ����
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
 * ���������� TR
 ***********************************************************************/
typedef struct
{
char	In	[	5	];	/*		*/
char	EmpNo	[	9	];	/*	�����ȣ	*/
char	TrxTp	[	1	];	/*	ó������	*/
char	EmpPwd	[	8	];	/*	�����й�ȣ	*/
char	EmpNm	[	40	];	/*	�����	*/
char	WrkBrnNo	[	3	];	/*	�ٹ�������ȣ	*/
char	JpstnCode	[	3	];	/*	�����ڵ�	*/
char	BrnNo	[	3	];	/*	������ȣ	*/
char	EmpTp	[	1	];	/*	�������	*/
char	SrlstCode	[	2	];	/*	ȣ���ڵ�	*/
char	JrnkCode	[	3	];	/*	�����ڵ�	*/
char	DtpstiCode	[	3	];	/*	��å�ڵ�	*/
char	RnkNo	[	7	];	/*	������ȣ	*/
char	IntraTelSeqno	[	4	];	/*	�系��ȭ�Ϸù�ȣ	*/
char	TelRgno	[	4	];	/*	��ȭ������ȣ	*/
char	TelExno	[	4	];	/*	��ȭ����ȣ	*/
char	TelSeqno	[	4	];	/*	��ȭ�Ϸù�ȣ	*/
char	HpRgno	[	4	];	/*	�޴���������ȣ	*/
char	HpExno	[	4	];	/*	�޴�������ȣ	*/
char	HpSeqno	[	4	];	/*	�޴����Ϸù�ȣ	*/
char	Rrno	[	13	];	/*	�ֹε�Ϲ�ȣ	*/
char	JncoDt	[	8	];	/*	�Ի���	*/
char	RetirDt	[	8	];	/*	������	*/
char	WrkGfordDt	[	8	];	/*	�ٹ��߷���	*/
char	EmailAddr	[	100	];	/*	�̸����ּ�	*/
char	PostNo	[	6	];	/*	�����ȣ	*/
char	Addr	[	100	];	/*	�ּ�	*/
char	EmpMgmtCode	[	3	];	/*	��������ڵ�	*/
char	EmpMgmtCode01	[	3	];	/*	��������ڵ�01	*/
char	EmpMgmtCode02	[	3	];	/*	��������ڵ�02	*/
char	EmpMgmtCode03	[	3	];	/*	��������ڵ�03	*/
char	InLcns01	[	5	];	/*		*/
char	Tp01	[	1	];	/*	����	*/
char	InLcns02	[	5	];	/*		*/
char	Tp02	[	1	];	/*	����	*/
char	InLcns03	[	5	];	/*		*/
char	Tp03	[	1	];	/*	����	*/
char	InLcns04	[	5	];	/*		*/
char	Tp04	[	1	];	/*	����	*/
char	InLcns05	[	5	];	/*		*/
char	Tp05	[	1	];	/*	����	*/
char	InLcns06	[	5	];	/*		*/
char	Tp06	[	1	];	/*	����	*/
char	InLcns07	[	5	];	/*		*/
char	Tp07	[	1	];	/*	����	*/
char	InLcns08	[	5	];	/*		*/
char	Tp08	[	1	];	/*	����	*/
char	InLcns09	[	5	];	/*		*/
char	Tp09	[	1	];	/*	����	*/
char	InLcns10	[	5	];	/*		*/
char	Tp10	[	1	];	/*	����	*/
char	InLcns11	[	5	];	/*		*/
char	Tp11	[	1	];	/*	����	*/
char	InLcns12	[	5	];	/*		*/
char	Tp12	[	1	];	/*	����	*/
char	InLcns13	[	5	];	/*		*/
char	Tp13	[	1	];	/*	����	*/
char	InLcns14	[	5	];	/*		*/
char	Tp14	[	1	];	/*	����	*/
char	InLcns15	[	5	];	/*		*/
char	Tp15	[	1	];	/*	����	*/
char	InLcns16	[	5	];	/*		*/
char	Tp16	[	1	];	/*	����	*/
} SSLDT028_IN, * lpSSLDT028_IN;
#define SZ_SSLDT028_IN              sizeof(SSLDT028_IN)

typedef struct
{
char	In	[	5	];	/*		*/
char	EmpNo	[	9	];	/*	�����ȣ	*/
char	TrxTp	[	1	];	/*	ó������	*/
char	EmpPwd	[	8	];	/*	�����й�ȣ	*/
char	EmpNm	[	40	];	/*	�����	*/
char	WrkBrnNo	[	3	];	/*	�ٹ�������ȣ	*/
char	JpstnCode	[	3	];	/*	�����ڵ�	*/
char	BrnNo	[	3	];	/*	������ȣ	*/
char	EmpTp	[	1	];	/*	�������	*/
char	SrlstCode	[	2	];	/*	ȣ���ڵ�	*/
char	JrnkCode	[	3	];	/*	�����ڵ�	*/
char	DtpstiCode	[	3	];	/*	��å�ڵ�	*/
char	RnkNo	[	7	];	/*	������ȣ	*/
char	IntraTelSeqno	[	4	];	/*	�系��ȭ�Ϸù�ȣ	*/
char	TelRgno	[	4	];	/*	��ȭ������ȣ	*/
char	TelExno	[	4	];	/*	��ȭ����ȣ	*/
char	TelSeqno	[	4	];	/*	��ȭ�Ϸù�ȣ	*/
char	HpRgno	[	4	];	/*	�޴���������ȣ	*/
char	HpExno	[	4	];	/*	�޴�������ȣ	*/
char	HpSeqno	[	4	];	/*	�޴����Ϸù�ȣ	*/
char	Rrno	[	13	];	/*	�ֹε�Ϲ�ȣ	*/
char	JncoDt	[	8	];	/*	�Ի���	*/
char	RetirDt	[	8	];	/*	������	*/
char	WrkGfordDt	[	8	];	/*	�ٹ��߷���	*/
char	EmailAddr	[	100	];	/*	�̸����ּ�	*/
char	PostNo	[	6	];	/*	�����ȣ	*/
char	Addr	[	100	];	/*	�ּ�	*/
char	EmpMgmtCode	[	3	];	/*	��������ڵ�	*/
char	EmpMgmtCode01	[	3	];	/*	��������ڵ�01	*/
char	EmpMgmtCode02	[	3	];	/*	��������ڵ�02	*/
char	EmpMgmtCode03	[	3	];	/*	��������ڵ�03	*/
char	InLcns01	[	5	];	/*		*/
char	Tp01	[	1	];	/*	����	*/
char	InLcns02	[	5	];	/*		*/
char	Tp02	[	1	];	/*	����	*/
char	InLcns03	[	5	];	/*		*/
char	Tp03	[	1	];	/*	����	*/
char	InLcns04	[	5	];	/*		*/
char	Tp04	[	1	];	/*	����	*/
char	InLcns05	[	5	];	/*		*/
char	Tp05	[	1	];	/*	����	*/
char	InLcns06	[	5	];	/*		*/
char	Tp06	[	1	];	/*	����	*/
char	InLcns07	[	5	];	/*		*/
char	Tp07	[	1	];	/*	����	*/
char	InLcns08	[	5	];	/*		*/
char	Tp08	[	1	];	/*	����	*/
char	InLcns09	[	5	];	/*		*/
char	Tp09	[	1	];	/*	����	*/
char	InLcns10	[	5	];	/*		*/
char	Tp10	[	1	];	/*	����	*/
char	InLcns11	[	5	];	/*		*/
char	Tp11	[	1	];	/*	����	*/
char	InLcns12	[	5	];	/*		*/
char	Tp12	[	1	];	/*	����	*/
char	InLcns13	[	5	];	/*		*/
char	Tp13	[	1	];	/*	����	*/
char	InLcns14	[	5	];	/*		*/
char	Tp14	[	1	];	/*	����	*/
char	InLcns15	[	5	];	/*		*/
char	Tp15	[	1	];	/*	����	*/
char	InLcns16	[	5	];	/*		*/
char	Tp16	[	1	];	/*	����	*/
char	OutWrkBrn	[	5	];	/*		*/
char	BrnNm	[	40	];	/*	������	*/
char	OutTeam	[	5	];	/*		*/
char	BrnNm_Out	[	40	];	/*	������	*/
char	OutHr	[	5	];	/*		*/
char	JpstnNm	[	40	];	/*	������	*/
char	JrnkNm	[	40	];	/*	����	*/
char	DtpstiNm	[	40	];	/*	��å��	*/
char	OutDate	[	5	];	/*		*/
char	RegDt	[	8	];	/*	�����	*/
char	ChgDt	[	8	];	/*	������	*/

}SSLDT028_OUT, * lpSSLDT028_OUT;
#define SZ_SSLDT028_OUT         sizeof(SSLDT028_OUT)


/***********************************************************************
 * ���TR 
 ***********************************************************************/
typedef struct
{
char	In		[	5	];	/*		*/
char	CardFirmNo		[	3	];	/*	ī��ȸ���ȣ	*/
char	CardAcntNo		[	20	];	/*	ī����¹�ȣ	*/
char	CardIssCnt		[	10	];	/*	ī��߱ްǼ�	*/
char	CardPtnCode		[	2	];	/*	ī�������ڵ�	*/
char	MgrCardFirmNo		[	3	];	/*	å����ī��ȸ���ȣ	*/
char	MgrCardAcntNo		[	20	];	/*	å����ī����¹�ȣ	*/
char	MgrCardPtnCode		[	2	];	/*	å����ī�������ڵ�	*/
char	MgrCardIssCnt		[	10	];	/*	å����ī��߱�Ƚ��	*/
char	AgrmReqstDt		[	8	];	/*	���ο�û��	*/
char	AgrmTrxId		[	8	];	/*	����ó��ID	*/
char	LastAgrmUserId		[	16	];	/*	����������ID	*/
char	AgrmUserNm		[	40	];	/*	���λ���ڸ�	*/
char	AgrmAddMsg		[	100	];	/*	�������߰��޽���	*/
char	ClntCardMsdata		[	23	];	/*	��ī��MSDATA	*/
char	AgrmCardMsdata		[	23	];	/*	����ī���ȣ	*/
char	TrxSlctBrnNo		[	3	];	/*	ó���Ƿ�������ȣ	*/
char	PdptnCode		[	2	];	/*	��ǰ�����ڵ�	*/
char	AcntNo		[	20	];	/*	���¹�ȣ	*/
char	MnyMgmtNo		[	20	];	/*	�ڱݰ�����ȣ	*/
char	Pwd		[	8	];	/*	��й�ȣ	*/
char	SmryNo		[	4	];	/*	�����ȣ	*/
char	MnyAmt		[	16	];	/*	���ݱݾ�	*/
char	ChckAmt		[	16	];	/*	��ǥ�ݾ�	*/
char	AskpsnNm		[	40	];	/*	�Ƿ��θ�	*/
char	IsuNo		[	12	];	/*	�����ȣ	*/
char	MnyoutTotamt		[	16	];	/*	����Ѿ�	*/

} SDPDT003_IN, * lpSDPDT003_IN;
#define SZ_SDPDT003_IN              sizeof(SDPDT003_IN)

typedef struct
{
char	In		[	5	];	/*		*/
char	CardFirmNo		[	3	];	/*	ī��ȸ���ȣ	*/
char	CardAcntNo		[	20	];	/*	ī����¹�ȣ	*/
char	CardIssCnt		[	10	];	/*	ī��߱ްǼ�	*/
char	CardPtnCode		[	2	];	/*	ī�������ڵ�	*/
char	MgrCardFirmNo		[	3	];	/*	å����ī��ȸ���ȣ	*/
char	MgrCardAcntNo		[	20	];	/*	å����ī����¹�ȣ	*/
char	MgrCardPtnCode		[	2	];	/*	å����ī�������ڵ�	*/
char	MgrCardIssCnt		[	10	];	/*	å����ī��߱�Ƚ��	*/
char	AgrmReqstDt		[	8	];	/*	���ο�û��	*/
char	AgrmTrxId		[	8	];	/*	����ó��ID	*/
char	LastAgrmUserId		[	16	];	/*	����������ID	*/
char	AgrmUserNm		[	40	];	/*	���λ���ڸ�	*/
char	AgrmAddMsg		[	100	];	/*	�������߰��޽���	*/
char	ClntCardMsdata		[	23	];	/*	��ī��MSDATA	*/
char	AgrmCardMsdata		[	23	];	/*	����ī���ȣ	*/
char	TrxSlctBrnNo		[	3	];	/*	ó���Ƿ�������ȣ	*/
char	PdptnCode		[	2	];	/*	��ǰ�����ڵ�	*/
char	AcntNo		[	20	];	/*	���¹�ȣ	*/
char	MnyMgmtNo		[	20	];	/*	�ڱݰ�����ȣ	*/
char	Pwd		[	8	];	/*	��й�ȣ	*/
char	SmryNo		[	4	];	/*	�����ȣ	*/
char	MnyAmt		[	16	];	/*	���ݱݾ�	*/
char	ChckAmt		[	16	];	/*	��ǥ�ݾ�	*/
char	AskpsnNm		[	40	];	/*	�Ƿ��θ�	*/
char	IsuNo		[	12	];	/*	�����ȣ	*/
char	MnyoutTotamt		[	16	];	/*	����Ѿ�	*/
char	Out		[	5	];	/*		*/
char	Inouno		[	10	];	/*	�ⳳ��ȣ	*/
char	RcvblOcrAmt		[	16	];	/*	�̼��߻��ݾ�	*/
char	DpsBfbalAmt		[	16	];	/*	���������ܱݾ�	*/
char	DpsCrbalAmt		[	16	];	/*	�����ݱ��ܱݾ�	*/
char	NSavBfbalAmt		[	16	];	/*	���������ܱݾ�	*/
char	NSavCrbalAmt		[	16	];	/*	��������ܱݾ�	*/
char	AcntNm		[	40	];	/*	���¸�	*/
char	SmryNm		[	40	];	/*	�����	*/
char	IsuNm		[	40	];	/*	�����	*/
char	AgrmTrxStep		[	1	];	/*	����ó���ܰ�	*/ 
char	AgrmMthdCode		[	2	];	/*	���ι���ڵ�	*/

}SDPDT003_OUT, * lpSDPDT003_OUT;
#define SZ_SDPDT003_OUT         sizeof(SDPDT003_OUT)

/***********************************************************************
 * �����ɼ� ��Ź�� ��TR 
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
 * ��ȭ���TR 
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
 * ��ȭ�Ա�TR
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
 * �ݵ� ���º����ݵ� ��ȸ
 ***********************************************************************/
typedef struct
{
char	In		[	5	];			
char	AcntNo	[	20	];	/*	���¹�ȣ	*/
char	Pwd		[	8	];	/*	��й�ȣ	*/
char	BaseDt	[	8	];	/*	������	*/
char	BnsTp	[	1	];	/*	�Ÿű���	*/
char	FundOrdTp	[	1	];	/*	�ݵ��ֹ�����	*/
char	SubAcntNo	[	20	];	/*	������¹�ȣ	*/
char	RpPtnCode	[	2	];	/*	ȯ�������ڵ�	*/
} SOFFQ141_IN, *lpSOFFQ141_IN;
#define SZ_SOFFQ141_IN sizeof(SOFFQ141_IN)

typedef struct
{
char	IndrcInvstCode	[	2	];	/*	���������ڵ�	*/
char	SubAcntNo2	[	20	];	/*	������¹�ȣ	*/
char	SubAcntSeqno	[	3	];	/*	�����Ϸù�ȣ	*/
char	IvstfndCode	[	12	];	/*	�����ݵ��ڵ�	*/
char	FundSeq	[	10	];	/*	�ݵ��Ϸù�ȣ	*/
char	HanglIvstfndNm	[	40	];	/*	�ѱ������ݵ��	*/
char	BasePrc	[	13	];	/*	���ذ�	*/
char	FundBalQty	[	20	];	/*	�ݵ��ܰ����	*/
char	OpnDt	[	8	];	/*	������	*/
char	EvalAmt	[	16	];	/*	�򰡱ݾ�	*/
char	AdjstAmt	[	16	];	/*	����ݾ�	*/
char	BuyPtnCode	[	2	];	/*	�ż������ڵ�	*/
char	PayMthdCode	[	2	];	/*	���Թ���ڵ�	*/
char	CvntTermMthQty	[	6	];	/*	���Ⱓ����	*/
char	CvntAmt	[	16	];	/*	���ݾ�	*/
char	RpPtnCode2	[	2	];	/*	ȯ�������ڵ�	*/
char	OpfirmCode	[	3	];	/*	�����ڵ�	*/
char	OpfirmNm	[	50	];	/*	�����	*/
char	IndrcInvstNm	[	40	];	/*	�������ڸ�	*/
char	PayMthdNm	[	40	];	/*	���Թ����	*/
char	Dps	[	16	];	/*	������	*/
char	MthPayDt	[	2	];	/*	��������	*/
char	IvtrstDtlCode	[	2	];	/*	���Ż��ڵ�	*/
char	IvtrstDtlNm	[	40	];	/*	���Ż󼼸�	*/
char	BuyPramt	[	16	];	/*	�ż�����	*/
char	BoaBasePrc	[	20	];	/*	��ǥ���ذ�	*/
char	BaseTimeBnsType	[	1	];	/*	���ؽð��Ÿű���	*/
char	TotRwrdRat	[	17	];	/*	�Ѻ�����	*/
char	MchndRwrdRat	[	17	];	/*	�Ǹź�����	*/
char	MchndCmsnAmtRat	[	11	];	/*	�Ǹż�������	*/
} SOFFQ141_OUT_SUB, *lpSOFFQ141_OUT_SUB;
#define SZ_SOFFQ141_OUT_SUB sizeof(SOFFQ141_OUT_SUB)

typedef struct
{
char	In		[	5	];			
char	AcntNo	[	20	];	/*	���¹�ȣ	*/
char	Pwd		[	8	];	/*	��й�ȣ	*/
char	BaseDt	[	8	];	/*	������	*/
char	BnsTp	[	1	];	/*	�Ÿű���	*/
char	FundOrdTp	[	1	];	/*	�ݵ��ֹ�����	*/
char	SubAcntNo	[	20	];	/*	������¹�ȣ	*/
char	RpPtnCode	[	2	];	/*	ȯ�������ڵ�	*/

char	Out			[	5	];	/* 		*/
char	AcntNm		[	40	];	/*	���¸�	*/

char	OutCnt		[	5	];	/*	��°Ǽ�	*/

SOFFQ141_OUT_SUB		SOFFQ141_OUTSUB [30]; 

} SOFFQ141_OUT, *lpSOFFQ141_OUT;
#define SZ_SOFFQ141_OUT sizeof(SOFFQ141_OUT)

/***********************************************************************
 * �ݵ� �ŵ�
 ***********************************************************************/
typedef struct
{
char	In	[	5	];			
char	AcntNo	[	20	];	/*	���¹�ȣ	*/
char	Pwd				[	8	];	/*	��й�ȣ	*/
char	RpPrslPtnTp		[	1	];	/*	ȯ�Ž�û��������	*/
char	SellOrdAmt		[	16	];	/*	�ŵ��ֹ��ݾ�	*/
char	IvstfndCode		[	12	];	/*	�����ݵ��ڵ�	*/
char	SpclMidwRpYn	[	1	];	/*	Ư���ߵ�ȯ�ſ���	*/
char	FndtdTrxTp		[	1	];	/*	�ݵ�Ÿ�ó������	*/
char	OppAcntNo		[	20	];	/*	�����¹�ȣ	*/
char	CnvsTp			[	1	];	/*	��������	*/
} SOFFT130_IN, *lpSOFFT130_IN;
#define SZ_SOFFT130_IN sizeof(SOFFT130_IN)

typedef struct
{
char	In		[	5	];			
char	AcntNo	 [	20	];	/*	���¹�ȣ	*/
char	Pwd	[	8	];	/*	��й�ȣ	*/
char	RpPrslPtnTp	[	1	];	/*	ȯ�Ž�û��������	*/
char	SellOrdAmt	[	16	];	/*	�ŵ��ֹ��ݾ�	*/
char	IvstfndCode	[	12	];	/*	�����ݵ��ڵ�	*/
char	SpclMidwRpYn	[	1	];	/*	Ư���ߵ�ȯ�ſ���	*/
char	FndtdTrxTp	[	1	];	/*	�ݵ�Ÿ�ó������	*/
char	OppAcntNo	[	20	];	/*	�����¹�ȣ	*/
char	CnvsTp	[	1	];	/*	��������	*/
char	Out	[	5	];	/*		*/
char	OrdNo	[	10	];	/*	�ֹ���ȣ	*/
char	BncertSellUnit	[	16	];	/*	�������Ǹŵ��¼�	*/
char	BalUnit	[	16	];	/*	�ܰ��¼�	*/
char	SellAmt	[	16	];	/*	�ŵ��ݾ�	*/
char	RpCmsnAmt	[	16	];	/*	ȯ�ż�����	*/
char	HldbkCmsnAmt	[	16	];	/*	����������	*/
char	Ictax	[	16	];	/*	�ҵ漼	*/
char	Ihtax	[	16	];	/*	�ֹμ�	*/
char	BasePrc	[	12	];	/*	���ذ�	*/
char	BoaBasePrc	[	20	];	/*	��ǥ���ذ�	*/
char	BasePrcAppDt	[	8	];	/*	���ذ�������	*/
char	SettDt	[	8	];	/*	������	*/
char	FundNm	[	40	];	/*	�ݵ��	*/

} SOFFT130_OUT, *lpSOFFT130_OUT;
#define SZ_SOFFT130_OUT sizeof(SOFFT130_OUT)

/***********************************************************************
 * �ݵ� �Ÿ����
 ***********************************************************************/
typedef struct
{
char	In	[	5	];	/*		*/
char	AcntNo	[	20	];	/*	���¹�ȣ	*/
char	Pwd	[	8	];	/*	��й�ȣ	*/
char	TrdTp	[	1	];	/*	�ŷ�����	*/
char	TrxBrnNo	[	3	];	/*	ó��������ȣ	*/
char	IvtrstIadTp	[	1	];	/*	���ű����ܱ���	*/
char	OrdDt	[	8	];	/*	�ֹ���	*/
char	OrdNo	[	10	];	/*	�ֹ���ȣ	*/
char	FndtdTrxTp	[	1	];	/*	�ݵ�Ÿ�ó������	*/
char	OppAcntNo	[	20	];	/*	�����¹�ȣ	*/
} SOFFT131_IN, *lpSOFFT131_IN;
#define SZ_SOFFT131_IN sizeof(SOFFT131_IN)

typedef struct
{
char	In	[	5	];	/*		*/
char	AcntNo	[	20	];	/*	���¹�ȣ	*/
char	Pwd	[	8	];	/*	��й�ȣ	*/
char	TrdTp	[	1	];	/*	�ŷ�����	*/
char	TrxBrnNo	[	3	];	/*	ó��������ȣ	*/
char	IvtrstIadTp	[	1	];	/*	���ű����ܱ���	*/
char	OrdDt	[	8	];	/*	�ֹ���	*/
char	OrdNo	[	10	];	/*	�ֹ���ȣ	*/
char	FndtdTrxTp	[	1	];	/*	�ݵ�Ÿ�ó������	*/
char	OppAcntNo	[	20	];	/*	�����¹�ȣ	*/
char	Out	[	5	];	/*		*/
char	AcntNo2	[	20	];	/*	���¹�ȣ	*/
char	TrdDate	[	8	];	/*	�ŷ�����	*/
char	TrdNo	[	10	];	/*	�ŷ���ȣ	*/
char	Inouno	[	10	];	/*	�ⳳ��ȣ	*/
char	BuyAmt	[	16	];	/*	�ż��ݾ�	*/
char	BuyQty	[	16	];	/*	�ż�����	*/
char	SecBfbalQty	[	16	];	/*	�����������ܼ���	*/
char	SecCrbalQty	[	16	];	/*	�������Ǳ��ܼ���	*/
char	BasePrcAppDt	[	8	];	/*	���ذ�������	*/
char	SettDt	[	8	];	/*	������	*/
char	MchndCmsnAmt	[	16	];	/*	�Ǹż�����	*/
char	BnsBasePrc	[	19	];	/*	�Ÿű��ذ�	*/
char	BoaBasePrc	[	19	];	/*	��ǥ���ذ�	*/
char	IvstfndCode	[	12	];	/*	�����ݵ��ڵ�	*/
char	HanglIvstfndNm	[	40	];	/*	�ѱ������ݵ��	*/
char	IvstfndSeqno	[	10	];	/*	�����ݵ��Ϸù�ȣ	*/
} SOFFT131_OUT, *lpSOFFT131_OUT;
#define SZ_SOFFT131_OUT sizeof(SOFFT131_OUT)

/***********************************************************************
 * ���࿹���ּ�����ȸ - SDPKT120
 ***********************************************************************/
typedef struct
{
char	In	[	5	];	/*		*/
char	BnkCode	[	3	];	/*	�����ڵ�	*/
char	BnkAcntNo	[	20	];	/*	������¹�ȣ	*/
} SDPKT120_IN, *lpSDPKT120_IN;
#define SZ_SDPKT120_IN sizeof(SDPKT120_IN)

typedef struct
{
char	In	[	5	];	/*		*/
char	BnkCode	[	3	];	/*	�����ڵ�	*/
char	BnkAcntNo	[	20	];	/*	������¹�ȣ	*/
char	Out	[	5	];	/*		*/
char	BnkNm	[	40	];	/*	�����	*/
char	BnkBrnNm	[	40	];	/*	����������	*/
char	DpsPsnNm	[	40	];	/*	�����ָ�	*/
char	BnkRspnsCode	[	4	];	/*	���������ڵ�	*/
} SDPKT120_OUT, *lpSDPKT120_OUT;
#define SZ_SDPKT120_OUT sizeof(SDPKT120_OUT)

/***********************************************************************
 *
 *	object name : SOFAT331 ���� (��ȭ���� �¶��� ü�� ó�� �ڽ��� ����)
 *	prgram id	: GIS - Tr2009.pc
 *	description	: SOFAT331 ���� ����ü
 *
 ***********************************************************************/
typedef struct
{
    char 	In         			[ 5];
	char    zTrxTp              [ 1];   // ó������
    char    lIttCode            [ 9];   // ����ڵ�
    char    zTrxDt              [ 8];   // ó����
    char    zAcntNo             [20];   // ���¹�ȣ
    char    zPwd                [ 8];   // ��й�ȣ
    char    zExecDt             [ 8];   // ü����
    char    lFileTrdNo          [10];   // ���ϰŷ���ȣ
    char    zClntNo             [20];   // ����ȣ
    char    zFileAcntNo         [20];   // ���ϰ��¹�ȣ
    char    zClmDt              [ 8];   // û����
    char    zBnsCode            [ 2];   // �Ÿ��ڵ�
    char    zIsuNo              [12];   // �����ȣ
    char    zFileCntryCode      [ 2];   // ���ϱ����ڵ�
    char    lIttNp              [ 6];   // �����ȣ
    char    zOwnTp              [ 1];   // ��������
    char    lTrdQty             [16];   // �ŷ�����
    char    dUprc               [15];   // �ܰ�
    char    zCrcyCode           [ 3];   // ��ȭ�ڵ�
    char    dFcurrSettAmt       [17];   // ��ȭ�����ݾ�
    char    dFcurrTrdAmt        [17];   // ��ȭ�ŷ��ݾ�
    char    dSecCmsnAmt         [17];   // SEC������
    char    dFcurrEtcTax        [17];   // ��ȭ��Ÿ����
    char    dStk2000CmsnAmt     [17];   // 2000�ּ�����
    char    zBloterCode         [ 2];   // BLOTER �ڵ�
    char    zOppPrdtTp          [ 1];   // ����ǰ����
    char    zOppClntNo          [20];   // ������ȣ
    char    zOppAcntNo          [20];   // �����¹�ȣ
    char    zAgnt               [24];   // �븮��
    char    zTrdMkt             [24];   // �ŷ�����
    char    zOthprty            [20];   // ����
    char    zOthprtyNm          [40];   // �����
    char    zLclTrdNo           [12];   // �����ŷ���ȣ
    char    zFileTrdDt          [ 8];   // ���ϰŷ���
    char    zSettPreargDt       [ 8];   // ����������
    char    zCsgnAcntNo         [20];   // ��Ź���¹�ȣ
    char    dCmsnAmt1           [17];   // ������1
    char    dCmsnAmt2           [17];   // ������2
    char    dCmsnAmt3           [17];   // ������3
    char    dCmsnAmt4           [17];   // ������4
    char    dCmsnAmt5           [17];   // ������5

} SOFAT331_IN, * lpSOFAT331_IN;
#define SZ_SOFAT331_IN              sizeof(SOFAT331_IN)

typedef struct
{
    char sTrxTp          [  1]; /* ó������     */
    char sIttCode        [  8]; /* ����ڵ�     */
    char sTrxDt          [  8]; /* ó����       */
    char sAcntNo         [ 20]; /* ���¹�ȣ     */
    char sPwd            [ 32]; /* ��й�ȣ     */
    char sExecDt         [  8]; /* ü����       */
    char sFileTrdNo      [  9]; /* ���ϰŷ���ȣ */
    char sClntNo         [ 20]; /* ����ȣ     */
    char sFileAcntNo     [ 20]; /* ���ϰ��¹�ȣ */
    char sClmDt          [  8]; /* û����       */
    char sBnsCode        [  2]; /* �Ÿ��ڵ�     */
    char sIsuNo          [ 12]; /* �����ȣ     */
    char sFileCntryCode  [  2]; /* ���ϱ����ڵ� */
    char sIttNo          [  5]; /* �����ȣ     */
    char sOwnTp          [  1]; /* ��������     */
    char sTrdQty         [ 15]; /* �ŷ�����     */
    char sUprc           [ 13]; /* �ܰ�         */
    char sCrcyCode       [  3]; /* ��ȭ�ڵ�     */
    char sFcurrSettAmt   [ 15]; /* ��ȭ�����ݾ� */
    char sFcurrTrdAmt    [ 15]; /* ��ȭ�ŷ��ݾ� */
    char sSecCmsnAmt     [ 15]; /* SEC������    */
    char sFcurrEtcTax    [ 15]; /* ��ȭ��Ÿ���� */
    char sStk2000CmsnAmt [ 15]; /* 2000�ּ����� */
    char sBloterCode     [  2]; /* BLOTER �ڵ�  */
    char sOppPrdtTp      [  1]; /* ����ǰ���� */
    char sOppClntNo      [ 20]; /* ������ȣ */
    char sOppAcntNo      [ 20]; /* �����¹�ȣ */
    char sAgnt           [ 24]; /* �븮��       */
    char sTrdMkt         [ 24]; /* �ŷ�����     */
    char sOthprty        [ 20]; /* ����       */
    char sOthprtyNm      [ 40]; /* �����     */
    char sLclTrdNo       [ 12]; /* �����ŷ���ȣ */
    char sFileTrdDt      [  8]; /* ���ϰŷ���   */
    char sSettPreargDt   [  8]; /* ����������   */
    char sCsgnAcntNo     [ 20]; /* ��Ź���¹�ȣ */
    char sCmsnAmt1       [ 15]; /* ������1      */
    char sCmsnAmt2       [ 15]; /* ������2      */
    char sCmsnAmt3       [ 15]; /* ������3      */
    char sCmsnAmt4       [ 15]; /* ������4      */
    char sCmsnAmt5       [ 15]; /* ������5      */
}   SOFAT331_OUT, * lpSOFAT331_OUT;
#define SZ_SOFAT331_OUT     sizeof(SOFAT331_OUT)

/***********************************************************************
 *
 *	object name : SOFAQ239 ���� (��ȭ�������������ܰ���Ȳ)
 *	prgram id	: GIS - Tr2022.pc
 *	description	: SOFAQ239 ���� ����ü
 *
 ***********************************************************************/
typedef struct
{
char	In	[	5	];	/*		*/
char	BrnNo	[	3	];	/*	������ȣ	*/
char	SrtIsuNo	[	12	];	/*	���������ȣ	*/
char	BaseDt	[	8	];	/*	������	*/
char	QryTp	[	1	];	/*	��ȸ����	*/
char	IttCode	[	9	];	/*	����ڵ�	*/
char	MktCode	[	2	];	/*	�����ڵ�	*/
char	FcstckPtnCode	[	2	];	/*	��ȭ���������ڵ�	*/
} SOFAQ239_IN, * lpSOFAQ239_IN;
#define SZ_SOFAQ239_IN              sizeof(SOFAQ239_IN)

typedef struct
{
char    BrnNm   [   40  ];  /*  ������  */
char    SumQty  [   16  ];  /*  �հ����    */
char    FcurrTotamt1    [   17  ];  /*  ��ȭ�հ�ݾ�1   */
} SOFAQ239_Sub1_OUT, *lpSOFAQ239_Sub1_OUT;
#define SZ_SOFAQ239_Sub1_OUT sizeof(SOFAQ239_Sub1_OUT)

typedef struct
{
char    IsuNo   [   12  ];  /*  �����ȣ    */
char    IsuNm   [   40  ];  /*  �����  */
char    CrcyCode    [   3   ];  /*  ��ȭ�ڵ�    */
char    HldQty  [   16  ];  /*  ��������    */
char    FcurrBookAmt    [   17  ];  /*  ��ȭ��αݾ�    */
char    MktTpNm [   20  ];  /*  ���屸��    */
char    Xchrat  [   11  ];  /*  ȯ��    */
char    GdCprc  [   19  ];  /*  ����    */
char    FcurrEvalAmt    [   17  ];  /*  ��ȭ�򰡱ݾ�    */
char    WonEvalAmt  [   16  ];  /*  ��ȭ�򰡱ݾ�    */
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
    char OrdDt              [ 8]; /*�ֹ���                */
    char TrdDt              [ 8]; /*�ŷ���                */
    char SettPreargDt       [ 8]; /*����������            */
    char DpartNm            [40]; /*�μ���                */
    char FundOpAcntNo       [20]; /*�ݵ�����¹�ȣ      */
    char Pwd                [ 8]; /*��й�ȣ              */
    char IsuNo              [12]; /*�����ȣ              */
    char FcstckTrdPtnCode   [ 2]; /*��ȭ���ǰŷ������ڵ�  */
    char OrdXchrat          [11]; /*�ֹ�ȯ��              */
    char UprcAutoCompYn     [ 1]; /*�ܰ��ڵ���꿩��      */
    char OrdUprc            [15]; /*�ֹ��ܰ�              */
    char OrdQty             [16]; /*�ֹ�����              */
    char BuyDtInptYn        [ 1]; /*�ż����Է¿���        */
    char BndBuyDt           [ 8]; /*ä�Ǹż���            */
    char FcurrOrdAmt        [17]; /*��ȭ�ֹ��ݾ�          */
    char TrdOthprtyNm       [40]; /*�ŷ������          */
    char SettIttNm          [40]; /*���������            */
    char ThcoCstdyIttNm     [40]; /*��纸�������        */
    char OppCstdyIttNm      [40]; /*��뺸�������        */
    char OppBrkNm           [40]; /*����߰��θ�          */
    char IntrstFcurrAmt     [17]; /*ä�����ڿ�ȭ�ݾ�      */
    char PremFcurrAmt       [17]; /*�����̾���ȭ�ݾ�      */
    char AbrdFcurrCmsnAmt   [17]; /*���ܿ�ȭ������        */
    char AbrdEvrprcFcurrAmt [17]; /*����������ȭ�ݾ�    */
    char CorpTaxRat         [ 7]; /*���μ���              */
    char WonCorpTax         [16]; /*��ȭ���μ�            */
    char TrtaxRat           [7]; /*�ŷ�����              */
    char WonTrtax           [16]; /*��ȭ�ŷ���            */
    char BnsRsn             [100]; /*�ŸŻ���              */
    char OpPlan             [100]; /*����ȹ              */
}   SSEAT308I_st,   * lpSSEAT308I_st;
#define SZ_SSEAT308I    sizeof(SSEAT308I_st)

typedef struct _SSEAT309I_
{
    char In                  [ 5];
    char OrdDt               [ 8];    /*�ֹ���                */
    char SettPreargDt        [ 8];    /*����������            */
    char TrdDt               [ 8];    /*�ŷ���                */
    char DpartNm             [40];    /*�μ���                */
    char FundOpAcntNo        [20];    /*�ݵ�����¹�ȣ      */
    char Pwd                 [ 8];    /*��й�ȣ              */
    char IsuNo               [12];    /*�����ȣ              */
    char FcstckTrdPtnCode    [ 2];    /*��ȭ���ǰŷ������ڵ�  */
    char OrdXchrat           [11];    /*�ֹ�ȯ��              */
    char UprcAutoCompYn      [ 1];    /*�ܰ��ڵ���꿩��      */
    char OrdUprc             [15];    /*�ֹ��ܰ�              */
    char OrdQty              [16];    /*�ֹ�����              */
    char BuyDtInptYn         [ 1];    /*�ż����Է¿���        */
    char BndBuyDt            [ 8];    /*ä�Ǹż���            */
    char FcurrOrdAmt         [17];    /*��ȭ�ֹ��ݾ�          */
    char TrdOthprtyNm        [40];    /*�ŷ������          */
    char SettIttNm           [40];    /*���������            */
    char ThcoCstdyIttNm      [40];    /*��纸�������        */
    char OppCstdyIttNm       [40];    /*��뺸�������        */
    char OppBrkNm            [40];    /*����߰��θ�          */
    char IntrstFcurrAmt      [17];    /*������ڿ�ȭ�ݾ�      */
    char PremFcurrAmt        [17];    /*�����̾���ȭ�ݾ�      */
    char AbrdFcurrCmsnAmt    [17];    /*���ܿ�ȭ������        */
    char AbrdEvrprcFcurrAmt  [17];    /*����������ȭ�ݾ�    */
    char BnsRsn              [100];    /*�ŸŻ���              */
    char OpPlan              [100];    /*����ȹ              */
}   SSEAT309I_st,   * lpSSEAT309I_st;
#define SZ_SSEAT309I    sizeof(SSEAT309I_st)

/***********************************************************************
 *
 *	object name : SOFAQ215 �Է� ���� (��ȭ���� AHTS�ŷ����� �ڽ��� �Է�����)
 *	prgram id	: GIS - Tr2009.pc
 *	description	: SOFAQ215 ���� �Է� ����ü
 *
 ***********************************************************************/
typedef struct SOFAQ215_IN_ST
{
    char In       [  5]; /* ���ڵ尹�� */
    char sAcntNo  [ 20]; /* ���¹�ȣ */
    char sSrtDt   [  8]; /* ������   */
    char sEndDt   [  8]; /* ������   */
    char sQryTp   [  1]; /* ��ȸ���� */
    char sBnsCode [  2]; /* �Ÿ��ڵ� */
    char sIttCode [  8+1]; /* ����ڵ� */
    char sBaseDtTp[  1]; /* ������ ���� */
}   SOFAQ215_IN, * lpSOFAQ215_IN;
#define SZ_SOFAQ215_IN     sizeof(SOFAQ215_IN)

/***********************************************************************
 *
 *	object name : SOFAQ215 ��� ���� (��ȭ���� AHTS�ŷ����� �ڽ��� �������)
 *	prgram id	: GIS - Tr2009.pc
 *	description	: SOFAQ215 ���� ��� ����ü
 *
 ***********************************************************************/
typedef struct _SOFAQ215Occ_sub_
{
    char sTrdDt        [ 8    ];    /* �ŷ���       */
    char sSettDt       [ 8    ];    /* ������       */
    char sIsuNm        [40    ];    /* �����       */
    char sTrdNo        [ 9 + 1];    /* �ŷ���ȣ     */
    char sAcntNo       [20    ];    /* ���¹�ȣ     */
    char sBnsTpNm      [10    ];    /* �Ÿű���     */
    char sTrdQty       [15 + 1];    /* �ŷ�����     */
    char sUprc         [13 + 2];    /* �ܰ�         */
    char sFcurrTrdAmt  [15 + 2];    /* ��ȭ�ŷ��ݾ� */
    char sFcurrSettAmt [15 + 2];    /* ��ȭ�����ݾ� */
    char sCmsnAmt1     [15 + 2];    /* ������1      */
    char sCmsnAmt2     [15 + 2];    /* ������2      */
    char sCmsnAmt3     [15 + 2];    /* ������3      */
    char sBrkCmsnAmt   [15 + 2];    /* BROKER������ */
    char sCmsnAmt4     [15 + 2];    /* ������4      */
    char sCmsnAmt5     [15 + 2];    /* ������5      */
    char sAbrdMktIdNm  [50    ];    /* �ؿܰŷ��Ҹ� */
    char sIsuNo        [12    ];    /* �����ȣ     */
    char sFileCntryCode[ 2    ];    /* ���ϱ�����ȣ */
    char sCrcyCode     [ 3    ];    /* ��ȭ�ڵ�     */
	char OwnTp         [ 1    ];
    char TpNm21        [10    ];
}   SOFAQ215Occ_Sub_st, * lpSOFAQ215Occ_Sub_st;
#define SZ_SOFAQ215Occ_sub  sizeof(SOFAQ215Occ_Sub_st)

typedef struct _SOFAQ215Occ_
{
    SOFAQ215_IN         icc;
    char Out            [ 5    ];    /* ���ڵ尹�� */
}   SOFAQ215Occ_st, * lpSOFAQ215Occ_st;
#define SZ_SOFAQ215Occ_st   sizeof(SOFAQ215Occ_st)


#if 0
typedef struct SOFAQ215_OUT_ST
{
    char sTrdDt        [ 8];    /* �ŷ���       */
    char sSettDt       [ 8];    /* ������       */
    char sIsuNm        [40];    /* �����       */
    char sTrdNo        [ 9];    /* �ŷ���ȣ     */
    char sAcntNo       [20];    /* ���¹�ȣ     */
    char sBnsTpNm      [10];    /* �Ÿű���     */
    char sTrdQty       [15];    /* �ŷ�����     */
    char sUprc         [13];    /* �ܰ�         */
    char sFcurrTrdAmt  [15];    /* ��ȭ�ŷ��ݾ� */
    char sFcurrSettAmt [15];    /* ��ȭ�����ݾ� */
    char sCmsnAmt1     [15];    /* ������1      */
    char sCmsnAmt2     [15];    /* ������2      */
    char sCmsnAmt3     [15];    /* ������3      */
    char sBrkCmsnAmt   [15];    /* BROKER������ */
    char sCmsnAmt4     [15];    /* ������4      */
    char sCmsnAmt5     [15];    /* ������5      */
    char sAbrdMktIdNm  [50];    /* �ؿܰŷ��Ҹ� */
}   SOFAQ215_OUT, * lpSOFAQ215_OUT;
#define SZ_SOFAQ215_OUT     sizeof(SOFAQ215_OUT)
#endif

/***********************************************************************
 * ��ȭ���ǰ������� - SOFAQ211
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
    char  EmpNm[40];	      /*�����*/
    char  IsuNm[40];	      /*�����*/
    char  BrnNm[40];	      /*������*/
    char  BnsTpNm[10];	      /*�Ÿű���*/
    char  CntryNm[40];	      /*������*/
    char  TrdMkt[24];  	      /*�ŷ�����*/
    char  BuyCnt[10];	      /*�ż��Ǽ�*/
    char  FcurrBuyAmt[17];	  /*��ȭ�ż��ݾ�*/
    char  SellCnt[10];	      /*�ŵ��Ǽ�*/
    char  FcurrSellAmt[17];	  /*��ȭ�ŵ��ݾ�*/
    char  AppyCnt[10];	      /*û��Ǽ�*/
    char  FcstckAppyAmt[17];	/*��ȭ����û��ݾ�*/
    char  BuySecCmsnAmt[17];	/*�ż�SEC������*/
    char  SellSecCmsnAmt[17];	/*�ŵ�SEC������*/
    char  BuyFcurrEtcTax[17];	/*�ż���ȭ��Ÿ����*/
    char  SellFcurrEtcTax[17];	/*�ŵ���ȭ��Ÿ����*/
    char  BuyBrkCmsnAmt[17];	/*�ż�BROKER������*/
    char  SellBrkCmsnAmt[17];	/*�ŵ�BROKER������*/
    char  BuyKsdCmsnAmt[17];	/*�ż�KSD������*/
    char  SellKsdCmsnAmt[17];	/*�ŵ�KSD������*/
    char  BuyOtherFee[17];	    /*�ż�Other Fee*/
    char  SellOtherFee[17];	    /*�ŵ�Other Fee*/
    char  CmsnAmt1[17];	/*������1*/
    char  CmsnAmt2[17];	/*������2*/
    char  CmsnAmt3[17];	/*������3*/
    char  CmsnAmt4[17];	/*������4*/
    char  CmsnAmt5[17];	/*������5*/
    char  CmsnAmt6[17];	/*������6*/
} SOFAQ211_OUT, *lpSOFAQ211_OUT;
#define SZ_SOFAQ211_OUT sizeof(SOFAQ211_OUT)




/***********************************************************************
 * ��ȭ���ǿ�Ź�ݺ������� - SOFAQ238
 ***********************************************************************/
typedef struct
{
	char    In  		[ 5];	/*      */
	char 	BrnNo		[ 3];	/* ������ȣ */
	char	QryDt		[ 8];	/* ��ȸ�� */
	char	PdptnCode	[ 2];	/* ��ǰ�����ڵ� */
	char	CrcyCode	[ 3];	/* ��ȭ�ڵ� */
} SOFAQ238_IN, *lpSOFAQ238_IN;
#define SZ_SOFAQ238_IN sizeof(SOFAQ238_IN)

typedef struct
{
    char    BrnNm[40];          /*������            */
    char    CrcyCode[3];        /*��ȭ�ڵ�          */
    char    CrcyNm[40];         /*��ȭ��            */
    char    FcurrDpsBfbal[17];  /*��ȭ����������    */
    char    FcurrDpsCrbal[17];  /*��ȭ�����ݱ���    */
    char    FcurrDpsIncamt[17]; /*��ȭ�����������ݾ�*/
    char    FcurrDpsDeamt[17];  /*��ȭ�����ݰ��ұݾ�*/
} SOFAQ238_Sub1_OUT, *lpSOFAQ238_Sub1_OUT;
#define SZ_SOFAQ238_Sub1_OUT sizeof(SOFAQ238_Sub1_OUT)

typedef struct
{
    char    SmryNo[ 4];             /*�����ȣ        */
    char    SmryNm[40];             /*�����          */
    char    RealMnyinFcurrAmt[17];  /*���Աݾ�(��ȭ)  */
    char    RealMnyioFcurrAmt[17];  /*������ݿ�ȭ�ݾ�*/
    char    FcurrOrgAmt[17];        /*��ȭ���ݾ�      */
    char    SecCmsnAmt[17];         /*SEC������       */
    char    KsdCmsnAmt[17];         /*KSD������       */
    char    BrkCmsnAmt[17];         /*BROKER������    */
    char    FcurrEtcTax[17];        /*��ȭ��Ÿ����    */
    char    FcurrEtcCmsnAmt[17];    /*��ȭ��Ÿ������  */
    char    CmsnAmt1[17];           /*������1         */
    char    CmsnAmt2[17];           /*������2         */
    char    CmsnAmt3[17];           /*������3         */
    char    CmsnAmt4[17];           /*������4         */
    char    CrcyCode[ 3];           /*��ȭ�ڵ�        */
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
 * ���� �ֹ� - SONAT000
 ***********************************************************************/
typedef struct
{
char  In                  [5 ];
char  AcntNo              [20];  //���¹�ȣ
char  InptPwd             [8 ];  //��й�ȣ
char  IsuNo               [12];  //�����ȣ
char  OrdQty              [16];  //�ֹ�����
char  OrdPrc              [13];  //�ֹ�����
char  BnsTp               [1 ];  //�Ÿű��� 1:�ŵ� 2:�ż�
char  OrdprcPtnCode       [2 ];  //ȣ�������ڵ� 00:������ 03:���尡
char  PrgmOrdprcPtnCode   [2 ];  //���α׷�ȣ�������ڵ� 00:�Ϲ�
char  StslAbleYn          [1 ];  //���ŵ����ɿ���  0:�Ұ�
char  StslOrdprcTp        [1 ];  //���ŵ�ȣ������  0:�Ϲ�
char  CommdaCode          [2 ];  //��Ÿ�ü�ڵ�
char  MgntrnCode          [3 ];  //�ſ�ŷ��ڵ�  000:����
char  LoanDt              [8 ];  //������
char  MbrNo               [3 ];  //ȸ����ȣ  052:����
char  OrdCndiTp           [1 ];  //�ֹ����Ǳ���  0:���� 1:IOC 2:FOK
char  StrtgCode           [6 ];  //�����ڵ�
char  GrpId               [20];  //�׷�ID
char  OrdSeqNo            [10];  //�ֹ�ȸ��
char  PtflNo              [10];  //��Ʈ��������ȣ
char  BskNo               [10];  //�ٽ��Ϲ�ȣ
char  TrchNo              [10];  //Ʈ��ġ��ȣ
char  ItemNo              [10];  //�����۹�ȣ
char  OpDrtnNo            [12];  //��������ȣ
char  LpYn                [1 ];  //�����������ڿ��� 0:�Ϲ�
char  CvrgTp              [1 ];  //�ݴ�Ÿű���  0:�Ϲ�
} SONAT000_IN, *lpSONAT000_IN;
#define SZ_SONAT000_IN sizeof(SONAT000_IN)

typedef struct
{
char    In  [   5   ]   ;   /*      */
char    AcntNo  [   20  ]   ;   /*  ���¹�ȣ    */
char    InptPwd [   8   ]   ;   /*  �Էº�й�ȣ    */
char    IsuNo   [   12  ]   ;   /*  �����ȣ    */
char    OrdQty  [   16  ]   ;   /*  �ֹ�����    */
char    OrdPrc  [   13  ]   ;   /*  �ֹ���  */
char    BnsTp   [   1   ]   ;   /*  �Ÿű���    */
char    OrdprcPtnCode   [   2   ]   ;   /*  ȣ�������ڵ�    */
char    PrgmOrdprcPtnCode   [   2   ]   ;   /*  ���α׷�ȣ�������ڵ�    */
char    StslAbleYn  [   1   ]   ;   /*  ���ŵ����ɿ���  */
char    StslOrdprcTp    [   1   ]   ;   /*  ���ŵ�ȣ������  */
char    CommdaCode  [   2   ]   ;   /*  ��Ÿ�ü�ڵ�    */
char    MgntrnCode  [   3   ]   ;   /*  �ſ�ŷ��ڵ�    */
char    LoanDt  [   8   ]   ;   /*  ������  */
char    MbrNo   [   3   ]   ;   /*  ȸ����ȣ    */
char    OrdCndiTp   [   1   ]   ;   /*  �ֹ����Ǳ���    */
char    StrtgCode   [   6   ]   ;   /*  �����ڵ�    */
char    GrpId   [   20  ]   ;   /*  �׷�ID  */
char    OrdSeqNo    [   10  ]   ;   /*  �ֹ�ȸ��    */
char    PtflNo  [   10  ]   ;   /*  ��Ʈ��������ȣ  */
char    BskNo   [   10  ]   ;   /*  �ٽ��Ϲ�ȣ  */
char    TrchNo  [   10  ]   ;   /*  Ʈ��ġ��ȣ  */
char    ItemNo  [   10  ]   ;   /*  �����۹�ȣ  */
char    OpDrtnNo    [   12  ]   ;   /*  ������ù�ȣ    */
char    LpYn    [   1   ]   ;   /*  �����������ڿ���    */
char    CvrgTp  [   1   ]   ;   /*  �ݴ�Ÿű���    */
char    Out [   5   ]   ;   /*      */
char    OrdNo   [   10  ]   ;   /*  �ֹ���ȣ    */
char    OrdTime [   9   ]   ;   /*  �ֹ��ð�    */
char    OrdMktCode  [   2   ]   ;   /*  �ֹ������ڵ�    */
char    OrdPtnCode  [   2   ]   ;   /*  �ֹ������ڵ�    */
char    ShtnIsuNo   [   9   ]   ;   /*  ���������ȣ    */
char    MgempNo [   9   ]   ;   /*  ���������ȣ    */
char    OrdAmt  [   16  ]   ;   /*  �ֹ��ݾ�    */
char    SpareOrdNo  [   10  ]   ;   /*  �����ֹ���ȣ    */
char    CvrgSeqno   [   10  ]   ;   /*  �ݴ�Ÿ��Ϸù�ȣ    */
char    RsvOrdNo    [   10  ]   ;   /*  �����ֹ���ȣ    */
char    SpotOrdQty  [   16  ]   ;   /*  �ǹ��ֹ�����    */
char    RuseOrdQty  [   16  ]   ;   /*  �����ֹ�����  */
char    MnyOrdAmt   [   16  ]   ;   /*  �����ֹ��ݾ�    */
char    SubstOrdAmt [   16  ]   ;   /*  ����ֹ��ݾ�    */
char    RuseOrdAmt  [   16  ]   ;   /*  �����ֹ��ݾ�  */
char    AcntNm  [   40  ]   ;   /*  ���¸�  */
char    IsuNm   [   40  ]   ;   /*  �����  */

} SONAT000_OUT, *lpSONAT000_OUT;
#define SZ_SONAT000_OUT sizeof(SONAT000_OUT)

/***********************************************************************
 * ���� ���� �ֹ� - SONAT001
 ***********************************************************************/
typedef struct
{
char    In  [   5   ]   ;   /*      */
char    OrgOrdNo  [   10  ]   ;   /* �ֹ���ȣ */
char    AcntNo  [   20  ]   ;   /*  ���¹�ȣ    */
char    InptPwd [   8   ]   ;   /*  �Էº�й�ȣ    */
char    IsuNo   [   12  ]   ;   /*  �����ȣ    */
char    OrdQty  [   16  ]   ;   /*  �ֹ�����    */
char    OrdprcPtnCode  [   2   ]   ;   /* ȣ�������ڵ� */
char    OrdCndiTp  [   1   ]   ;   /* �ֹ����Ǳ��� */
char    OrdPrc  [   13   ]   ;   /* �ֹ��� */
char    CommdaCode  [   2   ]   ;   /*  ��Ÿ�ü�ڵ�    */
char    StrtgCode   [   6  ]   ;   /* �����ڵ� */
char    GrpId   [   20  ]   ;   /*  �׷�ID  */
char    OrdSeqNo    [   10  ]   ;   /*  �ֹ�ȸ��    */
char    PtflNo  [   10  ]   ;   /*  ��Ʈ��������ȣ  */
char    BskNo   [   10  ]   ;   /*  �ٽ��Ϲ�ȣ  */
char    TrchNo  [   10  ]   ;   /*  Ʈ��ġ��ȣ  */
char    ItemNo  [   10  ]   ;   /*  �����۹�ȣ  */

} SONAT001_IN, *lpSONAT001_IN;
#define SZ_SONAT001_IN sizeof(SONAT001_IN)

typedef struct
{
char    In  [   5   ]   ;   /*      */
char    OrgOrdNo  [   10  ]   ;   /* �ֹ���ȣ */
char    AcntNo  [   20  ]   ;   /*  ���¹�ȣ    */
char    InptPwd [   8   ]   ;   /*  �Էº�й�ȣ    */
char    IsuNo   [   12  ]   ;   /*  �����ȣ    */
char    OrdQty  [   16  ]   ;   /*  �ֹ�����    */
char    OrdprcPtnCode  [   2   ]   ;   /* ȣ�������ڵ� */
char    OrdCndiTp  [   1   ]   ;   /* �ֹ����Ǳ��� */
char    OrdPrc  [   13   ]   ;   /* �ֹ��� */
char    CommdaCode  [   2   ]   ;   /*  ��Ÿ�ü�ڵ�    */
char    StrtgCode   [   6  ]   ;   /* �����ڵ� */
char    GrpId   [   20  ]   ;   /*  �׷�ID  */
char    OrdSeqNo    [   10  ]   ;   /*  �ֹ�ȸ��    */
char    PtflNo  [   10  ]   ;   /*  ��Ʈ��������ȣ  */
char    BskNo   [   10  ]   ;   /*  �ٽ��Ϲ�ȣ  */
char    TrchNo  [   10  ]   ;   /*  Ʈ��ġ��ȣ  */
char    ItemNo  [   10  ]   ;   /*  �����۹�ȣ  */

char    Out [   5   ]   ;   /*      */
char    OrdNo   [   10  ]   ;   /*  �ֹ���ȣ    */
char    PrntOrdNo   [   10  ]   ;   /* ���ֹ���ȣ */
char    OrdTime [   9   ]   ;   /*  �ֹ��ð�    */
char    OrdMktCode  [   2   ]   ;   /*  �ֹ������ڵ�    */
char    OrdPtnCode  [   2   ]   ;   /*  �ֹ������ڵ�    */
char    ShtnIsuNo   [   9   ]   ;   /*  ���������ȣ    */
char    PrgmOrdprcPtnCode   [   2   ]   ;   /* ���α׷�ȣ�������ڵ� */
char    StslOrdprcTp   [   1   ]   ;   /* ���ŵ�ȣ������ */
char    StslAbleYn   [   1   ]   ;   /* ���ŵ����ɿ��� */
char    MgntrnCode   [   3   ]   ;   /*�ſ�ŷ��ڵ�*/
char    LoanDt  [   8   ]   ;   /*  ������  */
char    CvrgOrdTp  [   1   ]   ;   /*  �ݴ�Ÿű���    */
char    LpYn    [   1   ]   ;   /*  �����������ڿ���    */
char    MgempNo [   9   ]   ;   /*  ���������ȣ    */
char    OrdAmt [   16   ]   ;   /* �ֹ��ݾ�*/
char    BnsTp [   1   ]   ;   /* �Ÿű��� */
char    SpareOrdNo  [   10  ]   ;   /*  �����ֹ���ȣ    */
char    CvrgSeqno   [   10  ]   ;   /*  �ݴ�Ÿ��Ϸù�ȣ    */
char    RsvOrdNo    [   10  ]   ;   /*  �����ֹ���ȣ    */
char    MnyOrdAmt    [   16  ]   ;   /* �����ֹ��ݾ� */
char    SubstOrdAmt    [   16  ]   ;   /* �����ֹ��ݾ� */
char    RuseOrdAmt    [   16  ]   ;   /* �����ֹ��ݾ� */
char    AcntNm    [   40  ]   ;   /* ���¸� */
char    IsuNm   [   40  ]   ;   /*  �����  */

} SONAT001_OUT, *lpSONAT001_OUT;
#define SZ_SONAT001_OUT sizeof(SONAT001_OUT)


/***********************************************************************
 * ���� ��� �ֹ� - SONAT002
 ***********************************************************************/
typedef struct
{
char    In  [   5   ]   ;   /*      */
char    OrgOrdNo  [   10  ]   ;   /* �ֹ���ȣ */
char    AcntNo  [   20  ]   ;   /*  ���¹�ȣ    */
char    InptPwd [   8   ]   ;   /*  �Էº�й�ȣ    */
char    IsuNo   [   12  ]   ;   /*  �����ȣ    */
char    OrdQty  [   16  ]   ;   /*  �ֹ�����    */
char    CommdaCode  [   2   ]   ;   /*  ��Ÿ�ü�ڵ�    */
char    GrpId   [   20  ]   ;   /*  �׷�ID  */
char    StrtgCode   [   6  ]   ;   /* �����ڵ� */
char    OrdSeqNo    [   10  ]   ;   /*  �ֹ�ȸ��    */
char    PtflNo  [   10  ]   ;   /*  ��Ʈ��������ȣ  */
char    BskNo   [   10  ]   ;   /*  �ٽ��Ϲ�ȣ  */
char    TrchNo  [   10  ]   ;   /*  Ʈ��ġ��ȣ  */
char    ItemNo  [   10  ]   ;   /*  �����۹�ȣ  */

} SONAT002_IN, *lpSONAT002_IN;
#define SZ_SONAT002_IN sizeof(SONAT002_IN)

typedef struct
{
char    In  [   5   ]   ;   /*      */
char    OrgOrdNo  [   10  ]   ;   /* �ֹ���ȣ */
char    AcntNo  [   20  ]   ;   /*  ���¹�ȣ    */
char    InptPwd [   8   ]   ;   /*  �Էº�й�ȣ    */
char    IsuNo   [   12  ]   ;   /*  �����ȣ    */
char    OrdQty  [   16  ]   ;   /*  �ֹ�����    */
char    CommdaCode  [   2   ]   ;   /*  ��Ÿ�ü�ڵ�    */
char    GrpId   [   20  ]   ;   /*  �׷�ID  */
char    StrtgCode   [   6  ]   ;   /* �����ڵ� */
char    OrdSeqNo    [   10  ]   ;   /*  �ֹ�ȸ��    */
char    PtflNo  [   10  ]   ;   /*  ��Ʈ��������ȣ  */
char    BskNo   [   10  ]   ;   /*  �ٽ��Ϲ�ȣ  */
char    TrchNo  [   10  ]   ;   /*  Ʈ��ġ��ȣ  */
char    ItemNo  [   10  ]   ;   /*  �����۹�ȣ  */

char    Out [   5   ]   ;   /*      */
char    OrdNo   [   10  ]   ;   /*  �ֹ���ȣ    */
char    PrntOrdNo   [   10  ]   ;   /* ���ֹ���ȣ */
char    OrdTime [   9   ]   ;   /*  �ֹ��ð�    */
char    OrdMktCode  [   2   ]   ;   /*  �ֹ������ڵ�    */
char    OrdPtnCode  [   2   ]   ;   /*  �ֹ������ڵ�    */
char    ShtnIsuNo   [   9   ]   ;   /*  ���������ȣ    */
char    PrgmOrdprcPtnCode   [   2   ]   ;   /* ���α׷�ȣ�������ڵ� */
char    StslOrdprcTp   [   1   ]   ;   /* ���ŵ�ȣ������ */
char    StslAbleYn   [   1   ]   ;   /* ���ŵ����ɿ��� */
char    MgntrnCode   [   3   ]   ;   /*�ſ�ŷ��ڵ�*/
char    LoanDt  [   8   ]   ;   /*  ������  */
char    CvrgOrdTp  [   1   ]   ;   /*  �ݴ�Ÿű���    */
char    LpYn    [   1   ]   ;   /*  �����������ڿ���    */
char    MgempNo [   9   ]   ;   /*  ���������ȣ    */
char    BnsTp [   1   ]   ;   /* �Ÿű��� */
char    SpareOrdNo  [   10  ]   ;   /*  �����ֹ���ȣ    */
char    CvrgSeqno   [   10  ]   ;   /*  �ݴ�Ÿ��Ϸù�ȣ    */
char    RsvOrdNo    [   10  ]   ;   /*  �����ֹ���ȣ    */
char    AcntNm    [   40  ]   ;   /* ���¸� */
char    IsuNm   [   40  ]   ;   /*  �����  */

} SONAT002_OUT, *lpSONAT002_OUT;
#define SZ_SONAT002_OUT sizeof(SONAT002_OUT)

/***********************************************************************
 * �������������ݻ� - SONCQ021
 ***********************************************************************/
typedef struct
{
	char In          [ 5]; /*            */
	char AcntNo      [20]; /*���¹�ȣ    */
	char Pwd         [ 8]; /*��й�ȣ    */
} SONCQ021_IN, *lpSONCQ021_IN;
#define SZ_SONCQ021_IN sizeof(SONCQ021_IN)

typedef struct 
{
	char BuyAmt        [16]; /*�ż��ݾ�    */
    char BuyCmsnAmt    [16]; /*�ż�������  */
    char BuyAdjstAmt   [16]; /*�ż�����ݾ�*/
    char SellAmt       [16]; /*�ŵ��ݾ�    */
    char SellCmsnAmt   [16]; /*�ŵ�������  */
    char SellEvrTax    [16]; /*�ŵ�������  */
    char SellAdjstAmt  [16]; /*�ŵ�����ݾ�*/
    char BnsAmt        [16]; /*�Ÿűݾ�    */
    char BnsCmsnAmt    [16]; /*�Ÿż�����  */
    char EvrTax        [16]; /*������      */
} SONCQ021_OUT_Sub, *lpSONCQ021_OUT_Sub;
#define SZ_SONCQ021_OUT_Sub sizeof(SONCQ021_OUT_Sub)

typedef struct 
{
	char Dps           [16]; /*������      */
    char RepayRqrdAmt  [16]; /*�����ҿ��  */
    char D1dps         [16]; /*D1������    */
    char D2dps         [16]; /*D2������    */
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
    char AcntNo        [20]; //���¹�ȣ      
    char Pwd           [8]; //��й�ȣ       
} SDPAQ013_IN, *lpSDPAQ013_IN;
#define SZ_SDPAQ013_IN sizeof(SDPAQ013_IN)


///////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char In                  [  5]; //  
    char FundOpAcntNo        [ 20]; // �ݵ�����¹�ȣ X(20)
    char BookQty             [ 16]; // ��μ��� S9(15)
    char ExecDt              [  8]; // ü���� X(8)
    char OpLmtAmt            [ 16]; // ����ѵ��ݾ� S9(15)
    char BuyLmtAmt           [ 16]; // �ż��ѵ��ݾ� S9(15)
    char CrdayHldRat         [ 12]; // ���Ϻ������� S9(4).9(6)
    char FundErnrat          [ 12]; // �ݵ���ͷ� S9(4).9(6)
    char HldQty              [ 16]; // �������� S9(15)
    char HldAmt              [ 16]; // �����ݾ� S9(15)
    char EvalAmt             [ 16]; // �򰡱ݾ� S9(15)
    char EvalPnlAmt          [ 16]; // �򰡼��ͱݾ� S9(15)
    char DtBnsplAmt          [ 17]; // �ϸŸż��ͱݾ� S9(16)
    char MthBnsplAmt         [ 17]; // ���Ÿż��ͱݾ� S9(16)
    char BnsplAmt            [ 16]; // �Ÿż��ͱݾ� S9(15)
    char AllPnlSum           [ 16]; // ��ü�����հ� S9(15)
    char PrdayCmpPnlAmt      [ 16]; // ���ϴ����ͱݾ� S9(15)
} SSESQ110_IN, *lpSSESQ110_IN;
#define SZ_SSESQ110_IN sizeof(SSESQ110_IN)

typedef struct
{
	char In                  [  5]; //
    char FundOpAcntNoi        [ 20]; // �ݵ�����¹�ȣ X(20)
    char BookQtyi             [ 16]; // ��μ��� S9(15)
    char ExecDti              [  8]; // ü���� X(8)
    char OpLmtAmti            [ 16]; // ����ѵ��ݾ� S9(15)
    char BuyLmtAmti           [ 16]; // �ż��ѵ��ݾ� S9(15)
    char CrdayHldRati         [ 12]; // ���Ϻ������� S9(4).9(6)
    char FundErnrati          [ 12]; // �ݵ���ͷ� S9(4).9(6)
    char HldQtyi              [ 16]; // �������� S9(15)
    char HldAmti              [ 16]; // �����ݾ� S9(15)
    char EvalAmti             [ 16]; // �򰡱ݾ� S9(15)
    char EvalPnlAmti          [ 16]; // �򰡼��ͱݾ� S9(15)
    char DtBnsplAmti          [ 17]; // �ϸŸż��ͱݾ� S9(16)
    char MthBnsplAmti         [ 17]; // ���Ÿż��ͱݾ� S9(16)
    char BnsplAmti            [ 16]; // �Ÿż��ͱݾ� S9(15)
    char AllPnlSumi           [ 16]; // ��ü�����հ� S9(15)
    char PrdayCmpPnlAmti      [ 16]; // ���ϴ����ͱݾ� S9(15)
    char Out                 [  5]; //  
    char FundNm              [ 40]; // �ݵ�� X(40)
    char OpLmtAmt            [ 16]; // ����ѵ��ݾ� S9(15)
    char BuyLmtAmt           [ 16]; // �ż��ѵ��ݾ� S9(15)
    char CrdayHldRat         [ 12]; // ���Ϻ������� S9(4).9(6)
    char FundErnrat          [ 12]; // �ݵ���ͷ� S9(4).9(6)
    char HldQty              [ 16]; // �������� S9(15)
    char HldAmt              [ 16]; // �����ݾ� S9(15)
    char EvalAmt             [ 16]; // �򰡱ݾ� S9(15)
    char EvalPnlAmt          [ 16]; // �򰡼��ͱݾ� S9(15)
    char DtBnsplAmt          [ 17]; // �ϸŸż��ͱݾ� S9(16)
    char MthBnsplAmt         [ 17]; // ���Ÿż��ͱݾ� S9(16)
    char BnsplAmt            [ 16]; // �Ÿż��ͱݾ� S9(15)
    char AllPnlSum           [ 16]; // ��ü�����հ� S9(15)
    char PrdayCmpPnlAmt      [ 16]; // ���ϴ����ͱݾ� S9(15)
    char BalStat             [  5]; //  
} SSESQ110_OUT, *lpSSESQ110_OUT;
#define SZ_SSESQ110_OUT sizeof(SSESQ110_OUT)

typedef struct
{
    char RegMktNm            [ 40]; // ��Ͻ���� X(40)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char IsuNm               [ 40]; // ����� X(40)
    char PrdayHldQty         [ 16]; // ���Ϻ������� S9(15)
    char SellQty             [ 16]; // �ŵ����� S9(15)
    char BuyQty              [ 16]; // �ż����� S9(15)
    char CrdayHldQty         [ 16]; // ���Ϻ������� S9(15)
    char Curprc              [ 13]; // ���簡 S9(9).99
    char BookUprc            [ 15]; // ��δܰ� S9(9).9(4)
    char BookAmt             [ 16]; // ��αݾ� S9(15)
    char EvalAmt             [ 16]; // �򰡱ݾ� S9(15)
    char ErnRat              [ 12]; // ���ͷ� S9(4).9(6)
    char CrdayHldRat         [ 12]; // ���Ϻ������� S9(4).9(6)
    char BnsPnlAmt           [ 16]; // �Ÿż��ͱݾ� S9(15)
    char EvalPnlAmt          [ 16]; // �򰡼��ͱݾ� S9(15)
    char TrdCostAmt          [ 16]; // �ŷ����ݾ� S9(15)
    char BnsCostAmt          [ 16]; // �Ÿź��ݾ� S9(15)
} SSESQ110_SUB, *lpSSESQ110_SUB;
#define SZ_SSESQ110_SUB sizeof(SSESQ110_SUB)
//////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char In                  [  5]; //  
    char ClrgTp              [  1]; // ��걸�� X(1)
    char IvstfndCode         [ 12]; // �����ݵ��ڵ� X(12)
    char ClrgDt              [  8]; // ����� X(8)
    char ClrgTrxTp           [  1]; // ���ó������ X(1)
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char MgmtPsnEmpNo        [  9]; // �����ڻ����ȣ X(9)
} SOFFQ174_IN, *lpSOFFQ174_IN;
#define SZ_SOFFQ174_IN sizeof(SOFFQ174_IN)

typedef struct
{
    char Out                 [  5]; // X(5) 
    char OtptDt              [  8]; // ������� X(8)
    char TrnsrcvTme          [  9]; // �ۼ��Žð� X(9)
    char HanglIvstfndNm      [ 40]; // �ѱ������ݵ�� X(40)
    char RmndLoanAmt         [ 16]; // �ܿ�����ݾ� S9(15)
    char DstbBfCostAmt       [ 16]; // �й������ݾ� S9(15)
	char Hang				 [100];
    char stAsClrg            [  5]; //  
} SOFFQ174_OUT, *lpSOFFQ174_OUT;
#define SZ_SOFFQ174_OUT sizeof(SOFFQ174_OUT)

typedef struct
{
    char BrnNo               [  3]; // ������ȣ X(3)
    char BrnNm               [ 40]; // ������ X(40)
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char AcntNm              [ 40]; // ���¸� X(40)
    char ClrgBnsPrc          [ 20]; // ���ŸŰ� S9(8).9(10)
    char ClrgBoaPrc          [ 20]; // ����ǥ�� S9(8).9(10)
    char TrdAmt              [ 16]; // �ŷ��ݾ� S9(15)
    char TrdQty              [ 16]; // �ŷ����� S9(15)
    char BoaAmt              [ 16]; // ��ǥ�ݾ� S9(15)
    char TrdNo               [ 10]; // �ŷ���ȣ S9(9)
    char Ictax               [ 16]; // �ҵ漼 S9(15)
    char Ihtax               [ 16]; // �ֹμ� S9(15)
    char BalUnit             [ 16]; // �ܰ��¼� S9(15)
    char TaxBfAmt            [ 16]; // �����ݾ� S9(15)
    char TaxAfAmt            [ 16]; // ���ıݾ� S9(15)
    char BalQty              [ 16]; // �ܰ���� S9(15)
    char IvstfndCode2        [ 12]; // �����ݵ��ڵ�2 X(12)
    char FundNm              [ 40]; // �ݵ�� X(40)
    char DecBoaAmt2010       [ 16]; // �ؿ��ݵ� 2010��
    char OfstMchndCmsnAmt    [ 16]; // �����Ǹż����� S9(15)
    char OfstCdscHldbkBoaAmt [ 16]; // ����CDSC������ǥ�ݾ� S9(15)
    char OfstBoaHldbkAmt     [ 16]; // ������ǥ�����ݾ� S9(15)
    char OfstLossCrovrBoaAmt [ 16]; // �����ս��̿���ǥ�ݾ� S9(15)
    char AddLossCrovrBoaAmt  [ 16]; // ����ս��̿���ǥ�ݾ� S9(15)
    char AddBoaHldbkAmt      [ 16]; // �����ǥ�����ݾ� S9(15)
    char OpfirmCmsnAmt       [ 16]; // ��������� S9(15)
    char CmsnAmt             [ 16]; // ������ S9(15)
    char TrxTpNm1            [ 20]; // ó�����и�1 X(20)
    char TrdTpNm1            [ 20]; // �ŷ����и�1 X(20)
    char MgmtPsnEmpNo        [  9]; // �����ڻ����ȣ X(9)
    char MgmtPsnNm           [ 40]; // �����ڸ� X(40) 
	char CnvsEmpNo 			 [  9];
	char CnvsEmpNm			 [ 40]; 
	char PeclFundTp			 [  1];

} SOFFQ174_SUB, *lpSOFFQ174_SUB;
#define SZ_SOFFQ174_SUB sizeof(SOFFQ174_SUB)
/////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char In                  [  5]; //  
    char BaseDt              [  8]; // ������ X(8)
    char CpnTp               [  1]; // ��ǥ���� X(1)
    char FundOpAcntNo        [ 20]; // �ݵ�����¹�ȣ X(20)
    char ClrgPtnTp           [  1]; // ����������� X(1)
    char NewOldTp            [  1]; // �ű����� X(1)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char SettTp              [  1]; // �������� X(1)
    char QryTp               [  1]; // ��ȸ���� X(1)
} SSEBQ412_IN, *lpSSEBQ412_IN;
#define SZ_SSEBQ412_IN sizeof(SSEBQ412_IN)

typedef struct
{
    char Out                 [  5]; //  
    char CoNm                [ 40]; // ȸ��� X(40)
    char BaseDt              [  8]; // ������ X(8)
    char FundOpAcntNo        [ 20]; // �ݵ�����¹�ȣ X(20)
    char FundNm              [ 40]; // �ݵ�� X(40)
    char ClntMthAvrQty       [ 20]; // ������ռ��� S9(13).9(5)
    char Drtn                [ 17]; // �෹�̼� S9(5).9(10)
    char Drtn1               [ 17]; // �෹�̼�1 S9(5).9(10)
    char Crtdr               [ 17]; // �����෹�̼� S9(5).9(10)
    char SettTpNm            [ 41]; // �������и� X(41)
    char CouponRat           [ 18]; // ǥ������ S9.9(15)
    char PchsErnrat          [ 12]; // ���Լ��ͷ� S99.9(8)
    char Out2                [  5]; //  
} SSEBQ412_OUT, *lpSSEBQ412_OUT;
#define SZ_SSEBQ412_OUT sizeof(SSEBQ412_OUT)

typedef struct
{
    char TpNm2               [ 40]; // ���и�2 X(40)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char IsuNm               [ 40]; // ����� X(40)
    char IssuDt              [  8]; // ������ X(8)
    char DueDt               [  8]; // ������ X(8)
    char RemnTerm            [  6]; // �����Ⱓ S9(5)
    char BndClssNm           [ 40]; // ä�Ǻз��� X(40)
    char BndKindCodeNm       [ 40]; // ä�������ڵ�� X(40)
    char SmbndKindNm         [ 40]; // �Ҿ�ä�������� X(40)
    char BalQty              [ 16]; // �ܰ���� S9(15)
    char EvalErnrat1         [ 12]; // �򰡼��ͷ�1 S9(4).9(6)
    char EvalUprc1           [ 15]; // �򰡴ܰ�1 S9(9).9(4)
    char EvalAmt             [ 16]; // �򰡱ݾ� S9(15)
    char BookUprc            [ 15]; // ��δܰ� S9(9).9(4)
    char BookAmt             [ 16]; // ��αݾ� S9(15)
    char PassIntrstAmt       [ 16]; // ������ڱݾ� S9(15)
    char CorpTaxDps          [ 16]; // ���μ������� S9(15)
    char BpUprc              [ 15]; // BP�ܰ� S9(9).9(4)
    char BpErnrat            [ 12]; // BP���ͷ� S9(4).9(6)
    char RcvblIntrstAmt      [ 16]; // �̼����ڱݾ� S9(15)
    char AcmBookAmt          [ 16]; // ������αݾ� S9(15)
    char EvalPnlAmt          [ 16]; // �򰡼��ͱݾ� S9(15)
    char BuyErnrat           [ 12]; // �ż����ͷ� S9(4).9(6)
    char Drtn                [ 17]; // �෹�̼� S9(5).9(10)
    char ModDrtn             [ 17]; // �����෹�̼� S9(5).9(10)
    char Convexity           [ 17]; // ������Ƽ S9(5).9(10)
    char TpNm1               [ 40]; // ���и�1 X(40)
    char Tax                 [ 16]; // ���� S9(15)
    char Amt1                [ 16]; // �ݾ�1 S9(15)
    char Amt2                [ 16]; // �ݾ�2 S9(15)
    char CouponRat           [ 18]; // ǥ������ S9.9(15)
    char PchsErnrat          [ 12]; // ���Լ��ͷ� S99.9(8)
    char SoptQty             [ 16]; // �ǹ����� S9(15)
    char PldgQty             [ 16]; // �㺸���� S9(15)
    char CodeNm01            [ 40]; // �ڵ�� X(40)
    char CodeNm02            [ 40]; // �ڵ�� X(40)
    char CodeNm03            [ 40]; // �ڵ�� X(40)
    char CodeNm04            [ 40]; // �ڵ�� X(40)
    char RcvblAsmAmt         [ 16]; // �̼����ڴ���� S9(15)
    char BuyUprc             [ 15]; // �ż��ܰ� S9(9).9(4)
    char BuyDt               [  8]; // �ż��� X(8)
    char Amt3                [ 16]; // �ݾ�3 S9(15)
    char Amt4                [ 16]; // �ݾ�4 S9(15)
    char UndYn               [  1]; // �μ������� X(1)
    char UndDsgnNm           [ 40]; // �μ������� X(40)
    char PassDays            [  6]; // ����ϼ� S9(5)
    char AdmisAstTp          [  1]; // �����ڻ걸�� X(1)
    char UndTpNm             [  4]; // �μ������и� X(4)
    char DpslTpNm            [ 20]; // ó�б��и� X(20)
    char IttNm               [ 40]; // ����� X(40)
} SSEBQ412_SUB, *lpSSEBQ412_SUB;
#define SZ_SSEBQ412_SUB sizeof(SSEBQ412_SUB)
/////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char In                  [  5]; // X(5) 
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char BaseDt              [  8]; // ������ X(8)
    char QryTp               [  1]; // ��ȸ���� X(1)
    char IsuLgclssCode       [  2]; // �����з��ڵ� X(2)
    char IsuMdclssCode       [  2]; // �����ߺз��ڵ� X(2)
    char IsuSmclssCode       [  3]; // ����Һз��ڵ� X(3)
    char HanglEngTp          [  1]; // �ѿ����� X(1)
    char TrxTp               [  1]; // ó������ X(1)
} SSEOQ103_IN, *lpSSEOQ103_IN;
#define SZ_SSEOQ103_IN sizeof(SSEOQ103_IN)

typedef struct
{
    char Tot                 [  5]; // X(5) 
    char FutsSellQty         [ 16]; // �����ŵ����� S9(15)
    char FutsSellPnl         [ 16]; // �����ŵ����� S9(15)
    char FutsBuyQty          [ 16]; // �����ż����� S9(15)
    char FutsBuyPnl          [ 16]; // �����ż����� S9(15)
    char CallSellQty         [ 16]; // �ݸŵ����� S9(15)
    char CallSellPnl         [ 16]; // �ݸŵ����� S9(15)
    char CallBuyQty          [ 16]; // �ݸż����� S9(15)
    char CallBuyPnl          [ 16]; // �ݸż����� S9(15)
    char PutSellQty          [ 16]; // ǲ�ŵ����� S9(15)
    char PutSellPnl          [ 16]; // ǲ�ŵ����� S9(15)
    char PutBuyQty           [ 16]; // ǲ�ż����� S9(15)
    char PutBuyPnl           [ 16]; // ǲ�ż����� S9(15)
    char FutsUnsttQty        [ 16]; // �����̰������� S9(15)
    char FutsPnlSum          [ 16]; // ���������հ� S9(15)
    char OptUnsttQty         [ 16]; // �ɼǹ̰������� S9(15)
    char OptPnlSum           [ 16]; // �ɼǼ����հ� S9(15)
    char EvalPnlSum          [ 15]; // �򰡼����հ� S9(14)
    char FutsCtrctAmt        [ 16]; // ���������ݾ� S9(15)
    char CalloptCtrctAmt     [ 16]; // �ݿɼǾ����ݾ� S9(15)
    char PutoptCtrctAmt      [ 16]; // ǲ�ɼǾ����ݾ� S9(15)
    char AllCtrctAmt         [ 16]; // ��ü�����ݾ� S9(15)
    char Out                 [  5]; // X(5) 
} SSEOQ103_OUT, *lpSSEOQ103_OUT;
#define SZ_SSEOQ103_OUT sizeof(SSEOQ103_OUT)

typedef struct
{
    char FnoIsuNo            [ 32]; // �����ɼ������ȣ X(32)
    char ShtnHanglIsuNm      [ 40]; // �����ѱ������ X(40)
    char BnsTp               [  1]; // �Ÿű��� X(1)
    char TpNm1               [ 40]; // ���и�1 X(40)
    char BalQty              [ 16]; // �ܰ���� S9(15)
    char FnoAvrPrc           [ 19]; // ��հ� S9(9).9(8)
    char BookAmt             [ 16]; // ��αݾ� S9(15)
    char LqdtQty             [ 16]; // û����� S9(15)
    char Curprc              [ 13]; // ���簡 S9(9).99
    char BalEvalAmt          [ 16]; // �ܰ��򰡱ݾ� S9(15)
    char BalEvalPnlAmt       [ 16]; // �ܰ��򰡼��ͱݾ� S9(15)
} SSEOQ103_SUB, *lpSSEOQ103_SUB;
#define SZ_SSEOQ103_SUB sizeof(SSEOQ103_SUB)

//////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    char In                  [  5]; // X(5)
    char QryTp               [  1]; // ��ȸ���� X(1)
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char Pwd                 [  8]; // ��й�ȣ X(8)
    char QrySrtDt            [  8]; // ��ȸ������ X(8)
    char QryEndDt            [  8]; // ��ȸ������ X(8)
    char SrtNo               [ 10]; // ���۹�ȣ S9(9)
    char PdptnCode           [  2]; // ��ǰ�����ڵ� X(2)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char StnlnSeqTp          [  1]; // ���ļ������� X(1)
} SDPBQ001_IN, *lpSDPBQ001_IN;
#define SZ_SDPBQ001_IN sizeof(SDPBQ001_IN)

typedef struct
{
    char Out                 [  5]; // X(5)
    char AcntNm              [ 40]; // ���¸� X(40)
    char Out2                [  5]; // X(5)
} SDPBQ001_OUT, *lpSDPBQ001_OUT;
#define SZ_SDPBQ001_OUT sizeof(SDPBQ001_OUT)

typedef struct
{
    char TrdDate             [  8]; // �ŷ����� X(8)
    char TrdNo               [ 10]; // �ŷ���ȣ S9(9)
    char TrdAcntNo           [ 20]; // �ŷ����¹�ȣ X(20)
    char TrdTpNm             [ 20]; // �ŷ����� X(20)
    char SmryNo              [  4]; // �����ȣ X(4)
    char SmryNm              [ 40]; // ����� X(40)
    char CancTpNm            [ 20]; // ��ұ��� X(20)
    char TrdQty              [ 16]; // �ŷ����� S9(15)
    char Trtax               [ 16]; // �ŷ��� S9(15)
    char AdjstAmt            [ 16]; // ����ݾ� S9(15)
    char OvdSum              [ 16]; // ��ü�� S9(15)
    char DpsBfbalAmt         [ 16]; // ���������ܱݾ� S9(15)
    char SellPldgRfundAmt    [ 16]; // �ŵ��㺸��ȯ�� S9(15)
    char DpspdgLoanBfbalAmt  [ 16]; // ��Ź�㺸�������ܱݾ� S9(15)
    char TrdmdaNm            [ 40]; // �ŷ���ü�� X(40)
    char OrgTrdNo            [ 10]; // ���ŷ���ȣ S9(9)
    char IsuNm               [ 40]; // ����� X(40)
    char TrdUprc             [ 13]; // �ŷ��ܰ� S9(9).99
    char CmsnAmt             [ 16]; // ������ S9(15)
    char RfundDiffAmt        [ 16]; // ��ȯ���̱ݾ� S9(15)
    char RepayAmtSum         [ 16]; // �������հ� S9(15)
    char SecCrbalQty         [ 16]; // �������Ǳ��ܼ��� S9(15)
    char CslLoanRfundIntrstAmt[ 16]; // �ŵ���ݴ㺸�����ȯ���ڱݾ� S9(15)
    char DpspdgLoanCrbalAmt  [ 16]; // ��Ź�㺸������ܱݾ� S9(15)
    char TrxTime             [  9]; // ó���ð� X(9)
    char Inouno              [ 10]; // �ⳳ��ȣ S9(9)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char TrdAmt              [ 16]; // �ŷ��ݾ� S9(15)
    char TaxSumAmt           [ 16]; // �����հ�ݾ� S9(15)
    char IntrstUtlfee        [ 16]; // �����̿�� S9(15)
    char DvdAmt              [ 16]; // ���ݾ� S9(15)
    char RcvblOcrAmt         [ 16]; // �̼��߻��ݾ� S9(15)
    char TrxBrnNo            [  3]; // ó��������ȣ X(3)
    char TrxBrnNm            [ 40]; // ó�������� X(40)
    char DpspdgLoanAmt       [ 16]; // ��Ź�㺸����ݾ� S9(15)
    char DpspdgLoanRfundAmt  [ 16]; // ��Ź�㺸�����ȯ�ݾ� S9(15)
    char BasePrc             [ 13]; // ���ذ� S9(9).99
    char DpsCrbalAmt         [ 16]; // �����ݱ��ܱݾ� S9(15)
    char Boa                 [ 16]; // ��ǥ S9(15)
    char MnyoutAbleAmt       [ 16]; // ��ݰ��ɱݾ� S9(15)
    char BcrLoanOcrAmt       [ 16]; // �������Ǵ㺸����߻��� S9(15)
    char BcrLoanBfbalAmt     [ 16]; // �������Ǵ㺸�������ܱ� S9(15)
    char BnsBasePrc          [ 20]; // �Ÿű��ذ� S9(8).9(10)
    char TaxchrBasePrc       [ 20]; // �������ذ� S9(8).9(10)
    char TrdUnit             [ 16]; // �ŷ��¼� S9(15)
    char BalUnit             [ 16]; // �ܰ��¼� S9(15)
    char EvrTax              [ 16]; // ������ S9(15)
    char EvalAmt             [ 16]; // �򰡱ݾ� S9(15)
    char BcrLoanRfundAmt     [ 16]; // �������Ǵ㺸�����ȯ�� S9(15)
    char BcrLoanCrbalAmt     [ 16]; // �������Ǵ㺸������ܱ� S9(15)
    char AddMgnOcrTotamt     [ 16]; // �߰����űݹ߻��Ѿ� S9(15)
    char AddMnyMgnOcrAmt     [ 16]; // �߰��������űݹ߻��ݾ� S9(15)
    char AddMgnDfryTotamt    [ 16]; // �߰����űݳ����Ѿ� S9(15)
    char AddMnyMgnDfryAmt    [ 16]; // �߰��������űݳ��αݾ� S9(15)
    char BnsplAmt            [ 16]; // �Ÿż��ͱݾ� S9(15)
    char Ictax               [ 16]; // �ҵ漼 S9(15)
    char Ihtax               [ 16]; // �ֹμ� S9(15)
    char LoanDt              [  8]; // ������ X(8)
    char EtcBndInfo          [100]; // ��Ÿä������ X(100)
    char CrdtGrdVal          [ 40]; // �ſ��ް� X(40)
} SDPBQ001_SUB, *lpSDPBQ001_SUB;
#define SZ_SDPBQ001_SUB sizeof(SDPBQ001_SUB)
//////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char In                  [  5]; //  
    char BaseDt              [  8]; // ������ X(8)
    char FundOpAcntNo        [ 20]; // �ݵ�����¹�ȣ X(20)
    char ClrgTp              [  1]; // ��걸�� X(1)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char ExecTp              [  1]; // ü�ᱸ�� X(1)
    char SbrwTp              [  1]; // �������� X(1)
} SSEBQ414_IN, *lpSSEBQ414_IN;
#define SZ_SSEBQ414_IN sizeof(SSEBQ414_IN)

typedef struct
{
    char Out                 [  5]; //  
    char CoNm                [ 40]; // ȸ��� X(40)
    char TrxDt               [  8]; // ó���� X(8)
    char FundOpAcntNo        [ 20]; // �ݵ�����¹�ȣ X(20)
    char TpNm1               [ 40]; // ���и�1 X(40)
    char Out2                [  5]; //  
} SSEBQ414_OUT, *lpSSEBQ414_OUT;
#define SZ_SSEBQ414_OUT sizeof(SSEBQ414_OUT)

typedef struct
{
    char TpNm1               [ 40]; // ���и�1 X(40)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char IsuNm               [ 40]; // ����� X(40)
    char RfundDt             [  8]; // ��ȯ�� X(8)
    char RemnDays            [  6]; // �����ϼ� S9(5)
    char BndKindCodeNm       [ 40]; // ä�������ڵ�� X(40)
    char BalQty              [ 16]; // �ܰ���� S9(15)
    char EvalErnrat          [ 12]; // �򰡼��ͷ� S9(4).9(6)
    char EvalUprc            [ 15]; // �򰡴ܰ� S9(9).9(4)
    char EvalAmt             [ 16]; // �򰡱ݾ� S9(15)
    char BookAmt             [ 16]; // ��αݾ� S9(15)
    char EvalPnlAmt          [ 16]; // �򰡼��ͱݾ� S9(15)
    char SbrwBrwQty          [ 16]; // �������Լ��� S9(15)
    char SbrwSellQty         [ 16]; // �����ŵ����� S9(15)
    char SbrwSecEvalAmt      [ 16]; // ���������򰡱ݾ� S9(15)
    char StslTrdAmt          [ 16]; // �����ŷ��ݾ� S9(15)
    char StslBnsplAmt        [ 16]; // �����Ÿż��ͱݾ� S9(15)
    char CouponRat           [ 18]; // ǥ������ S9.9(15)
    char BuyDt               [  8]; // �ż��� X(8)
    char BuyUprc             [ 15]; // �ż��ܰ� S9(9).9(4)
    char RpBalQty            [ 16]; // RP�ܰ���� S9(15)
    char RpSellAmt           [ 16]; // RP�ŵ��ݾ� S9(15)
    char RpEvalAmt           [ 16]; // RP�򰡱ݾ� S9(15)
    char RpErnAmt            [ 16]; // RP���ͱݾ� S9(15)
    char Drtn                [ 17]; // �෹�̼� S9(5).9(10)
    char ModDrtn             [ 17]; // �����෹�̼� S9(5).9(10)
    char FundOpAcntNo        [ 20]; // �ݵ�����¹�ȣ X(20)
    char Convexity           [ 17]; // ������Ƽ S9(5).9(10)
    char Amt                 [ 16]; // �ݾ� S9(15)
	char Rcv				 [ 16];
} SSEBQ414_SUB, *lpSSEBQ414_SUB;
#define SZ_SSEBQ414_SUB sizeof(SSEBQ414_SUB)
//////////////////////////////////////////////////////////////////////////////////

typedef struct
{
	char In                  [  5]; //  
    char TrxTp               [  1]; // ó������ X(1)
    char IsuNo               [ 12]; // �����ȣ X(12)
    char FcstckIsuNm         [ 60]; // ��ȭ��������� X(60)
    char FcstckWarrantIsuNm  [ 60]; // ��ȭ���ǿ���Ʈ����� X(60)
    char FcstckPtnCode       [  2]; // ��ȭ���������ڵ� X(2)
    char LstdYn              [  1]; // ���忩�� X(1)
    char CncrnDomIsuNo       [ 12]; // ���ñ��������ȣ X(12)
    char FltnDt              [  8]; // ������ X(8)
    char DueDt               [  8]; // ������ X(8)
    char StkXchgRat          [ 15]; // �ֽı�ȯ���� S9(9).9(4)
    char DrXchgRat           [ 15]; // ��Ź������ȯ���� S9(9).9(4)
    char MinTrdAbleAmt       [ 16]; // �ּҰŷ����ɱݾ� S9(15)
    char FcstckXrcPrc        [ 15]; // ��ȭ������簡 S9(9).9(4)
    char FcurrFxdXchrat      [ 11]; // ��ȭ����ȯ�� S9(5).9(4)
    char WonFxdXchrat        [ 11]; // ��ȭ����ȯ�� S9(5).9(4)
    char CntryNo             [  3]; // ������ȣ X(3)
    char CrcyCode            [  3]; // ��ȭ�ڵ� X(3)
    char IsuTrdTp            [  1]; // ����ŷ����� X(1)
    char FcstckFltnPrc       [ 15]; // ��ȭ���ǹ��డ S9(9).9(4)
    char FcstckParprc        [ 15]; // ��ȭ���Ǿ׸鰡 S9(9).9(4)
    char FltnPsnLgclssCode   [  2]; // �����ڴ�з��ڵ� X(2)
    char FltnPsnNm           [ 40]; // �����ڸ� X(40)
    char FcstckMprc          [ 15]; // ��ȭ���ǽð� S9(9).9(4)
    char IttCode             [  9]; // ����ڵ� S9(8)
    char CstdyIttCode        [  9]; // ��������ڵ� S9(8)
    char SeCode              [  3]; // ���ǰŷ����ڵ� X(3)
    char CmnCode             [ 12]; // �����ڵ� X(12)
    char MjorIsuTp           [  1]; // �ֿ����񱸺� X(1)
    char EvalPtn             [  1]; // �����μ��Ǻλ�ä������ X(1)
    char TrdUnitQty          [ 16]; // �ŷ��������� S9(15)
    char RsnTp               [  1]; // �������� X(1)
    char MktCode4            [  4]; // �����ڵ� X(4)
} SOFAT310_IN, *lpSOFAT310_IN;
#define SZ_SOFAT310_IN sizeof(SOFAT310_IN)

typedef struct
{
    char Out                 [  5]; //  
    char InptPsnId           [ 16]; // �Է���ID X(16)
    char TrxDate             [  8]; // ó������ X(8)
} SOFAT310_OUT, *lpSOFAT310_OUT;
#define SZ_SOFAT310_OUT sizeof(SOFAT310_OUT)
//////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    char In                  [  5]; // X(5)
	char AcntNo	[20]; //���¹�ȣ	X(20)
	char BaseDt	[8]; //������	X(8)
	char IsuLgclssCode[2]; //	�����з��ڵ�	X(2)
	char IsuMdclssCode[2]; //	�����ߺз��ڵ�	X(2)
} SSEOQ137_IN, *lpSSEOQ137_IN;
#define SZ_SSEOQ137_IN sizeof(SSEOQ137_IN)

typedef struct
{
	char Tot                 [  5]; // X(5) 
    char Amt11               [ 16]; // �ݾ�11 S9(15)
    char Amt12               [ 16]; // �ݾ�12 S9(15)
    char Amt13               [ 16]; // �ݾ�13 S9(15)
    char Amt21               [ 16]; // �ݾ�21 S9(15)
    char Amt22               [ 16]; // �ݾ�22 S9(15)
    char Amt23               [ 16]; // �ݾ�23 S9(15)
    char Amt31               [ 16]; // �ݾ�31 S9(15)
    char Amt32               [ 16]; // �ݾ�32 S9(15)
    char Amt33               [ 16]; // �ݾ�33 S9(15)
    char Amt41               [ 16]; // �ݾ�41 S9(15)
    char Amt42               [ 16]; // �ݾ�42 S9(15)
    char Amt43               [ 16]; // �ݾ�43 S9(15)
    char Amt51               [ 16]; // �ݾ�51 S9(15)
    char Amt52               [ 16]; // �ݾ�52 S9(15)
    char Amt53               [ 16]; // �ݾ�53 S9(15)
    char Amt61               [ 16]; // �ݾ�61 S9(15)
    char Amt62               [ 16]; // �ݾ�62 S9(15)
    char Amt63               [ 16]; // �ݾ�63 S9(15)
    char Amt71               [ 16]; // �ݾ�71 S9(15)
    char Amt72               [ 16]; // �ݾ�72 S9(15)
    char Amt73               [ 16]; // �ݾ�73 S9(15)
    char Amt81               [ 16]; // �ݾ�81 S9(15)
    char Amt83               [ 16]; // �ݾ�83 S9(15)
    char Out                 [  5]; // X(5) 
} SSEOQ137_OUT, *lpSSEOQ137_OUT;
#define SZ_SSEOQ137_OUT sizeof(SSEOQ137_OUT)

typedef struct
{
    char FnoIsuNo            [ 32]; // �����ɼ������ȣ X(32)
    char IsuNm               [ 40]; // ����� X(40)
    char BnsTp               [  1]; // �Ÿű��� X(1)
    char BnsTpNm             [ 10]; // �Ÿű��� X(10)
    char BalQty              [ 16]; // �ܰ���� S9(15)
    char LqdtOrdAbleQty      [ 16]; // û���ֹ����ɼ��� S9(15)
    char AvrUprc             [ 13]; // ��մܰ� S9(9).99
    char CurPrc              [ 13]; // ���簡 S9(9).99
    char CtrctAmt            [ 16]; // �����ݾ� S9(15)
    char EvalAmt             [ 16]; // �򰡱ݾ� S9(15)
    char EvalPnlAmt          [ 16]; // �򰡼��ͱݾ� S9(15)
    char DeltaLmt            [ 16]; // ��Ÿ�ѵ� S9(15)
    char GmmaLmt             [ 16]; // �����ѵ� S9(15)
    char DeltaRisk           [ 16]; // ��Ÿ����ũ S9(15)
    char GmmaRisk            [ 16]; // ��������ũ S9(15)
    char VagaRisk            [ 16]; // ��������ũ S9(15)
    char DeepOTM             [ 16]; // �����ܰ��ݿɼǸŵ������ S9(15)
    char RiskAmt             [ 16]; // ����ݾ� S9(15)
} SSEOQ137_SUB, *lpSSEOQ137_SUB;
#define SZ_SSEOQ137_SUB sizeof(SSEOQ137_SUB)
////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    char In                  [  5]; // X(5)
    char QryDt [8]; //������   X(8)
} SONBQ708_IN, *lpSONBQ708_IN;
#define SZ_SONBQ708_IN sizeof(SONBQ708_IN)

typedef struct
{
    char Out2                [  5]; //  
    char DpstgMnyAsmAmt      [ 16]; // ��Ź���ݴ���ݾ� S9(15)
    char DpstgSubstAsmAmt    [ 16]; // ��Ź��봩��ݾ� S9(15)
    char CsgnMgnTotamt       [ 16]; // ��Ź���ű��Ѿ� S9(15)
    char BnsMgn              [ 16]; // �Ÿ����űݾ� S9(15)
    char Out3                [  5]; // X(5) 
    char DpstgMnyAsmAmt2      [ 16]; // ��Ź���ݴ���ݾ� S9(15)
    char DpstgSubstAsmAmt2    [ 16]; // ��Ź��봩��ݾ� S9(15)
    char CsgnMgnTotamt2       [ 16]; // ��Ź���ű��Ѿ� S9(15)
    char BnsMgn2              [ 16]; // �Ÿ����űݾ� S9(15)
    char Out4                [  5]; //  
    char DpstgMnyAsmAmt3      [ 16]; // ��Ź���ݴ���ݾ� S9(15)
    char DpstgSubstAsmAmt3    [ 16]; // ��Ź��봩��ݾ� S9(15)
    char CsgnMgnTotamt3       [ 16]; // ��Ź���ű��Ѿ� S9(15)
    char BnsMgn3              [ 16]; // �Ÿ����űݾ� S9(15)
    char Out                 [  5]; //     
} SONBQ708_OUT, *lpSONBQ708_OUT;
#define SZ_SONBQ708_OUT sizeof(SONBQ708_OUT)

typedef struct
{
    char AcntNo              [ 20]; // ���¹�ȣ X(20)
    char AcntNm              [ 40]; // ���¸� X(40)
    char DpstgMny            [ 16]; // ��Ź���� S9(15)
    char DpstgSubst          [ 16]; // ��Ź��� S9(15)
    char CsgnMgn             [ 16]; // ��Ź���űݾ� S9(15)
    char BnsMgn              [ 16]; // �Ÿ����űݾ� S9(15)
} SONBQ708_SUB, *lpSONBQ708_SUB;
#define SZ_SONBQ708_SUB sizeof(SONBQ708_SUB)

/////////////////////////////////////////////////////////////////////
typedef struct
{
    char In                  [  5]; // X(5)
    char    zAcntNo             [20];   // ���¹�ȣ
    char    zPwd                [ 8];   // ��й�ȣ
    char    zQryDt              [ 8];   // ����
} SOFAQ229_IN, *lpSOFAQ229_IN;
#define SZ_SOFAQ229_IN sizeof(SOFAQ229_IN)

typedef struct
{
    char    Out1                [ 5];   // ���ڵ尹��
    char    lWonDpsBalAmt       [16];   // ��ȭ�������ܰ�ݾ�
    char    lWonMgn             [16];   // ��ȭ���űݾ�
    char    lPsnOutAbleAmt      [16];   // ���Ⱑ�ɱݾ�
    char    Out                 [ 5];   // ���ڵ尹��
} SOFAQ229_OUT, *lpSOFAQ229_OUT;
#define SZ_SOFAQ229_OUT sizeof(SOFAQ229_OUT)

typedef struct
{
    char    zCrcyCode           [ 3];   // ��ȭ�ڵ�
    char    dFcurrDpsBalAmt     [17];   // ��ȭ�������ܰ�ݾ�
    char    dFcurrMgn           [17];   // ��ȭ���űݾ�
    char    dBaseXchrat         [11];   // ����ȯ��
    char    lWonDpsBalAmt       [16];   // ��ȭ�������ܰ�ݾ�
    char    lWonMgn             [16];   // ��ȭ���űݾ�
    char    dFcurrExecAmt       [17];   // �ŵ�ü��ݾ�
    char    lSellExecAmt        [16];   // �ŵ�ü��ݾ�(��ȭ)
} SOFAQ229_SUB, *lpSOFAQ229_SUB;
#define SZ_SOFAQ229_SUB sizeof(SOFAQ229_SUB)
/////////////////////////////////////////////////////////////////////

/***********************************************************************
 *
 *	object name : SONAT002F(GTS�� SONAT002�� ������, ���� ������ �����̸��� ���� GIS���� ����)
 *	prgram id	: 
 *	tr code		: 2503
 *	description	: �ؿ��ֽ� ���� ����ֹ�
 *
 ***********************************************************************/

#if 0
typedef struct	
{
	char	In[5];							/* ���ڵ尹�� */
	char	lOrgOrdNo[9];					/* ���ֹ���ȣ */
	char	zAcntNo[20];					/* ���¹�ȣ */
	char	zInptPwd[8];					/* �Էº�й�ȣ */
	char	zCntryCode[3];					// �����ڵ�
	char	zMarketCode[4];					// �����ڵ�
	char	zEcnID[10];						// ECN
	char	zIsuNo[12];						/* �����ȣ */
	char	lOrdQty[16];					/* �ֹ����� */
	char	zCommdaCode[2];					/* ��Ÿ�ü�ڵ� */
	char    CrcyCode[3];       				/* 08.10.27 : ��ȭ�ڵ� */
}   SONAT002F_IN, * lpSONAT002F_IN;
#define SZ_SONAT002F_IN				sizeof(SONAT002F_IN)

// SONAT002F_IN�� ���� ����
typedef	struct	
{
	char	In[5];							/* ���ڵ尹�� */
	char	lOrgOrdNo[9];					/* ���ֹ���ȣ */
	char	zAcntNo[20];					/* ���¹�ȣ */
	char	zInptPwd[8];					/* �Էº�й�ȣ */
	char	zCntryCode[3];					// �����ڵ�
	char	zMarketCode[4];					// �����ڵ�
	char	zEcnID[10];						// ECN
	char	zIsuNo[12];						/* �����ȣ */
	char	lOrdQty[16];					/* �ֹ����� */
	char	zCommdaCode[2];					/* ��Ÿ�ü�ڵ� */
	char    CrcyCode[3];       				/* 08.10.27 : ��ȭ�ڵ� */
	char	Out[5];							/* ���ڵ尹��  */
	char	lOrdNo[9];						/* �ֹ���ȣ */
	char	lPrntOrdNo[9];					/* ���ֹ���ȣ */
	char	zOrdTime[9];					/* �ֹ��ð� */
	char	zOrdMktCode[2];					/* �ֹ������ڵ� */
	char	zOrdPtnCode[2];					/* �ֹ������ڵ� */
	char	zShtnIsuNo[9];					/* ���������ȣ */
	char	zPrgmOrdprcPtnCode[2];			/* ���α׷�ȣ�������ڵ� */
	char	zMgempNo[9];					/* ���������ȣ */
	char	zBnsTp[1];						/* �Ÿű��� */
	char	zAcntNm[40];					/* ���¸� */
	char	zIsuNm[40];						/* ����� */
}   SONAT002F_OUT, * lpSONAT002F_OUT;
#define SZ_SONAT002F_OUT				sizeof(SONAT002F_OUT)

// ��� ���� ����
typedef	struct	
{
	char	sOrdxctPtnCode[2];				/* �ֹ�ü�������ڵ� */
	char	zCntryCode[3];					// �����ڵ�
	char	zMarketCode[4];					// �����ڵ�
	char	zEcnID[10];						// ECN
	char	zOrdPtnCode[2];					/* �ֹ������ڵ� */
	char	zAcntNo[20];					/* ���¹�ȣ */
	char	zIsuNo[12];						/* �����ȣ */
	char	zIsuNm[40];						/* ����� */
	char	lOrdNo[9];						/* �ֹ���ȣ */
	char	lPrntOrdNo[9];					/* ���ֹ���ȣ */
	char	lOrdQty[16];					/* �ֹ����� */
	char	dOrdPrc[17];					/* �ֹ��� */
	char	zOrdprcPtnCode[2];				/* ȣ�������ڵ� */
	char	sOrgOrdUnercQty[16];			/* ���ֹ���ü����� */
	char	sOrgOrdMdfyQty[16];				/* ���ֹ��������� */
	char	sOrgOrdCancQty[16];				/* ���ֹ���Ҽ��� */
	char	lOrdAmt[17];					/* �ֹ��ݾ� */
	char	zOrdTime[9];					/* �ֹ��ð� */
}   SONAT002F_RES, * lpSONAT002F_RES;
#define SZ_SONAT002F_RES				sizeof(SONAT002F_RES)
#endif




/***********************************************************************
 *	DATE        : 2020-07-14
 *	prgram id	: SSESQ201
 *	tr code		: 3984
 *  �ֽ��Ϻ��ݵ� ������Ȳ
 ***********************************************************************/
typedef struct	
{
	char	In           [5 ]; 
	char	FundOpAcntNo [20]; /*  �ݵ�����¹�ȣ*/
	char	QrySrtDt     [8 ]; /*  ��ȸ������      */
	char	QryEndDt     [8 ]; /*  ��ȸ������      */
	char	CreBaseCode  [2 ]; /*  ���������ڵ�    */
	char	IsuNo        [12]; /*  �����ȣ        */
}   SSESQ201_IN, * lpSSESQ201_IN;
#define SZ_SSESQ201_IN				sizeof(SSESQ201_IN)

typedef	struct	
{
	char  Out           [5 ];   /*                */
	char  FundNm        [40];   /*  �ݵ��        */
	char  FundDtCfBnspl [5 ];   /*                */
}   SSESQ201_OUT, * lpSSESQ201_OUT;
#define SZ_SSESQ201_OUT				sizeof(SSESQ201_OUT)

typedef	struct	
{
	char  ExecDt        [8 ];   /*  ü����        */
	char  BookQty       [16];   /*  ��μ���      */
	char  BookAmt       [16];   /*  ��αݾ�      */
	char  EvalAmt       [16];   /*  �򰡱ݾ�      */
	char  DtBnsplAmt    [17];   /*  �ϸŸż��ͱݾ�*/
	char  DtEvalPnlAmt  [17];   /*  ���򰡼��ͱݾ�*/
	char  DtTotPnlAmt   [17];   /*  ���Ѽ��ͱݾ�  */
	char  YearBnsplAmt  [17];   /*  ��Ÿż��ͱݾ�*/
	char  YearEvalPnlAmt[17];   /*  ���򰡼��ͱݾ�*/
	char  YearTotPnlAmt [17];   /*  ���Ѽ��ͱݾ�  */
}   SSESQ201_OUT_OCCR1, * lpSSESQ201_OUT_OCCR1;
#define SZ_SSESQ201_OUT_OCCR1				sizeof(SSESQ201_OUT_OCCR1)



/***********************************************************************
 *	DATE        : 2020-07-14
 *	prgram id	: SSESQ119
 *	tr code		: 7179
 *  �ڱ��ֽ��ݵ��ܰ�׼�����Ȳ
 ***********************************************************************/
typedef struct	
{
    char    In              [5   ]; /*                  */
    char    FundOpAcntNo    [20  ]; /* �ݵ�����¹�ȣ */
    char    SrtVal          [17+1]; /* ���۰�           */
    char    OpLmtAmt        [15+1]; /* ����ѵ��ݾ�     */
    char    BfDtBnsPnlamt   [15+1]; /* ���ϸŸż��ͱݾ� */
    char    BfDtEvalPnlAmt  [15+1]; /* �����򰡼��ͱݾ� */
    char    PrdayCmpMktAmt  [15+1]; /* ���ϴ��         */
    char    HldQty          [15+1]; /* ��������         */
    char    DtBnsplAmt      [16+1]; /* �ϸŸż��ͱݾ�   */
    char    MthBnsplAmt     [16+1]; /* ���Ÿż��ͱݾ�   */
    char    BnsplAmt        [15+1]; /* �Ÿż��ͱݾ�     */
    char    HldAmt          [15+1]; /* �����ݾ�         */
    char    EvalAmt         [15+1]; /* �򰡱ݾ�         */
    char    EvalPnlAmt      [15+1]; /* �򰡼��ͱݾ�     */
    char    EvalErnrat      [10+2]; /* �򰡼��ͷ�       */
    char    BuyLmtAmt       [15+1]; /* �ż��ѵ��ݾ�     */
    char    PnlSumAmt       [15+1]; /* �����հ�ݾ�     */
}   SSESQ119_IN, * lpSSESQ119_IN;
#define SZ_SSESQ119_IN				sizeof(SSESQ119_IN)

typedef struct	
{
    char    Out             [5   ]; /*                  */
    char    FundNm          [40  ]; /* �ݵ��           */
    char    OpLmtAmt        [15+1]; /* ����ѵ��ݾ�     */
    char    BfDtBnsPnlamt   [15+1]; /* ���ϸŸż��ͱݾ� */
    char    BfDtEvalPnlAmt  [15+1]; /* �����򰡼��ͱݾ� */
    char    PrdayCmpMktAmt  [15+1]; /* ���ϴ��         */
    char    HldQty          [15+1]; /* ��������         */
    char    DtBnsplAmt      [16+1]; /* �ϸŸż��ͱݾ�   */
    char    MthBnsplAmt     [16+1]; /* ���Ÿż��ͱݾ�   */
    char    BnsplAmt        [15+1]; /* �Ÿż��ͱݾ�     */
    char    HldAmt          [15+1]; /* �����ݾ�         */
    char    EvalAmt         [15+1]; /* �򰡱ݾ�         */
    char    EvalPnlAmt      [15+1]; /* �򰡼��ͱݾ�     */
    char    EvalErnrat      [10+2]; /* �򰡼��ͷ�       */
    char    BuyLmtAmt       [15+1]; /* �ż��ѵ��ݾ�     */
    char    PnlSumAmt       [15+1]; /* �����հ�ݾ�     */
    char    BalPnlSt        [5   ]; /*                  */
}   SSESQ119_OUT, * lpSSESQ119_OUT;
#define SZ_SSESQ119_OUT				sizeof(SSESQ119_OUT)

typedef struct	
{
    char    IsuNo           [12  ]; /* �����ȣ         */
    char    IsuNm           [40  ]; /* �����           */
    char    PrdayHldQty     [15+1]; /* ���Ϻ�������     */
    char    CrdayHldQty     [15+1]; /* ���Ϻ�������     */
    char    CrdayBuyExecQty [15+1]; /* ���ϸż�ü����� */
    char    CrdaySellExecQty[15+1]; /* ���ϸŵ�ü����� */
    char    OrdAbleQty      [15+1]; /* �ֹ����ɼ���     */
    char    BookUprc        [13+2]; /* ��δܰ�         */
    char    Curprc          [11+2]; /* ���簡           */
    char    SellUprc        [13+2]; /* �ŵ��ܰ�         */
    char    BuyUprc         [13+2]; /* �ż��ܰ�         */
    char    BnsplAmt        [15+1]; /* �Ÿż��ͱݾ�     */
    char    EvalErnrat      [10+2]; /* �򰡼��ͷ�       */
    char    EvalPnlAmt      [15+1]; /* �򰡼��ͱݾ�     */
    char    CrdayHldRat     [10+2]; /* ���Ϻ�������     */
    char    OpRat           [9 +1]; /* ������         */
    char    EvalAmt         [15+1]; /* �򰡱ݾ�         */
    char    BookAmt         [15+1]; /* ��αݾ�         */
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
    char    IsuNo           [12 +1]; /* �����ȣ         */
    char    IsuNm           [40 +1]; /* �����           */
    double    PrdayHldQty     ; /* ���Ϻ�������     */
    double    CrdayHldQty     ; /* ���Ϻ�������     */
    double    CrdayBuyExecQty ; /* ���ϸż�ü����� */
    double    CrdaySellExecQty; /* ���ϸŵ�ü����� */
    double    OrdAbleQty      ; /* �ֹ����ɼ���     */
    double    BookUprc        ; /* ��δܰ�         */
    double    Curprc          ; /* ���簡           */
    double    SellUprc        ; /* �ŵ��ܰ�         */
    double    BuyUprc         ; /* �ż��ܰ�         */
    double    BnsplAmt        ; /* �Ÿż��ͱݾ�     */
    double    EvalErnrat      ; /* �򰡼��ͷ�       */
    double    EvalPnlAmt      ; /* �򰡼��ͱݾ�     */
    double    CrdayHldRat     ; /* ���Ϻ�������     */
    double    OpRat           ; /* ������         */
    double    EvalAmt         ; /* �򰡱ݾ�         */
    double    BookAmt         ; /* ��αݾ�         */
}   SSESQ119_OUT_OCCR1_DB;
#define SZ_SSESQ119_OUT_OCCR1_DB sizeof(SSESQ119_OUT_OCCR1_DB)


#endif
