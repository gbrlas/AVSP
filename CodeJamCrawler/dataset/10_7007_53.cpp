#include<stdio.h>
int main(){
    int t,i,n,k,s[31]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
    freopen ("C:\\Users\\QQQ\\Desktop\\1.out","w",stdout);
    freopen ("C:\\Users\\QQQ\\Desktop\\1.in","r",stdin);
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d",&n,&k);
        printf("Case #%d: ",i);
        if((k%s[n])==s[n]-1)
            printf("ON");
        else
            printf("OFF");
        if(i!=t)
            printf("\n");
    }
    return 0;
}
