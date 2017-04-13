#include <iostream>
#include <vector>

using namespace std;

int getResult(int test) {
	int n,m;
	cin>>m>>n;

	vector <int> v;
	vector <vector <int> > a;

	int x;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin>>x;
			v.push_back(x);
		}
		a.push_back(v);
		v.clear();
	}
	
	cout<<"Case #"<<test<<": ";

	for (int i = 0; i < m; i++) {
		bool flag1 = true, flag2 = true;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 2) continue;
			for (int k = 0; k < n; k++) {
				if (a[i][k] == 2) {
					flag1 = false;
					break;
				}
			}
			for (int k = 0; k < m; k++) {
				if (a[k][j] == 2) {
					flag2 = false;
					break;
				}
			}
			if (!flag1 && !flag2) {
				cout<<"NO"<<endl;return 0;
			}
		}
	}
	cout<<"YES"<<endl;

	return 0;
}

int main () {
	int test;
	cin>>test;
	
	for (int i = 1; i <= test; i++) {
		getResult(i);
	}
	
	return 0;
}
			
