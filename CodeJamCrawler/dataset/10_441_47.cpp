#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int MAX_N=61;
int n,k;
char a[MAX_N][MAX_N],b[MAX_N][MAX_N];

void readdata()
{
    scanf( "%d%d\n", &n, &k );
    for ( int i=1; i<=n; i++ ) 
    {
        for ( int j=1; j<=n; j++ ) scanf( "%c", &a[i][j] );
        scanf( "\n" );
    }
    
    for ( int i=1; i<=n; i++ )
    for ( int j=1; j<=n; j++ ) b[j][n-i+1]=a[i][j];
    
    for ( int j=1; j<=n; j++ )
    {
        int i=n;
        while ( i>0 )
        {
            while ( b[i][j]=='.' )
            {
                bool flag=false;
                for ( int k=i; k>=1; k-- )
                if ( b[k][j]!='.' ) flag=true;
                if ( flag==false ) break;
                
                for ( int k=i; k>1; k-- ) swap( b[k][j], b[k-1][j] );
                b[1][j]='.';
            }
            i--;
        }
    }
    
    /*
    for ( int i=1; i<=n; i++ )
    {
        for ( int j=1; j<=n; j++ ) cout << b[i][j]; 
        cout << endl;
    }
    */
}

void work()
{
    bool flag1=false,
         flag2=false;
        
    // heng
    for ( int i=1; i<=n; i++ )
    {
        int tot=0,
            las=0;
        for ( int j=1; j<=n; j++ )
        {
            if ( b[i][j]=='.' ) { tot=0; las=0; } else
            if ( b[i][j]=='R' && las==1 ) tot++; else
            if ( b[i][j]=='B' && las==2 ) tot++; else
            if ( b[i][j]=='R' && las!=1 ) { tot=1; las=1; } else
            if ( b[i][j]=='B' && las!=2 ) { tot=1; las=2; }
            if ( tot>=k && las==1 ) flag1=true;
            if ( tot>=k && las==2 ) flag2=true;
        }
    }
    
    // shu
    for ( int j=1; j<=n; j++ )
    {
        int tot=0,
            las=0;
        for ( int i=1; i<=n; i++ )
        {
            if ( b[i][j]=='.' ) { tot=0; las=0; } else
            if ( b[i][j]=='R' && las==1 ) tot++; else
            if ( b[i][j]=='B' && las==2 ) tot++; else
            if ( b[i][j]=='R' && las!=1 ) { tot=1; las=1; } else
            if ( b[i][j]=='B' && las!=2 ) { tot=1; las=2; }
            if ( tot>=k && las==1 ) flag1=true;
            if ( tot>=k && las==2 ) flag2=true;
        }
    }
    
    // xie
    for ( int i=1; i<=n; i++ )
    for ( int j=1; j<=n; j++ )
    {
        int kk=0,
            tot=0,
            las=0;
        while ( true )
        {
            int ti=i+kk,
                tj=j+kk;
            if ( ti>n || ti<1 || tj>n || tj<1 ) break;
            if ( b[ti][tj]=='.' ) { tot=0; las=0; } else
            if ( b[ti][tj]=='R' && las==1 ) tot++; else
            if ( b[ti][tj]=='B' && las==2 ) tot++; else
            if ( b[ti][tj]=='R' && las!=1 ) { tot=1; las=1; } else
            if ( b[ti][tj]=='B' && las!=2 ) { tot=1; las=2; }
            if ( tot>=k && las==1 ) flag1=true;
            if ( tot>=k && las==2 ) flag2=true;         
            kk++;   
        }
    }
    
    // shu
    for ( int i=1; i<=n; i++ )
    for ( int j=1; j<=n; j++ )
    {
        int kk=0,
            tot=0,
            las=0;
        while ( true )
        {
            int ti=i+kk,
                tj=j+kk;
            if ( ti>n || ti<1 || tj>n || tj<1 ) break;
            if ( b[ti][tj]=='.' ) { tot=0; las=0; } else
            if ( b[ti][tj]=='R' && las==1 ) tot++; else
            if ( b[ti][tj]=='B' && las==2 ) tot++; else
            if ( b[ti][tj]=='R' && las!=1 ) { tot=1; las=1; } else
            if ( b[ti][tj]=='B' && las!=2 ) { tot=1; las=2; }
            if ( tot>=k && las==1 ) flag1=true;
            if ( tot>=k && las==2 ) flag2=true;            
            kk--;
        }
    }
    
    if ( flag1 && flag2 ) cout << "Both" << endl; else
    if ( flag1 ) cout << "Red" << endl; else
    if ( flag2 ) cout << "Blue" << endl; else cout << "Neither" << endl;
}

int main()
{
    freopen( "a.in", "r", stdin );
    freopen( "a.out", "w", stdout );
    
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
