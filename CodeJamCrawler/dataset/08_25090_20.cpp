#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

#define FOR(i,a,b) for (int i=(a),_n=(b); i <= _n; i++) 
#define FORIT(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())

#if 0
#define D(X) {cerr << "DUMP: "<< #X << " = '" << (X) << "'" << endl;}
#else
#define D(X)
#endif

int M, V;
vector<int> nodes,changeable;
//vector<int> leaf;
int numint;
int numleaf;

int counth(int x)
{
	if(x>numint)
	{
		if(x>M)
			cerr << "x>m" << endl;
		D("LEAF")
		D(x)
		if(nodes[x] == 1)
			return 0;
		else
			return -1;
	}
	int left = x*2;
	int right = x*2+1;
	
	int lv = counth(left);
	int rv = counth(right);
	D(x)
	D(left)
	D(lv)
	D(right)
	D(rv)
	D(changeable[x])

	if(nodes[x] == 0)//OR
	{
		if(lv == -1 && rv != -1)return rv;
		if(lv != -1 && rv == -1)return lv;
		if(lv == -1 && rv == -1)return -1;
		return min(lv,rv);
	}

	if(!changeable[x])
	{
		if(lv == -1 || rv == -1)
			return -1;
		return lv + rv;
	}
	else
	{
		if(lv == -1 && rv != -1)return 1+rv;
		if(lv != -1 && rv == -1)return 1+lv;
		if(lv == -1 && rv == -1)return -1;
		return min( lv+rv , (1+min(lv,rv) ));
	}
}

int main()
{
	int numInputs;
	cin >> numInputs;
	FOR(cs,1,numInputs)
	{
		D(cs)
		cin >> M >> V;

		if(V != 1)
			V=0;

		numint = (M-1)/2;
		numleaf = (M+1)/2;

		if(numint + numleaf != M)cerr << "ERROR" << endl;
		nodes.resize(M+10);
		changeable.resize(numint+10);
		//leaf.resize(numleaf+10);

		for(int i=1;i<=numint;i++)
		{
			cin >> nodes[i] >> changeable[i];
			if(nodes[i] != 1)
				nodes[i] = 0;
			if(changeable[i] != 1)
				changeable[i] = 0;
		}
		
		for(int i=numint+1;i<=M;i++)
		{
			cin >> nodes[i];
		}

		if(V == 0)
		{
			for(int i=1;i<=M;i++)
			{
				if(nodes[i])
					nodes[i] = 0;
				else
					nodes[i] = 1;
			}
		}
		
		int numm = counth(1);
		cout << "Case #" << cs << ": ";
		if(numm == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << numm << endl;
	}
	return 0;
}
