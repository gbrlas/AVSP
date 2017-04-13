/*	Author:			Kumar Subham
 *	Date:			27-Apr-2013
 *	Email:			krsubham@gmail.com
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <string>
#include <cmath>

using namespace std;

typedef long long int ll;

/* Basic Macros */
#define FOR(i, begin, end)		for ( typeof(begin) i = begin; i < end; ++i )
#define ITERATE(p, arr)			for ( typeof(arr.begin()) p = arr.begin(); p != arr.end(); ++p )
#define ini(a, v)				memset(a, v, sizeof(a))

int main(void)
{
	int testcases;
	cin >> testcases;

	FOR(i, 1, testcases+1) {
		ll r, t, n = 0;
		cin >> r >> t;

		long double d = sqrt(4*pow(r, 2) + 1 -4*r + 8*t);
		long double temp = (( 1 - 2*r) + d)/4;
		n = (ll)temp;
		cout << "Case #" << i << ": " << n << endl;
	}
	return 0;
}
