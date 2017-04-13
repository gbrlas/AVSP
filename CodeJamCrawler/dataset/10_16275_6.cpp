#include <iostream>
using namespace std;
#define maxn 1005
int n,m;
bool exist[maxn][maxn];
bool temp[maxn][maxn];
int sum;
bool isok(int i,int j)
{
    if(exist[i-1][j]&&exist[i][j-1]) return 1;
    else return 0;
}
bool isnull(int i,int j)
{
    if(exist[i-1][j]==0&&exist[i][j-1]==0) return 1;
    else return 0;
}
void run()
{
    int i,j;
    for(i=0;i<=100;i++)
        for(j=0;j<=100;j++)
             temp[i][j]=0;
    sum=0;
    for(i=0;i<=100;i++)
        for(j=0;j<=100;j++)
        {
            if(exist[i][j])
            {
                if(isnull(i,j)) temp[i][j]=0;
                else temp[i][j]=1,sum++;
            }
            else
            {
                if(isok(i,j)) temp[i][j]=1,sum++;
                else temp[i][j]=0;
            }
        }
//    cout<<sum<<endl;
    for(i=0;i<=100;i++)
        for(j=0;j<=100;j++)
            exist[i][j]=temp[i][j];
}
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    int i,j,k,t,T;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        int x1,x2,y1,y2;
        memset(exist,0,sizeof(exist));
        sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(j=x1;j<=x2;j++)
                for(k=y1;k<=y2;k++)
                {
                    if(exist[k][j]==0) sum++,exist[k][j]=1;
                }
        }
        int ans=0;
        while(sum)
        {
            ans++;
            run();
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
