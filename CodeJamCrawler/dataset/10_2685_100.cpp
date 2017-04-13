#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
const int MXN = 502;
int cn,n;
long long f[MXN][MXN],c[MXN][MXN];
int ans[MXN];
int main() {
    freopen("C-large.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d",&cn);
    memset(f,0,sizeof(f));
    memset(c,0,sizeof(c));
    c[0][0]=1;
    for(int i=1;i<MXN;i++)
        for(int j=0;j<=i;j++) {
            if(j==0 || j==i) {
                c[i][j]=1;
            }else {
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%100003;
            }
        }
    f[2][1]=1;
    memset(ans,0,sizeof(ans));
    ans[2]=1;
    for(int i=3;i<=MXN-1;i++) {
        ans[i]=1;
        f[i][1]=1;
        for(int j=2;j<i;j++) {
            for(int k=1;k<j;k++) {
                f[i][j] += (f[j][k] * c[i-j-1][j-k-1]) % 100003;
            }
            ans[i]=(ans[i]+f[i][j]) % 100003;
        }
    }
    for (int ci = 0; ci < cn; ci++) {
        cin>>n;
        printf("Case #%d: %ld\n",ci+1,ans[n]);
    }
    return 0;
}
