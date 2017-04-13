#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <ctype.h>
using namespace std;

typedef long long LL;
typedef long double LD;
const LL inf=1000002013,N=1000+5;
const double eps=1e-10;

pair<pair<LL,LL>,LL> a[N<<1];
pair<LL,LL> b[N<<1];

LL n,m;
LL calc(LL x,LL y,LL z){
    y-=x;
    LL ret=((m+m-y+1)%inf*y*z/2)%inf;
    //cout<<x<<","<<y<<","<<z<<","<<ret<<endl;
    return ret;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int total;
    cin>>total;
    for (int t=1;t<=total;t++){
        LL x,y,z;
        LL tmp,ans;
        cin>>m>>n;
        tmp=ans=0;
        for (int i=0;i<n;i++){
            cin>>x>>y>>z;

            tmp+=calc(x,y,z);
            if (tmp>=inf)tmp-=inf;

            a[i]=make_pair(make_pair(x,0),z);
            a[n+i]=make_pair(make_pair(y,1),z);
        }
        sort(a,a+n+n);
        int top=0;
        for (int i=0;i<n+n;i++){
            if (a[i].first.second){
                top--;
                z=min(a[i].second,b[top].second);
                ans+=calc(b[top].first,a[i].first.first,z);
                if (ans>=inf)ans-=inf;
                a[i].second-=z;
                b[top].second-=z;
                if (b[top].second)top+=1;
                if (a[i].second)i-=1;
            }else {
                b[top++]=make_pair(a[i].first.first,a[i].second);
            }
        }
        ans=(tmp-ans+inf)%inf;
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}
