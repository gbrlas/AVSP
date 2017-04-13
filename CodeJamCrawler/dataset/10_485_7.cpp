#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;

const int maxn=111;
int n;
long long l;
long long f[maxn*maxn];
int a[maxn];

void readdata()
{
     cin >> l >> n;
     for ( int i=1; i<=n; i++ ) scanf( "%d", &a[i] ); 
}

void work()
{
     memset( f, 255, sizeof(f) );
     f[0]=0;
     for ( int i=0; i<10000; i++ ) if ( f[i]!=-1 )
     for ( int j=1; j<=n; j++ )
     for ( int t=1; i+a[j]*t<=10000; t++  )
     if ( f[i+a[j]*t]==-1 || f[i+a[j]*t]>f[i]+t ) f[i+a[j]*t]=f[i]+t;
     
     long long ans=-1;
     for ( int i=1; i<=n; i++ )
     {
         for ( int j=0; j<=10000; j++ )
         if ( (l-j)%a[i]==0 && f[j]!=-1 )
         if ( ans==-1 || (l-j)/a[i]+f[j]<ans ) ans=(l-j)/a[i]+f[j];
     }
     
     if ( ans==-1 ) printf( "IMPOSSIBLE\n" );
     else cout << ans << endl;
}

int main()
{
    freopen( "b.in", "r", stdin );
    freopen( "b.out", "w", stdout );
    
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

