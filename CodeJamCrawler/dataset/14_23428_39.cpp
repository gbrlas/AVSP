#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#define getcx getchar_unlocked
#ifndef ONLINE_JUDGE
    #define getcx getchar
#endif
using namespace std;

inline int inp()
{
   int n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   return n*sign;
}
 
int main() 
{
	int T,i,a,l=1;
	double c,f,x,b,t,q,z;
	//cin >> T;
	T = inp();
 
	while ( T-- )
	{
		q = 2;
		t = 0;
		z = 0;
		a = 1;
		cin >> c >> f >> x;
		double T = x/2;
		for ( i=1;;i++ ) 
		{
			t = t + c/q;
			//printf("%lf ",c/q);
			z = z+c;
			q = q+f;
			if ( T > (t+x/q) ) 
			{
				T = t+x/q;
			}
			else
			break;
		}
		printf("Case #%d: %0.7lf\n",l,T);
		l++;
		}
	return 0;
}