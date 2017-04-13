#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <iostream>

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)

using namespace std;

struct node {
	int x, y, h;
	
	node(int x, int y, int h): x(x), y(y), h(h) {}
	
	friend bool operator<(const node &a, const node &b) {
		return a.h > b.h;
	}
};

bool comp(const node *a, const node *b) {
	if(a->y != b->y)
		return a->y < b->y;
	return a->x < b->x;
}

int H, W;
vector <node> all;
vector <vector <int> > board;
vector <vector <vector <node*> > > ne;
const int move[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t) {
		scanf("%d%d", &H, &W);
		all.clear();
		board.clear();
		ne.clear();
		board.resize(H + 2);
		ne.resize(H + 2);
		foreach(i, 0, board) {
			board[i].resize(W + 2, 1000000);
			ne[i].resize(W + 2, vector <node*>());
			if(i == 0 || i == H + 1)
				continue;
			foreach(j, 2, board[i]) {
				scanf("%d", &board[i][j - 1]);
				all.push_back(node(j - 1, i, board[i][j - 1]));
			}
		}
		sort(all.begin(), all.end());
		vector <node*> sink;
		foreach(i, 0, all) {
			int lowest = 1000001;
			for(int j = 0; j < 4; ++j)
				if(board[all[i].y + move[j][0]][all[i].x + move[j][1]] < all[i].h)
					lowest = min(lowest, board[all[i].y + move[j][0]][all[i].x + move[j][1]]);
			for(int j = 0; j < 4; ++j)
				if(lowest == board[all[i].y + move[j][0]][all[i].x + move[j][1]]) {
					ne[all[i].y + move[j][0]][all[i].x + move[j][1]].push_back(&all[i]);
					goto good;
				}
			sink.push_back(&all[i]);
			good:;
		}
		sort(sink.begin(), sink.end(), comp);
		vector <pair <pair <int, int>, int> > vv(sink.size(), pair <pair <int, int>, int>(make_pair(1000000, 1000000), -1));
		foreach(i, 0, sink) {
			queue <node*> Q;
			Q.push(sink[i]);
			while(!Q.empty()) {
				node *aa = Q.front();
				board[aa->y][aa->x] = i;
				if(make_pair(aa->y, aa->x) < vv[i].first)
					vv[i] = make_pair(make_pair(aa->y, aa->x), i);
				Q.pop();
				foreach(j, 0, ne[aa->y][aa->x])
					Q.push(ne[aa->y][aa->x][j]);
			}
		}
		sort(vv.begin(), vv.end());
		vector <int> where(vv.size());
		foreach(i, 0, vv)
			where[vv[i].second] = i;
		printf("Case #%d:\n", t + 1);
		for(int y = 1; y <= H; ++y) {
			for(int x = 1; x <= W; ++x) {
				printf("%c", 'a' + where[board[y][x]]);
				if(x != W)
					printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
