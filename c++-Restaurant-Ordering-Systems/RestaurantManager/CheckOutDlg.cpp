// CheckOutDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "CheckOutDlg.h"
#include "afxdialogex.h"


// CCheckOutDlg �Ի���

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


// CCheckOutDlg ��Ϣ�������


void CCheckOutDlg::OnBnClickedButtonCheckout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxMessageBox(_T("���˳ɹ���"));
	// �رնԻ��򲢷���IDOK
	CDialogEx::OnOK();
//	CDialogEx::OnCancel();
}
