#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t;
int n;
char a[105][105];
int nw,na,nub;
double wp[105],owp[105],oowp[105];
int main()
{
        freopen("inA.txt","r",stdin);
        freopen("outA.txt","w",stdout);
        scanf("%d",&t);
        for(int r=1;r<=t;r++)
        {
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                {
                        scanf("%s",a[i]);
                }
                //find WP
                for(int i=0;i<n;i++)
                {
                        nw=0;
                        na=0;
                        for(int j=0;j<n;j++)
                        {
                                if(a[i][j]=='1')
                                {
                                        nw++;
                                }
                                if(a[i][j]!='.')
                                {
                                        na++;
                                }
                        }               
                        if(na!=0)
                        wp[i]=nw*1.0/na;
                        else wp[i]=0;
                }
                //find OWP
                for(int i=0;i<n;i++)
                {
                        owp[i]=0;
                        nub=0;
                        for(int j=0;j<n;j++)
                        {
                                if(a[i][j]!='.')
                                {
                                        nub++;
                                        nw=0;
                                        na=0;
                                        for(int k=0;k<n;k++)
                                        {
                                                if(k!=i)
                                                {
                                                        if(a[j][k]=='1')
                                                        {
                                                                nw++;
                                                        }
                                                        if(a[j][k]!='.')
                                                        {
                                                                na++;
                                                        }
                                                }
                                        }
                                        //printf("%d %d %d %d\n",i,j,nw,na);
                                        owp[i]+=(nw*1.0/na);
                                }
                        }
                        if(nub!=0)
                        owp[i]/=nub;
                }
                //find oowp
                for(int i=0;i<n;i++)
                {
                        oowp[i]=0;
                        nub=0;
                        for(int j=0;j<n;j++)
                        {
                                if(a[i][j]!='.')
                                {
                                        nub++;
                                        oowp[i]+=owp[j];
                                }
                        }
                        if(nub!=0)
                        oowp[i]/=nub;
                }       
                printf("Case #%d:\n",r);
                for(int i=0;i<n;i++)
                {
                        //printf("%lf %lf %lf\n",wp[i],owp[i],oowp[i]);
                        printf("%.12lf\n",wp[i]/4+owp[i]/2+oowp[i]/4);
                }
        }        
        //system("pause");               
}
