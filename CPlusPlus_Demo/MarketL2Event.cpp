/////////////////////////////////////////////////////////////////////////
/*@
	�ļ����ƣ�	MarketL2Event.cpp
	�ļ�������	ʵ��TDX COM���L2�����¼�֪ͨ����
*/
/////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StockComEvent.h"
#include "MarketL2Event.h"

/////////////////////////////////////////////////////////////////////////////
// CMarketL2Event

STDMETHODIMP CMarketL2Event::Invoke( DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,
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

			CComVariant varConnRet, varConnID,varHost,varPort,varTradeConn;
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
			hRet = ConnectEvent(varTradeConn.pdispVal, varConnID.uiVal,varHost.bstrVal,varPort.uiVal,varConnRet.boolVal);
			VariantClear(&varConnRet);
			VariantClear(&varConnID);
			VariantClear(&varHost);
			VariantClear(&varPort);
			VariantClear(&varTradeConn);
			break;
		}

		case 0x00000003:
		{
			if ( pDispParams->cArgs != 3 )
				return DISP_E_BADPARAMCOUNT;
			if ( pDispParams->cNamedArgs )
				return DISP_E_NONAMEDARGS;

			CComVariant varReqID,varFive,varRecord;
			VariantInit(&varReqID);
			VariantInit(&varFive);
			VariantInit(&varRecord);
			hRet = VariantChangeTypeEx( &varReqID,&(pDispParams->rgvarg[2]),lcid,0,VT_UI4);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = VariantChangeTypeEx( &varFive,&(pDispParams->rgvarg[1]),lcid,0,VT_BOOL);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = VariantChangeTypeEx( &varRecord,&(pDispParams->rgvarg[0]),lcid,0,VT_DISPATCH);
			if FAILED(hRet)
				return DISP_E_BADVARTYPE;
			hRet = StockQuoteEvent(varReqID.ulVal,varFive.boolVal,varRecord.pdispVal);
			VariantClear(&varReqID);
			VariantClear(&varFive);
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

		case 0x00000007:
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
			hRet = StockDetailTransEvent(varReqID.ulVal,varCode.bstrVal,varRecord.pdispVal);
			VariantClear(&varReqID);
			VariantClear(&varCode);
			VariantClear(&varRecord);
			break;
		}

		case 0x00000008:
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
			hRet = StockDetailOrderEvent(varReqID.ulVal,varCode.bstrVal,varRecord.pdispVal);
			VariantClear(&varReqID);
			VariantClear(&varCode);
			VariantClear(&varRecord);
			break;
		}

		case 0x00000009:
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
			hRet = StockOrderListEvent(varReqID.ulVal,varCode.bstrVal,varRecord.pdispVal);
			VariantClear(&varReqID);
			VariantClear(&varCode);
			VariantClear(&varRecord);
			break;
		}

		case 0x0000000A:
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
			hRet = ServerErrEvent(varConnID.ulVal,varReqID.ulVal);
			VariantClear(&varConnID);
			VariantClear(&varReqID);
			break;
		}
		default:
			break;
	}
	return hRet;
}

STDMETHODIMP CMarketL2Event::InitEvent(IDispatch* piMarket,VARIANT_BOOL bOK)
{
	HRESULT hRet(E_FAIL);
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		BOOL bInitFlag = FALSE;
		if(VARIANT_TRUE == bOK)
		{
			bInitFlag = TRUE;
		}
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_INITRETURN,(WPARAM)bInitFlag,(LPARAM)this);
	}
	return hRet;
}

STDMETHODIMP CMarketL2Event::ConnectEvent(IDispatch* piMarket,ULONG nConnID,BSTR bstrHost,USHORT nPort,VARIANT_BOOL bOK)
{
	HRESULT hRet(E_FAIL);
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		CString strLogInfo;
		BOOL bConnected = FALSE;
		IMarketLevel2Ptr spiMarket(piMarket);
		CComBSTR bstrUID;
		spiMarket->get_Level2UserName(&bstrUID);
		if(VARIANT_TRUE == bOK)
		{
			strLogInfo.Format(L"���� %s �˿� %d ���ӳɹ�����¼�˺�:%s",\
				CString(bstrHost),nPort,(CString)bstrUID.m_str);
			bConnected = TRUE;
		}
		else
		{
			ATLASSERT(spiMarket);
			CComBSTR bstrErrInfo;
			spiMarket->get_LastErrDesc(&bstrErrInfo);
			strLogInfo.Format(L"���� %s �˿� %d ����ʧ�ܣ�����ԭ��:%s",CString(bstrHost),nPort,CString(bstrErrInfo.m_str));
			bstrErrInfo.Empty();
		}
		/// ֻ��������������¼������������ʽ֪ͨ��ȷ���õ��ӿ�ǰû�б��ͷ�
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_LOGINRETURN,(WPARAM)bConnected,(LPARAM)this);
	}
	return hRet;
}

STDMETHODIMP CMarketL2Event::ServerErrEvent(ULONG nConnID,ULONG nReqID)
{
	HRESULT hRet(E_FAIL);
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_SERVERERRVER,(WPARAM)nConnID,(LPARAM)this);
	}
	return hRet;
}

STDMETHODIMP CMarketL2Event::StockQuoteEvent(ULONG nReqID,VARIANT_BOOL bFive,IDispatch* piRecordInfo)
{
	HRESULT hRet(E_FAIL);
	m_spiRecord = NULL;
	if(NULL == piRecordInfo)
		return hRet;
	hRet = piRecordInfo->QueryInterface(IID_ITradeRecord,(LPVOID *)&m_spiRecord);
	if(NULL == m_spiRecord)
		return hRet;
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		/// ��ǰ�����˼�¼����������PostMessage
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_STOCKQUOTE,nReqID,(LPARAM)this);
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

STDMETHODIMP CMarketL2Event::StockTransEvent(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo)
{
	HRESULT hRet(E_FAIL);
	m_spiRecord = NULL;
	if(NULL == piRecordInfo)
		return hRet;
	hRet = piRecordInfo->QueryInterface(IID_ITradeRecord,(LPVOID *)&m_spiRecord);
	if(NULL == m_spiRecord)
		return hRet;
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		/// ��ǰ�����˼�¼����������PostMessage
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_STOCKTRANS,nReqID,(LPARAM)this);
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

STDMETHODIMP CMarketL2Event::StockMinuteEvent(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo)
{
	HRESULT hRet(E_FAIL);
	m_spiRecord = NULL;
	if(NULL == piRecordInfo)
		return hRet;
	hRet = piRecordInfo->QueryInterface(IID_ITradeRecord,(LPVOID *)&m_spiRecord);
	if(NULL == m_spiRecord)
		return hRet;
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		/// ��ǰ�����˼�¼����������PostMessage
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_STOCKMINUTE,nReqID,(LPARAM)this);
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

STDMETHODIMP CMarketL2Event::StockBarsEvent(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo)
{
	HRESULT hRet(E_FAIL);
	m_spiRecord = NULL;
	if(NULL == piRecordInfo)
		return hRet;
	hRet = piRecordInfo->QueryInterface(IID_ITradeRecord,(LPVOID *)&m_spiRecord);
	if(NULL == m_spiRecord)
		return hRet;
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		/// ��ǰ�����˼�¼����������PostMessage
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_STOCKBARS,nReqID,(LPARAM)this);
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

STDMETHODIMP CMarketL2Event::StockDetailTransEvent(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo)
{
	HRESULT hRet(E_FAIL);
	m_spiRecord = NULL;
	if(NULL == piRecordInfo)
		return hRet;
	hRet = piRecordInfo->QueryInterface(IID_ITradeRecord,(LPVOID *)&m_spiRecord);
	if(NULL == m_spiRecord)
		return hRet;
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		/// ��ǰ�����˼�¼����������PostMessage
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_STOCKDETAILTRANS,nReqID,(LPARAM)this);
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

STDMETHODIMP CMarketL2Event::StockDetailOrderEvent(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo)
{
	HRESULT hRet(E_FAIL);
	m_spiRecord = NULL;
	if(NULL == piRecordInfo)
		return hRet;
	hRet = piRecordInfo->QueryInterface(IID_ITradeRecord,(LPVOID *)&m_spiRecord);
	if(NULL == m_spiRecord)
		return hRet;
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		/// ��ǰ�����˼�¼����������PostMessage
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_STOCKDETAILORDER,nReqID,(LPARAM)this);
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

STDMETHODIMP CMarketL2Event::StockOrderListEvent(ULONG nReqID,BSTR bstrCode,IDispatch* piRecordInfo)
{
	HRESULT hRet(E_FAIL);
	m_spiRecord = NULL;
	if(NULL == piRecordInfo)
		return hRet;
	hRet = piRecordInfo->QueryInterface(IID_ITradeRecord,(LPVOID *)&m_spiRecord);
	if(NULL == m_spiRecord)
		return hRet;
	if(NULL != m_hParentWnd && ::IsWindow(m_hParentWnd))
	{
		/// ��ǰ�����˼�¼����������PostMessage
		::PostMessage(m_hParentWnd,WM_TRADEEVENT_STOCKORDERLIST,nReqID,(LPARAM)this);
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