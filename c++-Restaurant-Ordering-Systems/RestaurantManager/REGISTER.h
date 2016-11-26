#pragma once


// REGISTER 对话框

class REGISTER : public CDialogEx
{
	DECLARE_DYNAMIC(REGISTER)

public:
	REGISTER(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~REGISTER();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_REGISTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m=0;
	CString m_Name;
	int m_number;
	CString m_password;
	afx_msg void OnBnClickedButton1Complete();
};
