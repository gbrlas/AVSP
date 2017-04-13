// SearchEngineQueryDlg.h : header file
//

#if !defined(AFX_SEARCHENGINEQUERYDLG_H__CEBFF389_FBE1_4E5D_AFA7_B2275AA82668__INCLUDED_)
#define AFX_SEARCHENGINEQUERYDLG_H__CEBFF389_FBE1_4E5D_AFA7_B2275AA82668__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSearchEngineQueryDlg dialog

class CSearchEngineQueryDlg : public CDialog
{
// Construction
public:
	CSearchEngineQueryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchEngineQueryDlg)
	enum { IDD = IDD_SEARCHENGINEQUERY_DIALOG };
	CEdit	m_EdtInputFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchEngineQueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CString m_strInputFileName;
	CString m_strOutputFileName;
	//char m_QueryString[1000][100];
	//char m_SearchEngine[100][100];

	//Function Declarations
	void ProcessInputFileData();

	// Generated message map functions
	//{{AFX_MSG(CSearchEngineQueryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtninputfilebrowser();
	afx_msg void OnBtngenerateoutput();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHENGINEQUERYDLG_H__CEBFF389_FBE1_4E5D_AFA7_B2275AA82668__INCLUDED_)
