#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int tc,c;
ll t,r,start,req,res;


int main(){
    scanf("%d",&tc);
    for(c = 1; c <= tc; c++){
        scanf("%lld %lld",&r,&t);
        r++;
        res = 0;
        while(1){
            req = (r*r)-((r-1)*(r-1));     
            if(req>t) break;
            res++;
            t -= req;
            r += 2;
        }
        printf("Case #%d: %lld\n",c,res);
        
            
    }
    
    
    return 0;
}
