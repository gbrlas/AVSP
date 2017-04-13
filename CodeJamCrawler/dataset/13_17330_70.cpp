#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, s, t) for(i = (s); i < (t); i++)
#define rrep(i, s, t) for(i = (s)-1; i >= (t); i--)

using namespace std;

int t,n,s,p;
int min_,min_s;
vector<int> v;
int ret;
char board[4][4];
char w;
bool isX(char c) { return (c=='X'||c=='T'); }
bool isO(char c) { return (c=='O'||c=='T'); }
void calc()
{
    int i,j,x,o;
    w='T';
    //rows
    rep(i,0,4) {
        x=o=0;
        rep(j,0,4) {
            if(isX(board[i][j])) x++;
            if(isO(board[i][j])) o++;
        }
        if(x==4) {w='X';return;}
        if(o==4) {w='O';return;}
    }
    //columns
    rep(i,0,4) {
        x=o=0;
        rep(j,0,4) {
            if(isX(board[j][i])) x++;
            if(isO(board[j][i])) o++;
        }
        if(x==4) {w='X';return;}
        if(o==4) {w='O';return;}
    }
    //diags
    x=o=0;
    rep(i,0,4) {
        if(isX(board[i][i])) x++;
        if(isO(board[i][i])) o++;
    }
    if(x==4) {w='X';return;}
    if(o==4) {w='O';return;}
    x=o=0;
    rep(i,0,4) {
        if(isX(board[i][3-i])) x++;
        if(isO(board[i][3-i])) o++;
    }
    if(x==4) {w='X';return;}
    if(o==4) {w='O';return;}

    rep(i,0,4)
        rep(j,0,4)
            if(board[i][j]=='.') w='.';
}
void input()
{
    string line;
    for(int i=0;i<4;i++) {
        cin>>line;
        for(int j=0;j<4;j++)
            board[i][j]=line[j];
    }
}
void output(int ncase)
{
    printf("Case #%d: ",ncase);
    if(w=='X' || w=='O')
        printf("%c won\n",w);
    if(w=='.')
        printf("Game has not completed\n");
    if(w=='T')
        printf("Draw\n");
}
int main(void)
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        input();
        calc();
        output(i+1);
    }
    return 0;
}
