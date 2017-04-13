#include<stdio.h>
main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int score,t1,t2,b1,b2;
    int T,n,s,p,c;
    scanf("%d",&T);
    for(c=1;c<=T;c++){
        scanf("%d %d %d",&n,&s,&p);
        t1=0;
        t2=0;
        if(p==0) b1=b2=0;
        else{
            b1=3*p-2;
            b2=3*p-4;
            if(b2<1) b2=1;
        }
        while(n--){
            scanf("%d",&score);
            if(score>=b1) t1++;
            else if(score>=b2) t2++;
        }
        if(t2>s) t2=s;
        printf("Case #%d: %d\n",c,t1+t2);
    }
}
