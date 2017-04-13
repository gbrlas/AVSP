// 1BA.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_DEPRECATE
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <iomanip> // for setprecision()
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

double r[100];
char buf[100][100];
int bf[100][100];

double wp[100][3];
double owp[100][3];
double oowp[100][3];




int _tmain(int argc, _TCHAR* argv[])
{
	int i, j, k, t, tt;

	fr = fopen( "A-large.in", "r");
	freopen( "A-large.out", "w", stdout );

	cout << setprecision(12);
	tt = ni();
	fo(t, 1, tt+1)
	{
		printf("Case #%d:\n", t);
		n = ni();

		_(r,0.0);
		_(buf,0);
		_(bf,-1);
		_(wp,0.0);
		_(owp,0.0);
		_(oowp,0.0);

		fi(n)
		{
			string s = ns();
			fj(n)
			{
				buf[i][j] = s[j];
				if (s[j] == '1') { bf[i][j] = 1;		wp[i][0] += 1.0;	wp[i][1] += 1.0; }
				else if (s[j] == '0') { bf[i][j] = 0;						wp[i][1] += 1.0; }

			}
			wp[i][2] = (wp[i][0] / wp[i][1]);
		}

		fi(n)
		{
			fj(n)
			{
				if (bf[j][i] == 0 || bf[j][i] == 1)
				{
					owp[i][0] += (wp[j][0]-bf[j][i]*1.0)/(wp[j][1]-1.0);
					owp[i][1] += 1.0;
				}
				//printf("%f %f \t", owp[i][0], owp[i][1]);
			}
			owp[i][2] = (owp[i][0] / owp[i][1]);
			//printf("(%f)\n", owp[i][2]);
		}

		fi(n)
		{
			fj(n)
			{
				if (bf[i][j] == 0 || bf[i][j] == 1)
				{
					oowp[i][0] += owp[j][2];
					oowp[i][1] += 1.0;
				}
				//printf("%f %f \t", oowp[i][0], oowp[i][1]);
			}
			oowp[i][2] = (oowp[i][0] / oowp[i][1]);
			//printf("(%f)\n", oowp[i][2]);

			r[i] = 0.25 * wp[i][2] + 0.50 * owp[i][2] + 0.25 * oowp[i][2];
		}

		

		fi(n)
			cout << r[i] << endl;
			//printf("%.6f\n", r[i]);
	}
	//system("PAUSE");
	return 0;
}


