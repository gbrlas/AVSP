#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int cs;
int n,S,p;
int a[128];

int dp[128][128];

int solve(int pos,int Sleft) {
    if( Sleft < 0 )return int(-1e9);
    if( pos == n )return 0;
    
    int &d = dp[pos][Sleft];
    if( ~d )return d;
    d = 0;
    
    for(int i=0;i<=10;i++) 
    for(int j=i;j-i<=2;j++)
    for(int k=j;k-i<=2 && k-j<=2;k++)
    if( i+j+k == a[pos] ) {
        int mx = max( i , max(j,k) );
        bool surprising = (k-i == 2 || k-j == 2 || j-i == 2);
        d = max( d , (mx>=p) + solve(pos+1,Sleft-surprising) );
    }
    return d;
}
int main() {

    int runs;
    cin >> runs;
    
    while( runs-- ) {
           memset( dp , -1 , sizeof dp );
           cin >> n >> S >> p;
           for(int i=0;i<n;i++) cin >> a[i];
           
           printf("Case #%d: %d\n",++cs,solve(0,S));
    }
    return 0;
}
