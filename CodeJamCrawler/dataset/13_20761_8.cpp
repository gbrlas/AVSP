#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>

using namespace std;

ifstream fin("A-small-attempt1.in");
ofstream fout("A-small-attempt1.out");

//ifstream fin("input.txt");
//ofstream fout("output.txt");


const int maxn = 100013;

typedef long long ll;

string str;
int n;
int d[maxn];

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

/*
long long solve() {

	long long result  = 0LL;
	
	memset(d, 0, sizeof(d));

	if (!isVowel(str[0])) d[0] = 1;

	for (int i=1;i<str.length();i++) {
		if (!isVowel(str[i])) {
			d[i] = d[i-1] + 1;
			d[i-1] = 0;
		}
	}

	int N = 0;
	int a = 0;
	int b = 0;
	int p = 0;

	for (int i=0;i<str.length();i++) {
		if (d[i] != 0) {
			N = d[i];
			if (N == n) {

				a = i - N + 1 - p;

				b = str.length() - i - 1;

				result += ((ll) b + 1LL) * ((ll) a + 1LL);

				p = N - n + 1;
			
			} else
				if ( N > n) {
					a = i - N + 1 - p;

				b = str.length() - i - 1;

				result += ((ll) b + 1LL) * ((ll) N - (ll)n + (ll)a + 2LL);

				p = N - n + 1;
				}
		}
	}

	return result;
}*/

long long solve(int i) {

	if (i >= str.length()) return 0;
	
	int cnt = 0;
	int start = -1;
	int end = -1;

	for (int j=i;j<str.length();j++) {
		if (!isVowel(str[j])) {
			cnt++;
		} else {
			cnt = 0;
		}
		if (cnt >= n) {
			start = j - cnt + 1;
			end = j;
			break;
		}
	}

	if (start == -1) return 0;

	int a = start - i;
	int b = str.length() - end - 1;

	long long result = ((ll)a + 1LL) * ((ll)b + 1LL);

	result += solve(start + 1);

	return result;

}

int main() {

	int T;
	fin >> T;

	for (int t=1;t<=T;t++) {
		fin >> str >> n;
		fout << "Case #" << t << ": " << solve(0) << "\n";
	}

	fin.close();
	fout.close();

	return 0;

}