//google code jam 09 qualification round
//Welcome to Code Jam
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXN 550
int opt[20][MAXN];
char line[MAXN];
char sentence[20]="welcome to code jam";    //19 characters from 0 to 18

void work();

int main()
{
    int n;
    scanf("%d",&n);
    cin.get();
    for(int i=1;i<=n;++i)
    {
        printf("Case #%d: ",i);
        work();
    }
    return 0;
}

void work()
{
    int i,j,k,len;
    cin.getline(line,MAXN);
    memset(opt,0,sizeof(opt));
    len=strlen(line);
    //init
    for(i=0;i<len;++i)
        if(line[i]=='w') opt[0][i]=1;
    for(i=1;i<19;++i)
    {
        for(j=i;j<len;++j)
        {
            if(line[j]==sentence[i])
            {
                for(k=i-1;k<=j-1;++k)
                {
                    opt[i][j]+=opt[i-1][k];
                    opt[i][j] %=10000;
                }
            }
        }
    }
    int res=0;
    for(i=0;i<len;++i)
    {
        res+=opt[18][i];
        res%=10000;
    }
    printf("%04d\n",res);
}
