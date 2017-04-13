#include <stdio.h>
#include <stdlib.h>
#include <share.h>
#include <string>
#include <math.h>

const unsigned int MAX_U16 = 65535;

bool IsPalindrome(int num)
{
	char asString[1024];
	sprintf_s(asString, 1024, "%d", num);
	
	int n = strlen(asString);
	for (int k = 0; k < n / 2; k++)
		if (asString[k] != asString[n - 1 - k])
			return false;
	return true;
}

void main()
{
	char* fileName = "input\\C-small-attempt0.in";
	char* fileOutName = "output\\C-small-attempt0.out";
	FILE* filePtr = _fsopen(fileName, "r", _SH_DENYNO);
	FILE* fileOutPtr = _fsopen(fileOutName, "w", _SH_DENYNO);
	if (!filePtr || !fileOutPtr)
	{
		printf("File not found\n");
		return;
	}
	/*1, 2, 3,, 9
	11
	111, 121, 191, 212, 313, 
	1111, 1221, 1991, 2112
	11111, 11211, 11911, 12121


	for (int i = 1; i <= 7; i++)
	{
		char* tempStr = (char*)malloc(i + 1);
		for (int j = 1; j <= 9; j++)
		{
			tempStr[0] = tempStr[
			printf(tempStr, "%d", i);
	}

	for (int i = 1; i <= 9999999; i++)
	{
	}
	printf("done");
	return;*/

	char currLine[MAX_U16];
	fgets(currLine, MAX_U16, filePtr);
	int numCases = atoi(currLine);
	for (int i = 0; i < numCases; i++)
	{
		fgets(currLine, MAX_U16, filePtr);
		char* parseContext;
		char* currSpot = strtok_s(currLine, " ", &parseContext);
		__int64 inStart = _strtoui64(currSpot, NULL, 10);
		currSpot = strtok_s(NULL, " ", &parseContext);
		__int64 inEnd = _strtoui64(currSpot, NULL, 10);
		
		__int64 foundCount = 0;
		for (__int64 j = inStart; j <= inEnd; j++)
		{
			int theRoot = (int)sqrt((long double)j);
			if ((theRoot * theRoot) != (int)j)
				continue;
			
			if (IsPalindrome(theRoot) && IsPalindrome(j))
				foundCount++;
		}
		fprintf(fileOutPtr, "Case #%d: %lld\n", i + 1, foundCount);
	}
	fflush(fileOutPtr);
	fclose(fileOutPtr);
	fclose(filePtr);
}