#include<stdio.h>
int main(){
    int t,r,k,n,g[1000],i,j,a,b,c;
    freopen ("C:\\Users\\QQQ\\Desktop\\1.out","w",stdout);
    freopen ("C:\\Users\\QQQ\\Desktop\\1.in","r",stdin);
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d %d",&r,&k,&n);
        for(j=0;j<n;j++)
            scanf("%d",&g[j]);
        for(j=a=0;r>0;r--){
            b=0;
            c=j;
            while(1){
                if(j==n)
                    j=0;
                if(b+g[j]>k||(c==j&&b!=0))
                    break;
                b+=g[j];
                j++;
            }
            a+=b;
        }
        printf("Case #%d: %d\n",i,a);
    }
    return 0;
}
