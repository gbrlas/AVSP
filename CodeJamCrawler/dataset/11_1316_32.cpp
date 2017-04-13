#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t;
	cin>>t;
	for (int tt = 1; tt <= t; ++tt) {
		int r, c;
		cin>>r>>c;
		vector< string > v(r);
		for (int i = 0; i < r; ++i) {
			cin>>v[i];
		}
		bool fl = true;
		for (int i = 0; (i < r) && fl; ++i) {
			for (int j = 0; (j < c) && fl; ++j) {
				if (v[i][j] == '#') {
					if (((i + 1) == r) || ((j + 1) == c)) {
						fl = false;
					} else {
						if ((v[i + 1][j] == '#') && (v[i][j + 1] == '#') && (v[i + 1][j + 1] == '#')) {
							v[i][j] = v[i + 1][j + 1] = '/';
							v[i + 1][j] = v[i][j + 1] = '\\';
						} else {
							fl = false;
						}
					}
				}
			}
		}
		cout<<"Case #"<<tt<<":"<<endl;
		if (fl) {
			for (int i = 0; i < r; ++i) {
				cout<<v[i]<<endl;
			}
		} else {
			cout<<"Impossible"<<endl;
		}
	}
	return 0;
}
