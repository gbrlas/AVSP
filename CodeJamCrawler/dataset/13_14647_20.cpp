#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
int main()
{
    ofstream fout ("output.out");
    ifstream fin ("A-small-attempt0.in");
    int t;
    char c[4][4],a,flag;
    fin>>t;
    for(int x=1;x<=t;x++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                fin>>c[i][j];
            }
        }
        for(int i=0;i<4;i++)
        {
            flag=0;
            if(c[i][0]!='.')
            {
                a=c[i][0];
                if(c[i][0]=='T')
                {
                    if(c[i][1]!='.')
                    {
                        a=c[i][1];
                        for(int j=2;j<4;j++)
                        {
                            if(c[i][j]!=a)
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        flag=1;
                    }
                }
                else
                {
                    for(int j=1;j<4;j++)
                    {
                        if(c[i][j]!=a && c[i][j]!='T')
                        {
                            flag=1;
                            break;
                        }
                    }
                }

            }
            else
            {
                flag=1;
            }
            if(flag==0)
            {

                fout<<"Case #"<<x<<": "<<a<<" won"<<endl;
                 break;
            }

        }
        if(flag==1)
        {

        for(int i=0;i<4;i++)
        {
            flag=0;
            if(c[0][i]!='.')
            {
                a=c[0][i];
                if(c[0][i]=='T')
                {
                    if(c[1][i]!='.')
                    {
                        a=c[1][i];
                        for(int j=2;j<4;j++)
                        {
                            if(c[j][i]!=a)
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        flag=1;
                    }
                }
                else
                {
                    for(int j=1;j<4;j++)
                    {
                        if(c[j][i]!=a && c[j][i]!='T')
                        {
                            flag=1;
                            break;
                        }
                    }
                }

            }
            else
                    {
                        flag=1;
                    }
            if(flag==0)
            {

                fout<<"Case #"<<x<<": "<<a<<" won"<<endl;
                break;
            }
        }
        if(flag==1)
        {
            flag=0;
            if(c[0][0]!='.')
            {
                a=c[0][0];
                if(c[0][0]=='T')
                {
                    if(c[1][1]!='.')
                    {
                        a=c[1][1];
                        for(int i=2;i<4;i++)
                        {
                            if(a!=c[i][i])
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        flag=1;
                    }

                }
                else
                {
                    for(int i=1;i<4;i++)
                        {
                            if(a!=c[i][i])
                            {
                                flag=1;
                                break;
                            }
                        }
                }

            }
            else
                    {
                        flag=1;
                    }
            if(flag==0)
            {

                fout<<"Case #"<<x<<": "<<a<<" won"<<endl;

            }
            else if(flag==1)
        {
            flag=0;
            if(c[3][0]!='.')
            {
                a=c[3][0];
                if(c[3][0]=='T')
                {
                    if(c[2][1]!='.')
                    {
                        a=c[2][1];
                        for(int i=1;i>=0;i--)
                        {
                            if(a!=c[i][3-i])
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        flag=1;
                    }

                }
                else
                {
                    for(int i=1;i<4;i++)
                        {
                            if(a!=c[i][3-i])
                            {
                                flag=1;
                                break;
                            }
                        }
                }

            }
            else
                    {
                        flag=1;
                    }
            if(flag==0)
            {

                fout<<"Case #"<<x<<": "<<a<<" won"<<endl;

            }
            else if(flag==1)
        {
            flag=0;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(c[i][j]=='.')
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    break;
                }
            }
            if(flag==1)
            {
                fout<<"Case #"<<x<<": "<<"Game has not completed"<<endl;
            }
            else
            {
                fout<<"Case #"<<x<<": "<<"Draw"<<endl;
            }
        }

        }

        }


      }

    }

    return 0;
}
