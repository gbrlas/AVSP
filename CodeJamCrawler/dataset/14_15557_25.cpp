#include <iostream>
using namespace std;

int main(int, char**){
	int T, X, m, k;
	double f, x, c, t;
	cout.precision(7);
	cin >> T;
	for(X = 1; X <= T; X++){
		cin >> c >> f >> x;
		if(x <= c){
			t = x / 2.0;
		}else{
			m = ((x - c) / c) - 2 / f + 1;
			t = 0;
			for(k = 1; k <= m; k++){
				t += c / ( 2 + (k - 1) * f);
			}
			t += x / (2 + m * f);
		}
		cout << "Case #" << X << ": " << fixed << t << endl;
	}
	return 0;
}