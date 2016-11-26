#pragma once
#include "afxcmn.h"
#include "DishesHistory.h"


// CHistoryDlg 对话框

class CHistoryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHistoryDlg)

public:
	CHistoryDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHistoryDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HISTORY };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctrlHisList;
	CListCtrl m_ctrlHisOrder;
	DishesHistory m_DishesHistory;
	afx_msg void OnClickListHislist(NMHDR *pNMHDR, LRESULT *pResult);
};
