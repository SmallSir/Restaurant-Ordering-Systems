#pragma once


// REGISTER �Ի���

class REGISTER : public CDialogEx
{
	DECLARE_DYNAMIC(REGISTER)

public:
	REGISTER(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~REGISTER();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_REGISTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m=0;
	CString m_Name;
	int m_number;
	CString m_password;
	afx_msg void OnBnClickedButton1Complete();
};
