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

typedef pair<int,int> pii;

vector<pii> a;

int D,A,B;

void read(int k){
    for(int add=0,h,m,i=1;i>-2;i-=2){
        scanf("%d:%d",&h,&m);
        a.push_back(pii(h*60+m+add,i*k));
        add+=D;
        k=3^k;
    }
}

bool check(int i,int j){
    int q[3]={0,i,j};
    for(int k=0;k<a.size();++k){
        pii p=a[k];
        if(p.second>0)q[p.second]--;
        else q[-p.second]++;
        if(q[1]<0 || q[2]<0)return false;
    }
    return true;
}

int main(){
    #ifdef LocalHost
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    #endif
    int T,tc=0;
    for(cin>>T;tc++<T;){
        cin>>D>>A>>B;
        a.clear();
        for(int i=0;i<A;++i)read(1);
        for(int i=0;i<B;++i)read(2);
        sort(a.begin(),a.end());
        int ra=A,rb=B;
        for(int k=0;k<=ra+rb;++k)
            for(int i=0;i<=k;++i)
                if(check(i,k-i))
                    ra=i,rb=k-i;
        printf("Case #%d: %d %d\n",tc,ra,rb);
    }
    return 0;
}
