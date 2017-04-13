// ExistingTrain.cpp: implementation of the CExistingTrain class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TrainTimeTable.h"
#include "ExistingTrain.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CExistingTrain::CExistingTrain()
{
	m_nDepartueTime = 0;
	m_nArrivalTime = 0;
	IsAOriginalLocation = true;
    IsACurrentLocation = true;
    enStatus = Status_Ready;

}

CExistingTrain::~CExistingTrain()
{

}
