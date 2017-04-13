#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int T = 0;

	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w+", stdout);
	
	cin >> T;

	for (int cas = 1; cas <= T; cas++) {
		int N = 0;
		vector <double> alice;
		vector <double> bob;

		cin >> N;
		for (int i = 0; i < N; i++) {
			double t;
			cin >> t;
			alice.push_back(t);
		}

		for (int i = 0; i < N; i++) {
			double t;
			cin >> t;
			bob.push_back(t);
		}

		int normal = 0;
		int cheat = 0;

		sort(alice.begin(), alice.end());
		sort(bob.begin(), bob.end());

		reverse(alice.begin(), alice.end());
		reverse(bob.begin(), bob.end());

		int head = 0, tail = N - 1;
		for (int i = 0; i < N; i++) {
			if (alice[i] > bob[head]) {
				normal++;
				tail--;
			} else {
				head++;
			}
		}

		head = 0, tail = N - 1;
		for (int i = N - 1; i >= 0; i--) {
			if (alice[i] > bob[tail]) {
				cheat++;
				tail--;
			} else {
				head++;
			}
		}

		cout << "Case #" << cas << ": " << cheat << " " << normal << endl;
	}
    return 0;
}
