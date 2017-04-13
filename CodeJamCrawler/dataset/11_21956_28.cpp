#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int x,int y){
    if (!x||!y) return x>y?x:y;
    for (int t;t=x%y;x=y,y=t);
    return y;
}

int main(){
    freopen("csmall.in","r",stdin);
    freopen("csmall.out","w",stdout);
    int tt,n;
    int l,h;
    int f[100];
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++){
        bool fv=true;
        scanf("%d%d%d",&n,&l,&h);
        for (int i=0;i<n;i++) scanf("%d",&f[i]);
        //cout<<"sdfsF"<<endl;
        for (int i=l;i<=h;i++){
            bool flag=true;
            for (int j=0;j<n;j++)
                if (i%f[j]!=0&&f[j]%i!=0) flag=false;
            if (flag){
                printf("Case #%d: %d\n",t,i);
                fv=false;
                break;
            }
        }
        if (fv) printf("Case #%d: NO\n",t);
    }
    return 0;
}
