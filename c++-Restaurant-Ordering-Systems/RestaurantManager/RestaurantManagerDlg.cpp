
// RestaurantManagerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "afxdialogex.h"
#include "RestaurantManager.h"
#include "RestaurantManagerDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CRestaurantManagerDlg �Ի���



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


// CRestaurantManagerDlg ��Ϣ�������

BOOL CRestaurantManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	// ��ʼ���˵�
	initMenuList();

	// ����ͷ������
	m_sAvatar.SetWindowPos(NULL,
		2,		// x����
		2,		// y����
		133,	// ��ʾ���
		133,	// ��ʾ�߶�
		SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER
	);

	// ��ʼ����ʷ�˵�
	m_HistoryDlg->Create(IDD_DIALOG_HISTORY, this);

	// ��ʾ�ͻ���
	m_ClientDlg->Create(IDD_DIALOG_CLIENT, this);
	m_ClientDlg->ShowWindow(SW_SHOW);

	// ������ʱ��
	SetTimer(1, 1000, NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRestaurantManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRestaurantManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CRestaurantManagerDlg::initMenuList()
{
	// �� �� �����Ϊ�ؼ���Ӷ��������������
	m_listMenu.SetExtendedStyle(m_listMenu.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	// ����һ�У�������Ϊ0������Ϊ��ţ������50���ء���ͬ
	m_listMenu.InsertColumn(0, _T("���"), LVCFMT_LEFT, 50);
	m_listMenu.InsertColumn(1, _T("����"), LVCFMT_LEFT, 150);
	m_listMenu.InsertColumn(2, _T("��ϵ"), LVCFMT_LEFT, 120);
	m_listMenu.InsertColumn(3, _T("����"), LVCFMT_LEFT, 110);

	m_listOrder.SetExtendedStyle(m_listOrder.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listOrder.InsertColumn(0, _T("���"), LVCFMT_LEFT, 50);
	m_listOrder.InsertColumn(1, _T("����"), LVCFMT_LEFT, 110);
	m_listOrder.InsertColumn(2, _T("����"), LVCFMT_LEFT, 70);
	m_listOrder.InsertColumn(3, _T("����"), LVCFMT_LEFT, 50);
	m_listOrder.InsertColumn(4, _T("�۸�"), LVCFMT_LEFT, 70);

	m_listTypeMenu.SetExtendedStyle(m_listOrder.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	m_listTypeMenu.InsertColumn(0, _T("����"), LVCFMT_LEFT, 150);

	CString path = _T("DishMenuData.txt");
	// ��ȡ�˵�����
	while (m_DishesTypeMenu.readData(path) == FALSE) {
		// �������
		m_DishesTypeMenu.clear();
		// ��ȡʧ�ܣ��˳�����
		if (IDOK == MessageBox(_T("��ȡ���ݳ���\n�Ƿ��ֶ�ѡ���ļ�·����"), _T("����"), MB_OKCANCEL | MB_ICONERROR)) {
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
	// ��ʾȫ���˵�
	m_DishesTypeMenu.showMenu(0);
	m_listTypeMenu.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
}


void CRestaurantManagerDlg::OnBnClickedButtonLogout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CRestaurantManagerDlg::OnBnClickedButtonExit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CRestaurantManagerDlg::OnBnClickedButtonStartCheckout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_DishesOrder.getCount() == 0) {
		MessageBox(_T("�˵�Ϊ�գ�"), _T("��ʾ"), MB_OK | MB_ICONINFORMATION);
		return;
	}
	CCheckOutDlg dlg;
	if (dlg.DoModal() == IDOK) {
		// ��¼�˵�
		m_HistoryDlg->m_DishesHistory.addOrder(m_DishesOrder);
		// ��յ����
		m_DishesOrder.clearDish();
		// ˢ���ܼ�
		m_bEditTotal.SetWindowTextW(m_DishesOrder.getPayment());
	}
}


void CRestaurantManagerDlg::OnBnClickedButtonDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// ��ȡ��ǰѡ����ѵ��Ʒ���±�
	int index = m_listOrder.GetNextItem(-1, LVNI_SELECTED);
	// û��ѡ��ɾ����ʱɾ�����һ��
	if (index == -1) {
		index = m_DishesOrder.getCount() - 1;
	}
	m_DishesOrder.deleteDish(index);
	// ˢ���ܼ�
	m_bEditTotal.SetWindowTextW(m_DishesOrder.getPayment());
}


void CRestaurantManagerDlg::OnBnClickedButtonClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int res = MessageBox(_T("ȷ��Ҫ�����"), _T("���"), MB_OKCANCEL | MB_ICONQUESTION);
	if (res == IDOK) {
		m_DishesOrder.clearDish();
		// ˢ���ܼ�
		m_bEditTotal.SetWindowTextW(m_DishesOrder.getPayment());
	}
}


void CRestaurantManagerDlg::OnBnClickedButtonOrder()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nType = m_listTypeMenu.GetNextItem(-1, LVNI_SELECTED);
	int nOrder = m_listMenu.GetNextItem(-1, LVNI_SELECTED);
	if (nType == -1 || nOrder == -1) {
		MessageBox(_T("δѡ������"), _T("��ʾ"), MB_OK | MB_ICONINFORMATION);
		return;
	}

	m_DishesOrder.orderDish(*m_DishesTypeMenu.getMenu(nType)->getDish(nOrder));
	// ˢ���ܼ�
	m_bEditTotal.SetWindowTextW(m_DishesOrder.getPayment());
}


void CRestaurantManagerDlg::OnMenuShow()
{
	// TODO: �ڴ���������������
	m_ClientDlg->ShowWindow(SW_SHOW);
}


void CRestaurantManagerDlg::OnMenuLogout()
{
	// TODO: �ڴ���������������
	this->OnBnClickedButtonLogout();
}


void CRestaurantManagerDlg::OnMenuExit()
{
	// TODO: �ڴ���������������
	this->OnBnClickedButtonExit();
}


void CRestaurantManagerDlg::OnMenuOrder()
{
	// TODO: �ڴ���������������
	this->OnBnClickedButtonOrder();
}


void CRestaurantManagerDlg::OnMenuDelete()
{
	// TODO: �ڴ���������������
	this->OnBnClickedButtonDelete();
}


void CRestaurantManagerDlg::OnMenuClear()
{
	// TODO: �ڴ���������������
	this->OnBnClickedButtonClear();
}


void CRestaurantManagerDlg::OnMenuCheckout()
{
	// TODO: �ڴ���������������
	this->OnBnClickedButtonStartCheckout();
}


void CRestaurantManagerDlg::OnMenuHistory()
{
	// TODO: �ڴ���������������
	m_HistoryDlg->ShowWindow(SW_SHOW);
}


void CRestaurantManagerDlg::OnDblclkListMenu(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	this->OnBnClickedButtonOrder();
}


void CRestaurantManagerDlg::OnRButtonClickedLishCtrl(CListCtrl *listCtrl, UINT IDR)
{
/*	//��ȡ�������
	CPoint ptCurSel(0, 0);
	GetCursorPos(&ptCurSel);
	//ת��Ϊ��ǰ�ؼ�����ϵ������
	listCtrl->ScreenToClient(&ptCurSel);
	LVHITTESTINFO HitTestInfo;
	HitTestInfo.pt = ptCurSel;
	//�ж��������еڼ���
	int nItem = listCtrl->HitTest(&HitTestInfo);*/

	int nItem = listCtrl->GetNextItem(-1, LVNI_SELECTED);

	//�����ѡ����
	if (nItem != -1)
	{
		CPoint point;
		GetCursorPos(&point);
		//�����˵�
		CMenu menu;
		menu.LoadMenuW(IDR);
		CMenu *pSubMenu = menu.GetSubMenu(0);
		pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
}


void CRestaurantManagerDlg::OnRclickListMenu(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	
	this->OnRButtonClickedLishCtrl(&m_listMenu, IDR_DISHMENU);
}


void CRestaurantManagerDlg::OnDishMenuOrder()
{
	// TODO: �ڴ���������������
	this->OnBnClickedButtonOrder();
}


void CRestaurantManagerDlg::OnRclickListOrder(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	this->OnRButtonClickedLishCtrl(&m_listOrder, IDR_ORDERMENU);
}

void CRestaurantManagerDlg::OnClickListTypemenu(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	int index = m_listTypeMenu.GetNextItem(-1, LVNI_SELECTED);
	m_DishesTypeMenu.showMenu(index);
}

void CRestaurantManagerDlg::OnOrderMenuAddAgain()
{
	int nOrder = m_listOrder.GetNextItem(-1, LVNI_SELECTED);
	m_DishesOrder.orderDish(*m_DishesOrder.getDish(nOrder));
	// ˢ���ܼ�
	m_bEditTotal.SetWindowTextW(m_DishesOrder.getPayment());
}


void CRestaurantManagerDlg::OnOrderMenuDelete()
{
	// TODO: �ڴ���������������
	this->OnBnClickedButtonDelete();
}


void CRestaurantManagerDlg::OnOrderMenuClear()
{
	// TODO: �ڴ���������������
	this->OnBnClickedButtonClear();
}


void CRestaurantManagerDlg::OnOrderMenuCheckOut()
{
	// TODO: �ڴ���������������
	this->OnBnClickedButtonStartCheckout();
}


void CRestaurantManagerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	// ��ȡ��ǰʱ��
	CTime t = CTime::GetCurrentTime();
	// ��ʾ��ǰʱ��
	m_strCurTime = t.Format(_T("%H:%M:%S"));
	// ����������һ
	workseconds++;
	// ��ʾ����ʱ��
	m_strWorkTime.Format(_T("%02d:%02d:%02d"), ((workseconds / 60) / 60) % 24, (workseconds / 60) % 60, workseconds % 60);
	UpdateData(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}
