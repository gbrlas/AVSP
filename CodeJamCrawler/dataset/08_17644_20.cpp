#include <string>
#include <cstring>
#include <iostream>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int maxn = 10000;
const int maxm = 2000;

int l[maxn], r[maxn], ul[maxn], dl[maxn], ur[maxn], dr[maxn];
int rep[maxm];
string s[maxm];
int n, d, nx, ny, tot;

main()
{
    freopen("a-small-attempt0.in", "r", stdin);
    freopen("a.out", "w", stdout);
       
	int T;
	scanf("%d", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		scanf("%d", &n);
        for (int i = 0; i < n; ++i) cin >> s[i] >> rep[i];

           int cx = 5000, cy = 5000, ans = 0;
		   d = tot = 0;

           for (int i = 9001; i > 0; --i) r[i] = 0, l[i] = maxn;

           for (int i = 0; i < n; ++i)
               for (int j = 0; j < rep[i]; ++j)
                   for (int k = 0; k < s[i].size(); ++k)
					{
						if (s[i][k] == 'L')
						{
							d = d + 3 & 3;
							continue;
						}
						if (s[i][k] == 'R')
						{
							d = d + 1 & 3;
							continue;
						}
						if (!dx[d])
						{
							if (d == 2) ny = cy - 1;
							else ny = cy;
							l[ny] <?= cx; r[ny] >?= cx;
                        }
						nx = cx + dx[d]; ny = cy + dy[d];
                        ans += nx * cy - ny * cx;
                        cx = nx; cy = ny;
                    }

            dl[0] = ul[9001] = maxn;

            for (int i = 1; i < 9000; ++i) dl[i] = dl[i-1] <? l[i], dr[i] = dr[i-1] >? r[i];

            for (int i = 9000; i > 0; --i)
			   ul[i] = ul[i+1] <? l[i], ur[i] = ur[i+1] >? r[i],
			   l[i] <?= dl[i] >? ul[i], r[i] >?= dr[i] <? ur[i];

            for (int i = 9000; i > 0; --i) tot += r[i]-l[i] >? 0;

			printf("Case #%d: %d\n", tst, tot - abs(ans) / 2);

       }

	  return 0;
}
