#include<iostream>
#include<algorithm>
using namespace std;
char s[600][600];
int map[600][600];
int used[600][600];
int temp[600][600];
struct dd{
    int v,num;
}a[5000];
void trans(int p,int k,char c)
{
    int x;
    if(c>='0'&& c<='9') x=c-'0';
    else x=c-'A'+10;
    int i=(k+1)*4-1;
    while(x)
    {
        map[p][i]=x%2;
        x/=2;
        i--;
    }
}
int n,m,ans;
int sum;
int cmp(dd a,dd b)
{
    return a.v>b.v;
}
void cal()
{
    int i,j,p,k,l,r,max;
    while(1)
    {
       for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        temp[i][j]=used[i][j];
        max=0;
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            if(temp[i][j]!=2)
            {
                k=1;
                while(i+k<m&&j+k<n)
                {
                    for(p=j;p<=j+k-1;p++)
                    if(temp[i+k][p]==2) break;
                    else
                    {
                        if(p==j)
                        {
                            if(map[i+k][p]==map[i+k-1][p]) break;
                        }
                        else
                        {
                            if(map[i+k][p]==map[i+k-1][p] || map[i+k][p-1]==map[i+k][p]) break;
                        }
                    }
                    if(p<=j+k-1) break;

                    for(p=i;p<=i+k-1;p++)
                    if(temp[p][j+k]==2) break;
                    else
                    {
                        if(p==i)
                        {
                            if(map[p][j+k]==map[p][j+k-1]) break;
                        }
                        else
                        {
                            if(map[p][j+k]==map[p][j+k-1] || map[p][j+k]==map[p-1][j+k]) break;
                        }
                    }
                    if(p<=i+k-1) break;

                    if(temp[i+k][j+k]==2) break;
                    if(map[i+k][j+k]==map[i+k][j+k-1] || map[i+k][j+k]==map[i+k-1][j+k]) break;
                    k++;
                }
                if(k>max) {max=k;l=i;r=j;}
            }
        }
        if(max==1|| max==0) break;
       // if(max==0) break;
        for(i=l;i<=l+max-1;i++)
         for(j=r;j<=r+max-1;j++)
         used[i][j]=2;
        for(i=0;i<ans;i++)
        if(a[i].v==max) {sum+=max*max;a[i].num++;break;}
        if(i==ans)
        {
            a[ans].v=max;
            a[ans].num=1;
            ans++;
            sum+=max*max;
        }
    }
    if(max==1){
    a[ans].v=1;
    a[ans].num=n*m-sum;
    ans++;}
}
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    int i,j,k,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&m,&n);
        //getchar();
        memset(map,0,sizeof(map));
        for(j=0;j<m;j++)
        {
            scanf("%s",s[j]);
            for(k=0;k<n/4;k++)
            {
                trans(j,k,s[j][k]);
            }
        }
        ans=0;
        sum=0;
        memset(used,0,sizeof(used));
        cal();
        sort(a,a+ans,cmp);
        printf("Case #%d: %d\n",i,ans);
        for(j=0;j<ans;j++)
        printf("%d %d\n",a[j].v,a[j].num);
    }
}
