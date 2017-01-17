#pragma once


// CCheckOutDlg 对话框

class CCheckOutDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckOutDlg)

public:
	CCheckOutDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCheckOutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHECKOUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCheckout();
	afx_msg void OnBnClickedButton3();
	double m3;
	double m1;
	double m2;
	afx_msg void OnBnClickedCancel();
};
