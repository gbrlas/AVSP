// GoogleCodeJam_0.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <complex>
#include <cstdio>
#include <string.h>
#include <cassert>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

#include <string>
using namespace std;


#define COMMAND_LINE_ARGUMENT_INPUTFILE			"-in:"
#define COMMAND_LINE_ARGUMENT_OUTPUTFILE		"-out:"

#define DEFAULT_OUTPUTFILE_EXTENSION			".out"


bool ProcessFile(char *pszInputFile, char * pszOutputFile);


/**************
	TOOLS
**************/


#define IS_STR_BEGINING(str,with)				(!strncmp((str),(with),strlen(with)))


/* function used to wait before output closes */
void _PauseBeforeExit(void)
{
	wprintf(L"\r\nPress Enter to continue.\r\n");

	getchar();

	return;
}

/*
bool _FileExists(wchar_t *pszPath)
{
	HANDLE				lFile;
	WIN32_FIND_DATA		FileInfo;

	lFile = FindFirstFile(pszPath, &FileInfo);

	if (lFile != INVALID_HANDLE_VALUE)
	{
		FindClose(lFile);
		return true;
	}
	
	return false;
}
*/



/**************
	MAIN
**************/

int main(int argc, char * argv[])
{
	int		iReturnCode = -1 /* default=error */;
	char *pszInputFile = NULL;
	char *pszOutputFile = NULL;

	/* check that we have enough arguments */
	if (argc < 2)
	{
		printf("Not enough arguments!\r\n");
		goto lblEnd;
	}

	/* processes command line arguments */
	for (int iArg = 1; iArg < argc; iArg ++)
	{
		if (IS_STR_BEGINING(argv[iArg], COMMAND_LINE_ARGUMENT_INPUTFILE))
		{
			char *pszIn = (argv[iArg] + strlen(COMMAND_LINE_ARGUMENT_INPUTFILE));

			pszInputFile = strdup(pszIn);
		}
		else if (IS_STR_BEGINING(argv[iArg], COMMAND_LINE_ARGUMENT_OUTPUTFILE))
		{
			char *pszOut = (argv[iArg] + strlen(COMMAND_LINE_ARGUMENT_OUTPUTFILE));

			pszOutputFile = strdup(pszOut);
		}
	}

	/* missing the input file argument */
	if (!pszInputFile)
	{
		printf("Missing input file argument!\r\n");
		goto lblEnd;
	}

	/* no output file specified, we'll create it ourselves */
	if (!pszOutputFile)
	{
		size_t		nAllocSize = (strlen(pszInputFile) + strlen(DEFAULT_OUTPUTFILE_EXTENSION) + 1) * sizeof(char);

		pszOutputFile = (char *)malloc(nAllocSize);
		snprintf(pszOutputFile, nAllocSize, "%s%s", pszInputFile, DEFAULT_OUTPUTFILE_EXTENSION);
	}

	printf("Input file=%s \r\n", pszInputFile);
	printf("Output file=%s \r\n", pszOutputFile);

	/* check that the file exists in the file system */
	/*if (!_FileExists(pszInputFile))
	{
		wprintf(L"Input file does not exist!\r\n");
		goto lblEnd;
	}*/

	/* launch processing of the input file to the output file */
	if (ProcessFile(pszInputFile, pszOutputFile))
	{
		/* return success */
		iReturnCode = 0;
		printf("\r\nOperation successful.\r\n");
	}


lblEnd:

	free(pszInputFile);
	free(pszOutputFile);

	_PauseBeforeExit();

	return iReturnCode;
}





/****************
	PROCESSING
****************/


/* core function that processes the intput file into an output file */
bool ProcessFile(char *pszInputFile, char * pszOutputFile)
{
	fstream		f_in;
	fstream		f_out;
	string		strEndOfLine;
	bool		bRet = true;

	f_in.open(pszInputFile, std::ios_base::in);
	f_out.open(pszOutputFile, std::ios_base::out);

	int		iT;

	f_in >> iT;
	
	getline(f_in, strEndOfLine);

	printf("This input file contains %d entries.\r\n",  iT);

	for (int iEntry = 1; iEntry <= iT; iEntry ++)
	{
		string		strQuery;

		getline(f_in, strQuery);

		int dN;
		int dK;
		sscanf(strQuery.c_str(), "%d %d", &dN, &dK);
		
		unsigned int dMinK = (unsigned int)pow(2, dN) - 1;
		bool bLight = ((dK & dMinK) == dMinK);

		// set the output string
		f_out << "Case #" << iEntry << ": " << (bLight ? "ON" : "OFF") << "\n";
	}

	bRet = true;

	f_in.close();
	f_out.close();

	return bRet;
}


