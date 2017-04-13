#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long LL;

LL g[1005];
int visited[1005];
LL profit[1005];

int main() {
	int cases;

	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		LL rounds, people;
		int groups;
		cin >> rounds >> people >> groups;
		for( int i = 0; i < groups; ++i ) {
			cin >> g[i];
		}
		//
		memset( visited, -1, sizeof(visited) );

		int q_start = 0;
		int index = 0;
		LL profit_sum = 0;

		do {
			visited[q_start] = index;
			profit[index] = profit_sum;
			//
			int next_q_start = q_start;
			LL load = 0;
			for( int i = 0; i < groups; ++i ) {
				LL add = g[next_q_start];
				if( add+load > people ) break;
				next_q_start = (next_q_start+1)%groups;
				load += add;
			}
			profit_sum += load;
			q_start = next_q_start;
			++index;
		} while( visited[q_start] == -1 );

		int cycle_length = index-visited[q_start];
		int pre_length = visited[q_start];

		LL res = 0;
		if( rounds <= pre_length ) {
			res = profit[rounds];
		} else {
			res = profit[pre_length];
			rounds -= pre_length;

			LL cycle_profit = profit_sum - profit[pre_length];
			res += (rounds / cycle_length) * cycle_profit;
			LL rem = rounds % cycle_length;
			res += profit[pre_length+rem]-profit[pre_length];
		}

		cout << "Case #" << caseid << ": " << res << endl;
	}
	return 0;
}
