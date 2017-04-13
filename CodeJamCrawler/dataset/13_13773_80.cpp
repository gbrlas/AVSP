
#include <iostream>
#include <stdio.h>
#include <cstring>
enum winner{DRAW,X_,O_,NOT_END,NO_RESULT};
const int O=1,X=25,EMPTY=0,ANY=5;
using namespace std;
int sum(int src[4])
{
    int sum;
    for(int i=0;i<4;i++)
        sum+=src[i];
    return sum;
}
winner get_arr(int a[4][4])
{
    winner game=NO_RESULT;
    for(int i=0;i<4;i++)
    {
        char s[5];
        cin>>s;
        for(int j=0;j<4;j++)
        {
            char c=s[j];
            if(c=='O')
                a[i][j]=O;
            if(c=='X')
                a[i][j]=X;
            if(c=='.'){
                
                a[i][j]=EMPTY;
                game=NOT_END;
            }
            if(c=='T')a[i][j]=ANY;
        }
    }
    return game;
}
void wins(int a[4][4],winner& game)
{

    if(game==NO_RESULT)
        game=DRAW;
    for(int i=0;i<4;i++)
    {
        int sm=a[i][0]+a[i][1]+a[i][2]+a[i][3];
        if((sm==100) || (sm==80))
        {
            game=X_;
            return ;
        }
        if((sm==4) || (sm==8))
        {
            game=O_;
            return ;
        }
    }
    for(int i=0;i<4;i++)
    {
        int sm=a[0][i]+a[1][i]+a[2][i]+a[3][i];
        if(sm==100 || sm==80)
            game=X_;
        if(sm==4 || sm==8)
            game=O_;
    }
    
    int _sm=a[0][0]+a[1][1]+a[2][2]+a[3][3];
    if((_sm==100) || (_sm==80))
        game=X_;
    if((_sm==4) || (_sm==8))
        game=O_;
    int sum_=a[0][3]+a[1][2]+a[2][1]+a[3][0];
    if((sum_==100) || (sum_==80))
        game=X_;
    if((sum_==4) || (sum_==8))
        game=O_;

}
int main(int argc, const char * argv[])
{
    freopen("/Users/igorm/Documents/1.txt","w",stdout
            );
    const char *ans[20]={"Draw","X won","O won","Game has not completed","BEBE"};
    winner game=NO_RESULT;
    int a[4][4];
    int T;
    cin>>T;
    for(int j=0;j<T;j++)
    {
        game=get_arr(a);
        
        wins(a,game);
        cout<<"Case #"<<
        j+1<<": "<<ans[game]<<endl;
    }
    return 0;
}

