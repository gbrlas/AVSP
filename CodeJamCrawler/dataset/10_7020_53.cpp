#include<stdio.h>
int q(int a,int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a>b)
        return q(a%b,b);
    return q(b%a,a);
}
int main(){
    int c,n,t[1002],i,j,a[3];
    freopen ("C:\\Users\\QQQ\\Desktop\\1.out","w",stdout);
    freopen ("C:\\Users\\QQQ\\Desktop\\1.in","r",stdin);
    scanf("%d",&c);
    for(i=1;i<=c;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&t[j]);
        a[0]=t[1]-t[0];
        if(n==3){
            a[1]=t[2]-t[1];
            a[2]=t[2]-t[0];
        }
        for(j=0;j<3;j++)
            if(a[j]<0)
                a[j]*=-1;
        if(n==3)
            a[0]=q(a[0],q(a[1],a[2]));
        if(t[0]%a[0]==0)
            printf("Case #%d: 0\n",i);
        else
            printf("Case #%d: %d\n",i,a[0]*(t[0]/a[0]+1)-t[0]);
    }
    return 0;
}
