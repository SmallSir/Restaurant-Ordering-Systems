#include "stdafx.h"
#include "WorkerInfo.h"


void CWorkerInfo::Serialize(CArchive & ar)
{
	CObject::Serialize(ar);
}

CWorkerInfo::CWorkerInfo()
{
}


CWorkerInfo::~CWorkerInfo()
{
}
/*
void CWorkerInfo::ReaserchPerson(int m_number, CString m_password,int n)
{
	int i;
	for (i = 0; i <= n; i++)
	{
		if (p[i].number == m_number)
		{
			if (p[i].password != m_password)
			{
				AfxMessageBox(_T("密码或者工号错误，请确认后重新输入"));
			}
			else
			{
				CDialogEx::OnOK();
			}
		}
	}
}
*/