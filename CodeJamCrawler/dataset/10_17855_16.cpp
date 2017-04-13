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

int a[2000], b[2000];
int ret;

void solve(int left, int right)
{
     bool kt=false;
     for (int i=left;i<right;i++)
         if (a[i]>0) kt=true;
     if (!kt) return;
     ret++;
     for (int i=left;i<right;i++)
         a[i]--;
     solve(left,(left+right+1)/2);
     solve((left+right+1)/2,right);
}
int main()
{
    ifstream fi("world cup 2010.in");
    ofstream fo("world cup 2010.out");
    int t;
    fi>>t;
    for (int tc=1;tc<=t;tc++)
    {
        fo<<"Case #"<<tc<<": ";
        int n;
        fi>>n;
        for (int i=0;i<(1<<n);i++)
        {
            fi>>a[i];
            a[i]=n-a[i];
        }
        int k=n-1, lol;
        while (k>=0)
        {
              for (int i=0;i<(1<<k);i++)
                  fi>>lol;
              k--;
        }
        ret=0;
        solve(0,(1<<n));
        fo<<ret<<endl;
    }
}
