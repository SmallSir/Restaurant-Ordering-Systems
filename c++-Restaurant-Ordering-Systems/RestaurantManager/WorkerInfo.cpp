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
				AfxMessageBox(_T("������߹��Ŵ�����ȷ�Ϻ���������"));
			}
			else
			{
				CDialogEx::OnOK();
			}
		}
	}
}
*/