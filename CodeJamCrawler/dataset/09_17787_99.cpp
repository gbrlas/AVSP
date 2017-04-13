#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <ctime>
#include <queue>
#include <fstream>

using namespace std;
typedef long long LL;

ifstream fi("B.in");
ofstream fo("B.out");

int h, w;
int a[110][110];
char r[110][110];
char next, cur;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
//int dy[4]={0,1,-1,0};

bool check(int x, int y)
{
     if (x>=0 && x<h && y>=0 && y<w) return true;
     return false;
}
void go1(int x, int y)
{
     cur=r[x][y];
     if (cur!=' ') return;
     int lx=-1, ly=-1, best=100000;
     for (int k=0;k<4;k++)
     {
         int i=x+dx[k], j=y+dy[k];
         if (!check(i,j)) continue;
         if (a[i][j]<best)
         {
                          best=a[i][j];
                          lx=i;
                          ly=j;
         }
     }
     if (best>=a[x][y]) return;
     go1(lx,ly);
}
void go2(int x, int y)
{
     if (r[x][y]!=' ') return;
     r[x][y]=cur;
     int lx=-1, ly=-1, best=100000;
     for (int k=0;k<4;k++)
     {
         int i=x+dx[k], j=y+dy[k];
         if (!check(i,j)) continue;
         if (a[i][j]<best)
         {
                          best=a[i][j];
                          lx=i;
                          ly=j;
         }
     }
     if (best>=a[x][y]) return;
     go2(lx,ly);
}
int main()
{
    int t;
    fi>>t;
    for (int tt=1;tt<=t;tt++)
    {
        fi>>h>>w;
        for (int i=0;i<h;i++)
            for (int j=0;j<w;j++) fi>>a[i][j];
        memset(r,' ',sizeof(r));
        next='a';
        for (int i=0;i<h;i++)
            for (int j=0;j<w;j++)
            {
                if (r[i][j]!=' ') continue;
                cur=' ';
                go1(i,j);
                if (cur==' ') cur=next++;
                go2(i,j);
            }
        fo<<"Case #"<<tt<<":"<<endl;
        for (int i=0;i<h;i++)
        {
            for (int j=0;j<w;j++)
                fo<<r[i][j]<<" ";
            fo<<endl;
        }
    }
}
