#include <direct.h>
#include <stdio.h>
#include <share.h>
#include <windows.h>
#include <math.h>

int main(int argc, char** argv)
{
	FILE* filePtr = _fsopen("C:\\BlueMammoth\\DungeonBlitz\\src\\bin\\A-small-attempt0.in", "r", _SH_DENYNO);
	FILE* fileOut = _fsopen("C:\\BlueMammoth\\DungeonBlitz\\src\\bin\\A-small.out", "w", _SH_DENYNO);
	char currLine[MAX_U16];
	fgets(currLine, MAX_U16, filePtr);
	int numCases = atoi(currLine);
	for (int i=0; i < numCases; i++)
	{
		fgets(currLine, MAX_U16, filePtr);
		char* parseContext;
		char* p1 = strtok_s(currLine, " ", &parseContext);
		char* p2 = strtok_s(NULL, " ", &parseContext);
		int n = atoi(p1);
		int k = atoi(p2);
		int power = (1 << n);
		bool aa = (((k + 1) % power) == 0);
		fprintf(fileOut, "Case #%d: %s\n", i+1, aa ? "ON" : "OFF");
	}
	return 0;
}