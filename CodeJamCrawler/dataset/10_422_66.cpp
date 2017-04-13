#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    freopen( "s.in", "r", stdin );
    freopen( "s.out", "w", stdout );
    
    int test;
    scanf( "%d", &test );
    for ( int ttt=1; ttt<=test; ttt++ )
    {
        int n,k;
        scanf( "%d%d", &n, &k );
        
        bool flag=true;
        for ( int i=1; i<=n; i++ )
        if ( ( k&( 1<<(i-1) ) ) == 0 ) flag=false;
        
        printf( "Case #%d: ", ttt );
        if ( flag ) printf( "ON\n" );
        else printf( "OFF\n" );
    }    
    
    return 0;
}
