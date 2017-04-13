#line 3 "main.cpp"
#include  "iostream" 
#include  "vector"
#include  "string"
#include  "string.h"
#include  "algorithm" 
#include  "sstream"
#include  "set"
#include  "map"
#include  "queue"
#include  "deque"
#include  "stack"
#include "list"
#include  "bitset"
#include  "cstdio"
#include  "assert.h"
#include  "cmath"
#include  "cstdlib"
#include  "ctime"
#include  "cfloat"
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define INF 1<<28
using namespace std;

long long hgcd(long long a, long long b)
{
        if(b == 0)
                return a;
        else
                return hgcd(b, a % b);
}

int main()
{
    int t;
  
    cin>>t;
     long long n,pd,pg;
    for(int ii=1; ii<=t; ii++)
    {
      
        cin>>n>>pd>>pg;
             
        cout<<"Case #"<<ii<<": ";
    if (pg==0 && pd>0)
    {
            cout<<"Broken\n";
        continue;
        }
        if (pg==100 && pd!=100)
    {
            cout<<"Broken\n";
            continue;
        }
        if (pd == 100)
    {
            cout<<"Possible\n";
            continue;
        }
      
        if (pd<100 && pg<100)
    {
            long long gcd=hgcd(pd,100);
            pd/=gcd;
            long long resto=100/gcd;
            if(resto<=n && resto>pd ) cout<<"Possible\n";
            else cout<<"Broken\n";
        }
    }
  
    return 0;
}
