#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

void cheapest(vector<int> cells, set<int> release, int coins, set<int> &costs){
	if(release.empty()){
		costs.insert(coins);
		return;
	}
	
	for(set<int>::iterator itr=release.begin(); itr != release.end(); ++itr){
		int rem = (*itr)-1;
		int i = 0;
		for(i = rem; i < cells.size(); ++i){if(cells[i] == 0) break;}
		int right = (i-1)-rem;
		for(i = rem; i >= 0; --i){if(cells[i] == 0) break;}
		int left = rem-(i+1);

		set<int> rel;
		remove_copy(release.begin(), release.end(), inserter(rel, rel.begin()), *itr);
		cells[rem] = 0;
		cheapest(cells, rel, coins+left+right, costs);
		cells[rem] = 1;
	}
}

int main(int argc, char* argv[]){
	freopen("input_small.txt", "r", stdin);
	freopen("output_small.txt", "w", stdout);

	int N=0;
	scanf("%d\n", &N);

	for(int c = 0; c < N; ++c){
		int Q = 0, P = 0;
		scanf("%d %d\n", &Q, &P);

		vector<int> cells(Q, 1);
		set<int> release;

		for(int p = 0; p < P; ++p){
			int n = 0;
			scanf("%d", &n);
			release.insert(n);
		}

		int coins = 0;
		set<int> costs;
		cheapest(cells, release, coins, costs);
		
		printf("Case #%d: %d\n", c+1, *(costs.begin()));



	}


	return 0;
}