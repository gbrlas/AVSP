#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cassert>

using namespace std;

typedef long long ll;
typedef double ld;

int p, q, n;

int h[1<<7];
int g[1<<7];
int ext[1<<7]; //extra time we get if tower gets the kill
               //need to get in req shots before tower gets in ext shots
int req[1<<7]; //time we need to spend if we get the kill

int memo[1<<7][1<<11]; // memo[monster on][extra time]

int dp(int mon, int ti){
	if (mon == n) return 0;
	if (memo[mon][ti] != -1) return memo[mon][ti];
	
	int ans = 0;
	ans = max(ans,dp(mon+1,ti+ext[mon]));
	if (ti > req[mon] - ext[mon]){
		ans = max(ans,g[mon] + dp(mon+1,ti-(req[mon]-ext[mon])-1));
	}
	memo[mon][ti] = ans;
	//cout << "dp(" << mon << "," << ti << ") = " << ans << endl;
	return ans;
}

int main(){
	int T; cin >> T;
	for (int zz = 1; zz <= T; zz++){
		cin >> p >> q >> n;
		for (int i = 0; i < n; i++)
			cin >> h[i] >> g[i];
		h[0] += q;
		for (int i = 0; i < n; i++){
			ext[i] = (h[i]+q-1) / q;
			int rem = h[i]-(ext[i]-1)*q;
			//int rem = (h[i]%q);
			//if (rem == 0) rem = q;
			req[i] = (rem+p-1) / p;
		}
		/*
		for (int i = 0; i < n; i++)
			cout << ext[i] << " ";
		cout << endl;
		for (int i = 0; i < n; i++)
			cout << req[i] << " ";
		cout << endl;
		*/
		memset(memo,-1,sizeof(memo));
		int ans = dp(0,0);
		cout << "Case #" << zz << ": " << ans << endl;
	}
	
	return 0;
}
