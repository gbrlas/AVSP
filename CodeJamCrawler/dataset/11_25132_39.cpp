#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t;
char a[505][505];
bool mark;
int r,c,d;
double midx,midy,sumx,sumy;
int main()
{
        freopen("inB.txt","r",stdin);
        freopen("outB.txt","w",stdout);
        scanf("%d",&t);
        for(int rr=1;rr<=t;rr++)
        {
                mark=0;
                scanf("%d %d %d",&r,&c,&d);
                for(int i=1;i<=r;i++)
                {
                        scanf("%s",a[i]+1);
                }
                printf("Case #%d: ",rr);
                for(int i=min(r,c);i>2;i--)
                {
                        for(int j=1;j+i-1<=r;j++)
                        {
                                for(int k=1;k+i-1<=c;k++)
                                {
                                        midx=(k+(k+i-1))/2.0;
                                        midy=(j+(j+i-1))/2.0;
                                        //printf("%lf %lf\n",midy,midx);
                                        sumx=0;
                                        sumy=0;
                                        for(int p=j;p<=j+i-1;p++)
                                        {
                                                for(int q=k;q<=k+i-1;q++)
                                                {
                                                        if(p==j && q==k) continue;
                                                        if(p==j+i-1 && q==k+i-1) continue;
                                                        if(p==j+i-1 && q==k) continue;
                                                        if(p==j && q==k+i-1) continue;
                                                        sumx+=(q-midx)*(a[p][q]-'0');
                                                        sumy+=(p-midy)*(a[p][q]-'0');
                                                        /*if(i==5 && j==2 && k==2)
                                                        {
                                                                printf("%d %d %c %lf %lf\n",p,q,a[p][q],(p-midx)*(a[p][q]-'0'),(q-midy)*(a[p][q]-'0'));
                                                                printf("%lf %lf\n",sumx,sumy);
                                                                system("pause");
                                                        }*/
                                                }
                                        }
                                        if(sumx==0 && sumy==0)
                                        {
                                                mark=1;
                                                printf("%d\n",i);
                                                //printf("%d %d\n",j,k);
                                                break;
                                        }
                                }
                                if(mark) break;
                        }
                        if(mark) break;
                }
                if(!mark)
                {
                        printf("IMPOSSIBLE\n");
                }
        }
        //system("pause");
}
