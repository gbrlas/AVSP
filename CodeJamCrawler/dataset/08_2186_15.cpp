#include <iostream>
#include <vector>
#include <cstdio>
#include <list>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

#define _Test
#ifdef _Test
#define in cin
#define out cout
#else
#endif

typedef long long Int64;

int m;
int ct;
int p[1024 * 16];
int c[1024 * 16];
int q[1024 * 16][2];

int IM = 11000;

int Chy(int r, int v);

int ChyWhen(int r, int v, int pr)
{
    int r1 = 2 * r + 1;
    int r2 = 2 *r + 2;
    int cnt;
    if (pr == 1) // AND
    {
        if (v == 0)
        {
            cnt = min(Chy(r1, 0) + Chy(r2, 0), Chy(r1, 0) + Chy(r2, 1));
            cnt = min(cnt, Chy(r1, 1) + Chy(r2, 0));
        }
        else
        {
            cnt = Chy(r1, 1) + Chy(r2, 1);
        }
    }
    else
    {
        if (v == 1)
        {
            cnt = min(Chy(r1, 1) + Chy(r2, 1), Chy(r1, 0) + Chy(r2, 1));
            cnt = min(cnt, Chy(r1, 1) + Chy(r2, 0));
        }
        else
        {
            cnt = Chy(r1, 0) + Chy(r2, 0);
        }
    }
    return cnt;
}

int Chy(int r, int v)
{
    if (q[r][v] != -1)
    {
        //return q[r][v];
    }

    if (r >= ct)
    {
        return q[r][v] = (p[r] == v ? 0 : IM);
    }
    
    int cnt = ChyWhen(r, v, p[r]);
    if (cnt >= IM && c[r])
    {
        cnt = ChyWhen(r, v, !p[r]) + 1;
    }
    return q[r][v] = cnt;
}

void One(int idx)
{
    int v;
    in >> m >> v;
    ct = (m - 1) / 2;
    memset(q, -1, sizeof(q));
    for (int i = 0; i < ct; ++i)
    {
        in >> p[i] >> c[i];        
    }
    for (int i = ct; i < m; ++i)
    {
        in >> p[i];
        c[i] = 0;
    }

    out << "Case #" << idx << ": ";
    int cnt = Chy(0, v);
    if (cnt >= IM)
    {
        out << "IMPOSSIBLE";
    }
    else
    {
        out << cnt;
    }
    out << endl;
}

void SolveN()
{
	int _N;
	in >> _N;
	for (int i = 0; i < _N; ++i)
	{
		One(i + 1);
	}
}

int main()
{
	SolveN();
	return 0;
}