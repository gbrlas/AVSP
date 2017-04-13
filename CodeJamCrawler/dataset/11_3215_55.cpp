// CandySplittingA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <vector>
#include <string>
#include <atlstr.h>
#include <tchar.h>
#include <fstream>
#include <algorithm>
#include <functional>

typedef std::string				string;
typedef std::wstring			wstring;
typedef std::vector<string>		strings;
typedef std::vector<wstring>	wstrings;

typedef std::vector<unsigned int> UINTS;

typedef struct SEQINPUT {
	unsigned int nTestCase;
	UINTS tCandy;

	SEQINPUT() {
		nTestCase = 0;
	};

	SEQINPUT(const SEQINPUT& src) {
		nTestCase = src.nTestCase;
		tCandy = src.tCandy;
	};

	SEQINPUT& operator =(const SEQINPUT& src) {
		nTestCase = src.nTestCase;
		tCandy = src.tCandy;
		return *this;
	};

} SEQINPUT;
typedef std::vector<SEQINPUT> SEQINPUTS;

/*
sample input
2
5
1 2 3 4 5
3
3 5 6

sample output
Case #1: NO
Case #2: 11
*/

int SplitA(strings& dest, const string& src, LPCSTR p, const bool bIncludeEmpty)
{
	dest.clear();

	if (NULL == p) {
		string::size_type nLength = src.size();
		if (nLength > 0) {
			int nPos = 0;
			string sz;
			for (string::const_iterator it = src.begin(); it != src.end(); ++it, nPos++) {
				if (CHAR('\0') != *it) {
					sz += *it;
				} else if (bIncludeEmpty || (!bIncludeEmpty && !sz.empty())) {
					dest.insert(dest.end(), sz);
					sz.clear();
				}
			}
			if (bIncludeEmpty || (!bIncludeEmpty && !sz.empty()))
				dest.insert(dest.end(), sz);
		}
	} else {
		string sep = p;
		string::size_type nSepLen = sep.size();
		if (nSepLen <= 0) {
			dest.insert(dest.end(), src);
		} else {
			string::size_type nLength = src.size();
			if (nLength > 0) {
				string::size_type nPos = 0, nPosFrom = 0;
				string sz, s;
				CString cstr;
				do {
					nPos = src.find(sep.c_str(), nPosFrom);
					if (0 == nPos) {
						if (bIncludeEmpty)
							dest.insert(dest.end(), "");
						nPosFrom = nPos + nSepLen;
					} else if (string::npos == nPos) {
						sz = src.substr(nPosFrom);
						s = sz;
						cstr = sz.c_str();
						cstr.Trim();
						if (bIncludeEmpty || (!bIncludeEmpty && !cstr.IsEmpty()))
							dest.insert(dest.end(), s);
						break;
					} else {
						sz = src.substr(nPosFrom, nPos - nPosFrom);
						s = sz;
						cstr = sz.c_str();
						cstr.Trim();
						if (bIncludeEmpty || (!bIncludeEmpty && !cstr.IsEmpty()))
							dest.insert(dest.end(), s);
						nPosFrom = nPos + nSepLen;
					}
				} while (nPos >= 0);
			}
		}
	}

	return (int)dest.size();
}

bool GetInput(const string& sInput, SEQINPUTS* pSeqInput)
{
	if (!pSeqInput)
		return false;
	pSeqInput->clear();

	// split to lines
	strings sLines;
	SplitA(sLines, sInput, "\n", false);
	if (sLines.empty())
		return false;

	// examine each line
	strings sItem;
	int nCount = 0, i = 0, nTestCase = 0,  nLine = 0;
	for (strings::iterator it = sLines.begin(); it != sLines.end(); ++it, nLine++) {
		if (0 == nLine)
			continue;
		if (1 == nLine %2)
			continue;

		SEQINPUT input;
		input.nTestCase = ++nTestCase;

		nCount = SplitA(sItem, *it, " ", false);
		if (nCount > 0) {
			unsigned int nData = 0;
			for (strings::iterator itdata = sItem.begin(); itdata != sItem.end(); ++itdata) {
				nData = atoi(itdata->c_str());
				input.tCandy.push_back(nData);
			}
			sort(input.tCandy.begin(), input.tCandy.end(), std::greater<unsigned int>());
		}
		pSeqInput->push_back(input);
	}
	return !pSeqInput->empty();
}

bool SetOutput(LPCTSTR lpszOutfile, const SEQINPUTS* pSeqInput)
{
	if (!lpszOutfile || !pSeqInput || pSeqInput->empty())
		return false;

	std::fstream output(lpszOutfile, std::fstream::out);
	for (SEQINPUTS::const_iterator it = pSeqInput->begin(); it != pSeqInput->end(); ++it) {
		// xor from highest number, the remaing add should equal
		unsigned int nTotalSeanActual = 0, nTotalSeanMax = 0, nTotalSean = 0, nTotalPatrick = 0;
		bool bOk = false;
		int nCount = it->tCandy.size();
		if (nCount > 0) {
			// no skipping
			for (int i = 0; i < nCount -1; i++) {
				nTotalSean = 0;
				nTotalPatrick = 0;
				for (int j = 0; j <= i; j++)
					nTotalSean ^= it->tCandy.at(j);
				for (int k = i +1; k < nCount; k++)
					nTotalPatrick ^= it->tCandy.at(k);
				if (nTotalSean == nTotalPatrick) {
					// get Sean actual total
					nTotalSeanActual = 0;
					for (int j = 0; j <= i; j++)
						nTotalSeanActual += it->tCandy.at(j);
					if (nTotalSeanActual > nTotalSeanMax) {
						nTotalSeanMax = nTotalSeanActual;
						bOk = true;
					}
				}
			}
		}
		if (bOk)
			output << "Case #" << it->nTestCase << ": " << nTotalSeanMax << std::endl;
		else
			output << "Case #" << it->nTestCase << ": " << "NO" << std::endl;
	}
	output.close();
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// check number of argument
	if (3 != argc)
		return -1;

	// get input and output filenames
	CString sArg1(argv[1]), sArg2(argv[2]);
	CString sInfile, sOutfile;
	if (0 == sArg1.Left(3).CompareNoCase(_T("-i="))) {
		sInfile = sArg1.Mid(3);
		if (0 == sArg2.Left(3).CompareNoCase(_T("-o=")))
			sOutfile = sArg2.Mid(3);
		else
			return -1;
	} else if (0 == sArg1.Left(3).CompareNoCase(_T("-o="))) {
		sOutfile = sArg1.Mid(3);
		if (0 == sArg2.Left(3).CompareNoCase(_T("-i=")))
			sInfile = sArg2.Mid(3);
		else
			return -1;
	} else
		return -1;
	if (sInfile.IsEmpty() || sOutfile.IsEmpty())
		return -1;
	if (!PathFileExists(sInfile))
		return -1;

	// open input file
	HANDLE hInfile = CreateFile(sInfile, GENERIC_READ, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hInfile)
		return -1;

	string sInput;
	DWORD dwSize = GetFileSize(hInfile, NULL);
	if (INVALID_FILE_SIZE != dwSize) {
		char* pBuf = new char[dwSize +1];
		ZeroMemory(pBuf, dwSize +1);
		DWORD dwBytesRead = 0;
		if (ReadFile(hInfile, (LPVOID)pBuf, dwSize, &dwBytesRead, NULL))
			sInput = string(pBuf, dwBytesRead);
		delete[] pBuf;
	}
	CloseHandle(hInfile);
	if (sInput.empty())
		return -1;

	// check sequence given
	SEQINPUTS tInput;
	if (!GetInput(sInput, &tInput))
		return -1;

	// generate output
	if (!SetOutput(sOutfile, &tInput))
		return -1;

	return 0;
}

