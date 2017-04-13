#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cassert>

typedef long long int64;
typedef double real;

const int inf = 0x3f3f3f3f;

#define Eo(x) { std::cerr << #x << " = " << x << std::endl; }

using namespace std;

char msg[] = "welcome to code jam";

int dp[1 << 9][20];

char s[1 << 9];

int main(){
	int n;
	scanf("%d\n", &n);
	for (int _ = 0; _ < n; ++_){
		memset(dp, 0, sizeof(dp));
		gets(s);
		int len = strlen(s);
		dp[len][0] = 1;
		for (int i = len - 1; i >= 0; --i){
			for (int j = 0; j < 20; j++){
				dp[i][j] = dp[i + 1][j];
				if (j && s[i] == msg[19 - j])
					dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % 10000;
			}
		}
		printf("Case #%d: %04d\n", _ + 1, dp[0][19]);
	}
	return 0;
}
