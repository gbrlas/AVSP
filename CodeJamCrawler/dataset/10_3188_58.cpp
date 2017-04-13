#include <iostream>
#define maxN 2000

using std::cin;
using std::cout;
using std::endl;

int a[maxN], b[maxN];

int
main()
{
	int T, z;
	cin >> T;
	for (z = 1; z <= T; z++)
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> a[i] >> b[i];
		int ans = 0;
		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++)
				if ((a[i] > a[j] && b[i] < b[j]) || (a[i] < a[j] && b[i] > b[j]))
					ans++;
		cout << "Case #" << z << ": " << ans << endl;
	}
	return(0);
}

