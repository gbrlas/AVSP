#include <iostream>
#include <cstdio>
#include <string>
int p;
int n, s, T;
int counter;
#define N 101

int t[N];
int spr[N];
int Nspr[N];
bool isUsed[N];

using namespace std;
int main() {
	int tmp;
	freopen("D://B-large.in", "r", stdin);
	freopen("D://B-large.out", "w", stdout);
	cin >> T;

	for(int j = 0; j < T; ++j) {
		cin >> n >> s >> p;
		for(int i = 0; i < n; ++i) {
			isUsed[i] = false;
		}
		counter = 0;
	
		for(int i = 0; i < n; ++i) {
			cin >> t[i];
			if(t[i] == 0) {
				Nspr[i] = spr[i] = 0;
				continue;
			}
			tmp = t[i] / 3;
			switch (t[i] % 3) {
			case 0: 
				Nspr[i] = tmp;
				spr[i] = tmp+1;
				break;
			case 1: 
				spr[i] = Nspr[i] = tmp+1;
				break;
			case 2:
				spr[i] = tmp + 2;
				Nspr[i] = tmp + 1;
				break;
			}
		}

		/*for(int i = 0; i < n; ++i) {
			cout << t[i] << "\t" << spr[i] << "\t" << Nspr[i] << endl;
		}*/

		for(int i = 0; i < n; ++i) {
			if(Nspr[i] >= p) {
				counter++;
				isUsed[i] = true;
			}
		}

		for(int i = 0; i < n; ++i) {
			if(s == 0)
				break;
			if(!isUsed[i]) {
				if(spr[i] >= p) {
					counter++;
					isUsed[i] = true;
					s--;
				}
			}
		}

		cout << "Case #" << j+1 << ": " << counter << endl;
	}
	

	return 0;
}