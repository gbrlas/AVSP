#include<iostream>
#include<stdio.h>
using namespace std;
int g[5][5];
bool iscompleted;
int wins;
void work(int x0,int y0,int dx,int dy)
{
    int x,y,c=0;
    if (iscompleted==false)
    {
        int tt=0;
        int i;
        for (i=0;i<4;i++)
        {
            x=x0+dx*i;
            y=y0+dy*i;
            if (g[x][y]==1 || g[x][y]==2)
            {
                if (tt)
                {
                    if (tt!=g[x][y]) break;
                }
                else tt=g[x][y];
                c++;
            }
        }
        if (i==4 && c>=3)
        {
            iscompleted=true;
            wins=tt;
        }
    }
}
int main()
{
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for (int CaseNum=1;CaseNum<=t;CaseNum++)
    {
        string s;
        int c=0;
        for (int i=1;i<=4;i++)
        {
            cin>>s;
            for (int j=0;j<4;j++)
                switch (s[j])
            {
                case 'X' : g[i][j+1]=1;c++; break;
                case 'O' : g[i][j+1]=2;c++; break;
                case 'T' : g[i][j+1]=3;c++; break;
                case '.' : g[i][j+1]=0; break;
            }
        }
        //check
        iscompleted=false;
        for (int i=1;i<=4;i++)
        {
            work(1,i,1,0);
            work(i,1,0,1);
        }
        work(1,1,1,1);
        work(1,4,1,-1);
        if (iscompleted)
        {
            char ch;
            if (wins==1) ch='X';
            else ch='O';
            printf("Case #%d: %c won\n",CaseNum,ch);
        }
        else if (c==16)
            printf("Case #%d: Draw\n",CaseNum);
        else
            printf("Case #%d: Game has not completed\n",CaseNum);
    }
    return 0;
}
