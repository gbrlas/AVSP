#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define X first
#define Y second
#define all(v) (v).begin( ), (v).end( )
#define VV vector
#define VI VV<int>
#define VS VV<string>
typedef pair<int, int> pii;
typedef long long ll;
int countes(vector<int> v,int p)
{
	vector<int> vec(p,1);
	int j;
	int sum = 0;
	forn(j,v.size())
	{
		vec[v[j] - 1] = 0;
		for(int t = v[j]; ; ) 
		{
			if(t <= int(vec.size() - 1) && vec[t] == 1 )
			{
				sum++;
				t++;
			}
			else
				break;
		}
		for(int w = v[j] - 2; ;) 
		{
			if(w >= 0 && vec[w] == 1 )
			{
				sum++;
				w--;
			}
			else
				break;
		}
	}
	return sum;
}
int main()
{
	freopen(CIN_FILE, "rt", stdin);
	freopen(COUT_FILE, "wt", stdout);
	int n;
	scanf("%d",&n);
	int i;
	
	forn(i,n)
	{
		int p,q;
		scanf("%d %d",&p,&q);
		int j;
		vector<int> needper(q);
		forn(j,q)
		{
			scanf("%d",&needper[j]);
		}
		sort(needper.begin(),needper.end());
		bool fl = true;
		int mn = INT_MAX;
		while(fl)
		{
			mn = min(mn,countes(needper,p));
			fl = next_permutation(all(needper));
		}
		printf("Case #%d: %d\n",i+1,mn);
	}
	

	return 0;
}
         	

