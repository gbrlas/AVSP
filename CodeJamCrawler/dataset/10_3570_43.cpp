#include <direct.h>
#include <stdio.h>
#include <share.h>
#include <windows.h>
#include <math.h>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
	FILE* filePtr = _fsopen("C:\\BlueMammoth\\DungeonBlitz\\src\\bin\\C-small-attempt0.in", "r", _SH_DENYNO);
	FILE* fileOut = _fsopen("C:\\BlueMammoth\\DungeonBlitz\\src\\bin\\C-small.out", "w", _SH_DENYNO);
	char currLine[1000000];
	fgets(currLine, 1000000, filePtr);
	int numCases = atoi(currLine);
	for (int i=0; i < numCases; i++)
	{
		fgets(currLine, 1000000, filePtr);
		char* parseContext;
		char* p1 = strtok_s(currLine, " ", &parseContext);
		char* p2 = strtok_s(NULL, " ", &parseContext);
		char* p3 = strtok_s(NULL, " ", &parseContext);
		int R = atoi(p1);
		int k = atoi(p2);
		int num = atoi(p3);
		fgets(currLine, 1000000, filePtr);
		queue<int> currQueue;
		char* asas = strtok_s(currLine, " ", &parseContext);
		currQueue.push(atoi(asas));
		for (int j = 1; j < num; j++)
		{
			char* asas2 = strtok_s(NULL, " ", &parseContext);
			currQueue.push(atoi(asas2));
		}
		int euros = 0;
		for (int hh = 0; hh < R; hh++)
		{
			int pushs = 0;
			int riders = 0;
			while ((pushs < num) && (riders < k))
			{
				int thisGroup = currQueue.front();
				if ((riders + thisGroup) > k)
					break;
				currQueue.pop();
				currQueue.push(thisGroup);
				riders += thisGroup;
				euros += thisGroup;
				pushs++;
			}
		}
		fprintf(fileOut, "Case #%d: %d\n", i+1, euros);
	}
	return 0;
}