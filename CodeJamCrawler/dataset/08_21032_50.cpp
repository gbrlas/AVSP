#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXR 17
#define MAXPOS 12000000
#define LOTS 10000000

int R, C;
int pc;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
#define LEFT 2
#define RIGHT 0
#define UP 3
#define DOWN 1

struct portal {
	bool is;
	int r, c;
	portal(): is(false) {}
	portal(int code) {
		if (code == 0)
			is = false;
		else {
			is = true;
			--code;
			r = code / C + 1;
			c = code % C + 1;
		}
	}
	portal(int r, int c): is(true), r(r), c(c) {}
	int code() {
		if (!is)
			return 0;
		return (r - 1) * C + (c - 1) + 1;
	}
};

struct pos {
	int r, c;
	portal blue, orange;
	pos(): r(0), c(0), blue(), orange() {}
	pos(int r, int c, int bluecode, int orangecode): r(r), c(c), blue(bluecode), orange(orangecode) {}
	pos(int code) {
		orange = portal(code % pc);
		code /= pc;
		blue = portal(code % pc);
		code /= pc;
		c = code % C + 1;
		r = code / C + 1;
	}
	int code() {
		return (((r-1) * C + (c-1)) * pc + blue.code()) * pc + orange.code();
	}
};

bool wall[MAXR][MAXR];
portal pp[MAXR][MAXR][4];
int moves[MAXPOS];
queue<int> Q;
int cr, cc;
int answer = -1;

void move(int poscode, int m) {
	if (moves[poscode] > m) {
		moves[poscode] = m;
		Q.push(poscode);
	}
}

void moveto(int r, int c, int m, int oldpb, int oldpo) {
	if (wall[r][c])
		return;
	if (r == cr && c == cc)
		answer = m;
	pos P(r, c, oldpb, oldpo);
	move(P.code(), m);
	for (int i = 0; i < 4; ++i) {
		P.blue = pp[r][c][i];
		move(P.code(), m);
	}
	P.blue = portal(oldpb);
	for (int i = 0; i < 4; ++i) {
		P.orange = pp[r][c][i];
		move(P.code(), m);
	}
	for (int i = 0; i < 4; ++i) {
		P.blue = pp[r][c][i];
		for (int j = 0; j < 4; ++j)
			if (i != j) {
				P.orange = pp[r][c][j];
				move(P.code(), m);
			}
	}
}

void fillportals() {
	fill(pp[0][0], pp[MAXR][0], portal());
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			if (wall[i][j])
				continue;
			if (wall[i][j-1])
				pp[i][j][LEFT] = portal(i, j);
			else
				pp[i][j][LEFT] = pp[i][j-1][LEFT];
			if (wall[i-1][j])
				pp[i][j][UP] = portal(i, j);
			else
				pp[i][j][UP] = pp[i-1][j][UP];
		}
	}
	for (int i = R; i; --i) {
		for (int j = C; j; --j) {
			if (wall[i][j])
				continue;
			if (wall[i][j+1])
				pp[i][j][RIGHT] = portal(i, j);
			else
				pp[i][j][RIGHT] = pp[i][j+1][RIGHT];
			if (wall[i+1][j])
				pp[i][j][DOWN] = portal(i, j);
			else
				pp[i][j][DOWN] = pp[i+1][j][DOWN];
		}
	}
}

int solve() {
	scanf("%d%d", &R, &C);
	pc = R*C + 1;
	char line[MAXR];
	fill(wall[0], wall[MAXR], true);
	int sr, sc;
	for (int i = 1; i <= R; ++i) {
		scanf(" %s", line);
		for (int j = 1; j <= C; ++j) {
			wall[i][j] = line[j-1] == '#';
			if (line[j-1] == 'O')
				sr = i, sc = j;
			if (line[j-1] == 'X')
				cr = i, cc = j;
		}
	}
	fillportals();
	fill(moves, moves+MAXPOS, LOTS);
	answer = -1;
	while (!Q.empty())
		Q.pop();
	moveto(sr, sc, 0, 0, 0);
	while (!Q.empty() && answer < 0) {
		int pcode = Q.front();
		Q.pop();
		pos p(pcode);
		for (int i = 0; i < 4; ++i) {
			moveto(p.r+dr[i], p.c+dc[i], moves[pcode]+1, p.blue.code(), p.orange.code());
		}
		if (p.blue.is && p.orange.is) {
			if (p.r == p.blue.r && p.c == p.blue.c)
				moveto(p.orange.r, p.orange.c, moves[pcode]+1, p.blue.code(), p.orange.code());
			if (p.r == p.orange.r && p.c == p.orange.c)
				moveto(p.blue.r, p.blue.c, moves[pcode]+1, p.blue.code(), p.orange.code());
		}
	}
	return answer;
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		int r = solve();
		if (r >= 0)
			printf("%d\n", r);
		else
			printf("THE CAKE IS A LIE\n");
	}
	return 0;
}
