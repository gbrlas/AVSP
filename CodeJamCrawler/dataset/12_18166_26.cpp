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

int n, w, l;
vector<LL> r;

int get(int k)
{
    LL x1=rand(), x2=rand(), x3=rand();
    LL x=(((x1*x2)%k)*x3)%k;
    return x;
}
int main()
{
    freopen("aerobics.in","r",stdin);freopen("aerobics.out","w",stdout);
    srand(time(NULL));
    int tc;
    cin>>tc;
    for (int tt=1;tt<=tc;tt++)
    {
        cout<<"Case #"<<tt<<": ";
        cin>>n>>w>>l;
        r.clear();
        for (int i=0;i<n;i++)
        {
            int t;
            cin>>t;
            r.push_back(t);
        }
        LL x[1050], y[1050];
        while (1)
        {
              int i=0;
              for (i=0;i<n;i++)
              {
                  bool can;
                  for (int times=0;times<5000;times++)
                  {
                      int a=get(w), b=get(l);
//                      cout<<"    "<<i<<":   "<<a<<" "<<b;cin.get();
                      can=1;
                      for (int j=0;j<i;j++)
                      {
                          LL t1=(a-x[j])*(a-x[j])+(b-y[j])*(b-y[j]);
                          LL t2=(r[j]+r[i])*(r[j]+r[i]);
                          if (t1<t2)
                          {
                                                                                      can=0;
                                                                                      break;
                          }
                      }
                      if (can)
                      {
                              x[i]=a;
                              y[i]=b;
                              break;
                      }
                  }
                  if (!can) break;
              }
              if (i>=n) break;
        }
        for (int i=0;i<n-1;i++) cout<<x[i]<<" "<<y[i]<<" ";
        cout<<x[n-1]<<" "<<y[n-1]<<endl;
    }
}
