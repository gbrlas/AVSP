#include<cstdio>
#include<cstring>
using namespace std;
short change[13][28];
bool mark[28][1008];
char s[1008],temps[8],now;
int main()
{
    freopen("in.txt","r",stdin);
    int n,flag,cc;
    while(scanf("%d",&n)>0)
    {
        scanf("%s",s);
        getchar();
        while(gets(temps),temps[1]!='n')
        {
            change[temps[4]-'0'][temps[6]-'A']=temps[0];
            change[temps[4]-'0'][temps[6]-'A']<<=1;
            change[temps[4]-'0'][temps[6]-'A']|=temps[2]=='R';
        }
        now='A',flag=0;
        memset(mark,0,sizeof(mark));
        while(!mark[now-'A'][n])
        {
            mark[now-'A'][n]=1;
            cc=change[s[n]-'0'][now-'A']&1;
            now=change[s[n]-'0'][now-'A']>>1;
            if(now=='H'){ flag=1; break; }
            n=n+(cc==0?-1:1);
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
}