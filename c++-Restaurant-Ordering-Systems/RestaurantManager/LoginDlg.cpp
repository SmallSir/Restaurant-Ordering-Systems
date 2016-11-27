// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "Filex.h"
#include "REGISTER.h"
int n;


// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

void CLoginDlg::HowManyPerson(int m)
{
	n = m;
}

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
	, m_Number(0)
	, m_password(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::SumNumber(int m)
{
	n = m;
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Number);
	DDX_Text(pDX, IDC_EDIT2, m_password);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CLoginDlg::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_REGISTER, &CLoginDlg::OnBnClickedButtonRegister)
END_MESSAGE_MAP()


// CLoginDlg ��Ϣ�������


void CLoginDlg::OnBnClickedButtonLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//����WorkerInfo�еĺ��������Ѿ���д����Ϣ�����ĵ����Ѿ�ע�����Ϣ���бȽϣ��ж��Ƿ�������
	int i;
	CFilex file(_T("d:\\person.txt"), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	for (i = 0; i < n; i++)
	{
		if (m_Number == file.p[i].Password&&m_password == file.p[i].Password)
		{
			CDialogEx::OnOK();
		}
		else
		{
			AfxMessageBox(_T("������߹��Ŵ�����ȷ�Ϻ���������"));
		}
	}
}



void CLoginDlg::OnBnClickedButtonRegister()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	REGISTER dlg;
	dlg.DoModal();
}


