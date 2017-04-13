#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int a,b;
bool is_pal(int k){
    int t[107],len=0;
    while(k){
        t[len++]=k%10;
        k/=10;
    }
    for(int i=0;i<(len/2+1);i++)
        if(t[i]!=t[len-i-1])return false;
    return true;
}
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++){
        scanf("%d%d",&a,&b);
        int A=sqrt(a);
        while(A*A<a)A++;
        int B=sqrt(b);
        int ans=0;
        for(int i=A;i<=B;i++){
            if(is_pal(i)&&is_pal(i*i))ans++;
        }
        printf("Case #%d: %d\n",kase,ans);
    }
}
