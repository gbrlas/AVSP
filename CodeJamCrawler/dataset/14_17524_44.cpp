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
#define eps 1e-8
using namespace std;

int t;
int n,a1,a2;
double  a[1010],b[1010];

int main()
{
    //freopen("D-small-attempt0.in","r",stdin);
    freopen("D-large.in","r",stdin);
    freopen("d.txt","w",stdout);
    scanf("%d",&t);
    int __=0;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)scanf("%lf",&a[i]);
        for(int i=0;i<n;++i)scanf("%lf",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        int flag=0;
        a2=0;int j=0;
        for(int i=0;i<n;++i){
            while(b[j]<a[i]-eps)
            {
                a2++;j++;
                if(j==n){
                    flag=1;break;}
            }
            if(flag)break;
            j++;
            if(j==n)break;
        }
        //a2=n-a2;

        a1=0;
        j=n-1;flag=0;
        for(int i=n-1;i>=0;--i){
            while(a[i]<b[j]-eps)
            {
                j--;
                if(j<0)
                {flag=1;break;}
            }
            if(flag)break;
            j--;a1++;
            if(j<0)break;

        }
        //a1=n-a1;

        printf("Case #%d: %d %d\n",++__,a1,a2);
    }

    return 0;
}
