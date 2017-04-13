#include<iostream>
using namespace std;
void out(char stats,int tlmt){
    string phrase;
    if (stats=='x')phrase="X won";
    else if(stats=='o')phrase="O won";
    else if(stats=='d')phrase="Draw";
    else if(stats=='g')phrase="Game has not completed";
    cout<<"Case #"<<tlmt<<": "<<phrase<<endl;
}
bool check(char tb[][4],char c)
{
    bool win;

    //check horizontal
    for(int y=0;y<4;y++)
    {
        win=1;
        for(int x=0;x<4;x++)
        {
            if(tb[x][y]==c||tb[x][y]=='T');
            else
            {
                win=0;
                break;
            }
        }
        if (win==1)return win;
    }

    //check vertical
    for(int x=0;x<4;x++)
    {
        win=1;
        for(int y=0;y<4;y++)
        {
            if(tb[x][y]==c||tb[x][y]=='T');
            else
            {
                win=0;
                break;
            }
        }
        if (win==1)return win;
    }

    //check backward slash
    win=1;
    for(int x=0,y=0;x<4;x++,y++)
    {
        if(tb[x][y]==c||tb[x][y]=='T');
        else
        {
            win=0;
            break;
        }
    }
    if(win==1)return win;

    //check forward slash
    win=1;
    for(int x=0,y=3;x<4;x++,y--)
    {
        if(tb[x][y]==c||tb[x][y]=='T');
        else
        {
            win=0;
            break;
        }
    }
    return win;
}

bool dot(char tb[][4]){
    for(int y=0;y<4;y++)
    {
        for(int x=0;x<4;x++)
        {
            if (tb[x][y]=='.')return 1;
        }
    }
    return 0;
}
int main()
{
    int T;
    char tb[4][4];
    cin>>T;
    for(int tlmt=1;tlmt<=T;tlmt++)
    {
        for(int y=0;y<4;y++)
        {
            for(int x=0;x<4;x++)
            {
                cin>>tb[x][y];
            }
        }
        if (check(tb,'X'))out('x',tlmt);
        else if(check(tb,'O'))out('o',tlmt);
        else if(dot(tb))out('g',tlmt);
        else out('d',tlmt);
    }
}
