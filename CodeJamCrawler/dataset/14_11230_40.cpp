#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long int in;
typedef pair<in,in> PI;
typedef vector<in> VI;
typedef vector<PI> VPI;

void testcase() {
	in N; cin>> N;
	in X; cin >> X;

	VI V;
	for(in i=0; i<N; i++) {
		in a;
		cin >> a;
		V.PB(-a);
	}
	sort(V.begin(), V.end());
	for(in i=0; i<N; i++) V[i] = -V[i];
	vector<bool> used(N,false);
	in l,r;
	in cost = 0;
	for(l=0; l<N; l++) {
		if(used[l]) continue;
		r=l+1;
		while(r<N && (used[r] || (V[l]+V[r]>X))) r++;
		cost++;
		used[l] = true;
		// cout << V[l] << endl;
		if(r<N) {
			// cout << " and " << V[r] << endl;
			used[r] = true;
		}
	}
	cout << cost;
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