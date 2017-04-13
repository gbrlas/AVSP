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

struct Trip
{
    int d;
    int a;
    int sp; // 0: A, 1 : B
    bool operator <(Trip& t)
    {
        return d < t.d;
    }
};

struct Train
{
    int sp; //0 : A, 1 : B
    static int T;
    Trip* t;
    void Update(int time)
    {
        if (t == NULL)
        {
            return;
        }
        if (t->a + T <= time)
        {
            t = NULL;
        }
    }
};
int Train::T = 0;

void One(int idx)
{
    Trip p[256];
 //   int T;
    in >> Train::T;
    int NA, NB;
    in >> NA;
    in >> NB;
    for (int i = 0; i< NA; ++i)
    {
        int dh, dm, ah, am;
        scanf("%d:%d %d:%d", &dh, &dm, &ah, &am);
        p[i].d = dh * 60 + dm;
        p[i].a = ah * 60 + am;
        p[i].sp = 0;
    }
    for (int i = 0; i< NB; ++i)
    {
        int dh, dm, ah, am;
        scanf("%d:%d %d:%d", &dh, &dm, &ah, &am);
        p[i + NA].d = dh * 60 + dm;
        p[i + NA].a = ah * 60 + am;
        p[i + NA].sp = 1;
    }

    int N = NA + NB;
    sort(p, p + N);

    Train train[256];
    int c = 0;
    int ca = 0;
    int cb = 0;

    for (int i = 0; i < N; ++i)
    {
        //find a train
        int time = p[i].d;
        int k = -1;
        for (int j = 0; j < c; ++j)
        {
            train[j].Update(time);
            if (train[j].t == NULL && train[j].sp == p[i].sp)
            {
                k = j;
                break;
            }
        }
        if (k == -1)
        {
            train[c].sp = p[i].sp;
            k = c;
            if (p[i].sp == 0)
            {
                ca++;
            }
            else
            {
                cb++;
            }
            ++c;
        }
        train[k].t = &p[i];
        train[k].sp = 1 - train[k].sp;
    }

OP:
    out << "Case #" << idx << ": ";
    out << ca << " " << cb;
    out << endl;
}

void SolveN()
{
	int n;
	in >> n;
	for (int i = 0; i < n; ++i)
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