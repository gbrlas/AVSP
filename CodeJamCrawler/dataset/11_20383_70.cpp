/*
 * a.cpp
 *
 *  Created on: 08.05.2011
 *      Author: 1
 */

#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

string s, t;
map<char, set<pair<char, char> > > c;
map<char, set<char> > o;
int n;

vector<char> Solve()
{
	c.clear();
	o.clear();
	vector<char> res;

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> t;
		c[t[0]].insert(make_pair(t[1], t[2]));
		c[t[1]].insert(make_pair(t[0], t[2]));
	}
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> t;
		o[t[0]].insert(t[1]);
		o[t[1]].insert(t[0]);
	}
	cin >> n >> s;

	for(int i = 0; i < n; i++)
	{
		res.push_back(s[i]);
		if(res.size() > 1)
		{
			set<pair<char, char> >::iterator it;
			for(it = c[res[res.size() - 1]].begin(); it != c[res[res.size() - 1]].end(); it++)
			{
				if(it->first == res[res.size() - 2])
					break;
			}
			if(it != c[res[res.size() - 1]].end())
			{
				res.pop_back();
				res.pop_back();
				res.push_back(it->second);
			}
			else
			{
				bool bad = 0;
				for(int i = 0; i < res.size() - 1; i++)
				{
					if(o[res[i]].find(res[res.size() - 1]) != o[res[i]].end())
					{
						bad = 1;
						break;
					}
				}
				if(bad)
					res.clear();
			}
		}
	}

	return res;
}

int main()
{
	freopen("c:\\gcj\\in.txt", "r", stdin);
	freopen("c:\\gcj\\out.txt", "w", stdout);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cout << "Case #" << (i + 1) << ": [";
		vector<char> res = Solve();
		for(int i = 0; i < res.size(); i++)
		{
			if(i > 0)
				cout << ", ";
			cout << res[i];
		}
		cout << "]" << endl;
	}
	return 0;
}
