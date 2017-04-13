#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)

//#define coutpoint5 setiosflags(ios::fixed)<<setprecision(5)

//#define maxn 60
//#define maxm 1000000
//#define MAXP 12

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int a[5][5],b[5][5];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	//ios_base::sync_with_stdio(false);
	
	int T;
	cin>>T;
	for (int TT=1;TT<=T;TT++)
	{
		cout<<"Case #"<<TT<<": ";
		int h1,h2;
		cin>>h1;
		FOR(i,1,4)
			FOR(j,1,4)
				cin>>a[i][j];
		cin>>h2;
		FOR(i,1,4)
			FOR(j,1,4)
				cin>>b[i][j];
		int count=0;
		int num=0;
		FOR(i,1,4)
			FOR(j,1,4)
				if (a[h1][i]==b[h2][j])
				{
					count++;
					num=a[h1][i];
				}
		if (count==1) 
			cout<<num<<endl;
		else
			if (count>1)
				cout<<"Bad magician!\n";
			else
				cout<<"Volunteer cheated!\n";
	}
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
