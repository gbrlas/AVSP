#include <cstdio>
#include <cstring>
char g[5][5];
char row(int i)
{
    int j;
    char tmp='.';
    for(j=0;j<4;++j)
    {
        if(g[i][j]=='.') return '.';
        if(tmp=='.' || tmp=='T')tmp=g[i][j];
        else if(g[i][j]=='T')continue;
             else if(g[i][j]!=tmp)return '.';
    }
    return tmp;
}
char col(int i)
{
    int j;
    char tmp='.';
    for(int j=0;j<4;++j)
    {
        if(g[j][i]=='.')return '.';
        if(tmp=='.' || tmp=='T')tmp=g[j][i];
        else if(g[j][i]=='T')continue; 
             else if(g[j][i]!=tmp)return '.';
    }
    return tmp;
}
char dia()
{
    int j,flag=0;
    char tmp='.'; 
    for(int j=0;j<4;++j)
    {
        if(g[j][j]=='.'){ flag=1; break;}
        if(tmp=='.' || tmp=='T')tmp=g[j][j];
        else if(g[j][j]=='T')continue;
             else if(g[j][j]!=tmp) {flag=1; break;}
    }
    if(!flag)return tmp;
    flag=0,tmp='.';
    for(int j=0;j<4;++j)
    {
        if(g[j][3-j]=='.'){ flag=1; break;}
        if(tmp=='.' || tmp=='T')tmp=g[j][3-j];
        else if(g[j][3-j]=='T')continue;
             else if(g[j][3-j]!=tmp) { flag=1; break;}
    }
    if(!flag)return tmp;
    return '.';
}
int main()
{
    int t;
//    freopen("A-small-attempt0.in","r",stdin);
//    freopen("output.txt","w",stdout);
//    freopen("1","r",stdin);
    scanf("%d\n",&t);
    for(int cas=1;cas<=t;++cas)
    {
        for(int i=0;i<4;++i)gets(g[i]);
        char flag='.';
        for(int i=0;i<4;++i)
        {
            if(flag=='.')flag=row(i);
            else break;
            if(flag=='.')flag=col(i);
            else break;
        }
        if(flag=='.')flag=dia();        
        printf("Case #%d: ",cas);
        if(flag!='.')printf("%c won\n",flag);
        else 
        {
            int emp=0;
            for(int i=0;i<4;++i)
                for(int j=0;j<4;++j)if(g[i][j]=='.')emp=1;
            if(emp)puts("Game has not completed");
            else puts("Draw");
        }
        scanf("\n");
    }
    return 0;
}
