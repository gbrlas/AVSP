#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

const int bufferN = 1000;

int main(){
    int testN;
    cin >> testN;

    for (int t = 1; t <= testN; ++t) {
	int sN, qN;
	string name;
	char buffer[bufferN];

	cin >> sN;

	// search engins.
	map<string, int> S;
	for (int i = 1; i <= sN; ++i) {
	    do {
        	    cin.getline(buffer, bufferN);
	    } while (strcmp(buffer, "") == 0);
	    name = string(buffer);
	    S[name] = i;
	    //cout << name << endl;
	}

	cin >> qN;

	// initial switch table.
	int switchN[sN + 1][qN + 1];
	for (int i = 1; i <= sN; ++i)
	    switchN[i][0] = 0;

	// query.
	int kth;
	for (int i = 1; i <= qN; ++i) {
	    do {
        	    cin.getline(buffer, bufferN);
	    } while (strcmp(buffer, "") == 0);
	    name = string(buffer);
	    kth = S[name];
	    //cout << name << " " << kth << endl;

	    // fill table.
	    for (int j = 1; j <= sN; ++j) {
		if (j == kth) switchN[j][i] = qN;
		else {
		    // without switch.
		    switchN[j][i] = switchN[j][i - 1];

		    // with switch.
		    for (int k = 1; k <= sN; ++k) {
			if (k == j) continue;
			else if (switchN[k][i - 1] + 1 < switchN[j][i]) {
			    switchN[j][i] = switchN[k][i - 1] + 1;
			}
		    }
		}
	    }
	}

	// find answer.
	int ans = qN;
	for (int i = 1; i <= sN; ++i)
	    if (switchN[i][qN] < ans) ans = switchN[i][qN];

	// output.
	// Case #1: 1
	cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
