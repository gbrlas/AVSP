#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define bl 1
#define wh 2
#define no 0
#define yes 1
#define inf 999999
struct man
    {
        int st,en;
    };

    man s[100000];

bool com(man a,man b )
{
    if(a.st==b.st)
        return a.en<b.en;

    return a.st<b.st;
}

bool coma(man a,man b )
{
    if(a.en==b.en)
        return a.st<b.st;

    return a.en<b.en;
}


using namespace std;

vector<string>v[10000];
int test,n,m,i,j,k,c1,c2,sum,cas=0;
string a,x,b;

int main()
{
    freopen("a_l.in","r",stdin);
    freopen("a_l.out","w",stdout);

    int test,n,i,j,cont,cas=0;

    cin>>test;

    while(test--)
    {
        cont=0;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>s[i].st>>s[i].en;
        sort(s,s+n,com);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
                if(s[i].en>=s[j].en)
                    ++cont;
        }
        printf("Case #%d: %d\n",++cas,cont);
    }

    return 0;
}
