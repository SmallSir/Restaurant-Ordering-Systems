/****************************************************************************************
 * @���� RestaurantManager ������������ϵͳ
 * @���� ����¹С��
 * @��Ա ������ 201531104032  ����� 201531104048  ���� 201531104078  ½�� 201531104038
 * @���� 2016.11.4
 * @���� ����Ա����½��ע�ᡢһ����ɵ�ͽ��ˡ���¼����ʱ�䡢�ͻ���ʵʱ��ʾ���鿴��ʷ�˵�
 * @ʵ�� ����ؼ��Ļ������������ݿ�ʵ�ֵ�¼ע�ᡢ���ļ���ȡ�˺źͲ˵����ݡ�Unicode���ַ�����
         ϵͳʱ��Ļ�ȡ����ģ̬�Ի������ʾ���һ��������ܲ˵���vector������ʹ�á�
		 �������������⴦���ַ��������ֵ��໥ת������Ӧ���ڴ�С�仯��������Զ�ö���
****************************************************************************************/



// RestaurantManager.cpp : Ӧ�ó�������ࡣ
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "LoginDlg.h"
#include "RestaurantManagerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRestaurantManagerApp

BEGIN_MESSAGE_MAP(CRestaurantManagerApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CRestaurantManagerApp ����

CRestaurantManagerApp::CRestaurantManagerApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CRestaurantManagerApp ����

CRestaurantManagerApp theApp;


// CRestaurantManagerApp ��ʼ��

BOOL CRestaurantManagerApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	// SetRegistryKey(_T("����¹С��"));
	
	do {
		// ��ʾ��¼�Ի���
		CLoginDlg LoginDlg;
		int nResponse = LoginDlg.DoModal();
		// ����ֵΪIDOKʱ��¼�ɹ��������˳�����
		if (nResponse != IDOK) {
			break;
		}
		else {
			CRestaurantManagerDlg dlg;
			dlg.ID = LoginDlg.ID;
			dlg.name = LoginDlg.name;
			// ��ʾ������
			nResponse = dlg.DoModal();
			// ����ֵΪIDOKʱ���µ�¼�������˳�����
			if (nResponse != IDOK) {
				break;
			}
		}
	} while (true);

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

