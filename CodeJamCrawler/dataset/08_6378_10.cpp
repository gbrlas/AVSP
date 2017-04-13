#include <fstream>
#include <set>
using namespace std;
set <int> primes;
set <int> :: iterator it, ite;
bool cpf (int a, int b, int P)
  {
  for (it = primes.upper_bound(P - 1); it != primes.end(); it++)
    if (a % *it == 0 && b % *it == 0)
      return true;
  return false;
  }
int main ()
  {
  int C, i, A, B, P, j, k;
  int ats;
  int aibes[1000];
  set <int> aas[1000];
  primes.insert(2);
  for (i = 3; i < 1000; i+= 2)
    {
    for (it = primes.begin(); it != primes.end(); it++)
      if (i % *it == 0)
        break;
    if (it == primes.end())
      primes.insert(--primes.end(), i);
	}
  ifstream fin("B-small.in");
  ofstream fout("B-small.out");
  fin >> C;
  for (i = 1; i <= C; i++)
    {
    fin >> A >> B >> P;
    for (j = 0; j <= B - A; j++)
      {
      aibes[j] = j;
      aas[j].clear();
      aas[j].insert(j);
      }
    ats = B - A + 1;
    for (j = A; j < B; j++)
      for (k = j + 1; k <= B; k++)
        if (cpf(j, k, P))
          if (aibes[j - A] != aibes[k - A])
            {
            ite = aas[aibes[k - A]].end();
            for (it = aas[aibes[k - A]].begin(); it != ite; it++)
              {
              aibes[*it] = aibes[j - A];
              aas[aibes[j - A]].insert(*it);
		      }
            ats--;
			}
    fout << "Case #" << i << ": " << ats << endl;
    }
  return 0;
  }
