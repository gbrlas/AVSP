// TrainTimeTableDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TrainTimeTable.h"
#include "TrainTimeTableDlg.h"


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
// CTrainTimeTableDlg dialog

CTrainTimeTableDlg::CTrainTimeTableDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CTrainTimeTableDlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CTrainTimeTableDlg)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrainTimeTableDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CTrainTimeTableDlg)
    DDX_Control(pDX, IDC_EDTINPUTFILE, m_edtInputFile);
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTrainTimeTableDlg, CDialog)
    //{{AFX_MSG_MAP(CTrainTimeTableDlg)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BTNINPUTFILE, OnBtninputfile)
    ON_BN_CLICKED(IDC_BTNOUTPUTFILE, OnBtnoutputfile)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrainTimeTableDlg message handlers

BOOL CTrainTimeTableDlg::OnInitDialog()
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

void CTrainTimeTableDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTrainTimeTableDlg::OnPaint() 
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
HCURSOR CTrainTimeTableDlg::OnQueryDragIcon()
{
    return (HCURSOR) m_hIcon;
}

void CTrainTimeTableDlg::OnBtninputfile() 
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
        m_edtInputFile.SetWindowText(m_strInputFileName);

    }
    
}

void CTrainTimeTableDlg::OnBtnoutputfile() 
{
    ProcessInputFileData();
    
}


// Function to process Input File and generate output file
void CTrainTimeTableDlg::ProcessInputFileData() 
{
    char *fileInput = m_strInputFileName.GetBuffer(m_strInputFileName.GetLength());

    char *fileOutput = m_strOutputFileName.GetBuffer(m_strOutputFileName.GetLength());

    std::ifstream fInputStream(fileInput);
    std::ofstream fOutputStream;
    fOutputStream.open(fileOutput,std::ios::out);

    
    char chTestCaseCnt[10];
    // Get the Number of Test Cases
    fInputStream.getline(chTestCaseCnt,100);
    int nTestCaseCnt = atoi(chTestCaseCnt);

    for( int nTestCaseCounter= 0; nTestCaseCounter < nTestCaseCnt; nTestCaseCounter++ )
    {
        // Vector to hold the TimeTable
        std::vector<CTimeTableInfo> vectorTimeTable;
   
        // Get the Turn Around Time
        char chTurnAroundTime[10];
        fInputStream.getline(chTurnAroundTime,10);
        int nTurnAroundTime = atoi(chTurnAroundTime);

        int nTripsFromA = 0;
        int nTripsFromB = 0;

        // Read the line to obtain the number of trips for A and B
        char chTripsCount[20];
        fInputStream.getline(chTripsCount,20);
        char TokenizeTripsString[20];
        strcpy(TokenizeTripsString,chTripsCount); 

        // Parse the string to obtain the number of trips fom A and B separately
        char *token;
        char seps[]   = " \n";

        // Get the first token: 
        token = strtok( chTripsCount, seps );
        // Obtain Number of Trips from A
        if( token != NULL )
        {
            nTripsFromA = atoi(token);
            // Get next token
            token = strtok( NULL, seps );
            if( token != NULL )
            {
                nTripsFromB = atoi(token);
            }
        }

        CreateTimeTableInfo(vectorTimeTable,fInputStream, nTripsFromA, nTripsFromB,nTurnAroundTime);
        int nCount = vectorTimeTable.size();
        
        SortVectorByDepartueTime(vectorTimeTable);
        int nTrainsFromA =0;
        int nTrainsFromB =0;

        ProcessTrainDepartures(vectorTimeTable,nTrainsFromA,nTrainsFromB);
        // Write to the file the number of switches
        fOutputStream<<" Case #"<<(nTestCaseCounter + 1)<<": "<<nTrainsFromA<<" "<<nTrainsFromB<<"\n";
        vectorTimeTable.clear();
        
    }
    
    // Close Input and Output file streams
    fInputStream.close();
    fOutputStream.close();
    

}

void CTrainTimeTableDlg::ProcessTrainDepartures(std::vector<CTimeTableInfo>& vectorTimeTable,int& nTrainsFromA,int& nTrainsFromB)
{
    std::vector<CExistingTrain> vectorExistingTrains;

    for( int nDepartureCount = 0; nDepartureCount< vectorTimeTable.size(); nDepartureCount++)
    {
        bool bAvailable = FindExistingTrainAvailability(vectorTimeTable[nDepartureCount], vectorExistingTrains,nTrainsFromA,nTrainsFromB);
        if( !bAvailable )
        {
            CExistingTrain objExistingTrain;
            objExistingTrain.enStatus = Status_Running;
            objExistingTrain.IsACurrentLocation = !vectorTimeTable[nDepartureCount].m_bDirectionAToB;
            objExistingTrain.IsAOriginalLocation = vectorTimeTable[nDepartureCount].m_bDirectionAToB;
            objExistingTrain.m_nArrivalTime = vectorTimeTable[nDepartureCount].m_nArrivalTime;
            objExistingTrain.m_nDepartueTime = vectorTimeTable[nDepartureCount].m_nDepartueTime;
            vectorExistingTrains.push_back(objExistingTrain);
            vectorTimeTable[nDepartureCount].m_bProcessed = true;
            if( objExistingTrain.IsAOriginalLocation )
            {
                nTrainsFromA++;
            }
            else
            {
                nTrainsFromB++;
            }
        }
    }
    vectorExistingTrains.clear();

}

bool CTrainTimeTableDlg::FindExistingTrainAvailability(CTimeTableInfo& objTimeTable, std::vector<CExistingTrain>& vectorExistingTrains,int& nTrainsFromA,int& nTrainsFromB)
{
    bool bAvailable = false;
    
    // Check the status of all Running trains
    for(int nExistingTrainCnt= 0; nExistingTrainCnt< vectorExistingTrains.size(); nExistingTrainCnt++)
    {
        if( vectorExistingTrains[nExistingTrainCnt].enStatus == Status_Running 
            && vectorExistingTrains[nExistingTrainCnt].m_nArrivalTime <= objTimeTable.m_nDepartueTime )
        {
            vectorExistingTrains[nExistingTrainCnt].enStatus = Status_Ready;
        }
    }
    
    for(int nExistingTrainCnt= 0; nExistingTrainCnt< vectorExistingTrains.size(); nExistingTrainCnt++)
    {
        if( vectorExistingTrains[nExistingTrainCnt].enStatus == Status_Ready 
            && vectorExistingTrains[nExistingTrainCnt].IsACurrentLocation == objTimeTable.m_bDirectionAToB )
        {
            bAvailable = true;
            vectorExistingTrains[nExistingTrainCnt].enStatus = Status_Running;
            vectorExistingTrains[nExistingTrainCnt].m_nArrivalTime = objTimeTable.m_nArrivalTime;
            vectorExistingTrains[nExistingTrainCnt].m_nDepartueTime = objTimeTable.m_nDepartueTime;
            vectorExistingTrains[nExistingTrainCnt].IsACurrentLocation = !vectorExistingTrains[nExistingTrainCnt].IsACurrentLocation;
            break;
        }

    }

    return bAvailable;
}

void CTrainTimeTableDlg::SortVectorByDepartueTime(std::vector<CTimeTableInfo>& vectorTimeTable)
{
        for( int nOuterIndex=0; nOuterIndex< vectorTimeTable.size(); nOuterIndex++ )
        {
            for(int nInnerIndex= 0; nInnerIndex< vectorTimeTable.size() - 1; nInnerIndex++ )
            {
                if( vectorTimeTable[nInnerIndex + 1].m_nDepartueTime < vectorTimeTable[nInnerIndex].m_nDepartueTime )
                {
                    CTimeTableInfo objTimeTable = vectorTimeTable[nInnerIndex + 1];
                    vectorTimeTable[nInnerIndex + 1] = vectorTimeTable[nInnerIndex];
                    vectorTimeTable[nInnerIndex]= objTimeTable;
                }
            }
        }
}


void CTrainTimeTableDlg::CreateTimeTableInfo(std::vector<CTimeTableInfo>& vectorTimeTable,std::ifstream& fInputStream, int nTripsToA, int nTripsToB, int nTurnAroundTime) 
{
        CreateTimeTableInfo_A(vectorTimeTable,fInputStream,nTripsToA,nTurnAroundTime) ;
        CreateTimeTableInfo_B(vectorTimeTable,fInputStream,nTripsToB,nTurnAroundTime) ;
}

void CTrainTimeTableDlg::CreateTimeTableInfo_A(std::vector<CTimeTableInfo>& vectorTimeTable,std::ifstream& fInputStream, int nTrips, int nTurnAroundTime) 
{
    // Obtain the arrival and departure time from A
    for( int nATripCounter = 0; nATripCounter < nTrips; nATripCounter++ )
    {
        // Read the line to obtain the Departue and Arrival timings of the train
        char chTrainTiming[20];
        fInputStream.getline(chTrainTiming,20);
        char TokenizeTrainTiming[20];
        strcpy(TokenizeTrainTiming,chTrainTiming); 

        
        char *tokenTime;
        char sepsTime[]   = ": \n";

        // Get the first token: 
        tokenTime = strtok( TokenizeTrainTiming, sepsTime );

        int nDepartureHour = 0;
        int nDepartureMinute = 0;
        int nArrivalHour = 0;
        int nArrivalMinute = 0;
        
        // Obtain Number of Trips from A
        if( tokenTime != NULL )
        {
            // Get the hour value for Departue Hour from A
            nDepartureHour = atoi(tokenTime);
            // Get next token i.e value for Departue Minute from A
            tokenTime = strtok( NULL, sepsTime );
            if( tokenTime != NULL )
            {
                nDepartureMinute = atoi(tokenTime);
            }

            // Get the hour value for Arrival Hour at B
            tokenTime = strtok( NULL, sepsTime );
            if( tokenTime != NULL )
            {
                nArrivalHour = atoi(tokenTime);
            }

            // Get the hour value for Arrival Minute at B
            tokenTime = strtok( NULL, sepsTime );
            if( tokenTime != NULL )
            {
                nArrivalMinute = atoi(tokenTime);
            }

        }

        CTimeTableInfo objTimeTable;
        objTimeTable.m_bDirectionAToB = true;
        objTimeTable.m_nDepartueTime = nDepartureHour*60 + nDepartureMinute;
        objTimeTable.m_nArrivalTime = nArrivalHour * 60 + nArrivalMinute + nTurnAroundTime;
        vectorTimeTable.push_back(objTimeTable);

    }
}



void CTrainTimeTableDlg::CreateTimeTableInfo_B(std::vector<CTimeTableInfo>& vectorTimeTable,std::ifstream& fInputStream, int nTrips, int nTurnAroundTime) 
{
    // Obtain the arrival and departure time from A
    for( int nBTripCounter = 0; nBTripCounter < nTrips; nBTripCounter++ )
    {
        // Read the line to obtain the Departue and Arrival timings of the train
        char chTrainTiming[20];
        fInputStream.getline(chTrainTiming,20);
        
        char *tokenTime;
        char sepsTime[]   = ": \n";

        // Get the first token: 
        tokenTime = strtok( chTrainTiming, sepsTime );

        
        int nDepartureHour = 0;
        int nDepartureMinute = 0;
        int nArrivalHour = 0;
        int nArrivalMinute = 0;
        
        
        // Obtain Number of Trips from A
        if( tokenTime != NULL )
        {
         
            // Get the hour value for Departue Hour from B
            nDepartureHour = atoi(tokenTime);
            // Get next token i.e value for Departue Minute from B
            tokenTime = strtok( NULL, sepsTime );
            if( tokenTime != NULL )
            {
                nDepartureMinute = atoi(tokenTime);
            }

            // Get the hour value for Arrival Hour at A
            tokenTime = strtok( NULL, sepsTime );
            if( tokenTime != NULL )
            {
                nArrivalHour = atoi(tokenTime);
            }

            // Get the hour value for Arrival Minute at A
            tokenTime = strtok( NULL, sepsTime );
            if( tokenTime != NULL )
            {
                nArrivalMinute = atoi(tokenTime);
            }

        }

        CTimeTableInfo objTimeTable;
        objTimeTable.m_bDirectionAToB = false;
        objTimeTable.m_nDepartueTime = nDepartureHour*60 + nDepartureMinute;
        objTimeTable.m_nArrivalTime = nArrivalHour * 60 + nArrivalMinute + nTurnAroundTime;
        vectorTimeTable.push_back(objTimeTable);

    }
}