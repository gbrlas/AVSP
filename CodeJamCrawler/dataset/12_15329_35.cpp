#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<iterator>
#include<complex>

#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_set>
#include <hash_map>
#endif
#endif
using namespace std;

int N;
int p,s;
bool can(int x,bool s)
{
	if(x/3 >= p) return 1;
	if( x%3 && x/3+1 >= p) return 1;
	if( s && (x-2)/3 + 2 >= p) return 1;
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","rt",stdin);
	freopen("GCJ_B.txt","wt",stdout);

#endif 
	int tc=1,TC;
	
	scanf("%d",&TC);
	while( TC-- )
	{
		int r=0,x;
		scanf("%d %d %d",&N,&s,&p);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&x);
			if(can(x,0))
				r++;
			else if(x>1 && s && can(x,1))
			{
				r++;
				s--;
			}
		}
		printf("Case #%d: %d\n",tc++,r);
	}
	return 0;
}