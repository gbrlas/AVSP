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

char a[55][55];
int dx[8]={-1,0,1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main()
{
    FILE *fi=fopen("rotate.in","r");//, *fo=fopen("rotate.out","w");
    ofstream fo("rotate.out");
    int t;
    fscanf(fi,"%d",&t);
    for (int tt=1;tt<=t;tt++)
    {
        fo<<"Case #"<<tt<<": ";
//        fprintf(fo,"Case #&d: ",tt);
        int n, k;
        fscanf(fi,"%d %d\n",&n,&k);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
                fscanf(fi,"%c",&a[i][j]);
            fscanf(fi,"%c",&a[54][54]);
        }
        for (int i=0;i<n;i++)
        {
            int j=n-1;
            queue<int> x, y;
            while (j>=0)
            {
                  if (a[i][j]=='.')
                  {
                                   x.push(i);
                                   y.push(j);
                  }
                  else if (!x.empty())
                  {
                       int xx=x.front(), yy=y.front();
                       x.pop();
                       y.pop();
                       a[xx][yy]=a[i][j];
                       a[i][j]='.';
                       x.push(i);
                       y.push(j);
                  }
                  j--;
            }
        }
        bool red=0, blue=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (a[i][j]!='.')
                   for (int h=0;h<8;h++)
                   {
                       int x=i, y=j, d=0;
                       while (x<n && x>=0 && y<n && y>=0 && a[x][y]==a[i][j])
                       {
                             x+=dx[h];
                             y+=dy[h];
                             d++;
                       }
                       if (d>=k)
                       {
                                if (a[i][j]=='R') red=1;
                                else blue=1;
                       }
                   }
        string ret="Neither";
        if (red && blue) ret="Both";
        else if (red) ret="Red";
        else if (blue) ret="Blue";
        fo<<ret<<endl;
//        fprintf(fo,"%s\n",ret);
    }
}
