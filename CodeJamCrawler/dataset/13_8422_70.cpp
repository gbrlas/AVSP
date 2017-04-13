#include <iostream>
#include <cstdio>
#include <cstring >
#include <cstdlib>
#include <algorithm>

using namespace std;

#define IM 5
char g[IM][IM];
bool hasEmpty,xWon,oWon;

bool Judge(int cx,int co,int ct)
{
    if(cx == 4 || (cx == 3 && ct == 1))
    {
        xWon = true;
        return true;
    }
    if(co == 4 || (co == 3 && ct == 1))
    {
        oWon = true;
        return true;
    }

    return false;
}

void Deal()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(g[i][j] =='.')
            {
                hasEmpty = true;
                break;
            }

    int cx,co,ct;
    for(int i = 0; i < 4; i++)
    {

        cx = co = ct = 0;
        for(int j = 0; j < 4; j++)
        {
            if(g[i][j] == 'X')
                cx++;
            else if(g[i][j] == 'O')
                co++;
            else if(g[i][j] == 'T')
                ct++;
        }
        if(Judge(cx,co,ct)) return;
        cx = co = ct = 0;
        for(int j = 0; j < 4; j++)
        {
            if(g[j][i] == 'X')
                cx++;
            else if(g[j][i] == 'O')
                co++;
            else if(g[j][i] == 'T')
                ct++;
        }
        if(Judge(cx,co,ct)) return;
    }

    cx = co = ct = 0;
    for(int j = 0; j < 4; j++)
    {
        if(g[j][j] == 'X')
            cx++;
        else if(g[j][j] == 'O')
            co++;
        else if(g[j][j] == 'T')
            ct++;
    }
    if(Judge(cx,co,ct)) return;

    cx = co = ct = 0;
    for(int j = 0; j < 4; j++)
    {
        if(g[j][3-j] == 'X')
            cx++;
        else if(g[j][3-j] == 'O')
            co++;
        else if(g[j][3-j] == 'T')
            ct++;
    }
    if(Judge(cx,co,ct)) return;

}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    int T;
    scanf("%d",&T);
    for(int cas = 1; cas <= T; cas++)
    {
        memset(g,0,sizeof(g));
        for(int i = 0; i < 4; i++)
            scanf("%s",g[i]);
        hasEmpty = xWon = oWon = false;

        Deal();

        printf("Case #%d: ",cas);
        if(xWon)
            printf("X won\n");
        else if(oWon)
            printf("O won\n");
        else if(hasEmpty)
        {
            printf("Game has not completed\n");
        }
        else
        {
            printf("Draw\n");
        }
    }
    return 0;
}
