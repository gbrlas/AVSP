// 2a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef unsigned long long LL;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)

map<int,int> maps;

VI getBits(string num)
{
	stringstream sout;
	sout << num;
	string res = sout.str();
	VI ret;
	for (int i = 0; i < res.size(); i++)
	{
		ret.push_back(res[i] - '0');
	}
	return ret;
}

string getRes(VI nums)
{
	ostringstream sout;
	for (int i = 0; i < nums.size(); i++)
		sout << nums[i];
	return sout.str();
}

VI check(VI nums)
{
	int zero = -1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
			zero = i;
		else
			break;
	}
	if (zero > -1)
	{
		swap(nums[0],nums[zero+1]);
	}
	return nums;
}

int main()
{

	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);

	int t;
	cin >> t;
	int caseId = 1;
	while (t--)
	{
		LL n;
		string nn;
		cin >> nn;
		maps.clear();
		VI nums = getBits(nn);
		
		bool flag = 0;
		flag = next_permutation(nums.begin(),nums.end());

		string res;
		if (flag)
		{
			res = getRes(nums);
		}
		else
		{
			sort(nums.begin(),nums.end());
			nums = check(nums);
			nums.insert(nums.begin() + 1,0);
			res = getRes(nums);
		}
		cout << "Case #" << caseId++ << ": " << res << endl;
	}

	return 0;
}

