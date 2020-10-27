/*[
header:
	�ý��ۿ��� ����ϴ� Tr ����
name:
	trst.h
synopsis:
	���ȭ��
return:
	����
description:
	���ȭ��
remarks:
	����
date:
	11/02/28
author:
	�赿ȯ
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
/* GIS ���� ���� Header													    */
/****************************************************************************/

typedef struct  _Header_st
{
	char	Stx		[  1];			/* X(01) STX 0x02			*/
	char	Len		[LENGTH];		/* 9(05) DATA Length		*/
	char	TrCode	[  4];			/* 9(04) TR CODE			*/
	char	Pid		[  8];			/* 9(06) Process ID			*/
	char	Handle	[ 10];			/* 9(10) Client WINDOWS ID	*/
	char	PageId	[  1];			/* 9(01) Client Page ID		*/
	char	ContGb	[  1];			/* 9(01) ���� ����			*/
									/* Server -=> PC			*/
									/* 0:����, 1:����     		*/
									/* 2:����, 3:����     		*/
	char	PcIpaddr[ 15];			/* X(15) Pc Ip Address		*/
	char	RetCode [  4];			/* 9(04) Return Code		*/
	char	TranGb  [  1];			/* X(01) ���� ����			*/
									/*   :Tr �䱸 Auto  Set  PC -=> Server  */
									/*  1:Tr �䱸 AutoNoSet  PC -=> Server  */
									/*  0:Tr ����Server -=> PC  */
									/*  7:AutoDataServer -=> PC */
									/*  8:SetServer -=> Server	*/
									/*  9:Reset              PC -=> Server  */
									/*  X:Set (RESET����)    Server -=> Server*/
	char	ReqsGb  [  1];          /* 9(01) ����Ÿ ��û ����   */
									/*       PC -=> Server      */
									/*       0:ó��, 1:����     */
									/*       2:����, 9:�ڵ�     */
	char	AccKind [  1];          /* ���°���TR���� Y.�ش� Etc.���ش� */

	char	DataOcc [  4];			/* (����/��û)����Ÿ�� ���� */
	char	MediumGb[  2];			/* ��ü���� */
	char	IsKoscom[  1];			/* KOSCOM TR�ΰ� : Y */
	char	WorkGbn [  1];			/* �۾����� (1:�Է�, 2:��ȸ, 3:����, 4:����) */
	char	UserId  [  8];			// ����� �α���̵�
	char	Filler  [  3];
} Header_st, * lpHeader_st;
#define	SZ_Header	sizeof(Header_st)	/* 70 Bytes */

// ����޽���
typedef struct _err_st
{
	Header_st				Head;
	char	Msg				[100];		// �޼���
	char	Etx				[ 1];		// ETX(0x03)
}	Err_st,	* lpErr_st,
 	Ret_st,	* lpRet_st;
#define	SZ_Err_st	sizeof(Err_st)
#define	SZ_Ret_st	sizeof(Err_st)


/****************************************************************************/
/* GIS ���� ���� Header2												    */
/****************************************************************************/
// ����ڷα�
typedef struct _work_tr0001I_
{
	Header_st				Head;
	char	UserId				[ 8];	// �����ID
	char	Pswd				[12];	// ��й�ȣ
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0001I_st,	* lpTr0001I_st;
#define	SZ_Tr0001I	sizeof(Tr0001I_st)
typedef struct _work_tr0001O_
{
	Header_st				Head;
	char	UserName			[10];	// ����ڸ�
	char	UserGrp				[10];	// �������Ѵ�з�
	char	UserGrad			[ 2];	// ���������ߺз�
	char	UserLevel			[ 2];	// �����Ǽ��ѼҺз�
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0001O_st,	* lpTr0001O_st;
#define	SZ_Tr0001O	sizeof(Tr0001O_st)

// �޴���û
typedef struct _work_tr0002I_
{
	Header_st				Head;
	char	UserGrp				[10];	// �������Ѵ�з�
	char	UserGrad			[ 2];	// ���������ߺз�
	char	UserLevel			[ 2];	// �����Ǽ��ѼҺз�
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0002I_st,	* lpTr0002I_st;
#define	SZ_Tr0002I	sizeof(Tr0002I_st)

// ���¸���ȸ
typedef struct _work_tr0010I_
{
	Header_st				Head;
	char	AcNo		    [20];	// ���¹�ȣ
	char	AcGubun			[ 1];	// ���±���
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0010I_st,	* lpTr0010I_st;
#define	SZ_Tr0010I	sizeof(Tr0010I_st)

typedef struct _work_tr0010O_
{
	Header_st				Head;
	char	AcName			[50];	// ����ڸ�
	char	Idno			[13];	// �ֹι�ȣ
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0010O_st,	* lpTr0010O_st;
#define	SZ_Tr0010O	sizeof(Tr0010O_st)

/* ��й�ȣ���� */
typedef struct _work_tr0020I_
{
	Header_st				Head;
	char	UserId				[ 8];	/* �����ID */
	char	Pswd				[10];	/* ��й�ȣ */
	char	newPswd				[10];	/* ���ο��й�ȣ */
	char	Etx					[ 1];	/* ETX(0x03) 	*/
}	Tr0020I_st,	* lpTr0020I_st;
#define	SZ_Tr0020I	sizeof(Tr0020I_st)

// �ݵ�������ȸ
typedef struct _work_tr0030I_
{
	Header_st				Head;
	char	FundCode		[ 6];	// ���¹�ȣ
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0030I_st,	* lpTr0030I_st;
#define	SZ_Tr0030I	sizeof(Tr0030I_st)

typedef struct _work_tr0030O_
{
	Header_st				Head;
	char	FundCode  	[ 6];	//�ݵ������ڵ� 
	char	FundName  	[40];	//�ݵ�� 
	char	DivInvst  	[20];	//���������ڵ� 
	char	DivOffr   	[10];	//�������� 
	char	UcostBasic	[13];	//���ذ� 
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0030O_st,	* lpTr0030O_st;
#define	SZ_Tr0030O	sizeof(Tr0030O_st)

// ���࿹���ּ�����ȸ
typedef struct _work_tr0031I_
{
	Header_st				Head;
	char	BnkCode			[ 3];	// �����ڵ�
	char	BnkAcntNo		[20];	// ������¹�ȣ
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0031I_st,	* lpTr0031I_st;
#define	SZ_Tr0031I	sizeof(Tr0031I_st)

typedef struct _work_tr0031O_
{
	Header_st			Head;
	char	BnkNm  		[40];	//����� 
	char	BnkBrnNm  	[40];	//���������� 
	char	DpsPsnNm  	[40];	//�����ָ� 
	char	BnkRspnsCode[4];	//���������ڵ� 
	char	BnkMsgCnts  [100];	//����޼������� 
	char	Etx					[ 1];	// ETX(0x03)
}	Tr0031O_st,	* lpTr0031O_st;
#define	SZ_Tr0031O	sizeof(Tr0031O_st)

// �������ȸ
typedef struct _work_tr0032I_
{
	Header_st				Head;
	char	Gubun			[ 1];	// ������ȸ���� 0:�⺻��ȸ
    char    Key             [IN_KEY_LEN];   // ���ӽ� Ű�� �߰�..
    char    Etx             [ 1];   // ETX(0x03)
}	Tr0032I_st,	* lpTr0032I_st;
#define	SZ_Tr0032I	sizeof(Tr0032I_st)

typedef struct _work_tr0032Occ_sub_
{
    char    Gubun            [1];    // ����
    char    CodeDgst         [4];   // �����ڵ�
    char    NameDgst         [40];   // �����
}   Tr0032Occ_Sub_st,   * lpTr0032Occ_Sub_st;
#define SZ_Tr0032Occ_sub    sizeof(Tr0032Occ_Sub_st)

typedef struct _work_tr0032Occ_
{
    Header_st               Head;
    char    Key             [KEY_LEN];  // ���ӽ� Ű�� �߰�..
    lpTr0032Occ_Sub_st          Occ;
    char    Etx                 [ 1];
}   Tr0032Occ_st,   * lpTr0032Occ_st;
#define	SZ_Tr0032O	sizeof(Tr0032O_st)

/////////////////////////////////////////////////////////////////////
//������ȸ
typedef struct _work_tr0033S_
{
    Header_st               Head;
    char    Fld1            [10];   //
    char    Key             [IN_KEY_LEN];   // ���ӽ� Ű�� �߰�..
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
    char    Key             [KEY_LEN];  // ���ӽ� Ű�� �߰�..
    Tr0033S2Occ_Sum_st      Sum;
    lpTr0033S2Occ_Sub_st          Occ;
    char    Etx                 [ 1];
}   Tr0033S2Occ_st,   * lpTr0033S2Occ_st;

//������ȸ
typedef struct _work_tr0034S_
{
    Header_st               Head;
    // Head.WorkGbn = �۾����� (1:���ϸ��,2.3.���ϳ���,4.���ϼ���)
    char    Fld1            [10];   //
    char    Key             [IN_KEY_LEN];   // ���ӽ� Ű�� �߰�..
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
    char    Key             [KEY_LEN];  // ���ӽ� Ű�� �߰�..
    lpTr0034SOcc_Sub_st          Occ;
    char    Etx                 [ 1];
}   Tr0034SOcc_st,   * lpTr0034SOcc_st;


///////////////////////////////////////////////////////////////////////


#endif /* _TRST_HEAD_H_ */
