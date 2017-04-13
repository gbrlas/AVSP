#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <cstring>
#define oo (int)1e9
#define fill( a , v ) memset( a , v , sizeof (a) )
#define bits( x ) __builtin_popcount( x )
#define gcd( a , b ) __gcd( a, b )
#define lcm( a , b ) (a/gcd( a, b ) ) * b
#define s(n)scanf( "%d" , &n )
#define add push_back
const int mxn = 1000000 + 10;
typedef long long ll;
#define pii pair<double,double>
using namespace std;
int cs, T;
int F[4][4], S[4][4];


int main() {
	int first, second;
	s(T);

	while(T--) {
		s(first);first--;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				s(F[i][j]);
		s(second);second--;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				s(S[i][j]);

		int fmask = 0;
		for(int i=0;i<4;++i)
			fmask |= 1 << (F[first][i] - 1);

		int smask = 0;
		for(int i=0;i<4;i++)
			smask |= 1 << (S[second][i] - 1);

		if(bits(fmask & smask) == 0)
			printf("Case #%d: Volunteer cheated!\n", ++cs);
		else if(bits(fmask & smask) > 1)
			printf("Case #%d: Bad magician!\n", ++cs);
		else {
			int val = fmask & smask;
			int count = 0;
			while(val) val /= 2, count++;
			printf("Case #%d: %d\n", ++cs, count);
		}
	}
}