#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define bl 1
#define wh 2
#define no 0
#define yes 1
#define inf 999999


int ax1[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int ay1[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

int ax2[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int ay2[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

int ax3[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int ay3[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int ax4[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int ay4[]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18,-19,-20};

int ax5[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int ay5[]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18,-19,-20};

int ax6[]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18,-19,-20};
int ay6[]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18,-19,-20};

int ax7[]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18,-19,-20};
int ay7[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int ax8[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int ay8[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};


struct man
    {
        int st,en;
    };

    man s[100000];

bool com(man a,man b )
{
    if(a.st==b.st)
        return a.en<b.en;

    return a.st<b.st;
}

bool coma(man a,man b )
{
    if(a.en==b.en)
        return a.st<b.st;

    return a.en<b.en;
}


using namespace std;

int main()
{
    int i,j,test,n,t,k,c1,x,y,cas=0;
    char a[100][100],b[100][100];
    bool R,B;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>test;
    while(test--)
    {
        cin>>n>>t;
        R=false;
        B=false;

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                cin>>a[i][j];

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                b[i][j]='.';

        for(i=n;i>0;i--)
        {
            k=n;
            for(j=n;j>0;j--)
                if(a[i][j]!='.')
                    b[i][k--]=a[i][j];
        }

        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                cout<<b[i][j];
            cout<<endl;
        }*/


        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(b[i][j]=='R')
                {
                    //1
                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax1[k];
                        y=j+ay1[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        R=true;
                        goto blue;
                    }

                    //2
                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax2[k];
                        y=j+ay2[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        R=true;
                        goto blue;
                    }

                    //3
                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax3[k];
                        y=j+ay3[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        R=true;
                        goto blue;
                    }

                    //4

                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax4[k];
                        y=j+ay4[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        R=true;
                        goto blue;
                    }

                    //5

                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax5[k];
                        y=j+ay5[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        R=true;
                        goto blue;
                    }

                    //6
                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax6[k];
                        y=j+ay6[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        R=true;
                        goto blue;
                    }

                    //7
                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax7[k];
                        y=j+ay7[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        R=true;
                        goto blue;
                    }

                    //8
                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax8[k];
                        y=j+ay8[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        R=true;
                        goto blue;
                    }
                }
            }
        }
    blue:
            ;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(b[i][j]=='B')
                {
                    //1
                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax1[k];
                        y=j+ay1[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        B=true;
                        goto enl;
                    }

                    //2
                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax2[k];
                        y=j+ay2[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        B=true;
                        goto enl;
                    }

                    //3
                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax3[k];
                        y=j+ay3[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        B=true;
                        goto enl;
                    }

                    //4

                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax4[k];
                        y=j+ay4[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        B=true;
                        goto enl;
                    }

                    //5

                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax5[k];
                        y=j+ay5[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        B=true;
                        goto enl;
                    }

                    //6
                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax6[k];
                        y=j+ay6[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        B=true;
                        goto enl;
                    }

                    //7
                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax7[k];
                        y=j+ay7[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        B=true;
                        goto enl;
                    }

                    //8
                    c1=0;
                    for(k=0;k<t;k++)
                    {
                        x=i+ax8[k];
                        y=j+ay8[k];
                        if(x>0 && x<=n && y>0 && y<=n)
                            if(b[i][j]==b[x][y])
                                ++c1;
                            else
                                break;
                    }
                    if(c1==t-1)
                    {
                        B=true;
                        goto enl;
                    }
                }
            }
        }
    enl:
            ;

        if(R==true && B==true)
            printf("Case #%d: Both\n",++cas);
        else if(R==true && B==false)
            printf("Case #%d: Red\n",++cas);
        else if(R==false && B==true)
            printf("Case #%d: Blue\n",++cas);
        else
            printf("Case #%d: Neither\n",++cas);

    }


    return 0;
}
