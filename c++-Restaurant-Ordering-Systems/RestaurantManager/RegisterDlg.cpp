// REGISTER.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "RegisterDlg.h"
#include "afxdialogex.h"


// REGISTER �Ի���

IMPLEMENT_DYNAMIC(CRegisterDlg, CDialogEx)

CRegisterDlg::CRegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_REGISTER, pParent)
	, m_Name(_T(""))
	, m_password(_T(""))
	, m_number(_T(""))
{

}

CRegisterDlg::~CRegisterDlg()
{
}

void CRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_Name);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	DDX_Text(pDX, IDC_EDIT_NUMBER, m_number);
}


BEGIN_MESSAGE_MAP(CRegisterDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1_COMPLETE, &CRegisterDlg::OnBnClickedButton1Complete)
	ON_BN_CLICKED(IDC_BUTTON_CANCL, &CRegisterDlg::OnBnClickedButtonCancl)
END_MESSAGE_MAP()


// REGISTER ��Ϣ�������


void CRegisterDlg::OnBnClickedButton1Complete()
{
	UpdateData(true);
	if (m_number == "")
	{
		AfxMessageBox(_T("�������˺ţ�"));
	}
	else if (m_Name == "")
	{
		AfxMessageBox(_T("������������"));
	}
	else if (m_password == "")
	{
		AfxMessageBox(_T("���������룡"));
	}
	::CoInitialize(NULL);
	_ConnectionPtr  m_pConnection=NULL;
	_RecordsetPtr m_pRecordset=NULL;
	_CommandPtr m_Command = NULL;
	m_Command.CreateInstance(_uuidof(Command));
	m_pConnection.CreateInstance(__uuidof(Connection));
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	HRESULT hr= m_pConnection->Open("DSN=RestaurantWorkers", "", "", 0);
	if (FAILED(hr))
	{
		AfxMessageBox(_T("����ʧ��"));
	}
	CString str;
	str.Format(_T("insert into Workers values('%s','%s','%s')"), m_number, m_Name, m_password);
	BSTR bstrSQL = str.AllocSysString();
	_variant_t RecordsAffected;
	m_pConnection->Execute((_bstr_t)str, &RecordsAffected, adCmdText);
	m_pConnection->Close();
	if (atoi(_bstr_t(RecordsAffected)) == 0)
	{
		MessageBox(_T("���ӹ�����Ա����ʧ��!"));
	}
	else
	{
		MessageBox(_T("���ӹ�����Ա�����ɹ�!"));
		CDialogEx::OnOK();
	}
}

void CRegisterDlg::OnBnClickedButtonCancl()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
