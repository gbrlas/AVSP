#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
int vis[100],vis2[100],linjie[100][100],huchi[100][100];
char k1[1000],k2[1000],k3[1000];
vector<int>pp;
vector<int>::iterator it;
int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int a,b,c,m,i,j,k,n,h1,h2,h3,tap=0,qq;
    char p1,p2,p3;
    scanf("%d",&m);
    for(int kk=1; kk<=m; kk++)
    {
        memset(linjie,0,sizeof(linjie));
        memset(huchi,0,sizeof(huchi));
        pp.clear();
        scanf("%d",&a);
        for(i=1; i<=a; i++)
        {
            scanf("%s",k1);
            p1=k1[0];
            p2=k1[1];
            p3=k1[2];
            h1=p1-'A'+1;
            h2=p2-'A'+1;
            h3=p3-'A'+1;
            linjie[h1][h2]=h3;
            linjie[h2][h1]=h3;
        }
        scanf("%d",&b);
        for(i=1; i<=b; i++)
        {
            scanf("%s",k1);
            p1=k1[0];
            p2=k1[1];
            h1=p1-'A'+1;
            h2=p2-'A'+1;
            huchi[h1][h2]=1;
            huchi[h2][h1]=1;
        }
        scanf("%d",&qq);
        scanf("%s",k3);
        memset(vis,0,sizeof(vis));
        c=k3[0]-'A'+1;
        pp.push_back(c);
        n=strlen(k3);
        for(i=1; i<=26; i++)
            if(linjie[c][i]!=0)
                vis[i]=linjie[c][i];
        for(i=1; i<=n-1; i++)
        {
            c=k3[i]-'A'+1;
            if(vis[c]!=0)
            {
                it=pp.end();
                it--;
                pp.erase(it);
                pp.push_back(vis[c]);
                memset(vis,0,sizeof(vis));
            }
            else
            {
                tap=0;
                for(j=0; j<pp.size(); j++)
                    if(huchi[pp[j]][c]>0)
                        tap=1;
                if(tap==1)
                {
                    pp.clear();
                    memset(vis,0,sizeof(vis));
                }
                else
                {
                    pp.push_back(c);
                    memset(vis,0,sizeof(vis));
                    for(j=1; j<=26; j++)
                        if(linjie[c][j]!=0)
                            vis[j]=linjie[c][j];
                }
            }

        }
        printf("Case #%d: ",kk);
        if(pp.size()==0)
            printf("[]\n");
        else
        {
            printf("[");
            for(i=0; i<pp.size()-1; i++)
                printf("%c, ",pp[i]+'A'-1);
            printf("%c]",pp[i]+'A'-1);
             printf("\n");
        }
    }
}
