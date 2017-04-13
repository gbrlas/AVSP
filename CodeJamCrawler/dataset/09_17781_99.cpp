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

ifstream fi("A.in");
ofstream fo("A.out");
int main()
{
    int l, d, n;
    fi>>l>>d>>n;
    string s[5010];
    for (int i=0;i<d;i++) fi>>s[i];
    for (int i=0;i<n;i++)
    {
        string t;
        fi>>t;
        int ret=0;
        for (int j=0;j<d;j++)
        {
            int cur=0;
            bool kt=true;
            for (int k=0;k<t.size();k++)
            {
                if (t[k]!='(' && t[k]!=')' && t[k]!=s[j][cur])
                {
                              kt=false;
                              break;
                }
                if (t[k]==s[j][cur])
                {
                                    cur++;
                                    continue;
                }
                int h=k+1;
                bool got=false;
                while (t[h]!=')')
                {
                      if (t[h]==s[j][cur]) got=true;
                      h++;
                }
                k=h;
                cur++;
                if (!got)
                {
                         kt=false;
                         break;
                }
            }
            if (kt) ret++;
        }
        fo<<"Case #"<<(i+1)<<": "<<ret<<endl;
    }
}
