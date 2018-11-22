/////////////////////////////////////////////////////////////////////////
/*@
	�ļ����ƣ�	MarketEvent.cpp
	�ļ�������	ʵ��TDX COM��������¼�֪ͨ����
*/
/////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MarketEvent.h"

/////////////////////////////////////////////////////////////////////////////
// CMarketEvent

STDMETHODIMP CMarketEvent::Invoke( DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,
                DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr)
{
	HRESULT hRet(S_OK);
	switch( dispIdMember )
	{
		case 0x00000001:
		{
			if ( pDispParams->cArgs != 2 )
				return DISP_E_BADPARAMCOUNT;
			if ( pDispParams->cNamedArgs )
				return DISP_E_NONAMEDARGS;

			CComVariant varConnRet,varTradeConn;
			VariantInit(&varConnRet);
			VariantInit(&varTradeConn);
			hRet = VariantChangeTypeEx( &varTradeConn,&(pDispParams->rgvarg[1]),lcid,0,VT_DISPATCH);
			hRet = VariantChangeTypeEx( &varConnRet,&(pDispParams->rgvarg[0]),lcid,0,VT_BOOL);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = InitEvent(varTradeConn.pdispVal,varConnRet.boolVal);
			VariantClear(&varConnRet);
			VariantClear(&varTradeConn);
			break;
		}

		case 0x00000002:
		{
			if ( pDispParams->cArgs != 5 )
				return DISP_E_BADPARAMCOUNT;
			if ( pDispParams->cNamedArgs )
				return DISP_E_NONAMEDARGS;

			CComVariant varConnRet,varConnID,varHost,varPort,varTradeConn;
			VariantInit(&varConnRet);
			VariantInit(&varConnID);
			VariantInit(&varPort);
			VariantInit(&varHost);
			VariantInit(&varTradeConn);
			hRet = VariantChangeTypeEx( &varTradeConn,&(pDispParams->rgvarg[4]),lcid,0,VT_DISPATCH);
			hRet = VariantChangeTypeEx( &varConnID,&(pDispParams->rgvarg[3]),lcid,0,VT_UI4);
			hRet = VariantChangeTypeEx( &varHost,&(pDispParams->rgvarg[2]),lcid,0,VT_BSTR);
			hRet = VariantChangeTypeEx( &varPort,&(pDispParams->rgvarg[1]),lcid,0,VT_UI2);
			hRet = VariantChangeTypeEx( &varConnRet,&(pDispParams->rgvarg[0]),lcid,0,VT_BOOL);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = ConnectEvent(varTradeConn.pdispVal, varConnID.ulVal,varHost.bstrVal,varPort.uiVal,varConnRet.boolVal);
			VariantClear(&varConnRet);
			VariantClear(&varConnID);
			VariantClear(&varHost);
			VariantClear(&varPort);
			VariantClear(&varTradeConn);
			break;
		}

		case 0x00000003:
		{
			if ( pDispParams->cArgs != 2 )
				return DISP_E_BADPARAMCOUNT;
			if ( pDispParams->cNamedArgs )
				return DISP_E_NONAMEDARGS;

			CComVariant varReqID,varRecord;
			VariantInit(&varReqID);
			VariantInit(&varRecord);
			hRet = VariantChangeTypeEx( &varReqID,&(pDispParams->rgvarg[1]),lcid,0,VT_UI4);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = VariantChangeTypeEx( &varRecord,&(pDispParams->rgvarg[0]),lcid,0,VT_DISPATCH);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = StockQuoteEvent(varReqID.ulVal,varRecord.pdispVal);
			VariantClear(&varReqID);
			VariantClear(&varRecord);
			break;
		}

		case 0x00000004:
		{
			if ( pDispParams->cArgs != 3 )
				return DISP_E_BADPARAMCOUNT;
			if ( pDispParams->cNamedArgs )
				return DISP_E_NONAMEDARGS;

			CComVariant varReqID,varCode,varRecord;
			VariantInit(&varReqID);
			VariantInit(&varCode);
			VariantInit(&varRecord);
			hRet = VariantChangeTypeEx( &varReqID,&(pDispParams->rgvarg[2]),lcid,0,VT_UI4);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = VariantChangeTypeEx( &varCode,&(pDispParams->rgvarg[1]),lcid,0,VT_BSTR);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = VariantChangeTypeEx( &varRecord,&(pDispParams->rgvarg[0]),lcid,0,VT_DISPATCH);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = StockMinuteEvent(varReqID.ulVal,varCode.bstrVal,varRecord.pdispVal);
			VariantClear(&varReqID);
			VariantClear(&varCode);
			VariantClear(&varRecord);
			break;
		}

		case 0x00000005:
		{
			if ( pDispParams->cArgs != 3 )
				return DISP_E_BADPARAMCOUNT;
			if ( pDispParams->cNamedArgs )
				return DISP_E_NONAMEDARGS;

			CComVariant varReqID,varCode,varRecord;
			VariantInit(&varReqID);
			VariantInit(&varCode);
			VariantInit(&varRecord);
			hRet = VariantChangeTypeEx( &varReqID,&(pDispParams->rgvarg[2]),lcid,0,VT_UI4);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = VariantChangeTypeEx( &varCode,&(pDispParams->rgvarg[1]),lcid,0,VT_BSTR);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = VariantChangeTypeEx( &varRecord,&(pDispParams->rgvarg[0]),lcid,0,VT_DISPATCH);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = StockTransEvent(varReqID.ulVal,varCode.bstrVal,varRecord.pdispVal);
			VariantClear(&varReqID);
			VariantClear(&varCode);
			VariantClear(&varRecord);
			break;
		}

		case 0x00000006:
		{
			if ( pDispParams->cArgs != 3 )
				return DISP_E_BADPARAMCOUNT;
			if ( pDispParams->cNamedArgs )
				return DISP_E_NONAMEDARGS;

			CComVariant varReqID,varCode,varRecord;
			VariantInit(&varReqID);
			VariantInit(&varCode);
			VariantInit(&varRecord);
			hRet = VariantChangeTypeEx( &varReqID,&(pDispParams->rgvarg[2]),lcid,0,VT_UI4);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = VariantChangeTypeEx( &varCode,&(pDispParams->rgvarg[1]),lcid,0,VT_BSTR);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = VariantChangeTypeEx( &varRecord,&(pDispParams->rgvarg[0]),lcid,0,VT_DISPATCH);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = StockBarsEvent(varReqID.ulVal,varCode.bstrVal,varRecord.pdispVal);
			VariantClear(&varReqID);
			VariantClear(&varCode);
			VariantClear(&varRecord);
			break;
		}

		case 0x00000009:
		{
			if ( pDispParams->cArgs != 2 )
				return DISP_E_BADPARAMCOUNT;
			if ( pDispParams->cNamedArgs )
				return DISP_E_NONAMEDARGS;

			CComVariant varConnID,varReqID;
			VariantInit(&varConnID);
			VariantInit(&varReqID);
			hRet = VariantChangeTypeEx( &varConnID,&(pDispParams->rgvarg[1]),lcid,0,VT_UI4);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = VariantChangeTypeEx( &varReqID,&(pDispParams->rgvarg[0]),lcid,0,VT_UI4);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = ServerErrEvent(varConnID.uiVal,varReqID.ulVal);
			VariantClear(&varConnID);
			VariantClear(&varReqID);
			break;
		}

		default:
			break;
	}
	return hRet;
}

STDMETHODIMP CMarketEvent::InitEvent(IDispatch* piMarket,VARIANT_BOOL bOK)
{
	HRESULT hRet(E_FAIL);
	m_spiMarket = NULL;
	m_spiMarket = piMarket;
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		BOOL bInitFlag = FALSE;
		if(VARIANT_TRUE == bOK)
		{
			bInitFlag = TRUE;
		}
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_INITRETURN,(WPARAM)bInitFlag,(LPARAM)m_nConnIndex);
	}
	return hRet;
}

STDMETHODIMP CMarketEvent::ConnectEvent(IDispatch* piMarket, ULONG nConnID,BSTR bstrHost,USHORT nPort,VARIANT_BOOL bOK)
{
	HRESULT hRet(E_FAIL);
	m_spiMarket = NULL;
	m_spiMarket = piMarket;
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		CString strLogInfo;
		BOOL bConnected = FALSE;
		ULONG nCurConnID = 0;
		m_spiMarket->get_CurConnID(&nCurConnID);
		if(VARIANT_TRUE == bOK)
		{
			strLogInfo.Format(L"���� %s �˿� %d ���ӳɹ�����Ӧ��ͨ����ID:%d ������ID:%d",\
				CString(bstrHost),nPort,nConnID,nCurConnID);
			bConnected = TRUE;
		}
		else
		{
			ATLASSERT(m_spiMarket);
			CComBSTR bstrErrInfo;
			m_spiMarket->get_LastErrDesc(&bstrErrInfo);
			strLogInfo.Format(L"���� %s �˿� %d ����ʧ�ܣ�����ԭ��:%s",CString(bstrHost),nPort,CString(bstrErrInfo.m_str));
			bstrErrInfo.Empty();
		}
		if(nCurConnID == nConnID)
		{
			/// ֻ��������������¼������������ʽ֪ͨ��ȷ���õ��ӿ�ǰû�б��ͷ�
			::PostMessage(m_hParentWnd,WM_TRADEEVENT_LOGINRETURN,(WPARAM)bConnected,(LPARAM)m_nConnIndex);
		}
#ifdef _DEBUG
		/// ���Դ���
		else
		{
			/// ������������¼�Ľ���ID������������ȡ����ȣ���������������������
			/// �����Ҫ������������¼������Щ�ɹ��Ľ���ID�Ա����ã��ͷ�����ʱָ������ID������ָ��0�ͷ���������
			ITradeRecordPtr spiRecord = NULL;
			CString strGetCode;
			int nIndex = nConnID%5;
			switch(nIndex)
			{
			case 0:
				strGetCode = L"000001";
				break;
			case 1:
				strGetCode = L"000002";
				break;
			case 2:
				strGetCode = L"000005";
				break;
			case 3:
				strGetCode = L"000006";
				break;
			case 4:
				strGetCode = L"000008";
				break;
			default:
				strGetCode = L"600000";
			}
			/// ��¼����ID���¼�֪ͨ��Я��������ID����������ƥ����������
			ULONG nReqID = 0;
			m_spiMarket->GetQuotes(nConnID,CComBSTR(strGetCode),&nReqID);
		}
#endif
	}
	return hRet;
}

STDMETHODIMP CMarketEvent::ServerErrEvent(ULONG nConnID,ULONG nReqID)
{
	HRESULT hRet(E_FAIL);
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_SERVERERRVER,(WPARAM)nConnID,(LPARAM)m_nConnIndex);
	}
	return hRet;
}

STDMETHODIMP CMarketEvent::StockQuoteEvent(ULONG nReqID,IDispatch* piRecordInfo)
{
	HRESULT hRet(E_FAIL);
	m_spiRecord = NULL;
	if(NULL == piRecordInfo)
		return hRet;
	hRet = piRecordInfo->QueryInterface(IID_ITradeRecord,(LPVOID *)&m_spiRecord);
	if(NULL == m_spiRecord)
		return hRet;
	m_nRequestID = nReqID;
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		/// ��ǰ�����˼�¼����������PostMessage
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_STOCKQUOTE,nReqID,(LPARAM)m_nConnIndex);
	}
	else
	{
#ifdef _DEBUG
		/// ������Ϣ
		CComBSTR bstrText;
		m_spiRecord->GetJsonString(&bstrText);
//		::MessageBox(NULL,CString(_T("�յ�ʵʱ�������ݣ�"))+(CString)bstrCode.m_str,ZM_APPLICATION_NAME,MB_OK);
		bstrText.Empty();
#endif
	}
	return hRet;
}

STDMETHODIMP CMarketEvent::StockTransEvent(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo)
{
	HRESULT hRet(E_FAIL);
	m_spiRecord = NULL;
	if(NULL == piRecordInfo)
		return hRet;
	hRet = piRecordInfo->QueryInterface(IID_ITradeRecord,(LPVOID *)&m_spiRecord);
	if(NULL == m_spiRecord)
		return hRet;
	m_nRequestID = nReqID;
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		/// ��ǰ�����˼�¼����������PostMessage
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_STOCKTRANS,nReqID,(LPARAM)m_nConnIndex);
	}
	else
	{
#ifdef _DEBUG
		/// ������Ϣ
		CComBSTR bstrText;
		m_spiRecord->GetJsonString(&bstrText);
//		::MessageBox(NULL,CString(_T("�յ��������ݣ�"))+(CString)bstrCode.m_str,ZM_APPLICATION_NAME,MB_OK);
		bstrText.Empty();
#endif
	}
	return hRet;
}

STDMETHODIMP CMarketEvent::StockMinuteEvent(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo)
{
	HRESULT hRet(E_FAIL);
	m_spiRecord = NULL;
	if(NULL == piRecordInfo)
		return hRet;
	hRet = piRecordInfo->QueryInterface(IID_ITradeRecord,(LPVOID *)&m_spiRecord);
	if(NULL == m_spiRecord)
		return hRet;
	m_nRequestID = nReqID;
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		/// ��ǰ�����˼�¼����������PostMessage
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_STOCKMINUTE,nReqID,(LPARAM)m_nConnIndex);
	}
	else
	{
#ifdef _DEBUG
		/// ������Ϣ
		CComBSTR bstrText;
		m_spiRecord->GetJsonString(&bstrText);
//		::MessageBox(NULL,CString(_T("�յ��������ݣ�"))+(CString)bstrCode.m_str,ZM_APPLICATION_NAME,MB_OK);
		bstrText.Empty();
#endif
	}
	return hRet;
}

STDMETHODIMP CMarketEvent::StockBarsEvent(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo)
{
	HRESULT hRet(E_FAIL);
	m_spiRecord = NULL;
	if(NULL == piRecordInfo)
		return hRet;
	hRet = piRecordInfo->QueryInterface(IID_ITradeRecord,(LPVOID *)&m_spiRecord);
	if(NULL == m_spiRecord)
		return hRet;
	m_nRequestID = nReqID;
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		/// ��ǰ�����˼�¼����������PostMessage
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_STOCKBARS,nReqID,(LPARAM)m_nConnIndex);
	}
	else
	{
#ifdef _DEBUG
		/// ������Ϣ
		CComBSTR bstrText;
		m_spiRecord->GetJsonString(&bstrText);
//		::MessageBox(NULL,CString(_T("�յ��������ݣ�"))+(CString)bstrCode.m_str,ZM_APPLICATION_NAME,MB_OK);
		bstrText.Empty();
#endif
	}
	return hRet;
}