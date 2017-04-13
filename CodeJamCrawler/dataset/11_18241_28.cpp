#define inputLevel 1

#if inputLevel==0
#define PATH_INP	"test.in"
#define PATH_OUT	"test.out"

#elif inputLevel==1
#define PATH_INP	"A-small-attempt2.in"
#define PATH_OUT	"A-small-attempt2.out"

#elif inputLevel==2
#define PATH_INP	"A-large.in"
#define PATH_OUT	"A-large.out"

#elif inputLevel==3
#define PATH_INP	"A-small-practice.in"
#define PATH_OUT	"A-small-practice.out"
#endif

#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define fr(i,a,n)		for(int i=(int)(a);i<(int)(n);i++)
#define loop(i,x)		fr(i,0,x)
#define getloop(i,x)	x=geti(); fr(i,0,x)

typedef long long int	int64;
inline int geti()
{
    int n;
    scanf("%d",&n);
    return n;
}

int R,C,x[50][50];

bool solve() // for each case
{
    bool ok=true;
    scanf("%d%d\n",&R,&C);

    loop(r,R)
    {
        loop(c,C)
        {
            char ch;
            scanf("%c",&ch);

            if(ch=='.')
            {
                x[r][c]=0;
            }
            else
            {
                bool c1 = c==0 || x[r][c-1]%2==0;
                bool r1 = r==0 || x[r-1][c]>2 || x[r-1][c]==0;
                x[r][c] = (r1?0:2)+(c1?1:2);
            }

            switch(x[r][c])
            {
            case 0:
                if(r>0) // up
                    if(x[r-1][c]==1 || x[r-1][c]==2) ok=false;
                if(c>0) // left
                    if(x[r][c-1]==1 || x[r][c-1]==3) ok=false;
                break;
            case 1:
                if(r>0) // up
                    if(x[r-1][c]==1 || x[r-1][c]==2) ok=false;
                if(c>0) // left
                    if(x[r][c-1]==1 || x[r][c-1]==3) ok=false;
                break;
            case 2:
                if(r>0) // up
                    if(x[r-1][c]==1 || x[r-1][c]==2) ok=false;
                if(c>0) // left
                    if(x[r][c-1]!=1) ok=false;
                break;
            case 3:
                if(r>0)
                    if(x[r-1][c]!=1) ok=false;
                if(c>0)
                    if(x[r][c-1]==1 || x[r][c-1]==3) ok=false;
                break;
            case 4:
                if(r>0)
                    if(x[r-1][c]!=2) ok=false;
                if(c>0)
                    if(x[r][c-1]!=3) ok=false;
                break;
            }
            if(r==R-1 && (x[r][c]==1 || x[r][c]==2)) ok=false;
        }
        if(x[r][C-1]%2) ok=false;

        scanf("\n");
    }
    return ok;
}

int main()
{
    freopen(PATH_INP, "r", stdin);
    freopen(PATH_OUT, "w", stdout);

    int T;
    getloop(Case,T)
    {
        cout << "Case #" << Case+1 << ": " << endl;
        if(!solve())
            cout<< "Impossible" << endl;
        else
        {
            loop(r,R)
            {
                loop(c,C)
                {
                    printf(x[r][c]==0 ? "." : x[r][c]/2!=1 ? "/":"\\");
                }
                cout << endl;
            }
        }
    }

    return 0;
}
