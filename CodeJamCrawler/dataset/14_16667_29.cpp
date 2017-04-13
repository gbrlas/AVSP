#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <limits>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <queue>
#include <cstring>

using namespace std;


int N;
int a[1005];
int b[1005];
int c[1005];

int main()
{
	int test_cnt;
	cin >> test_cnt;
	for(int test_num=1;test_num<=test_cnt;test_num++)
	{
		scanf("%d", &N);
		for(int i=0;i<N;i++)
			scanf("%d", &a[i]);
		int best = 1000000000;
		for(int mask=0;mask<(1<<N);mask++)
		{
			vector<int> X, Y;
			for(int i=0;i<N;i++)
				if (mask & (1<<i)) X.push_back(a[i]);
				else Y.push_back(a[i]);
			sort(X.begin(), X.end());
			sort(Y.begin(), Y.end());
			///reverse(Y.begin(), Y.end());
			for(int i=X.size()-1;i>=0;i--) b[i] = X[i];
			for(int i=Y.size()-1;i>=0;i--) b[N-i-1] = Y[i];
			
			memcpy(c, a, N*sizeof(int));
			int tmp = 0;
			for(int i=0;i<N;i++)
			{
				int y = c[i];
				for(int j=i;y!=b[i];j++)
				{
					swap(y, c[j+1]);
					tmp++;
				}
			}
			if (tmp < best) best = tmp;	
		}
		printf("Case #%d: %d\n", test_num, best);	
		
	}
    
	return 0;
}
