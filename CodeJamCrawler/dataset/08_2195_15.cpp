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
int k;
char s[50005];
int len;
int Com(int p[])
{
    char d[10000];
    for (int i = 0; s[i]; ++i)
    {
        d[i] = s[i / k * k + p[i % k]];
    }
    int cnt = 1;
    for (int i = 1; i < len; ++i)
    {
        cnt += (d[i] != d[i-1]);
    }
    return cnt;
}

void One(int idx)
{
    in >> k >> s;
    len = strlen(s);
    int p[] = {0, 1, 2, 3, 4};
    int cnt = 1000000;
    cnt = min(cnt, Com(p));
    for (; std::next_permutation(p, p + k);)
    {
        cnt = min(cnt, Com(p));
    }

    
    out << "Case #" << idx << ": ";
    out << cnt;
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