#pragma once
#include "afx.h"
class CFilex :
	public CFile
{
public:
	CFilex(LPCTSTR lpszFileName, UINT nOpenFlags) 
		:CFile(lpszFileName, nOpenFlags) {}
	struct  people
	{
		int Number;
		CString Password;
		CString Name;
	}p[1000];
	CFilex();
	~CFilex();
};

