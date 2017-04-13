/**

*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>

using namespace std;

int a[20],t;
int n,m;
int l,x;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.txt","w",stdout);
    scanf("%d",&t);
    int __=0;
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
            {
                scanf("%d",&l);
                if(i+1==n)
                {
                    a[l]++;
                }
            }
        }
        x=0;
        int ans=0;
        scanf("%d",&m);
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
            {
                scanf("%d",&l);
                if(i+1==m)
                {
                    a[l]++;
                    if(a[l]==2)
                    {
                        x++;ans=l;
                    }
                }
            }
        }
        printf("Case #%d: ",++__);
        if(!x)printf("Volunteer cheated!\n");
        else if(x==1)printf("%d\n",ans);
        else printf("Bad magician!\n");
    }

    return 0;
}
