#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <math.h>
#include <sstream>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
#define sz
using namespace std;
int main ()
{
    freopen("test.txt","r",stdin);
    freopen("out.txt","w",stdout);
    string likha;
     stringstream convert;
    ll i,j,test,t,a,b,c,d,e,f,g;
    bool not_flag;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        c=0;
        cin>>f>>g;
        a=sqrt(f);
        b=sqrt(g);
        if((a*a)!=f)
        a++;
        for(i=a;i<=b;i++)
        {
           // cout<<"jnd "<<i<<endl;
            not_flag=0;
            convert.str("");
            convert<<i;
            likha=convert.str();
          //  cout<<likha<<endl;
            d=likha.size()/2;
            e=likha.size()-1;
            for(j=0;j<d;j++)
            {
                if(likha[j]!=likha[e-j])
                {
                    not_flag=1;
                    break;
                }
            }
            if(not_flag)
            continue;
            j=pow(i,2);
            convert.str("");
            convert<<j;
            likha=convert.str();
          //  cout<<likha<<endl;
            d=likha.size()/2;
            e=likha.size()-1;
            for(j=0;j<d;j++)
            {
                if(likha[j]!=likha[e-j])
                {
                    not_flag=1;
                    break;
                }
            }
            if(!not_flag)
            c++;
        }
        printf("Case #%lld: %lld\n",t,c);
    }
    return 0;
}

