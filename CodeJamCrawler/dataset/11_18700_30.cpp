#include "..\..\my_header.h"


struct solver
{
  int N;
  int_v candies;
  
  bool_v for_sean;
  
  int best_sean;
  
  int pseudo_sum(int a, int b)
  {
    int c = 0;
    //string a_bin, b_bin;
    
    for (int i=0 ; i < 30 ; i++)
    {
      bool a_1 = (a & (1 << i)) != 0;
      bool b_1 = (b & (1 << i)) != 0;
      
      //a_bin = (a_1 ? "1" : "0") + a_bin;
      //b_bin = (b_1 ? "1" : "0") + b_bin;
      
      bool c_1 = (a_1 && !b_1) || (!a_1 && b_1);
      
      if (c_1)
        c += 1 << i;
    }
    
    return c;
  }
  
  void search(int pos)
  {
    if (pos == N)
    {
      bool sean_empty = true;
      bool patrick_empty = true;
      int pseudo_sean = 0;
      int real_sean = 0;
      int pseudo_patrick = 0;
      
      for (int i=0 ; i < N ; i++)
      {
        int candy = candies[i];
        
        if (for_sean[i])
        {
          sean_empty = false;
          pseudo_sean = pseudo_sum(pseudo_sean, candy);
          real_sean += candy;
        }
        else
        {
          patrick_empty = false;
          pseudo_patrick = pseudo_sum(pseudo_patrick, candy);
        }
      }
      
      if (sean_empty || patrick_empty)
        return;

      if (pseudo_sean == pseudo_patrick && (best_sean == -1 || real_sean > best_sean))
        best_sean = real_sean;  
      
      return;  
    }
    
    for_sean[pos] = true;
    search(pos+1);
    
    for_sean[pos] = false;
    search(pos+1);  
  }
  
	int solve()
	{
	  best_sean = -1;
	  for_sean.resize(N);
	  search(0);
		return best_sean;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  solver s;
	read1(s.N);
	s.candies = get_ints(ifs);

	int val = s.solve();
	
	string res = val == -1 ? "NO" : to_string(val);

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
