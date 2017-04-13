// Author: Osvald Ivarsson

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); \
		it != (v).end(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<char, char> pcc;

bool solve( int tc ) {
	map<pair<char,char>, char> combine;
	map<char, vector< char> > opposed;
	int c;
	cin >> c;
	pcc temp;
	for(int i = 0; i < c; i++) {
		string comb;
		char a,b,c;
		//cout << a << b << c << endl;
		cin >> comb;
		a = comb[0];
		b = comb[1];
		c = comb[2];	
		temp.first = min(a, b);
		temp.second = max(a, b);	
		combine[temp] = c;
	}
	int d;
	cin >> d;
	for(int i = 0; i < d; i++) {
		string opp;
		cin >> opp;
		char a, b;
		a = opp[0];
		b = opp[1];
		if(opposed.count(a)) {
			opposed[a].push_back(b);
		}
		else {
			vector<char> tempv;
			tempv.push_back(b);
			opposed[a] = tempv;
		}

		if(opposed.count(b)) {
			opposed[b].push_back(a);
		}
		else {
			vector<char> tempv;
			tempv.push_back(a);
			opposed[b] = tempv;
		}
	}
	int n;
	cin >> n;
	string elements;
	cin >> elements;
	string out;
	for(int i = 0; i < elements.size(); i++) {
		out += elements[i];	
		if(out.size() < 2) continue;
		char a = out[out.size()-2]; // second last
		char b = out[out.size()-1]; // last
		pcc temp;
		temp.first = min(a,b);
		temp.second = max(a,b);	
		if(combine.count(temp)) {
			out[out.size()-2] = combine[temp];
			out.erase(out.begin()+out.size()-1);	
		}
		else {
			for(int f = 0; f < out.size(); f++) {
				if(opposed.count(out[f])) {
					for(int m = 0; m < opposed[out[f]].size(); m++) {
						if(opposed[out[f]][m] == b) {
							out.clear();
						}
					}	
				}
			}
		}
		
	}

	cout << "Case #" << tc+1 << ": [";
	for(int i = 0; i < out.size(); i++) {
		cout << out[i];
		if(i != out.size()-1) {
			cout << ", ";
		}
	}
	cout << "]" << endl;

	return true;
}

int main() {
	int n;
	cin >> n;
	for( int i = 0; i < n && solve( i ); ++i );
	return 0;
}
