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
    freopen("googler.in","r",stdin);
    freopen("googler.out","w",stdout);
    int tc;
    cin>>tc;
    for (int tcc=1;tcc<=tc;tcc++)
    {
        cout<<"Case #"<<tcc<<": ";
        int n, s, p, ret=0;
        cin>>n>>s>>p;
        for (int i=0;i<n;i++)
        {
            int k;
            cin>>k;
            int t=k/3;
            if (k%3==0)
            {
                       if (t>=p) ret++;
                       else if (s>0 && t+1>=p && t>0) s--, ret++;
            }
            else if (k%3==1)
            {
                 if (t+1>=p) ret++;
            }
            else
            {
                if (t+1>=p) ret++;
                else if (s>0 && t+2>=p) s--, ret++;
            }
        }
        cout<<ret<<endl;
    }
}
