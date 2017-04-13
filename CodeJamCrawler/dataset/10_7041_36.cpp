#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(){
    int i,t,l,p,c,num,ans;
    freopen("C:\\Users\\QQQ\\Desktop\\1.in","r",stdin);
    freopen("C:\\Users\\QQQ\\Desktop\\1.out","w",stdout);
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d%d",&l,&p,&c);
        for(num=0;l<p;l*=c,num++);
        ans=log2l(num);
        if(ans!=log2l(num))
            ans++;
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
