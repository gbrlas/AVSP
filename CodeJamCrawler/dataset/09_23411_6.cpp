//	for Google code jam
//	lang: C++
//	author: millky
//	2009/9/27

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

long long stdVector[40];
int n;
void init() {
	stdVector[0] = 0;
	stdVector[1] = 1;
	for (int i = 2, j = 1; i < 40; ++i, ++j) {
		stdVector[i] = (1 << j);
		stdVector[i] |= stdVector[i-1];
	}
}
set<vector<long long> > sets;
vector<long long> cmp;
struct Node {
	vector<long long> data;
	int step;
	bool check();
};
queue<Node> q;
bool Node::check() {
	for (int i = 0; i < data.size(); ++i) {
		if (data[i] & cmp[i]) return false;
	}
	return true;
}

void buildStd(int n) {
	cmp.clear();
	for (int i = n-1; i > -1; --i) {
		cmp.push_back(stdVector[i]);
	}
}

//int bfs(Node node) {
//	while (!q.empty()) q.pop();
//	q.push(node);
//	sets.insert(q.front().data);
//	int step = 0;
//	while (!q.empty()) {
//		Node temp = q.front();
//		q.pop();
//		step = temp.step;
//		if (temp.check()) break;
//		vector<long long> vi = temp.data;
//		for (int i = 0; i < n - 1; ++i) {
//			int j = i + 1;
//			if (i != j) {
//				swap(vi[i], vi[j]);
//				if (sets.find(vi) == sets.end()) {
//					Node tn;
//					tn.step = step + 1;
//					tn.data = vi;
//					q.push(tn);
//				}
//				swap(vi[i], vi[j]);
//			}
//		}
//	}
//	return step;
//}
int bfs(Node node) {
	while (!node.check()) {
		for (int i = 0, j; i < n; ++i) {
			if (node.data[i] & cmp[i]) {
				for (j = i+1; j < n; ++j) {
					if ((node.data[j]&cmp[i]) == 0) break;
				}
				node.step += j - i;
				long long temp = node.data[j];
				for (int k = j; k > i; --k) {
					node.data[k] = node.data[k-1];
				}
				node.data[i] = temp;
				break;
			}
		}
	}
	return node.step;
}
long long covert(char* buf) {
	long long res = 0LL;
	for (int i = 0; buf[i]; ++i) {
		res <<= 1;
		res |= (buf[i] - '0');
	}
	return res;
}
int main() {
	freopen("C:\\Documents and Settings\\Simon Lee\\×ÀÃæ\\GCJ_Codes\\A-small.in", "r", stdin);
	freopen("C:\\Documents and Settings\\Simon Lee\\×ÀÃæ\\GCJ_Codes\\A-small.out", "w", stdout);
	init();
	int nCase;
	long long temp;
	char buf[64];
	scanf("%d", &nCase);
	for (int cnt = 1; cnt <= nCase; ++cnt) {
		scanf("%d", &n);
		vector<long long> vi;
		for (int i = 0;i< n; ++i) {
			scanf("%s",buf);
			temp = covert(buf);
			vi.push_back(temp);
		}
		Node node;
		node.data = vi;
		node.step = 0;
		buildStd(n);
		printf("Case #%d: %d\n", cnt,bfs(node));
	}
	return 0;
}
