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

int t,y,z,n,i,r,cnt,no,j,p;
float nao[1002],ken[1002],tmp;

int main()
{
    //scanf("%d",&t);
    t = inp();
    
    while ( t-- )
    {
       cnt = 0;
       no++;
       
       //scanf("%d",&n);
       n = inp();
       for ( i=0;i<n;i++ )
       {
           scanf("%f",&nao[i]);
       }
       
       sort(nao,nao+n);
       
       for ( i=0;i<n;i++ )
       {
           scanf("%f",&ken[i]);
       }
       
       sort(ken,ken+n);
       
       j = 0;
       for ( i=0;i<n;i++ )
       {
           while ( (ken[j]<nao[i]) && (j<n) )
           {
              	j++;
           }
           if ( j<n )
           {
           		cnt++;
           		j++;
           }
           else
           break;
       }
       z = n - cnt;
       cnt = 0;
       j = 0;
       for ( i=0;i<n;i++ )
       {
           if ( (nao[i]>ken[j]) && (j<n) )
           {
              	cnt++;
              	j++;
           }
       }
       y = cnt;
       r = n>>1;
       for ( i=0;i<r;i++ )
       {
           	tmp = ken[i];
           	ken[i] = ken[n-i-1];
           	ken[n-i-1] = tmp;
       }
       cnt = 0;
       for ( i=0;i<n;i++ )
       {
           	if ( ken[i]>nao[i] )
           	cnt++;
           	else
           	break;
       }
       p = n - cnt;
       if ( y<p )
       y = p;
       printf("Case #%d: %d %d\n",no,y,z);
    }
    return 0;
}