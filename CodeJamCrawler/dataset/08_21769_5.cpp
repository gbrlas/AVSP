#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<n;i++)

#define gn atoi( nstr(1));
#define GN Atoi( nstr(1));

typedef __int64 INT;

FILE *fip;
//int NA, NB;
int T,P,K,L;
char Arg[5000];
int EndOfFile = 0;

__int64 let[2000];


void sort()
{
	int i,j;

	F0(i,L)
	{
		for( j = i+1 ; j < L ; j++)
		{
			if( let[i] < let[j])
			{
				int temp = let[i];
				let[i] = let[j];
				let[j] = temp;
			}
		}
	}
}




INT Process()
{
	int i, j, k;
	INT ret = 0, nl = 0;

	sort();

	i = 0;

	while( i < L )
	{
		nl++;
		if( nl > P )
			break;
		for( j = 0 ; j < K ; j++ )
		{
			ret += nl * let[i];
			i++;
			if(i >= L)
				break;
		}
	}

	if( nl > P )
	{
		return -1;
	}

	return ret;





	
}
		

unsigned __int64 Atoi(char *str)
{
	int i, len = strlen(str);
	unsigned __int64 t = 1, ret=0;

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
	int *la;
	
	fip = fopen("A-small-attempt1.in", "r");
	fop = fopen("A-small-attempt1.out", "w");

	//fip = fopen("A-large.in", "r");
	//fop = fopen("A-large.out", "w");

	//fip = fopen("input.txt", "r");
	//fop = fopen("output.txt", "w");



	//while( printf("%s\n", nstr(0)) != 1 );

	nIP = atoi( nstr(1));
	for( k = 0 ; k < nIP ; k++ )
	{
		P = gn;
		K = gn;
		L = gn;
		//NA = GN;
		//NB = GN;

		j=0;
		F0(i,L)
		{
			let[j++] = gn;
		}

		INT ans = Process();
		if( ans == -1 )
			fprintf( fop, "Case #%d: %s\n", k+1, "Impossible");
		else
			fprintf( fop, "Case #%d: %d\n", k+1, ans);
		printf( "Case #%d: %d\n", k+1, ans);
	}
	printf("\nDone.\n");
	//getch();
	return 0;
}



