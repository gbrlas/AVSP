#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
bool judge(int k)
{
    int i,j,n=0;
    int a[20];
    while(k)
    {
        a[n++] = k%10;
        k /=10;
    }
    for(i=0 ; i < n/2; i++)
    {
        if(a[i] != a[n-i-1])
            return false;
    }
    return true;
}
int main()
{
    freopen("d:\\C-small-attempt0.in","r",stdin);
    freopen("d:\\c1out.txt","w",stdout);
    int i,t,ncase;
    int n,m,k;
    scanf("%d",&ncase);
    for(t = 1; t <= ncase; t++)
    {
        int ans = 0;
        scanf("%d%d",&n,&m);
        for(i = n; i <= m;i++)
        {
            double j = sqrt(double(i));
            if(j != int(j))
                continue;
            k = int(j);
            //printf("%d %d\n",i,k);
            if(judge(i)&&judge(k))
            {
                //printf("****%d\n",i);
                ans++;
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
}
