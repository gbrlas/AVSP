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

bool a[150][150], b[150][150];
int main()
{
    ifstream fi("bacteria.in");
    ofstream fo("bacteria.out");
    int t;
    fi>>t;
    for (int tc=1;tc<=t;tc++)
    {
        fo<<"Case #"<<tc<<": ";
        int r;
        fi>>r;
        memset(a,0,sizeof(a));
        for (int i=0;i<r;i++)
        {
            int x1, y1, x2, y2;
            fi>>x1>>y1>>x2>>y2;
            for (int x=x1;x<=x2;x++)
                for (int y=y1;y<=y2;y++) a[x][y]=1;
        }
        int ret=0;
        while (1)
        {
/*              for (int i=0;i<6;i++)
              {
                  for (int j=0;j<5;j++)
                      cout<<a[i][j];
                  cout<<endl;
              }cout<<endl;
              cin.get();*/
              ret++;
              bool kt=false;
              for (int i=0;i<=100;i++)
                  for (int j=0;j<=100;j++)
                      if (a[i][j]==0)
                      {
                                     if (i>=1 && j>=1 && a[i-1][j] && a[i][j-1])
                                     {
                                              b[i][j]=1;
                                              kt=true;
                                     }
                                     else b[i][j]=0;
                      }
                      else
                      {
                          if ((i<1 || !a[i-1][j]) && (j<1 || !a[i][j-1])) b[i][j]=0;
                          else
                          {
                              kt=true;
                              b[i][j]=1;
                          }
                      }
              if (!kt) break;
              memcpy(a,b,sizeof(a));
        }
        fo<<ret<<endl;
    }
}
