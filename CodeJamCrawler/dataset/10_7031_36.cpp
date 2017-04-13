#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int i,j,k,t,n,a[10001],b[10001],q,w,ans;
    freopen("C:\\Users\\QQQ\\Desktop\\1.in","r",stdin);
    freopen("C:\\Users\\QQQ\\Desktop\\1.out","w",stdout);
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        ans=0;
        memset(a,0,10001*sizeof(int));
        memset(b,0,10001*sizeof(int));
        scanf("%d",&n);
        scanf("%d%d",&q,&w);
        a[q]=1;
        b[q]=w;
        for(j=1;j<n;j++){
            scanf("%d%d",&q,&w);
            if(q<w){
                for(k=1;k<q;k++)
                    if(a[k]==1&&b[k]>w)
                        ans++;
                for(k++;k<10001;k++)
                    if(a[k]==1&&b[k]<w)
                        ans++;
            }
            else{
                for(k=10000;k>q;k--)
                    if(a[k]==1&&b[k]<w)
                        ans++;
                for(k--;k>0;k--)
                    if(a[k]==1&&b[k]>w)
                        ans++;
            }
            a[q]=1;
            b[q]=w;
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
