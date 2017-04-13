// 1AA.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_DEPRECATE
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

#define fo(o,a,c) for( o = ( a ); o < ( c ); ++ o )
#define fr(r,c) fo( r, 0, ( c ) )
#define fi(c) fr( i, ( c ) )
#define fj(c) fr( j, ( c ) )
#define fk(c) fr( k, ( c ) )

#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )

using namespace std;
FILE *fr;
int ni() { int a; fscanf( fr, "%d", &a ); return a; }
double nf() { double a; fscanf( fr, "%lf", &a ); return a; }
char sbuf[100005]; string ns() { fscanf( fr, "%s", sbuf ); return sbuf; }
long long nll() { long long a; fscanf( fr, "%lld", &a ); return a; }

template <class T> void out( T a, T b ) {
	bool first = true;
	for( T i = a; i != b; ++ i )
	{ 
		if( !first ) printf( ", " );
		first = false;
		cout << * i;
	} 
	printf( "" ); 
}
template <class T> void outl( T a, T b ) {
	for( T i = a; i != b; ++ i ) {
		cout << * i << "\n"; 
	} 
}

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

int n, m, o;
using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	int i, j, k, t, tt;

	fr = fopen( "A-small-attempt1.in", "r");
	freopen( "A-small-attempt1.out", "w", stdout );

	bool hunpos = true;
	bool zeropos = true;


	int minN[101];
	minN[0] = 1;
	minN[1] = 100;
	minN[2] = 50;
	minN[3] = 100;
	minN[4] = 25;
	minN[5] = 20;
	minN[6] = 50;
	minN[7] = 100;
	minN[8] = 25;
	minN[9] = 1;
	minN[10] = 1;

	minN[100] = 1;

	fo(i, 1, 100)
	{
		j=i;
		int N = 100;
		if (j%2 == 0) { N /=2; j/=2; }
		if (j%2 == 0) { N /=2; j/=2; }
		if (j%5 == 0) { N /=5; j/=5; }
		if (j%5 == 0) { N /=5; j/=5; }
		minN[i] = N;
		//printf("%d => %d\n", i, N);
	}



	tt = ni();
	fo(t, 1, tt+1)
	{
		printf("Case #%d: ", t);
		n = ni();
		m = ni();
		o = ni();

		if (m == 100)
		{
			if (o > 0)
				printf("Possible\n");
			else
				printf("Broken\n");
		}
		else if (m == 0)
		{
			if (o < 100)
				printf("Possible\n");
			else
				printf("Broken\n");
		}
		else
		{

			if (n >= minN[m])
			{
				if (o > 0 && o < 100)
					printf("Possible\n");
				else
					printf("Broken\n");
			}
			else
				printf("Broken\n");
		}
	}
	//system("PAUSE");
	return 0;
}

