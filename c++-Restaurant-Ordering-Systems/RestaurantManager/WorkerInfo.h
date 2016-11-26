#pragma once
#include "afx.h"
class CWorkerInfo :
	public CObject
{
public:
	virtual void Serialize(CArchive& ar);
	DECLARE_SERIAL(CWorkerInfo);
	CWorkerInfo();
	~CWorkerInfo();
	//void ReaserchPerson(int m_number, CString m_password,int n);
public:
	struct person
	{
		int number;
		CString password;
		CString name;
	}p[100];
};

