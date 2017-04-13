#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <math.h>

using namespace std;

long long A, B;
long long digits[100];

bool isPalindrome(long long b)
{
   long long n = 0;
   while (b > 0)
   {
     long long z = b % 10;
     digits[n] = z;
     b /= 10;
     n++;
   }
   for (long long i = 0; i < n/2; i++)
   {
      if (digits[i] != digits[n - 1 - i]) return false;
   }
   return true;
}

long long getresult()
{
    long long sum = 0;
    long long A1 = (long long)sqrt((long double)A);
    if (A1*A1 < A) A1++;
    long long B1 = (long long)sqrt((long double)B);
    
    for (long long i = A1; i <= B1; i++)
    {
        
        if (isPalindrome(i))
        {
            long long q = i*i;
            if (isPalindrome(q))
            {
                sum++;
            }
        }
    }

    return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream f("c:\\temp\\input.in");
    ofstream f2("c:\\temp\\output.txt");

    int T;  // number of tests
    f >> T;
    for (int t = 1; t <= T; t++)
    {
       f >> A >> B; 
       long long result = getresult();
       f2 << "Case #" << t << ": " << result << endl;
    }


    f.close();
    f2.close();
	return 0;
}

