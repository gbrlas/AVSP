#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <complex>
#include <set>
#include <map>

using namespace std;

typedef complex<double> Point;
const double EPS = 1e-6;

int dblcmp(double x) { return x > EPS ? 1 : x < -EPS ? -1 : 0; }
double cross(const Point & a, const Point & b) { return a.real() * b.imag() - a.imag() * b.real(); }
double dot(const Point & a, const Point & b) { return a.real() * b.real() + a.imag() * b.imag(); }

const int MAX_LENGTH = 300000 + 100, DELTA = 3050;
const int MOVE[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int pathCnt;
char tot[MAX_LENGTH], str[100];
int go[DELTA * 2][DELTA * 2][4], q[DELTA * 2 * DELTA * 2][2], v[DELTA * 2][DELTA * 2];
int top[DELTA * 2], down[DELTA * 2], LEFT[DELTA * 2], RIGHT[DELTA * 2];
inline bool inRange(int x, int y) { return 0 <= x && x < DELTA * 2 && 0 <= y && y < DELTA * 2; }

void update(int cx, int cy)
{
					top[cx] <?= cy;
					down[cx] >?= cy;
					LEFT[cy] <?= cx;
					RIGHT[cy] >?= cx;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int caseNo = 1; caseNo <= cases; ++caseNo)
	{
		scanf("%d", &pathCnt);
		int ptr = 0;
		for (int i = 0, rptTime; i < pathCnt; ++i)
		{
			scanf("%s %d", str, &rptTime);
			int len = strlen(str);
			for (int j = 0; j < rptTime; ++j)
				for (int k = 0; k < len; ++k)
					tot[ptr++] = str[k];
			if (ptr > MAX_LENGTH)
			{
				printf("ERROR!\n");
				exit(0);
			}
		}
		// calcs [go]
		int dx = 0 + DELTA, dy = 0 + DELTA, cx, cy, dd = 0;
		int minX = dx, minY = dy, maxX = dx, maxY = dy;
		for (int i = 0; i < DELTA * 2; ++i)
		{
			top[i] = DELTA * 2;
			down[i] = -1;
			LEFT[i] = DELTA * 2;
			RIGHT[i] = -1;
		}
			
		for (int i = 0; i < ptr; ++i)
		{
			if (tot[i] == 'L')
				dd = (dd + 3) % 4;
			else if (tot[i] == 'R')
				dd = (dd + 1) % 4;
			else
			{
				cx = dx + MOVE[dd][0], cy = dy + MOVE[dd][1];
				if (dd == 0)
					go[dx][dy][3] = go[dx][dy - 1][1] = caseNo;
				else if (dd == 2)
					go[cx][cy][3] = go[cx][cy - 1][1] = caseNo;
				else if (dd == 1)
					go[dx][dy][2] = go[dx + 1][dy][0] = caseNo;
				else
					go[cx][cy][2] = go[cx + 1][cy][0] = caseNo;
			//	printf("%d, %d - %d, %d\n", cx - 500, cy - 500, dx - 500, dy - 500);
				dx = cx; dy = cy;

				minX = min(minX, cx);
				minY = min(minY, cy);
				maxX = max(maxX, cx);
				maxY = max(maxY, cy);
			}
		}
		int front = -1, rear = 0;
		minX -= 2; minY -= 2; maxX += 2; maxY += 2;
		q[0][0] = minX; q[0][1] = minY; v[0][0] = caseNo;
		while (front++ < rear)
		{
			cx = q[front][0], cy = q[front][1];
			for (int i = 0; i < 4; ++i)
				if (go[cx][cy][i] != caseNo && inRange(cx + MOVE[i][0], cy + MOVE[i][1]) && v[cx + MOVE[i][0]][cy + MOVE[i][1]] != caseNo)
				{
					++rear;
					q[rear][0] = cx + MOVE[i][0]; q[rear][1] = cy + MOVE[i][1];
					v[q[rear][0]][q[rear][1]] = caseNo;
				}
		}
		for (int i = minX; i <= maxX; ++i)
			for (int j = minY; j <= maxY; ++j)
				if (v[i][j] != caseNo)
					update(i, j);
		//printf("Here\n");
		// top
		/*
		for (int i = minX; i <= maxX; ++i)
			for (int j = minY; j <= maxY; ++j)
				top[i][j] = j > 0 && top[i][j - 1] || v[i][j] != caseNo;
		// down
		for (int i = 0; i < DELTA * 2; ++i)
			for (int j = DELTA * 2 - 1; j >= 0; --j)
				down[i][j] = j < DELTA * 2 - 1 && down[i][j + 1] || v[i][j] != caseNo;
		// LEFT
		for (int i = 0; i < DELTA * 2; ++i)
			for (int j = 0; j < DELTA * 2; ++j)
				LEFT[i][j] = i > 0 && LEFT[i - 1][j] || v[i][j] != caseNo;
		// RIGHT
		for (int j = 0; j < DELTA * 2; ++j)
			for (int i = DELTA * 2 - 1; i >= 0; --i)
				RIGHT[i][j] = i < DELTA * 2 - 1 && RIGHT[i + 1][j] || v[i][j] != caseNo;
		*/
		int ans = 0;
		for (int i = 0; i < DELTA * 2; ++i)
			for (int j = 0; j < DELTA * 2; ++j)
				if (v[i][j] == caseNo && (top[i] <= j && j <= down[i] || LEFT[j] <= i && i <= RIGHT[j]))
				{
					//printf("%d, %d\n", i - DELTA, j - DELTA);
					++ans;
				}
		printf("Case #%d: %d\n", caseNo, ans);
	}
	return 0;
}
