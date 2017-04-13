
/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)	
#define mod 1000000007
#define MAXN 1000010

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;

int main(){

	int t;
	scanf("%d\n",&t);
	string str="yhesocvxduiglbkrztnwjpfmaq";
	FOR(test,1,t+1)
	{
		string s,r="";
		getline(cin,s);

		REP(i,s.length())
		{
			char ch=s[i];
			if(ch==' ')
			{
				r+=" ";
				continue;
			}
			char c=str[ch-97];
			r+=c;
		}

		cout<<"Case #"<<test<<": "<<r<<endl;


	}
	return 0;
}
