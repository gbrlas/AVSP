#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <complex>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define DOWNFOR(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define CD complex<double>
#define All(x) (x).begin(), (x).end()

#define AND 1
#define OR 0

class Bod
{
public:
	LL minchange[2];
	int oper, changable;
};

LL N, M, V, G, C;
vector<Bod> strom;

void make(int v)
{
	if (v > (M-1)/2)
		return;

	make(2*v);
	make(2*v+1);

	LL minop[2][2];

	minop[AND][0] = min(strom[2*v].minchange[0]+strom[2*v+1].minchange[0], min(
					strom[2*v].minchange[0]+strom[2*v+1].minchange[1],
					strom[2*v].minchange[1]+strom[2*v+1].minchange[0]));
	minop[AND][1] = strom[2*v].minchange[1]+strom[2*v+1].minchange[1];
	minop[OR][0] = strom[2*v].minchange[0]+strom[2*v+1].minchange[0];
	minop[OR][1] = min(strom[2*v].minchange[1]+strom[2*v+1].minchange[1], min(
					strom[2*v].minchange[0]+strom[2*v+1].minchange[1],
					strom[2*v].minchange[1]+strom[2*v+1].minchange[0]));

	int OP = strom[v].oper;

	if (!strom[v].changable)
	{
		strom[v].minchange[0] = minop[OP][0];
		strom[v].minchange[1] = minop[OP][1];
	}
	else
	{
		strom[v].minchange[0] = min(minop[OP][0], minop[!OP][0]+1);
		strom[v].minchange[1] = min(minop[OP][1], minop[!OP][1]+1);
	}

}

int main()
{
	cin >> N;
	FOR (icase, 0, N)
	{
		cin >> M >> V;
		strom.resize(M+1);

		FOR (i, 1, (M-1)/2+1)
		{
			cin >> G >> C;
			if (G)
				strom[i].oper = AND;
			else
				strom[i].oper = OR;
			if (C)
				strom[i].changable = 1;
			else
				strom[i].changable = 0;
		}
		FOR (i, (M-1)/2+1, M+1)
		{
			cin >> C;
			strom[i].minchange[C] = 0;
			strom[i].minchange[!C] = M+1;
		}

		make(1);

		if (strom[1].minchange[V] > M)
			cout << "Case #" << icase+1 << ": IMPOSSIBLE" << endl;
		else
			cout << "Case #" << icase+1 << ": " << strom[1].minchange[V] << endl;
	}
	return 0;
}
