// TrainTimeTable.h : main header file for the TRAINTIMETABLE application
//

#if !defined(AFX_TRAINTIMETABLE_H__A2B462D0_8FE0_420D_91C6_06EF724CF56C__INCLUDED_)
#define AFX_TRAINTIMETABLE_H__A2B462D0_8FE0_420D_91C6_06EF724CF56C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTrainTimeTableApp:
// See TrainTimeTable.cpp for the implementation of this class
//

class CTrainTimeTableApp : public CWinApp
{
public:
	CTrainTimeTableApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrainTimeTableApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTrainTimeTableApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAINTIMETABLE_H__A2B462D0_8FE0_420D_91C6_06EF724CF56C__INCLUDED_)
