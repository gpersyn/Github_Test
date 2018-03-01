
// Hello_World.h : main header file for the Hello_World application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CHello_WorldApp:
// See Hello_World.cpp for the implementation of this class
//

class CHello_WorldApp : public CWinAppEx
{
public:
	CHello_WorldApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHello_WorldApp theApp;
