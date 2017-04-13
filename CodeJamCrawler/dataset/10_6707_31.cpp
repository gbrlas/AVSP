#include <iostream>

using namespace std;

int R[4000];
int C[4000];
int f_m[4000][15];
int P;

const int INF = int(1e9);

int f(int v, int r) {
	//cout << "R: " << v << " " << r << " " << f_m[v][r] << endl;
	if (f_m[v][r] == -1) {
		if (v >= (1 << P)) {			
			if (r >= R[v - (1 << P)])
				f_m[v][r] = 0;
			else
				f_m[v][r] = INF;
		//	cout << "VVV: " << v << " " << r << " " << f_m[v][r] << endl;
		} else {
			f_m[v][r] = INF;
			for (int left = 0; left <= r+1; ++left)
				for (int right = 0; right <= r+1; ++right)
					f_m[v][r] = min(f_m[v][r], f(2*v, left) + f(2*v+1, right) + C[v]);
			for (int left = 0; left <= r; ++left)
				for (int right = 0; right <= r; ++right)
					f_m[v][r] = min(f_m[v][r], f(2*v, left) + f(2*v+1, right));
		}
		//cout << v << " " << r << " " << f_m[v][r] << endl;
	}	
	return f_m[v][r];
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {		
		cin >> P;		
		for (int i = 0; i < (1 << P); ++i) {
			cin >> R[i];
			R[i] = P - R[i];
		}

		for (int i = P-1; i >= 0; --i) {
			for (int j = 0; j < (1 << i); ++j)
				cin >> C[(1 << i) + j];
		}

		/*for (int i = 0; i < (1 << P); ++i)
			cout << C[i] << " ";
		cout << endl;*/

		for (int i = 0; i <= (1 << (P+1)); ++i)
			for (int j = 0; j <= P; ++j)
				f_m[i][j] = -1;
			
		cout << "Case #" << t + 1 << ": " << f(1,0) << endl;
	}
}
