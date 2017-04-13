#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;


int main()
{
    ifstream input;
    input.open("in.in");
    int t; input >> t;

    ofstream output;
    output.open("output");


    for(int i = 0; i < t; ++i)
    {
        int row1, row2;
        int desk1[4][4];
        int desk2[4][4];

        input >> row1;
        for(int i = 0; i < 4; ++i)
            input >> desk1[i][0] >> desk1[i][1] >> desk1[i][2] >> desk1[i][3];

        input >> row2;
        for(int i = 0; i < 4; ++i)
            input >> desk2[i][0] >> desk2[i][1] >> desk2[i][2] >> desk2[i][3];

        int counter = 0;
        int theNumber = -1;
        for(int i = 0; i < 4; ++i)
        {
            for(int j = 0; j < 4; ++j)
            {
                if(desk1[row1-1][i] == desk2[row2-1][j])
                {
                    ++counter;
                    theNumber = desk1[row1-1][i];
                }
            }

        }
        output << "Case #" << (i+1) << ": ";
        if(!counter)
            output << "Volunteer cheated!";
        else if(counter == 1)
            output << theNumber;
        else
            output << "Bad magician!";
        output << endl;
    }

    return 0;
}



