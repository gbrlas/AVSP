#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i,n) for(int i=0;i<(n);i++)
#define DFOR(i,n) for(int i=(n);i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define S(n) scanf("%d",&n)
#define SLL(n) scanf("%lld",&n)
#define SD(n) scanf("%lf",&n)
#define SS(n) scanf("%s",n)
#define P(n) printf("%d\n",n)
#define PLL(n) printf("%lld\n",n)
#define PD(n) printf("%lf\n",n)
#define PS(n) printf("%s\n",n)
#define eps 1e-9
#define inf 1e9
#define PB push_back
#define PF push_front

typedef long long LL;
typedef vector <int> VI;
typedef vector <LL> VLL;
typedef vector <double> VD;
typedef vector <string> VS;
typedef list <int> LI;
typedef list <LL> LLL;
typedef list <string> LS;
typedef list <double> LD;

int main()
{
	int T,A,N;
	LL motes[100],tmp,cnt;
	int count[101];
	count[0]=0;
	S(T);
	REP(k,1,T)
	{
		S(A);S(N);
		FOR(i,N)
			SLL(motes[i]);
		if(A==1)
		{
			printf("Case #%d: %d\n",k,N);
			continue;
		}
		/*if(N==1 && motes[0]>2*A-1)
		{
			printf("Case #%d: %d\n",k,1);
			continue;
		}*/
		sort(motes,motes+N);
		tmp=A;
		cnt=0;
		FOR(i,N)
		{
			if(tmp>motes[i])
				tmp+=motes[i];
			else
			{
				//cout<<motes[i]<<" "<<tmp<<endl;
				while(tmp<=motes[i])
				{
					tmp+=tmp-1;
					cnt++;
				}
				tmp+=motes[i];
			}
			count[i+1]=cnt;
			//cout<<motes[i]<<" "<<tmp<<" "<<cnt<<endl;
		}
		REP(i,1,N)
		{
			if(count[i]-count[i-1]>N-i+1)
			{
				cnt=count[i-1]+N-i+1;
				break;
			}
		}
		printf("Case #%d: %lld\n",k,cnt);
	}
	return 0;
}