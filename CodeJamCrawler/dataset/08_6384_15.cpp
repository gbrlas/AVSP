#include <fstream>
#include <set>
using namespace std;

int main ()
  {
  int N, i, j, k, paspaudimu, klavisu, K, P, L;
  unsigned long long ats;
  multiset <int> aibe;
  multiset <int> :: reverse_iterator rit;
  ifstream fin("A-small.in");
  ofstream fout("A-small.out");
  fin >> N;
  for (i = 1; i <= N; i++)
    {
    paspaudimu = 1;
    ats = 0;
    aibe.clear();
    fin >> P >> K >> L;
    klavisu = K;
    for (j = 0; j < L; j++)
      {
      fin >> k;
      aibe.insert(k);
      }
    for (rit = aibe.rbegin(); rit != aibe.rend(); rit++)
      {
	  ats += paspaudimu * (*rit);
      if (--klavisu == 0)
        {
        paspaudimu++;
        klavisu = K;
	    }
	  }
    fout << "Case #" << i << ": " << ats << endl;
    }
  return 0;
  }
