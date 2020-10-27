/*[
header:
	ITMS TABLE STRUCTURE
name:
	tbl_itms.h
synopsis:
	헤더화일
return:
	없음
description:
	헤더화일
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
    char    Last_Update[14+1];
}   ITMS0120;



#endif
