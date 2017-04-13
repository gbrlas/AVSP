#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t,r,c;
char a[55][55];
bool mark;
int main()
{
        freopen("inA2.txt","r",stdin);
        freopen("outA2.txt","w",stdout);
        scanf("%d",&t);
        for(int rr=1;rr<=t;rr++)
        {
                scanf("%d %d",&r,&c);
                mark=0;
                for(int i=0;i<r;i++)
                {
                        scanf("%s",a[i]);
                }
                for(int i=0;i<r;i++)
                {
                        for(int j=0;j<c;j++)
                        {
                                if(a[i][j]=='#')
                                {
                                        if(i==r-1 || j==c-1 || a[i][j+1]!='#' || a[i+1][j]!='#' || a[i+1][j+1]!='#')
                                        {
                                                mark=1;
                                        }
                                        else
                                        {
                                                a[i][j]='/';
                                                a[i][j+1]='@';
                                                a[i+1][j]='@';
                                                a[i+1][j+1]='/';
                                        }
                                }
                        }
                } 
                printf("Case #%d:\n",rr);
                if(mark)
                {
                        printf("Impossible\n");
                }
                else
                {
                        for(int i=0;i<r;i++)
                        {
                                for(int j=0;j<c;j++)
                                {
                                        if(a[i][j]=='@')
                                        {
                                                printf("\\");
                                        }
                                        else
                                        {
                                                printf("%c",a[i][j]);
                                        }
                                }
                                printf("\n");
                        }
                }
        }
        //system("pause");
}
