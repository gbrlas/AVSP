
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
string st1,c1,c2;
long t,q,tests,u1[20000],mp[200000];
int main(){
freopen("C:/input.txt","r",stdin);
freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
c1="zqejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
c2="qzour language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
for (int i=0;i<26;i++)
{
    char c=i+'a';
    q=0;
    while (c1[q]!=c)++q;
   // cout<<c<<" "<<q<<" "<<endl;
    if (q<c2.size()){mp[c2[q]]=q;u1[c2[q]]=1;}
}/*
for (int i=0;i<26;i++)
cout<<char(i+'a')<<" "<<mp[i+'a']<<endl;
for (int i=0;i<26;i++)
if (u1[i+'a']==0)cout<<char(i+'a')<<endl;
*/
cin>>tests;getline(cin,st1);
for (;tests;--tests)
{
    t++;
    getline(cin,st1);
    cout<<"Case #"<<t<<": ";
    for (int i=0;i<st1.size();i++)
    {
        q=0;
        while (c1[q]!=st1[i])++q;
        cout<<c2[q];
    }
    cout<<endl;
}
cin.get();cin.get();
return 0;}



