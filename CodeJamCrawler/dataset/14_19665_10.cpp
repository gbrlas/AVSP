#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>
#include <functional>
#include <sstream>
#include <cassert>


using namespace std;
class TestCase
{
public:
   int N;
   struct Rep
   {
      Rep() : c(0), r(0) {}
      char c;
      int r;
   };
   vector<Rep> reps[100];
   string un(vector<Rep> rs)
   {
      string s;
      for (int i = 0; i < rs.size() ; i++)
      {
         s += rs[i].c;
      }
      return s;
   }
   std::string eval(istream& is)
   {
      set<string> uns;
      is >> N;
      for (int i = 0; i < N ; i++)
      {
         string s;
         is >> s;
         Rep r;
         for (int j = 0; j < s.size() ; j++)
         {
            if (r.c == 0)
            {
               r.c = s[j];
               r.r++;
            }
            else if (r.c == s[j])
            {
               r.r++;
            }
            else 
            {
               reps[i].push_back(r);
               r = Rep();
               r.c = s[j];
               r.r = 1;
            }
         }
         reps[i].push_back(r);
         uns.insert(un(reps[i]));
      }
      if (uns.size() > 1)
      {
         return "Fegla Won";
      }

      int work = 0;
      for (int j = 0; j < reps[0].size() ; j++)
      {
         double avg=0;
      	for (int i = 0; i < N ; i++)
      	{
            avg += reps[i][j].r;
      	}
         avg /= N;
         int avgn = (int)round(avg);
         for (int i = 0; i < N; i++)
         {
            work += abs(reps[i][j].r - avgn);
         }
      }
      std::stringstream ss;
      ss << work;
      return ss.str();
   }
};

int main(int argc, char* argv[])
{
   ifstream infile(argv[1]);
   int T;
   infile >> T;
   for (int tc = 0; tc < T; ++tc)
   {
      TestCase testcase;
      cout << "Case #" << tc + 1 << ": " << testcase.eval(infile) << '\n';
   }
   return 0;
}

