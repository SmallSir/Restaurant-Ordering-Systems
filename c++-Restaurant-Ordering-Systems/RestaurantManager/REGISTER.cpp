// REGISTER.cpp : 实现文件
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "REGISTER.h"
#include "afxdialogex.h"
#include "Filex.h"


// REGISTER 对话框

IMPLEMENT_DYNAMIC(REGISTER, CDialogEx)

REGISTER::REGISTER(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_REGISTER, pParent)
	, m_Name(_T(""))
	, m_number(0)
	, m_password(_T(""))
{

}

REGISTER::~REGISTER()
{
}

void REGISTER::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_Name);
	DDX_Text(pDX, IDC_EDIT_NUMBER, m_number);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
}


BEGIN_MESSAGE_MAP(REGISTER, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1_COMPLETE, &REGISTER::OnBnClickedButton1Complete)
END_MESSAGE_MAP()


// REGISTER 消息处理程序


void REGISTER::OnBnClickedButton1Complete()
{
	CFilex file(_T("d:\\person.txt"),CFile::modeCreate|CFile::modeWrite);
	CArchive ar(&file, CArchive::load);
	file.p[m].Name = m_Name;
	file.p[m].Password = m_password;
	file.p[m].Number = m_number;
	m++;
	void SumSumNumber(int m);
	// TODO: 在此添加控件通知处理程序代码
}
