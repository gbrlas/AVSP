#include "global.h"

string a[50];
int k[50];

int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int tt;
	//scanf("%d", &tt);
	cin >> tt;
	For(ttt, 0, tt)
	{
		int n, res=0; cin >> n;
		For(i, 0, n) {
			cin >> a[i];
			if (a[i].find_last_of('1') == string::npos)
				k[i] = -1;
			else
				k[i] = a[i].find_last_of('1');
		}
		For(i, 0, n)
			if (k[i] > i)
				For(j, i+1, n)
					if (k[j] <= i)
					{
						res += j-i;
						ForD(t, j, i)
							swap(k[t], k[t+1]);
						break;
					}
		printf("Case #%d: %d\n", ttt+1, res);
	}
	return 0;
}