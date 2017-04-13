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
int a,b,k;

int main() {
    
	string s;
    freopen("input.txt", "r", stdin);
	s(T);

	while(T--) {
        int ans = 0;
        cin >> a >> b >> k;
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                if((i&j) < k) {
                    ans++;
                    //cout << i << " " << j << endl;
                }
		printf("Case #%d: %d\n", ++cs, ans);
	}
}