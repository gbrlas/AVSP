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

int n;
int m;
int c[128][16];

bool BitZ(int k, int b)
{
    return !(k & (1<<b));
}
int Cnt(int k)
{
    int c = 0;
    for (int i = 0; i < 32;++i)
    {
        if (!BitZ(k, i))
        {
            ++c;
        }
    }
    return c;
}
bool Is(int k)
{
    for (int i = 0; i < m; ++i)
    {
        int j;
        for (j = 0; j < n; ++j)
        {
            if (c[i][j] == 0 && BitZ(k, j))
            {
                break;
            }
            if (c[i][j] == 1 && !BitZ(k, j))
            {
                break;
            }
        }
        if (j >= n)
        {
            return false;
        }
    }
    return true;
}

void One(int idx)
{
    in >> n;
    in >> m;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            c[i][j] = -1;
        }

        int t;
        in >> t;
        for (int j = 0; j < t; ++j)
        {
            int x, y;
            in >> x >> y;
            c[i][x-1] = y;
        }
    }

    int c = 10000;
    int r = -1;
    for (int k = 0; k < (1 << n); ++k)
    {
        if (Is(k))
        {
            int tmp = Cnt(k);
            if (tmp < c)
            {
                c = tmp;
                r = k;
            }
        }
    }

    out << "Case #" << idx << ":";
    if (r == -1)
    {
        out << " IMPOSSIBLE";
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            out << " " << !BitZ(r, i);
        }
    }
    out << endl;
}

void SolveN()
{
	int N;
	in >> N;
	for (int i = 0; i < N; ++i)
	{
		One(i + 1);
	}
}



void Solve()
{
}

int main()
{
	SolveN();
	return 0;
}