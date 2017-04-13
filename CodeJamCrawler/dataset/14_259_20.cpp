#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,cap;
int m;
int a[20000];
int b[20000];
int c[20000];
int d[20000];
int best = 0;

int f(int st,int ed,int flag)
{
    if (st >=ed) return 0;
    int ans = 0;
    for (int i = st; i <= ed; i++){
        for (int j = i+1; j <= ed; j++)
        {
            if (c[i] >c[j] && flag == 0) ans++;
            if (c[i] < c[j] && flag == 1) ans++;
        }
    }
    return ans;
}
void cal()
{
    int ans = 0;
    int p,q;
    p = 0;
    q = 0;
    for (int i = 0; i < m;i++)
    {
        if (b[i]){
            p++;
            ans++;
            for (int j = i+1; j < m; j++)
            {
                if (b[j] == 0){
                    ans++;
                }
            }
        }
    }
    for (int i = m+1; i < n; i++){
        if (b[i]){
            q++;
            ans++;
            for(int j = m+1; j< i;j++){
               if (b[j] ==0)
                  ans++; 
            }
        }
    }
    ans += p*q;
    int r = 0;
    for (int i = 0; i< n; i++){
        if ( (i < m && b[i] ==0)||(i>m&&b[i] ==1)) c[r++]=a[i];
    }
    int w = r;
    c[r++]=a[m];
    for(int i = 0; i < n; i++){
    if ((i < m && b[i] ==1) ||(i>m&&b[i] ==0)) c[r++]=a[i];
    }
    ans += f(0,w-1,0);
        ans = ans + (n-w-1)*(n-w-2)/2-f(w+1,n-1,0);
    if (ans < best) best = ans;
}
void dfs(int dep)
{
    if (dep == n) {cal(); return ;}
    if (dep == m) dfs(dep+1);else
    {
        b[dep] = 0;dfs(dep+1);
        b[dep] = 1;dfs(dep+1);
    }
}
int main()
{
    int cases;
    int ans;
    scanf("%d",&cases);
    for (int i = 1; i <= cases; i++){
        best = 100000000;
        printf("Case #%d: ",i);
    ans = 0;
    scanf("%d",&n);
    for (int j = 0; j < n; j++) 
    {
        b[j] = 0;
        scanf("%d",a+j);
    }
    m = 0; 
    for(int j =  1; j < n; j++)
        if (a[m] < a[j]) m = j;
    dfs(0);
    printf("%d\n",best);
    }
    return 0;
}
