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
	, m1(0)
{

}

CClientDlg::~CClientDlg()
{
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_client);
	DDX_Text(pDX, IDC_EDIT_CLIENT_TOTAL, m1);
	DDX_Control(pDX, IDC_EDIT_CLIENT_TOTAL, m_edit);
}


BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CClientDlg::OnLvnItemchangedList1)
	ON_LBN_SELCHANGE(IDC_LIST2, &CClientDlg::OnLbnSelchangeList2)
	ON_EN_CHANGE(IDC_EDIT_CLIENT_TOTAL, &CClientDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CClientDlg 消息处理程序


void CClientDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


BOOL CClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_client.InsertColumn(0, _T("编号"), LVCFMT_LEFT, 50);
	m_client.InsertColumn(1, _T("菜名"), LVCFMT_LEFT, 110);
	m_client.InsertColumn(2, _T("单价"), LVCFMT_LEFT, 70);
	m_client.InsertColumn(3, _T("数量"), LVCFMT_LEFT, 50);
	m_client.InsertColumn(4, _T("价格"), LVCFMT_LEFT, 70);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CClientDlg::OnLbnSelchangeList2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CClientDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
