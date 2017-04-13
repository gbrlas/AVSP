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

int gcd(int a, int b)
{
    if (b==0) return a;
    if (a<b) return gcd(b,a);
    return gcd(b,a%b);
}
int main()
{
    ifstream fi("FreeCell Statistics.in");
    ofstream fo("FreeCell Statistics.out");
    int testcase;
    fi>>testcase;
    for (int tc=1;tc<=testcase;tc++)
    {
        fo<<"Case #"<<tc<<": ";
        long long n;
        int p1, p2, x, y;
        fi>>n>>p1>>p2;
        bool kt=false;
        if (n>=100) kt=true;
        else
        {
            for (int i=1;i<=n;i++)
            {
                int j=(int) p1/100.*i;
                if (j*100==i*p1)
                {
                                x=j;
                                y=i;
                                kt=true;
                                break;
                }
            }
        }
        if (kt)
        {
               if (n>=100)
               {
                          x=p1;
                          y=100;
               }
               int k=gcd(100*x,p2);
               if (k!=0 && abs(p2*y-100*x)%k!=0) kt=false;
               if (100*x<=p2 && p2*y>100*x) kt=false;
               else if ((p1!=100 && p2==100) || (p1!=0 && p2==0)) kt=false;
        }
        if (kt) fo<<"Possible"<<endl;
        else fo<<"Broken"<<endl;
    }
}
