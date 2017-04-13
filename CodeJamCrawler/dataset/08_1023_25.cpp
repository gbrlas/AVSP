#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int  a[100],left;
char s[100][110];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int ncase,k=0 ;
    scanf("%d",&ncase);
    while(k<ncase){
        int n,q,i,j,change=0;
        char temp[110];
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        scanf("%d",&n);
        left=0;
        getchar();
        for(i=0;i<n;i++){
            gets(s[i]);
        }
        scanf("%d",&q);
        getchar();
        for(i=0;i<q;i++){
            gets(temp);
            for(j=0;j<n;j++){
                if(a[j]==0&&strcmp(temp,s[j])==0){
                    a[j]=1;
                    left++;
                    break;
                }
            }
            if(left==n){
                change++;
                left=1;
                memset(a,0,sizeof(a));
                a[j]=1;
            }
        }
        k++;        
        printf("Case #%d: %d\n",k,change);
    }
    return 1;
}
