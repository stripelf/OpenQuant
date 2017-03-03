#pragma once
#include <vector>
#include "ProtoDataStruct.h"


//////////////////////////////////////////////////////////////////////////
//��ȡ��������Э��, PROTO_ID_GET_BASIC_PRICE

struct	BasicPriceReqBody
{
	int nStockMarket;
	std::string strStockCode;
};

struct BasicPriceAckBody
{
	int nHigh;
	int nOpen;
	int nClose;
	int nLastClose;
	int nLow;
	int nCur;
	INT64 nVolume;
	INT64 nTurnover;
	INT64 nLotSize;

	int nStockMarket;
	std::string strStockCode;
	DWORD dwTime;
};

struct	BasicPrice_Req
{
	ProtoHead			head;
	BasicPriceReqBody	body;
};

struct	BasicPrice_Ack
{
	ProtoHead				head;
	BasicPriceAckBody		body;
};


//////////////////////////////////////////////////////////////////////////
//��ȡ������ϢЭ��, PROTO_ID_GET_GEAR_PRICE

struct	GearPriceReqBody
{
	int nNum;
	int nStockMarket;	
	std::string strStockCode;	
};

struct GearPriceAckItem
{
	int nBuyOrder;
	int nSellOrder;
	int nBuyPrice;
	int nSellPrice;
	INT64 nBuyVolume;
	INT64 nSellVolume;
};

typedef std::vector<GearPriceAckItem>	VT_GEAR_PRICE;

struct GearPriceAckBody 
{
	int nStockMarket;
	std::string strStockCode;
	VT_GEAR_PRICE vtGear;
};

struct	GearPrice_Req
{
	ProtoHead			head;
	GearPriceReqBody	body;
};

struct	GearPrice_Ack
{
	ProtoHead			head;
	GearPriceAckBody	body;
};

//////////////////////////////////////////////////////////////////////////
//��ȡ��ʱ����Э��, PROTO_ID_QT_GET_RT_DATA

struct	RTDataReqBody
{
	int nStockMarket;	
	std::string strStockCode;
};

struct RTDataAckItem
{
	int   nDataStatus; 
	std::wstring strTime; 
	DWORD dwOpenedMins;  //���̵ڶ��ٷ���  

	int   nCurPrice;
	DWORD nLastClosePrice; //��������̼� 

	int   nAvgPrice;

	INT64 ddwTDVolume;
	INT64 ddwTDValue;  
};

typedef std::vector<RTDataAckItem>	VT_RT_DATA;

struct RTDataAckBody 
{
	int nNum;
	int nStockMarket;
	std::string strStockCode;
	VT_RT_DATA vtRTData;
};

struct RTData_Req
{
	ProtoHead			head;
	RTDataReqBody		body;
};

struct RTData_Ack
{
	ProtoHead			head;
	RTDataAckBody		body;
};

//////////////////////////////////////////////////////////////////////////
//��ȡ��ǰK������Э��

struct	KLDataReqBody
{
	int nRehabType;
	int nKLType;
	int nStockMarket;
	int nNum;
	std::string strStockCode;
};

struct KLDataAckItem
{
	int   nDataStatus; 
	std::wstring strTime; 
	INT64   nOpenPrice;
	INT64   nClosePrice;
	INT64   nHighestPrice;
	INT64   nLowestPrice;
	int   nPERatio; //��ӯ��(��λС��)
	int   nTurnoverRate;//������(���ɼ�ָ������/��/��K��)
	INT64 ddwTDVol; 
	INT64 ddwTDVal;
};

typedef std::vector<KLDataAckItem>	VT_KL_DATA;

struct KLDataAckBody 
{
	int nRehabType;
	int nKLType;
	int nStockMarket;
	std::string strStockCode;
	VT_KL_DATA vtKLData;
};

struct KLData_Req
{
	ProtoHead			head;
	KLDataReqBody		body;
};

struct KLData_Ack
{
	ProtoHead			head;
	KLDataAckBody		body;
};

/////////////////////////////////////////
//��Ʊ����Э��, PROTO_ID_QT_SUBSTOCK

struct StockSubReqBody
{
	int nStockSubType;
	int nStockMarket;
	std::string strStockCode;
};

struct StockSubAckBody
{
	int nStockSubType;
	int nStockMarket;
	std::string strStockCode;
};

struct StockSub_Req
{
	ProtoHead		head;
	StockSubReqBody	body;
};

struct StockSub_Ack
{
	ProtoHead			head;
	StockSubAckBody		body;
};

/////////////////////////////////////////
//��Ʊ������Э��, PROTO_ID_QT_UNSUBSTOCK

struct StockUnSubReqBody
{
	int nStockSubType;
	int nStockMarket;
	std::string strStockCode;
};

struct StockUnSubAckBody
{
	int nStockSubType;
	int nStockMarket;
	std::string strStockCode;
};

struct StockUnSub_Req
{
	ProtoHead			head;
	StockUnSubReqBody	body;
};

struct StockUnSub_Ack
{
	ProtoHead				head;
	StockUnSubAckBody		body;
};

/////////////////////
////��ѯ���Ľӿ�PROTO_ID_QT_QueryStockSub
struct QueryStockSubReqBody
{

};

struct SubInfoAckItem
{
	int nStockSubType;
	int nStockMarket;
	std::wstring strStockCode;
};

typedef std::vector<SubInfoAckItem>	VT_SUB_INFO;

struct QueryStockSubAckBody
{
	VT_SUB_INFO vtSubInfo;
};

struct QueryStockSub_Req
{
	ProtoHead					head;
	QueryStockSubReqBody		body;
};

struct QueryStockSub_Ack
{
	ProtoHead					head;
	QueryStockSubAckBody		body;
};


//////////////////////////////////////////////////////////////////////////
//������Э��, PROTO_ID_QT_GET_TICKER

struct	TickerReqBody
{
	int nGetTickNum;
	int nStockMarket;	// enum StockMktType
	INT64 nSequence;	// Ŀǰû��������
	std::string strStockCode;	
};

struct TickerAckItem
{
	int nPrice;	
	int nDealType;	
	INT64 nSequence;
	INT64 nVolume;
	INT64 nTurnover;
	std::string strTickTime;
};

typedef std::vector<TickerAckItem>	VT_TICKER_DATA;

struct TickerAckBody 
{
	int nStockMarket;	// enum StockMktType
	std::string strStockCode;
	INT64 nNextSequence;// Ŀǰû��������
	VT_TICKER_DATA vtTicker;
};

struct	Ticker_Req
{
	ProtoHead		head;
	TickerReqBody	body;
};

struct	Ticker_Ack
{
	ProtoHead		head;
	TickerAckBody	body;
};


//////////////////////////////////////////////////////////////////////////
//���ָ��ʱ��εĽ������б�, PROTO_ID_QT_GET_TRADE_DATE

struct	TradeDateReqBody
{
	int nStockMarket;	// enum StockMktType	
	std::string strStartDate;//"YYYY-MM-DD"�����ַ�����ʾEnd��ǰһ��
	std::string strEndDate;//"YYYY-MM-DD"�����ַ�����ʾ����
};

//"YYYY-MM-DD"
typedef std::vector<std::string>	VT_TRADE_DATE; 

struct TradeDateAckBody 
{
	int nStockMarket;	// enum StockMktType	
	std::string strStartDate;
	std::string strEndDate;
	VT_TRADE_DATE vtTradeDate;
};

struct	TradeDate_Req
{
	ProtoHead			head;
	TradeDateReqBody	body;
};

struct	TradeDate_Ack
{
	ProtoHead			head;
	TradeDateAckBody	body;
};



//////////////////////////////////////////////////////////////////////////
//���ָ�����͵Ĺ�Ʊ��Ϣ, PROTO_ID_QT_GET_STOCK_LIST
struct	StockListReqBody
{
	int nStockMarket;	// enum StockMktType
	int nSecurityType;  // enum PluginSecurityType	
};

struct StockListAckItem
{
	INT64 nStockID;
	int  nLotSize;	
	int  nSecurityType;  // enum PluginSecurityType	
	std::string strSimpName;
	std::string strStockCode;	
};

typedef std::vector<StockListAckItem>	VT_STOCK_INFO;

struct StockListAckBody 
{
	int nStockMarket;	// enum StockMktType	
	VT_STOCK_INFO vtStockList;
};

struct	StockList_Req
{
	ProtoHead			head;
	StockListReqBody	body;
};

struct	StockList_Ack
{
	ProtoHead			head;
	StockListAckBody	body;
};

//////////////////////////////////////////////////////////////////////////
//���ָ�����͵Ĺ�Ʊ��Ϣ, PROTO_ID_QT_GET_SNAPSHOT
struct SnapshotReqItem
{
	int nStockMarket; // enum StockMktType
	std::string strStockCode;	
};

typedef std::vector<SnapshotReqItem> VT_REQ_SNAPSHOT;

struct	SnapshotReqBody
{
	VT_REQ_SNAPSHOT vtReqSnapshot;
};

struct SnapshotAckItem
{
	INT64 nStockID;
	std::string strStockCode;
	int nStockMarket; // enum StockMktType
	int instrument_type;// enum PluginSecurityType	
	INT64 last_close_price;
	INT64 nominal_price;
	INT64 open_price;
	INT64  update_time;
	INT64  suspend_flag;
	INT64  listing_status;
	INT64  listing_date;
	INT64 shares_traded;
	INT64 turnover;
	INT64 highest_price;
	INT64 lowest_price;
	int turnover_ratio;
	int ret_err;//0Ϊ�ɹ�
};

typedef std::vector<SnapshotAckItem>	VT_ACK_SNAPSHOT;

struct SnapshotAckBody 
{	
	VT_ACK_SNAPSHOT vtSnapshot;
};

struct	Snapshot_Req
{
	ProtoHead		head;
	SnapshotReqBody	body;
};

struct	Snapshot_Ack
{
	ProtoHead		head;
	SnapshotAckBody	body;
};

//////////////////////////////////////////////////////////////////////////
//��������, PROTO_ID_QT_GET_STOCK_INFO

struct BatchBasicReqItem
{
	int nStockMarket;
	std::string strStockCode;	
};

typedef std::vector<BatchBasicReqItem>	VT_REQ_BATCHBASIC;

struct BatchBasicReqBody
{
	VT_REQ_BATCHBASIC vtReqBatchBasic;
};

struct BatchBasicAckItem
{
	int nStockMarket;
	std::string strStockCode;	

	int nHigh;
	int nOpen;
	int nLastClose;
	int nLow;
	int nCur;
	int nSuspension;
	int nTurnoverRate;
	INT64 nVolume;
	INT64 nValue;
	INT64 nAmpli;
	std::wstring strDate; 
	std::wstring strTime;
	std::wstring strListTime; 
};

typedef std::vector<BatchBasicAckItem>	VT_ACK_BATCHBASIC;

struct BatchBasicAckBody 
{	
	VT_ACK_BATCHBASIC vtAckBatchBasic;
};

struct BatchBasic_Req
{
	ProtoHead			head;
	BatchBasicReqBody	body;
};

struct BatchBasic_Ack
{
	ProtoHead			head;
	BatchBasicAckBody	body;
};

//�����ʷK��, PROTO_ID_QT_GET_HISTORYKL

struct	HistoryKLReqBody
{
	int nRehabType;
	int nKLType;
	int nStockMarket;
	std::string strStockCode;
	std::string strStartDate;
	std::string strEndDate;
};

struct HistoryKLAckItem
{
	std::wstring strTime; 
	INT64   nOpenPrice;
	INT64   nClosePrice;
	INT64   nHighestPrice;
	INT64   nLowestPrice;
	int   nPERatio; //��ӯ��(��λС��)
	int   nTurnoverRate;//������(���ɼ�ָ������/��/��K��)
	INT64 ddwTDVol; 
	INT64 ddwTDVal;
};

typedef std::vector<HistoryKLAckItem>	VT_HISTORY_KL;

struct HistoryKLAckBody 
{
	int nRehabType;
	int nKLType;
	int nStockMarket;
	std::string strStockCode;
	std::string strStartDate;
	std::string strEndDate;
	VT_HISTORY_KL vtHistoryKL;
};

struct HistoryKL_Req
{
	ProtoHead				head;
	HistoryKLReqBody		body;
};

struct HistoryKL_Ack
{
	ProtoHead				head;
	HistoryKLAckBody		body;
};

//////////////////////////////////////////////////////////////////////////
//��Ȩ, PROTO_ID_QT_GET_EXRIGHTINFO
struct ExRightInfoReqItem
{
	int nStockMarket; // enum StockMktType
	std::string strStockCode;	
};

typedef std::vector<ExRightInfoReqItem> VT_REQ_EXRIGHTINFO;

struct ExRightInfoReqBody
{
	VT_REQ_EXRIGHTINFO vtReqExRightInfo;
};

struct ExRightInfoAckItem
{
	int nStockMarket; // enum StockMktType
	std::string strStockCode;	
	std::string str_ex_date;    // ��Ȩ��Ϣ����, ����20160615
	
	INT32 split_ratio;//��Ϲɱ���
	INT64 per_cash_div;//�ֽ�����
	INT32 per_share_ratio;//�͹ɱ���
	INT32 per_share_trans_ratio;//ת���ɱ���
	INT32 allotment_ratio;//��ɱ���
	INT64 allotment_price;//��ɼ�
	INT32 stk_spo_ratio;//��������
	INT64 stk_spo_price;//�����۸�

	// result_self
	INT64 fwd_factor_a;
	INT64 fwd_factor_b;
	INT64 bwd_factor_a;
	INT64 bwd_factor_b;

	// ���������ı�����
	//std::wstring str_sc_txt;

	// ���������ı�����
	//std::wstring str_tc_txt;
};

typedef std::vector<ExRightInfoAckItem>	VT_ACK_EXRIGHTINFO;

struct ExRightInfoAckBody 
{	
	VT_ACK_EXRIGHTINFO vtAckExRightInfo;
};

struct	ExRightInfo_Req
{
	ProtoHead		head;
	ExRightInfoReqBody	body;
};

struct ExRightInfo_Ack
{
	ProtoHead		head;
	ExRightInfoAckBody	body;
};

/////////////////////////////////////////
//����Э��, PROTO_ID_QT_PushStockData

struct PushStockDataReqBody
{
	int nStockPushType;
	int nStockMarket;
	std::string strStockCode;
};

struct PushStockDataAckBody
{
	int nStockPushType;
	int nStockMarket;
	std::string strStockCode;
};

struct PushStockData_Req
{
	ProtoHead		head;
	PushStockDataReqBody	body;
};

struct PushStockData_Ack
{
	ProtoHead					head;
	PushStockDataAckBody		body;
};


//���ͱ���, PROTO_PUSH_BATCHPRICE

struct PushBatchBasicReqItem
{
	int nStockMarket;
	std::string strStockCode;
};

typedef std::vector<PushBatchBasicReqItem>	VT_REQ_PUSHBATCHBASIC;

struct PushBatchBasicReqBody
{
	VT_REQ_PUSHBATCHBASIC vtReqBatchBasic;
};

struct PushBatchBasicAckItem
{
	int nStockMarket;
	std::string strStockCode;

	int nHigh;
	int nOpen;
	int nLastClose;
	int nLow;
	int nCur;
	int nSuspension;
	int nTurnoverRate;
	INT64 nVolume;
	INT64 nValue;
	INT64 nAmpli;
	std::wstring strDate;
	std::wstring strTime;
	std::wstring strListTime;
};

typedef std::vector<PushBatchBasicAckItem>	VT_ACK_PUSHBATCHBASIC;

struct PushBatchBasicAckBody
{
	VT_ACK_PUSHBATCHBASIC vtAckBatchBasic;
};

struct PushBatchBasic_Req
{
	ProtoHead			head;
	PushBatchBasicReqBody	body;
};

struct PushBatchBasic_Ack
{
	ProtoHead			head;
	PushBatchBasicAckBody	body;
};

//////////////////////////////////////////////////////////////////////////
//���Ͱ���, PROTO_ID_PUSH_GERA

struct	PushGearPriceReqBody
{
	int nNum;
	int nStockMarket;
	std::string strStockCode;
};

struct PushGearPriceAckItem
{
	int nBuyOrder;
	int nSellOrder;
	int nBuyPrice;
	int nSellPrice;
	INT64 nBuyVolume;
	INT64 nSellVolume;
};

typedef std::vector<PushGearPriceAckItem>	VT_GEAR_PRICE_PUSH;

struct PushGearPriceAckBody
{
	int nStockMarket;
	std::string strStockCode;
	VT_GEAR_PRICE_PUSH vtGear;
};

struct	PushGearPrice_Req
{
	ProtoHead			head;
	PushGearPriceReqBody	body;
};

struct	PushGearPrice_Ack
{
	ProtoHead			head;
	PushGearPriceAckBody	body;
};

//////////////////////////////////////////////////////////////////////////
//�������Э��, PROTO_ID_PUSH_TICKER

struct	PushTickerReqBody
{
	int nGetTickNum;
	int nStockMarket;	// enum StockMktType
	INT64 nSequence;	// Ŀǰû��������
	std::string strStockCode;
};

struct PushTickerAckItem
{
	int nPrice;
	int nDealType;
	INT64 nSequence;
	INT64 nVolume;
	INT64 nTurnover;
	std::string strTickTime;
};

typedef std::vector<PushTickerAckItem>	VT_TICKER_DATA_PUSH;

struct PushTickerAckBody
{
	int nStockMarket;	// enum StockMktType
	std::string strStockCode;
	INT64 nNextSequence;// Ŀǰû��������
	VT_TICKER_DATA_PUSH vtTicker;
};

struct	PushTicker_Req
{
	ProtoHead		head;
	PushTickerReqBody	body;
};

struct	PushTicker_Ack
{
	ProtoHead		head;
	PushTickerAckBody	body;
};

//////////////////////////////////////////////////////////////////////////
//����K������Э��

struct	PushKLDataReqBody
{
	int nRehabType;
	int nKLType;
	int nStockMarket;
	int nNum;
	std::string strStockCode;
};

struct PushKLDataAckItem
{
	std::wstring strTime;
	INT64   nOpenPrice;
	INT64   nClosePrice;
	INT64   nHighestPrice;
	INT64   nLowestPrice;
	int   nPERatio; //��ӯ��(��λС��)
	int   nTurnoverRate;//������(���ɼ�ָ������/��/��K��)
	INT64 ddwTDVol;
	INT64 ddwTDVal;
};

typedef std::vector<PushKLDataAckItem>	VT_KL_DATA_PUSH;

struct PushKLDataAckBody
{
	int nRehabType;
	int nKLType;
	int nStockMarket;
	std::string strStockCode;
	VT_KL_DATA_PUSH vtKLData;
};

struct PushKLData_Req
{
	ProtoHead			head;
	PushKLDataReqBody		body;
};

struct PushKLData_Ack
{
	ProtoHead			head;
	PushKLDataAckBody		body;
};

//////////////////////////////////////////////////////////////////////////
//���ͷ�ʱ����Э��

struct	PushRTDataReqBody
{
	int nStockMarket;
	std::string strStockCode;
};

struct PushRTDataAckItem
{
	int   nDataStatus;
	std::wstring strTime;
	DWORD dwOpenedMins;  //���̵ڶ��ٷ���  

	int   nCurPrice;
	DWORD nLastClosePrice; //��������̼� 

	int   nAvgPrice;

	INT64 ddwTDVolume;
	INT64 ddwTDValue;
};

typedef std::vector<PushRTDataAckItem>	VT_RT_DATA_PUSH;

struct PushRTDataAckBody
{
	int nNum;
	int nStockMarket;
	std::string strStockCode;
	VT_RT_DATA_PUSH vtRTData;
};

struct PushRTData_Req
{
	ProtoHead			head;
	PushRTDataReqBody		body;
};

struct PushRTData_Ack
{
	ProtoHead			head;
	PushRTDataAckBody		body;
};