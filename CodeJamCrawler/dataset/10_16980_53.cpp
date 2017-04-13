#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,r,k,n,g[2000];
    int sum[2001],people[1000],groups[1000];
    int lo,hi,mi,f;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        printf("Case #%d: ",tc);
        
        scanf("%d %d %d",&r,&k,&n);
        
        for(int i=0;i<n;++i) scanf("%d",&g[i]);
        for(int i=n;i<=2*n;++i) g[i] = g[i-n];
        
        memset(people,0,sizeof(people));
        memset(groups,0,sizeof(groups));
        
        sum[0] = 0;
        for(int i=1;i<=2*n;++i) sum[i] = sum[i-1]+g[i-1];
        
        for(int i=0;i<n;++i){
            lo = i+1; hi = i+n;
            
            while(lo<hi){
                mi = (lo+hi+1)/2;
                f = sum[mi]-sum[i];
                
                if(f>k) hi = mi-1;
                else lo = mi;
            }
            
            people[i] = sum[lo]-sum[i];
            groups[i] = lo-i;
        }
        
        int pos = 0;
        long long ans = 0;
        
        for(int i=0;i<r;++i){
            ans += people[pos];
            pos = (pos+groups[pos])%n;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
