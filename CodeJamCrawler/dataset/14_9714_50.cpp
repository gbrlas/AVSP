#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;


int main()
{
	int T;
	int N, X;
	vector<int> a;
	vector<int> b;
	
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		
		scanf("%d %d", &N, &X);
		a.resize(N);
		
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &a[i]);
		}
		
		sort(a.begin(), a.end());
		
		int j;
		
		b.clear();
		
		for(j = N-1; j >= 0 && 2*a[j] > X; j--)
		{
			b.push_back(a[j]);
		}
		int ou = b.size()-1;
		int autres = 0;
		for(; j >= 0; j--)
		{
			if(ou >= 0 && a[j] + b[ou] <= X)
			{
				ou--;
			}
			else
			{
				autres++;
			}
		}
		
		printf("%d\n", (int)b.size() + (autres+1)/2);
		
	}

	return 0;
}
