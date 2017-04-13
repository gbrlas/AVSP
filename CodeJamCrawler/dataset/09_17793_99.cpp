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

ifstream fi("C.in");
ofstream fo("C.out");

string ref="welcome to code jam";
int a[510][20];
int main()
{
    int t;
    fi>>t;
    string s;
    getline(fi,s);
    for (int tt=1;tt<=t;tt++)
    {
        getline(fi,s);
        memset(a,0,sizeof(a));
        int n=s.size(), m=ref.size();
        if (s[n-1]==ref[m-1]) a[n-1][m-1]=1;
        for (int i=n-2;i>=0;i--)
        {
            a[i][m-1]=a[i+1][m-1];
            if (s[i]==ref[m-1]) a[i][m-1]++;
        }
        for (int i=n-2;i>=0;i--)
            for (int j=m-2;j>=0;j--)
            {
                a[i][j]+=a[i+1][j];
                a[i][j]%=10000;
                if (s[i]==ref[j] && a[i+1][j+1]>0)
                {
                                 a[i][j]+=a[i+1][j+1];
                                 a[i][j]%=10000;
                }
            }
        string zero="";
        int ret=a[0][0];
        if (ret<10) zero="000";
        else if (ret<100) zero="00";
        else if (ret<1000) zero="0";
        fo<<"Case #"<<tt<<": "<<zero<<ret<<endl;
    }
}
