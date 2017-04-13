#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>

#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <list>

#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) a.size() - 1
#define all(a) a.begin(), a.end()
#define I (int)
#define I64 (int64)
#define LD (long double)
#define VI vector<int>

const long double EPS = 1E-9;
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double PI = 2 * acos(.0);

struct node {
	long double z;
	string value;
	node * l, * r;
};

node * root;
set<string> st;
char buf[100100];

string s;

void parsing(node * &root, int l, int r){
	while (s[l] != '(') l++;
	while (s[r] != ')') r--;

	string t = "";
	for(int i = l + 1; i <= r; i++)
		if (s[i] == ')' || s[i] == '(') break;
		else t += s[i];

	stringstream st;
	st << t;
	long double z;
	st >> z;

	root = new node();
	root->z = z;
	root->l = root->r = 0;
	if (!(st >> t)) return;
	root->value = t;

	int h = 0, p = -1;
	for(int i = l + 1; i < r; i++){
		if (s[i] == '('){
			h++;
			if (p == -1) p = i;
		}

		if (s[i] == ')') {
			h--;
			if (h == 0){
				parsing(root->l, p, i);
				parsing(root->r, i + 1, r - 1);
				return;
			}
		}
	}
}

inline void readData(){
	int l;
	scanf("%d\n", &l);
	forn(i, l){
		gets(buf);
		s += buf;
	}
}

long double getAnswer(node * root, long double t){
	long double ans = t * root->z;
	if (root->l == 0 && root->r == 0) return ans;

	if (st.count(root->value))
		return getAnswer(root->l, ans);
	else
		return getAnswer(root->r, ans);
}

inline void writeData(){
	int m;
	scanf("%d\n", &m);
	forn(i, m){
		gets(buf);
		stringstream St;
		St << buf;
		string t;
		St >> t;
		St >> t;

		st.clear();
		while (St >> t) st.insert(t);
		printf("%.7lf\n", getAnswer(root, 1.0));
	}

}

inline void init(){
	s = "";
}

void solve(){
	init();
	readData();

	parsing(root, 0, (int) s.size() - 1);

	writeData();
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tests;
	scanf("%d", &tests);
	forn(test, tests){
		printf("Case #%d:\n", test + 1);
		solve();
	}
	
	return 0;
}