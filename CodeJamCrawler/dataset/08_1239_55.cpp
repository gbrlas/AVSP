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

int main(){
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    int T,tc=0;
    for(cin>>T;tc++<T;){
        printf("Case #%d: ",tc);
        cin>>k>>s;
        int res=s.size();
        int p[k];
        for(int i=0;i<k;++i)
            p[i]=i;
        do{
            string q(s.size(),' ');
            for(int j=0;j<q.size();j+=k)
                for(int i=0;i<k;++i)
                    q[j+p[i]]=s[j+i];
            res<?=unique(q.begin(),q.end())-q.begin();
        }while(next_permutation(p,p+k));
        cout<<res<<endl;
    }
    return 0;
}
