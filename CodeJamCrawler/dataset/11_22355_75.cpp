#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int p[200];
int dis[110][110][110];
int q[110*110*110]={0};

int calc(int od,int op,int bp)
{
    return (od*100+op)*100+bp;
}

int od[9]={1,1,1,0,0,0,-1,-1,-1},bd[9]={1,0,-1,1,0,-1,1,0,-1};

bool check(int op,int bp)
{
    return op>=0 && op<100 && bp>=0 && bp<100;
}

int bfs(int n)
{
    int ff=0,rr=1;
    
    memset(dis,0,sizeof dis);
    q[0]=calc(0,0,0);
    dis[0][0][0]=1;
    while(ff<rr)
    {
        int up,op,bp;

        bp=q[ff]%100;q[ff]/=100;
        op=q[ff]%100;q[ff]/=100;
        up=q[ff++];
        
        for(int i=0;i<9;i++)
        {
            if( check(op+od[i],bp+bd[i]) && !dis[up][op+od[i]][bp+bd[i]] )
            {
                dis[up][op+od[i]][bp+bd[i]]=dis[up][op][bp]+1;
                q[rr++]=calc(up,op+od[i],bp+bd[i]);
            }
        }
        if(op+1==p[up])
            for(int i=-1;i<=1;i++)
                if(check(op,bp+i) && !dis[up+1][op][bp+i])
                {
                    dis[up+1][op][bp+i]=dis[up][op][bp]+1;
                    if(up==n-1)
                        return dis[up][op][bp];
                    q[rr++]=calc(up+1,op,bp+i);
                }
        if(bp+1==-p[up])
            for(int i=-1;i<=1;i++)
                if(check(op+i,bp) && !dis[up+1][op+i][bp])
                {
                    dis[up+1][op+i][bp]=dis[up][op][bp]+1;
                    if(up==n-1)
                        return dis[up][op][bp];
                    q[rr++]=calc(up+1,op+i,bp);
                }
    }
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
    //freopen("A-large.in","r");freopen("A-large.out","w",stdout);
    int test;

    cin>>test;
    for(int times=1;times<=test;times++)
    {
        int n;
        string s;

        cin>>n;
        for(int i=0;i<n;i++)
        {
            int num;
            
            cin>>s;
            cin>>num;
            if(s[0]=='O') p[i]=num;
            else p[i]=-num;
        }
        printf("Case #%d: %d\n",times,bfs(n));
    }
    return 0;
}

