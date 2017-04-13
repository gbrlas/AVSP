#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <time.h>
#include <math.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for (int i=0; i<n; i++)
#define FOR(i,x,y) for (int i=x; i<=y; i++)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
const double pi=acos(-1.0);

LL NOD(LL a, LL b)
{
	while(a!=0 && b!=0)
	{
		if (a>b) a%=b;
		else b%=a;
	}
	return a+b;
}

LL NOK(LL a, LL b)
{
	return (a*b)/NOD(a,b);
}

int main()
{
	freopen("C-small-attempt2.in","rt",stdin);
	freopen("output.txt","wt",stdout);



	int t;
	cin>>t;
	FOR(tests,1,t)
	{
		int N,L,H;
		int data[10009];
		cin>>N>>L>>H;
		printf("Case #%d: ",tests);

		FOR(i,0,N-1)
			scanf("%d",data+i);

		FOR(i,L,H)
		{
			FOR(j,0,N-1)
				if (data[j]%i && i%data[j])
					goto a1;
			cout<<i<<endl;
			goto b1;
a1:
			int a;
		}
		cout<<"NO"<<endl;
b1:
		int b;
	}

}
