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



struct fire
{
	double x, y, z, vx, vy, vz;
	fire& operator+= (fire a) {x += a.x;vx += a.vx;y += a.y;vy += a.vy;z += a.z;vz += a.vz;}
	fire() {x = y = z = vx = vy = vz = 0;}
};

double dist2 (fire a)
{
	return (a.x*a.x + a.y*a.y + a.z*a.z);
}

const int maxn = 500;
fire a[maxn];
fire m;



int main()
{
	int StartTime = clock();
	openfiles ("fireflies");
	int TT;
	TT = nextint();
	for (int tt = 0; tt < TT; tt++)
	{
		m.x = 0;
		m.y = 0;
		m.z = 0;
		m.vx = 0;
		m.vy = 0;
		m.vz = 0;
		int n = nextint();
		for (int i = 0; i < n; i++)
		{
			a[i].x = nextdouble();
			a[i].y = nextdouble();
			a[i].z = nextdouble();
			a[i].vx = nextdouble();
			a[i].vy = nextdouble();
			a[i].vz = nextdouble();
			m += a[i];
		}
		m.x /= n;
		m.y /= n;
		m.z /= n;
		m.vx /= n;
		m.vy /= n;
		m.vz /= n;
/*		print(m.x);print ("\n");
		print(m.y);print ("\n");
		print(m.z);print ("\n");
		print(m.vx);print ("\n");
		print(m.vy);print ("\n");
		print(m.vz);print ("\n");*/
		if (m.vx == 0 && m.vy == 0 && m.vz == 0)
		{
			fprintf (out, "Case #%d: %f %f\n", tt+1, sqrt(dist2(m)), 0);
			continue;
		}
		double t = -(m.x*m.vx + m.y*m.vy + m.z*m.vz) / (m.vx*m.vx + m.vy*m.vy + m.vz*m.vz);
//		fprintf(out, "%lf\n", t);
		if (t < 0)
		{
			fprintf (out, "Case #%d: %f %f\n", tt+1, sqrt(dist2(m)), 0);
			continue;
		}
		fire nm;
		nm.x = t * m.vx + m.x;
		nm.y = t * m.vy + m.y;
		nm.z = t * m.vz + m.z;
		fprintf (out, "Case #%d: %f %f\n", tt+1, sqrt(dist2(nm)), t);		
	}
	prval ("time", clock() - StartTime);
	return 0;
}

