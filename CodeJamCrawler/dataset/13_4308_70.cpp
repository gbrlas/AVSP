#include <iostream>

using namespace std;

char m[4][16];

enum States
{
    X_WON,
    O_WON,
    DRAW,
    NOT_COMPLETE,
};

char getM(int i, int j, int mode)
{
    switch (mode)
    {
    case 0:
        return m[i][j];
    case 1:
        return m[j][i];
    case 2:
        return m[j][(j+i)%4];
    case 3:
        return m[j][(i+4-j)%4];
    }
    return 0;
}

States check()
{
    bool hasDot = false;
    int sX = 0, sT = 0, sO = 0;

    for (int mode = 0; mode < 4; ++mode)
    {
        int ie = (mode != 2 ? 4 : 1);
        int is = (mode == 3 ? 3 : 0);
        for (int i = is; i < ie; ++i)
        {
            sX = 0, sT = 0, sO = 0;
            for (int j = 0; j < 4; ++j)
            {
                switch (getM(i,j,mode))
                {
                case '.':
                    hasDot = true;
                    break;
                case 'X':
                    ++sX; break;
                case 'T':
                    ++sT; break;
                case 'O':
                    ++sO; break;
                }
            }
            if (sO == 0 && (sX == 4 || sX == 3 && sT == 1))
                return X_WON;
            else if (sX == 0 && (sO == 4 || sO == 3 && sT == 1))
                return O_WON;
        }
    }

    if (hasDot)
    {
        return NOT_COMPLETE;
    }
    else
    {
        return DRAW;
    }
}

void main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        for (int i = 0; i < 4; ++i)
            cin >> m[i];

        cout << "Case #" << t << ": ";
        switch (check())
        {
        case X_WON:
            cout << "X won"; break;
        case O_WON:
            cout << "O won"; break;
        case DRAW:
            cout << "Draw"; break;
        case NOT_COMPLETE:
            cout << "Game has not completed"; break;
        }
        cout << endl;
    }
}
