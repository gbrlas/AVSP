#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t=0;t<T;t++) {
		unsigned int N, K;
		cin >> N >> K;
		unsigned int expect = (1<<N)-1;
		cout << "Case #" << (t+1) << ": ";
		if (((K+1)&expect) == 0) cout << "ON";
		else cout << "OFF";
		cout << endl;
	}
}

