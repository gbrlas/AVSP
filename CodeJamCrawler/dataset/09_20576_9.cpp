#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int occ[10];

void findOcc(int x, int* arr)
{
	int t = x;
	while(t != 0)
	{
		int dig = t % 10;
		if(dig > 0) arr[dig]++;
		t /= 10;
	}
}

int main()
{
	FILE* fin = fopen("in.txt", "r");
	FILE* fout = fopen("out.txt", "w");

	int T;
	fscanf(fin, "%d", &T);
	for(int tests = 1; tests <= T; ++tests)
	{
		int N;
		fscanf(fin, "%d", &N);
		memset(occ, 0, sizeof(occ));
		findOcc(N, occ);
		for(int i = N + 1; ; ++i)
		{
			int arr[10];
			memset(arr, 0, sizeof(arr));
			findOcc(i, arr);
			bool same = true;
			for(int j = 1; j < 10; ++j)
				if(arr[j] != occ[j])
				{
					same = false;
					break;
				}
			if(same)
			{
				fprintf(fout, "Case #%d: %d\n", tests, i);
				break;
			}
		}
	}

	fclose(fin);
	fclose(fout);

	return 0;
}