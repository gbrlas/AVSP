#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
    ofstream ki;
    ki.open("A.txt");
    ifstream be;
    be.open("A-small-attempt0.in");
    int T;
    be >>T;
    for(int t=1;t<=T;t++)
    {
        int r1,r2;
        bool atmeneti[17]={0};
        int board[5][5]={0};
        be >> r1;
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                be >> board[i][j];
            }
        }
        for(int i=1;i<=4;i++)
        {
            atmeneti[board[r1][i]]=true;
        }
        be >> r2;
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                be >> board[i][j];
            }
        }
        int a=0,b=0;
        for(int i=1;i<=4;i++)
        {
            if(atmeneti[board[r2][i]]==true)
            {
                a++;
                b=board[r2][i];
            }
        }
        ki << "Case #" << t <<": ";
        if(a==1)
        {
            ki << b <<endl;
        } else if (a>=2)
        {
            ki <<"Bad magician!"<<endl;
        }
        else if(a==0)
        {
            ki<<"Volunteer cheated!"<<endl;
        }
    }
    be.close();
    ki.close();
    return 0;
}
//CodeBlocks 13.12,Win8.1
