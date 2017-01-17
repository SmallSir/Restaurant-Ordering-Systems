// CheckOutDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "CheckOutDlg.h"
#include "afxdialogex.h"


// CCheckOutDlg 对话框

IMPLEMENT_DYNAMIC(CCheckOutDlg, CDialogEx)

CCheckOutDlg::CCheckOutDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CHECKOUT, pParent)
	, m1(0)
	, m2(0)
	, m3(0)

{

}

CCheckOutDlg::~CCheckOutDlg()
{
}

void CCheckOutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m1);
	//  DDX_Text(pDX, IDC_EDIT2, m2);
	DDX_Text(pDX, IDC_EDIT3, m3);
	DDX_Text(pDX, IDC_EDIT1, m1);
	DDX_Text(pDX, IDC_EDIT2, m2);
}


BEGIN_MESSAGE_MAP(CCheckOutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CHECKOUT, &CCheckOutDlg::OnBnClickedButtonCheckout)
	ON_BN_CLICKED(IDC_BUTTON3, &CCheckOutDlg::OnBnClickedButton3)

	ON_BN_CLICKED(IDCANCEL, &CCheckOutDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CCheckOutDlg 消息处理程序


void CCheckOutDlg::OnBnClickedButtonCheckout()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	// 关闭对话框并返回IDOK
	if (m2 >= m1) {
		AfxMessageBox(_T("结账成功！"));
		CDialogEx::OnOK();
	}
	else {
		AfxMessageBox(_T("金额不足，交易失败！"));
	}
}


void CCheckOutDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	m3 = m2 - m1;
	UpdateData(0);
}


void CCheckOutDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
