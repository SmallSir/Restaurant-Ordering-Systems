// ClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "ClientDlg.h"
#include "afxdialogex.h"


// CClientDlg 对话框

IMPLEMENT_DYNAMIC(CClientDlg, CDialogEx)

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CLIENT, pParent)
{

}

CClientDlg::~CClientDlg()
{
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
END_MESSAGE_MAP()


// CClientDlg 消息处理程序
