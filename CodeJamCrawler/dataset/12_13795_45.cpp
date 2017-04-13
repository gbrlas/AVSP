#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <string.h>

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define pi 3.14159265358979
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define L(s) (int)((s).size())
#define ms(x) memset(x,0,sizeof(x))
#define del(y,x) erase(y.begin()+x)

typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
const int inf = 2147483647;
const ll llinf = 9223372036854775807ll;
const int st = 100010;
const int st1 = 1000010;
const ll mod = 1000000007;

int pr[10000100];

int main()
{
#ifndef online_judge
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	int test = 1;
	while(T)
	{
		int A,B;
		ll ans = 0;
		ms(pr);
		cin >> A >> B;
		for(int i = A;i <= B;i++)
		{
			int k = i;
			string b = "";
			if(pr[k]==0)
			{
				while(k)
				{
					b+=k%10+48;
					k/=10;
				}
				ll kol = 0;
				reverse(ALL(b));
				for(int j = 0;j <= L(b);j++)
				{
					ll ch = 0;
					if(b[0]!='0')
					{
						for(int l = 0;l < L(b);l++)
						{
							ch*=10;
							ch+=b[l]-48;
						}
						if(pr[ch]==0 && ch<=B && ch>=A)
						{
							pr[ch]++;
							kol++;
						}
					}
					b = b[L(b)-1] + b;
					b.erase(b.begin()+L(b)-1);
				}
				kol--;
				ans+=(1+kol)*kol/2;
			}

		}
		printf("Case #%d: %d",test,ans);
		printf("\n");
		test++;
		T--;
	}
}