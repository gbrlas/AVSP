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
int n,tot;
int a[maxn][maxn],b[maxn][maxn];

void readdata()
{
     memset( a, 0, sizeof(a) );
     tot=0;
     
     scanf( "%d", &n );
     for ( int i=1; i<=n; i++ )
     {
         int x1,y1,x2,y2;
         scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 );
         if ( x1>x2 ) swap( x1, x2 );
         if ( y1>y2 ) swap( y1, y2 );
         
         for ( int j=x1; j<=x2; j++ )
         for ( int k=y1; k<=y2; k++ ) { tot++; a[j][k]=1; }
     }
}

void work()
{
     int step=0;
     
     while ( tot!=0 )
     {
           for ( int i=1; i<=100; i++ )
           for ( int j=1; j<=100; j++ )
           {
               b[i][j]=a[i][j];
               if ( a[i][j]==1 && a[i-1][j]==0 && a[i][j-1]==0 ) b[i][j]=0;
               if ( a[i][j]==0 && a[i-1][j]==1 && a[i][j-1]==1 ) b[i][j]=1;
           }
           
           tot=0;
           for ( int i=1; i<=100; i++ )
           for ( int j=1; j<=100; j++ ) 
           {
               a[i][j]=b[i][j];
               if ( a[i][j]==1 ) tot++;
           }
           
           
           /*
           for ( int i=1; i<=30; i++ )
           {
               for ( int j=1; j<=30; j++ ) cout << a[i][j];
               cout << endl;
           }
           cout << tot << endl;
           cout << endl;
           */
     
           step++;
           
           //if ( step>10 ) break;
     }
     
     cout << step << endl;
}

int main()
{
    freopen( "c.in", "r", stdin );
    freopen( "c.out", "w", stdout );
    
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

