// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include "WTL/atlddx.h"
#include "StockComEvent.h"

class CMainDlg : public CAxDialogImpl<CMainDlg>, public CWinDataExchange<CMainDlg>
{
protected:

	///  �������COM����
	IStockTradePtr		m_spiTrade;
	/// �Ƿ�������ȯ�˺�
	BOOL				m_bRZRQ;

	/// ���ײ�ѯ����
	CComboBox		m_wndTradeList;
	/// ��ʷ��������
	CComboBox		m_wndHistoryList;
	/// ȯ������
	CComboBox		m_wndBrokerType;
	/// �˺�����
	CComboBox		m_wndAccountType;

	/// ���׽ӿ��¼�COOKIE����
	DWORD							m_nTradeEventCookie;
	/// ���׽ӿ��¼���������
	CComObject<CStockComEvent>*		m_spiTradeClientEvent;

	/// �����¼�֪ͨ
	void AdviseTradeClient();
	/// �Ͽ��¼�֪ͨ
	void UnAdviseTradeClient();

	/// �ͷ����
	void ReleaseCom();

	///��ý�������
	ITradeRecordPtr GetCategoryData(EZMStockQueryType eCategoryType);
	///�����ʷί������
	ITradeRecordPtr GetHisData(EZMHisOrderType eCategoryType);

	/// ���ָ����Ʊ��ǰʵʱ����
	ITradeRecordPtr GetStockMarket(const CString& strStockCode);

public:
	enum { IDD = IDD_MAINDLG };

	BEGIN_DDX_MAP(CMainDlg)
		DDX_CHECK(IDC_CHECK_RZRQ,m_bRZRQ);
   END_DDX_MAP()

	BEGIN_MSG_MAP(CMainDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)

		MESSAGE_HANDLER(WM_TRADEEVENT_INITRETURN, OnInitReturn)
		MESSAGE_HANDLER(WM_TRADEEVENT_LOGINRETURN, OnLoginReturn)
		MESSAGE_HANDLER(WM_TRADEEVENT_SENDORDER, OnOrderOK)
		MESSAGE_HANDLER(WM_TRADEEVENT_ORDERERROR, OnOrderError)
		MESSAGE_HANDLER(WM_TRADEEVENT_STOCKQUOTE, OnStockQuote)
		MESSAGE_HANDLER(WM_TRADEEVENT_SERVERERRVER, OnServerError)
		MESSAGE_HANDLER(WM_TRADEEVENT_ORDERSUCCESS, OnOrderSuccess)

		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)

		COMMAND_HANDLER(IDC_BUTTON_INIT, BN_CLICKED, OnBnClickedInit)
		COMMAND_HANDLER(IDC_BUTTON_UNINIT, BN_CLICKED, OnBnClickedUnInit)
		COMMAND_HANDLER(IDC_BUTTON_GETTRADE, BN_CLICKED, OnBnClickedGetTradeData)
		COMMAND_HANDLER(IDC_BUTTON_FIVEMARKET, BN_CLICKED, OnBnClickedGetFiveMarket)
		COMMAND_HANDLER(IDC_BUTTON_HISDATA, BN_CLICKED, OnBnClickedGetHisData)
		COMMAND_HANDLER(IDC_BUTTON_BUY, BN_CLICKED, OnBnClickedBuy)
		COMMAND_HANDLER(IDC_BUTTON_SELL, BN_CLICKED, OnBnClickedSell)

		COMMAND_HANDLER(IDC_BUTTON_NEWSTOCK, BN_CLICKED, OnBnClickedIPO)
		COMMAND_HANDLER(IDC_BUTTON_MARKET, BN_CLICKED, OnBnClickedMarket)
		COMMAND_HANDLER(IDC_BUTTON_MARKETEX, BN_CLICKED, OnBnClickedMarketEx)
		COMMAND_HANDLER(IDC_BUTTON_MARKETL2, BN_CLICKED, OnBnClickedMarketL2)
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	LRESULT OnInitReturn(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnLoginReturn(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnOrderOK(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnOrderError(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnStockQuote(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnServerError(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnOrderSuccess(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

	LRESULT OnBnClickedInit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedGetFiveMarket(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedGetTradeData(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedGetHisData(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedBuy(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedSell(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	LRESULT OnBnClickedUnInit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedIPO(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedMarket(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedMarketEx(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedMarketL2(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};
