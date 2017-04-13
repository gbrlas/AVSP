#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int t,n,r;
double w,l;
struct node {
        int num;
        double va;
        bool operator < (const node &o) const { return va<o.va; }
}rr[1005];
double ra[1005];
double nowx,maxx,dist,x[1005],y[1005],ans[1005][2];
main()
{
        freopen("Bin.txt","r",stdin);
        freopen("Bout.txt","w",stdout);
        scanf("%d",&t);
        for(r=1;r<=t;r++)
        {
                scanf("%d %lf %lf",&n,&w,&l);
                for(int i=0;i<n;i++)
                {
                        scanf("%lf",&rr[i].va);
                        ra[i]=rr[i].va;
                        rr[i].num=i;
                }
                sort(&rr[0],&rr[n]);
                nowx=-rr[0].va;
                maxx=0;
                for(int i=0;i<n;i++)
                {
                        nowx+=rr[i].va+0.0001;
                        if(nowx>w) nowx=0;
                        for(int j=0;j<i;j++)
                        {
                                dist = sqrt((rr[i].va+rr[j].va)*(rr[i].va+rr[j].va)-(x[j]-nowx)*(x[j]-nowx))+y[j];
                                if((rr[i].va+rr[j].va)*(rr[i].va+rr[j].va)-(x[j]-nowx)*(x[j]-nowx)<0) dist = 0;
                                //printf("%d %d %lf\n",i,j,dist);
                                if(dist>maxx) maxx=dist;
                        }
                        maxx+=0.0001;
                        x[i]=nowx;
                        y[i]=maxx;
                        if(x[i]>w)
                        {
                                //printf("%lf %lf\n",x[i],w);
                                //printf("ERROR\n");
                        }
                        if(y[i]>l)
                        {
                                //printf("%lf %lf\n",y[i],l);
                                //printf("ERROR\n");
                        }
                        ans[rr[i].num][0]=x[i];
                        ans[rr[i].num][1]=y[i];
                        nowx+=rr[i].va;
                }                
                //check ans
                for(int i=0;i<n;i++)
                {
                        for(int j=i+1;j<n;j++)
                        {
                                if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=(rr[i].va+rr[j].va)*(rr[i].va+rr[j].va))
                                {
                                       // printf("%lf %lf %lf %lf\n",x[i],y[i],x[j],y[j]);
                                       //printf("ERROR\n");
                                }
                        }
                }
                printf("Case #%d:",r);         
                for(int i=0;i<n;i++)
                {
                        printf(" %.6lf",ans[i][0]);
                        printf(" %.6lf",ans[i][1]);
                }
                printf(" \n");                 
                for(int i=0;i<n;i++)
                {
                        //if(ans[i][0]<0 || ans[i][0]>w) printf("ERROR\n");
                        //if(ans[i][1]<0 || ans[i][1]>l) printf("ERROR\n");
                        for(int j=i+1;j<n;j++)
                        {
                                //if((ans[i][0]-ans[j][0])*(ans[i][0]-ans[j][0])+(ans[i][1]-ans[j][1])*(ans[i][1]-ans[j][1])<=(ra[i]+ra[j])*(ra[i]+ra[j]))
                                //printf("ERROR\n");
                        }
                }
        }
}
