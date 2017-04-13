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


int main() {
	int T, N;
	cin >> T;
	int temp;
	for(int cnt = 0; cnt < T; cnt++) {
		cin >> N;
		vector<int> nums;
		int possible = 0;
		for(int i = 0; i < N; i++) {
			cin >> temp;
			nums.push_back(temp);
			possible ^= temp;
		}
		possible = !possible;
		sort(nums.rbegin(), nums.rend());
		int sum = 0;
		int ret = 0;
		int heh = 0;
		for(int i = 0; i < N; i++) {
			sum+=nums[i];
			heh^=nums[i];
			int rem = 0;
			for(int j = i+1; j < N; j++) rem ^=nums[j];
			if(heh==rem && i!=N-1) ret=max(ret, sum); 
		}
		
		cout << "Case #" << (cnt+1)<<": ";
		if(possible) cout << ret;
		else cout << "NO";
		cout << endl;
	}

	return 0;
}
