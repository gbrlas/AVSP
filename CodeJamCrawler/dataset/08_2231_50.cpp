#include <iostream>
using namespace std;
struct node
{
    int s,t;
}a[110],b[110];
int t,mark1[110],mark2[110],res1,res2,n,m;
void make(int i,int tag)
{
    int j;
    if(tag==0)
    {
        int next=-1,mini,k;
        for(j=0;j<m;j++)
        {
            if(mark2[j]==1)continue;
            k=b[j].s-a[i].t;
            if(k>=t)
            {
                if(next==-1||k-t<mini)
                {
                    next=j;
                    mini=k-t;
                }    
            }
        }        
        if(next!=-1)
        {
            mark2[next]=1;
            res2--;
        }
    }
    else 
    {
        int next=-1,mini,k;
        for(j=0;j<n;j++)
        {
            if(mark1[j]==1)continue;
            k=a[j].s-b[i].t;
            if(k>=t)
            {
                if(next==-1||k-t<mini)
                {
                    next=j;
                    mini=k-t;
                }
            }
        }        
        if(next!=-1)
        {
            mark1[next]=1;
            res1--;
        }
    }
}             
int main()
{
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int cas,i,j,ca=1;
    cin>>cas;
    char s[10];
    while(cas--)
    {
        cin>>t>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>s;
            a[i].s=((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
            cin>>s;
            a[i].t=((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
            mark1[i]=0;
        }
        for(i=0;i<m;i++)
        {
            cin>>s;
            b[i].s=((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
            cin>>s;
            b[i].t=((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
            mark2[i]=0;
        }    
        res1=n;
        res2=m;
        for(i=0;i<n;i++)
        {
            make(i,0);
        }
        for(i=0;i<m;i++)
        {
            make(i,1);
        }        
        printf("Case #%d: %d %d\n",ca++,res1,res2);
    }
    return 0;
}        
