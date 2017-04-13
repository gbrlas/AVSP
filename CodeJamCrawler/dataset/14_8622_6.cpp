#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	map <int,int> mapa;
	int nc;
	int row;
	int a[4];
	int b[4];
	int num;

	scanf("%d", &nc);

	for (int h = 0; h < nc; h++)
	{
		mapa.clear();
		scanf( "%d", &row );
		for( int i=0; i<4; i++ )
		{
			for (int j = 0; j < 4; j++)
			{
				scanf("%d", &num);
				if( i + 1 ==row )
					a[j]=num;
			}
		}
		scanf( "%d", &row );
		for( int i=0; i<4; i++ )
		{
			for (int j = 0; j < 4; j++)
			{
				scanf("%d", &num);
				if( i + 1 ==row )
					b[j]=num;
			}
		}	
		/*
		for (int i = 0; i < 4; i++)
		{
			printf("%3d", a[i]);
		}
		puts("");
		for (int i = 0; i < 4; i++)
		{
			printf("%3d", b[i]);
		}
		puts("");
		*/
		int t=0;
		int ans;
		for (int i = 0; i < 4; i++)
		{
			mapa[ a[i] ]++;
		}
		for (int i = 0; i < 4; i++)
		{
			if( mapa[ b[i] ] == 1 )
			{
				t++;
				ans = b[i];
			}
		}

		if( t==1 )
			printf("Case #%d: %d\n",h+1,ans);
		else if( t == 0 )
			printf("Case #%d: Volunteer cheated!\n",h+1);
		else
			printf("Case #%d: Bad magician!\n",h+1);

	}

	return 0;
}