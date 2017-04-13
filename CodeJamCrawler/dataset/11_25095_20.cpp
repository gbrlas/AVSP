#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int r,pd,pg,hh,t,h1,h2;
bool mark;
long long n,A,B,G,P1,P2;
int hrm(int h1,int h2)
{
        if(h2==0) return h1;
        return hrm(h2,h1%h2);
}
int main()
{
        freopen("inA.txt","r",stdin);
        freopen("outA.txt","w",stdout);
        scanf("%d",&t);
        for(int r=1;r<=t;r++)
        {
                printf("Case #%d: ",r);
                scanf("%I64d %d %d",&n,&pd,&pg);
                if(pg==100)
                {
                        if(pd==100)
                        {
                                printf("Possible\n");
                        }
                        else
                        {
                                printf("Broken\n");
                        }
                        continue;
                }        
                if(pg==0)
                {
                        if(pd==0)
                        {
                                printf("Possible\n");
                        }
                        else
                        {
                                printf("Broken\n");
                        }
                        continue;
                }                               
                mark=0;
                hh=hrm(pd,100);
                //printf("%d\n",100/hh);
                if(100/hh>n)
                {
                        mark=1;
                }
                else
                {
                        /*h1=pd/hh;
                        h2=100/hh;
                        B=n/h2*h2;
                        printf("%d %d AA%I64d\n",h1,h2,B);
                        A=B*h1/h2;
                        printf("%d %d BB%I64d\n",h1,h2,A);
                        hh=hrm(pg,100);
                        P1=pg/hh;
                        P2=100/hh;
                        
                        printf("%I64d %I64d %I64d %I64d %I64d\n",A,B,P1,P2,G);
                        if(P1*B-P2*A<0) mark=1;
                        else
                        {
                                G=(P1*B-P2*A)/(P2-P1);
                        printf("%I64d %I64d %I64d %I64d %I64d\n",A,B,P1,P2,G);
                                if(P2*(A+G)-P1*B<0)
                                {
                                        mark=1;
                                }
                        }*/
                }
                if(mark)
                printf("Broken\n");
                else
                printf("Possible\n");
        }
        //system("pause");
}       
