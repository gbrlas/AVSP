#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

char welcome[] = "welcome to code jam";

int dp[512][20];

int main()
{
	FILE* fin = fopen("in.txt", "r");
	FILE* fout = fopen("out.txt", "w");

	int N;
	char num[16];
	fgets(num, 16, fin);
	sscanf(num, "%d", &N);
	// fscanf(fin, "%d", &N);
	for(int test = 1; test <= N; ++test)
	{
		memset(dp, 0, sizeof(dp));
		char str[1024];
		fgets(str, 1024, fin);
		// fscanf(fin, "%s", str);
		int len = strlen(str);
		for(int i = len - 1; i >= 0; i--)
		{
			if(i != len - 1)
				for(int j = 0; j < 19; ++j)
					dp[i][j] = dp[i + 1][j];
			if(str[i] == welcome[18])
				dp[i][18] = (dp[i][18] + 1) % 10000;
			for(int j = 17; j >= 0; j--)
			{
				if(str[i] == welcome[j])
				{
					dp[i][j] = (dp[i][j] + dp[i + 1][j + 1]) % 10000;
				}
			}
		}
		fprintf(fout, "Case #%d: %.4d\n", test, dp[0][0]);
	}

	return 0;
}