#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
int main()
{
   // freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int a,b,c,m,i,j,k,n,k1,k2,ans,t,t1,t2;
    scanf("%d",&m);
    char p1[20],p2[20],mm;
    for(int pp=1; pp<=m; pp++)
    {
        k1=1;
        k2=1;
        scanf("%d",&n);
        ans=0;
        t1=0;
        t2=0;
        for(i=1; i<=n; i++)
        {
            scanf("%s %d",p1,&a);
            if(i==1)
            {
                if(p1[0]=='O')
                {
                    ans+= (a-1);
                    ans+=1;
                    mm=p1[0];
                    k1=a;
                    t1=ans;
                }
                else if(p1[0]=='B')
                {
                    ans+= (a-1);
                    ans+=1;
                    mm=p1[0];
                    k2=a;
                    t2=ans;
                }
            }
            else
            {
                if(p1[0]==mm)
                {
                    if(p1[0]=='O')
                    {
                        ans+=(abs(a-k1)+1);
                        k1=a;
                        t1=ans;
                    }
                    else if(p1[0]=='B')
                    {
                        ans+=(abs(a-k2)+1);
                        k2=a;
                        t2=ans;
                    }
                }
                else
                {
                    if(p1[0]=='O')
                    {
                        if(ans-t1>=abs(a-k1))
                        {
                            ans++;
                            k1=a;
                            t1=ans;
                        }
                        else
                        {
                            ans+=(abs(a-k1)-(ans-t1));
                            ans++;
                            t1=ans;
                        }
                        k1=a;
                        mm=p1[0];
                    }
                    else if(p1[0]=='B')
                    {
                        if(ans-t2>=abs(a-k2))
                        {
                            ans++;
                            k2=a;
                            t2=ans;
                        }
                        else
                        {
                            ans+=(abs(a-k2)-(ans-t2));
                            ans++;
                            t2=ans;
                        }
                        k2=a;
                        mm=p1[0];
                    }
                }
            }
        }
        printf("Case #%d: %d\n",pp,ans);
    }
}
