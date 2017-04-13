#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
using namespace std; 
#define ALL(a) (a).begin(), (a).end() 
#define SZ(a) (int)(a).size() 
#define FOR(i,s,n) for(int i=(s);i<(n);++i) 
#define REP(i,n) FOR(i,0,(n)) 
#define PB(x) push_back((x)) 
#define CLR(a,v) memset((a),(v),sizeof((a))) 
typedef long long ll; 

char res[55][55];
int R, C, M;

void print()
{
    REP(i,R)
    {
        res[i][C]='\0';
        printf("%s\n",res[i]);
    }
}

bool trivial()
{
    CLR(res, '*');
    int tot = R*C;
    int free = tot - M;
    if (tot == M)
    {
        cout << "Impossible\n";
        return true;
    }
    if (free == 1)
    {
        res[0][0]='c';
        print();
        return true;
    }
    if(R==1)
    {
        REP(i,free)res[0][i]='.';
        res[0][0]='c';
        print();
        return true;
    }
    if(C==1)
    {
        REP(i,free)res[i][0]='.';
        res[0][0]='c';
        print();
        return true;
    }
    if (free == 2 || free == 3 || free == 5)
    {
        cout << "Impossible\n";
        return true;
    }
    if(M==0)
    {
        CLR(res,'.');
        res[0][0]='c';
        print();
        return true;
    }
    return false;
}

bool f(int x, int y, int free)
{
    if (res[x][y]=='0')
        return false;

    int newFree = 0;
    FOR(dx,-1,2)FOR(dy,-1,2)
    {
        int xx=x+dx, yy=y+dy;
        if(xx<0||yy<0||xx>=R||yy>=C)
            continue;
        if(res[xx][yy]=='*')
            ++newFree;
    }
    if(newFree>free)
        return false;

    char old[55][55];
    memcpy(old, res, sizeof(res));

    FOR(dx,-1,2)FOR(dy,-1,2)
    {
        int xx=x+dx, yy=y+dy;
        if(xx<0||yy<0||xx>=R||yy>=C)
            continue;
        if(res[xx][yy]=='*')
            res[xx][yy]='.';
    }
    if (newFree == free)
        return true;

    res[x][y] = '0';
    free -= newFree;

    FOR(dx,-1,2)FOR(dy,-1,2)
    {
        int xx=x+dx, yy=y+dy;
        if(xx<0||yy<0||xx>=R||yy>=C)
            continue;
        if(res[xx][yy]=='.' && f(xx, yy, free))
        {
            return true;
        }
    }

    memcpy(res, old, sizeof(res));
    return false;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int T;
    scanf("%d", &T);

    FOR(t,1,T+1)
    {
        cout << "Case #" << t << ":\n";
        cin >> R >> C >> M;

        if (trivial())
            continue;

        REP(x,R)REP(y,C)
        {
            CLR(res, '*');
            if (f(x, y, R*C-M))
            {
                REP(i,R)REP(j,C)if(res[i][j]=='0')res[i][j]='.';
                res[x][y]='c';
                print();
                goto nxt;
            }
        }
        cout << "Impossible\n";
    nxt:
        T=T;
    }

    return 0;
}
