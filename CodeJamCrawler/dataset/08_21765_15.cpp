#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *fip;
//int NA, NB;
int T;
char Arg[5000];
int EndOfFile = 0;

__int64 A, B, P;

int pset[10/*000000*/], psetc;
__int64 set[100000000];

int inpset( int p )
{
	int i;
	for(i = 0 ; i < psetc ; i++ )
	{
		if( pset[i] == p )
			return 1;
	}
	return 0;
}
/*
int shhset( __int64 n1, __int64 n2)
{
	int i,j;
	int n1p = 0 ,n2p = 0;

	for(i = 0 ; i < ns ; i++ )
	{
		n1p = 0 ,n2p = 0;
		for(j = 0 ; j < sc[i] ; j++ )
		{
			if( set[i][j] == n1 )
				n1p = 0;
			if( set[i][j] == n2 )
				n2p = 0;
		}
		if( n1p && n2p )
			return 1;
	}
	return 0;
}*/

void uset( __int64 n1, __int64 n2)
{
	__int64 i,j;
	int x = set[n2];
	for( i = 0 ; i <= B ; i++ )
	{
		if( set[i] == x )
			set[i] = set[n1];
	}
}


int ispr( __int64 p)
{
	int i;
	for(i=2;i<p;i++)
	{
		if( p % i == 0)
			return 0;
	}
	return 1;
}

__int64 sh( __int64 n1, __int64 n2)
{
	__int64 i;
	for( i = P ; i <= n1 && i <= n2 ; i++)
	{
		if( (n1 % i == 0) && (n2 % i == 0) &&  ispr(i))
			return i;
	}
	return 0;
}


int Process()
{
	__int64 i, j, k;
	__int64 S = B - A + 1;

	psetc = 0;

	for( i = A ; i <= B ; i++ )
	{
		set[i] = i;
	}

	for( i = A; i <= B ; i++ )
	{
		for( j = i+1 ; j <= B ; j++ )
		{
			int p = sh(i,j);
			if( p )
			{
				/*if( !inpset(p) )
				{
					S--;
					pset[psetc++] = p;
				}*/

				if( set[i] != set[j])
				{
					S--;
					uset(i,j);
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
	int i,k;
	FILE *fop;
	int nIP;

	fip = fopen("B-small-attempt0.in", "r");
	fop = fopen("B-small-attempt0.out", "w");

	//fip = fopen("B-large.in", "r");
	//fop = fopen("B-large.out", "w");

	//fip = fopen("input.txt", "r");
	//fop = fopen("output.txt", "w");

	//while( printf("%s\n", nstr(0)) != 1 );

	nIP = atoi( nstr(1));
	for( k = 0 ; k < nIP ; k++ )
	{
		A = Atoi( nstr(1));
		B = Atoi( nstr(1));
		P = Atoi( nstr(1));
		//NA = atoi( nstr(1));
		//NB = atoi( nstr(1));

		fprintf( fop, "Case #%d: %ld\n", k+1, Process());
		//printf("Case %d: %d %d\n", k+1, nStart[A], nStart[B]);
	}
	printf("\nDone.\n");
	//getch();
	return 0;
}



