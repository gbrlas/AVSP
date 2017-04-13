#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <ctype.h>
#include <string>
#include <stdio.h>

using namespace std;

typedef long double ld;
typedef long long ll;
ld EPS = 1e-9;
int INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back


bool computedans[1003][1003];
ld memans[1003][1003];


template<class T> T choose (T n, T k)
{
	if(n < k) return 0;
	
	T ret = 1;
	for (T i = n, j = 1 ; j <= n ; i--, j++){
	    ret *= n; 
	    ret /= i;
	}
	return ret;
}


template<class T> T factorial(T n)
{
	T ret=1;
	while(n>1) ret*=n--;
	return ret;
}


ld pd(ll n, ll m) {
	if(m >= 18) return 0;

	ld ret = 0;
	for(int k = 0; k <=min(n-m,18LL); k++) {
		ret+= ((k%2)?-1.0:1.0)/factorial(k);
	}

	return ret/factorial(m);
}

ld ans(ll n, ll f) {
	if(n==f) return 0;
	if(computedans[n][f]) return memans[n][f];
	//cout << "hmm " << n << " " << f << endl;
	
	ld &ret = memans[n][f];
	ret = 0;
	
	for(int i = 1; i <= n-f; i++) {
		ret += pd(n-f,i)*(1+ans(n,f+i));
	}

	ret += pd(n-f,0);
	ret /= (1-pd(n-f,0));

	computedans[n][f]=true;
	return ret;
}


int main() {
	for(int i = 0; i < 1003; i++)for(int j = 0; j < 1003; j++) computedans[i][j]=false;

	int T, N;
	cin >> T;
	int temp;
	for(int cnt = 0; cnt < T; cnt++) {
		cin >> N;
		int f=0;
		for(int i = 0; i < N; i++) {
			cin >> temp;
			if(temp == i+1) f++;
		}
		
		cout << "Case #" << (cnt+1)<<": " << (N-f) << endl;
		//cout << "Case #" << (cnt+1)<<": " << (ans(N,f)-(N-f)) << endl;
	}

	return 0;
}
