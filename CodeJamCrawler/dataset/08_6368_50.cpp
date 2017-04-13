#include <fstream>
#include <set>
using namespace std;
struct Trip
  {
  int pr, pab;
  bool A;
  bool operator() (const Trip & a, const Trip & b) const
    {
    if (a.pr != b.pr)
      return a.pr < b.pr;
      else
      return a.pab < b.pab;
    }
  };

int main ()
  {
  int N, T, NA, NB, i, j, temps[2], atsA, atsB;
  multiset <Trip, Trip> AB;
  multiset <int> stoviA, stoviB;
  multiset <Trip, Trip> :: iterator sit;
  freopen("pasakojimas.txt", "w", stdout);
  string str;
  Trip temp;
  ifstream fin("B-small.in");
  ofstream fout("B-small.out");
  fin >> N;
  for (i = 1; i <= N; i++)
    {
    atsA = 0;
    atsB = 0;
    AB.clear();
    stoviA.clear();
    stoviB.clear();
    fin >> T >> NA >> NB;
    temp.A = true;
    for (j = 0; j < NA; j++)
      {
      getline(fin, str, ':');
      temps[0] = atoi(str.c_str());
      getline(fin, str, ' ');
      temps[1] = atoi(str.c_str());
      temp.pr = temps[0] * 60 + temps[1];
      getline(fin, str, ':');
      temps[0] = atoi(str.c_str());
      getline(fin, str);
      temps[1] = atoi(str.c_str());
      temp.pab = temps[0] * 60 + temps[1];
      AB.insert(temp);
      }
    temp.A = false;
    for (j = 0; j < NB; j++)
      {
      getline(fin, str, ':');
      temps[0] = atoi(str.c_str());
      getline(fin, str, ' ');
      temps[1] = atoi(str.c_str());
      temp.pr = temps[0] * 60 + temps[1];
      getline(fin, str, ':');
      temps[0] = atoi(str.c_str());
      getline(fin, str);
      temps[1] = atoi(str.c_str());
      temp.pab = temps[0] * 60 + temps[1];
      AB.insert(temp);
      }
    for (sit = AB.begin(); sit != AB.end(); sit++)
      {
      if (sit->A)
        printf("AB ");
        else
        printf("BA ");
      printf("%d %d\n", sit->pr, sit->pab);
		  }
		for (sit = AB.begin(); sit != AB.end(); sit++)
		  {
	    printf("=========\nTraukinys %d:%d išvyksta iš ", sit->pr / 60, sit->pr % 60);
		  if (sit->A)
		    printf("A į B");
		    else
		    printf("B į A");
		  printf(", atvyksta %d:%d, apsisuka ligi %d:%d\n", sit->pab / 60, sit-> pab % 60, (sit->pab + T) / 60, (sit->pab + T) % 60);
		  if (sit->A)
		    {
		    printf("Stotelėje A yra %d traukinių", stoviA.size());
		    if (stoviA.size() > 0)
		      {
		      printf(", kurių pirmas gali išvykti %d:%d", *(stoviA.begin()) / 60, *(stoviA.begin()) % 60);
		      if (*(stoviA.begin()) <= sit->pr)
		        {
		        printf(", ir išvyksta");
		        stoviA.erase(stoviA.begin());
		        stoviB.insert(sit->pab + T);
					  }
  					else
	  				{
            stoviB.insert(sit->pab + T);
            atsA++;
	  				printf(", todėl reikia naujo traukinio stotelėje A. Joje startuoja bent %d", atsA);
				    }
					}
					else
					{
          stoviB.insert(sit->pab + T);
          atsA++;
  				printf(", todėl reikia naujo traukinio stotelėje A. Joje startuoja bent %d", atsA);
				  }
				printf("\n");
				}
        else
        {
		    printf("Stotelėje B yra %d traukinių", stoviB.size());
        if (stoviB.size() > 0)
          {
		      printf(", kurių pirmas gali išvykti %d:%d", *(stoviB.begin()) / 60, *(stoviB.begin()) % 60);
		      if (*(stoviB.begin()) <= sit->pr)
		        {
		        printf(", ir išvyksta");
		        stoviB.erase(stoviB.begin());
		        stoviA.insert(sit->pab + T);
					  }
  					else
	  				{
            stoviA.insert(sit->pab + T);
            atsB++;
	  				printf(", todėl reikia naujo traukinio stotelėje B. Joje startuoja bent %d", atsB);
				    }
					}
					else
					{
          stoviA.insert(sit->pab + T);
          atsB++;
   				printf(", todėl reikia naujo traukinio stotelėje B. Joje startuoja bent %d", atsB);
				  }
				printf("\n");
				}
		  }
    fout << "Case #" << i << ": " << atsA << ' ' << atsB << endl;
    }
  return 0;
  }
