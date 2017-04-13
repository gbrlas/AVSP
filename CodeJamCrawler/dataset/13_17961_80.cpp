#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>

using namespace std;

char M[4][4];

int checkLine(int x, int y, int kx, int ky)
{
    int no = 0;
    int nx = 0;
    while (x > -1 && y > -1 && x < 4 && y < 4)
    {
        char c = M[y][x];
        if (c == 'O') {
            no++;
            nx = 0;
        }
        else if (c == 'X') 
        {
            nx++;
            no = 0;
        }
        else if (c == 'T')
        {
            nx++;
            no++;
        }
        else
        {
            nx = no = 0;
        }
        x+= kx;
        y+= ky;

        if (nx == 4) return 1;
        if (no == 4) return 2;
    }
    return 0;
}

int checkUnfineshed()
{
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            char c = M[y][x];
            if (c == '.') return 3;
        }
    }
    return 4;
}

int getresult()
{
    int r = 0;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            for (int kx = -1; kx <= 1; kx++)
            {
                for (int ky = -1; ky <= 1; ky++)
                {
                    if (! (kx == 0 && ky == 0))
                    {
                        r = checkLine(x,y,kx,ky);
                        if (r > 0)
                        {
                            return r;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream f("c:\\temp\\input.in");
    ofstream f2("c:\\temp\\output.txt");

    int T;  // number of tests
    f >> T;
    for (int t = 1; t <= T; t++)
    {
       char c;
       for (int h = 0; h < 4; h++)
       {
            for (int w = 0; w < 4; w++)
            {
               
               f >> c;   
               M[h][w] = c;               
            }
       }
       
    
       int result = getresult();

       if (result == 0) result = checkUnfineshed();

       switch (result)
       {
       case 1:
          f2 << "Case #" << t << ": X won" << endl;
          break;
       case 2:
           f2 << "Case #" << t << ": O won" << endl;
           break;
       case 3:
           f2 << "Case #" << t << ": Game has not completed" << endl;
           break;
       case 4:
            f2 << "Case #" << t << ": Draw" << endl;
           break;
       }
       
       //f2 << "Case #" << t << ": " << result << endl;
    }

 
    f.close();
    f2.close();
	return 0;
}

