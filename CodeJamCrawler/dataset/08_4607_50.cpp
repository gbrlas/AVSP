#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int a, b, ns, nq, S, Q, TC, idx, ret;
	string assign;
	ifstream in;
	ofstream out;
	in.open("A-large.in");
	out.open("A-large.out");
//	in.open("A-small-attempt0.in");
//	out.open("A-small-attempt0.out");
	char str[1024];

	vector<string> search, query;
	vector<int>::iterator it;

	in.getline(str, 1024);
	TC = atoi(str);

	for( int i = 0; i < TC; i ++ ) {
		ret = 0;
		in.getline(str, 1024);
		S = atoi(str);

		for( a = 0; a < S; a++ ) {
			in.getline(str, 1024);
			search.push_back(str);
		}

		in.getline(str, 1024);
		Q = atoi(str);
		for( a = 0; a < Q; a++ ) {
			in.getline(str, 1024);
			query.push_back(str);
		}

		nq = query.size();
		ns = search.size();
		vector<int> chk(ns, -1); 
		idx = -1;

		for( a = 0; a < nq; a++ ) {
			for( b = 0; b < ns; b++ ) {
				if( search[b] == query[a] ) chk[b] = a, idx = b;
			}
			
			int cnt = 0;
			for( b = 0; b < ns; b++ ) {
				if( chk[b] != -1 ) cnt++;
			}

			if( cnt == search.size() ) {  // used all then swapping
				ret++;	
				assign = search[idx];

				chk.assign(chk.size(), -1);
				chk[idx] = a-1;
			}
		}
		cout << "Case #" << i+1 <<": " << ret << endl;
		out << "Case #" << i+1 <<": " << ret << endl;

		search.clear();
		query.clear();
		chk.clear();
	}
	return 0;
}
