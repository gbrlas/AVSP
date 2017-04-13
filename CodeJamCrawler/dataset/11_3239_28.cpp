// 1A.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <map>
#include <vector>
#include <string>
#include <atlstr.h>
#include <tchar.h>
#include <fstream>
#include <float.h>
#include <math.h>

//-------------------------------------------------------------------
// helper function
//-------------------------------------------------------------------

typedef std::string				string;
typedef std::wstring			wstring;
typedef std::vector<string>		strings;
typedef std::vector<wstring>	wstrings;

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

bool GetInput(string& sInput, LPCTSTR lpszInFile)
{
	// open input file
	HANDLE hInfile = CreateFile(lpszInFile, GENERIC_READ, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hInfile)
		return false;

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
		return false;

	return true;
}

//-------------------------------------------------------------------
// solution
//-------------------------------------------------------------------

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

//-------------------------------------------------------------------
// main
//-------------------------------------------------------------------

int _tmain(int argc, _TCHAR* argv[])
{
	// files in project folder
	CString sInfile = _T("input.txt"), sOutfile = _T("output.txt");

	string sInput;
	if (!GetInput(sInput, sInfile))
		return -1;

	std::fstream output(sOutfile, std::fstream::out);

	strings lines, items;
	SplitA(lines, sInput, "\n", false);
	string line1, line2;
	DWORDLONG L = 0, H = 0, N = 0, F = 0, TC = atol(lines.at(0).c_str()), LCM = 0, OK = 0;

	for (DWORDLONG i = 1; i <= TC *2; i += 2) {
		line1 = lines.at(i);
		line2 = lines.at(i +1);

		SplitA(items, line1, " ", false);
		N = atol(items.at(0).c_str());
		L = atol(items.at(1).c_str());
		H = atol(items.at(2).c_str());

		SplitA(items, line2, " ", false);
		LCM = 0;
		for (DWORDLONG j = L; j <= H; j++) {
			OK = 0;
			for (strings::iterator it = items.begin(); it != items.end(); ++it) {
				F = atol(it->c_str());
				if ((F % j == 0) || (j % F == 0))
					OK++;
				else
					break;
			}
			if (OK == items.size()) {
				LCM = j;
				break;
			}
		}
		if (LCM > 0)
			output << "Case #" << (i +1) /2 << ": " << LCM << std::endl;
		else
			output << "Case #" << (i +1) /2 << ": " << "NO" << std::endl;
	}

	output.close();

	return 0;
}

