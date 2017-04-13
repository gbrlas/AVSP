/* 
 * File:   main.cpp
 * Author: Alex Ambrose
 *
 * Created on April 14, 2012, 1:37 AM
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

const string filename = "C-small-attempt0.txt";
int main()
{
    ifstream input(filename.c_str());
    ofstream output("Recycled_output.txt");
    int T;
    input >> T;
    for (int c = 1; c <= T; c++)
    {
        int A, B;
        input >> A;
        input >> B;
        int total = 0;
        
        stringstream B_ss;
        B_ss << B;
        string B_str = B_ss.str();
        
        for (int n = A; n < B; n++)
        {
            stringstream n_ss;
            n_ss << n;
            string n_str = n_ss.str();
            vector<string> solutions;
            for (int i = 1; i < n_str.size(); i++)
            {
                string m_str = string(n_str, n_str.size() - i, i) + string(n_str, 0, n_str.size() - i);
                if (m_str[0] == '0')
                    continue;
                if (m_str > n_str && m_str <= B_str)
                {
                    bool taken = false;
                    for (int j = 0; j < solutions.size(); j++)
                    {
                        if (m_str == solutions[j])
                            taken = true;
                    }
                    if (!taken)
                    {
                        solutions.push_back(m_str);
                        total++;
                    }
                }
            }
        }
        output << "Case #" << c << ": " << total << endl;
        
    }
    return 0;
}

