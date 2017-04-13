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
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long long tests,ans,q,ts,n,d[500000],l[500000],D,bst[500000];
int main(){
freopen("C:/input.txt","r",stdin);
freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>tests;
for (;tests;--tests)
{
    ts++;
    cout<<"Case #"<<ts<<": ";
    cin>>n;
    for (int i=0;i<n;i++)
    cin>>d[i]>>l[i];
    cin>>D;
    bst[0]=d[0];
    for (int i=1;i<=n;i++)bst[i]=0;
    for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++)
    {
        if (bst[i]>=d[j]-d[i])
        {
                              q=d[j]-d[i];
                              q=min(q,l[j]);
                              if (q>bst[j])bst[j]=q;
        }
    }
    ans=0;
    for (int i=0;i<n;i++)
    if (D-bst[i]<=d[i])ans=1;
    if (ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
}

cin.get();cin.get();
return 0;}

















