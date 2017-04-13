//============================================================================
// Name        : AlienLanguage.cpp
// Author      : Farhad Noorzay
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;

#define SZ(a) int((a).size())
#define PB push_back
#define ALL(c) (c).begin(),(c).end()
#define TR(c,it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++) //traverse
#define PRESENT(c,x) ((c).find(x) != (c).end()) //find in set/maps,etc
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end()) //find in vectors


set<string> data; //words in the language
int L, D, N;
vector < vector< pair<string, int> > >vs; //array holding options
int w = 0; //number of words in alien language that match the pattern
string yy;

void rec( int i) {
	bool exists = false;
	//cerr << "i = " << i << endl;
	if( i == 0) {
		yy = "";
	}

	//stop early if there is no match
	//if( i == 3 || i == 6 || i == 11  ) {
		TR(data, t ) {
			string ww = t->substr(0, i);
			if( yy.compare(ww) == 0 ) {
				exists = true;
				break;
			}
		}
		if(exists == false)
			return;
//	}

	if( i == L) {
		//cerr << "yy = " << yy << endl;

		if( PRESENT( data, yy) )
			w++;
		return;
	}

	vector< pair<string, int> > z = vs[i];
	//vector< pair<string, int> >::iterator it = z.begin();
	TR( z, it ) {
		if (it->second == 0) {
			string l = it->first;
			it->second = 1; //mark visited
			//cerr << "l = " << l << endl;

			yy = yy + l;
//			cerr << "yy = " << yy << endl;

			i++; //call rec on neighbors
			rec(i);
		}
		it->second = 0;
		yy = yy.substr(0, yy.length()-1);
		i--;
	}
}

int handlecase( string s) {
	vs.clear();

	//iterate through each letter
	for( unsigned int i = 0; i < s.length(); i++) {
		vector< pair<string, int> > x;
		if( s[i] == '(' ) {
			i++;
			while(s[i] != ')' ) {
				string n = s.substr(i,1);
				pair<string, int> p;
				p.first = n; p.second = 0;
				x.push_back(p);
				i++;
			}
			//string n = s.substr(start, length-1);
			//vs.push_back(n);
		} else {
			string n = s.substr(i,1);
			pair<string, int> p;
			p.first = n; p.second = 0;
			x.push_back(p);
		}
		vs.push_back(x);
	}
	w = 0;
	rec(0);

	return w;
}

int main() {

	freopen("A-small-attempt1.in.txt", "r", stdin);
	//freopen("test.txt", "r", stdin);

	freopen("A-small-attempt1.out.txt", "w", stdout);

	cin >> L;
	cin >> D;
	cin >> N;
	cerr << "L= " << L << " D= " << D << " N = " << N << endl;

	string s;
	getline(cin, s); //ignore empty line

	for( int i = 0; i < D; i++) {
		getline(cin, s);
		data.insert(s);
	}


	TR(data, it) {
			cerr << *it << endl;
	}

	for( int i=1; i<=N; i++ ) {
		getline(cin, s); //get first case
		cerr << "Handling case " << i << "-- " << s << endl;
		int  words = handlecase(s);
		cout << "Case #" << i << ": " << words << endl;
	}

	/*
	fclose(stdout);
	*/
	return 0;
}
