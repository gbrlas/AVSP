#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

#define MXSZ 13

const int uglies[] = {2, 3, 5, 7};
int len;

struct residues {
	int r[4];
	residues() {r[0] = r[1] = r[2] = r[3] = 0;}
	residues(int one, int two, int thr, int four) {
		r[0] = one;
		r[1] = two;
		r[2] = thr;
		r[3] = four;
	}
	int& operator[](int i) {return r[i];}
	residues operator+(residues rs) {
		return residues(r[0] + rs.r[0] % uglies[0], r[1] + rs.r[1] % uglies[1], r[2] + rs.r[2] % uglies[2], r[3] + rs.r[3] % uglies[3]);
	}
	residues operator-(residues rs) {
		return residues(r[0] - rs.r[0] + uglies[0] % uglies[0], r[1] - rs.r[1] + uglies[1] % uglies[1], r[2] - rs.r[2] + uglies[2] % uglies[2], r[3] - rs.r[3] + uglies[3] % uglies[3]);
	}
	bool isugly() {
		return (!(r[0]%uglies[0] && r[1]%uglies[1] && r[2]%uglies[2] && r[3]%uglies[3]));
	}
} res[MXSZ][MXSZ];



long long stoll(const string& str, int b, int e) {
	long long ret = 0;
	for (int i = b; i <= e; i++) {
		ret *= 10;
		ret += str[i]-'0';
	}
	return ret;

}

long long cnt(int p, residues sum, bool frst) {
	if (p >= len) return sum.isugly();
	long long tot = 0;

	for (int i = p; i < len; i++) {
		tot += cnt(i+1, (sum + res[i][p]), false);
		if (!frst) tot += cnt(i+1, (sum - res[i][p]), false);
	}

	return tot;
}

int main() {
	int ncases;
	cin >> ncases;

	for (int n = 1; n <= ncases; n++) {
		cout << "Case #" << n << ": ";

		string num;
		cin >> num;
		len = num.size();
		//cout << endl << num << endl;

		for (int i = 0; i < len; i++) {
			for (int j = 0; j<=i; j++) {
				long long cur;
				cur = stoll(num, j, i);
				for (int k = 0; k < 4; k++) {
					res[i][j][k] = cur % uglies[k];
					//printf("[%d,%d]:%lld mod %d = %d\n",j,i,cur,uglies[k],res[i][j][k]);
				}
			}
		}

		long long result = 0;
		
		result += cnt(0, residues(), true);
		cout << result;
		cout << endl;
	}
	return 0;
}