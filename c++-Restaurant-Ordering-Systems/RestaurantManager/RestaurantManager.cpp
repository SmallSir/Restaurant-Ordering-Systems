/****************************************************************************************
 * @名称 RestaurantManager 餐厅收银管理系统
 * @作者 长颈鹿小组
 * @成员 刘海波 201531104032  邱振豪 201531104048  于蒙 201531104078  陆洋 201531104038
 * @日期 2016.11.4
 * @功能 餐厅员工登陆和注册、一键完成点餐结账、记录工作时间、客户端实时显示、查看历史账单
 * @实现 各类控件的基本操作、数据库实现登录注册、从文件读取账号和菜单数据、Unicode宽字符处理、
         系统时间的获取、非模态对话框的显示、右击弹出功能菜单、vector容器的使用、
		 操作不当的问题处理、字符串和数字的相互转化、适应窗口大小变化、窗口永远置顶等
****************************************************************************************/



// RestaurantManager.cpp : 应用程序入口类。
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "LoginDlg.h"
#include "RestaurantManagerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRestaurantManagerApp

BEGIN_MESSAGE_MAP(CRestaurantManagerApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CRestaurantManagerApp 构造

CRestaurantManagerApp::CRestaurantManagerApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CRestaurantManagerApp 对象

CRestaurantManagerApp theApp;


// CRestaurantManagerApp 初始化

BOOL CRestaurantManagerApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	// SetRegistryKey(_T("长颈鹿小组"));
	
	do {
		// 显示登录对话框
		CLoginDlg LoginDlg;
		int nResponse = LoginDlg.DoModal();
		// 返回值为IDOK时登录成功，否则退出程序
		if (nResponse != IDOK) {
			break;
		}
		else {
			CRestaurantManagerDlg dlg;
			dlg.ID = LoginDlg.ID;
			dlg.name = LoginDlg.name;
			// 显示主界面
			nResponse = dlg.DoModal();
			// 返回值为IDOK时重新登录，否则退出程序
			if (nResponse != IDOK) {
				break;
			}
		}
	} while (true);

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

