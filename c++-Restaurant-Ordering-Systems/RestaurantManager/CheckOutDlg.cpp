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
{

}

CCheckOutDlg::~CCheckOutDlg()
{
}

void CCheckOutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCheckOutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CHECKOUT, &CCheckOutDlg::OnBnClickedButtonCheckout)
END_MESSAGE_MAP()


// CCheckOutDlg 消息处理程序


void CCheckOutDlg::OnBnClickedButtonCheckout()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxMessageBox(_T("结账成功！"));
	// 关闭对话框并返回IDOK
	CDialogEx::OnOK();
//	CDialogEx::OnCancel();
}
