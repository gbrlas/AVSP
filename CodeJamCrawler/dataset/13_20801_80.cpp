#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
bool a[1005],b[1005];
int main()
{
    int i,j,k,l,n,m;
    cin>>n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for (j=1;j<=1000;j++)
    {
        int p[5];
        int s=0,i=j;
        while (i>0)
        {
            s++;
            p[s]=i%10;
            i/=10;
        }
        bool f=1;
        for (i=1;i<=s;i++)
        {
            if (p[i]!=p[s-i+1])
            {
                f=0;
                break;
            }
        }
        if (f)
        {
            a[j]=1;
            if (j*j<=1000) {b[j*j]=1;}
        }
    }
    for (l=1;l<=n;l++)
    {
        int q,w;
        cin>>q>>w;
        k=0;
        for (j=q;j<=w;j++) if (a[j] && b[j])
        {
            k++;
        }
        printf("Case #%d: %d\n",l,k);
    }
}
