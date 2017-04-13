#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define FILE_IN  "A-small-attempt1.in"
#define FILE_OUT "A-small-attempt1.out"

typedef set<string> ss;

struct node {
	double w;
	string attr;
	node *left, *right;
	node(double w): w(w), attr(""), left(NULL), right(NULL) {}
	~node() { delete left; delete right; }
};

char buf[15];

node *read() {
	double w;
	if (scanf(" (%lf", &w) != 1)
		return NULL;
	node *n = new node(w);
	int t = 0;
	scanf(" ");
	scanf(")%n", &t);
	if (t != 1) {
		scanf("%s", buf);
		n->attr = buf;
		n->left = read();
		n->right = read();
		scanf(" )");
	}
	return n;
}

void print(node *n) {
	if (n == NULL) {
		printf("[]");
		return;
	}
	printf("(%lf", n->w);
	if (n->attr != "") {
		printf(" %s\n", n->attr.c_str());
		print(n->left);
		print(n->right);
	}
	printf(")\n");
}

double getScore(node *n, const ss& attrs) {
	double score = n->w;
	if (n->attr != "") {
		if (attrs.count(n->attr))
			score *= getScore(n->left, attrs);
		else
			score *= getScore(n->right, attrs);
	}
	return score;
}

void solve() {
	scanf(" %*d");
	node *n = read();
	int a;
	scanf(" %d", &a);
	for (int i = 0; i < a; ++i) {
		string name;
		int k;
		scanf(" %s %d", buf, &k);
		name = buf;
		ss attrs;
		for (int j = 0; j < k; ++j) {
			scanf(" %s", buf);
			attrs.insert(buf);
		}
		double score = getScore(n, attrs);
		printf("%.7lf\n", score);
	}
	delete n;
	fflush(stdout);
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d:\n", i);
		solve();
	}
	return 0;
}
