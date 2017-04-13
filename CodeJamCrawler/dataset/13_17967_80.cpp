#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>

using namespace std;

int Mat[100][100];
int Mat2[100][100];
int M, N;
bool change = false;

int checkLine(int n, int m, int kn, int km)
{
    int max = 0;    
    while ( n > -1 && m > -1 && n < N && m < M)
    {
        if (max < Mat[n][m]) 
        {
            max = Mat[n][m];
        }
        n+=kn;
        m+=km;
    }
    return max;
}

void print()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            cout << Mat2[n][m];
        }
        cout << endl;
    }
}

void sawline(int n, int m, int kn, int km, int h)
{    
    while ( n > -1 && m > -1 && n < N && m < M)
    {
        if (Mat2[n][m] > h) 
        {
            Mat2[n][m] = h;
            change = true;
        }
        n+=kn;
        m+=km;
    }
}

void saw()
{
    for (int n = 0; n < N; n++)
    {
        int h;
        h = checkLine(n, 0, 0, 1); 
        sawline(n, 0, 0, 1, h);
        h = checkLine(n, M - 1, 0, -1);
        sawline(n, M - 1, 0, -1, h);
    }
    for (int m = 0; m < M; m++)
    {
        int h;
        h = checkLine(0, m, 1, 0);
        sawline(0, m, 1, 0, h);
        h = checkLine(N-1, m, -1, 0); 
        sawline(N-1, m, -1, 0, h);
    }
}

bool checkLawn()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            if (Mat[n][m] != Mat2[n][m]) return false;
        }
    }
    return true;
}



int _tmain(int argc, _TCHAR* argv[])
{
    ifstream f("c:\\temp\\input.in");
    ofstream f2("c:\\temp\\output.txt");

    int T;  // number of tests
    f >> T;
    for (int t = 1; t <= T; t++)
    {
       
       f >> N >> M;
       int c;
       for (int n = 0; n < N; n++)
       {
            for (int m = 0; m < M; m++)
            {               
               f >> c;   
               Mat[n][m] = c;               
               Mat2[n][m] = 100;
            }
       }
       
       change = true;
       while (change)
       {
         change = false;
         saw();
       }

       //print();
       bool result = checkLawn();
      

       switch (result)
       {
       case false:
          f2 << "Case #" << t << ": NO" << endl;
          break;
       case true:
           f2 << "Case #" << t << ": YES" << endl;
           break;      
       }
             
    }

 
    f.close();
    f2.close();
	return 0;
}

