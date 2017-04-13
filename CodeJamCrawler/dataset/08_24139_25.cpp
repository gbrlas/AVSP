// SearchEng.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SearchEng.h"
#include <stdio.h>
#include <afxcoll.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

void Pass2Map (CStringList& lst, CMapStringToPtr & map)
{
	__int64 lstsize = lst.GetCount();
	int i;
	POSITION pos;
	
	for (i = 0;i < lstsize ; i++)
	{
		pos = lst.FindIndex(i);
		map.SetAt(lst.GetAt(pos), (void *)i);
	}
}


void 	HandleCase (int CaseNum, CStringList& engines, CStringList& requests, FILE *pout)
{

	CMapStringToPtr engines_map;
	POSITION pos = requests.GetHeadPosition();
	__int64 iCount = requests.GetCount();
	int iCounter = -1;
	void * stam = NULL;

	int i;
	CMapStringToPtr engines_cr;

	Pass2Map(engines, engines_cr);

	for (i = 0; i < iCount; i++)
	{
		bool bfound = false;
		pos = requests.FindIndex(i);
		if (engines_cr.GetCount() == 1)
		{
			bfound = true;
		}


		engines_cr.RemoveKey(requests.GetAt(pos));
		if (engines_cr.GetCount() == 0 && bfound)
		{
			iCounter ++;
			Pass2Map(engines, engines_cr);
			engines_cr.RemoveKey(requests.GetAt(pos));
		}

	}

	fprintf (pout, "Case #%d: %d\n", CaseNum + 1, iCounter + 1);
}



int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: MFC initialization failed\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
	}

	if (argc != 3) return 0;

	FILE * pin, *pout;

	pin = fopen (argv[1], "r");
	pout = fopen (argv[2], "w");


	int inumcases;

	if (!pin || !pout)
	{
		return 0;
	}

	fscanf (pin, "%d", &inumcases);

	CStringList engines;
	CStringList requests;

	int icases;

	for ( icases = 0; icases < inumcases;icases ++)
	{
		// cleanup
		engines.RemoveAll();
		requests.RemoveAll();

		int inumengines;
		int inumrequests;

		char szstr[1024 * 4];
		int j;

		fscanf (pin, "%d\n" , &inumengines);

		for (j = 0; j < inumengines; j ++)
		{
			fgets(szstr, 1024*4, pin);
			CString cs(szstr);
			engines.AddTail(cs);
		}

		fscanf (pin, "%d\n" , &inumrequests);

		for (j = 0; j < inumrequests; j ++)
		{
			fgets(szstr, 1024*4, pin);
			CString cs(szstr);
			requests.AddTail(cs);
		}
	
		HandleCase (icases, engines, requests, pout);
	}
	return nRetCode;
}
