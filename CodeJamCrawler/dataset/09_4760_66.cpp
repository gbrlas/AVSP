#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	char buf[1024];
	ifstream in;
	ofstream out;
	in.open("C-small-attempt0.in");
	out.open("C.txt");
	in.getline(buf, 1024, '\n');
	int n = atoi(buf);

	FILE *output;
	output=fopen("C.txt", "wt");

	char *str = "welcome to code jam";

	for(int a = 1; a <= n; a++ )
	{
		int dp[19][1024];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 0;
		in.getline(buf, 1024, '\n');

		for( int i = 0; i < 19; i++ )
			for( int j = 0; j < strlen(buf); j++ )
			{
				if( str[i] == buf[j] ) 
				{
					if( i == 0 ) 
					{
						if( j == 0 ) dp[i][j] = 1;
						else dp[i][j] = (dp[i][j-1] + 1)%10000;
					}
					else 
					{
						if( j == 0 ) dp[i][j] = dp[i-1][j];
						else dp[i][j] = (dp[i][j-1] + dp[i-1][j])%10000;
					}
				}
				else 
				{
					if( j == 0 ) dp[i][j] = 0;
					else dp[i][j] = dp[i][j-1]; 
				}
			}
		fprintf(output, "Case #%d: %04d\n", a, dp[18][strlen(buf)-1]);
		printf("Case #%d: %04d\n", a, dp[18][strlen(buf)-1]);
	}
	return 0;
}