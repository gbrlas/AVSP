#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int i,j,t,g=1;
    double time,tt,f,c,x,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf",&c,&f,&x);
        double ti=0;
        double ff=2;
        ans=999999999;
        for(i=0;i<=100000;i++)
        {
            if(i==0) time=x/2;
            else
            {
                time=ti+c/ff+x/(f*i+2);
                ti=ti+c/ff;
                ff=f*i+2;
            }
            //printf("%.7lf %.7lf %d %.7lf\n",time,ff,i,ti);
            if(ans>time) ans=time;
            else break;
        }
        printf("Case #%d: ",g++);
        printf("%.7lf\n",ans);
    }
    return 0;
}
