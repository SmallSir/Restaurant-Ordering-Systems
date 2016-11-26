#pragma once
#include "afxcmn.h"
#include "DishesHistory.h"


// CHistoryDlg �Ի���

class CHistoryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHistoryDlg)

public:
	CHistoryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHistoryDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HISTORY };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctrlHisList;
	CListCtrl m_ctrlHisOrder;
	DishesHistory m_DishesHistory;
	afx_msg void OnClickListHislist(NMHDR *pNMHDR, LRESULT *pResult);
};
