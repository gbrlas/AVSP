#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#define N 200

ifstream input;
ofstream output;

bool f[27][27];
int a[27][27];

int main()
{
	char s[N], ans[N];
	int t, i, j, n, k, l;
	input.open("B-large.in");
	output.open("B-large.out");

	input >> t;
	for (i = 1; i <= t; i++)
	{
		memset(a, 0, sizeof(a));
		memset(f, 0, sizeof(f));
		input >> n;
		for (j = 0; j < n; j++)
		{
			input >> s;
			a[s[0]-'A'+1][s[1]-'A'+1] = s[2]-'A'+1;
			a[s[1]-'A'+1][s[0]-'A'+1] = s[2]-'A'+1;
		}
		input >> n;
		for (j = 0; j < n; j++)
		{
			input >> s;
			f[s[0]-'A'+1][s[1]-'A'+1] = true;
			f[s[1]-'A'+1][s[0]-'A'+1] = true;
		}
		input >> n >> s;
		k = 0;
		for (j = 0; j < n; j++)
		{
			ans[k++] = s[j];
			if (k == 1)
				continue;
			if ( a[ans[k-1]-'A'+1][ans[k-2]-'A'+1] != 0 )
			{
				ans[k-2] = a[ans[k-1]-'A'+1][ans[k-2]-'A'+1] + 'A' - 1;
				k--;
			}
			if ( k > 1 )
				for (l = k-2; l >= 0; l--)
					if ( f[ans[l]-'A'+1][ans[k-1]-'A'+1] )
					{
						k = 0;
						break;
					}
		}
		output << "Case #" << i << ": [";
		for (j = 0; j < k - 1; j++)
			output << ans[j] << ", ";
		if ( k > 0 )
			output << ans[k-1];
		output << "]" << endl;
	}
	input.close();
	output.close();
	return 0;
}
			
			