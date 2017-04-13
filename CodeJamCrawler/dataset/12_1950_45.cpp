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
	
	ll T,S,p,pi;
	cin>>T;
	rep(i,T)
	{
	cin>>N;
	cin>>S;
	cin>>p;
	ll k=0;
		rep(j,N)
		{
			cin>>pi;
			ll p3=pi/3;
			ll pl=pi%3;
		//	cout<<p3<<" "<<pl<<endl;
			
			if (pl!=0) p3++;
			
			if (p3>=p) {k++;continue;}
			
			if (pl==2) 
				if (p3+1>=p) 
					if (S>0) {S--;k++; continue;}

			if (pl==0 && p3>0) 
				if (p3+1>=p) 
					if (S>0) {S--;k++; continue;}

					
		}
		printf("Case #%I64d: %I64d\n",i+1,k);
	}
	
	return 0;
}
