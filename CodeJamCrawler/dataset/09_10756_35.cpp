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
#include <fstream>


using namespace std;

typedef long double ld;
typedef long long ll;
double EPS = 1e-9;
int INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back



vector<int> heh2(string temp) {
	vector<int> ds(10);
	for(int i = 0; i < temp.size(); i++) ds[temp[i]-'0']++;
	ds.erase(ds.begin());
	return ds;
}

vector<int> heh(int N) {
	vector<int> ds(9);
	while(N) {
		int dig = N%10;
		if(dig) ds[dig-1]++;
		N/=10;
	}
	return ds;
}


int main(){
	int T;
	string temp;
	getline(cin, temp);
	T = atoi(temp.c_str());

	for(int cnt = 0; cnt < T; cnt++) {
		getline(cin, temp);
		int N = atoi(temp.c_str());
		vector<int> ds = heh(N);
		int ans;
		while(1){
			N++;
			if(heh(N) == ds) {
				ans = N;
				break;
			}
		}

		

		cout << "Case #" << (cnt+1) << ": " << ans << endl;
	}
}


