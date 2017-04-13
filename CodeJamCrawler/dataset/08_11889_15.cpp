#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include<algorithm>
#include <vector>
#include <string>
using namespace std;

typedef std::vector<long long> vectorlongint;
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

	int nTestCases = 0;
	fscanf(fp, "%d", &nTestCases);

	
	FILE *fpOut = NULL;
	fpOut = fopen("c:\\jam1.out", "w");
	if(fpOut == NULL)
	{
		printf("Output file opening error\n");
		return 0;
	}


	int P, K, L;
	vectorlongint vectFreq;
	for(int nTest = 1; nTest <= nTestCases; nTest++)
	{
		vectFreq.clear();
		fscanf(fp, "%d", &P);
		fscanf(fp, "%d", &K);
		fscanf(fp, "%d", &L);
		for(int iLetter=0;iLetter<L;iLetter++)
		{
			long long freq = 0;
			fscanf(fp, "%lld", &freq);
			vectFreq.push_back(freq);
		}

		std::sort(vectFreq.begin(), vectFreq.end(), greater<long long>());

		long long ans = 0;
		int nCurKeyCnt = 0;
		int nCurP = 1;
		for(int iLetter=0;iLetter<L;iLetter++)
		{
			if(nCurKeyCnt < K)
			{
				ans += nCurP * vectFreq[iLetter];
				nCurKeyCnt++;
			}
			if(nCurKeyCnt >= K)
			{
				nCurKeyCnt = 0;
				nCurP++;
			}
		}

		fprintf(fpOut, "Case #%d: %lld\n", nTest, ans);
	}
	

	

	if(fp)
		fclose(fp);
	if(fpOut)
		fclose(fpOut);

	return 0;
}