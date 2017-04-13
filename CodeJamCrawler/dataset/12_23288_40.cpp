
//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-8
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
set <long> cn[2100000];
long p,a,q,sz,w,ans,b,tests,pw[2000];
int main(){
freopen("C:/input.txt","r",stdin);
freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//c1="zqejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
//c2="qzour language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
cin>>tests;
for (;tests;--tests)
{
p++;
cin>>a>>b;
pw[1]=10;
pw[0]=1;
for (int i=2;i<=10;i++)pw[i]=pw[i-1]*10;
for (int i=a;i<=b;i++)
cn[i].erase(cn[i].begin(),cn[i].end());
for (int i=a;i<=b;i++)
{
    q=i;
    sz=0;
    while (q){sz++;q/=10;}
    q=i;
    for (int j=1;j<=10;j++)
    {
        w=q%10;q=q/10+pw[sz-1]*w;
        if (q>i&&q<=b)cn[i].insert(q);
    }    
}
ans=0;
for (int i=a;i<=b;i++)
ans+=cn[i].size();
cout<<"Case #"<<p<<": ";
cout<<ans<<endl;
}
cin.get();cin.get();
return 0;}



