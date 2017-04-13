#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

string itoa(int val)
{
	ostringstream oss;
	oss << val;
	return oss.str();
}

int main()
{
	freopen("C-small-in.txt", "r", stdin);
	freopen("C-small-out.txt", "w", stdout);
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int A, B, ans = 0;
		cin >> A >> B;
		for (int j = A; j < B; j++)
		{
			for (int k = j + 1; k < B + 1; k++)
			{
				string m = itoa(j);
				string n = itoa(k);
				if (n.length() != m.length()) break;
				int p = n.length();
				for (int p_ = 0; p_ < p; p_++)
				{
					int matches = 0;
					int p1 = 0, p2 = p_;
					while (matches < p && m[p1] == n[p2])
					{
						p1++;
						p2 = (p2 + 1) % p;
						matches++;
					}
					if (matches == p)
					{
					    ans++;
					    break;
					}
				}
			}
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}