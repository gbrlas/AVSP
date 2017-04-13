#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cassert>

using namespace std;

struct Vine {
	int dist;
	int len;
};

struct Cache {
	bool done;
	bool result;
};

Cache simple_memo[10001];
Cache pair_memo[10001][10001];

bool can_do_it(const vector<Vine>& vines,
               int vine_idx,
               bool at_end,
               int previous_vine,
               int D) {

	Cache& cache = at_end ? simple_memo[vine_idx] : pair_memo[vine_idx][previous_vine];

	if (cache.done) {
		return cache.result;
	}

	int dist_to_reach = vines[vine_idx].dist;
	if (at_end) {
		dist_to_reach += vines[vine_idx].len;
	}
	else {
		dist_to_reach += vines[vine_idx].dist-vines[previous_vine].dist;
	}

	if (dist_to_reach >= D) {
		return true;
	}
	else {
		for (int i = vine_idx+1; i < vines.size() && vines[i].dist <= dist_to_reach; ++i) {

			if (vines[i].len < vines[i].dist-vines[vine_idx].dist) {
				if (can_do_it(vines, i, true, -1, D)) {
					cache.result = true;
					cache.done = true;
					return true;
				}
			}
			else if (can_do_it(vines, i, false, vine_idx, D)) {
				cache.result = true;
				cache.done = true;
				return true;
			}
		}
		cache.result = false;
		cache.done = true;
		return false;
	}
}

void handle_case(int case_nbr) {
	cout << "Case #" << case_nbr << ": ";

	int nvines;
	cin >> nvines;

	vector<Vine> vines;

	for (int i = 0; i < nvines; i++) {
		int d,l;
		cin >> d >> l;
		Vine vine;
		vine.dist = d;
		vine.len = l;
		vines.push_back(vine);
	}

	int D;
	cin >> D;

	vines[0].len = vines[0].dist;

	for (int i = 0; i <= nvines; i++) {
		simple_memo[i].done = false;
		for (int j = 0; j <= nvines; j++) {
			pair_memo[i][j].done = false;
		}
	}

	if (can_do_it(vines, 0, true, -1, D)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	cout << endl;
}

int main(void) {
	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		handle_case(i+1);
	}

	return 0;
}
