#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
int T;
cin >> T;
for(int i = 1; i<=T; i++) {
	int N;
	cin >> N;
	vector<double> n(N);
	vector<double> k(N);
	for(int j = 0; j<N; j++)
		cin >> n[j];
	for(int j = 0; j<N; j++)
		cin >> k[j];
	sort(n.begin(), n.end());
	sort(k.begin(), k.end());
	int ansdw =0, nw = 0, ndw = 0, kw = 0, kdw = 0, answ = N;
	while(kw != N) {
		if(k[kw] > n[nw]) {
			answ--;
			nw++;
		}
		kw++;
	}
	while(ndw != N) {
		if(n[ndw] > k[kdw]) {
			ansdw++;
			kdw++;
		}
		ndw++;
	}
	cout << "Case #" << i << ": " << ansdw << " " << answ << endl;
}
}