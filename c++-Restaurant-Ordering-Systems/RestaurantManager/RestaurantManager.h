
// RestaurantManager.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRestaurantManagerApp: 
// �йش����ʵ�֣������ RestaurantManager.cpp
//

class CRestaurantManagerApp : public CWinApp
{
public:
	CRestaurantManagerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRestaurantManagerApp theApp;