#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int N, total;
string welcome = "welcome to code jam";
string test;

void testar(int pw, int pt) {
	if(pt > (int) test.size()) return;

	if((int) test.size() - pt < (int) welcome.size() - pw) return;

	if(pw == (int) welcome.size()){
		total = (total + 1) % 10000;
		return;
	}

	for (int i = pt; i < (int) test.size(); i++) {
		if (test[i] == welcome[pw]) {
			testar(pw+1, i+1);
		}
	}
}

int main() {
	cin >> N;
	getline(cin, test);

	for (int i = 1; i <= N; ++i) {
		getline(cin, test);

		total = 0;
		if (test.size() >= welcome.size()) {
			testar(0, 0);
		}

		printf("Case #%d: %04d\n", i, total % 10000);
	}
	return (0);
}
