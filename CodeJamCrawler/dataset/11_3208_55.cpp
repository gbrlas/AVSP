// MagickaA.cpp : Defines the entry point for the console application.

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
typedef std::map<string, string> stringmap;

typedef struct MAGICKASEQ {
	stringmap combine;
	strings remove;
	string data;

	MAGICKASEQ() {
	};

	MAGICKASEQ(const MAGICKASEQ& src) {
		combine = src.combine;
		remove = src.remove;
		data = src.data;
	};

	MAGICKASEQ& operator =(const MAGICKASEQ& src) {
		combine = src.combine;
		remove = src.remove;
		data = src.data;
		return *this;
	};

} MAGICKASEQ;

typedef struct SEQINPUT {
	unsigned int nTestCase;
	MAGICKASEQ tMagicka;

	SEQINPUT() {
		nTestCase = 0;
	};

	SEQINPUT(const SEQINPUT& src) {
		nTestCase = src.nTestCase;
		tMagicka = src.tMagicka;
	};

	SEQINPUT& operator =(const SEQINPUT& src) {
		nTestCase = src.nTestCase;
		tMagicka = src.tMagicka;
		return *this;
	};

} SEQINPUT;
typedef std::vector<SEQINPUT> SEQINPUTS;

/*
sample input:
5
0 0 2 EA
1 QRI 0 4 RRQR
1 QFT 1 QF 7 FAQFDFQ
1 EEZ 1 QE 7 QEEEERA
0 1 QW 2 QW

sample output:
Case #1: [E, A]
Case #2: [R, I, R]
Case #3: [F, D, T]
Case #4: [Z, E, R, A]
Case #5: []
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
	int nCount = 0, i = 0, nQty = -1, nTestCase = 0;
	for (strings::iterator it = sLines.begin(); it != sLines.end(); ++it) {
		nCount = SplitA(sItem, *it, " ", false);
		if (nCount <= 1)
			continue;

		SEQINPUT input;
		input.nTestCase = ++nTestCase;
		bool bString = false;
		int nStage = 0;		// 0 combine, 1 remove, 2 data
		string s;
		for (i = 0; i < nCount; i++) {
			s = sItem.at(i);
			if (0 == i) {
				nQty = atoi(s.c_str());
				if (nQty > 0)
					bString = true;
				else {
					bString = false;
					nStage = 1;
				}
			} else if (0 == nStage) {
				// bString = true
				input.tMagicka.combine[s.substr(0, 2)] = s.substr(2, 1);
				nQty--;
				if (nQty <= 0) {
					bString = false;
					nStage = 1;
					nQty = -1;
				}
			} else if (1 == nStage) {
				if (!bString) {
					nQty = atoi(s.c_str());
					if (nQty > 0)
						bString = true;
					else {
						bString = false;
						nStage = 2;
					}
				} else {
					input.tMagicka.remove.push_back(s);
					nQty--;
					if (nQty <= 0) {
						bString = false;
						nStage = 2;
						nQty = -1;
					}
				}
			} else if (2 == nStage) {
				if (!bString)
					bString = true;
				else {
					CStringA cstr(s.c_str());
					cstr.Trim();
					input.tMagicka.data = cstr;
				}
			}
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
	string data, datasubstr, s, c1, c2, s1, s2;
	int nLen = 0, i = 0;
	for (SEQINPUTS::const_iterator it = pSeqInput->begin(); it != pSeqInput->end(); ++it) {
		nLen = it->tMagicka.data.length();
		data = it->tMagicka.data;
		if (nLen > 1) {
			for (i = 2; i <= nLen; ) {
				datasubstr = data.substr(0, i);
				bool bCombine = false, bRemove = false;
				if (!it->tMagicka.combine.empty()) {
					for (stringmap::const_iterator itcombine = it->tMagicka.combine.begin(); itcombine != it->tMagicka.combine.end(); ++itcombine) {
						s = itcombine->first;
						if (datasubstr.length() > 1) {
							c1 = datasubstr.substr(datasubstr.length() -2, 1);
							c2 = datasubstr.substr(datasubstr.length() -1, 1);
							s1 = s.at(0);
							s2 = s.at(1);
							if (((s1 == c1) && (s2 == c2)) || (s1 == c2) && (s2 == c1)) {
								data.replace(i -2, 2, itcombine->second);
								i--;
								bCombine = true;
							}
						}
					}
				}
				if (!bCombine && !it->tMagicka.remove.empty()) {
					for (strings::const_iterator itremove = it->tMagicka.remove.begin(); itremove != it->tMagicka.remove.end(); ++itremove) {
						if (datasubstr.length() > 1) {
							s = *itremove;
							c1 = s.at(0);
							c2 = s.at(1);
							if ((datasubstr.npos != datasubstr.find(c1)) && (datasubstr.npos != datasubstr.find(c2))) {
								bRemove = true;
								if (data.length() < i) {
									data.clear();
									datasubstr.clear();
									break;
								} else {
									data = data.substr(i);
									datasubstr = data.substr(0, 2);
								}
							}
						}
					}
				}
				if (bRemove) i = 2;
				else i++;
			}
		}
		s.clear();
		if (!data.empty()) {
			for (string::iterator itdata = data.begin(); itdata != data.end(); ) {
				s += *itdata;
				++itdata;
				if (data.end() != itdata)
					s += ", ";
			}
		}
		output << "Case #" << it->nTestCase << ": [" << s << "]" << std::endl;
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

