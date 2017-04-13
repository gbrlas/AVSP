#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

int dp[512][19];

int locate(char ch) {
	string str = "welcome to code jam";	
	for (int i = 0; i < str.length(); ++i)
		if (ch == str[i]) return i;
	return 0;
}

int main() {
	//freopen("E:\\Ëã·¨\\GCJ\\09qual\\B-large.in", "r", stdin);
	//freopen("E:\\Ëã·¨\\GCJ\\09qual\\B-large.out", "w", stdout);
	int n = 0;
	char buf[512];
	string str = "welcome to code jam";	
	//fgets(buf, 512, stdin);
	gets(buf);
	n = atoi(buf);

	for (int cnt = 0; cnt < n; ++cnt) {
//		fgets(buf, 512, stdin);
		gets(buf);
		int res = 0, len = strlen(buf);
		memset(dp, 0 ,sizeof dp);

		for (int i = 0; i < len; ++i)
			if (buf[i] == 'w') dp[i][0] = 1;
		for (int i = 0; i < len; ++i) {
			int pos = 0;
			for (int j = 0; j < str.length(); ++j) {
				if (str[j] == buf[i]) {
					pos = j;
					break;
				}
			}
			while (pos) {
				int j;
				char ch = str[pos - 1];
				int temp = 0;
				for (j = 0; j < i; ++j)
					if (buf[j] == ch) {
						temp += dp[j][pos-1];
						temp %= 10000;		
					}
				dp[i][pos] = temp;
				for (j = pos + 1; j < str.length(); ++j) {
					if (str[j] == buf[i]) {
						pos = j;
						break;
					}
				}
				if (j == str.length()) pos = 0;
			}
		}

		for (int i = len - 1; i > -1; --i)
			if (buf[i] == 'm') {
				res = dp[i][18];
				break;
			}
		cout << "Case #"<< cnt << ": ";
		cout << setfill('0') << setw(4) << res << endl;
	}

	return 0;
}
