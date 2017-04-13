#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int q, p, a[10];

int fac(int q)
{
    int ans=1;
    
    for (int i=1; i<=q; i++)
    {
        ans*=i;
    }
    
    return ans;
}
int main(void)
{
    freopen("C-small-attempt0.in","r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t, sum, ww, ans, temp;
    int queue[110];
    
    scanf("%d", &t);
    for (int ca=1; ca<=t; ca++)
    {
        scanf("%d%d", &p, &q);
        for (int i=1; i<=q; i++)
        {
            scanf("%d", &a[i]);
        }
        sum=0;
        ww=fac(q);
        ans=1000000;
        memset(queue, 0, sizeof(queue));
     //   system("pause");
        for (int i=1; i<=ww; i++)
        {
            next_permutation(&a[1], &a[q+1]);
            temp=0;
            memset(queue, 0, sizeof(queue));
            queue[0]=queue[p+1]=1;
            
            for (int j=1; j<=q; j++)
            {
                queue[a[j]]=true;
                for (int kk=a[j]-1; !queue[kk] && kk>0; kk--) temp++;
                for (int kk=a[j]+1; !queue[kk] && kk<=p; kk++) temp++;
            }
            if (temp<ans) ans=temp;
        }
        printf("Case #%d: %d\n", ca, ans);
    }
   // system("pause");
    return 0;
}
