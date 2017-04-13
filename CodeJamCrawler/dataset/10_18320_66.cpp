#include "..\..\my_header.h"


class solver
{
public:
  
	bool solve(intw N, intw K)
	{
    while (N > 0)
    {
      if ((K & 1) == 0)
        return false;
      K = K >> 1;
      N--;
    }
    
    return true;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
	intw N, K;
	
	read2(N, K);

	bool res = solver().solve(N, K);
	
	cout << "Case #" << case_num << ": " << (res ? "ON" : "OFF") << endl;
	ofs << "Case #" << case_num << ": " << (res ? "ON" : "OFF") << endl;
}

/*************************************************************************************/

void main(int argc, char **argv)
{
	ifstream ifs(argv[1], ifstream::in);
	ofstream ofs(argv[2]);

	ofs.precision(7);
	ofs << fixed;

	int n = to_int(get_line(ifs));

	assert(n > 0 && n <= 10000);

	for (int i=0 ; i < n ; i++)
	{
		if (i > 0)
			cout << "\n---------------------------------------------\n\n";
		process_test_case(i+1, ifs, ofs);
	}
}
