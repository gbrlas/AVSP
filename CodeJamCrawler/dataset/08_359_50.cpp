#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;
using std::make_pair;
using std::sort;

int solve(vector<pair<int, int> > data) {
	int res=0, acc=0;
	sort(data.begin(), data.end());
	for (int i=0; i<data.size(); i++)
		if (data[i].second == 0) // arrive
			acc++;
		else
			if (acc > 0) acc--;
			else res++;
	return res;
}

int main() {
	FILE *fin = fopen("in.txt", "r");
	FILE *fout = fopen("out.txt", "w");

	int tests;
	fscanf(fin, "%d\n", &tests);
	for (int test=0; test<tests; test++) {
		int turn;
		fscanf(fin, "%d", &turn);
		int n, m;
		fscanf(fin, "%d %d", &n, &m);

		vector<pair<int, int> > data1, data2;
		
		for (int j=0; j<n+m; j++) {
			int start, end, sh, sm, eh, em;
			fscanf(fin, "%d:%d %d:%d", &sh, &sm, &eh, &em);
			start = sh*60 + sm;
			end = eh*60 + em + turn;
			int a=1,b=0;
			if (j >= n) { int t=start; start=end; end=t; a=0; b=1;}
			data1.push_back(make_pair(start, a));
			data2.push_back(make_pair(end, b));
		}

		int ans1 = solve(data1);
		int ans2 = solve(data2);

		fprintf(fout, "Case #%d: %d %d\n", test+1, ans1, ans2);
	}

	return 0;
}
