#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

int main() {
	ifstream in("B.in");
	ofstream out("B.out");
	
	int tests;
	in >> tests;
	for (int i=1; i<=tests; i++) {
		string num;
		in >> num;

		int prev = -1;
		vector<int> digits(10, 0);
		bool done = false;
		for (int j=num.length() - 1; j >=0; j--) {
			digits[num[j] - '0']++;

			if (num[j] - '0' >= prev) {
				prev = num[j] - '0';
			}
			else {
				int lower = num[j] - '0';
				for (int k=lower + 1; k < 10; k++) {
					if (digits[k] > 0) {
						num = num.substr(0, j) + (char)(k + '0');
						digits[k]--;
						break;
					}
				}
				done = true;
				break;
			}
		}

		if (!done) {
			digits[0]++;
			for (int j=1; j<10; j++)
				if (digits[j]) {
					digits[j]--;
					num = string("") + (char)(j + '0');
					break;
				}
		}
		out << "Case #" << i << ": " << num;
		for (int j=0; j<10; j++)
			for (int k=0; k<digits[j]; k++)
				out << j;
		out << endl;
	}
}
