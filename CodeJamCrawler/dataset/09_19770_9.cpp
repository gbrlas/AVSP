#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<math.h>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert> 
#include <list>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;
#define getcx getchar_unlocked

inline void in( int &n ) {
        n=0;
        int ch=getcx();
        while( ch < '0' || ch > '9' ) ch=getcx();
        while( ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}

 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define fr(i, n) for(i=0;i<n;i++)
#define fr2(i, a, n) for(i=a;i<n;i++)
#define mem(a, n) memset(a, n, sizeof(a))
typedef vector<int> VI;
int main() {
	int t, k;
	in(t);
	fr2(k, 1, t+1) {
		string s;
		char a[30];
		scanf("%s", &a);
		string tmp = a;
		tmp = "0" + tmp;
		s = tmp;
		
		sort(all(s));
		string m = "9999999999999999999999999999999";
		do {
			if(s>tmp && s<m) 
				m = s;
		} while(next_permutation(all(s)));
		if(m[0]=='0')
			m = m.substr(1, m.size()-1);
		printf("Case #%d: %s\n", k, m.c_str());
	}
}
