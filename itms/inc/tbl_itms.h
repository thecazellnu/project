/*[
header:
	ITMS TABLE STRUCTURE
name:
	tbl_itms.h
synopsis:
	���ȭ��
return:
	����
description:
	���ȭ��
remarks:
date:
	2020/07/16
author:
]*/

#ifndef _TBL_ITMS_ST_H_
#define _TBL_ITMS_ST_H_


typedef struct
{
    char    Fund_Div   [2 +1];
    char    Fund_Nm    [40+1];
    char    Fund_Cd    [20+1];
    char    Use_Yn     [1 +1];
    char    User_ID    [16+1];
    char    User_BrChno[3 +1];
    char    Last_Update[14+1];
}   ITMS0100;

typedef struct
{
    char      Date          [8+1];
    char      FundCd        [20+1];
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
    char    Last_Update[14+1];
}   ITMS0110;

typedef struct
{
    char      Date          [8+1];
    char      FundCd        [20+1];
    char      FundNm        [40+1];
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
    char    Last_Update[14+1];
}   ITMS0120;



#endif
