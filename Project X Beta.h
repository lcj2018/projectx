
// Project X Beta.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CProjectXBetaApp: 
// �йش����ʵ�֣������ Project X Beta.cpp
//

class CProjectXBetaApp : public CWinApp
{
public:
	CProjectXBetaApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CProjectXBetaApp theApp;