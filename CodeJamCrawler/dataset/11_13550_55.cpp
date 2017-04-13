#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


using namespace std;


void solve()
{
     ifstream fin("input.txt", ios::in);
     ofstream fout("output.txt", ios::out);
     int k = 0,a = 0, *cand, max, min;
     fin >> k;
     
     //fin.getline(s,1000);
     for (int i = 0; i < k; i++)
     {
         fin >> a;
         cand = new int[a];
         for (int j = 0; j < a; j++)
         {
             fin >> cand[j];
         }
         max = 0;
         bool can = false;
         for (long unsigned int j = 0; j < pow(2,a); j++)
         {
             unsigned int counts = 0;
             unsigned int countp = 0;
             unsigned int countps = 0;
             unsigned int countsp = 0;
             int temp = j;
             int y;
             
             for (int w = 0; w < a; w++)
             {
                 y = temp%2;
                 temp = temp/2;
                 
                 if (y == 1)
                 {
                    counts = counts + cand[w];
                    countsp = countsp ^ cand[w];
                 }
                 else
                 {
                     //cout << countps << "  " << cand[w] << endl;
                     countp = countp + cand[w];
                     countps = countps ^ cand[w];
                     //cout << countps << endl;
                 }
             }
             //cout << endl;
             if (countsp == countps)
             {
                ///cout << countp << "  " << counts << endl;
                //cout << countps << "  " << countsp << endl;
                
                if (countp > max && counts != 0)
                {
                   can = true;
                   max = countp;
                }
                if (counts > max && countp != 0)
                {
                   can = true;
                   max = counts;
                }
             }
         }
         fout << "Case #" << (i+1) << ": ";
         if (can)
            fout << max << endl;
         else 
              fout << "NO" << endl;
         delete cand;
     }
     
}


int main()
{
    solve();
    //system("PAUSE");
    return 0;
}
