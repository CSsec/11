#pragma once

// ����L2���鴦������
class CMarketL2Event : 
	public CComObjectRoot,
	//ʵ��L2�����¼�֪ͨ�ӿ�
	public _IMarketLevel2Events
{
protected:

	/// ������
	HWND			m_hParentWnd;
	/// ����ID
	ULONG			m_nRequestID;

	/// �������ݻ���
	ITradeRecordPtr	m_spiRecord;

	/// ��������
	CString			m_strErrInfo;

public:
	CMarketL2Event()
		:m_hParentWnd(NULL)
		,m_spiRecord(NULL)
		,m_nRequestID(0)
	{
	}

	~CMarketL2Event()
	{
		m_spiRecord = NULL;
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

	ULONG GetReqID()
	{
		return m_nRequestID;
	}

	ITradeRecordPtr GetReqData()
	{
		return m_spiRecord;
	}

BEGIN_COM_MAP(CMarketL2Event)
	COM_INTERFACE_ENTRY(_IMarketLevel2Events)
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
	
	//  _IMarketLevel2Events
	/// ��ʼ���ӿڽ��֪ͨ
	STDMETHOD(InitEvent)(IDispatch* piMarket,VARIANT_BOOL bOK);
	/// ���ӷ��������֪ͨ
	STDMETHOD(ConnectEvent)(IDispatch* piMarket, ULONG nConnID,BSTR bstrHost,USHORT nPort,VARIANT_BOOL bOK);
	/// ��ѯָ����Ʊʵʱ5������ر�
	STDMETHOD(StockQuoteEvent)(ULONG nReqID,VARIANT_BOOL bFive,IDispatch* piRecordInfo);
	/// ��ѯָ����Ʊ��ʱ����ر�
	STDMETHOD(StockMinuteEvent)(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo);
	/// ��ѯָ����Ʊ��ʱ�ɽ��ر�
	STDMETHOD(StockTransEvent)(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo);
	/// ��ѯָ����ƱK�߻ر�
	STDMETHOD(StockBarsEvent)(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo);
	/// ��ѯָ����Ʊ��ʳɽ��ر�
	STDMETHOD(StockDetailTransEvent)(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo);
	/// ��ѯָ����Ʊ���ί�лر�
	STDMETHOD(StockDetailOrderEvent)(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo);
	/// ��ѯָ����Ʊ�������лر�
	STDMETHOD(StockOrderListEvent)(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo);

	/// ����������֪ͨ
	STDMETHOD(ServerErrEvent)(ULONG nConnID,ULONG nReqID);
};