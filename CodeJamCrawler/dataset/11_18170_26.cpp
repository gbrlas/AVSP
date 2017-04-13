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

int a[15][15];
double eps=1e-9;

bool check(int x, int y, int k)
{
//     cout<<x<<" "<<y<<" "<<k;cin.get();
     double cx=x+k/2., cy=y+k/2., rx=0, ry=0;
     for (int i=x;i<x+k;i++)
         for (int j=y;j<y+k;j++)
         {
             if (i==x && j==y) continue;
             if (i==x && j==y+k-1) continue;
             if (i==x+k-1 && j==y) continue;
             if (i==x+k-1 && j==y+k-1) continue;
             rx+=a[i][j]*1.*(cx-i-.5);
             ry+=a[i][j]*1.*(cy-j-.5);
//             cout<<(double)coy(i)<<" "<<(double)cox(j)<<" "<<a[i][j];cin.get();
         }
//cout<<rx<<" "<<ry;cin.get();
     if (abs(rx)<eps && abs(ry)<eps) return true;
     return false;
}
int main()
{
    ifstream fi("blade.in");
    ofstream fo("blade.out");
    int nt;
    fi>>nt;
    for (int tc=1;tc<=nt;tc++)
    {
        fo<<"Case #"<<tc<<": ";
        int r, c, d;
        fi>>r>>c>>d;
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++)
            {
                char ch;
                fi>>ch;
                a[i][j]=d+(ch-'0');
            }
        int ret=-1;
        for (int k=3;k<=min(r,c);k++)
        {
            bool kt=false;
            for (int i=0;i<=r-k;i++)
                for (int j=0;j<=c-k;j++)
                    if (!kt && check(i,j,k)) kt=true;
            if (kt) ret=k;
        }
        if (ret==-1) fo<<"IMPOSSIBLE"<<endl;
        else fo<<ret<<endl;
    }
}
