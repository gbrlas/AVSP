#include <algorithm> 
#include <cassert>
#include <cctype> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <iostream>
#include <map> 
#include <set> 
#include <string> 
#include <sstream>
#include <queue> 
#include <vector> 
using namespace std;

int T, N, ans;
vector <vector<int> > tb;
vector <int> gl;


void solve()
{
	gl.clear();
	int j;
	for (int i=0; i<N; i++)
	{
		j=0;
		for (int k=0; k<N; k++)
			if (tb[i][k]==1) j=k;
		gl.push_back(j);
	}
	ans = 0;
	int curminpos, curmin;
	for (int i=0; i<N; i++)
	{
		curminpos=i;
		for (int k=i; k<N; k++)
			if (gl[curminpos]>gl[k] && gl[curminpos]>i) curminpos=k;
		curmin = gl[curminpos];
		for (int k=curminpos; k>i; k--)
		{
			gl[k]=gl[k-1];
			ans++;
		}
		gl[i]=curmin;
	}
}

void write(int i)
{
	printf("Case #%d: %d", i, ans);
	if (i!=T) printf("\n");


}
int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	char buf[1000];
	string s;
	vector <int> tmp;


	scanf("%d",&T);
	for (int i=0; i<T; i++)
	{
		scanf("%d", &N);
		tb.clear();
		char c;
		for (int k=0; k<N; k++)
		{
			tmp.clear();
			scanf("%c", &c);
			for (int j=0; j<N; j++)
			{
				scanf("%c", &c);
				tmp.push_back(c-'0');
			}
			tb.push_back(tmp);
		}
		solve();
		write(i+1);
	}
	return 0;
}
