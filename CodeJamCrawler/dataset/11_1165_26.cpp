#include "libfns.h"

bool testBalanced(__int64* arr1, __int64* arr2, int arrLen)
{
	int halfSize = arrLen/2;
// 	__int64 halfRowSum[2] = {0,0};
// 	__int64 halfColSum[2] = {0,0};
	
	for(int i=0; i<halfSize; ++i)
	{
// 		halfRowSum[0] += arr1[i];
// 		halfColSum[0] += arr2[i];
// 		halfRowSum[1] += arr1[arrLen-1-i];
// 		halfColSum[1] += arr2[arrLen-1-i];
		if(arr1[i] != arr1[arrLen-1-i])
		{
			return false;
		}
		if(arr2[i] != arr2[arrLen-1-i])
		{
			return false;
		}
	}
// 	return ((halfRowSum[0]==halfRowSum[1]) && (halfColSum[0] == halfColSum[1]));
	return true;
}

int findLargest(__int64* grid, int R, int C, int D)
{
	int retval = 0;
	int biggestPossible;
	if(R<C)
		biggestPossible = R;
	else
		biggestPossible = C;

	for(int testVal = biggestPossible; testVal >= 3; --testVal)
	{
		for(int startR = 0; startR+testVal <= R; ++startR)
		{
			for(int startC = 0; startC+testVal <= C; ++startC)
			{
				__int64 *rowSums = new __int64[testVal];
				__int64 *colSums = new __int64[testVal];

				memset(rowSums,0,testVal*sizeof(__int64));
				memset(colSums,0,testVal*sizeof(__int64));

				for(int currR = startR; currR < startR+testVal; ++currR)
				{
					for(int currC = startC; currC < startC+testVal; ++currC)
					{
						rowSums[currR-startR] += grid[currR*C + currC];
						colSums[currC-startC] += grid[currR*C + currC];
					}
				}

				rowSums[0] -= grid[startR*C + startC];
				colSums[0] -= grid[startR*C + startC];

				rowSums[0] -= grid[startR*C + startC+testVal-1];
				colSums[testVal-1] -= grid[startR*C + startC+testVal-1];

				rowSums[testVal-1] -= grid[(startR+testVal-1)*C + startC];
				colSums[0] -= grid[(startR+testVal-1)*C + startC];

				rowSums[testVal-1] -= grid[(startR+testVal-1)*C + startC+testVal-1];
				colSums[testVal-1] -= grid[(startR+testVal-1)*C + startC+testVal-1];

				bool isBalanced = testBalanced(rowSums,colSums,testVal);

				delete[] rowSums;
				delete[] colSums;

				if(isBalanced)
				{
					return testVal;
				}
			}
		}
	}
	return retval;
}

int main(int argc, char* argv[])
{
	FILE* inF, *outF;
	getFiles(argc,argv,inF,outF);
	tokenizer t(inF);
	t.setSEPS(" \t\n");

	int cases = atoi(t.getToken());

	for(int i=1; i<=cases;++i)
	{
		t.setSEPS(" \t\n");
		int R = atoi(t.getToken());
		int C = atoi(t.getToken());
		int D = atoi(t.getToken());

		t.setSEPS("\t\n");
		__int64* grid = new __int64[R*C];
		for(int r=0; r<R; ++r)
		{
			char* rowPtr = t.getToken();
			for(int c=0; c<C; ++c)
			{
				grid[r*C + c] = rowPtr[c]-'0';
			}
		}

		int sizeOfGrid = findLargest(grid,R,C,D);
		delete[] grid;

		if(sizeOfGrid > 0)
		{
			fprintf(outF,"Case #%d: %d\n",i,sizeOfGrid);
		}
		else
		{
			fprintf(outF,"Case #%d: IMPOSSIBLE\n",i,sizeOfGrid);

		}
	}
	fclose(outF);
	fclose(inF);
	return 0;
}

