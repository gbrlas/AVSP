#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <math.h>
#include<set>
#include<vector>
#include <map>;
using namespace std;

typedef unsigned long long int ll;
typedef map<int, int> mii;

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
vector<int> used;
bool isInVec(vector<int> &l, int k)
{
	for(int i = 0; i < (int)l.size(); i ++)
	{
		if(l[i] == k)
			return true;
	}
	return false;
}
int m;
int main()
{

	freopen("C-large.in", "rt", stdin);
    freopen("C-large.out", "wt", stdout);

	cin >> t;

	powers.resize(8);
	powers[0] = 1;
	for(int i = 1; i < 8; i++)
	{
		powers[i]=powers[i-1]*10;
	}

	int curlennum = 0;
	for(int tk = 0; tk < t; tk++)
	{
		cin >> a >> b;
		curlennum = lennum(a);

		ans = 0;
		
		
		for(int n = a; n < b; n++)
		{
			used.clear();
			for(int j = curlennum-1; j >= 1; j--)
			{
				m=n%powers[j]*powers[curlennum-j]+n/powers[j];
				
				if(n < m && m <= b && !isInVec(used, m))
				{
					used.push_back(m);
					ans++;
				}
			}
			
		}
		
		cout << "Case #" << tk+1 << ": " << ans << endl;
	}
}