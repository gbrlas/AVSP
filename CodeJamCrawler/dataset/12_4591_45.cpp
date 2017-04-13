/* 
 * File:   main.cpp
 * Author: Alex Ambrose
 *
 * Created on April 13, 2012, 11:52 PM
 */

#include <iostream>
#include <fstream>

using namespace std;

const string FILENAME = "B-large.txt";

int main()
{
    ifstream input(FILENAME.c_str());
    ofstream output("googlers_large.txt");
    int T;
    input >> T;
    for (int c = 1; c <= T; c++)
    {
        int N;
        int S_not = 0;
        int p_not = 0;
        input >> N;
        input >> S_not;
        input >> p_not;
        int data[N];
        int possible[N];

        for (int i = 0; i < N; i++)
        {
            input >> data[i];
            possible[i] = 0;
        }

        for (int p = p_not; p < 11; p++)
        {
            for (int i = 0; i < N; i++)
            {
                int check_not = data[i] - p;

                int check = check_not - p;

                if ((check == (p - 1) || check == p) && check >= 0)
                {
                    possible[i] = 1;
                }
                else if (check == (p - 2) && check >= 0)
                {
                    if (!possible[i])
                    {
                        possible[i] = 2;
                    }
                }

                check = check_not - (p - 1);

                if (check == (p - 1) && check >= 0)
                {
                    possible[i] = 1;
                }
                else if (check == (p - 2) && check >= 0)
                {
                    if (!possible[i])
                    {
                        possible[i] = 2;
                    }
                }

                check = check_not - (p - 2);

                if (check == (p - 2) && check >= 0)
                {
                    if (!possible[i])
                    {
                        possible[i] = 2;
                    }
                }
            }
        }
        int S = 0;
        int total = 0;
        for (int i = 0; i < N; i++)
        {
            if (possible[i] == 2)
            {
                S++;
                total++;
            }
            else if (possible[i] == 1)
                total++;

        }
        if (S > S_not)
            total -= (S - S_not);

        output << "Case #" << c << ": " << total << endl;

    }
    input.close();
    output.close();
    return 0;
}

