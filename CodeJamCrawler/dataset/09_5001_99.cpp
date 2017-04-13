#include <cstdio>
#include <ctime>
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <list>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
FILE *in, *out;

void openfiles(string s)
{
	in = fopen ((s + ".in").c_str(), "rt");
	out = fopen ((s + ".out").c_str(), "wt");
}

void prval(const char* s, double x) {printf("%s = %lf;\n", s, x);}
void prval(const char* s, int x) {printf("%s = %d;\n", s, x);}
void prval(const char* s, long x) {printf("%s = %d;\n", s, x);}
void prval(const char* s, char x) {printf("%s = %c;\n", s, x);}
void prval(const char* s, char* a, int n, int dif) {
	printf("%s = [", s);
	for (int i = 0; i < n - 1; i++)
		printf("%c, ", a[i]+dif);
	if (n > 0)
		printf("%c", a[n-1]+dif);
	printf("];\n");
}
void prval(const char* s, int* a, int n, int dif) {
	printf("%s = [", s);
	for (int i = 0; i < n - 1; i++)
		printf("%d, ", a[i]+dif);
	if (n > 0)
		printf("%d", a[n-1]+dif);
	printf("];\n");
}
void prval(const char* s, bool* a, int n, int dif) {
	printf("%s = [", s);
	for (int i = 0; i < n - 1; i++)
		printf("%d, ", a[i]+dif);
	if (n > 0)
		printf("%d", a[n-1]+dif);
	printf("];\n");
}
void prval(const char* s, double* a, int n, double dif) {
	printf("%s = [", s);
	for (int i = 0; i < n - 1; i++)
		printf("%lf, ", a[i]+dif);
	if (n > 0)
		printf("%lf", a[n-1]+dif);
	printf("];\n");
}
void print(char c) {fprintf(out , "%c", c);}
void print(int i) {fprintf(out , "%d ", i);}
void print(double i) {fprintf(out , "%lf ", i);}
void print(const char* s) {fprintf(out , "%s", s);}
void print(string s) {fprintf(out , "%s", s.c_str());}
int nextint() {int u; fscanf (in, "%d", &u); return u;}
double nextdouble() {double u; fscanf (in, "%lf", &u); return u;}
char nextchar() {char u; fscanf (in, "%c", &u); return u;}
string nextstring() {static char s[1000000]; fgets (s, 1000000, in); return s;}
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

int h, w;
const int maxn = 100, inf = 1000000;
bool was[maxn+2][maxn+2];
int now;
int at[maxn+2][maxn+2], col[maxn+2][maxn+2];
int dir[maxn+2][maxn+2];
int dx[4] = {-1, 0, 0, 1},
	dy[4] = {0, -1, 1, 0};


void dfs (int x, int y)
{
	was[x][y] = true;
	col[x][y] = now;
//	prval("x", x);
//	prval("y", y);
//	printf ("\n");
	for (int i = 0; i < 4; i++)
	{
		int nx = x - dx[i];
		int ny = y - dy[i];
		if (dir[nx][ny] == i)
			dfs (nx, ny);
	}
}


void make (int x, int y)
{
	while (dir[x][y] != -1)
	{
		int xx = x;
		x += dx[dir[xx][y]];
		y += dy[dir[xx][y]];
	}
	dfs (x, y);
}

int main()
{
	int StartTime = clock();
	openfiles ("basins");
	int TTT = nextint();	
	for (int ttt = 0; ttt < TTT; ttt++)
	{
		fprintf (out, "Case #%d:\n", ttt+1);
		h = nextint();
		w = nextint();
		for (int i = 0; i <= h+1; i++)
		{
			at[i][0] = inf;
			at[i][w+1] = inf;
			dir[i][0] = -1;
			dir[i][w+1] = -1;
		}
		for (int i = 0; i <= w+1; i++)
		{
			at[0][i] = inf;
			at[h+1][i] = inf;
			dir[0][i] = -1;
			dir[h+1][i] = -1;
		}
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				at[i][j] = nextint();
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
			{
				int minat = inf;
				dir[i][j] = -1;
				for (int k = 0; k < 4; k++)
					if (at[i+dx[k]][j+dy[k]] < minat)
					{
						minat = at[i+dx[k]][j+dy[k]];
						dir[i][j] = k;
					}
//				prval("i", i);
//				prval("j", j);
//				prval("minat", minat);
				if (at[i+dx[dir[i][j]]][j+dy[dir[i][j]]] >= at[i][j])
					dir[i][j] = -1;
			}
		now = 0;
		memset (was, 0, sizeof (was));
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				if (!was[i][j])
				{
					make(i, j);
//					prval("now i", i);
//					prval("now j", j);
					now++;
				}
/*		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
				print(dir[i][j]);
			print("\n");
		}
		print("\n");*/
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				print((char)(col[i][j] + 'a'));
				print(' ');
			}
			print("\n");
		}
	}
	prval ("time", clock() - StartTime);
	return 0;
}

