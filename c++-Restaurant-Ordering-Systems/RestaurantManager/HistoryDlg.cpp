// HistoryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "HistoryDlg.h"
#include "afxdialogex.h"


// CHistoryDlg �Ի���

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
	m_ctrlHisList.InsertColumn(0, _T("�˵�"), LVCFMT_LEFT, 100);

	m_ctrlHisOrder.SetExtendedStyle(m_ctrlHisOrder.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_ctrlHisOrder.InsertColumn(0, _T("���"), LVCFMT_LEFT, 70);
	m_ctrlHisOrder.InsertColumn(1, _T("����"), LVCFMT_LEFT, 120);
	m_ctrlHisOrder.InsertColumn(2, _T("����"), LVCFMT_LEFT, 70);
	m_ctrlHisOrder.InsertColumn(3, _T("����"), LVCFMT_LEFT, 70);
	m_ctrlHisOrder.InsertColumn(4, _T("�۸�"), LVCFMT_LEFT, 70);

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


// CHistoryDlg ��Ϣ�������


void CHistoryDlg::OnClickListHislist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index = m_ctrlHisList.GetNextItem(-1, LVNI_SELECTED);
	m_DishesHistory.showOrder(index);

	*pResult = 0;
}
