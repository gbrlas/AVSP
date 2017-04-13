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

typedef long long int64 ;

int N, L, P, K, res;
vector <int> f;


void read()
{
	scanf("%d %d %d", &P, &K, &L);
	f.clear();
	int t;
	for (int i=0; i<L; i++)
	{
		scanf("%d", &t);
		f.push_back(t);
	}	
}

void solve()
{
	sort(f.begin(), f.end());
	reverse(f.begin(), f.end());
	res=0;
	for (int i=0; i<f.size(); i++)
	{
		res+=f[i]*(i/K+1);
	}


}

void write(int i)
{
	if (i==0)
		printf("Case #%d: %d", i+1, res);
	else
		printf("\nCase #%d: %d", i+1, res);

}
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &N);
	for (int i=0; i<N; i++)
	{
		read();
		solve();
		write(i);
	}
	return 0;
}