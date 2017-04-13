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

map<pair<int,int>, int> mp;
int main()
{
    freopen("swing.in","r",stdin);
    freopen("swing.out","w",stdout);
    int tc;
    cin>>tc;
    for (int tt=1;tt<=tc;tt++)
    {
        cout<<"Case #"<<tt<<": ";
        int n, D;
        int d[10010], l[10010];
        cin>>n;
        mp.clear();
        for (int i=0;i<n;i++)
            cin>>d[i]>>l[i];
        cin>>D;
        queue< pair<int, int> > q;
        q.push(make_pair(0,0));
        string ret="NO";
        for (int i=0;i<n;i++)
        while (!q.empty())
        {
              pair<int, int> p=q.front();
              int fr=p.first, pos=p.second;
              q.pop();
              if (mp[p]==1) continue;
              mp[p]=1;
              if (d[pos]+min(d[pos]-fr,l[pos])>=D)
              {
                                      ret="YES";
                                      break;
              }
              int i=pos+1;
              for (i=pos+1;i<n;i++)
                  if (d[pos]+min(l[pos],d[pos]-fr)>=d[i])q.push(make_pair(d[pos],i));
                  else break;
//              if (i==pos+1) break;q.push(make_pair(d[pos],i-1));
        }
        cout<<ret<<endl;
    }
}
