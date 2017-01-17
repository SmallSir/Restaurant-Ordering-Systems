// ClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "ClientDlg.h"
#include "afxdialogex.h"


// CClientDlg �Ի���

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


// CClientDlg ��Ϣ�������


void CClientDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


BOOL CClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_client.InsertColumn(0, _T("���"), LVCFMT_LEFT, 50);
	m_client.InsertColumn(1, _T("����"), LVCFMT_LEFT, 110);
	m_client.InsertColumn(2, _T("����"), LVCFMT_LEFT, 70);
	m_client.InsertColumn(3, _T("����"), LVCFMT_LEFT, 50);
	m_client.InsertColumn(4, _T("�۸�"), LVCFMT_LEFT, 70);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CClientDlg::OnLbnSelchangeList2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CClientDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
