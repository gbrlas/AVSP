#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

class ChangeStream {
public:
	template <typename Type>
	std::string ToString( const Type &str ) {
		std::ostringstream	ostream;
		ostream << str;
		return ostream.str();
	}

	template <typename Type>
	unsigned int ToInt( const Type &str ) {
		std::stringstream	stream;
		stream << str;
		stream >> value;
		return value;
	}

private:
	int				value;
};

namespace {
	const int	MAX_N(30);
}

int main(void)
{
	const char infname[] = "A-large.in";
	ifstream	fin(infname);
	if( fin.fail() )
	{
		cout << "File open failed: " << infname << endl;
		return -1;
	}

	string	fname(infname);
	fname = fname.substr(0, fname.find(".")) + ".out";
	ofstream	fout(fname.c_str());
	if( fout.fail() )
	{
		cout << "File open failed: " << fname << endl;
		return -1;
	}

	map<int, int>	max_nums;
	max_nums.insert( make_pair(1,1) );
	for( int i=1, num(1); i<=MAX_N; i++ )
	{
		num += (int)::pow((double)2, i);
		max_nums.insert( make_pair(i+1, num) );
	}

	ChangeStream	cs;
	string	line;
	getline(fin, line);
	//int	input_num(cs.ToInt(line));
	int	cnt(1);
	while( getline(fin, line) )
	{
		int	switch_num(cs.ToInt(line.substr(0, line.find(" "))));
		int switch_cnt(cs.ToInt(line.substr(line.find(" ")+1)));

		if( switch_cnt == 0 )
		{
			fout << "Case #" << cnt << ": OFF" << endl;
			cnt++;
			continue;
		}

		if( switch_num == 1 )
			switch_cnt = switch_cnt % 2;
		else
			switch_cnt = switch_cnt % (max_nums.find(switch_num)->second+1);

		if( switch_cnt == max_nums.find(switch_num)->second )
			fout << "Case #" << cnt << ": ON" << endl;
		else
			fout << "Case #" << cnt << ": OFF" << endl;

		cnt++;
	}

	return 0;
}