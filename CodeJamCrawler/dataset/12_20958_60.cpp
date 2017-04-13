#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include<set>
#include<vector>
#include <map>;
using namespace std;

typedef unsigned long long int ll;

vector<vector<int>> normal,conflicted;


int isInVec(vector<int> &v, int k)
{
	for(int i = 0; i < (int)v.size(); i ++)
	{
		if(v[i]==k)
			return 1;
	}
	return 0;
}

int t;
int main ()
{

	freopen("B-large.in", "rt", stdin);
    freopen("B-large.out", "wt", stdout);

	normal.resize(11);
	conflicted.resize(11);
	for(int i = 0; i < 11; i++)
	{
		vector<int> temp;
		for(int j = i; j < 11; j++)
		{
			if(i==j && j>0)
			{
				temp.push_back(3*j-2);
			}
			if(j!=0)
				temp.push_back(3*j-1);
			temp.push_back(3*j+1);
			temp.push_back(3*j);
		}
		sort(temp.begin(), temp.end());
		normal[i] = temp;
	}

	for(int i = 0; i < 11; i++)
	{
		vector<int> temp;
		for(int j = i; j < 11; j++)
		{
			if(3*j-3> 0 && 3*j-3 <= 30)
				if(isInVec(normal[i],3*j-3) == 0)
					temp.push_back(3*j-3);
			if(3*j-3> 0 && 3*j-4 <= 30)
				if(isInVec(normal[i],3*j-4) == 0)
					temp.push_back(3*j-4);
		}
		sort(temp.begin(), temp.end());
		conflicted[i] = temp;
	}

	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n,s,p, ans = 0;
		string str;
		cin >> n >> s >> p;
		for(int j = 0 ; j < n; j++)
		{
			int k;
			cin >> k;
			int c = isInVec(normal[p], k);
			if(c == 0 && s > 0)
			{
				c = isInVec(conflicted[p], k);
				if(c)
					s--;
			}
			ans+=c;
		}
		getline(cin, str);
		cout << "Case #" << i+1 << ": " <<ans << endl;
	}

	
}