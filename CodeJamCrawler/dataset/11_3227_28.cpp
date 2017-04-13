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
	string line;
	SplitA(lines, sInput, "\n", false);
	DWORDLONG R = 0, C = 0, TC = 0;

	for (strings::iterator it = lines.begin() +1; it != lines.end(); ) {
		TC++;
		SplitA(items, *it, " ", false);
		// R C
		R = atol(items.at(0).c_str());
		C = atol(items.at(1).c_str());
		it++;
		// data
//		string data;
//		for (DWORDLONG r = 0; r < R; r++) {
//			data += *it;
//			it++;
//		}
		char* data = new char[R * C +1];
		DWORDLONG c = 0;
		for (DWORDLONG r = 0; r < R; r++) {
			line = *it;
			it++;
			for (string::iterator itline = line.begin(); itline != line.end(); ++itline)
				data[c++] = *itline;
		//	c--;
		}
		data[R * C] = '\0';
		// check
		for (DWORDLONG i = 0; i < R * C; i++) {
//			if ((i +1 % C != 0) && (data.at(i) == '#') && (data.at(i +1) == '#') &&
//				(i + C +1 <= R * C) && (data.at(i + C) == '#') && (data.at(i + C +1) == '#'))
			if ((i +1 % C != 0) && (data[i] == '#') && (data[i +1] == '#') &&
				(i + C +1 <= R * C) && (data[i + C] == '#') && (data[i + C +1] == '#'))
			{
//				data.at(i) = '/';
//				data.at(i +1) = '\\';
//				data.at(i + C) = '\\';
//				data.at(i + C +1) = '/';
				data[i] = '/';
				data[i +1] = '\\';
				data[i + C] = '\\';
				data[i + C +1] = '/';
			}
		}
		// check if there is still #
		string s = data;
		output << "Case #" << TC << ": " << std::endl;
		if (s.find('#') != s.npos) {
			output << "Impossible" << std::endl;
		} else {
			for (DWORDLONG r = 0; r < R; r++)
				output << s.substr(r * C, C) << std::endl;
		}
		delete data;
	}

	output.close();

	return 0;
}

