#include<cstdio>
#include<cstring>
#include <cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

const int maxn = 35;
int ans[maxn*maxn];

void presolve(){
    char num[10];
    int n,len,tag;
    memset(ans,0,sizeof(ans));
    for(int i = 1;i < maxn;i++){
        n = i;
        itoa(n,num,10);
        len = strlen(num); tag = 1;
        for(int j = 0;j < (len+1)/2;j++)
            if(num[j] != num[len-j-1]) {tag = 0; break; }
        if(tag == 0) continue;
        n = i*i;
        itoa(n,num,10);//printf("%s\n",num);
        len = strlen(num); tag = 1;
        for(int j = 0;j < (len+1)/2;j++)
            if(num[j] != num[len-j-1]) tag = 0;
        if(tag == 1) {ans[i*i] = 1;
            //printf("%s\n\n",num);
        }
    }
    for(int i = 0;i < 1005;i++){
        ans[i+1] += ans[i];
        //printf(" %d ",ans[i]);
    }
}

int main(){
    presolve();
    freopen("outans","w",stdout);
    int t,kase = 0,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        //printf("%d %d\n",ans[b],ans[a-1]);
        printf("Case #%d: %d\n",++kase,ans[b]-ans[a-1]);
    }
    return 0;
}
