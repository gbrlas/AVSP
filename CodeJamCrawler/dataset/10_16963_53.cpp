#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,N,K;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d %d",&N,&K);
        
        int mask1 = 1, mask2 = 0;
        
        for(int i=0;i<K;++i){
            for(int j=0;j<N;++j) if(mask1 & (1<<j)) mask2 ^= (1<<j);
            mask1 = 1;
            for(int j=0;j<N-1;++j){
                if((mask2 & (1<<j))==0) break;
                mask1 |= (1<<(j+1));
            }
        }
        
        printf("Case #%d: ",tc);
        if(mask1==(1<<N)-1 && (mask2 & (1<<(N-1)))) printf("ON\n");
        else printf("OFF\n");
    }
    
    return 0;
}
