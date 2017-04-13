#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#define AND &&
#define OR ||
#define inf ( 1 << 30 );
using namespace std;
const double pi = 2 * acos (0.0);
const double eps = 1e-11;

int size, surprise, limit;

int arr[200];

bool compare ( const int &a, const int &b )
{
    if ( a > b ) return true;
    else return false;
}

bool check ( int score ); // Check if the score passes the limit

int main() {

	//freopen ("B-large.in","r",stdin);
	//freopen ("Problem B large.txt","w",stdout);

	int kase, count = 0;

	scanf ( "%d", &kase );

	int i, res;
	while ( kase-- )
    {
        scanf ( "%d %d %d", &size, &surprise, &limit );

        res = 0;
        for ( i = 0; i < size; i++ )
        {
            scanf ( "%d", &arr[i] );
        }

        sort ( arr, arr + size, compare );

        for ( i = 0; i < size; i++ )
        {
            //printf ( "%d ", arr[i] );
            if ( check ( arr[i] ) )
            {
                //printf ( "%d true\n", arr[i] );
                res++;
            }
            else break;
        }

        printf ( "Case #%d: %d\n", ++count, res );

    }
	return 0;
}

bool check ( int score )
{
    int highest;
    int middle, lowest;

    if ( score % 3 == 0 ) // Perfectly divisible
    {
        highest = score / 3;
        score -= highest;
    }
    else
    {
        highest = ( score / 3 ) + 1;
        score -= highest;
    }

    lowest = score / 2;
    middle = score - lowest;

    // If the highest passes the limit then its okay

    if ( highest >= limit )
    {
        return true;
    }
    else // Otherwise the score needs to be made surprising
    {
        if ( surprise > 0 && middle > 0 )
        {
            highest++;
            middle--;
            surprise--;

            if ( highest - middle > 2 ) return false;

            if ( highest >= limit )
            {
                //printf ( "2. ");
                return true;
            }
            else return false;
        }
    }

    return false;
}
