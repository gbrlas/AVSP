#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <map>
#include <math.h>
#include <sstream>
#include <stdlib.h>
using namespace std;
ifstream file; ofstream outfile;
int convert_tobase(int base, int num)
{
   return num;
   int sum=0;
   int div = 1;
   while (num > 0)
   {
      sum+=(num%base) * div;
         div *= base;
         num/=base;
   }
   return sum;
}
int square_digits(int base, int num)
{
   int total=0;
   int div = 1;
   while (num>0)
   {
      total+=(num%base)*(num%base);
      num/=base;
      div*=base;
   }
   return convert_tobase(base, total);
}

bool happy(int base, int num)
{
   for (int i = 0; i< 1000; ++i)
   {
      int sq = square_digits(base, num);
      if (sq==1) return true;
      num=sq;
   }
   return false;
}

void Case()
{
   std::vector<int> bases;
   char line[1000];
   file.getline(line, 1000);
   stringstream ss(line);
   int base;
   while (ss >> base)
   {
      bases.push_back(base);
   }

   for (int n = 2; n < 100000; ++n)
   {
      bool ok=true;
      for (size_t i = 0; i < bases.size(); ++i)
      {
         int n_real = n;
         if (! happy(bases[i], n_real))
         {
               ok = false;
               break;
         }
      }
      if (ok)
      {
         outfile << n;
         break;
      }
   }
   
   outfile << "\n";
}

int main()
{
   int cases(0);
   file.open("A-small-attempt0.in");
   outfile.open("1.out");
   file >> cases;
   file.ignore();
   for (int i = 0; i < cases; ++i)
   {
      outfile << "Case #" << i+1 << ": ";
      Case();
   }
   return 0;
}
