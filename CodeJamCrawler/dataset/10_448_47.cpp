#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int MAX_N=111,MAX_V=260;
int dd,ii,n,m;
int a[MAX_N];
int f[MAX_N][MAX_V];

void readdata()
{
    scanf( "%d%d%d%d", &dd, &ii, &m, &n );
    for ( int i=1; i<=n; i++ ) scanf( "%d", &a[i] );
}

void work()
{
    memset( f, 10, sizeof(f) );
    for ( int i=0; i<=255; i++ ) f[0][i]=0;
    
    for ( int i=1; i<=n; i++ )
    {
        // delete
        for ( int j=0; j<=255; j++ ) f[i][j]=f[i-1][j]+dd;
        
        // insert
        for ( int k=0; k<=255; k++ )
        for ( int j=0; j<=255; j++ )
        {
            int t=abs( k-j )-1;
            if ( t<0 ) t=0;
            if ( m!=0 && f[i][k]>f[i-1][j]+t/m*ii+abs( a[i]-k ) ) f[i][k]=f[i-1][j]+t/m*ii+abs( a[i]-k );
        }
        
        // change
        for ( int j=0; j<=255; j++ )
        for ( int k=0; k<=255; k++ )
        if ( abs( k-j )<=m && f[i][k]>f[i-1][j]+abs( k-a[i] ) ) f[i][k]=f[i-1][j]+abs( k-a[i] );
    }
    
    int ans=9999999;
    for ( int i=0; i<=255; i++ )
    {
        if ( f[n][i]<ans ) ans=f[n][i];
        //if ( f[n][i]==11 ) cout << i << endl;
    }
    printf( "%d\n", ans );
}

int main()
{
    freopen( "b.in", "r", stdin );
    freopen( "b.out", "w", stdout );
    
    int  test;
    scanf( "%d", &test );

    for ( int T=1; T<=test; T++ )
    {
        printf( "Case #%d: ", T );
        readdata();
        work();
    }
    
    return 0;
}
