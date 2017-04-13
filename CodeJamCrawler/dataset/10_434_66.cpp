#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAX_N=2011;
int r,k,n,tot;
int g[MAX_N];
int flag[MAX_N];
long long size[MAX_N];
bool v[MAX_N];

int main()
{
    freopen( "t.in", "r", stdin );
    freopen( "t.out", "w", stdout );
    
    int test;
    scanf( "%d", &test );
    for ( int ttt=1; ttt<=test; ttt++ )
    {
        scanf( "%d%d%d", &r, &k, &n );
        for ( int i=1; i<=n; i++ ) scanf( "%d", &g[i] );
        
        memset( v, false, sizeof(v) );
        tot=0;
        int i=1;
        while ( !v[i] )
        {
            int j=i;
            long long sum=0;
            while ( true )
            {
                sum+=g[j];
                if ( j==n ) j=1;
                else j++;
                
                if ( sum+g[j]>k ) break;
                if ( j==i ) break;
            }
            
            tot++;
            flag[tot]=i;
            size[tot]=sum;
            
            v[i]=true;
            i=j;
        }
        
        long long ans=0;
        int j=1;
        while ( i!=flag[j] && r>0 )
        {
            ans+=size[j];
            r--;
            j++;
            tot--;
        }
        
        long long temp=0;
        for ( int i=j; i<=j+tot-1; i++ ) temp+=size[i];        
        ans+=(r/tot)*temp;
        for ( int i=j; i<=j+r%tot-1; i++ ) ans+=size[i];
        
        printf( "Case #%d: ", ttt );
        cout << ans << endl;
    }
    
    return 0;
}
