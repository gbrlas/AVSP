#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
    int t,n,m,i,j,k,l,flag,flag1,count,temp;
    vector<int> b;
    vector<vector<int> > a;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                scanf("%d",&temp);
                b.push_back(temp);
            }
            a.push_back(b);
            b.clear();
        }
        if(n==1||m==1)
        {
                printf("Case #%d: YES\n",i+1);
                a.clear();
                continue;
        }
        count=0;
        for(j=0;j<n;j++)
        {
            flag=0;
            flag1=0;
            for(k=0;k<m;k++)
            {
                for(l=0;l<n;l++)
                if(a[l][k]>a[j][k])
                {
                    flag=1;
                    break;
                }                
                if(flag==1)
                for(l=0;l<m;l++)
                    if(a[j][l]>a[j][k])
                    {
                        flag1=1;
                        break;
                    }
                if(flag1==1)
                {
                    count++;
                    break;
                }
            }
            if(count>0)
            break;
        }
        if(count==0)
            printf("Case #%d: YES\n",i+1);
        else
            printf("Case #%d: NO\n",i+1);
        a.clear();
    }
}
