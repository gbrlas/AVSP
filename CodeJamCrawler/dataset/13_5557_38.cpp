// Author: Aman Choudhary

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
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) ((a)>(b)?(a):(b))
int ABS(int a) { if ( a < 0 ) return (-a); return a; }



bool vowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return true;
    }
    return false;
}

int main()
{

	freopen("ii.in","r",stdin);
    freopen("output.txt","w",stdout);
	ill t,ii=1,i,k,j;
	cin >> t;
	while ( t-- ) {
		string s;
		int n;
		cin >> s >> n;
		ill answer = 0;
		ill last = -1;
		ill cnt = 0;
		ill nn = s.size();
		F(i,0,nn) {
			if ( !vowel(s[i]) ) {
				cnt++;
				if ( cnt >= n ) {
					answer += ((i-n+1)-last)*(nn-i);
					last = i-n+1;
				}
			} else {
				cnt = 0;
			}
		}
		cout << "Case #" << ii << ": " << answer << endl;
		ii++;
	}
	return 0;
}
