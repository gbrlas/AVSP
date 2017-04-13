#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int
main()
{
	int T, z;
	cin >> T;
	for (z = 1; z <= T; z++)
	{
		long long L, P, C;
		cin >> L >> P >> C;
		long long G = 0;
		long long Q = L;
		while (Q < P)
		{
			Q *= C;
			G++;
		}
		int ans = 0;
		Q = 1;
		while (Q < G)
		{
			Q *= 2;
			ans++;
		}
		cout << "Case #" << z << ": " << ans << endl;
	}
	return(0);
}

