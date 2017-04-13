#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t,c,d;
int m[30][30];
int op[30][30],co,x;
char s[10],ans[205];
int main()
{
        freopen("inB.txt","r",stdin);
        freopen("outB.txt","w",stdout);
        scanf("%d",&t);
        for(int r=1;r<=t;r++)
        {
                for(int i=1;i<=26;i++)
                {
                        for(int j=1;j<=26;j++)
                        {
                                m[i][j]=0;
                        }
                }
                scanf("%d",&c);
                for(int i=0;i<c;i++)
                {
                        scanf("%s",s);
                        m[s[0]-'A'+1][s[1]-'A'+1]=s[2]-'A'+1;
                        m[s[1]-'A'+1][s[0]-'A'+1]=s[2]-'A'+1;
                }
                scanf("%d",&d);
                for(int i=0;i<d;i++)
                {
                        scanf("%s",s);
                        op[s[0]-'A'+1][s[1]-'A'+1]=r;
                        op[s[1]-'A'+1][s[0]-'A'+1]=r;
                }
                co=0;
                scanf("%d",&x);
                scanf("%s",s);
                for(int i=0;i<x;i++)
                {
                        if(co==0)
                        {
                                ans[co]=s[i];
                                co++;
                        }
                        else
                        {
                                if(m[ans[co-1]-'A'+1][s[i]-'A'+1]!=0)
                                {
                                        ans[co-1]=m[ans[co-1]-'A'+1][s[i]-'A'+1]+'A'-1;
                                }
                                else
                                {
                                        for(int j=0;j<co;j++)
                                        {
                                                if(op[s[i]-'A'+1][ans[j]-'A'+1]==r)
                                                {
                                                        co=0;
                                                        break;
                                                }
                                        }
                                        if(co!=0)
                                        {
                                                ans[co]=s[i];
                                                co++;
                                        }
                                }
                        }
                        /*printf("T%d %d %d\n",co,i,x);
                        for(int j=0;j<co;j++)
                        {
                                printf("DD%c",ans[j]);
                        }
                        printf("\n");*/
                        //system("pause");
                }
                printf("Case #%d: [",r);
                for(int i=0;i<co;i++)
                {
                        if(i!=0) printf(", ");
                        printf("%c",ans[i]);
                }
                printf("]\n");
        }
        //system("pause");
}
