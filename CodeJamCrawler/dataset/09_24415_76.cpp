#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

#define SZ(a) (int)(a).size()
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define INF (int)1e9

#define ll long long
#define vi vector<int>
#define vs vector<string>

using namespace std;
int L, D, N;

int check(vector < vector <char> > &pool, string word)
{
	for(int i = 0; i < SZ(word); i++)
	{
		bool found = false;
		for(int j = 0; j < SZ(pool[i]); j++)
		{
			if(word[i] == pool[i][j])
				found = true;
		}
		if(!found)
			return 0;
	}
	return 1;
}

int solve(string ip, vs &dict)
{
	vector < vector <char> >pool(L);
	
	bool open = false;
	int j = 0;
	for(int i = 0; i < SZ(ip); i++)
	{
		if(ip[i] == '(')
		{
			open = true;
		}
		else if(ip[i] == ')')
		{
			open = false;
		}
		else
		{
			pool[j].PB(ip[i]);
		}
		if(open == false)
			j++;
	}	
	
	int ret = 0;
	for(int i = 0; i < D; i++)
	{
		ret += check(pool, dict[i]);
	}
	
	return ret;
}

int main()
{
	cin >> L >> D >> N;
	vs dict(D);
	
	for(int i = 0; i < D; i++)
		cin >> dict[i];
		
	string ip;
	for(int i = 1; i <= N; i++)
	{
		cin >> ip;
		cout << "Case #" << i << ": " << solve(ip, dict) << endl;
	}
	
	return 0;
}
