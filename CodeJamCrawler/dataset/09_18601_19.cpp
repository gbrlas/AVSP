#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
using namespace std;
ifstream file; ofstream outfile;
std::map<int, double> fmap;
double  fact(int n)
{
   if (n == 0) return 1;
   if (fmap.find(n) != fmap.end())
   {
      return fmap[n];
   }
   double val=n;
   int  r = n;
   while (--r > 0)
   {
      val*=r;
   }
   fmap[n]=val;
   return val;
}
// k<n
double choice(double  k, double  n)
{
   //double v = 1;
   //double div;
   //for (int i = n; i >k; --i)
   //{
   //   v*= n;
   //}
   //div = fact(n-k);
   //return v/div;
   return fact(n)*1.0 / ((double)fact(k) * fact(n-k));
}
struct Way
{
   int n;
   double ways;
};
typedef boost::tuple<int,int,int> Parms;
std::map<Parms, double> mem;
void prob(int C, int N, int U,
            double& E, double thresh)
{
   Parms par(C,N,U);
   if (mem.find(par) != mem.end())
   {
      E=mem[par];
      return;
   }
   if (U >= C)
   {
      E=0;
      return;
   }
   double totalways=0.0;
   
   std::vector<Way> choices;
   for (int i = 0; i <= N; ++i)
   {
      int n = i;
      if (n>U || N-n>C-U) continue;
      double ways = choice(n, U) * choice(N-n, C-U);
      totalways+=ways;
      if (ways >= 0.0000000000001)
      {
         Way w;
         w.ways = ways;
         w.n = i;
         choices.push_back(w);
      }
   }
   double esum=0;
   double esumdiv=0;
   for (size_t i = 0; i< choices.size(); ++i)
   {
      Way& w= choices[i];
      double portion = w.ways / totalways;
      if (portion > thresh)
      {
         double expect=0;
         prob(C, N, U+(N-w.n), expect, thresh/portion);
         esum += w.ways * expect;
         esumdiv += w.ways;
      }
   }

   E = esum / totalways + 1;
   mem[par]=E;
}

void Case()
{
   char line[1000];
   file.getline(line,10000);
   stringstream ss(line);
   int C, N;
   ss >> C >> N;
   double E;
   prob(C, N, 0, E, .000000000001);
   
   outfile << std::setprecision(10) << E << "\n";
   cout << E << '\n';
}

int main()
{
   double E;
   prob(2, 1, 0, E, .0000001);
   cout << E << '\n';
   int cases(0);
   file.open("C-small-attempt4.in");
   outfile.open("2.out");
   file >> cases;
   file.ignore();
   for (int i = 0; i < cases; ++i)
   {
      outfile << "Case #" << i+1 << ": ";
      Case();
   }
   return 0;
}
