#pragma once

// ������չ���鴦������
class CMarketExEvent : 
	public CComObjectRoot,
	//ʵ����չ�����¼�֪ͨ�ӿ�
	public _IMarketExEvents
{
protected:

	/// ���Ӷ������
	USHORT			m_nConnIndex;
	/// ����ID
	ULONG			m_nRequestID;

	/// ������
	HWND			m_hParentWnd;

	/// �������ݻ���
	ITradeRecordPtr	m_spiRecord;

	/// �г�����
	IMarketExPtr	m_spiMarket;

	/// ��������
	CString			m_strErrInfo;

public:
	CMarketExEvent()
		:m_hParentWnd(NULL)
		,m_spiRecord(NULL)
		,m_spiMarket(NULL)
		,m_nConnIndex(0)
		,m_nRequestID(0)
	{
	}

	~CMarketExEvent()
	{
		m_spiRecord = NULL;
	}

	void SetCallPara(HWND hParentWnd,USHORT nIndex)
	{
		if(NULL != hParentWnd)
		{
			if(!::IsWindow(hParentWnd))
				return;
		}
		m_nConnIndex = nIndex;
		m_hParentWnd = hParentWnd;
	}

	ITradeRecordPtr GetReqData()
	{
		return m_spiRecord;
	}

	IMarketExPtr GetMarket()
	{
		return m_spiMarket;
	}

	ULONG GetReqID()
	{
		return m_nRequestID;
	}

BEGIN_COM_MAP(CMarketExEvent)
	COM_INTERFACE_ENTRY(_IMarketExEvents)
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
	
	//  _IMarketExEvents
	/// ��ʼ���ӿڽ��֪ͨ
	STDMETHOD(InitEvent)(IDispatch* piMarket,VARIANT_BOOL bOK);
	/// ���ӷ��������֪ͨ
	STDMETHOD(ConnectEvent)(IDispatch* piMarket, ULONG nConnID,BSTR bstrHost,USHORT nPort,VARIANT_BOOL bOK);
	/// ��ѯָ����Ʊʵʱ5������ر�
	STDMETHOD(StockQuoteEvent)(ULONG nReqID,IDispatch* piRecordInfo);
	/// ��ѯָ����Ʊ��ʱ����ر�
	STDMETHOD(StockMinuteEvent)(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo);
	/// ��ѯָ����Ʊ��ʱ�ɽ��ر�
	STDMETHOD(StockTransEvent)(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo);
	/// ��ѯָ����ƱK�߻ر�
	STDMETHOD(StockBarsEvent)(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo);

	/// ����������֪ͨ
	STDMETHOD(ServerErrEvent)(ULONG nConnID,ULONG nReqID);
};