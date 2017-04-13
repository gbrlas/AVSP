#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

using namespace std;

const int INF = (int)1e8;


int compute (vector < vector<int> > & V)
{

	int N = V.size();
	int M = V[0].size();

	int ans = 0;	
	for(int j = 0 ; j < M; j++)
	{
		int cost = 0;
		int mn = INF, mx = 0;

		for(int i = 0; i < N; i++)
		{
			mn = min(V[i][j], mn);
		    mx = max(V[i][j], mx);
		}

		int avg = (mn + mx) / 2;

		for(int i = 0; i < N; i++)
			cost += abs(V[i][j] - avg);

		ans += cost;

	}

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for(int test = 1; test <= T; test++)
	{
		int N;
		cin >> N;

		string s;
		string prevStr = "";

		vector <vector <int> > bigV;

		bool flag = false;
		for(int i = 0; i < N; i++)
		{
			cin >> s;
			s += '$';

			string p = "";
			p += s[0];

			char prev = s[0];
			int n = s.size();

			vector <int> lenV;

			int cnt = 1;
			for(int j = 1; j < n; j++)
			{
				if(s[j] == '$' || s[j] != prev)
				{
					lenV.push_back(cnt);
					p += s[j];
					prev = s[j];
					cnt = 1;
					
				}
				else
					cnt++;
			}

			bigV.push_back(lenV);

			if(prevStr != "" && prevStr != p)
			{
				flag = true;
				break;
			}

			prevStr = p;
		}

		cout <<  "Case #" << test << ": "; 

		if(flag)
			cout << "Fegla Won" << "\n";
		else
			cout << compute(bigV) << "\n";

	}


	return 0;
}