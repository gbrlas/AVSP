// SearchEngineQueryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SearchEngineQuery.h"
#include "SearchEngineQueryDlg.h"
#include <fstream.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchEngineQueryDlg dialog

CSearchEngineQueryDlg::CSearchEngineQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchEngineQueryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchEngineQueryDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSearchEngineQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchEngineQueryDlg)
	DDX_Control(pDX, IDC_EDTINPUTFILE, m_EdtInputFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSearchEngineQueryDlg, CDialog)
	//{{AFX_MSG_MAP(CSearchEngineQueryDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNINPUTFILEBROWSER, OnBtninputfilebrowser)
	ON_BN_CLICKED(IDC_BTNGENERATEOUTPUT, OnBtngenerateoutput)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchEngineQueryDlg message handlers

BOOL CSearchEngineQueryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSearchEngineQueryDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSearchEngineQueryDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSearchEngineQueryDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSearchEngineQueryDlg::OnBtninputfilebrowser() 
{
	char strFilterString[] = { "Input Files (*.in)|*.in|All Files (*.*)|*.*||" };

	CFileDialog FileDlgObj(TRUE, ".in", NULL, 0, strFilterString);
		

	if( FileDlgObj.DoModal() == IDOK )
	{
		m_strInputFileName = FileDlgObj.GetPathName( );
		
		CString strFileName = FileDlgObj.GetFileName();
		int nLength = strFileName.GetLength();
		m_strOutputFileName = m_strInputFileName.Left(m_strInputFileName.GetLength() - strFileName.GetLength() );
		m_strOutputFileName += "OutputFile.out";

	}
	else
	{
		return;
	}

	m_EdtInputFile.SetWindowText(m_strInputFileName);
	
 	
}


// Function to process Input File and generate output file
void CSearchEngineQueryDlg::ProcessInputFileData() 
{
	char *fileInput = m_strInputFileName.GetBuffer(m_strInputFileName.GetLength());

	char *fileOutput = m_strOutputFileName.GetBuffer(m_strOutputFileName.GetLength());

	ifstream fInputStream(fileInput);
	ofstream fOutputStream;//(fileOutput);
	fOutputStream.open(fileOutput,ios::out);

	
	char chTestCaseCnt[10];
	// Get the Number of Test Cases
	fInputStream.getline(chTestCaseCnt,100);
	int nTestCaseCnt = atoi(chTestCaseCnt);

	for( int nTestCaseCounter= 0; nTestCaseCounter < nTestCaseCnt; nTestCaseCounter++ )
	{

		// Array to hold Query Strings
		char arrQueryString[1000][100];
		// Array to hold Search Engines
		char arrSearchEngine[100][100];
		
		// Get the Number of Search Engines in the current Test Case
		char chSearchEngineCnt[10];
		fInputStream.getline(chSearchEngineCnt,100);
		int nSearchEngineCnt = atoi(chSearchEngineCnt);
		
		
		// Get the Search Engines
		for( int nCounter = 0; nCounter < nSearchEngineCnt; nCounter++ )
		{
			fInputStream.getline(arrSearchEngine[nCounter],100);
		}


		// Get the Number of queries in the current Test Case
		char chQueryCnt[10];
		fInputStream.getline(chQueryCnt,100);
		int nQueryCnt = atoi(chQueryCnt);
		

		// Get the Query Strings
		for( int nQueryCounter = 0; nQueryCounter < nQueryCnt; nQueryCounter++ )
		{
			fInputStream.getline(arrQueryString[nQueryCounter],100);
		}


		int nCurrentSearchEngineIndex = 0;
		int nSearchEngineLocation = -1;
	
		int nSwitches = 0;
		
		// Traverse through the Queries Array
		for( nQueryCounter = 0; nQueryCounter < nQueryCnt; nQueryCounter++ )
		{
			
			
			// Array to indicate whether the SearchEngine is found in the current Query Block
			bool arrSearchEngineFound[100] = {false};

			// Find the first location of each Search Engine within the current Queries Array Block
			for( int nEngineCounter = 0; nEngineCounter < nSearchEngineCnt; nEngineCounter++ )
			{
				
				// Find the first occurence of the Search Engine within the Query String Array
				for( int nProcessedQueryCounter = nQueryCounter; nProcessedQueryCounter < nQueryCnt; nProcessedQueryCounter++ )
				{
					if( strcmp(arrQueryString[nProcessedQueryCounter],arrSearchEngine[nEngineCounter]) == 0 )
					{
						
						// To indicate whether the search engine has been found
						arrSearchEngineFound[nEngineCounter] = true;

						// If the first position of the SearchEngine within the QueryString is greater
						// than the first position of any other Query String
						if( nProcessedQueryCounter > nSearchEngineLocation )
						{
							// Set the currentSearchIndex
							nCurrentSearchEngineIndex = nEngineCounter;
							// Set the max index of the query already processed
							nSearchEngineLocation = nProcessedQueryCounter;
						}
						break;
					}
					
				}
				
				if( !arrSearchEngineFound[nEngineCounter] )
				{
					// Set the currentSearchIndex
					nCurrentSearchEngineIndex = nEngineCounter;
					// Set the max index of the query already processed
					nSearchEngineLocation = nProcessedQueryCounter - 1;
				}

			}
			
			// This Search Engine String hasn't been found in the queries block
			// Hence this Engine needs to be used from now on
			if( !arrSearchEngineFound[nCurrentSearchEngineIndex] )
			{
				break;
			}
			else
			{
				// Start processing the Queries array from the current location
				nSearchEngineLocation--;
				nQueryCounter = nSearchEngineLocation;
				nSwitches++;
			}
		
			
		}

		// Write to the file the number of switches
		fOutputStream<<" Case #"<<(nTestCaseCounter + 1)<<": "<<nSwitches<<"\n";

						
	}
	
	// Close Input and Output file streams
	fInputStream.close();
	fOutputStream.close();
	

}

void CSearchEngineQueryDlg::OnBtngenerateoutput() 
{

	if( m_strInputFileName.IsEmpty() )
	{
		AfxMessageBox("Please enter valid Input and/or output file names");
	}
	else
	{
		ProcessInputFileData();
	}
}
