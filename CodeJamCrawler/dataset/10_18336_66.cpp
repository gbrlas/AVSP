#include "..\..\my_header.h"


class solver
{
public:
  int queue_pos_after_run(int init_queue_pos, intw R, intw k, intw N, intw_v gs, intw &taken)
  {
    int pos = init_queue_pos;
    taken = 0;
    
    while (taken + gs[pos] <= k)
    {
      taken += gs[pos];
      pos = (pos + 1) % N;
      if (pos == init_queue_pos)
        break;
    }
    
    return pos;  
  }
  
	intw solve(intw R, intw k, int N, intw_v gs)
	{
	  intw_v taken_before  = rep_vector<intw>(0, N);
	  intw_v reached_after = rep_vector<intw>(-1, N);
	  reached_after[0] = 0;

    bool skip = false;
    
    intw run_so_far = 0;
    intw taken_so_far = 0;
    int curr_pos = 0;
    
    for ( ; ; )
    {
      intw taken = 0;
      curr_pos = queue_pos_after_run(curr_pos, R, k, N, gs, taken);
      run_so_far++;
      taken_so_far += taken;
      
      if (!skip)
        if (reached_after[curr_pos] == -1)
        {
          reached_after[curr_pos] = run_so_far;
          taken_before[curr_pos]  = taken_so_far;      
        }
        else
        {
          intw cycle_len   = run_so_far - reached_after[curr_pos];
          intw cycle_taken = taken_so_far - taken_before[curr_pos];
          
          intw num_cycles = (R - run_so_far) / cycle_len;
          
          run_so_far   += num_cycles * cycle_len;
          taken_so_far += num_cycles * cycle_taken;
          
          skip = true;      
        }
      
      if (run_so_far == R)
        return taken_so_far;
    }
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  intw R, k;
  int N;
  intw_v gs;
  
  read3(R, k, N);
  gs = get_intws(ifs, "g[]");  
  
  assert(gs.size() == N);
  
	intw res = solver().solve(R, k, N, gs);
	
	if (res > R * k)
	{
	  cout << "Error case " << case_num << endl;
	  exit(1);
	}

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
