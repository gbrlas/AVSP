#include "..\..\my_header.h"


struct solver
{
	string solve(int C, int D, int N, str_v combs, str_v opposed, string elems)
	{
	  string list = elems.substr(0, 1);
	  
	  for (int i_e=1 ; i_e < N ; i_e++)
	  {
	    char elem = elems[i_e];
	    
	    int len = list.length();
	    
	    if (len == 0)
	      list += elem;
	    else
	    {
        char last_elem = list[len-1];
        
        bool combined = false;
        for (int i_c=0 ; i_c < C ; i_c++)
        {
          string &comb = combs[i_c];
          if ((comb[0] == last_elem && comb[1] == elem) || (comb[0] == elem && comb[1] == last_elem))
          {
            list[len-1] = comb[2];
            combined = true;
            break;
          }
        }
        
        if (!combined)
        {
	        bool cleared = false;

          for (int i_o=0 ; i_o < D ; i_o++)
          {
            string &opp_pair = opposed[i_o];
            
            char clear_elem = '\0';
            
            if (opp_pair[0] == elem)
              clear_elem = opp_pair[1];
            
            if (opp_pair[1] == elem)
              clear_elem = opp_pair[0];
            
            if (clear_elem != '\0')
            {
              for (int j=0 ; j < len ; j++)
                if (list[j] == clear_elem)
                {
                  list = "";
                  cleared = true;
                  break;	              
                }
            }
          }
          
          if (!cleared)
            list += elem;
        }
      }
    }
    
		return list;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  int C, D, N;
  
  str_v strs = get_strs(ifs);
  
  C = to_int(strs[0]);
  D = to_int(strs[C+1]);
  N = to_int(strs[C+D+2]);
  
  str_v combs(C);
  for (int i=0 ; i < C ; i++)
    combs[i] = strs[i+1];
  
  str_v opposed(D);
  for (int i=0 ; i < D ; i++)
    opposed[i] = strs[i+C+2];
  
  string elems = strs[C+D+3];  
  
  
	string res = solver().solve(C, D, N, combs, opposed, elems);

  string pr_res = "[";
  for (unsigned int i=0 ; i < res.length() ; i++)
  {
    pr_res += (i > 0 ? ", " : "");
    pr_res += res[i];
  }
  pr_res += "]";
  
	cout << "Case #" << case_num << ": " << pr_res << endl;
	ofs << "Case #" << case_num << ": " << pr_res << endl;
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
