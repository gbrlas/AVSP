#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n,p,q,temp;
int a[10001];
int f[102][102];

int calc(int x,int y){
    if (f[x][y]!=-1) return f[x][y];
    if (x>=y) return 0;
    int ans=INT_MAX;
  //  cout<<a[y]-a[x]-2<<endl;
    for (int k=x+1;k<=y-1;k++){
        temp=calc(x,k)+calc(k,y)+a[y]-a[x]-2;
        if (ans>temp){
            ans=temp;
           // cout<<temp<<endl;
        }
    }
    f[x][y]=ans;
    return f[x][y];
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d",&n);
    for (int o=1;o<=n;o++){
        scanf("%d%d",&p,&q);
        memset(a,0,sizeof(a));
        for (int i=1;i<=q;i++) scanf("%d",&a[i]);
        a[0]=0; a[q+1]=p+1;
        memset(f,-1,sizeof(f));
        for (int i=0;i<=q;i++) f[i][i+1]=0;
        printf("Case #%d: %d\n",o,calc(0,q+1));
    }
    return 0;
}
