#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <fstream>

using namespace std;

/*int solve(const vector<string>& _v, const vector<int>& _curr)
{
	for(int i = 0; i < _v.size(); ++i)
	{

	}
}*/

int dp[200][200];

int solve(string& _str1, string& _str2, int _curr1, int _curr2)
{
	if(_curr1 >= _str1.size() && _curr2 >= _str2.size())
	{
		return 0;
	}
	
	if(_curr1 >= _str1.size() || _curr2 >= _str2.size())
	{
		if(_curr1 >= _str1.size())
		{
			for(int i = _curr2; i < (int)_str2.size(); ++i)
			{
				if(_str2[i] != _str1[_str1.size()-1])
					return 100000;
			}

			return (int)_str2.size() - _curr2;
		}

		if(_curr2 >= _str2.size())
		{
			for(int i = _curr1; i < (int)_str1.size(); ++i)
			{
				if(_str1[i] != _str2[_str2.size()-1])
					return 100000;
			}

			return (int)_str1.size() - _curr1;
		}
	}

	if(dp[_curr1][_curr2] != - 1)
		return dp[_curr1][_curr2];
	
	if(_str1[_curr1] == _str2[_curr2])
	{
		dp[_curr1][_curr2] = solve(_str1, _str2, _curr1+1, _curr2+1);
		return dp[_curr1][_curr2];
	}
	
	int res = 100000;
	
	if(_curr1 - 1 >= 0)
	{
		if(_str1[_curr1 - 1] == _str2[_curr2])
		{
			res = min(res, solve(_str1, _str2, _curr1, _curr2+1) + 1 );
		}
	}
	if(_curr2 - 1 >= 0)
	{
		if(_str1[_curr1] == _str2[_curr2 - 1])
		{
			res = min(res, solve(_str1, _str2, _curr1 + 1, _curr2) + 1 );
		}
	}

	if(_curr1 + 1 < _str1.size() && _curr1 - 1 >= 0)
	{
		if(_str1[_curr1 + 1] == _str2[_curr2] && _str1[_curr1-1] == _str1[_curr1])
		{
			res = min(res, solve(_str1, _str2, _curr1 + 2, _curr2 + 1) + 1 );
		}
	}

	if(_curr2 + 1 < _str2.size() && _curr2 - 1 >= 0)
	{
		if(_str2[_curr2 + 1] == _str1[_curr1] && _str2[_curr2-1] == _str2[_curr2])
		{
			res = min(res, solve(_str1, _str2, _curr1 + 1, _curr2 + 2) + 1 );
		}
	}

	dp[_curr1][_curr2] = res;
	return dp[_curr1][_curr2];
}

int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);

	int T;
	cin >> T;

	for(int c = 1;  c <= T; ++c)
	{
		memset(dp, -1, sizeof(dp));
		int N;
		cin >> N;
		vector<string> str;
		vector<int> curr;

		for(int i = 0; i < N; ++i)
		{
			string temp;
			cin >> temp;
			curr.push_back(0);
			str.push_back(temp);
		}

		//solve(str, curr);
		int res = solve(str[0], str[1], 0, 0);
		if(res >= 100000)
			cout << "Case #"<< c << ": " << "Fegla Won" << endl;
		else
			cout << "Case #"<< c << ": " << res << endl;
	}

	return 0;
}