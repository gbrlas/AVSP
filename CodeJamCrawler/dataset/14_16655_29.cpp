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

typedef long long ll;

int N, X;
multiset<int> S;

int main()
{
	int test_cnt;
	cin >> test_cnt;
	for(int test_num=1;test_num<=test_cnt;test_num++)
	{
		scanf("%d%d", &N, &X);
		for(int i=0;i<N;i++)
		{
			int a;
			scanf("%d", &a);
			S.insert(-a);
		}
		int ans = 0;
		while(!S.empty())
		{
			int a = -(*S.begin());
			S.erase(S.begin());
			multiset<int>::iterator it = S.lower_bound(a-X);
			if (it != S.end())
			{
				S.erase(it);
			}			
			ans++;	
		}
		printf("Case #%d: %d\n", test_num, ans);
		
		
	}
    
	return 0;
}
