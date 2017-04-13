#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
#define sz
using namespace std;
int main ()
{
    freopen("test.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ll i,j,t,test,x,o,T,dot;
    bool drawflag,winflag;
    string a[6];
    cin>>test;
    for(t=1; t<=test; t++)
    {
        drawflag=winflag=0;
        for(i=0; i<4; i++)
            cin>>a[i];
        for(i=0; i<4; i++)
        {
            x=o=T=dot=0;
            for(j=0; j<4; j++)
            {
                if(a[i][j]=='X')
                    x++;
                else if(a[i][j]=='O')
                    o++;
                else if(a[i][j]=='.')
                    dot++,drawflag=1;
                else
                    T++;
            }
            if(x==4 || (x==3 && T==1))
            {
                winflag=1;
                printf("Case #%d: X won\n",t);
            }
            else if(o==4 || (o==3 && T==1))
            {
                winflag=1;
                printf("Case #%d: O won\n",t);
            }
            if(winflag)
                break;
        }
        if(!winflag)
        {
            for(i=0; i<4; i++)
            {
                x=o=T=dot=0;
                for(j=0; j<4; j++)
                {
                    if(a[j][i]=='X')
                        x++;
                    else if(a[j][i]=='O')
                        o++;
                    else if(a[j][i]=='.')
                        dot++,drawflag=1;
                    else
                        T++;
                }
                if(x==4 || (x==3 && T==1))
                {
                    winflag=1;
                    printf("Case #%d: X won\n",t);
                }
                else if(o==4 || (o==3 && T==1))
                {
                    winflag=1;
                    printf("Case #%d: O won\n",t);
                }
                if(winflag)
                    break;
            }
        }
        if(!winflag)
        {
            x=o=T=dot=0;
            for(i=0; i<4; i++)
            {
                if(a[i][3-i]=='X')
                    x++;
                else if(a[i][3-i]=='O')
                    o++;
                else if(a[i][3-i]=='.')
                    dot++,drawflag=1;
                else
                    T++;
            }
            if(x==4 || (x==3 && T==1))
            {
                winflag=1;
                printf("Case #%d: X won\n",t);
            }
            else if(o==4 || (o==3 && T==1))
            {
                winflag=1;
                printf("Case #%d: O won\n",t);
            }
        }
        if(!winflag)
        {
            x=o=T=dot=0;
            for(i=0; i<4; i++)
            {
                if(a[i][i]=='X')
                    x++;
                else if(a[i][i]=='O')
                    o++;
                else if(a[i][i]=='.')
                    dot++,drawflag=1;
                else
                    T++;
            }
            if(x==4 || (x==3 && T==1))
            {
                winflag=1;
                printf("Case #%d: X won\n",t);
            }
            else if(o==4 || (o==3 && T==1))
            {
                winflag=1;
                printf("Case #%d: O won\n",t);
            }

        }
        if(!winflag)
        {
            if(drawflag==0)
                printf("Case #%d: Draw\n",t);
            else
                printf("Case #%d: Game has not completed\n",t);
        }
    }

    return 0;
}
