#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *fip;
//int NA, NB;
int N;
__int64 A,B,C,D,x0,yo,M;
__int64 X,Y;
char Arg[5000];
int EndOfFile = 0;

__int64 Set[200000][2];

int inset(__int64 x, __int64 y)
{
	int i;
	for(i=0; i<N; i++)
	{
		if( Set[i][0] == x && Set[i][1] == y )
			return 1;
	}
	return 0;
}




int Process()
{
	int i, j, k;
	__int64 x,y;
	int S = 0;

	for(i=0; i<N; i++ )
	{
		for(j=i+1 ; j < N ; j++)
		{

			for(k = j+1 ; k < N ; k++)
			{
				x = 0;
				y = 0;
				if(i==j || j==k || k==i )
					continue;
				if( (Set[i][0] + Set[j][0] + Set[k][0]) % 3 == 0)
					//x = (Set[i][0] + Set[j][0] + Set[k][0]) / 3;
				//else continue;
				{
					if( (Set[i][1] + Set[j][1] + Set[k][1]) % 3 == 0)
					//y = (Set[i][1] + Set[j][1] + Set[k][1]) / 3;
				//else continue;

				//if( inset(x,y) )
					S++;
				}
			}
		}
	}
	return S;
}





	

		

__int64 Atoi(char *str)
{
	int i, len = strlen(str);
	__int64 t = 1, ret=0;

	for(i = len-1; i >=0 ; i--)
	{
		ret += t * (str[i] - '0');
		t *= 10;
	}

	return ret;
}





char *nstr( int end )
{
	int i = 0;
	char ch[2];

	if( EndOfFile )
		return "";

	while( !feof( fip ) )
	{
		fread( ch, 1, 1, fip);
		if( ( !end || ch[0] != ' ') && ch[0] != '\n' )
		{
			Arg[i++] = ch[0];
		}
		else
		{
			Arg[i] = '\0';
			return Arg;
		}
	}
	EndOfFile = 1;
	Arg[i-1] = '\0';
	return Arg;
}

int main()
{
	int i,j,k;
	FILE *fop;
	int nIP;

	fip = fopen("A-small-attempt0.in", "r");
	fop = fopen("A-small-attempt0.out", "w");

	//fip = fopen("A-large.in", "r");
	//fop = fopen("A-large.out", "w");

	//fip = fopen("input.txt", "r");
	//fop = fopen("output.txt", "w");

	//while( printf("%s\n", nstr(0)) != 1 );

	nIP = atoi( nstr(1));
	for( k = 0 ; k < nIP ; k++ )
	{
		N = atoi( nstr(1));
		A = Atoi( nstr(1));
		B = Atoi( nstr(1));
		C = Atoi( nstr(1));
		D = Atoi( nstr(1));
		x0 = Atoi( nstr(1));
		yo = Atoi( nstr(1));
		M = Atoi( nstr(1));


		X = x0;
		Y = yo;
		Set[0][0] = X;
		Set[0][1] = Y;

		for(i = 1 ; i < N ; i++)
		{
			X = (A * X + B) % M;
			Y = (C * Y + D) % M;
			Set[i][0] = X;
			Set[i][1] = Y;
		}






		//Process();

		fprintf( fop, "Case #%d: %d\n", k+1, Process());
		//printf("Case %d: %d %d\n", k+1, nStart[A], nStart[B]);
	}
	printf("\nDone.\n");
	//getch();
	return 0;
}



