#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#define MAX(x,y) (x) > (y) ? (x) : (y)
#define MIN(x,y) (x) < (y) ? (x) : (y)

using namespace std;
long long mul(int base, int place)
{
	if (place == 0)
		return 1;
	long long ans = 1;
	for (int i=0; i < place; i++)
		ans = ans * base;
	//cout << "Debug: base =" <<base <<"ans = "<<ans<<endl;
	return ans;
}
int dmap(char c, vector<char> v)
{
//	for (int i=0; i < v.size();i++)
//		cout << v[i];
//	cout << "char" <<c<<endl;
	for (int i=0; i < v.size(); i++)
	{
		if (c == v[i])
			return i;
	}
	return -1;
}
long long calculate(string s)
{
	vector <char> v;
	long long ans = 0;
	if (s.length() == 1)
		return 1;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != s[0])
		{
			v.push_back(s[i]);
			break;
		}
	}
	if (v.size() == 0)
		v.push_back('0');
//	v.push_back(s[1]);
	for (int i=0; i < s.length(); i++)
	{
		if (find(v.begin(), v.end(), s[i]) == v.end())
			v.push_back(s[i]);
	}
//	for (int i=0; i<v.size(); i++)
//		cout << v[i];
	int base = v.size();
	int len = s.length();
	for (int i=len-1; i >= 0; i--)
	{
		ans = ans + dmap(s[i],v) * mul (base, len - 1 - i);
//		cout << "Debug: ans = "<<ans <<endl;
	}
	return ans;
}
int main()
{
	ifstream fin ("a.in");
	int n;
	string s;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> s;
		cout << "Case #" << i+1 << ": " << calculate(s) << endl;
	}
	return 0;
}
