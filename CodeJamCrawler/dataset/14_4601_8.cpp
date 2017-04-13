#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
using namespace std;

#define FOR(a,b,c) for(a = b;a < c;a++)
#define REP(a,b) FOR(a,0,b)
#define BG begin()
#define ED end()

vector <array <int, 1001>> andr(1001);

int main()
{
	int t, test, a, b, k, i, j, cnt;
	REP(i, 1001)
		REP(j, 1001)
			andr[i][j] = i & j;
	
	
	cin >> t;
	REP(test, t)
	{
		cnt = 0;
		cin >> a >> b >> k;
		REP(i, a)
			REP(j, b)
				if(andr[i][j] < k)
					cnt++;
		cout << "Case #" << test + 1 << ": " << cnt << endl;
	}
}