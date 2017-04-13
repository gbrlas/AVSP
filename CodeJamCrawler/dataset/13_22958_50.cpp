#include <cstdio>
#include <cstring>

int tc,a,b;
int i;
int c[1010];
int main(){
    memset(c,0,sizeof c);
    c[1] = c[4] = c[9] = c[121] = c[484] = 1;
    for(i=1;i<1010;i++)
        c[i] += c[i-1];
    
    scanf("%d",&tc);
    for (i = 1;i <= tc; i++) {
        scanf("%d %d",&a,&b);    
        printf("Case #%d: %d\n",i,c[b]-c[a-1]);
        
    }
    
    
    return 0;
}
