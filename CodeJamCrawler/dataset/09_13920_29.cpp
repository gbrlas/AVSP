#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

typedef long long ll;

#define NMAX 15

int n, m;
char a[NMAX][NMAX];

struct Point
{
    int x, y;
    Point() {};
    Point(int _x, int _y)
    {
        x = _x; y = _y;
    }

};

inline bool operator<(const Point& p1, const Point& p2)
{
    if (p1.x != p2.x) return p1.x < p2.x;
    return p1.y < p2.y;
}

inline bool operator==(const Point& p1,const Point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

typedef vector<Point> Pos;

Pos st, fin;
map<Pos, int> d;
map<Pos, bool> stable;
queue<Pos> q;


int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool canPush(Pos u, int i, int k)
{
    Point p1(u[i].x + dx[k], u[i].y + dy[k]);
    if (!valid(p1.x, p1.y) || a[p1.x][p1.y] == '#') return false;
    Point p2(u[i].x - dx[k], u[i].y - dy[k]);
    if (!valid(p2.x, p2.y) || a[p2.x][p2.y] == '#') return false;

    forv(j, u)
    {
        if (u[j] == p1 || u[j] == p2) return false;
    }

    return true;
}

Pos Push(Pos u, int i, int k)
{
    Pos v = u;
    v[i].x += dx[k];
    v[i].y += dy[k];
    sort(all(v));
    return v;
}


int dist(const Point& p1, const Point& p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int leader[5];
int comp;

int up(int x)
{
    if (leader[x] != x) leader[x] = up(leader[x]);
    return leader[x];
}
void join(int x, int y)
{
    x = up(x); y = up(y);
    if (x == y) return;

    comp--;
    if (rand() & 1)
    {
       leader[x] = y;
    }
    else
    {
        leader[y] = x;
    }
}
bool isStable(Pos v)
{
    forv(i, v) leader[i] = i;
    comp = (int)v.size();

    forv(i, v)
    {
        forn(j, i)
        {
            if (dist(v[i], v[j]) == 1)
            {
                join(i, j);            
                if (comp == 1) return true;
            }
        }
    }

    return (comp == 1); 
}

void solve(int test)
{
    printf("Case #%d: ", test);
    
    cerr << test << endl;
    scanf("%d %d\n", &n, &m);
    forn(i, n)
    {
        forn(j, m)
        {
            scanf("%c", &a[i][j]);
        }
        scanf("\n");
    }

    d.clear(); stable.clear();
    while (!q.empty()) q.pop();

    st.clear(); fin.clear();
    forn(i, n)
    {
        forn(j, m)
        {
            if (a[i][j] == 'o' || a[i][j] == 'w') st.pb(Point(i, j));
            if (a[i][j] == 'x' || a[i][j] == 'w') fin.pb(Point(i, j));
        }
    }

    q.push(st);
    d[st] = 0;
    stable[st] = true;

    Pos u, v;
    while (!q.empty())
    {
        u = q.front(); q.pop();

        forv(i, u)
        {
            forn(k, 4)
            {
                if (!canPush(u, i, k)) continue;
                v = Push(u, i, k);

                if (d.count(v) != 0) continue;
                bool flag = isStable(v);
                if (!stable[u] && !flag) continue;

                d[v] = d[u] + 1;
                if (v == fin)
                {
                    printf("%d\n", d[v]);
                    return;
                }
                stable[v] = flag;
                q.push(v);
            }
        }
    }

    if (d.count(fin) == 0) printf("-1\n"); else printf("%d\n", d[fin]);
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc)
    {
        solve(it + 1);
    }
    return 0;
}