// TimeTableInfo.h: interface for the CTimeTableInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMETABLEINFO_H__A8801492_3B1B_4336_96D2_2582240DEDFC__INCLUDED_)
#define AFX_TIMETABLEINFO_H__A8801492_3B1B_4336_96D2_2582240DEDFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTimeTableInfo  
{
public:
	CTimeTableInfo();
	virtual ~CTimeTableInfo();

	UINT m_nDepartueTime;
	UINT m_nArrivalTime;
	bool m_bDirectionAToB;
	bool m_bProcessed;


};

#endif // !defined(AFX_TIMETABLEINFO_H__A8801492_3B1B_4336_96D2_2582240DEDFC__INCLUDED_)
