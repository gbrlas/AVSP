#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cmp(int i,int j){
    return i > j;
}


int main(){

    //freopen("B-small-attempt0.in","r",stdin);
   // freopen("B-small-attempt0.out","w",stdout);


    int T,n,s,p,Cas=1;

    scanf("%d",&T);
    while(T--){
        int a[110]={0};
        scanf("%d%d%d",&n,&s,&p);
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int s1 = 0,s2 = 0;
        int vis[110]={0};
        for(int i = 0; i < n; i++)
            if(a[i] >= max(3*p-4,p)  && s2<s&&!vis[i]) {
                s2++;
                vis[i]=1;
            }
        for(int i = 0; i < n; i++)
            if(!vis[i]&&a[i] >= 3*p-2 && s1<n-s) {
                s1++;
                vis[i] = 1;
            }
        printf("Case #%d: %d\n",Cas++,s1+s2);

    }

}
