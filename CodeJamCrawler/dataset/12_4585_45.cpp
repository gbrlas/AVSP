/* 
 * File:   main.cpp
 * Author: Alex Ambrose
 *
 * Created on April 14, 2012, 12:59 AM
 */

#include <iostream>
#include <fstream>

using namespace std;

const string G_TO_A =           "yhesocvxduiglbkrztnwjpfmaq";
const string filename = "A-small-attempt0.txt";

int main()
{
    ifstream input(filename.c_str());
    ofstream output("tongues_output.txt");
    int T;
    input >> T;
    input.ignore(INT_MAX, '\n');
    for (int i = 1; i <= T; i++)
    {
        string G, S = "";
        getline(input, G);
        for (int j = 0; j < G.size(); j++)
        {
            if (G[j] == ' ')
                S += " ";
            else if (G[j] > 96 && G[j] < 123)
                S += G_TO_A[G[j] - 97];
        }
        output << "Case #" << i << ": " << S << endl;
    }

    return 0;
}
