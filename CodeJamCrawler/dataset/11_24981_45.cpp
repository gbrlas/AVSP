#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <fstream>
#include <string>
//#include <windows.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define repk(i,k,n) for(int i = k; i < n; i++)
#define clr(a,x) memset(a,x,sizeof(a))
#define clearqueue(x) while(!x.empty()) x.pop();
#define clearvector(arr,n) rep(i,n)arr[i].clear();

int po[32];
void calcPow(){
	po[0] = 1;
	rep(i,30)
		po[i+1] = po[i] * 2;
}



int main()
{
	ifstream cin("b.in");
	ofstream cout("b.txt");

	int t, n, r, sum, a, mn, casenum = 1;
	cin >> t;
	while(t--){
		cin >> n;
		r = sum = 0;
		mn = INT_MAX;
		rep(i,n){
			cin >> a;
			sum += a;
			r ^= a;
			if(a < mn) mn = a;
		}
		cout << "Case #" << casenum++ << ": ";
		if(r == 0) cout << sum - mn << endl;
		else cout << "NO" << endl;
	
	}

	return 0;
}