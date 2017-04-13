#include<stdio.h>
#include <stdlib.h>

#include<algorithm>
#include <vector>
#include <string>
using namespace std;

typedef std::vector<std::string> vectorstring;
typedef std::vector<std::string>::iterator vectorit;
#define MAX_LEN 101

struct CaseInsensitive 
{
	bool operator()(const std::string &str1, const std::string &str2) const 
	{
		return (stricmp (str1.c_str(), str2.c_str()) < 0);
	}
};

void _sort(vectorstring &vect)
{
	sort(vect.begin(), vect.end(), CaseInsensitive());
}

bool lookup(vectorstring &vect, std::string &str)
{
	vectorit itVect = lower_bound(vect.begin(), vect.end(), str, CaseInsensitive());
	if(itVect == vect.end())
		return false;

	if(stricmp((*itVect).c_str(), str.c_str()) == 0)
		return true;

	return false;
}
void insert(vectorstring& vect, std::string &str)
{
	vectorit itVect = lower_bound(vect.begin(), vect.end(), str, CaseInsensitive());
	if(itVect == vect.end())
		vect.push_back(str);
	else
		vect.insert(itVect, str);
}

void remove(std::vector<string>& vect, std::string &str)
{
	vectorit itVect = lower_bound(vect.begin(), vect.end(), str, CaseInsensitive());
	
	if(itVect != vect.end())
	{
		if(stricmp((*itVect).c_str(), str.c_str()) == 0)
			vect.erase(itVect);
	}
}

std::string SelectEngine(vectorstring &vectQueries, vectorstring &vectNames, int *nIndex)
{
	vectorstring vectNameCopy(vectNames);
	while((vectNameCopy.size() > 1) && (*nIndex < vectQueries.size()))
	{
		remove(vectNameCopy, vectQueries[*nIndex]);
		(*nIndex)++;
	}

	while((*nIndex) < vectQueries.size())
	{
		if(stricmp(vectNameCopy[0].c_str(), vectQueries[*nIndex].c_str()) == 0)
		{
			break;
		}
		(*nIndex)++;
	}

	return vectNameCopy[0];
}

int FindShifts(vectorstring& vectQueries, vectorstring& vectNames)
{
	int nShift = 0;
	int nIndex = 0;
	std::string strPrev = "";
	std::string strCurrent = "";
	while(nIndex < vectQueries.size())
	{
		strCurrent = SelectEngine(vectQueries, vectNames, &nIndex);
		nShift++;
	}

	if(nShift)
		--nShift;

	return nShift;
}
int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Invalid command line arguments\n");
		printf("Usage: jam.exe inputfile");
	}

	FILE *fp = NULL;
	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		printf("Input file opening error\n");
		return 0;
	}

	char strTestCases[MAX_LEN];
	int nTestCases = 0;
	if(fgets(strTestCases, MAX_LEN, fp) == NULL)
	{
		return 0 ;
	}

	nTestCases = atoi(strTestCases);

	vectorstring vectNames;
	vectorstring vectQueries;

	FILE *fpOut = NULL;
	fpOut = fopen("c:\\A-small.out", "w");
	if(fpOut == NULL)
	{
		printf("Output file opening error\n");
		return 0;
	}

	for(int nTest = 1; nTest <= nTestCases; nTest++)
	{
		vectNames.clear();
		vectQueries.clear();

		char strNoNames[MAX_LEN];
		int nNames = 0;

		if(fgets(strNoNames, MAX_LEN, fp) == NULL)
			return 0 ;

		nNames = atoi(strNoNames);

		char strName[MAX_LEN];
		while(nNames)
		{
			memset(strName, 0, MAX_LEN);

			if(fgets(strName, MAX_LEN, fp) == NULL)
				return 0 ;

			vectNames.push_back(std::string(strName));

			nNames--;
		}

		char strNoQuery[MAX_LEN];
		int nQuery = 0;

		if(fgets(strNoQuery, MAX_LEN, fp) == NULL)
			return 0 ;

		nQuery = atoi(strNoQuery);


		while(nQuery)
		{
			memset(strName, 0, MAX_LEN);

			if(fgets(strName, MAX_LEN, fp) == NULL)
				return 0 ;

			vectQueries.push_back(std::string(strName));

			nQuery--;
		}


		_sort(vectNames);
		int nShifts = FindShifts(vectQueries, vectNames);
		char strOutput[MAX_LEN];
		sprintf(strOutput, "Case #%d: %d\n", nTest, nShifts);
		fputs(strOutput, fpOut);
	}


	if(fp)
		fclose(fp);
	if(fpOut)
		fclose(fpOut);

	return 0;
}