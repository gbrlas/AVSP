/* 
 * File:   main.cpp
 * Author: zrm
 *
 * Created on May 7, 2010, 10:56 PM
 *
 * Google Code Jam 2010 - Qualification Round
 * Problem A: Snapper Chain
 */

#include <iostream>

using namespace std;
/*
 * 
 */
int main(int argc, char** argv)
{
    int numCases;
    cin >> numCases;

    int N, K;
    int base;
    for (int i=0; i<numCases; ++i)
    {
        cin >> N >> K;
        base = 1 << N;
        //cout << "2^N=" << base << endl;
        cout << "Case #" << i+1 << ": ";
        if ((K%base) == (base-1))
            cout << "ON\n";
        else
            cout << "OFF\n";
    }

    return (EXIT_SUCCESS);
}

