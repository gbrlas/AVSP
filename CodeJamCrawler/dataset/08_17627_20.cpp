#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

string a[40];

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C.out", "w", stdout);

	a[0] = "001";
	a[1] = "005";
	a[2] = "027";
	a[3] = "143";
	a[4] = "751";
	a[5] = "935";
	a[6] = "607";
	a[7] = "903";
	a[8] = "991";
	a[9] = "335";
	a[10] = "047";
	a[11] = "943";
	a[12] = "471";
	a[13] = "055";
	a[14] = "447";
	a[15] = "463";
	a[16] = "991";
	a[17] = "095";
	a[18] = "607";
	a[19] = "263";
	a[20] = "151";
	a[21] = "855";
	a[22] = "527";
	a[23] = "743";
	a[24] = "351";
	a[25] = "135";
	a[26] = "407";
	a[27] = "903";
	a[28] = "791";
	a[29] = "135";
	a[30] = "647";

	int T;
	scanf("%d", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		int n;
		scanf("%d", &n);
		printf("Case #%d: %s\n", tst, a[n].c_str());
	}

	return 0;
}
