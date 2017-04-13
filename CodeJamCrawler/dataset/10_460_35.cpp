#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;

const int maxn=55;
int n;
int t[maxn*3];
int a[maxn*3][maxn*3],b[maxn*3][maxn*3];

int ttt( int p )
{
    int t=0;
    for ( int i=1; i<=p; i++ ) t+=i;
    for ( int i=1; i<p; i++ ) t+=i;
    return t;
}

void readdata()
{
     scanf( "%d", &n );
     for ( int i=1; i<=n; i++ )
     {
         t[i]=i;
         for ( int j=1; j<=i; j++ ) scanf( "%d", &a[i][j] );
     }
     for ( int i=n+1; i<=2*n-1; i++ )
     {
         t[i]=2*n-i;
         for ( int j=1; j<=2*n-i; j++  ) scanf( "%d", &a[i][j] );
     }
}

void work()
{
     int ans=n;
     
     // findMax
     for ( int i=1; i<=2*n-1; i++ )
     {
         int now=0;
         int j=1,
             k=t[i];
         while ( j<k )
         {
               if ( a[i][j]==a[i][k] ) 
               {
                    k--;
                    j++;
                    continue;
               }
               j++;
               now++;
         }
         if ( t[i]+now>ans ) ans=t[i]+now;
     }
     
     cout << ttt( ans )-ttt(n) << endl;
}

int main()
{
    freopen( "a.in", "r", stdin );
    freopen( "a.out", "w", stdout );
    
    int test;
    scanf( "%d", &test );
    for ( int T=1; T<=test; T++ )
    {
        printf( "Case #%d: ", T );
        readdata();
        work();
    }
    
    return 0;
}

