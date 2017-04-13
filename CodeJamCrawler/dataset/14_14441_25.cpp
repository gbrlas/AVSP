#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
int caseVal;
int main(void)
{
	ofstream fout;
	fout.open("1_result.txt", ios_base::out);
	scanf("%d", &caseVal);
	int row, a, arr[4], res[4], resultVal, resCount=0;
	for(int caseIndex = 0; caseIndex < caseVal; caseIndex++)
	{
		scanf("%d", &row);
		for(int i=0; i<(row-1)*4; i++)
			scanf("%d", &a);
		for(int i=0; i<4; i++)
			scanf("%d", &arr[i]);
		for(int i=0; i<(4-row)*4; i++)
			scanf("%d", &a);
		cin >> row;
		for(int i=0; i<(row-1)*4; i++)
			scanf("%d", &a);
		for(int i=0; i<4; i++)
			scanf("%d", &res[i]);
		for(int i=0; i<(4-row)*4; i++)
			scanf("%d", &a);
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
				if(arr[i] == res[j])
				{
					resultVal = res[j];
					resCount++;
				}
		}
		fout << "Case #" << caseIndex+1<< ": ";
		if(resCount == 1)
			fout << resultVal << endl;
		else if(resCount > 0)
			fout << "Bad magician!" << endl;
		else
			fout << "Volunteer cheated!" << endl;
		resCount = 0;
	}
	return 0;
}