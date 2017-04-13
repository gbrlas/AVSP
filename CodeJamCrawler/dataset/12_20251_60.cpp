#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <set>

using namespace std;

int fromString(string a) {
	int result;
	stringstream ss;
	ss << a;
	ss >> result;
	ss.flush();
	return result;
}

string toString(int a) {
	string result;
	stringstream ss;
	ss << a;
	ss >> result;
	ss.flush();
	return result;
}

int pow10(int n) {
	int result = 1;
	for (int i=0;i<n;i++)
		result *= 10;
	return result;
}

int solve(int A, int B) {
	int result = 0;
	set<int> mt;
	for (int n=A;n<=B;n++) {
		/*
		string sN = toString(n);
		set<int> mt;
		for (int p=1;p<sN.length();p++) {
			string part1 = sN.substr(0,p);
			string part2 = sN.substr(p,sN.length()-p);
			if (part2[0] != '0') {
				int m = fromString(part2 + part1);
				if ((m > n) && (m <= B) && (mt.find(m) == mt.end())) {
					mt.insert(m);
					result++;
				}
			}
		}
		*/
		mt.clear();
		int part1 = n;
		int p1_10 = 0;//toString(n).length() - 1;
		int nt = n;
		while (nt > 0) {
			p1_10++;
			nt /= 10;
		}
		p1_10--;
		int p2_10 = 0;
		int part2 = 0;
		while (part1/10 > 0) {
			int tmp = part1 % 10;
			part1 /= 10;
			if (tmp != 0) {
				part2 = tmp * pow10(p2_10) + part2;
				//print part1, part2, part2 * 10 ** p1_10 + part1
				int m = part2 * pow10(p1_10) + part1;
				if ((m > n) and (m <= B)) {
					if (mt.find(m) == mt.end()) {
						result += 1;
						mt.insert(m);
					}
				}
			}
			p2_10 += 1;
			p1_10 -= 1;
		}
	}
	return result;
}

int main() {
	int T,c,A,B;
	cin >> T;
	c = 0;
	while (T--) {
		c++;
		cin >> A >> B;
		cout << "Case #" << c << ": " << solve(A,B) << "\n";
	}
}