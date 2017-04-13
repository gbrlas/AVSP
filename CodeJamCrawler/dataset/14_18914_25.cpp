#include <iostream>
#include <cstring>
using namespace std;

int card[17];

void solve()
{
	int k, t;
	memset(card, 0, sizeof(card));
	cin >> k;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> t;
			if(k == i + 1) card[t]++;
		}
	}
	cin >> k;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> t;
			if(k == i + 1) card[t]++;
		}
	}
	int p = -1;
	for(int i = 1; i <=16; i++) {
		if(card[i] == 2) {
			if(p == -1) p = i;
			else {
				cout << "Bad magician!" << endl;
				return ;
			}
		}
	}
	if(p == -1) {
		cout << "Volunteer cheated!" << endl;
	} else {
		cout << p << endl;
	}
}

int main()
{
	int T, N = 1;
	cin >> T;
	while(T--) {
		cout << "Case #" << N++ << ": ";
		solve();
	}
	return 0;
}

