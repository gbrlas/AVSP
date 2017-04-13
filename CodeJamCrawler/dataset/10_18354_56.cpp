#include "..\..\my_header.h"


class solver
{
public:
  
	intw solve(int N, int K, intw B, intw T, intw_v &Xs, intw_v &Vs)
	{
	  if (K == 0)
	    return 0;
	  
	  intw_v can_make_it(N);
	  
	  for (int i=0 ; i < N ; i++)
	    can_make_it[i] = Xs[i] + T * Vs[i] >= B;
	  
	  intw have_made_it_so_far = 0;
	  intw must_be_overtaken_so_far = 0;
	  intw swaps_so_far = 0;
	  for (int i=N-1 ; i >= 0 ; i--)
	    if (can_make_it[i])
	    {
	      assert(have_made_it_so_far < K);
	      
	      have_made_it_so_far++;
	      swaps_so_far += must_be_overtaken_so_far;
	      if (have_made_it_so_far == K)
	        return swaps_so_far;	    
	    }
	    else
	    {
	      must_be_overtaken_so_far++;     
	    }
	    
		return -1;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  int N, K;
  intw B, T;
  read4(N, K, B, T);
  
  intw_v Xs = get_intws(ifs);
  intw_v Vs = get_intws(ifs);
  
	intw res = solver().solve(N, K, B, T, Xs, Vs);

  if (res == -1)
  {
	  cout << "Case #" << case_num << ": IMPOSSIBLE" << endl;
	  ofs << "Case #" << case_num << ": IMPOSSIBLE" << endl;
	}
	else
	{
	  cout << "Case #" << case_num << ": " << res << endl;
	  ofs << "Case #" << case_num << ": " << res << endl;
  }	
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
