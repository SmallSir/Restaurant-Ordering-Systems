// HistoryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "HistoryDlg.h"
#include "afxdialogex.h"


// CHistoryDlg 对话框

IMPLEMENT_DYNAMIC(CHistoryDlg, CDialogEx)

CHistoryDlg::CHistoryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_HISTORY, pParent)
	, m_DishesHistory(&m_ctrlHisList, &m_ctrlHisOrder)
{

}

CHistoryDlg::~CHistoryDlg()
{
}

BOOL CHistoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_ctrlHisList.InsertColumn(0, _T("账单"), LVCFMT_LEFT, 100);

	m_ctrlHisOrder.SetExtendedStyle(m_ctrlHisOrder.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_ctrlHisOrder.InsertColumn(0, _T("编号"), LVCFMT_LEFT, 70);
	m_ctrlHisOrder.InsertColumn(1, _T("菜名"), LVCFMT_LEFT, 120);
	m_ctrlHisOrder.InsertColumn(2, _T("单价"), LVCFMT_LEFT, 70);
	m_ctrlHisOrder.InsertColumn(3, _T("数量"), LVCFMT_LEFT, 70);
	m_ctrlHisOrder.InsertColumn(4, _T("价格"), LVCFMT_LEFT, 70);

	return TRUE;
}

void CHistoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_HISLIST, m_ctrlHisList);
	DDX_Control(pDX, IDC_LIST_HISORDER, m_ctrlHisOrder);
}


BEGIN_MESSAGE_MAP(CHistoryDlg, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST_HISLIST, &CHistoryDlg::OnClickListHislist)
END_MESSAGE_MAP()


// CHistoryDlg 消息处理程序


void CHistoryDlg::OnClickListHislist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int index = m_ctrlHisList.GetNextItem(-1, LVNI_SELECTED);
	m_DishesHistory.showOrder(index);

	*pResult = 0;
}
