#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ifstream fin("B.in");
    ofstream fout("B.out");
    int N;
    fin >> N;
    for (int casenum = 1; casenum <= N; casenum++)
    {
        string s;
        fin >> s;
        fout << "Case #" << casenum << ": ";
        bool ord = true;
        bool done = false;
        int nums[10];
        for (int k = 0; k < 10; k++)
            nums[k] = 0;
        for (int i = s.length() -1; i >= 0; i--)
        {
            nums[s[i]-'0']++;
            for (int j = s[i]-'0' + 1; j < 10; j++)
            {
                if (nums[j] > 0)
                {
                      ord = false;
                      for (int k = 0; k < i; k++)
                          fout << s[k];
                      fout << j;
                      nums[j]--;
                      for (int n = 0; n < 10; n++)
                      {
                          for (int m = 0; m < nums[n]; m++)
                              fout << n;
                      } 
                      fout << endl;
                      done = true;
                      break;     
                }
            }
            if (done)
                   break;
            
        }
        if (ord)
        {
                for (int n = 1; n < 10; n++)
                {
                    if (nums[n] > 0)
                    {
                        fout << n << 0;
                        nums[n]--;
                        break;
                    }
                }
                for (int n = 0; n < 10; n++)
                {
                    for (int m = 0; m < nums[n]; m++)
                        fout << n;
                }
                fout << endl;
        }
    }
    return 0;   
}
