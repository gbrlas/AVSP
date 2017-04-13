#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<list>
using namespace std;
int main()
{
    int a,b,k;
    int t,ca=0;
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int cnt=0;
        scanf("%d%d%d",&a,&b,&k);
        for(int i=0;i<a;++i)
            for(int j=0;j<b;++j)
            {
                if((i&j)<k)
                {
                    cnt++;
                }
            }
        printf("Case #%d: %d\n",++ca,cnt);
    }
}
