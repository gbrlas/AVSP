#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <sstream>
#include <set>
using namespace std;



struct BTree {
	string lbl;
	double w;

	BTree* a;
	BTree* b;
	BTree() {
		a = b = 0;
		w = 0;
		lbl = "";
	}
};

map<string, int> m;

string all;

BTree* make_tree(const int start, const int end) {
	BTree *tree  = new  BTree();
	string x = all.substr(start, end - start);
	stringstream ss = stringstream(x);
	char ch;
	double w;
	string f;
	ss >> ch >> w >> f;
	tree->w = w;
	if(f[0] == ')') { // leaf
		tree->lbl = "";
		return tree;
	}
	tree->lbl = f;
	int a = x.find_first_of(f);
	int o = 0, mode = 0;
	int o_st = a + f.length();
	while(true) {
		int x1 = x.find_first_of("(", a);
		int x2 = x.find_first_of(")", a);
		int y;
		if(x1 != string::npos && x2 != string::npos) {
			y = min(x1, x2);
			if( y == x1) o++; else o--;
		}
		else if(x1 != string::npos && x2 == string::npos) { y = x1; o++; }
		else if (x1 == string::npos && x2 != string::npos) { y = x2; o--; }
		else break;
		if(o == 0 && mode == 0) {
			tree->a = make_tree(start + o_st, start + y + 1);
			o_st = y + 1;
			mode++;
		} else if (o == 0 && mode == 1) {
			tree->b = make_tree(start + o_st, start + y + 1);
			break;
		}
		a = y + 1;
	}
	return tree;
}

set<string> features;

double func(double v, BTree* b) {
	if(!b) return v;

	double res = v * b->w;
	if(features.find(b->lbl) != features.end())  return func(res, b->a); else return func(res, b->b);
}

char line[245];
int main() {
	freopen("A.in", "rt", stdin);
	freopen("A.out", "wt", stdout);
	int test;
	cin >> test;
	for(int T = 1; T <= test; T++) {
		cout << "Case #" << T << ":" << endl;
		m.clear();
		int l;
		cin >> l;
		string x;
		all = "";
		cin.get();
		while(l--) { 
			cin.getline(line, sizeof(line)); 
			all += string(line); 
		}
		BTree *tree = make_tree(0, all.length());
		int ccc;
		cin >> ccc;
		while(ccc--) {
			string animal;
			cin >> animal;
			features.clear();
			int f;
			cin >> f;
			string ff;
			while(f--) { cin >> ff; features.insert(ff); }
			printf("%.7f\n", func(1, tree));
		}
	}
	return 0;
}