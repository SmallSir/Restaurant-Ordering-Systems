
// RestaurantManagerDlg.h : 头文件
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


// CRestaurantManagerDlg 对话框
class CRestaurantManagerDlg : public CDialogEx
{
// 构造
public:
	CRestaurantManagerDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CRestaurantManagerDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESTAURANTMANAGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	void initMenuList();
public:
	CString ID;					// 员工工号
	CString name;				// 员工姓名
	CStatic m_sAvatar;			// 员工头像
	// 对话框指针
	CClientDlg *m_ClientDlg;	// 客户端对话框
	CHistoryDlg *m_HistoryDlg;	// 历史账单对话框
	// 功能类
	DishesTypeMenu m_DishesTypeMenu;// 菜系类
	DishesOrder m_DishesOrder;	// 点餐类
	// 控件变量
	CStatic m_ctrlUserName;		// 员工姓名
	CStatic m_ctrlUserId;		// 员工ID
	CListCtrl m_listTypeMenu;	// 菜系列表
	CListCtrl m_listMenu;		// 菜单列表
	CListCtrl m_listOrder;		// 点餐列表
	CEdit m_bEditTotal;			// 总价编辑框
	// 记录工作时间
	CString m_strCurTime;		// 当前时间
	CString m_strWorkTime;		// 工作时间
	unsigned long workseconds;	// 工作秒数

	void OnRButtonClickedLishCtrl(CListCtrl* m_plistCtrl, UINT ID_MENU);	// 为LishControl控件添加右键菜单
	afx_msg void OnBnClickedButtonLogout();			// 按钮点击消息
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonStartCheckout();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonOrder();
	afx_msg void OnMenuShow();		// 菜单栏点击消息
	afx_msg void OnMenuLogout();
	afx_msg void OnMenuExit();
	afx_msg void OnMenuOrder();
	afx_msg void OnMenuDelete();
	afx_msg void OnMenuClear();
	afx_msg void OnMenuCheckout();
	afx_msg void OnMenuHistory();
	afx_msg void OnDblclkListMenu(NMHDR *pNMHDR, LRESULT *pResult);		// 双击菜单列表
	afx_msg void OnRclickListMenu(NMHDR *pNMHDR, LRESULT *pResult);		// 右击菜单列表
	afx_msg void OnRclickListOrder(NMHDR *pNMHDR, LRESULT *pResult);	// 右击点餐列表
	afx_msg void OnDishMenuOrder();			// 右击菜单点击消息
	afx_msg void OnOrderMenuAddAgain();
	afx_msg void OnOrderMenuDelete();
	afx_msg void OnOrderMenuClear();
	afx_msg void OnOrderMenuCheckOut();
	afx_msg void OnTimer(UINT_PTR nIDEvent);	// 记录工作时间的计时器
	afx_msg void OnClickListTypemenu(NMHDR *pNMHDR, LRESULT *pResult);
};
