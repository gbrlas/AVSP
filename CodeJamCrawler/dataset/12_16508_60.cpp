#include<stdio.h>
int p(int n){
    int t=1;
    while(n>=10){
        n/=10;
        t*=10;
    }
    return t;
}
int num(int n,int low){
    int tmp,t,count=0;
    t=p(n);
    tmp=n%10*t+n/10;
    while(tmp!=n){
        //printf("%d\n",tmp);
        if(n>tmp&&tmp>=low) count++;
        tmp=tmp%10*t+tmp/10;
    }
    return count;
}
main(){
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int T,a,b,i,c,ans;
    scanf("%d",&T);
    for(c=1;c<=T;c++){
        scanf("%d %d",&a,&b);
        ans=0;
        for(i=a;i<=b;i++) ans+=num(i,a);
        printf("Case #%d: %d\n",c,ans);
    }
}
