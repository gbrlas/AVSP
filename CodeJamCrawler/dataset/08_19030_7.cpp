#include <iostream>
using namespace std;

int g1[10][10];
int g2[10][10];

int n, m;
int ok = 0;
int v[10];
int a[10];

void check()
{
	int can = 1;
	for (int i = 1; i <= m; i++)  {
		if (!can) break;
		for (int j = 1; j <= m; j++) if (g2[i][j])
			if (!g1[a[i]][a[j]]) { can = 0; break; }
	}

  if (can) ok = 1;
}

void search(int d)
{
	if (ok) return ;
	for (int i =1 ; i <= n; i++) if (v[i] == 0) {
		a[d] = i;
		v[i] = 1;
		if (d < m) search(d + 1);
		else check();
		v[i] = 0;
	}
}
int main()
{
	freopen("C:\\Documents and Settings\\codejam\\Desktop\\D-small-attempt0.in", "r",stdin);
	freopen("C:\\Documents and Settings\\codejam\\Desktop\\output.txt", "w", stdout);
	int tests;
	cin >> tests;
	
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";
        ok = 0;
		memset(g1, 0, sizeof(g1));
		memset(g2, 0, sizeof(g2));
		cin >> n;
		for (int i = 1; i <= n - 1; i ++) {
			int x, y;
			cin >> x >> y;
			g1[x][y] = g1[y][x] = 1;
		}

		cin >> m;
		for (int i = 1; i <= m - 1; i++) {
			int x, y;
			cin >> x >> y;
			g2[x][y] = g2[y][x] = 1;
		}
		//cout << n << " " << m << endl;
		memset(v, 0, sizeof(v));
		search(1);

		if (ok) cout << "YES"; else cout << "NO";
			cout << endl;

	}
	return 0;
}
