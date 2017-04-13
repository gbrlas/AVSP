#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;


const int MaxN=111;
char ch;
int Testnum,N,cur,need_time,pos[2],tim[2];

struct robot
{
    int col,num;
} a[MaxN];


void init()
{
    scanf("%d",&N);
    for (int i=1; i<=N; ++i)
    {
        ch=getchar();
        while (ch==' ') ch=getchar();
        if (ch=='O') a[i].col=0;
        else a[i].col=1;
        scanf("%d",&a[i].num);
    }
}

void run()
{
    pos[0]=1; tim[0]=0;
    pos[1]=1; tim[1]=0;
    cur=0;
    for (int i=1; i<=N; ++i)
    {
        need_time=abs(a[i].num-pos[a[i].col]);
        cur=max(cur,tim[a[i].col]+need_time)+1;
        tim[a[i].col]=cur;
        pos[a[i].col]=a[i].num;
    } 
    printf("%d\n",cur);
} 

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    
    scanf("%d",&Testnum);
    for (int Test=1; Test<=Testnum; ++Test)
    {
        printf("Case #%d: ",Test);
        init();
        run();
    }
    
    return 0;
}
