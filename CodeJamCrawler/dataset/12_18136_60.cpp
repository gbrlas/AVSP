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

int main()
{
    freopen("recycle.in","r",stdin);
    freopen("recycle2.out","w",stdout);
    int tc;
    cin>>tc;
    for (int test=1;test<=tc;test++)
    {
        cout<<"Case #"<<test<<": ";
        int a, b;
        cin>>a>>b;
        int ret=0;
        set<pair<int, int> > ss;
        for (int i=a;i<=b;i++)
        {
            int t=10;
            while (t<=i) t*=10;
            t/=10;
            int t1=10, t2=t;
            while (t1<i)
            {
                  int x=i%t1, y=i/t1, z=x*t2+y;
//                  cout<<i<<" "<<t1<<" "<<t2<<" "<<z<<endl;cin.get();
                  t1*=10;
                  t2/=10;
                  if (z>=a && z<=b && z!=i && z>=t && z>i)
                  {
//                    cout<<i<<" "<<z<<endl;cin.get();
                      ss.insert(make_pair(i,z));
                      ret++;
                  }
            }
        }
        cout<<ss.size()<<endl;
    }
}
