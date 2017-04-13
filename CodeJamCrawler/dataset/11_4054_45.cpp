#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<fstream>
#include<sstream>
#include <cmath>

using namespace std;

int process_testcase(string s)
{
	int total = 0;
	int last_count = 0, diff = 0;
	char last_char = 'X';
	map<char, int> pos;
	pos['O'] = 1;
	pos['B'] = 1;

	istringstream iss(s);

	int num_entries  = 0;

	iss >> num_entries;

	for (int i = 0; i < num_entries; i++) {
		char cur_char;
		int req_num = 0;
		iss >> cur_char >> req_num;

		if (cur_char == last_char) {
			diff = abs(req_num - pos[cur_char]);
			last_count += (diff + 1);
		} else {
			int temp = abs(req_num - pos[cur_char]) - last_count;
			diff = 	0 > temp ? 0 : temp;
			last_count = diff + 1;
		}

		last_char = cur_char;
		pos[cur_char] = req_num;
		total += (diff + 1);
	}

	return total;
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
		cout << process_testcase(s) << endl;
	}
	is.close();
	return 0;
}