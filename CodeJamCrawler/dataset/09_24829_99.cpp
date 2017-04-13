#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string str;
int n;

int go()
{
	const int mod = 10000;

	n = str.length();
	str = " " + str;
	const char *phase = " welcome to code jam";
	int c[501][19] = {0,};

	for(int i=1; i<=n; ++i) for(int j=1; j<=19; ++j)
	{
		if(j == 1) {
			c[i][j] = phase[j] == str[i] ? 1 : 0;
		}
		else {	// j > 2
			c[i][j] = 0;
			if(phase[j] != str[i]) continue;
			for(int k = 1; k < i; ++ k)
			{
				c[i][j] += c[k][j - 1];
				c[i][j] %= mod;
			}
		}
	}
	
	int ret = 0;
	for(int i=1; i<=n; ++i)
	{
		ret += c[i][19];
		ret %= mod;
	}
	return ret;
}

int main()
{
//	freopen("input.txt","r",stdin);
	freopen("c-small.in","r",stdin);
	freopen("c-small.out","w",stdout);
	int T;

	getline(cin, str);
	istringstream(str) >> T;

	for(int t=1;t<=T; ++t)
	{
		getline(cin, str);	
		printf("Case #%d: %04d\n", t, go() % 10000);
	}
	return 0;
}