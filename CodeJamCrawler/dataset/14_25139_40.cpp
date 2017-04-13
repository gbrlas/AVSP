#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <iterator>
#include <functional>
#include <ctime>

using namespace std;

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define make_triple(x,y,z) make_pair((x), make_pair((y),(z)))
#define fr first
#define sc second
#define ts second.first
#define td second.second

typedef long long ll;
typedef unsigned long long ull; 
typedef double ld;

const long double eps = 1e-9;
const int inf = LONG_MAX;
const ll inf64 = LLONG_MAX;
const long double pi = 3.1415926535897932384626433832795;
const long long MOD = 1000000007;

#define N 20000

char buf[100];
string a[100][100];
int size[100];
int d[100];
int prov[100];
int n,m;

int mmax = 0, ccount = 0;

set<string> ss;

int trie(int kof)
{
	ss.clear();
	for (int i = 0; i<n; i++)
		if (d[i] == kof)
			for (int h = 0; h<size[i]; h++)
				ss.insert(a[i][h]);
	return ss.size() + 1;
}

void doit(int pos) 
{
	if (pos == n)
	{
		fill(prov, prov+m, 0);
		for (int i = 0; i<n; i++)
			prov[d[i]]++;
		for (int i = 0; i<m; i++)
			if (prov[i] == 0)
				return;
		int ans = 0;
		for (int i = 0; i<m; i++)
			ans += trie(i);
		if (mmax < ans)
			mmax = ans, ccount = 0;	
		if (mmax == ans)
			ccount++;
		return;
	}
	for (int i = 0; i<m; i++)
		d[pos] = i, doit(pos+1);
	d[pos] = 0;
}

int main()
{
	freopen("output1.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int ii = 0; ii<t; ii++)
	{
		scanf("%d%d\n", &n,&m);
		mmax=0, ccount = 0;
		for (int i = 0; i<n; i++)
		{
			gets(buf);
			int nn = strlen(buf);
			size[i] = nn;
			for (int h = 1; h<=nn; h++)
				a[i][h-1].assign(buf, h);
		}
	
		doit(0);
		
		
		printf("Case #%d: %d %d\n", ii+1, mmax, ccount); 
	}
	return 0;	
}