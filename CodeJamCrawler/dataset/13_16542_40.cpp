#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in;
    in.open("input");
    ofstream out;
    out.open("output");

    char x[4][4];
    int sumX = 0, sumO = 0, sumHX = 0, sumHO = 0, sumIHX = 0, sumIHO = 0;
    bool won = false, emp = false;
    int e;
    in>>e;
    for(int i = 0; i < e; i++)
    {
       for(int k = 0; k < 4; k++)
        {
            for(int l = 0; l < 4; l++)
            {
                in>>x[k][l];
                if(x[k][l] == '.')
                    emp = true;
            }
        }




        for(int l = 0; l < 4; l++)
        {
            if(x[l][l] == 'O' || x[l][l] == 'T')
                sumHO++;
            if(x[l][l] == 'X' || x[l][l] == 'T')
                sumHX++;
            if(x[l][3 - l] == 'O' || x[l][3 - l] == 'T')
                sumIHO++;
            if(x[l][3 - l] == 'X' || x[l][3 - l] == 'T')
                sumIHX++;
        }

        if (sumHO == 4 || sumIHO == 4)
        {
            out<<"Case #"<<i+1<<": "<<"O won"<<endl;won = true;
        }
        else if (sumHX == 4 || sumIHX == 4)
        {
            out<<"Case #"<<i+1<<": "<<"X won"<<endl;won = true;
        }
        sumX = sumO = sumHX = sumHO = sumIHX = sumIHO = 0;



        if(!won)
        {
        for(int k = 0; k < 4 && !won; k++)
        {
            for(int l = 0; l < 4; l++)
            {
                if(x[k][l] == 'O' || x[k][l] == 'T')
                    sumO++;
                if(x[k][l] == 'X' || x[k][l] == 'T')
                    sumX++;
                if(x[l][k] == 'O' || x[l][k] == 'T')
                    sumHO++;
                if(x[l][k] == 'X' || x[l][k] == 'T')
                    sumHX++;
            }
            if (sumO == 4 || sumHO == 4)
            {
                out<<"Case #"<<i+1<<": "<<"O won"<<endl;won = true;
            }
            else if (sumX == 4 || sumHX == 4)
            {
                out<<"Case #"<<i+1<<": "<<"X won"<<endl;won = true;
            }
            sumX = sumO = sumHX = sumHO = sumIHX = sumIHO = 0;
        }
        }
        if(!won && !emp)
            out<<"Case #"<<i+1<<": "<<"Draw"<<endl;
        else if(!won)
            out<<"Case #"<<i+1<<": "<<"Game has not completed"<<endl;
        won = emp = false;
    }


    return 0;
}
