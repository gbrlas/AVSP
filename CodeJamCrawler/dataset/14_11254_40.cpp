#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long int in;
typedef pair<in,in> PI;
typedef vector<in> VI;
typedef vector<string> VS;
typedef vector<VS> VVS;


in N, M; // N servers, M strings

VVS D; // distribution
VS S;
in maxs, cnt;

void rec(in i) {
	if(i==M) { // all strings distributed -> build tries
		vector<set<string> > TR(N);
		for(in j=0; j<N; j++) {
			for(in k=0; k<D[j].size(); k++) {
				for(in l=0; l<=D[j][k].size(); l++) {
					// cout << "server " << j << " word " << k << " " << D[j][k] << " with substr: " << D[j][k].substr(0,l) << endl;
					TR[j].insert(D[j][k].substr(0,l));
				}
			}
		}
		in totalsize = 0; 
		for(in j=0; j<N; j++) totalsize += TR[j].size();
		if(totalsize > maxs) {
			maxs = totalsize;
			cnt = 0;
		}
		if(maxs == totalsize) {
			cnt++;
		}
		return;
	}
	for(in j=0; j<N; j++) { // try server
		D[j].PB(S[i]);
		rec(i+1);
		D[j].pop_back();
	}

}

void testcase() {
	D.clear();
	S.clear();
	cin>>M >> N;
	D.resize(N);
	S.resize(M);
	for(in i=0; i<M; i++) {
		cin >> S[i];
	}
	maxs = 0; cnt = 0;
	rec(0);
	cout << maxs << " " << cnt;
}

int main() {
	in T;
	cin >> T;
	for(int t=0; t<T; t++) {
		cout << "Case #" << t+1 << ": ";
		testcase();
		cout << endl;
	}
}