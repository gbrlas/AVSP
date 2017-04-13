#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n,rV;

int G[11111],C[11111],V[11111];
int f[2][11111];

int F(int v,int x){
    if(x<=(n-1)/2){
        int &res=f[v][x];
        if(res<0){
            int l=x*2,r=l+1;
            res=n+1;
            for(int lv=0;lv<2;++lv)
                for(int rv=0;rv<2;++rv)
                    for(int o=0;o<2;++o){
                        int xv;
                        if(o)xv=lv&&rv;
                        else xv=lv||rv;
                        if(xv==v && (C[x] || o==G[x]))
                            res<?=(o!=G[x])+F(lv,l)+F(rv,r);
                    }
        }
        return res;
    }
    return x<=n?(V[x]==v?0:n+1):n+1;
}

int main(){
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    int tc=0,T;
    for(cin>>T;tc++<T;){
        printf("Case #%d: ",tc);
        cin>>n>>rV;
        for(int i=0;i<(n-1)/2;++i)
            cin>>G[i+1]>>C[i+1];
        for(int i=(n-1)/2;i<n;++i)
            cin>>V[i+1];
        memset(f,-1,sizeof f);
        int res=F(rV,1);
        if(res<=n)cout<<res<<endl;
        else puts("IMPOSSIBLE");
    }
    return 0;
}
