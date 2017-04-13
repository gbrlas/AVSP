#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctype.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>

using namespace std;

typedef pair<int,int> ii;

#define INF 0x3f3f3f3f
#define ll long long

vector<ll> v;

int pal(ll x) {
	int t=0;
	ll num[20];
	while (x>0LL) {
		num[t++] = x%10LL;
		x /= 10LL;
	}
	
	int i,j;
	i = 0;	j = t-1;
	while (i<j) {
		if (num[i] != num[j]) return 0;
		i++; j--;
	}
	
	return 1;
}

int main() {
	int nt,nteste=1,ans;
	ll a,b;
	for (ll i=1LL; i<=10000000LL; i+=1LL)
		if (pal(i))
			if (pal(i*i))
				v.push_back(i*i);
	
	cin>>nt;
	while (nt--) {
		cin>>a>>b;
		ans = 0;
		for (int i=0; i<v.size(); i++)
			if (v[i]>=a && v[i]<=b) ans++;

		cout << "Case #" << nteste++ << ": " << ans << endl;
	}	

	return 0;
}
