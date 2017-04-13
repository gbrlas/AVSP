#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

typedef long long ll;
#pragma warning(disable:4996)
#define all(t) t.begin(),t.end()
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
using namespace std;

int go(vector<int> a)
{
	char s[256];
	for(int i=2; ; ++i)
	{
		bool terr = false;
		for(int j=0; j<a.size(); ++j)
		{
			set<int> S;
			bool err = false;
			for(int val = i; val != 1; )
			{
				itoa(val, s, a[j]);
				val = 0;
				for(char *p=s; *p; ++p)
					val += (*p - '0') * (*p - '0');
				if(S.find(val) != S.end())
				{
					err = true;
					break;
				}
				S.insert(val);
			}
			if(err) {
				terr = true;
				break;
			}
		}
		if(!terr) return i;
	}
}

int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int T;
	string s;
	getline(cin, s);
	istringstream(s) >> T;
	for(int tt=1;tt<=T;++tt)
	{
		getline(cin, s);
		istringstream ss(s);
		int z; vector<int> a;
		while(ss >> z)
			a.push_back(z);
		printf("Case #%d: %d\n", tt, go(a));			
	}
	return 0;
}