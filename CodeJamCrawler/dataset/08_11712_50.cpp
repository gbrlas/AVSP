// TimeTableInfo.cpp: implementation of the CTimeTableInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TrainTimeTable.h"
#include "TimeTableInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTimeTableInfo::CTimeTableInfo()
{

	m_nDepartueTime = 0;
	m_nArrivalTime = 0;
	m_bDirectionAToB = true;
	m_bProcessed = false;

}

CTimeTableInfo::~CTimeTableInfo()
{

}
