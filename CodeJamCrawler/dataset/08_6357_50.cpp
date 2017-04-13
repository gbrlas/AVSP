#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#define INF 999999999
using namespace std;
struct intervalas
  {
  short a, b;
  };
struct duuns
  {
  unsigned a, b;
  };
typedef vector <int> vecint;
unsigned bfs (vector <vecint> krastines, unsigned pradzia, set <unsigned> pabaigos)
  {
  unsigned ret = INF, i;
  queue <duuns> q;
  duuns temp, t2;
  temp.a = pradzia;
  temp.b = 0;
  q.push(temp);
  while (!q.empty() && ret == INF)
    {
    temp = q.front();
    for (i = 0; i < krastines[temp.a].size(); i++)
      if (pabaigos.find(krastines[temp.a][i]) == pabaigos.end())
        {
        t2.a = krastines[temp.a][i];
        t2.b = temp.b + 1;
        q.push(t2);
	    }
	    else
	    {
	    ret = temp.b + 1;
	    break;
	    }
	krastines[temp.a].clear();
    q.pop();
	}
  return ret;
  }
int main ()
  {
  unsigned N, S, Q, i, j, k, ats;
  int pr;
  string str;
  map <string, int> engines_map;
  vector <intervalas> engsets;
  vector <unsigned> vec, pradzios;
  set <unsigned> pabaigos;
  vector <vecint> krastines;
//  vector <int> :: iterator vit;
  intervalas temp;
  ifstream fin("A-small.in");
  ofstream fout("A-small.out");
  fin >> N;
  for (i = 1; i <= N; i++)
    {
    vec.clear();
    engines_map.clear();
    engsets.clear();
    fin >> S;
    getline(fin, str);
    for (j = 0; j < S; j++)
      {
      getline(fin, str);
      engines_map[str] = j;
      }
    fin >> Q;
    getline(fin, str);
    for (j = 0; j < Q; j++)
      {
      getline(fin, str);
      vec.push_back(engines_map[str]);
	  }
    if (Q == 0)
      {
      fout << "Case #" << i << ": 0" << endl;
      continue;
      }
	for (j = 0; j < S; j++)
	  {
	  pr = -1;
	  for (k = 0; k < vec.size(); k++)
	    if (vec[k] != j)
	      {
	      if (pr == -1)
	        pr = k;
		  }
		  else
		  if (pr != -1)
		    {
		    temp.a = pr;
		    temp.b = k - 1;
		    engsets.push_back(temp); // viršūnės
		    pr = -1;
			}
	  if (pr != -1)
	    {
	    temp.a = pr;
	    temp.b = k - 1;
	    engsets.push_back(temp);
	    }
      }
    krastines.clear();
    krastines.resize(engsets.size());
    pradzios.clear();
    pabaigos.clear();
    ats = INF;
    for (j = 0; j < engsets.size(); j++)
      {
      if (engsets[j].a == 0)
        {
        pradzios.push_back(j);
        if (engsets[j].b == Q - 1)
          {
          ats = 0;
          break;
	      }
	    }
      if (engsets[j].b == Q - 1)
        pabaigos.insert(j);
      for (k = j + 1; k < engsets.size(); k++)
        if (engsets[k].a > engsets[j].a && engsets[k].a <= engsets[j].b + 1 && engsets[k].b > engsets[j].b)
          krastines[j].push_back(k);
          else if (engsets[j].a > engsets[k].a && engsets[j].a <= engsets[k].b + 1 && engsets[j].b > engsets[k].b)
          krastines[k].push_back(j);
	  }
/*if (i == 7)
	for (j = 0; j < krastines.size(); j++)
	  for (k = 0; k < krastines[j].size(); k++)
	    printf("%d – %d\n", j, krastines[j][k]);*/
	for (j = 0; j < pradzios.size() && ats != 0; j++)
	  for (k = 0; k < pabaigos.size(); k++)
	    ats = min(ats, bfs(krastines, pradzios[j], pabaigos));
    fout << "Case #" << i << ": " << ats << endl;
    }
  return 0;
  }
