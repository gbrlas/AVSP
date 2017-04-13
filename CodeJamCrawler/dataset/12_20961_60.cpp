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

vector<int> powers;

int lennum(int a)
{
	string l;
	char buff[20];
	int temp = sprintf(buff, "%d", a);
	l = string(buff);
	return l.length();
}

int a, b, ans, t;
int main()
{

	freopen("C-small-attempt0.in", "rt", stdin);
    freopen("C-small-attempt0.out", "wt", stdout);

	cin >> t;

	powers.resize(8);
	powers[0] = 1;
	for(int i = 1; i < 8; i++)
	{
		powers[i]=powers[i-1]*10;
	}

	int curlennum = 0;
	int nextl = 0;
	for(int tk = 0; tk < t; tk++)
	{
		cin >> a >> b;
		curlennum = 0;
		nextl = 0;
		curlennum = lennum(a);
		for(int i = 0; i < curlennum; i++)
		{
			nextl=nextl*10+9;
		}

		ans = 0;
		
		for(int n = a; n < b; n++)
		{
			int m;
			map<int, int> used;
			for(int j = curlennum-1; j >= 1; j--)
			{
				m=n%powers[j];
				m=m*powers[curlennum-j]+n/powers[j];

				if(a<=n && n < m && m <= b)
				{
					if(!used[m])
					{
						used[m]++;
						ans++;
					}
				}
			}
		}
		cout << "Case #" << tk+1 << ": " << ans << endl;
	}
}