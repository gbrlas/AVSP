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

int n, m, ret;
vector<int> room;
vector<int> col;
int r[10];
bool got;

void go(int pos, int c)
{
     if (got) return;
     if (pos==n)
     {
                got=true;
                for (int i=0;i<room.size();i++)
                {
                    int mask=0;
                    for (int j=0;j<n;j++)
                        if ((room[i]&(1<<j))) mask|=(1<<r[j]);
                    if (mask<(1<<ret)-1) got=false;
                }
                return;
     }
     for (int i=c, t=0;t<ret;i++, t++)
     {
         r[pos]=i%ret;
         go(pos+1,(i+1)%ret);
         if (got) break;
     }
}
int main()
{
    ifstream fi("kittens.in");
    ofstream fo("kittens.out");
    int nt;
    fi>>nt;
    for (int tc=1;tc<=nt;tc++)
    {
        fo<<"Case #"<<tc<<": ";
        fi>>n>>m;
        int a[10], b[10];
        bool con[10][10];
        for (int i=0;i<m;i++) fi>>a[i];
        for (int i=0;i<m;i++) fi>>b[i];
        memset(con,0,sizeof(con));
        for (int i=0;i<m;i++)
        {
            a[i]--;
            b[i]--;
            con[a[i]][b[i]]=1;
            con[b[i]][a[i]]=1;
        }
        for (int i=0;i<n-1;i++)
        {
            con[i][i+1]=1;
            con[i+1][i]=1;
        }
        con[n-1][0]=1;
        con[0][n-1]=1;
        room.clear();
        ret=-1;
        for (int i=1;i<(1<<n);i++)
        {
            int cnt=0;
            int deg[10];
            memset(deg,0,sizeof(deg));
            for (int j=0;j<n;j++)
                for (int k=0;k<n;k++)
                    if ((i&(1<<j)) && (i&(1<<k)) && con[j][k])
                    {
                                   cnt++;
                                   deg[j]++;
                                   deg[k]++;
                    }
            cnt/=2;
            if (cnt==__builtin_popcount(i))
            {
                                           int k;
                                           for (k=0;k<n;k++)
                                               if ((i&(1<<k)) && deg[k]!=4) break;
                                           if (k<n) continue;
                                           room.push_back(i);
                                           if (ret==-1 || ret>cnt) ret=cnt;
            }
        }
        col.clear();
        for (int i=0;i<room.size();i++) col.push_back(0);
        memset(r,-1,sizeof(r));
        while (true)
        {
              got=false;
              go(0,0);
              if (got) break;
              ret--;
        }
        fo<<ret<<endl;
        for (int i=0;i<n;i++)
            fo<<r[i]+1<<" ";
        fo<<endl;
    }
}
