#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int x,y;
}nodetemp;
bool mark[2010];
vector<node> vec[2010];
vector<int> rootof[2010];
bool cmp(node a,node b)
{
    return a.y<b.y;
}
int deal(int i)
{
    int j,k;
            for(j=0;j<vec[i].size();j++)
            {
                if(vec[i][j].y==0)
                {
                    if(!mark[vec[i][j].x])
                    {
                        rootof[vec[i][j].x].push_back(i);
                        return 1;
                    }
                }
                else 
                {
                    if(mark[vec[i][j].x]==1)return 1;
                    else 
                    {
                        mark[vec[i][j].x]=1;
                        for(k=0;k<rootof[vec[i][j].x].size();k++)
                        {
                            if(deal(rootof[vec[i][j].x][k])==0)return 0;
                        }
                        return 1;
                    }
                }
            }
            return 0;
}        
int main()
{
    int cas,ca=1,n,m,i,t,p,q,j;
    freopen("in.txt","r",stdin);
    freopen("o.txt","w",stdout);
    cin>>cas;
    while(cas--)
    {
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            vec[i].clear();
            cin>>t;
            for(j=0;j<t;j++)
            {
                vec[i].push_back(nodetemp);
                cin>>p>>q;
                vec[i][j].x=p;
                vec[i][j].y=q;
            }
            sort(vec[i].begin(),vec[i].end(),cmp);
        }
        for(i=1;i<=n;i++)
        {
            rootof[i].clear();
        }
        memset(mark,0,sizeof(mark));
        int res=1;
        for(i=0;i<m;i++)
        {
            if(deal(i)==0)
            {
                res=0;
                break;
            }
        }
        printf("Case #%d:",ca++);
        if(res==0)printf(" IMPOSSIBLE\n");
        else 
        {
            for(i=1;i<=n;i++)
            {
                if(mark[i]==0)printf(" 0");
                else printf(" 1");
            }
            printf("\n");
        }
    }
    return 0;
}
