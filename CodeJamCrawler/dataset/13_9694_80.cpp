#include <cstdio>
#include <iostream>

#define MAX 102

#define X_WON 0
#define O_WON 1
#define DRAW 2
#define INCOMPLETE 3

using namespace std;

int solve(int tc)
{
    char a[4][4];
    int i, j;

    int x, o, t;
    bool dot = false;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            cin>>a[i][j];
            if(a[i][j] == '.')
                dot=true;
        }
    }

    for(i=0; i<4; i++)
    {
        x = o = t = 0;
        for(j=0; j<4; j++)
        {
            if(a[i][j] == 'X')
            {
                x++;
            }
            else if(a[i][j] == 'O')
            {
                o++;
            }
            else if(a[i][j] == 'T')
            {
                t++;
                x++;
                o++;
            }
        }
        if(x == 4)
            return X_WON;
        else if(o == 4)
            return O_WON;
    }

    for(j=0; j<4; j++)
    {
        x = o = t = 0;
        for(i=0; i<4; i++)
        {
            if(a[i][j] == 'X')
            {
                x++;
            }
            else if(a[i][j] == 'O')
            {
                o++;
            }
            else if(a[i][j] == 'T')
            {
                t++;
                x++;
                o++;
            }
        }
        if(x == 4)
            return X_WON;
        else if(o == 4)
            return O_WON;
    }

    // 1st diagonal

    if((a[0][0] == 'X' || a[0][0] == 'T') && (a[1][1] == 'X' || a[1][1] == 'T') &&
       (a[2][2] == 'X' || a[2][2] == 'T') && (a[3][3] == 'X' || a[3][3] == 'T'))
    {
        return X_WON;
    }
    else if((a[0][0] == 'O' || a[0][0] == 'T') && (a[1][1] == 'O' || a[1][1] == 'T') &&
       (a[2][2] == 'O' || a[2][2] == 'T') && (a[3][3] == 'O' || a[3][3] == 'T'))
    {
        return O_WON;
    }

    // 2nd diadonal

    if((a[3][0] == 'X' || a[3][0] == 'T') && (a[2][1] == 'X' || a[2][1] == 'T') &&
       (a[1][2] == 'X' || a[1][2] == 'T') && (a[0][3] == 'X' || a[0][3] == 'T'))
    {
        return X_WON;
    }
    else if((a[3][0] == 'O' || a[3][0] == 'T') && (a[2][1] == 'O' || a[2][1] == 'T') &&
       (a[1][2] == 'O' || a[1][2] == 'T') && (a[0][3] == 'O' || a[0][3] == 'T'))
    {
        return O_WON;
    }

    if(dot)
        return INCOMPLETE;

    return DRAW;
}


int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("op.out", "w", stdout);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        switch(solve(tc))
        {
            case X_WON:
                cout << "Case #" << tc << ": X won" << endl;
                break;
            case O_WON:
                cout << "Case #" << tc << ": O won" << endl;
                break;
            case DRAW:
                cout << "Case #" << tc << ": Draw" << endl;
                break;
            case INCOMPLETE:
                cout << "Case #" << tc << ": Game has not completed" << endl;
                break;
        }
    }

    return 0;
}
