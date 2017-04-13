#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
const int MXN = 100;
const double eps = 1e-7;
int cn,n,c,b,t,ans;
int flag;
int f[MXN],x[MXN],v[MXN];
int main() {
    freopen("B-large.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&cn);
    memset(f,0,sizeof(f));
    for (int ci = 0; ci < cn; ci++) {
        memset(f,0,sizeof(f));
        cin>>n>>c>>b>>t;
        for(int i=0;i<n;i++)
            cin>>x[i];
        for(int i=0;i<n;i++)
            cin>>v[i];
        flag = 0;
        ans = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(x[i]+v[i]*t>=b) {
                flag++;
            }
            for(int j=i+1;j<n;j++) 
                if(x[i]+v[i]*t>=b && x[j]+v[j]*t<b) {
                    ans++;
                }
            if(flag==c) break;
        }
/*        for(int i=0;i<n;i++)
            cout<<f[i]<<' ';
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<x[i]+v[i]*t<<' ';
        cout<<endl;
        cout<<b<<endl;*/
        if(flag < c) 
            printf("Case #%d: IMPOSSIBLE\n",ci+1);
        else
            printf("Case #%d: %d\n",ci+1,ans);
    }
    return 0;
}
