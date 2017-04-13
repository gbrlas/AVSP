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
#define PI 3.14159265358979
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define L(s) (int)((s).size())
#define ms(x) memset(x,0,sizeof(x))
#define del(y,x) erase(y.begin()+x)

typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;
const int ST = 100010;
const int ST1 = 1000010;
const ll MOD = 1000000007;

ll ABS(ll a)
{
	if(a<0)
		return a*(-1);
	else
		return a;
}

int alph[26] = {24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	//int n;
	//cin >> n;
	//'a' -> 'y', 'o' -> 'e', and 'z' -> 'q'
	//alph['a'-'a'] = 'y'-'a';
	//alph['o'-'a'] = 'e'-'a';
	//alph['z'-'a'] = 'q'-'a';
	//alph['q'-'a'] = 'z'-'a';
	//char a[3][50];
	//gets(a[0]);
	//for(int i = 0;i < n;i++)
	//{
	//	gets(a[i]);
	//}
	//char b[50];
	//for(int i = 0;i < n;i++)
	//{
	//	gets(b);
	//	for(int j = 0;j < strlen(b);j++)
	//	{
	//		if(b[j]!=' ')
	//			alph[a[i][j]-'a']=b[j]-'a';
	//	}
	//}
	//sort(alph,alph+26);
	//for(int i = 0;i < 26;i++)
	//{
	//	cout << alph[i] << ",";
	//}
	char c[110];
	int T;
	cin >> T;
	int test = 1;
	gets(c);
	while(T)
	{
		gets(c);
		string ans = "";
		for(int j = 0;j < strlen(c);j++)
		{
			if(c[j]!=' ')
				ans+=(alph[c[j]-'a']+'a');
			else
				ans+=c[j];
		}
		printf("Case #%d: ",test);
		cout << ans;
		printf("\n");
		test++;
		T--;
	}
}