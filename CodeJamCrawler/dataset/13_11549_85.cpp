//
//  main.cpp
//  TTTT
//
//  Created by Akhil Verghese on 4/13/13.
//  Copyright (c) 2013 Akhil Verghese. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int t,x=0;
    char* board[4];
    bool flagO,flagX,flagnotComp,flagnotO,flagnotX;
    cin>>t;
    while(t--)
    {
        flagO=flagX=flagnotComp=0;
        x++;
        for(int i=0;i<4;i++)
        {
            board[i]=(char*)malloc(4);
            cin>>board[i];
        }
        for(int i=0;i<4;i++)
        {
            flagnotO=flagnotX=0;
            for(int j=0;j<4;j++)
            {
                if (board[i][j]=='O'|board[i][j]=='.')
                    flagnotX=1;
                if (board[i][j]=='X'|board[i][j]=='.')
                    flagnotO=1;
                if (board[i][j]=='.')
                    flagnotComp=1;
            }
            if(flagnotO==0)
                flagO=1;
            if(flagnotX==0)
                flagX=1;
        }
        
        if(!flagO&!flagX)
        {
            for(int i=0;i<4;i++)
            {
                flagnotO=flagnotX=0;
                for(int j=0;j<4;j++)
                {
                    if (board[j][i]=='O'|board[j][i]=='.')
                        flagnotX=1;
                    if (board[j][i]=='X'|board[j][i]=='.')
                        flagnotO=1;
                }
                if(flagnotO==0)
                    flagO=1;
                if(flagnotX==0)
                    flagX=1;
            }
        }
        if(!flagO&!flagX)
        {
            flagnotO=flagnotX=0;
            for(int i=0;i<4;i++)
            {
                if (board[i][i]=='O'|board[i][i]=='.')
                    flagnotX=1;
                if (board[i][i]=='X'|board[i][i]=='.')
                    flagnotO=1;
            }
            if(flagnotO==0)
                flagO=1;
            if(flagnotX==0)
                flagX=1;
            flagnotO=flagnotX=0;
            for(int i=0;i<4;i++)
            {
                if (board[3-i][i]=='O'|board[3-i][i]=='.')
                    flagnotX=1;
                if (board[3-i][i]=='X'|board[3-i][i]=='.')
                    flagnotO=1;
            }
            if(flagnotO==0)
                flagO=1;
            if(flagnotX==0)
                flagX=1;
        }
        if(flagX==1)
            cout<<"Case #"<<x<<": "<<"X won"<<endl;
        else if(flagO==1)
            cout<<"Case #"<<x<<": "<<"O won"<<endl;
        else if(flagnotComp==1)
            cout<<"Case #"<<x<<": "<<"Game has not completed"<<endl;
        else
            cout<<"Case #"<<x<<": "<<"Draw"<<endl;
        for(int i=0;i<4;i++)
            free(board[i]);
        getchar();
    }
    return 0;
}

