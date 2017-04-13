#include <iostream>
#include <cstdio>
using namespace std;

int lawn[100][100], N, M;

void input()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> lawn[i][j];
		}
	}
}

bool isok(int x, int y)
{
	int i;
	for(i = 0; i < N; i++) {
		if(lawn[i][y] > lawn[x][y]) break;
	}
	if(i == N) return true;
	for(i = 0; i < M; i++) {
		if(lawn[x][i] > lawn[x][y]) break;
	}
	if(i == M) return true;
	return false;
}

void answer()
{
	for(int x = 0; x < N; x++) {
		for(int y = 0; y < M; y++) {
			if(!isok(x, y)) {
				cout << "NO" << endl;
				return ;
			}
		}
	}
	cout << "YES" << endl;
}

int main()
{
	int t;
	freopen("small.in", "r", stdin);
	freopen("small.out", "w", stdout);
	cin >> t;
	for(int i = 1; i <= t; i++) {
		input();
		cout << "Case #" << i << ": ";
		answer();
	}
	return 0;
}

