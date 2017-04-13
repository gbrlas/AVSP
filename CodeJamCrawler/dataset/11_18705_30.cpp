#include "..\..\my_header.h"


class solver
{
public:

	bool solve(int N, int Pd, int Pg)
	{
	  int min_g = 1;
	  
	  if (Pd < 100 && Pg == 100)
	    return false;
	  
	  if (Pd > 0 && Pg == 0)
	    return false;

	  if (Pd % 4 == 0)
	    ;
	  else if (Pd % 2 == 0)
	    min_g *= 2;
	  else
	    min_g *= 4;
	  
	  if (Pd % 25 == 0)
	    ;
	  else if (Pd % 5 == 0)
	    min_g *= 5;
	  else
	    min_g *= 25;
	  
	  return N >= min_g;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  int N, Pd, Pg;
  
  ifs >> N >> Pd >> Pg;
  
	bool res = solver().solve(N, Pd, Pg);

	cout << "Case #" << case_num << ": " << (res ? "Possible" : "Broken") << endl;
	ofs << "Case #" << case_num << ": " << (res ? "Possible" : "Broken") << endl;
}

/*************************************************************************************/

void main(int argc, char **argv)
{
	ifstream ifs(argv[1], ifstream::in);
	ofstream ofs(argv[2]);

	ofs.precision(7);
	ofs << fixed;

	int n = to_int(get_line(ifs));

	assert(n > 0 && n < 200);

	for (int i=0 ; i < n ; i++)
	{
		if (i > 0)
			cout << "\n---------------------------------------------\n\n";
		process_test_case(i+1, ifs, ofs);
	}
}
