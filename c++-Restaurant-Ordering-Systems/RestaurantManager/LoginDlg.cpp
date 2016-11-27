// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "Filex.h"
#include "REGISTER.h"
int n;


// CLoginDlg 对话框

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


// CLoginDlg 消息处理程序


void CLoginDlg::OnBnClickedButtonLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	//引用WorkerInfo中的函数，把已经填写的信息根据文档内已经注册的信息进行比较，判断是否有问题
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
			AfxMessageBox(_T("密码或者工号错误，请确认后重新输入"));
		}
	}
}



void CLoginDlg::OnBnClickedButtonRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	REGISTER dlg;
	dlg.DoModal();
}


