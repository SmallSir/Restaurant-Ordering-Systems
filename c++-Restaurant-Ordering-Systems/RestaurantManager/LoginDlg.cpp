// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RestaurantManager.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "RegisterDlg.h"



// CLoginDlg �Ի���

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
	, m_password(_T(""))
	, m_Number(_T(""))
{
	CoInitialize(NULL);
	//ע�᱾�����ݿ�����Դ
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


// CLoginDlg ��Ϣ�������


void CLoginDlg::OnBnClickedButtonLogin()
{
	UpdateData(true);
	if (m_Number == "")
	{
		AfxMessageBox(_T("�ʺ�Ϊ�գ�"));
	}
	else if (m_password == "")
	{
		AfxMessageBox(_T("����Ϊ�գ�"));
	}
	else {
		// ����CDatabase������������Դ
		CDatabase m_db;
		m_db.OpenEx(_T("DSN=RestaurantWorkers;"), CDatabase::noOdbcDialog);
		// ����CRecordset����
		CRecordset m_rec(&m_db);
		// SQL���
		CString strSQL = "select * from Workers";
		// �������ݿ�
		m_rec.Open(CRecordset::dynaset, strSQL);
		while (!m_rec.IsEOF())
		{
			// ʹ�����ݿ�Ĵ��룬�����������ݶ����ַ����͵�
			CString id;
			m_rec.GetFieldValue(short(0), id);  //��ĳ���ֶεĵ�ǰ�е�ֵ����MyVirabl��
			// �ж�ID�Ƿ���ͬ
			if (m_Number.Compare(id) == 0) {
				CString password;
				m_rec.GetFieldValue(short(2), password);
				// �ж������Ƿ���ͬ
				if (m_password.Compare(password) == 0) {
					// ��ȡ�û�����
					CString name;
					m_rec.GetFieldValue(short(1), name);
					this->ID = id;
					this->name = name;
					// �رնԻ���
					CDialogEx::OnOK();
					break;
				}
			}
			m_rec.MoveNext(); //����¼�Ƶ���һ��
		}
		if (m_rec.IsEOF())
		{
			AfxMessageBox(_T("�˺Ż��������"));
		}
		// �Ͽ�����
		m_db.Close();
	}
}



void CLoginDlg::OnBnClickedButtonRegister()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRegisterDlg dlg;
	dlg.DoModal();
}


