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
    freopen("airport.in","rt",stdin);
    freopen("airport.out","wt",stdout);
    int nt;
    cin>>nt;
    for (int tc=1;tc<=nt;tc++)
    {
        cout<<"Case #"<<tc<<": ";
        int len, s, r, t, n;
        cin>>len>>s>>r>>t>>n;
        int st[1010], en[1010], v[1010];
        vector<int> cv;
        for (int i=0;i<len;i++) cv.push_back(0);
        for (int i=0;i<n;i++)
        {
            cin>>st[i]>>en[i]>>v[i];
            for (int j=st[i];j<en[i];j++)
                cv[j]=v[i];
        }
        sort(cv.begin(),cv.end());
        double tm=0, ret=0;
        for (int i=0;i<len;i++)
        {
            if (tm>=t)
            {
/*                      int j=i;
                      while (j<len && cv[j]==cv[i]) j++;
                      ret+=(j-i)*1./(cv[i]+s);
                      i=j-1;*/
                      ret+=1./(cv[i]+s);
                      continue;
            }
            double k=1./(cv[i]+r);
            if (tm+k<=t)
            {
                       tm+=k;
                       ret+=k;
            }
            else
            {
                double ex=t-tm;
                ret+=ex+(1.-(cv[i]+r)*ex)/(cv[i]+s);
                tm+=k;
            }
        }
        printf("%.9lf\n",ret);
    }
}
