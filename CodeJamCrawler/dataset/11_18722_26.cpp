#include "..\..\my_header.h"


struct solver
{
	double solve(int X, int S, int R, int t, int N, int_v &Bs, int_v &Es, int_v &ws)
	{
	  int_v wls(N);
	  for (int i=0 ; i < N ; i++)
	    wls[i] = Es[i] - Bs[i];

	  int twl = 0;
	  for (int i=0 ; i < N ; i++)
	    twl += wls[i];
	  
	  double no_twl = X - twl;
	  double run_time_left = t;
	  
	  double time = 0;
	  
	  double rt = no_twl / R;
	  if (rt <= run_time_left)
	  {
	    time = rt;
	    run_time_left -= rt;
	  }
	  else
	  {
	    time = run_time_left + double(no_twl - (run_time_left * R)) / S;
	    run_time_left = 0;
	  }
	  
	  int_v wis = sorted_indexes(ws);
	  
	  for (int j=0 ; j < N ; j++)
	  {
	    int i_w = wis[j];
	    rt = double(wls[i_w]) / (R + ws[i_w]);
	    
	    if (rt <= run_time_left)
	    {
	      time += rt;
	      run_time_left -= rt;
	    }
	    else
	    {
	      time += run_time_left + double(wls[i_w] - run_time_left * (R + ws[i_w])) / (S + ws[i_w]);
	      run_time_left = 0;
	    }
	  
	  }
	  
	    
	  
		return time;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  int X, S, R, T, N;
  ifs >> X >> S >> R >> T >> N;
  
  int_v Bs(N), Es(N), ws(N);
  for (int i=0 ; i < N ; i++)
    ifs >> Bs[i] >> Es[i] >> ws[i];
    
  
	double res = solver().solve(X, S, R, T, N, Bs, Es, ws);

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
