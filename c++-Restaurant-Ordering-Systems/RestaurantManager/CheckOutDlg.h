#pragma once


// CCheckOutDlg �Ի���

class CCheckOutDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckOutDlg)

public:
	CCheckOutDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCheckOutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHECKOUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCheckout();
};
