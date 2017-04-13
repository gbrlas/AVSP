#include <stdio.h>
#include <stdlib.h>
#include <share.h>
#include <string>
#include <math.h>
#include <unordered_map>
using namespace std::tr1;

const unsigned int MAX_LINE = 1050000;

void main(int argc, char *argv[])
{
	char* fileName = "input\\A-small-attempt0.in";
	char* fileOutName = "output\\A-small-attempt0.out";
	FILE* filePtr = _fsopen(fileName, "r", _SH_DENYNO);
	FILE* fileOutPtr = _fsopen(fileOutName, "w", _SH_DENYNO);
	if (!filePtr || !fileOutPtr)
	{
		printf("File not found\n");
		return;
	}

	int isVowel[26] = {0};
	isVowel[('a' - 'a')] = 1;
	isVowel[('e' - 'a')] = 1;
	isVowel[('i' - 'a')] = 1;
	isVowel[('o' - 'a')] = 1;
	isVowel[('u' - 'a')] = 1;

	char* currStr = (char*)malloc(MAX_LINE);
	fgets(currStr, MAX_LINE, filePtr);
	int numCases = atoi(currStr);
	for (int i = 0; i < numCases; i++)
	{
		fgets(currStr, MAX_LINE, filePtr);

		char* spaceSpot = strstr(currStr, " ");
		spaceSpot++;

		int tarSize = atoi(spaceSpot);
		spaceSpot--;
		*spaceSpot = '\0';

		int mySum = 0;
		int noCount = 0;
		int constCount = 0;
		int testLen = strlen(currStr);
		for (int j = 0; j < testLen; j++)
		{
			if (!isVowel[(currStr[j] - 'a')])
				constCount++;
			else
				constCount = 0;
			if (constCount < tarSize)
				noCount++;
			else
				noCount = 0;

			int currSS = (j + 1) - noCount - (tarSize - 1);
			if (currSS > 0)
				mySum += currSS;
		}
		fprintf(fileOutPtr, "Case #%d: %d\n", i + 1, mySum);
	}
	fflush(fileOutPtr);
	fclose(fileOutPtr);
	fclose(filePtr);
}