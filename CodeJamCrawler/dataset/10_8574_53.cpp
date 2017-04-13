/* 
 * File:   main.cpp
 * Author: zrm
 *
 * Created on May 7, 2010, 8:58 PM
 *
 * Google Code Jam 2010 - Qualification Round
 * Problem C: Theme Park
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */
inline int inc(int index, int n)
{
    return (++index%n);
}

int calcRev(int R, int k, int N, vector<int>& q, int index)
{
    int load;
    int groups;
    long rev = 0;

    //cout << "R:" << R << " k:" << k << " N:" << N << endl;
    for (int i=0; i<R; ++i)
    {
        //cout << "Round " << i+1 << endl;

        load = 0;
        groups = 0;

        while (groups < N)
        {
            if ((load+q.at(index)) <= k)
            {
                //cout << q[index] << " ";
                load += q[index];
                index = inc(index,N);
                ++groups;
            }
            else
                break;
        }

        //cout << "= " << load << "\n";
        rev += load;
    }

    return rev;
}

int main(int argc, char** argv)
{
    int numCases = 0;
    cin >> numCases;
    int R, k, N, p;
    vector<int> q;
    
    for (int i=0; i<numCases; ++i)
    {
        q.clear();
        
        cin >> R >> k >> N;
        for (int j=0; j<N; ++j)
        {
            cin >> p;
            q.push_back(p);
        }
        
        cout << "Case #" << i+1 << ": " << calcRev(R, k, N, q, 0) << "\n";
    }

    return (EXIT_SUCCESS);
}

