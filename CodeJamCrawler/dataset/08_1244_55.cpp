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

int k;
string s;

int d[16][16],dd[16][16];
int f[16][1<<16];

int F(int first,int last,int p){
    int&res=f[last][p];
    if(res<0){
        res=0;
        if(p){
            for(int i=0;i<k;++i)if(p&1<<i)
                res>?=d[last][i]+F(first,i,p^1<<i);
        }else {
            res=dd[last][first];
        }
    }
    return res;
}

int main(){
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    int T,tc=0;
    for(cin>>T;tc++<T;){
        printf("Case #%d: ",tc);
        cin>>k>>s;
        int res=s.size();
        memset(d,0,sizeof d);
        memset(dd,0,sizeof dd);
        for(int i=0;i<k;++i)
            for(int j=0;j<k;++j)
                if(i!=j){
                    for(int p=0;p<s.size();p+=k){
                        if(s[p+i]==s[p+j])
                            d[i][j]++;
                    }
                    for(int p=0;p+k<=s.size();p+=k)
                        if(s[p+i]==s[p+j+k])
                            dd[i][j]++;
                }
        for(int i=0;i<k;++i)
            memset(f,-1,sizeof f),
            res<?=s.size()-F(i,i,((1<<k)-1)^1<<i);
        cout<<res<<endl;
    }
    return 0;
}
