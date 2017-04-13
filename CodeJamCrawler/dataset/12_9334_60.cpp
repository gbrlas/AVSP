#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
using namespace std;
set<int>ms;

int main()
{
    freopen("3.in","r",stdin);
    freopen("3.out","w",stdout);
    int cas;
    scanf("%d",&cas);
    for(int g=1;g<=cas;g++)
    {
        
        int a,b;
        scanf("%d%d",&a,&b);
        int t=a,len=0;
        ms.clear();
        while(t)
        {
            len++;
            t/=10;
        }
        int ans=0,ten=1;
        for(int i=1;i<len;i++)
            ten*=10;

        for(int i=a;i<b;i++)
        {
            ms.clear();
            int t=i;
            for(int j=1;j<len;j++)
            {
                int res=t%10;t/=10;
                if(!res) continue;
                t+=res*ten;
                if(t>i&&t<=b) ms.insert(t);
            }
            ans+=ms.size();
        }

       printf("Case #%d: %d\n",g,ans);
    }
    return 0;
}