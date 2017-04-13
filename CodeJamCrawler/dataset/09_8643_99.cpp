#include<stdio.h>

int h[30];

int i,j,r,n,m,L;

char s[6000][20],ss[100000];

int p[30];

int main(){
    h[0]=1;
    for(i=1;i<30;i++)h[i]=h[i-1]*2;
    scanf("%d %d %d",&L,&n,&m);
    for(i=1;i<=n;i++){
        scanf("%s",s[i]);
    }
    int ii=0;
    for(i=1;i<=m;i++){
        scanf("%s",ss);
        r=0;
        for(j=0;j<L;j++){
            p[j]=0;
            if(ss[r]=='('){
                r++;
                while(ss[r]!=')'){
                    p[j]|=h[ss[r]-'a'];
                    r++;
                }
            }else {
                p[j]|=h[ss[r]-'a'];
            }
            r++;
        }
        int ans=0;
        for(j=1;j<=n;j++){
            for(r=0;r<L;r++)if(!(p[r]&h[s[j][r]-'a']))break;
            if(r==L)ans++;
        }
        ii++;
        printf("Case #%d: %d\n",ii,ans);
    }
    return 0;
}
