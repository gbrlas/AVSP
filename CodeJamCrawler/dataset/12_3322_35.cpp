#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<fstream>
#include<sstream>
#include <cmath>

using namespace std;

int process2(string s)
{
	int out = 0;
	istringstream iss(s);

	int num, surps_allowed, min;

	iss >> num >> surps_allowed >> min;

	vector<int> scores;

	for (int i = 0; i < num; ++i) {
		int cur;
		iss >> cur;
		scores.push_back(cur);
	}

	int dir = 0, surps = 0;

	int min_dir, min_surp;

	min_dir = min + 2 * ((min-1 >= 0) ? (min-1) : 0); 
	min_surp = min + 2 * ((min-2 >= 0) ? (min-2) : 0); 

	for (int i = 0; i < num; ++i) {
		if (scores[i] >= (min_dir))
			dir++;
		else if (scores[i] >= min_surp)
			surps++;
	}

	out = dir + (surps_allowed < surps ? surps_allowed : surps);
	return out;
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
	iss >> tc;

	for(int i = 1; i <= tc; i++)
	{
		cout << "Case #" << i << ": ";
		getline(is,s); 
		cout << process2(s) << endl;
	}
	is.close();
	return 0;
}
