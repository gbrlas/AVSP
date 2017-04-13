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

using namespace std;

typedef long double ld;
typedef long long ll;
double EPS = 1e-9;
int INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back

int figure(int R, int k, int N, vector<int> & people) {
	vector<int> moveahead(N);
	vector<int> winmoney(N);
	
	for(int i = 0; i < N; i++){
		int mv = 1;
		int cursum = people[i];
		int blah = 1;
		while(++blah <= N && cursum + people[(i+mv)%N] <= k){
			cursum += people[(i+mv)%N];
			mv++;
		}
		moveahead[i] = mv % N;
		winmoney[i] = cursum;
	}
	
	int ret = 0;
	int curpos = 0;
	for(int i = 0; i < R; i++) {
		ret += winmoney[curpos];
		curpos = (curpos + moveahead[curpos])%N;
	}
	
	return ret;
}

int main(){
	int T;
	cin >> T;
	
	string line;
	getline(cin,line);

	for(int cnt = 0; cnt < T; cnt++) {
		getline(cin, line);
		stringstream ss(line.c_str());
		int R, k, N;
		ss >> R >> k >> N;
		vector<int> people;
		getline(cin, line);
		stringstream ss2(line.c_str());
		int temp;
		while(ss2 >> temp) people.push_back(temp);
		assert(people.size() == N);
		
		cout << "Case #" << (cnt+1) << ": " << figure(R, k, N, people) << endl;
	}
}
	
	
	
	