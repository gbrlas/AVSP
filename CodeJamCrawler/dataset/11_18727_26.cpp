#include "..\..\my_header.h"


struct solver
{
	int solve(int R, int C, int D, int_v2 &ws)
	{
	  int max_K_found = 0;
	  int max_K = min(R, C);
	  for (int K=3 ; K <= max_K ; K++)
	  {
	    bool found = false;
	    for (int dr=0 ; K+dr <= R ; dr++)
	      for (int dc=0 ; K+dc <= C ; dc++)
	      {
	        int center_R_2 = 2 * dr + K;
	        int center_C_2 = 2 * dc + K;
	        long long total_R_2 = 0;
	        long long total_C_2 = 0;
	        for (int ir=0 ; ir < K ; ir++)
	          for (int ic=0 ; ic < K ; ic++)
	          {
   	          if ((ir == 0 || ir == K-1) && (ic == 0 || ic == K-1))
   	            continue;   	            

	            int tile_center_R_2 = 2 * (dr + ir) + 1;
	            int tile_center_C_2 = 2 * (dc + ic) + 1;
	            
	            int delta_R_2 = tile_center_R_2 - center_R_2;
	            int delta_C_2 = tile_center_C_2 - center_C_2;
	            
	            int mass = D + ws(dr+ir, dc+ic);
	            
	            total_R_2 += delta_R_2 * mass;
	            total_C_2 += delta_C_2 * mass;	          
	          }
	        
	        if (total_R_2 == 0 && total_C_2 == 0)
	        {
	          found = true;
	          goto next_K;
	        }
	      }
	  
next_K:
	    if (found)
	      max_K_found = K;
	  }

		return max_K_found;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  int R, C, D;
  ifs >> R >> C >> D;
  
  int_v2 ws(R, C);
  for (int i=0 ; i < R ; i++)
  {
    string s;
    ifs >> s;
    for (int j=0 ; j < C ; j++)
      ws(i, j) = s[j] - '0';
  }
  
	int res = solver().solve(R, C, D, ws);

	cout << "Case #" << case_num << ": " << res << endl;
	
	if (res < 3)
	  ofs << "Case #" << case_num << ": IMPOSSIBLE" << endl;
	else
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
