
// RestaurantManagerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "afxdialogex.h"
#include "RestaurantManager.h"
#include "RestaurantManagerDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRestaurantManagerDlg 对话框



CRestaurantManagerDlg::CRestaurantManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RESTAURANTMANAGER_DIALOG, pParent)
	, m_ClientDlg(new CClientDlg())
	, m_HistoryDlg(new CHistoryDlg())
	, m_DishesTypeMenu(&m_listMenu, &m_listTypeMenu)
	, m_DishesOrder(&m_listOrder)
	, m_strCurTime(_T(""))
	, m_strWorkTime(_T(""))
	, workseconds(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CRestaurantManagerDlg::~CRestaurantManagerDlg()
{
}

void CRestaurantManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_USERNAME, m_ctrlUserName);
	DDX_Control(pDX, IDC_STATIC_USERID, m_ctrlUserId);
	DDX_Control(pDX, IDC_LIST_MENU, m_listMenu);
	DDX_Control(pDX, IDC_LIST_ORDER, m_listOrder);
	DDX_Control(pDX, IDC_EDIT_TOTAL, m_bEditTotal);
	DDX_Text(pDX, IDC_STATIC_CURTIME, m_strCurTime);
	DDX_Text(pDX, IDC_STATIC_WORKTIME, m_strWorkTime);
	DDX_Control(pDX, IDC_LIST_TYPEMENU, m_listTypeMenu);
	DDX_Control(pDX, IDC_STATIC_AVATAR, m_sAvatar);
}

BEGIN_MESSAGE_MAP(CRestaurantManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LOGOUT, &CRestaurantManagerDlg::OnBnClickedButtonLogout)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CRestaurantManagerDlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_START_CHECKOUT, &CRestaurantManagerDlg::OnBnClickedButtonStartCheckout)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CRestaurantManagerDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CRestaurantManagerDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_ORDER, &CRestaurantManagerDlg::OnBnClickedButtonOrder)
	ON_COMMAND(ID_MENU_LOGOUT, &CRestaurantManagerDlg::OnMenuLogout)
	ON_COMMAND(ID_MENU_SHOW, &CRestaurantManagerDlg::OnMenuShow)
	ON_COMMAND(ID_MENU_EXIT, &CRestaurantManagerDlg::OnMenuExit)
	ON_COMMAND(ID_MENU_ORDER, &CRestaurantManagerDlg::OnMenuOrder)
	ON_COMMAND(ID_MENU_DELETE, &CRestaurantManagerDlg::OnMenuDelete)
	ON_COMMAND(ID_MENU_CLEAR, &CRestaurantManagerDlg::OnMenuClear)
	ON_COMMAND(ID_MENU_CHECKOUT, &CRestaurantManagerDlg::OnMenuCheckout)
	ON_COMMAND(ID_MENU_HISTORY, &CRestaurantManagerDlg::OnMenuHistory)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_MENU, &CRestaurantManagerDlg::OnDblclkListMenu)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_MENU, &CRestaurantManagerDlg::OnRclickListMenu)
	ON_COMMAND(ID_32788, &CRestaurantManagerDlg::OnDishMenuOrder)
	ON_COMMAND(ID_32792, &CRestaurantManagerDlg::OnOrderMenuAddAgain)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_ORDER, &CRestaurantManagerDlg::OnRclickListOrder)
	ON_COMMAND(ID_32789, &CRestaurantManagerDlg::OnOrderMenuDelete)
	ON_COMMAND(ID_32790, &CRestaurantManagerDlg::OnOrderMenuClear)
	ON_COMMAND(ID_32791, &CRestaurantManagerDlg::OnOrderMenuCheckOut)
	ON_WM_TIMER()
	ON_NOTIFY(NM_CLICK, IDC_LIST_TYPEMENU, &CRestaurantManagerDlg::OnClickListTypemenu)
END_MESSAGE_MAP()


// CRestaurantManagerDlg 消息处理程序

BOOL CRestaurantManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	// 初始化菜单
	initMenuList();

	// 设置头像属性
	m_sAvatar.SetWindowPos(NULL,
		2,		// x坐标
		2,		// y坐标
		133,	// 显示宽度
		133,	// 显示高度
		SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER
	);

	// 初始化历史账单
	m_HistoryDlg->Create(IDD_DIALOG_HISTORY, this);

	// 显示客户端
	m_ClientDlg->Create(IDD_DIALOG_CLIENT, this);
	m_ClientDlg->ShowWindow(SW_SHOW);

	// 启动定时器
	SetTimer(1, 1000, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRestaurantManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRestaurantManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRestaurantManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CRestaurantManagerDlg::initMenuList()
{
	// 用 或 运算符为控件添加额外的网格型属性
	m_listMenu.SetExtendedStyle(m_listMenu.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	// 插入一列，索引号为0，列名为编号，左对齐50像素。下同
	m_listMenu.InsertColumn(0, _T("编号"), LVCFMT_LEFT, 50);
	m_listMenu.InsertColumn(1, _T("菜名"), LVCFMT_LEFT, 150);
	m_listMenu.InsertColumn(2, _T("菜系"), LVCFMT_LEFT, 120);
	m_listMenu.InsertColumn(3, _T("单价"), LVCFMT_LEFT, 110);

	m_listOrder.SetExtendedStyle(m_listOrder.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listOrder.InsertColumn(0, _T("编号"), LVCFMT_LEFT, 50);
	m_listOrder.InsertColumn(1, _T("菜名"), LVCFMT_LEFT, 110);
	m_listOrder.InsertColumn(2, _T("单价"), LVCFMT_LEFT, 70);
	m_listOrder.InsertColumn(3, _T("数量"), LVCFMT_LEFT, 50);
	m_listOrder.InsertColumn(4, _T("价格"), LVCFMT_LEFT, 70);

	m_listTypeMenu.SetExtendedStyle(m_listOrder.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	m_listTypeMenu.InsertColumn(0, _T("类型"), LVCFMT_LEFT, 150);

	CString path = _T("DishMenuData.txt");
	// 读取菜单数据
	while (m_DishesTypeMenu.readData(path) == FALSE) {
		// 清空数据
		m_DishesTypeMenu.clear();
		// 读取失败，退出程序
		if (IDOK == MessageBox(_T("读取数据出错！\n是否手动选择文件路径？"), _T("错误"), MB_OKCANCEL | MB_ICONERROR)) {
			CFileDialog dlg(TRUE);
			if (IDOK == dlg.DoModal()) {
				path = dlg.GetPathName();
			}
		}
		else {
			CDialogEx::OnCancel();
			break;
		}
	}
	// 显示全部菜单
	m_DishesTypeMenu.showMenu(0);
	m_listTypeMenu.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
}


void CRestaurantManagerDlg::OnBnClickedButtonLogout()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CRestaurantManagerDlg::OnBnClickedButtonExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CRestaurantManagerDlg::OnBnClickedButtonStartCheckout()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_DishesOrder.getCount() == 0) {
		MessageBox(_T("账单为空！"), _T("提示"), MB_OK | MB_ICONINFORMATION);
		return;
	}
	CCheckOutDlg dlg;
	if (dlg.DoModal() == IDOK) {
		// 记录账单
		m_HistoryDlg->m_DishesHistory.addOrder(m_DishesOrder);
		// 清空点餐栏
		m_DishesOrder.clearDish();
		// 刷新总价
		m_bEditTotal.SetWindowTextW(m_DishesOrder.getPayment());
	}
}


void CRestaurantManagerDlg::OnBnClickedButtonDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	// 获取当前选择的已点菜品项下标
	int index = m_listOrder.GetNextItem(-1, LVNI_SELECTED);
	// 没有选择删除项时删除最后一项
	if (index == -1) {
		index = m_DishesOrder.getCount() - 1;
	}
	m_DishesOrder.deleteDish(index);
	// 刷新总价
	m_bEditTotal.SetWindowTextW(m_DishesOrder.getPayment());
}


void CRestaurantManagerDlg::OnBnClickedButtonClear()
{
	// TODO: 在此添加控件通知处理程序代码
	int res = MessageBox(_T("确认要清空吗？"), _T("清空"), MB_OKCANCEL | MB_ICONQUESTION);
	if (res == IDOK) {
		m_DishesOrder.clearDish();
		// 刷新总价
		m_bEditTotal.SetWindowTextW(m_DishesOrder.getPayment());
	}
}


void CRestaurantManagerDlg::OnBnClickedButtonOrder()
{
	// TODO: 在此添加控件通知处理程序代码
	int nType = m_listTypeMenu.GetNextItem(-1, LVNI_SELECTED);
	int nOrder = m_listMenu.GetNextItem(-1, LVNI_SELECTED);
	if (nType == -1 || nOrder == -1) {
		MessageBox(_T("未选择添加项！"), _T("提示"), MB_OK | MB_ICONINFORMATION);
		return;
	}

	m_DishesOrder.orderDish(*m_DishesTypeMenu.getMenu(nType)->getDish(nOrder));
	// 刷新总价
	m_bEditTotal.SetWindowTextW(m_DishesOrder.getPayment());
}


void CRestaurantManagerDlg::OnMenuShow()
{
	// TODO: 在此添加命令处理程序代码
	m_ClientDlg->ShowWindow(SW_SHOW);
}


void CRestaurantManagerDlg::OnMenuLogout()
{
	// TODO: 在此添加命令处理程序代码
	this->OnBnClickedButtonLogout();
}


void CRestaurantManagerDlg::OnMenuExit()
{
	// TODO: 在此添加命令处理程序代码
	this->OnBnClickedButtonExit();
}


void CRestaurantManagerDlg::OnMenuOrder()
{
	// TODO: 在此添加命令处理程序代码
	this->OnBnClickedButtonOrder();
}


void CRestaurantManagerDlg::OnMenuDelete()
{
	// TODO: 在此添加命令处理程序代码
	this->OnBnClickedButtonDelete();
}


void CRestaurantManagerDlg::OnMenuClear()
{
	// TODO: 在此添加命令处理程序代码
	this->OnBnClickedButtonClear();
}


void CRestaurantManagerDlg::OnMenuCheckout()
{
	// TODO: 在此添加命令处理程序代码
	this->OnBnClickedButtonStartCheckout();
}


void CRestaurantManagerDlg::OnMenuHistory()
{
	// TODO: 在此添加命令处理程序代码
	m_HistoryDlg->ShowWindow(SW_SHOW);
}


void CRestaurantManagerDlg::OnDblclkListMenu(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	this->OnBnClickedButtonOrder();
}


void CRestaurantManagerDlg::OnRButtonClickedLishCtrl(CListCtrl *listCtrl, UINT IDR)
{
/*	//获取鼠标坐标
	CPoint ptCurSel(0, 0);
	GetCursorPos(&ptCurSel);
	//转换为当前控件坐标系的坐标
	listCtrl->ScreenToClient(&ptCurSel);
	LVHITTESTINFO HitTestInfo;
	HitTestInfo.pt = ptCurSel;
	//判断坐标命中第几项
	int nItem = listCtrl->HitTest(&HitTestInfo);*/

	int nItem = listCtrl->GetNextItem(-1, LVNI_SELECTED);

	//如果有选中项
	if (nItem != -1)
	{
		CPoint point;
		GetCursorPos(&point);
		//弹出菜单
		CMenu menu;
		menu.LoadMenuW(IDR);
		CMenu *pSubMenu = menu.GetSubMenu(0);
		pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
}


void CRestaurantManagerDlg::OnRclickListMenu(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	
	this->OnRButtonClickedLishCtrl(&m_listMenu, IDR_DISHMENU);
}


void CRestaurantManagerDlg::OnDishMenuOrder()
{
	// TODO: 在此添加命令处理程序代码
	this->OnBnClickedButtonOrder();
}


void CRestaurantManagerDlg::OnRclickListOrder(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	this->OnRButtonClickedLishCtrl(&m_listOrder, IDR_ORDERMENU);
}

void CRestaurantManagerDlg::OnClickListTypemenu(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	int index = m_listTypeMenu.GetNextItem(-1, LVNI_SELECTED);
	m_DishesTypeMenu.showMenu(index);
}

void CRestaurantManagerDlg::OnOrderMenuAddAgain()
{
	int nOrder = m_listOrder.GetNextItem(-1, LVNI_SELECTED);
	m_DishesOrder.orderDish(*m_DishesOrder.getDish(nOrder));
	// 刷新总价
	m_bEditTotal.SetWindowTextW(m_DishesOrder.getPayment());
}


void CRestaurantManagerDlg::OnOrderMenuDelete()
{
	// TODO: 在此添加命令处理程序代码
	this->OnBnClickedButtonDelete();
}


void CRestaurantManagerDlg::OnOrderMenuClear()
{
	// TODO: 在此添加命令处理程序代码
	this->OnBnClickedButtonClear();
}


void CRestaurantManagerDlg::OnOrderMenuCheckOut()
{
	// TODO: 在此添加命令处理程序代码
	this->OnBnClickedButtonStartCheckout();
}


void CRestaurantManagerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// 获取当前时间
	CTime t = CTime::GetCurrentTime();
	// 显示当前时间
	m_strCurTime = t.Format(_T("%H:%M:%S"));
	// 工作秒数加一
	workseconds++;
	// 显示工作时间
	m_strWorkTime.Format(_T("%02d:%02d:%02d"), ((workseconds / 60) / 60) % 24, (workseconds / 60) % 60, workseconds % 60);
	UpdateData(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}
