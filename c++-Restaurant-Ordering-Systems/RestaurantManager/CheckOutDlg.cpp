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


// CCheckOutDlg ��Ϣ�������


void CCheckOutDlg::OnBnClickedButtonCheckout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	// �رնԻ��򲢷���IDOK
	if (m2 >= m1) {
		AfxMessageBox(_T("���˳ɹ���"));
		CDialogEx::OnOK();
	}
	else {
		AfxMessageBox(_T("���㣬����ʧ�ܣ�"));
	}
}


void CCheckOutDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(1);
	m3 = m2 - m1;
	UpdateData(0);
}


void CCheckOutDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
