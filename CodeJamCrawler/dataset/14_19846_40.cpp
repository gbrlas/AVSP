#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

struct trie {
	shared_ptr<trie> c[26];
	int size() {
		int sz = 1;
		for (int i = 0; i < 26; ++i) {
			if (c[i]) {
				sz += c[i]->size();
			}
		}
		return sz;
	}
};

void add(const char* c, trie* t) {
	if (*c == 0) {
		return;
	}
	int i = *c - 'A';
	if (!t->c[i]) {
		t->c[i].reset(new trie);
	}
	add(c + 1, t->c[i].get());
}

int m, n;
vector<string> s;
vector<int> where;
vector<int> cnt;
int total;
int num;

void rec(int i) {
	if (i == m) {
		for (int j = 0; j < n; ++j) {
			if (cnt[j] == 0) {
				return;
			}
		}
		vector<trie> t(n);
		for (int j = 0; j < m; ++j) {
			add(s[j].c_str(), &t[where[j]]);
		}
		int cur = 0;
		for (int j = 0; j < n; ++j) {
			cur += t[j].size();
		}
		if (cur > total) {
			total = cur;
			num = 1;
		} else if (cur == total) {
			++num;
		}
		return;
	}
	for (int j = 0; j < n; ++j) {
		where[i] = j;
		++cnt[j];
		rec(i + 1);
		--cnt[j];
	}
}

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		cin >> m >> n;
		s.resize(m);
		for (int i = 0; i < m; ++i) {
			cin >> s[i];
		}
		cnt.resize(n);
		where.resize(m);
		total = 0;
		num = 0;
		rec(0);
		cout << "Case #" << test << ": " << total << " " << num << endl;
	}
}
