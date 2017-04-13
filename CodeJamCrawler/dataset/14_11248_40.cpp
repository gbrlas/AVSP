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
	VI V;
	VPI A;
	for(in i=0; i<N; i++) {
		in a;
		cin >> a;
		V.PB(a);
		A.PB(MP(-a,i));
	}
	sort(A.begin(), A.end());
	vector<bool> used(N,false);
	in l,r,a;
	l = r = a = A[0].second;
	used[a] = true;
	in cost = 0;
	for(in i = 1; i<N; i++) {
		a = A[i].second;
		in lsum=0;
		for(in j=a; j>=l; j--) lsum += used[j];
		in rsum=0;
		for(in j=a; j<=r; j++) rsum += used[j];
		cost += min(lsum,rsum);
		l = min(l,a);
		r = max(r,a);
		used[a] = true;
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