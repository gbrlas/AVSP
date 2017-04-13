// BotTrustA.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <map>
#include <vector>
#include <string>
#include <atlstr.h>
#include <tchar.h>
#include <fstream>

typedef std::string				string;
typedef std::wstring			wstring;
typedef std::vector<string>		strings;
typedef std::vector<wstring>	wstrings;

typedef struct ROBOTSEQ {
	bool bBlue;
	unsigned int nButton;

	ROBOTSEQ() {
		bBlue = false;
		nButton = 0;
	};

	ROBOTSEQ(const bool _bBlue, const unsigned int _nButton) {
		bBlue = _bBlue;
		nButton = _nButton;
	};

	ROBOTSEQ(const ROBOTSEQ& src) {
		bBlue = src.bBlue;
		nButton = src.nButton;
	};

	ROBOTSEQ& operator =(const ROBOTSEQ& src) {
		bBlue = src.bBlue;
		nButton = src.nButton;
		return *this;
	};

} ROBOTSEQ;
typedef std::map<int, ROBOTSEQ> ROBOTSEQS;

typedef struct SEQINPUT {
	unsigned int nTestCase;
	ROBOTSEQS tSeq;

	SEQINPUT() {
		nTestCase = 0;
	};

	SEQINPUT(const SEQINPUT& src) {
		nTestCase = src.nTestCase;
		tSeq = src.tSeq;
	};

	SEQINPUT& operator =(const SEQINPUT& src) {
		nTestCase = src.nTestCase;
		tSeq = src.tSeq;
		return *this;
	};

} SEQINPUT;
typedef std::vector<SEQINPUT> SEQINPUTS;

/*
sample input:
3
4 O 2 B 1 B 2 O 4
3 O 5 O 8 B 100
2 B 2 B 1

sample output:
Case #1: 6
Case #2: 100
Case #3: 4
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
	int nCount = 0, i = 0, nTestCase = 0;
	for (strings::iterator it = sLines.begin(); it != sLines.end(); ++it) {
		nCount = SplitA(sItem, *it, " ", false);
		if ((nCount <= 1) || (0 == nCount %2))
			continue;

		SEQINPUT input;
		input.nTestCase = ++nTestCase;
		bool bBlue = false;
		string s;
		for (i = 1; i < nCount; i++) {
			s = sItem.at(i);
			if (1 == i %2)
				bBlue = (0 != strcmpi(s.c_str(), "O"));
			else
				input.tSeq[i /2] = ROBOTSEQ(bBlue, atoi(s.c_str()));
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
		// starts with 0 step, blue and orange at button 1 position
		int nStep = 0, nTotalStep = 0, nBluePos = 1, nOrangePos = 1, nBlueLastSteps = 0, nOrangeLastSteps = 0;
		for (ROBOTSEQS::const_iterator itseq = it->tSeq.begin(); itseq != it->tSeq.end(); ++itseq) {
			if (itseq->second.bBlue) {
				nStep = abs(itseq->second.nButton - nBluePos) - nOrangeLastSteps;
				if (nStep < 0)
					nStep = 0;
				nStep +=1;
				nBluePos = itseq->second.nButton;
				nBlueLastSteps += nStep;
				nOrangeLastSteps = 0;
			} else {
				nStep = abs(itseq->second.nButton - nOrangePos) - nBlueLastSteps;
				if (nStep < 0)
					nStep = 0;
				nStep +=1;
				nOrangePos = itseq->second.nButton;
				nOrangeLastSteps += nStep;
				nBlueLastSteps = 0;
			}
			nTotalStep += nStep;
		}
		output << "Case #" << it->nTestCase << ": " << nTotalStep << std::endl;
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

