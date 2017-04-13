// TrainTimeTableDlg.h : header file
//

#if !defined(AFX_TRAINTIMETABLEDLG_H__4050A8EC_5051_4905_8E67_6D010C06D44B__INCLUDED_)
#define AFX_TRAINTIMETABLEDLG_H__4050A8EC_5051_4905_8E67_6D010C06D44B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TimeTableInfo.h"
#include "ExistingTrain.h"
#include<vector>
#include <fstream>
/////////////////////////////////////////////////////////////////////////////
// CTrainTimeTableDlg dialog

class CTrainTimeTableDlg : public CDialog
{
// Construction
public:
	CTrainTimeTableDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTrainTimeTableDlg)
	enum { IDD = IDD_TRAINTIMETABLE_DIALOG };
	CEdit	m_edtInputFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrainTimeTableDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CString m_strInputFileName;
	CString m_strOutputFileName;
	
	
	
	


	//Function Declarations
	void ProcessInputFileData();
	
    void CreateTimeTableInfo(std::vector<CTimeTableInfo>& vectorTimeTable,std::ifstream& fInputStream,int nTripsToA, int nTripsToB, int nTurnAroundTime) ;

	void CreateTimeTableInfo_A(std::vector<CTimeTableInfo>& vectorTimeTable,std::ifstream& fInputStream,int nTripsToA, int nTurnAroundTime) ;

	void CreateTimeTableInfo_B(std::vector<CTimeTableInfo>& vectorTimeTable,std::ifstream& fInputStream,int nTripsToB, int nTurnAroundTime) ;

	void SortVectorByDepartueTime(std::vector<CTimeTableInfo>& vectorTimeTable);

    void ProcessTrainDepartures(std::vector<CTimeTableInfo>& vectorTimeTable,int& nTrainsFromA,int& nTrainsFromB);
    
    bool CTrainTimeTableDlg::FindExistingTrainAvailability(CTimeTableInfo& vectorTimeTable,std::vector<CExistingTrain>& vectorExistingTrains,int& nTrainsFromA,int& nTrainsFromB);

	// Generated message map functions
	//{{AFX_MSG(CTrainTimeTableDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtninputfile();
	afx_msg void OnBtnoutputfile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAINTIMETABLEDLG_H__4050A8EC_5051_4905_8E67_6D010C06D44B__INCLUDED_)
