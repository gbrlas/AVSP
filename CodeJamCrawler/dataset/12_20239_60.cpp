#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int maxn = 128;

int N,S,p;
int T[maxn];

void solve(int tcase) {
	int result = 0;
	int St = S;
	int x,y,z;
	x = y = z = 0;
	for (int i=0;i<N;i++) {
		if (T[i] % 3 == 0) {
			if (T[i] / 3 >= p) result++;
			else if ((T[i] / 3 + 1 >= p) && (St > 0) && (T[i] / 3 - 1 >= 0)) {
				result++;
				St--;
			}
		}
		else
		if (T[i] % 3 == 1) {
			if (T[i] / 3 + 1 >= p) result++;
		}
		else {
			if (T[i] / 3 + 1 >= p) {
				result++;
			} else 
			if ((T[i] / 3 + 2 >= p) && (St > 0)) {
				result++;
				St--;
			}
		}
	}
	
	cout << "Case #" << tcase << ": " << result << "\n";
}

int main() {
	int nT;
	cin >> nT;
	int tcase = 0;
	while (nT--) {
		cin >> N >> S >> p;
		memset(T,0,sizeof(T));
		for (int i=0;i<N;i++)
			cin >> T[i];
		solve(++tcase);
	}
}