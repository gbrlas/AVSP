#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

int field[101][101];
int region[101][101];
int T, H, W;

void paint(int x, int y, int c)
{
	int mv = field[y][x], mx, my;
	bool sink = true;
	
	if(region[y][x] != 0) {
		int i, j, d = region[y][x];
		for(i = 0; i < H; ++i) {
			for(j = 0; j < W; ++j) {
				if(region[i][j] == d)
					region[i][j] = c;
			}
		}
	}
	region[y][x] = c;
	
	if(y > 0 && field[y - 1][x] < field[y][x] && field[y - 1][x] < mv) {
		// north
		mx = x;
		my = y - 1;
		mv = field[y - 1][x];
		sink = false;
	}
	
	if(x > 0 && field[y][x - 1] < field[y][x] && field[y][x - 1] < mv) {
		mx = x - 1;
		my = y;
		mv = field[y][x - 1];
		sink = false;
	}
	
	if(x < W - 1 && field[y][x + 1] < field[y][x] && field[y][x + 1] < mv) {
		mx = x + 1;
		my = y;
		mv = field[y][x + 1];
		sink = false;
	}
	
	if(y < H - 1 && field[y + 1][x] < field[y][x] && field[y + 1][x] < mv) {
		mx = x;
		my = y + 1;
		mv = field[y + 1][x];
		sink = false;
	}
	//printf("%d %d - %d %d\n", x, y, c, mv); fflush(stdout);
	
	if(!sink) {
		paint(mx, my, c);
	}
}

int main(void)
{
	int i, j, k, c;
	char ch;
	
	scanf("%d", &T);
	
	for(i = 0; i < T; ++i) {
		map<int, char> tb;
		scanf("%d%d", &H, &W);
		
		for(j = 0; j < H; ++j) {
			for(k = 0; k < W; ++k) {
				scanf("%d", &field[j][k]);
				region[j][k] = 0;
			}
		}
		
		c = 1;
		for(j = 0; j < H; ++j) {
			for(k = 0; k < W; ++k) {
				if(region[j][k] == 0) {
					paint(k, j, c);
					++c;
				}
			}
		}
		
		ch = 'a';
		for(j = 0; j < H; ++j) {
			for(k = 0; k < W; ++k) {
				if(tb.find(region[j][k]) == tb.end()) {
					tb[region[j][k]] = ch;
					++ch;
				}
			}
		}
		
		printf("Case #%d:\n", i + 1);
		for(j = 0; j < H; ++j) {
			for(k = 0; k < W; ++k) {
				printf("%c", tb[region[j][k]]);
				putchar(k + 1 < W ? ' ' : '\n');
			}
		}
	}
	
	return 0;
}
