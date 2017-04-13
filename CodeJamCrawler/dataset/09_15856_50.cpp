#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,P,Q,ans;
    int a[5];
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&P,&Q);
        
        for(int i=0;i<Q;i++) scanf("%d",&a[i]);
        for(int i=0;i<Q;i++) a[i]--;
        
        sort(a,a+Q);
        
        ans=INT_MAX;
        
        bool in[P];
        
        do{
            int aux=0;
            memset(in,true,sizeof(in));
            
            for(int i=0;i<Q;i++){
                in[a[i]]=false;
                for(int j=a[i]-1;j>=0 && in[j];j--) aux++;
                for(int j=a[i]+1;j<P && in[j];j++) aux++;
            }
            
            ans=min(ans,aux);
        }while(next_permutation(a,a+Q));
        
        printf("Case #%d: %d\n",tc,ans);
    }
    
    return 0;
}
