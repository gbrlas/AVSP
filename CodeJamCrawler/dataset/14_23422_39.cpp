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

int main() {
	// your code goes here
	int t,a[4][4],b[4][4],i,j,count,ch1,ch2,ans;
	
	t = inp();
	
	for ( int k=1;k<=t;k++ )
	{
		count = 0;
		
		ch1 = inp();
		for ( i=1;i<=4;i++ )
			for ( j=1;j<=4;j++ )
				a[i][j] = inp();
		
		ch2 = inp();
		for ( i=1;i<=4;i++ )
			for ( j=1;j<=4;j++ )
				b[i][j] = inp();
		
		for ( i=1;i<=4;i++ )
		{
			for ( j=1;j<=4;j++ )
				if ( a[ch1][i] == b[ch2][j] )
				{
					ans = a[ch1][i];
					count = count + 1;
				}
		}
		printf("Case #%d: ",k);
		if ( count == 1 )
		printf("%d\n",ans);
		else if ( count > 1 )
		printf("Bad magician!\n");
		else
		printf("Volunteer cheated!\n");
	}
	
	return 0;
}