#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <cstdio>
#include <map>

using namespace std;

string makeString (char ch1, char ch2)
{
	string result;
	
	result.push_back(ch1);
	result.push_back(ch2);
	return result;
}

string solve ()
{
	map < string , char > a;
	map < string , bool > b;
	
	int t;
	
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		string s;
		
		cin >> s;
		a[makeString(s[0], s[1])] = a[makeString(s[1], s[0])] = s[2];
	}
	
	cin >> t;
	
	for (int i = 0; i < t; ++i)
	{
		string s;
		
		cin >> s;
		b[s] = b[makeString(s[1], s[0])] = true;
	}

	string s;
	
	cin >> t;
	
	for (int i = 0; i < t; ++i)
	{
		char ch;
		
		cin >> ch;
		s.push_back(ch);

		if (s.size() < 2)
			continue;
		
		string st = s.substr(s.length() - 2, 2);
		
		if (a.count(st))
		{
			s.erase(s.length() - 2, 2);
			s.push_back(a[st]);
		}
		else
		{
			bool f = true;
			
			for (int i = 0; i < s.size() - 1 && f; ++i)
				for (int j = i + 1; j < s.size() && f; ++j)
					if (b.count(makeString(s[i], s[j])))
					{
						s.clear();
						f = false;
					}
		}
	}
	
	return s;
}

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	
	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		string s = solve();
		
		cout << "Case #" << (i + 1) << ": [";
		
		for (string::iterator it = s.begin(); it != s.end(); ++it)
			cout << *it << (it + 1 == s.end() ? "" : ", ");

		cout << "]" << endl;
	}		
	return 0;
}
