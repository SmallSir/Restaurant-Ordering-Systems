
// RestaurantManagerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "DishesTypeMenu.h"
#include "DishesMenu.h"
#include "DishesOrder.h"
#include "DishesHistory.h"
#include "ClientDlg.h"
#include "CheckOutDlg.h"
#include "HistoryDlg.h"


// CRestaurantManagerDlg �Ի���
class CRestaurantManagerDlg : public CDialogEx
{
// ����
public:
	CRestaurantManagerDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CRestaurantManagerDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESTAURANTMANAGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	void initMenuList();
public:
	CString ID;					// Ա������
	CString name;				// Ա������
	CStatic m_sAvatar;			// Ա��ͷ��
	// �Ի���ָ��
	CClientDlg *m_ClientDlg;	// �ͻ��˶Ի���
	CHistoryDlg *m_HistoryDlg;	// ��ʷ�˵��Ի���
	// ������
	DishesTypeMenu m_DishesTypeMenu;// ��ϵ��
	DishesOrder m_DishesOrder;	// �����
	// �ؼ�����
	CStatic m_ctrlUserName;		// Ա������
	CStatic m_ctrlUserId;		// Ա��ID
	CListCtrl m_listTypeMenu;	// ��ϵ�б�
	CListCtrl m_listMenu;		// �˵��б�
	CListCtrl m_listOrder;		// ����б�
	CEdit m_bEditTotal;			// �ܼ۱༭��
	// ��¼����ʱ��
	CString m_strCurTime;		// ��ǰʱ��
	CString m_strWorkTime;		// ����ʱ��
	unsigned long workseconds;	// ��������

	void OnRButtonClickedLishCtrl(CListCtrl* m_plistCtrl, UINT ID_MENU);	// ΪLishControl�ؼ�����Ҽ��˵�
	afx_msg void OnBnClickedButtonLogout();			// ��ť�����Ϣ
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonStartCheckout();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonOrder();
	afx_msg void OnMenuShow();		// �˵��������Ϣ
	afx_msg void OnMenuLogout();
	afx_msg void OnMenuExit();
	afx_msg void OnMenuOrder();
	afx_msg void OnMenuDelete();
	afx_msg void OnMenuClear();
	afx_msg void OnMenuCheckout();
	afx_msg void OnMenuHistory();
	afx_msg void OnDblclkListMenu(NMHDR *pNMHDR, LRESULT *pResult);		// ˫���˵��б�
	afx_msg void OnRclickListMenu(NMHDR *pNMHDR, LRESULT *pResult);		// �һ��˵��б�
	afx_msg void OnRclickListOrder(NMHDR *pNMHDR, LRESULT *pResult);	// �һ�����б�
	afx_msg void OnDishMenuOrder();			// �һ��˵������Ϣ
	afx_msg void OnOrderMenuAddAgain();
	afx_msg void OnOrderMenuDelete();
	afx_msg void OnOrderMenuClear();
	afx_msg void OnOrderMenuCheckOut();
	afx_msg void OnTimer(UINT_PTR nIDEvent);	// ��¼����ʱ��ļ�ʱ��
	afx_msg void OnClickListTypemenu(NMHDR *pNMHDR, LRESULT *pResult);
};
