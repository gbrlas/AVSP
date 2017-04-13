#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int T , W , L , N , R[1015] , rx[1015] , ry[1015] , pos[1015];
	scanf("%d" , &T );
	int c = 0;
	bool s = false;
	while( T-- )
	{
		bool f = false;
		scanf("%d %d %d" , &N , &W , &L );
		for(int i = 0; i < N; ++i)
			scanf("%d" , R + i ) , pos[i] = i;
		
		for(int i = 1; i < N; ++i)
		{
			for(int j = i; j > 0 ; --j)
			{
				if( R[j] < R[j-1] ) 
				{
					int t = R[j];
					R[j] = R[j-1];
					R[j-1] = t;
					t = pos[j];
					pos[j] = pos[j-1];
					pos[j-1] = t;
				}
				else
					break;
			}
		}
		int x = 0 , y = 0, nx = 0;
		rx[0] = ry[0] = 0;
		nx = rx[0] + R[0];
		bool re = false;
		for(int i = 1; i < N; ++i)
		{
			y =  ry[i-1] +  R[i-1] + R[i];
			if( y <= L )
			{
			if( !re )
			  rx[i] = rx[i-1] ;
			else
			  rx[i] = x + R[i];
			  ry[i] = y;
			  nx = max( nx , rx[i] + R[i] );
			}
			else
			{
				re = true;
				rx[i] = nx + R[i];
				ry[i] = 0;
				x = nx;
				nx = rx[i] + R[i];
			}
			if( rx[i] > W ) { f = true; }
		}
		cout <<"Case #"<<++c<<":";
		//if( f ) cout << " ERROR"  << "\n";
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				if( pos[j] == i )
				{
				cout << " " << rx[j] << " " << ry[j] ;
				break;
				}
			
		cout <<"\n";
	}
	
	return 0;
}