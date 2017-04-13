#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 16
using namespace std;
int n,a[MAXN];
int sum,x,y,ans;
int c1,c2;
void dfs(int pos,int dif)
{
    if(pos>n){
        if(x^y==0&&c1&&c2)
            ans=max(ans,(sum+abs(dif))/2);
    }
    else{
        x^=a[pos];
        dif+=a[pos];
        c1++;
        dfs(pos+1,dif);
        dif-=a[pos];
        x^=a[pos];
        c1--;
        
        c2++;
        y^=a[pos];
        dif-=a[pos];
        dfs(pos+1,dif);
        dif+=a[pos];
        y^=a[pos];
        c2--;
    }
}
    

int main()
{
    //freopen("C-small-attempt0.in","r",stdin);
    //freopen("C-small-attempt0.out","w",stdout);
    int t,tmp,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        tmp=0;
        sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            tmp^=a[i];
            sum+=a[i];
        }
        printf("Case #%d: ",++cas);
        if(tmp)
            puts("NO");
        else{
            c1=c2=0;
            ans=x=y=0;
            dfs(1,0);
            printf("%d\n",ans);
        }
    }
    //while(1);
    return 0;
}
    
