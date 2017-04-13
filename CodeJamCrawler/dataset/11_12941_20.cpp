#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;

int mat[100][100];
int wins[100];
int games[100];
double wp[100];
double woo[100][100];
double avwoop[100];
double another[100];

void solve()
{
	int N; cin >> N;
	memset(mat, 0, 100 * 100 * sizeof(int) );
	memset(wins, 0, sizeof(wins));
	memset(games, 0, sizeof(games));
	memset(wp, 0, sizeof(wp));
	memset(woo, 0, sizeof(double) * 100 * 100);
	memset(avwoop, 0, sizeof(avwoop));
	memset(another, 0, sizeof(another));


	for(int i=0; i<N; ++i)
	{
		for(int j = 0; j<N; ++j)
		{
			char c; cin >> c;
			if(c == '.')
				mat[i][j] = -1;
			else if(c == '1')
			{
				mat[i][j] = 1;
				wins[i]++;
				games[i]++;
			}
			else
			{
				mat[i][j] = 0;
				games[i]++;
			}
		}

		wp[i] = wins[i] / double(games[i]);
	}

	for(int i=0; i<N; ++i)
	{
		for(int j=0; j<N; ++j)
		{
			if(i == j)
				continue;

			if(mat[i][j] == 1)
				woo[i][j] =  (wins[i] - 1) / double(games[i] - 1);
			else if(mat[i][j] == 0)
				woo[i][j] = wins[i] / double(games[i] - 1);
			else
				woo[i][j] = wins[i] / double(games[i]);
		}
	}

	for(int i=0; i<N; ++i)
	{
		int c=0;
		for(int j=0; j<N; ++j)
			if(mat[i][j] > -1)
			{
				c++;
				avwoop[i] += woo[j][i];
			}
		avwoop[i] /= c;
	}

	for(int i=0; i<N; ++i)
	{
		int c =0;
		for(int j=0; j<N; ++j)
			if(mat[i][j] > -1)
			{
				c++;
				another[i] += avwoop[j];
			}
		another[i] /= c;
	}

	for(int i=0; i<N; ++i)
	{
		double rpi = 0.25 * wins[i] / double(games[i]);
		rpi += 0.5 * avwoop[i];
		rpi += 0.25 * another[i];

		printf("%.12lf\n", rpi);
	}
}

int main()
{
//	freopen("test.in", "r", stdin);

	int T; cin >> T;
	for(int test=1; test<=T; ++test)
	{
		printf("Case #%d:\n", test);
		solve();
	}
}