#include <iostream>
using namespace std;
char s[1010],ss[1010],t[101];
int cal()
{
    int res=1,i;
    for(i=1;ss[i];i++)
    {
        if(ss[i]!=ss[i-1])res++;
    }
    return res;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("oo.txt","w",stdout);
    int cas,ca=1,i,res,temp,k,j;
    cin>>cas;
    while(cas--)
    {
        scanf("%d",&k);
        cin>>s;
        for(i=0;i<k;i++)
        {
            t[i]=i;
        }
        for(i=0;s[i];i++)
        {
            ss[i]=s[i];
        }
        res=cal();
        while(next_permutation(t,t+k))
        {
            for(i=0;s[i];i+=k)
            {
                for(j=0;j<k;j++)
                {
                    ss[i+j]=s[i+t[j]];
                }
            }
            ss[i]=0;
            temp=cal();
            if(temp<res)res=temp;
        }
        printf("Case #%d: %d\n",ca++,res);
    }
    return 0;
}
                    
