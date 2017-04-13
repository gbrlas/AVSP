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

bool pred(int a)
{
	if(a > 0)	return true;
	else 		return false;
}

int rem(string &a,int x, int y)
{
     int carry = 0;
	 for(int i = 0; i < (int)a.length(); ++i)
     {  
          carry = a[i] + carry * x;
          a[i] = carry/y;
          carry %= y;
     }
     return carry;
}
string pred_process(string a,int &s)
{
	string b;
	b.assign(a.size(),0);
	
	map<int,int> Mp;
	Mp.insert(mp(a[0],1));
	b[0] = 1;
	int iter = 0;
	for(int i = 1; i < (int)a.size(); i++)
	{
		if(Mp.find(a[i]) == Mp.end())
		{
			Mp[a[i]] = iter;
			b[i] = iter;
		    if(iter == 0) 
				iter = 2;
			else
				iter++;
		}
		else
		{
			b[i] = Mp[a[i]];
		}

	}
	s = Mp.size();
	return b;
}
int main()
{
	freopen(CIN_FILE, "rt", stdin);
	freopen(COUT_FILE, "wt", stdout);
	string str;
	string inb;
	int n;
	scanf("%d",&n);
	int i = 0;
	forn(i,n)
	{
		cin >> str;
		int j = 0;
		//forn(j,str.size()) str[j] -= '0';
		int a = 0, b = 10;
		str = pred_process(str,a);
		if(a < 2) a = 2;
		while(find_if(str.begin(),str.end(),pred) != str.end()){
			int res = rem(str,a,b);
			inb.push_back(res + '0');
		}
		printf("Case #%d: ",i+1);
		for(string::reverse_iterator k = inb.rbegin(); k != inb.rend(); k++)
			printf("%c",*k);
		printf("\n");
		inb.clear();
	}

	return 0;
}
         	

