#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;

int lookup(int w, int str);
int memo[20][501] = {0};
int memoized[20][501] = {0};
int length = 0;
string welcome = "welcome to code jam";
string text;

int main()
{
	ifstream ifs;
	ofstream ofs;
	string buf;
	ifs.open("C-large.in", ios::in);
	ofs.open("C-large.out", ios::out);
	getline(ifs, buf);
	int n = atoi(buf.c_str());
	for(int i = 0; i < n; i++)
	{
		getline(ifs, buf);
		text = buf;
		length = text.length();
		for(int j = 0; j < 20; j++)
		{
			for(int k = 0; k < 501; k++)
			{
				memo[j][k] = 0;
				memoized[j][k] = 0;
			}
		}
		char out[5];
		int r = lookup(0, 0);
		sprintf(out, "%04d", r % 10000);
		ofs << "Case #" << i + 1 << ": " << out << endl;
	}
	return 0;
}

int lookup(int w, int str)
{
	int res = 0;
	if(memoized[w][str]) return memo[w][str];
	if(w >= 19)
	{
		memoized[w][str] = 1;
		memo[w][str] = 1;
		return 1;
	}
	if(str >= length)
	{
		memoized[w][str] = 1;
		memo[w][str] = 0;
		return 0;
	}
	if(welcome[w] == text[str])
		res = (lookup(w + 1, str + 1) + lookup(w, str + 1)) % 10000;
	else
		res = lookup(w, str + 1);
	memoized[w][str] = 1;
	memo[w][str] = res;
//	cout << "(" << w << ", " << str << ") : " << res << endl;
	return res;
}
