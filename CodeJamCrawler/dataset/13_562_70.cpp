#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int main()
{
    int t,turn=0;
    fstream myf,f2;
    myf.open("input.txt",ios::in|ios::app);
    f2.open("output.txt",ios::out);
    char ar[4][4];
    if(myf.is_open())
    {
        myf>>t;
        //cin>>t;
        //getline(cin,line);
        while(t--)
        {
            turn++;
            int dot=0,value=0;
            for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                myf>>ar[i][j];
                if(ar[i][j]=='.')
                dot++;
            }
                //horizontal
                int x=0,o=0,t=0;
                for(int i=0;i<4;i++)
                {
                    x=0;o=0;t=0;
                    for(int j=0;j<4;j++)
                    {
                        if(x!=0&&o!=0)
                        break;
                        if(ar[i][j]=='O')
                        o++;
                        else if(ar[i][j]=='X')
                        x++;
                        else if(ar[i][j]=='T')
                        t++;
                    }
                    if(t==1)
                    {
                        if(x==3)
                        {
                            f2<<"Case #"<<turn<<": X won\n";
                            value=1;
                            continue;
                        }
                        else if(o==3)
                        {
                            f2<<"Case #"<<turn<<": O won\n";
                            value=1;
                            continue;
                        }
                    }
                    else if(x==4)
                    {
                        f2<<"Case #"<<turn<<": X won\n";
                        value=1;
                        continue;
                    }
                    else if(o==4)
                    {
                        f2<<"Case #"<<turn<<": O won\n";
                        value=1;
                        continue;
                    }
                }
                if(value==1)
                continue;
                //vertical
                for(int j=0;j<4;j++)
                {
                    x=0;o=0;t=0;
                    for(int i=0;i<4;i++)
                    {
                        if(x!=0&&o!=0)
                        break;
                        if(ar[i][j]=='O')
                        o++;
                        else if(ar[i][j]=='X')
                        x++;
                        else if(ar[i][j]=='T')
                        t++;
                    }
                    if(t==1)
                    {
                        if(x==3)
                        {
                            f2<<"Case #"<<turn<<": X won\n";
                            value=1;continue;
                        }
                        else if(o==3)
                        {
                            f2<<"Case #"<<turn<<": O won\n";
                            value=1;continue;
                        }
                    }
                    else if(x==4)
                    {
                        f2<<"Case #"<<turn<<": X won\n";
                        value=1;continue;
                    }
                    else if(o==4)
                    {
                        f2<<"Case #"<<turn<<": O won\n";
                        value=1;continue;
                    }
                }
                if(value==1)
                continue;
                //Right diagonal
                    x=0;o=0;t=0;
                    for(int i=0;i<4;i++)
                    {
                                if(x!=0&&o!=0)
                                break;
                                if(ar[i][i]=='O')
                                o++;
                                else if(ar[i][i]=='X')
                                x++;
                                else if(ar[i][i]=='T')
                                t++;
                    }
                    if(t==1)
                    {
                        if(x==3)
                        {
                            f2<<"Case #"<<turn<<": X won\n";
                            value=1;continue;
                        }
                        else if(o==3)
                        {
                            f2<<"Case #"<<turn<<": O won\n";
                            value=1;continue;
                        }
                    }
                    else if(x==4)
                    {
                        f2<<"Case #"<<turn<<": X won\n";
                        value=1;continue;
                    }
                    else if(o==4)
                    {
                        f2<<"Case #"<<turn<<": O won\n";
                        value=1;continue;
                    }
                    if(value==1)
                    continue;
                    //left diagonal
                    x=0;o=0;t=0;
                    for(int i=3;i>=0;i--)
                    {
                                if(x!=0&&o!=0)
                                break;
                                if(ar[i][3-i]=='O')
                                o++;
                                else if(ar[i][3-i]=='X')
                                x++;
                                else if(ar[i][3-i]=='T')
                                t++;
                    }
                    //f2<<"left diagonal "<<o<<" "<<x<<" "<<t<<endl;
                    if(t==1)
                    {
                        if(x==3)
                        {
                            f2<<"Case #"<<turn<<": X won\n";
                            value=1;
                            continue;
                        }
                        else if(o==3)
                        {
                            f2<<"Case #"<<turn<<": O won\n";
                            value=1;
                            continue;
                        }
                    }
                    else if(x==4)
                    {
                        f2<<"Case #"<<turn<<": X won\n";
                        value=1;
                        continue;
                    }
                    else if(o==4)
                    {
                        f2<<"Case #"<<turn<<": O won\n";
                        value=1;continue;
                    }
                    // After checking all the conditions game is draw if there is no dot
                    if(dot==0)
                    {
                        f2<<"Case #"<<turn<<": Draw\n";
                        value=1;continue;
                    }
                    f2<<"Case #"<<turn<<": Game has not completed\n";
    }
    }
    return 0;
}
