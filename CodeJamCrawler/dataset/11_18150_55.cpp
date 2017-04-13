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
    ifstream fi("rpi.in");
    ofstream fo("rpi.out");
    int nt;
    fi>>nt;
    for (int tc=1;tc<=nt;tc++)
    {
        fo<<"Case #"<<tc<<": "<<endl;
        int n;
        fi>>n;
        int win[110], lose[110];
        double p[110], owp[110];
        char a[110][110];
        for (int i=0;i<n;i++)
        {
            int w=0, l=0;
            char ch;
            for (int j=0;j<n;j++)
            {
                fi>>ch;
                a[i][j]=ch;
                if (ch=='0') l++;
                else if (ch=='1') w++;
            }
            win[i]=w;
            lose[i]=l;
            p[i]=w*1./(w+l);
        }
        for (int i=0;i<n;i++)
        {
            owp[i]=0.;
            for (int j=0;j<n;j++)
                if (a[i][j]!='.')
                {
                                 if (a[j][i]=='0') owp[i]+=win[j]*1./(win[j]+lose[j]-1);
                                 else owp[i]+=(win[j]-1)*1./(win[j]+lose[j]-1);
                }
            owp[i]/=(win[i]+lose[i])*1.;
        }
        for (int i=0;i<n;i++)
        {
            double oowp=0.;
            for (int j=0;j<n;j++)
                if (a[i][j]!='.') oowp+=owp[j];
            oowp/=(win[i]+lose[i])*1.;
            double rpi=0.25*p[i]+0.5*owp[i]+0.25*oowp;
            fo<<rpi<<endl;
        }
    }
}
