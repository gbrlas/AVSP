#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int T, row, num;
	vector < int > ans;
	bool cnt[17];
	scanf ("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		memset (cnt, false, sizeof (cnt));
		ans.clear ();
		scanf ("%d", &row);
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				scanf ("%d", &num);
				if (i == row)
					cnt[num] = true;
			}
		scanf ("%d", &row);
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				scanf ("%d", &num);
				if (i == row && cnt[num])
					ans.push_back (num);
			}

		int sz = ans.size ();
		if (sz == 0)
			printf ("Case #%d: Volunteer cheated!\n", testcase);
		else if (sz == 1)
			printf ("Case #%d: %d\n", testcase, ans[0]);
		else
			printf ("Case #%d: Bad magician!\n", testcase);
	}
	return 0;
}
