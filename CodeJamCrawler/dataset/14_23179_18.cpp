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
string a[128];

string A,B;

int vis[128][128];
int dp[128][128];
int vid;

int solve(int x,int y) {
    
    if(x == A.size() && y == B.size()) return 0;
    
    if(x == A.size() || y == B.size()) return oo;
    
    if(A[x] != B[y]) return oo;
    
    
    int &v = vis[x][y];
    int &d  = dp[x][y];
    
    if( v == vid ) return d;
    v = vid;
    d = oo;
    
    if(x+1 < A.size() && A[x] == A[x+1])
        d = min(d, 1 + solve(x+1,y) );
    
    if(y+1 < B.size() && A[x] == B[y+1])
        d = min(d, 1 + solve(x,y+1));
        
    if(A[x] == B[y])
    d = min(d, solve(x+1,y+1));
    
    return d;
}

int main() {
    
	string s;
    freopen("input.txt", "r", stdin);
	s(T);

	while(T--) {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
        cin >> a[i];
        
        int ans = oo;
        for(int i=0;i<n;i++) {
            bool ok = true;
            int t = 0;
            for(int j=0;j<n && ok;j++) {
                B = a[i];
                A = a[j];
                ++vid;
                int ret = solve(0,0);
                if(ret == oo)
                    ok = false;
                t += ret;
            }
            if(ok)
                ans = min(ans, t);
        }
        if(ans < oo)
		printf("Case #%d: %d\n", ++cs, ans);
        else
        printf("Case #%d: Fegla Won\n", ++cs, ans);
	}
}