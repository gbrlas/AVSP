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

typedef long long ll;
typedef pair<int,int> pii;

int L,D,N;
char s[5555][22];

int main(){
    #ifdef LocalHost
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    #endif
    cin>>L>>D>>N;
    for(int i=0;i<D;++i)
        scanf("%s",s[i]);
    for(int i=0;i<N;++i){
        vector<int> v;
        for(int j=0;j<D;++j) v.push_back(j);
        string p;
        cin>>p;
        for(int j=0;j<L;++j){
            vector<int> V;
            int z=0;
            if(p[0]=='('){
                int k=1;
                for(;p[k]!=')';++k) z|=1<<p[k]-'a';
                p=p.substr(k+1);
            }else z=1<<p[0]-'a',p=p.substr(1);
            for(vector<int>::iterator q=v.begin();q!=v.end();++q)
                if(z&1<<s[*q][j]-'a')V.push_back(*q);
            v.swap(V);
        }
        printf("Case #%d: %d\n",1+i,v.size());
    }
    return 0;
}
