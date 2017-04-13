#include "..\..\my_header.h"


class solver
{
public:

  int min_tickets(int p, int_v &constraints, int start, int size)
  {
    assert(size >= 2);
    
    bool done = true;
    for (int i=0 ; i < size ; i++)
    {
      //assert(constraints[start+i] <= p);
      
      if (constraints[start+i] < p)
      {
        done = false;
        break;
      }
    }
    
    if (done)
      return 0;
    
    if (size == 2)
      return 1;
    
    return 1 + min_tickets(p-1, constraints, start,        size/2) +
               min_tickets(p-1, constraints, start+size/2, size/2);
  }
  
	int solve(int p, int_v &constraints, vector<int_v> &prices)
	{
		return min_tickets(p, constraints, 0, constraints.size());
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  int p;
  read1(p);
  
  int_v constraints = get_ints(ifs);
  
  vector<int_v> prices(p);
  for (int i=0 ; i < p ; i++)
    prices[i] = get_ints(ifs);
  
	int res = solver().solve(p, constraints, prices);

	cout << "Case #" << case_num << ": " << res << endl;
	ofs << "Case #" << case_num << ": " << res << endl;
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
