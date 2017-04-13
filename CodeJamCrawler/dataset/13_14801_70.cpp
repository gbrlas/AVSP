#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
char map[10][10];
bool judge_dia(char c)
{
    int flag = 0;

    if((map[0][0]==c || map[0][0]=='T') && (map[1][1]==c || map[1][1]=='T') && (map[2][2]==c || map[2][2]=='T') && (map[3][3]==c || map[3][3]=='T'))
        flag = 1;
    if((map[3][0]==c || map[3][0]=='T') && (map[2][1]==c || map[2][1]=='T') && (map[1][2]==c || map[1][2]=='T') && (map[0][3]==c || map[0][3]=='T'))
        flag = 1;
    return flag;
}
bool judge_row(char c)
{
    int flag = 0;
    for(int i=0; i<4; i++)
    {

        if((map[i][0]==c || map[i][0]=='T') && (map[i][1]==c || map[i][1]=='T') && (map[i][2]==c || map[i][2]=='T') &&(map[i][3]==c || map[i][3]=='T'))
            flag = 1;
    }
    return flag;
}
bool judge_col(char c)
{
    int flag = 0;
    for (int j=0; j<4; j++)
    {
        if((map[0][j]==c || map[0][j]=='T') && (map[1][j]==c || map[1][j]=='T') && (map[2][j]==c || map[2][j]=='T') && (map[3][j]==c || map[3][j]=='T'))
            flag = 1;
    }
    return flag;
}
bool check(char c)
{
    if(judge_dia(c)) return 1;
    if(judge_row(c)) return 1;
    if(judge_col(c)) return 1;
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int k = 0;
    bool flag=0;
    while(t--)
    {
        flag = 0;
        k++;
        for (int i=0; i<4; i++)
            scanf("%s",map[i]);
        char a = 'O';
        char b = 'X';
        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
                if(map[i][j]=='.')
                    flag = 1;
        printf("Case #%d: ",k);
        if(check(a))
            printf("O won\n");
        else if(check(b))
            printf("X won\n");
        else if(flag)
            printf("Game has not completed\n");
        else printf("Draw\n");
    }
    return 0;
}
