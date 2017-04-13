// Queries.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <math.h>


FILE *fip;
int S, Q;

struct _SEARCH_ENGINE
{
	char Name[101];
	int NoQuery;
} SearchEngine[200];

char Queries[2000][2000];

int SEptr( char *sQuery )
{
	int i ;
	for( i = 0 ; i < S ; i++ )
	{
		if( !strcmp( sQuery, SearchEngine[i].Name) )
			return i;
	}
	return 199;
}

int Switches( int Qptr )
{
	int i;
	int SEPC = 0;	//Search Engine query Present Count
	for( i = 0 ; i < S ; i++ )
	{
		SearchEngine[i].NoQuery = 1;
	}
	
	for( i = Qptr ; i < Q ; i++ )
	{
		int pSE = SEptr(Queries[i]);
		if( pSE < 199 )
		{
            if( SearchEngine[pSE].NoQuery == 1 )
			{
				SearchEngine[pSE].NoQuery = 0;
				SEPC++;
				if( SEPC == S )
				{
					return 1 + Switches(i);
				}
			}
		}
	}
	return 0;
}
	


char NextStr( char *str )
{
	int i = 0;
	char ch[2];

	while( !feof( fip ) )
	{
		fread( ch, 1, 1, fip);
		if( ch[0] != ' ' && ch[0] != '\n')
		{
			str[i++] = ch[0];
		}
		else
		{
			str[i] = '\0';
			return ch[0];
		}
		if( feof(fip) )
		{
			str[i] = '\0';
			return '\n';
		}
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i,j,k;
	FILE *fop;
	char Arg[1000];
	int nIP;

	fip = fopen("input", "r");
	fop = fopen("output", "w");

	NextStr(Arg);
	nIP = atoi( (const char *)Arg);
	for( k = 0 ; k < nIP ; k++ )
	{
		//Read Search Engines
		NextStr(Arg);
		S = atoi( (const char *)Arg);
		for( i = 0 ; i < S ; i++ )
		{
			char tch;
			int NamePtr = 0;
			do
			{
				tch = NextStr(Arg);
				strcpy( &(SearchEngine[i].Name[NamePtr]), Arg );
				NamePtr += strlen(Arg);
				SearchEngine[i].Name[NamePtr++] = tch;
			}
			while( tch != '\n');
			SearchEngine[i].Name[NamePtr-1] = '\0';
		}

		//Read Queries
		NextStr(Arg);
		Q = atoi( (const char *)Arg);
		for( i = 0 ; i < Q ; i++ )
		{
			char tch;
			int NamePtr = 0;
			do
			{
				tch = NextStr(Arg);
				strcpy( &(Queries[i][NamePtr]), Arg );
				NamePtr += strlen(Arg);
				Queries[i][NamePtr++] = tch;
			}
			while( tch != '\n');
			Queries[i][NamePtr-1] = '\0';
		}
		
		//Process
		fprintf( fop, "Case #%d: %d\n", k+1, Switches(0));
		//printf("Case %d: ", k+1);
	}
	return 0;
}



