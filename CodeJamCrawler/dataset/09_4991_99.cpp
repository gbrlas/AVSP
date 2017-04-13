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
		printf("%c, ", a[i]+dif);
	if (n > 0)
		printf("%c", a[n-1]+dif);
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

//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------

const int maxd = 5000, maxn = 500, maxl = 15;
string pat[maxd];
bool can[maxn][maxl][26];



int main()
{
	int StartTime = clock();
	openfiles ("aliens");
	int l = nextint(), d = nextint(), n = nextint();
//	prval ("l", l);
//	prval ("d", d);
//	prval ("n", n);
	fscanf(in, "\n");
	for (int i = 0; i < d; i++)
		pat[i] = nextstring();
	for (int i = 0; i < n; i++)
	{
		string s = nextstring();
		int now = 0;
		int sl = s.length();
		bool f = true;
		for (int j = 0; j < sl-1; j++)
		{
//			prval ("c", s[j]);
			if (s[j] == '(')
			{
				f = false;
				continue;
			}
			if (s[j] == ')')
			{
				f = true;
				now++;
				continue;
			}
			can[i][now][s[j] - 'a'] = true;
			if (f)
				now++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int amount = 0;
		for (int j = 0; j < d; j++)
		{
			bool f = true;
			for (int k = 0; k < l; k++)
				if (!can[i][k][pat[j][k] - 'a'])
				{
					f = false;
					break;
				}
			amount += f;
		}
		fprintf (out, "Case #%d: %d\n", i+1, amount);
	}
/*	for (int i = 0; i < n; i++)
		for (int j = 0; j < 26; j++)
			prval ("can[i][j]", can[i][j], 26, 0);*/
	prval ("time", clock() - StartTime);
	return 0;
}

