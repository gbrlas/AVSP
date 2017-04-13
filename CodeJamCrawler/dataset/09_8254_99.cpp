#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define PII pair<int, int>

int mas[105][105];
char res[105][105];
bool m[105][105][105][105];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int main() {
	freopen("B.in", "rt", stdin);
	freopen("B.out", "wt", stdout);

	int T,H, W;
	cin >> T;
	for(int test = 1; test <= T; test++) {
		cin >> H >> W;
		memset(mas, -1, sizeof(mas));
		memset(res, -1, sizeof(res));
		memset(m, 0, sizeof(m));
		for(int i = 1; i <= H; i++) {
			for(int j = 1; j <= W; j++) {
				cin >> mas[i][j];
			}
		}
		for(int i = 1; i <= H; i++) {
			for(int j = 1; j <= W; j++) {
				PII cur = PII(i, j);
				PII best = PII(-1, -1);
				for(int z = 0; z < 4; z++) {
					PII new_p = PII(cur.first + dx[z], cur.second + dy[z]);
					if(mas[new_p.first][new_p.second] == -1 || mas[new_p.first][new_p.second] >= mas[cur.first][cur.second]) continue;
					if(best.first == -1 || mas[new_p.first][new_p.second] < mas[best.first][best.second]) {
						best = new_p;
					}
				}
				if(best.first != -1) {
					m[i][j][best.first][best.second] = m[best.first][best.second][i][j] = 1;
				}
			}
		}
		int cnt = -1;
		for(int i = 1; i <= H; i++) {
			for(int j = 1; j <= W; j++) {
				if(res[i][j] != -1) continue;
				cnt++;
				queue<PII> q;
				q.push(PII(i, j));
				while(!q.empty()) {
					PII cur = q.front(); q.pop();
					res[cur.first][cur.second] = 'a' + cnt;
					PII best = PII(-1, -1);
					for(int z = 0; z < 4; z++) {
						PII new_p = PII(cur.first + dx[z], cur.second + dy[z]);
						if(m[cur.first][cur.second][new_p.first][new_p.second] && res[new_p.first][new_p.second] == -1) {
							q.push(new_p);
						}
					}
				}
			}
		}
		cout << "Case #" << test << ":" << endl;
		for(int i = 1; i <= H; i++) {
			cout << res[i][1];
			for(int j = 2; j <= W; j++) {
				cout << " " << res[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}