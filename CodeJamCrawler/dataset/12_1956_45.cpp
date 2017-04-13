#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <set>
#include <map>

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define rp(i,s,n) for((i)=(s);(i)<(n);(i)++)
#define _INF (1e9+1)
#define ll long long
#define _N 100001
#define MP make_pair 
#define x first
#define y second
#define _no_char '_'
#define _NONE -1

using namespace std;			

ll i,j,N,M,n,m,k,p;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	vector<int> used(2e6+1,0);
	ll T,A,B;
	cin>>T;
	
	rep(p,T)
	{
	cin>>A>>B;

	ll len;
	for(len=1;len<=B;len*=10);
	len/=10;
/*	cout<<len<<endl;
	cout<<A<<endl;
	cout<<B<<endl;
	*/
	
	rp(i,A,B+1) used[i]=0;
	
	ll sm=0;
	rp(i,A,B+1) if (used[i]==0)
	{
		
		j=i;
		ll k=0;
		ll iter=1;
		//printf("k=%I64d iter=%I64d j=%I64d sm=%I64d\n",k,iter,j,sm);	
		j=j/len+(j*10)%(len*10);
		//printf("k=%I64d iter=%I64d j=%I64d sm=%I64d\n",k,iter,j,sm);
		while(j!=i && used[j]==0)
		{
		 
		//	printf("k=%I64d iter=%I64d j=%I64d sm=%I64d\n",k,iter,j,sm);
			used[j]=1;
			used[i]=1;
		if ((j/len) >= 1 && j>=A && j<=B){	
			k += iter;
			iter++;
}
			j=j/len+(j*10)%(len*10);
			//printf("k=%I64d iter=%I64d j=%I64d sm=%I64d\n",k,iter,j,sm);
		}
		sm+=k;
	}
		printf("Case #%I64d: %I64d\n",p+1,sm);
	}
	
	
	
	
	return 0;
}