#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<fstream>
#include<sstream>
#include <cmath>

using namespace std;

unsigned long process_testcase_third(int num, string s)
{
	int total = 0;

	istringstream iss(s);
	unsigned long cur_min = 2000000, cur_total = 0, cur_xor = 0;

	for (int i = 0; i < num; i++) {
		unsigned long cur_int = 0;
		iss >> cur_int;

		if (cur_int < cur_min ) {
		    cur_min = cur_int;
		}

		cur_total += cur_int;

		cur_xor ^= cur_int;
	}

	if (cur_xor != 0) {
	    return -1;
	} else {
		return cur_total - cur_min;	
	}

}

int main(int argc, const char *argv[])
{
	int tc = 0;
	ifstream is;
	if(argc == 1)
		is.open("input.txt");
	else
		is.open(argv[1]);

	string s;
	getline(is,s); 
	istringstream iss(s);
	int numchars,dic;
	iss >> tc;

	for(int i = 1; i <= tc; i++)
	{
		printf("Case #%d: ",i);
		getline(is,s); 
		istringstream iss2(s);
		int num_candies;
		iss2 >> num_candies;
		getline(is, s);
		unsigned long max_pile = process_testcase_third(num_candies, s);
		if (max_pile == -1) {
			cout << "NO" << endl;
		} else {
			cout << max_pile << endl;
		}
	}
	is.close();
	return 0;
}