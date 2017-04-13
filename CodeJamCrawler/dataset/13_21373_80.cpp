#include <iostream>
using namespace std;
int main() {
	int r;
	cin >> r;
	for (int k = 1; k <= r; k++) {
		int n,m;
		cin >> n >> m;
		int * a = new int[n*m];
		int * rows = new int[n];
		int * cols = new int[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i*m+j];
		for (int i = 0; i < n; i++) rows[i]=0;
		for (int j = 0; j < m; j++) cols[j]=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (rows[i] < a[i*m+j]) rows[i] = a[i*m+j];
				if (cols[j] < a[i*m+j]) cols[j] = a[i*m+j];
			}
		}
		bool possible=true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i*m+j] < rows[i] && a[i*m+j] < cols[j])
					possible = false;
			}
		}
		if (possible) cout << "Case #" << k << ": YES" << endl;
		else cout << "Case #" << k << ": NO" << endl;
		delete[] a;
		delete[] rows;
		delete[] cols;
	}
	return 0;
}
