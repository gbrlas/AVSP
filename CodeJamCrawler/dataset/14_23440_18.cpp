#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define getcx getchar_unlocked
#ifndef ONLINE_JUDGE
    #define getcx getchar
#endif
#define mod 1000000
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
	int cases;
	cases = inp();
	for(int c1=1;c1<=cases;c1++){
	int a,b,k,ret=0;
	a=inp();b=inp();k=inp();
	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			if((i&j)<k)
				ret++;
	printf("Case #%d: %d\n",c1,ret);
	}
}