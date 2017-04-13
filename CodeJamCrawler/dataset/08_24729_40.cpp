#include <iostream>
#include <string>
#include <memory>

using namespace std;

int count(string& s)
{
	char last = s[0];
	int res = 1;
	for (int i=1; i<s.length(); i++)
	{
		if (s[i] != last)
		{
			last = s[i];
			res++;
		}
	}
	return res;
}

int d[200][20];
int now[20];
bool used[20];
int dn = 0;

void depth(int dep, int n)
{
	if (dep >= n)
	{
		for (int i=0; i<n; i++)
			d[dn][i] = now[i];
		dn++;
		return;
	}

	for (int i=0; i<n; i++)
		if (!used[i])
		{
			used[i] = true;
			now[dep] = i;
			depth(dep+1, n);
			used[i] = false;
		}
}

int main()
{
	int N;
	cin >> N;
	int cases = 0;
	while (N--)
	{
		int res = 2000000000;

		string s, s2;
		int k;

		cin >> k;
		cin >> s;
		s2 = s;
		
		dn = 0;
		memset(used, 0, sizeof used);
		depth(0, k);

		for (int i=0; i<dn; i++)
		{
			for (int j=0; j<s.length()/k; j++)
				for (int q=0; q<k; q++)
					s2[j*k+q] = s[j*k+d[i][q]];
			int nn = count(s2);
			if (nn < res) res = nn;
		}

		cout << "Case #" << ++cases << ": " << res << endl;
	}
	return 0;
}