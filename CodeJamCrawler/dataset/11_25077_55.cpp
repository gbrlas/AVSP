#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t,last[5],now[5],timee,in,in1,in2;
char s[5];
int main()
{
        freopen("out.txt","w",stdout);
        scanf("%d",&t);
        for(int i=0;i<t;i++)
        {
                last[0]=0;
                last[1]=0;
                now[0]=1;
                now[1]=1;
                timee=0;
                scanf("%d",&in);
                for(int j=0;j<in;j++)
                {
                        scanf("%s %d",s,&in2);
                        if(s[0]=='O')
                        {
                                in1=0;
                        }
                        else
                        {
                                in1=1;
                        }
                        if(abs(now[in1]-in2)>timee-last[in1])
                        {
                                timee=last[in1]+abs(now[in1]-in2);
                        }
                        timee++;
                        last[in1]=timee;
                        now[in1]=in2;
                        //printf("%d %d %d %d %d\n",timee,last[0],now[0],last[1],now[1]);
                }
                printf("Case #%d: %d\n",i+1,timee);
        }
        //system("pause");
}
