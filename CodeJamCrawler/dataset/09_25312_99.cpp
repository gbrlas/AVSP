#include <sstream>
#include <fstream>
#include <string>
#include <memory>

using namespace std;

const string pat = "welcome to code jam";
int d[2000][20];
int n;
string s;

ifstream fin("c.in");
ofstream fout("c.out");

int main()
{
	fin >> n;
	getline(fin, s);
	int cases = 0;
	while (n --)
	{
		getline(fin, s);
		memset(d, 0, sizeof d);
		int l = s.length();
		for (int i=0; i<l; i++)
		{
			for (int j=0; j<pat.length(); j++)
			{
				if (j == 0)
				{
					if (s[i] == pat[j]) d[i][j] = 1; else d[i][j] = 0;
				}
				else
				{
					if (s[i] == pat[j])
					{
						for (int k=0; k<i; k++)
							d[i][j] = (d[i][j] + d[k][j-1]) % 10000;
					}
				}
			}
		}
		int ans = 0;
		for (int i=0; i<s.length(); i++)
			ans = (ans + d[i][pat.length()-1])%10000;

		fout << "Case #" << ++cases << ": " << ans/1000 << ans/100%10 << ans/10%10 << ans%10 << endl;
	}
	return 0;
}