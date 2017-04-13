#pragma comment(linker, "/STACK:16777216")

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
#include<list>
using namespace std;

#define MAX 10007
#define INF 1000000007

#define pb push_back
#define MS( a ) memset( a,0,sizeof(a))
#define MSV( a,v ) memset( a,v,sizeof(v))

long N,D;
long P[MAX+7];
long H[MAX+7];
long Cover[MAX+7];

int main( void )
{
    long i,Icase,k = 0;

    freopen("Ain.txt","r",stdin );
    freopen("Aout.txt","w",stdout );

    scanf("%ld",&Icase );
    while( Icase-- ){
        scanf("%ld",&N );
        for( i=1;i<=N;i++ ){
            scanf("%ld%ld",&P[i],&H[i] );
        }
        scanf("%ld",&D );

        memset( Cover,0,sizeof(Cover));
        Cover[1]=2*P[1];
        long l = 1;
        for( i=2;i<=N;i++ ){
            while( l<i && Cover[l] < P[i] ){
                l++;
            }
            Cover[i] = P[i]+min( H[i],P[i]-P[l] );
        }

        for( i=1;i<=N;i++ ){
            if( Cover[i] >= D ) break;
        }

        if( i<=N ) printf("Case #%ld: YES\n",++k );
        else printf("Case #%ld: NO\n",++k );
    }


    return 0;
}
