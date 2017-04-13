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
const int mod = 1000000007;
int cs, T;
string s[128];
int mi[128];
int mx[128];
int dp[10][1<<10];
bool sorted[128];
int n;
bool ok[128][128];

int hash[26];

bool check(string S) {
	fill(hash, 0);
	int i = 0;
	while(i < S.size()) {
		int j = i;
		while(j < S.size() && S[j] == S[i]) j++;
		hash[S[i] - 'a']++;
		if(hash[S[i] - 'a'] > 1)
			return 0;
		i = j;
	}
	return 1;
}

struct SUM {
	int H[26];
	SUM() {
		for(int i=0;i<26;i++)
			H[i] = 0;
	}
};

SUM operator + (const SUM &X, const SUM &Y) {
	SUM sum;
	for(int i=0;i<26;i++)
		sum.H[i] = X.H[i] + Y.H[i];
	return sum;
}

SUM masks[1<<10];
int vis[1<<10];
SUM totalHashSum[128];
int id;

SUM getSum(int mask) {
	if(mask == 0) {
		SUM sum;
		return sum;
	}
	if(vis[mask] == id) return masks[mask];
	vis[mask] = id;

	for(int i=0;i<n;i++)
		if(mask & 1<<i)
			return masks[mask] = totalHashSum[i] + getSum(mask ^ 1<<i);
}
int pos[128][128];
int solve(int prev,int mask) {
	if(mask == (1<<n) - 1) return 1;

	int &d = dp[prev][mask];
	if(~d) return d;
	d = 0;

	char prevChar = s[prev][s[prev].size()-1];
	for(int i=0;i<n;i++) {
		if(!(mask & (1<<i)) && ok[prev][i] && sorted[i]) {
			SUM sum = getSum(mask);
			bool isok = true;
			int k = pos[prev][i];
			while(k < s[i].size()) {
				if(sum.H[s[i][k] - 'a'] > 0) {
					isok = false;
					break;
				}
				k++;
			}
			if(isok)
				d = (d + solve(i, mask | (1<<i))) % mod;
		}
			
	}
	return d;
}


int main() {

	s(T);

	while(T--) {
		fill(dp, -1); ++id;
		fill(pos, -1);
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> s[i];

		for(int i=0;i<n;i++) {
			mi[i] = oo;
			mx[i] = 0;
			string t = s[i];
			sort(t.begin(), t.end());
			sorted[i] = check(s[i]);
			SUM sum;
			for(int j=0;j<s[i].size();j++) {
				sum.H[s[i][j]-'a']++;
			}
			totalHashSum[i] = sum;
		}

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				ok[i][j] = check(s[i] + s[j]);
				int k = 0;
				char lastChar = s[i][s[i].size()-1];
				while(k < s[j].size() && s[j][k] == lastChar)k++;
				pos[i][j] = k;
			}
				
		}
		int ans = 0;
		for(int i=0;i<n;i++) {
			if(sorted[i])
				ans = (ans + solve(i, 1<<i)) % mod;
		}
		printf("Case #%d: %d\n", ++cs, ans);
	}
}