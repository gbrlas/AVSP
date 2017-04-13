#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;

int T;
int A, B;
bool digitsN[10];
bool digitsM[10];

int sumDigits(int num) {
	int sum = 0;
	
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}
	
	return sum;
}

int checkRecycled(string strn, string strm) {
	int num = 0;
	int len = (int)strn.size();
	int count;
	
	
	for (int I = 0; I < 10; ++I) {
		if (digitsN[I] != digitsM[I]) return 0;
	}
	
	for (int I = 0; I < len; ++I) {
		count = 0;
		for (int J = I; count < len; J = (J+1) % len, ++count) {
			if (strn[count] != strm[J]) break;
		}
		if (count == len) return 1;
	}
	
	return num;
}

void digits(int num, bool a[]) {
	int digit;
	while (num > 0) {
		digit = num % 10;
		a[digit] = true;
		num /= 10;
	}
}

int main(int argc, char *argv[]) {
	int I;
	int n, m;
	int numRecycled;
	int sumDigitsN;
	string strn, strm;
	stringstream ss;
	
	scanf("%d", &T);
	for (I = 1; I <= T; ++I) {
		scanf("%d %d", &A, &B);
		numRecycled = 0;
		
		for (n = A; n < B; ++n) {
			memset(digitsN, 0, sizeof(bool) * 10);
			digits(n, digitsN);
			sumDigitsN = sumDigits(n);
			ss.str("");
			ss << n;
			strn = ss.str();
			for (m = B; n != m; --m) {
				if (sumDigitsN == sumDigits(m)) {
					memset(digitsM, 0, sizeof(bool) * 10);
					digits(m, digitsM);
					ss.str("");
					ss << m;
					strm = ss.str();
					numRecycled += checkRecycled(strn, strm);
				}
			}
		}
		printf("Case #%d: %d\n", I, numRecycled);
	}
	return 0;
}
