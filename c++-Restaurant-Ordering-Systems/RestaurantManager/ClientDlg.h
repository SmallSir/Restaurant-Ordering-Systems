#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CClientDlg �Ի���

class CClientDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CClientDlg)

public:
	CClientDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CClientDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CLIENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_client;
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnSelchangeList2();
	double m1;
	afx_msg void OnEnChangeEdit1();
	CEdit m_edit;
};
