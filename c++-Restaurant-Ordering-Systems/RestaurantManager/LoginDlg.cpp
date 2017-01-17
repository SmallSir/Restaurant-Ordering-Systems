// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "RegisterDlg.h"



// CLoginDlg 对话框

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
	, m_password(_T(""))
	, m_Number(_T(""))
{
	CoInitialize(NULL);
	//注册本地数据库数据源
	SQLConfigDataSource(NULL, ODBC_ADD_DSN, _T("Microsoft Access Driver (*.mdb)"), _T("DSN=RestaurantWorkers;DBQ=Workers.mdb"));
}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_password);
	DDX_Text(pDX, IDC_EDIT1, m_Number);
}

BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CLoginDlg::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_REGISTER, &CLoginDlg::OnBnClickedButtonRegister)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnBnClickedButtonLogin()
{
	UpdateData(true);
	if (m_Number == "")
	{
		AfxMessageBox(_T("帐号为空！"));
	}
	else if (m_password == "")
	{
		AfxMessageBox(_T("密码为空！"));
	}
	else {
		// 创建CDatabase对象，连接数据源
		CDatabase m_db;
		m_db.OpenEx(_T("DSN=RestaurantWorkers;"), CDatabase::noOdbcDialog);
		// 创建CRecordset对象
		CRecordset m_rec(&m_db);
		// SQL语句
		CString strSQL = "select * from Workers";
		// 连接数据库
		m_rec.Open(CRecordset::dynaset, strSQL);
		while (!m_rec.IsEOF())
		{
			// 使用数据库的代码，读出来的数据都是字符串型的
			CString id;
			m_rec.GetFieldValue(short(0), id);  //将某个字段的当前行的值读到MyVirabl中
			// 判断ID是否相同
			if (m_Number.Compare(id) == 0) {
				CString password;
				m_rec.GetFieldValue(short(2), password);
				// 判断密码是否相同
				if (m_password.Compare(password) == 0) {
					// 获取用户姓名
					CString name;
					m_rec.GetFieldValue(short(1), name);
					this->ID = id;
					this->name = name;
					// 关闭对话框
					CDialogEx::OnOK();
					break;
				}
			}
			m_rec.MoveNext(); //将记录移到下一行
		}
		if (m_rec.IsEOF())
		{
			AfxMessageBox(_T("账号或密码错误！"));
		}
		// 断开连接
		m_db.Close();
	}
}



void CLoginDlg::OnBnClickedButtonRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	CRegisterDlg dlg;
	dlg.DoModal();
}


