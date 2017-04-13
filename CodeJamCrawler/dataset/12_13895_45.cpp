#include<cstdio>
#include<cstring>
using namespace std;
int t,a,b,br[2100000],ans;
int main()
{
    int i,j,h,k,o,o1,e,o2,o3,l;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        ans=0;
        scanf("%d%d",&a,&b);
        o=a;
        k=0;
        o2=1;
        while(o)
        {
            o/=10;
            k++;
            o2*=10;
        }
        o2/=10;
        for(j=a;j<=b;j++)
        if(!br[j])
        {
            o=1;
            h=10;
            o3=o2;
            l=0;
            while(o<k)
            {
                e=j%h;
                e*=o3;
                o3/=10;
                e+=j/h;
                h*=10;
                if(e>=a&&e<=b&&j!=e&&!br[e])
                {
                    br[e]=1;
                    //printf("%d\n",e);
                    l++;
                }
                o++;
            }
            //printf("%d\n",l);
            br[j]=1;
            if(l%2)ans+=(l/2)*l+l;
            else ans+=(l/2)*(l+1);
            //ans+=l;
        }
        printf("Case #%d: %d\n",i,ans);
        memset(br,0,sizeof(br));
        //for(j=a;j<=b;j++)
        //printf("%d\n",br[j]);
    }
}