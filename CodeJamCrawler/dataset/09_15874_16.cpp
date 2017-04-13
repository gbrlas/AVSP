#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

bool valid(string s, int k){
    for(int i=k;i<s.size();i++) if(s[i]=='1') return false;
    return true;
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("outA.txt","w",stdout);
    
    int T,N;
    scanf("%d",&T);
    vector<string> v;
    string s;
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&N);
        
        v.clear();
        for(int i=0;i<N;i++){
            cin>>s;
            v.push_back(s);
        }
        
        int ans=0;
        
        for(int i=0;i<N;i++){
            int cont=-1;
            
            for(int j=i;j<N;j++){
                cont++;
                if(valid(v[j],i+1)){
                    ans+=cont;
                    for(int k=j;k>i;k--) swap(v[k],v[k-1]);
                    break;
                }
            }
        }
        
        printf("Case #%d: %d\n",tc,ans);
    }
    
    return 0;
}
