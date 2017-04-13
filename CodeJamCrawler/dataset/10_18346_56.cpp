#include "..\..\my_header.h"


class solver
{
public:

	int solve(int N, int M, map<string, bool> &ex_dirs, str_v &new_dirs)
	{
	  int total_cost = 0;
	  
	  for (int i_new=0 ; i_new < M ; i_new++)
	  {
	    string nd = new_dirs[i_new];
	    str_v nd_ps = split(nd, '/');
	    int path_len = nd_ps.size();
	    
      int ex_count = 0;
      string path_so_far = "";
      
      while (ex_count < path_len)
      {
        if (!ex_dirs[path_so_far + "/" + nd_ps[ex_count]])
          break;      
        path_so_far += "/" + nd_ps[ex_count];
        ex_count++;
      }
      
      total_cost += path_len - ex_count;
      
      while (ex_count < path_len)
      {
        path_so_far += "/" + nd_ps[ex_count];
        ex_count++;
        ex_dirs[path_so_far] = true;
      }
	  }
	  
		return total_cost;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  int N, M;
  read2(N, M);
  
  map<string, bool> ex_dirs;
  str_v new_dirs;
  
  
  for (int i=0 ; i < N ; i++)
    ex_dirs[get_line(ifs)] = true;
  for (int i=0 ; i < M ; i++)
    new_dirs.push_back(get_line(ifs));
  
	int res = solver().solve(N, M, ex_dirs, new_dirs);

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
