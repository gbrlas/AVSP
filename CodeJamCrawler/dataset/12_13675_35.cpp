#include<iostream>
#include<cstdio>
//#define MX (int)1e9 * 2
using namespace std;
int main()
{
	int T , N , mot;
	int D[10015] , I[10015] , dp[10015];
	scanf("%d", &T );
	int c = 0 ;
	while( T-- )
	{
		scanf("%d", &N );
		for(int i = 0; i < N; ++i)
			scanf("%d %d", D+i , I + i );
		scanf("%d", &mot );
		D[N] = mot;
		for(int i = 0; i < N; ++i )
			dp[i] = 0;
		dp[0] = min( I[0] , D[0] );
		for(int i = 0; i < N; ++i )
		{
			dp[i] = min( dp[i] , I[i] );
			for(int j = i + 1; j < N; ++j)
			{
				if( D[j] <= D[i] + dp[i] )
				{
					dp[j] = max( D[j] - D[i] , dp[j] );
				}
			}
			if( dp[i] == 0 ) break;
		}
		bool f = false;
		for(int i = 0; i < N; ++i )
		{
			if( D[i] + dp[i] >= mot )
			{
				f =true;
				break;
			}
		}
		cout << "Case #"<<++c<<": ";
		if( f ) cout << "YES\n";
		else cout <<"NO\n";
	}
	return 0;
}