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

int what[256];



int main()
{
	int StartTime = clock();
	openfiles ("aliens");
	int TT = nextint();
	nextchar();
	for (int tt = 0; tt < TT; tt++)
	{
		memset (what, -1, sizeof(what));
		string s = nextstring();
		string t = "";
		int n = s.length();
		if (s[n-1] =='\n')
			n--;
		int min = 0;
		t[0] = 1;
		what[s[0]] = 1;
		for (int i = 1; i < n; i++)
		{
			if (what[s[i]] == -1)
			{
				what[s[i]] = min;
				min++;
				if (min == 1)
					min++;
			}
			t[i] = what[s[i]];			
		}
		int rad;
		if (min == 0)
			rad = 2;
		else
			rad = min;
		long long answ = 0;
		for (int i = 0; i < n; i++)
			answ = answ * rad + t[i];
		fprintf(out, "Case #%d: %lld\n", tt+1, answ);
	}
	prval ("time", clock() - StartTime);
	return 0;
}

