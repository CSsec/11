#pragma once
#include "StockComEvent.h"

// ��ͨ�����¼���������
class CMarketEvent : 
	public CComObjectRoot,
	//ʵ����ͨ�����¼�֪ͨ�ӿ�
	public _IMarketEvents
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

	/// ��ͨ����ӿ�
	IMarketPtr		m_spiMarket;

	/// ��������
	CString			m_strErrInfo;

public:
	CMarketEvent()
		:m_hParentWnd(NULL)
		,m_spiRecord(NULL)
		,m_spiMarket(NULL)
		,m_nConnIndex(0)
		,m_nRequestID(0)
	{
	}

	~CMarketEvent()
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

	ULONG GetReqID()
	{
		return m_nRequestID;
	}

	IMarketPtr GetMarket()
	{
		return m_spiMarket;
	}

BEGIN_COM_MAP(CMarketEvent)
	COM_INTERFACE_ENTRY(_IMarketEvents)
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
	
	//  _IMarketEvents
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