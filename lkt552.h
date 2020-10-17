// lkt552.h : main header file for the LKT552 application
//

#if !defined(AFX_LKT552_H__0CB02880_669F_4CCA_93D1_323D63003141__INCLUDED_)
#define AFX_LKT552_H__0CB02880_669F_4CCA_93D1_323D63003141__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLkt552App:
// See lkt552.cpp for the implementation of this class
//

class CLkt552App : public CWinApp
{
public:
	CLkt552App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLkt552App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLkt552App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LKT552_H__0CB02880_669F_4CCA_93D1_323D63003141__INCLUDED_)
