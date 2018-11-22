#pragma once
#include <atlstr.h>

/// �¼�֪ͨ��Ӧ����Ϣ
#define WM_TRADEEVENT_INITRETURN		WM_USER + 901
#define WM_TRADEEVENT_LOGINRETURN		WM_USER + 902
#define WM_TRADEEVENT_STOCKQUOTE		WM_USER + 903
#define WM_TRADEEVENT_STOCKQUOTE10		WM_USER + 904
#define WM_TRADEEVENT_STOCKMINUTE		WM_USER + 905
#define WM_TRADEEVENT_STOCKTRANS		WM_USER + 906
#define WM_TRADEEVENT_STOCKBARS			WM_USER + 907
#define WM_TRADEEVENT_STOCKDETAILTRANS	WM_USER + 908
#define WM_TRADEEVENT_STOCKDETAILORDER	WM_USER + 909
#define WM_TRADEEVENT_STOCKORDERLIST	WM_USER + 910
#define WM_TRADEEVENT_SERVERERRVER		WM_USER + 911

#define WM_TRADEEVENT_SENDORDER			WM_USER + 920
#define WM_TRADEEVENT_ORDERSUCCESS		WM_USER + 921
#define WM_TRADEEVENT_ORDERERROR		WM_USER + 922
#define WM_TRADEEVENT_CHANGESERVER		WM_USER + 923

// �����¼���������
class CStockComEvent : 
	public CComObjectRoot,
	//ʵ�ֽ����¼�֪ͨ�ӿ�
	public _ITradeEvents
{
protected:

	/// ������
	HWND			m_hParentWnd;

	/// �������ݻ���
//	ITradeRecordPtr	m_spiTradeRecord;

public:
	CStockComEvent()
		:m_hParentWnd(NULL)
	{
	}

	~CStockComEvent()
	{
	}

	void SetCallPara(HWND hParentWnd)
	{
		if(NULL != hParentWnd)
		{
			if(!::IsWindow(hParentWnd))
				return;
		}
		m_hParentWnd = hParentWnd;
	}

BEGIN_COM_MAP(CStockComEvent)
	COM_INTERFACE_ENTRY(_ITradeEvents)
END_COM_MAP()

public:

	STDMETHODIMP GetTypeInfoCount(UINT*)
    {
       return E_NOTIMPL;
    }

    STDMETHODIMP GetTypeInfo( UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo)
    { 
       return E_NOTIMPL;
    }

    STDMETHODIMP GetIDsOfNames( REFIID riid,LPOLESTR *rgszNames,UINT cNames,
                    LCID lcid,DISPID *rgDispId)
    { 
      return E_NOTIMPL;
    }

	STDMETHOD(Invoke)(DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,
               VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
	
	//  _ITradeEvents
	/// ��ʼ���ӿڽ��֪ͨ
	STDMETHOD(InitEvent)(IDispatch* piTrade,VARIANT_BOOL bOK);
	/// ��¼���������֪ͨ
	STDMETHOD(LoginEvent)(IDispatch* piTrade, ULONG nTradeID,BSTR bstrHost,USHORT nPort,VARIANT_BOOL bOK);
	/// ����ί�гɹ��ر�
	STDMETHOD(OrderOKEvent)(ULONG OrderOKEvent,EZMExchangeType eExchangeType,IDispatch* piRecordInfo);
	/// ����ί��ʧ�ܻر�
	STDMETHOD(OrderErrEvent)(ULONG nReqID,BSTR bstrErrInfo);
	/// ��ѯָ����Ʊʵʱ5������ر�
	STDMETHOD(StockQuoteEvent)(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo);
	/// ����ί�гɽ��ر�
	STDMETHOD(OrderSuccessEvent)(BSTR bstrOrderID,BSTR bstrJson);

	/// ����������֪ͨ
	STDMETHOD(ServerErrEvent)(ULONG nTradeID,ULONG nReqID);
	/// �������л�֪ͨ�������������
	STDMETHOD(ServerChangedEvent)(ULONG nPreTradeID, ULONG nCurTradeID);
};