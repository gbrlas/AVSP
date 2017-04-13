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

const string p = "welcome to code jam";
const int m = p.length(), maxn = 500;

int make (string s)
{
	long long a[maxn][m];
	int n = s.length()-1;
	if (s[n+1] != '\n')
		n++;
	for (int i = 0; i < n; i++)
		if (s[i] == p[m-1])
			a[i][m-1] = 1;
		else
			a[i][m-1] = 0;
	for (int i = m-2; i >= 0; i--)
		for (int j = 0; j < n; j++)
		{
			a[j][i] = 0;
			if (s[j] != p[i])
				continue;
			for (int k = j+1; k < n; k++)
				a[j][i] = (a[j][i] + a[k][i+1]) % 10000;
		}
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum = (sum + a[i][0]) % 10000;
	return sum;
}


int main()
{
	int StartTime = clock();
	openfiles ("welcome");
	int TT = nextint();
	fscanf(in, "\n");
	for (int tt = 0; tt < TT; tt++)
	{
		string s = nextstring();
		int kol = make(s);
		fprintf (out, "Case #%d: ", tt+1);
		for (int i = 1000; i > 0; i /=10)
		{
			fprintf (out, "%d", kol / i);
			kol %= i;
		}
		fprintf (out, "\n");
	}
	prval ("time", clock() - StartTime);
	return 0;
}

