#include <iostream>
using namespace std;
char a[105][105],b[1010][105],t;
bool mark[1010];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,cas,m,ca=1,i,j,t,res,k;
    cin>>cas;
    while(cas--)
    {
        cin>>n;
        while(cin.peek()=='\n')getchar();
        for(i=0;i<n;i++)cin.getline(a[i],105);
        cin>>m;
        while(cin.peek()=='\n')getchar();
        for(i=0;i<m;i++)cin.getline(b[i],105);
        t=0,res=0;
        for(i=0;i<n;i++)mark[i]=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(strcmp(b[i],a[j])==0)break;
            }
            if(mark[j]==0)
            {
                if(t==n-1)
                {
                    for(k=0;k<n;k++)
                    {
                        mark[k]=0;
                    }
                    mark[j]=1;
                    res++;
                    t=1;
                }  
                else 
                {      
                    mark[j]=1;
                    t++;
                }    
            }        
        }    
        printf("Case #%d: %d\n",ca++,res);
    }    
    return 0;
}    
        
