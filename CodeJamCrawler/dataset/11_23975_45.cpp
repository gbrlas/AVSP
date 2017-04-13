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

#define REP(i,n) for (LL i=0; i<n; i++)
#define FOR(i,x,y) for (int i=x; i<=y; i++)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define filein "A-large.in"

int main()
{
	freopen(filein,"rt",stdin);
	freopen("out.txt","wt",stdout);

	int T;
	cin>>T;


	FOR(t,1,T)
	{
		int posO=1,posB=1;
		int dO=0,dB=0;
		char ch;
		int pos, n;
		cin>>n;
		int res=0;
		FOR(i,0,n-1)
		{
			
			cin>>ch>>pos;
			if (ch=='O')
			{
				int toT=max(0,abs(posO-pos)-dB);
				res += (1+toT);
				dO += (toT+1);
				posO = pos;
				dB = 0;
			}
			if (ch=='B')
			{
				int toT=max(0,abs(posB-pos)-dO);
				res += (1+toT);
				dB += (toT+1);
				posB = pos;
				dO = 0;
			}
		}
		printf("Case #%d: %d\n",t,res);

	}
	fcloseall();
	//system("pause");
}
