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
#include <cassert>

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)

using namespace std;

vector <string> want;

struct node {
	double weight;
	string *option;
	node *up, *down;
	
	node(stringstream &ss): option(0), up(0), down(0) {
		string s;
		ss >> s >> weight; //
		assert(s == "(");
		ss >> s;
		if(s != ")") {
			option = new string(s);
			up = new node(ss);
			down = new node(ss);
			ss >> s;
			assert(s == ")");
		}
	}

	~node() {
		delete option;
		delete up;
		delete down;
	}

	double find() const {
		if(option == 0)
			return weight;
		if(binary_search(want.begin(), want.end(), *option))
			return weight * up->find();
		return weight * down->find();
	}
};

int main() {
	int tests;
	cin >> tests;
	for(int t = 1; t <= tests; ++t) {
		int lines, animals;
		cin >> lines;
		string s, s2;
		for(int i = 0; i <= lines; ++i) {
			getline(cin, s);
			s2 += s;
			swap(s, s2);
			s2 = "";
			foreach(i, 0, s) {
				if(s[i] == '(')
					s2 += " ( ";
				else if(s[i] == ')')
					s2 += " ) ";
				else
					s2 += s[i];
			}
		}
		stringstream ss(s2);
		//cout << s2 << endl << endl << endl;
		node tree(ss);
		cin >> animals;
		getline(cin, s);
		printf("Case #%d:\n", t);
		for(int i = 0; i < animals; ++i) {
			int num;
			vector <string> tt;
			cin >> s >> num;
			for(int i = 0; i < num; ++i) {
				cin >> s;
				tt.push_back(s);
			}
			want = tt;
			sort(want.begin(), want.end());
			double result = tree.find();
			cout << result << endl;
		}
	}
	return 0;
}
