// ExistingTrain.h: interface for the CExistingTrain class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXISTINGTRAIN_H__BB9F291A_3FF4_4D5A_B599_73ACCF4CCCB3__INCLUDED_)
#define AFX_EXISTINGTRAIN_H__BB9F291A_3FF4_4D5A_B599_73ACCF4CCCB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum Status
{
    Status_Ready,
    Status_Running
};

class CExistingTrain  
{
public:
	CExistingTrain();
	virtual ~CExistingTrain();

	UINT m_nDepartueTime;
	UINT m_nArrivalTime;
	bool IsAOriginalLocation;
    bool IsACurrentLocation;
	Status enStatus;

};

#endif // !defined(AFX_EXISTINGTRAIN_H__BB9F291A_3FF4_4D5A_B599_73ACCF4CCCB3__INCLUDED_)
