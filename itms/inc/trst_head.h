/*[
header:
	시스템에서 사용하는 Tr 구조
name:
	trst.h
synopsis:
	헤더화일
return:
	없음
description:
	헤더화일
remarks:
	없음
date:
	11/02/28
author:
	김동환
]*/

#ifndef _TRST_HEAD_H_
#define _TRST_HEAD_H_

#define	LENGTH	        5			// Data Length field length
#define	IN_KEY_LEN	    50			// Data Key
#define	KEY_LEN	        100			// Input Data + Data Key

#ifdef	TR_MAIN
char *KeyAttr[] = { "=", ">=", ">", "<>", "<=", "<", "LIKE" };
#else
extern char *KeyAttr[];
#endif

/****************************************************************************/
/* GIS 관련 공통 Header													    */
/****************************************************************************/

typedef struct  _Header_st
{
	char	Stx		[  1];			/* X(01) STX 0x02			*/
	char	Len		[LENGTH];		/* 9(05) DATA Length		*/
	char	TrCode	[  4];			/* 9(04) TR CODE			*/
	char	Pid		[  8];			/* 9(06) Process ID			*/
	char	Handle	[ 10];			/* 9(10) Client WINDOWS ID	*/
	char	PageId	[  1];			/* 9(01) Client Page ID		*/
	char	ContGb	[  1];			/* 9(01) 연속 구분			*/
									/* Server -=> PC			*/
									/* 0:없음, 1:다음     		*/
									/* 2:이전, 3:전후     		*/
	char	PcIpaddr[ 15];			/* X(15) Pc Ip Address		*/
	char	RetCode [  4];			/* 9(04) Return Code		*/
	char	TranGb  [  1];			/* X(01) 전송 구분			*/
									/*   :Tr 요구 Auto  Set  PC -=> Server  */
									/*  1:Tr 요구 AutoNoSet  PC -=> Server  */
									/*  0:Tr 응답Server -=> PC  */
									/*  7:AutoDataServer -=> PC */
									/*  8:SetServer -=> Server	*/
									/*  9:Reset              PC -=> Server  */
									/*  X:Set (RESET안함)    Server -=> Server*/
	char	ReqsGb  [  1];          /* 9(01) 데이타 요청 구분   */
									/*       PC -=> Server      */
									/*       0:처음, 1:다음     */
									/*       2:이전, 9:자동     */
	char	AccKind [  1];          /* 계좌관련TR여부 Y.해당 Etc.비해당 */

	char	DataOcc [  4];			/* (연속/요청)데이타의 갯수 */
	char	MediumGb[  2];			/* 매체구분 */
	char	IsKoscom[  1];			/* KOSCOM TR인가 : Y */
	char	WorkGbn [  1];			/* 작업구분 (1:입력, 2:조회, 3:삭제, 4:수정) */
	char	UserId  [  8];			// 사용자 로긴아이디
	char	Filler  [  3];
} Header_st, * lpHeader_st;
#define	SZ_Header	sizeof(Header_st)	/* 70 Bytes */

// 응답메시지
typedef struct _err_st
{
	Header_st				Head;
	char	Msg				[100];		// 메세지
	char	Etx				[ 1];		// ETX(0x03)
}	Err_st,	* lpErr_st,
 	Ret_st,	* lpRet_st;
#define	SZ_Err_st	sizeof(Err_st)
#define	SZ_Ret_st	sizeof(Err_st)


/****************************************************************************/
/* GIS 관련 공통 Header2												    */
/****************************************************************************/
// 사용자로긴
typedef struct _work_tr0001I_
{
	Header_st				Head;
	char	UserId				[ 8];	// 사용자ID
	char	Pswd				[12];	// 비밀번호
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0001I_st,	* lpTr0001I_st;
#define	SZ_Tr0001I	sizeof(Tr0001I_st)
typedef struct _work_tr0001O_
{
	Header_st				Head;
	char	UserName			[10];	// 사용자명
	char	UserGrp				[10];	// 유저권한대분류
	char	UserGrad			[ 2];	// 유저권한중분류
	char	UserLevel			[ 2];	// 유저권소한소분류
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0001O_st,	* lpTr0001O_st;
#define	SZ_Tr0001O	sizeof(Tr0001O_st)

// 메뉴요청
typedef struct _work_tr0002I_
{
	Header_st				Head;
	char	UserGrp				[10];	// 유저권한대분류
	char	UserGrad			[ 2];	// 유저권한중분류
	char	UserLevel			[ 2];	// 유저권소한소분류
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0002I_st,	* lpTr0002I_st;
#define	SZ_Tr0002I	sizeof(Tr0002I_st)

// 계좌명조회
typedef struct _work_tr0010I_
{
	Header_st				Head;
	char	AcNo		    [20];	// 계좌번호
	char	AcGubun			[ 1];	// 계좌구분
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0010I_st,	* lpTr0010I_st;
#define	SZ_Tr0010I	sizeof(Tr0010I_st)

typedef struct _work_tr0010O_
{
	Header_st				Head;
	char	AcName			[50];	// 사용자명
	char	Idno			[13];	// 주민번호
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0010O_st,	* lpTr0010O_st;
#define	SZ_Tr0010O	sizeof(Tr0010O_st)

/* 비밀번호변경 */
typedef struct _work_tr0020I_
{
	Header_st				Head;
	char	UserId				[ 8];	/* 사용자ID */
	char	Pswd				[10];	/* 비밀번호 */
	char	newPswd				[10];	/* 새로운비밀번호 */
	char	Etx					[ 1];	/* ETX(0x03) 	*/
}	Tr0020I_st,	* lpTr0020I_st;
#define	SZ_Tr0020I	sizeof(Tr0020I_st)

// 펀드종목조회
typedef struct _work_tr0030I_
{
	Header_st				Head;
	char	FundCode		[ 6];	// 계좌번호
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0030I_st,	* lpTr0030I_st;
#define	SZ_Tr0030I	sizeof(Tr0030I_st)

typedef struct _work_tr0030O_
{
	Header_st				Head;
	char	FundCode  	[ 6];	//펀드종목코드 
	char	FundName  	[40];	//펀드명 
	char	DivInvst  	[20];	//간접투자코드 
	char	DivOffr   	[10];	//모집유형 
	char	UcostBasic	[13];	//기준가 
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0030O_st,	* lpTr0030O_st;
#define	SZ_Tr0030O	sizeof(Tr0030O_st)

// 은행예금주성명조회
typedef struct _work_tr0031I_
{
	Header_st				Head;
	char	BnkCode			[ 3];	// 은행코드
	char	BnkAcntNo		[20];	// 은행계좌번호
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0031I_st,	* lpTr0031I_st;
#define	SZ_Tr0031I	sizeof(Tr0031I_st)

typedef struct _work_tr0031O_
{
	Header_st			Head;
	char	BnkNm  		[40];	//은행명 
	char	BnkBrnNm  	[40];	//은행지점명 
	char	DpsPsnNm  	[40];	//예금주명 
	char	BnkRspnsCode[4];	//은행응답코드 
	char	BnkMsgCnts  [100];	//은행메세지내용 
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0031O_st,	* lpTr0031O_st;
#define	SZ_Tr0031O	sizeof(Tr0031O_st)

// 적요명조회
typedef struct _work_tr0032I_
{
	Header_st				Head;
	char	Gubun			[ 1];	// 적요조회구분 0:기본조회
    char    Key             [IN_KEY_LEN];   // 연속시 키값 추가..
    char    Etx             [ 1];   // ETX(0x03)
}	Tr0032I_st,	* lpTr0032I_st;
#define	SZ_Tr0032I	sizeof(Tr0032I_st)

typedef struct _work_tr0032Occ_sub_
{
    char    Gubun            [1];    // 구분
    char    CodeDgst         [4];   // 적요코드
    char    NameDgst         [40];   // 적요명
}   Tr0032Occ_Sub_st,   * lpTr0032Occ_Sub_st;
#define SZ_Tr0032Occ_sub    sizeof(Tr0032Occ_Sub_st)

typedef struct _work_tr0032Occ_
{
    Header_st               Head;
    char    Key             [KEY_LEN];  // 연속시 키값 추가..
    lpTr0032Occ_Sub_st          Occ;
    char    Etx                 [ 1];
}   Tr0032Occ_st,   * lpTr0032Occ_st;
#define	SZ_Tr0032O	sizeof(Tr0032O_st)

/////////////////////////////////////////////////////////////////////
//종목조회
typedef struct _work_tr0033S_
{
    Header_st               Head;
    char    Fld1            [10];   //
    char    Key             [IN_KEY_LEN];   // 연속시 키값 추가..
    char    Etx             [ 1];   // ETX(0x03)
}   Tr0033S_st, * lpTr0033S_st;
#define SZ_Tr0033S  sizeof(Tr0033S_st)

typedef struct _work_tr0033S2Occ_sub_
{
    char Fld1[ 4];           //
    char Fld2[12];           //
    char Fld3[40];           //
}   Tr0033S2Occ_Sub_st,   * lpTr0033S2Occ_Sub_st;
#define SZ_Tr0033S2Occ_sub    sizeof(Tr0033S2Occ_Sub_st)

typedef struct _work_tr0033S2Occ_sum_
{
    char Fld1[10];           //
}   Tr0033S2Occ_Sum_st,   * lpTr0033S2Occ_Sum_st;
#define SZ_Tr0033S2Occ_sum    sizeof(Tr0033S2Occ_Sum_st)

typedef struct _work_tr0033S2Occ_
{
    Header_st               Head;
    char    Key             [KEY_LEN];  // 연속시 키값 추가..
    Tr0033S2Occ_Sum_st      Sum;
    lpTr0033S2Occ_Sub_st          Occ;
    char    Etx                 [ 1];
}   Tr0033S2Occ_st,   * lpTr0033S2Occ_st;

//계좌조회
typedef struct _work_tr0034S_
{
    Header_st               Head;
    // Head.WorkGbn = 작업구분 (1:파일목록,2.3.파일내용,4.파일수정)
    char    Fld1            [10];   //
    char    Key             [IN_KEY_LEN];   // 연속시 키값 추가..
    char    Etx             [ 1];   // ETX(0x03)
}   Tr0034S_st, * lpTr0034S_st;
#define SZ_Tr0034S  sizeof(Tr0034S_st)

typedef struct _work_tr0034SOcc_sub_
{
    char Fld1[20];           //
    char Fld2[60];           //
}   Tr0034SOcc_Sub_st,   * lpTr0034SOcc_Sub_st;
#define SZ_Tr0034SOcc_sub    sizeof(Tr0034SOcc_Sub_st)

typedef struct _work_tr0034SOcc_
{
    Header_st               Head;
    char    Key             [KEY_LEN];  // 연속시 키값 추가..
    lpTr0034SOcc_Sub_st          Occ;
    char    Etx                 [ 1];
}   Tr0034SOcc_st,   * lpTr0034SOcc_st;


///////////////////////////////////////////////////////////////////////


#endif /* _TRST_HEAD_H_ */
