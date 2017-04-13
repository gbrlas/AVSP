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
	const char infname[] = "C-small-attempt1.in";
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

	ChangeStream	cs;
	string	line;
	getline(fin, line);
	//int	input_num(cs.ToInt(line));
	int	cnt(1);
	while( getline(fin, line) )
	{
		int start_cnt(cs.ToInt(line.substr(0, line.find(" "))));
		line = line.substr(line.find(" ")+1);
		int max_seat_num(cs.ToInt(line.substr(0, line.find(" "))));
		int max_group_num(cs.ToInt(line.substr(line.find(" ")+1)));

		getline(fin, line);
		vector<int>	groups;
		for( int i=0; i<max_group_num-1; i++ )
		{
			groups.push_back(cs.ToInt(line.substr(0,line.find(" "))));
			line = line.substr(line.find(" ")+1);
		}
		groups.push_back(cs.ToInt(line));

		if( max_group_num == 1 )
		{
			int boarding_cnt(0);
			for( int i=0; i<start_cnt; i++ )
			{
				if( groups[0] <= max_seat_num )
					boarding_cnt += groups[0];
			}
			fout << "Case #" << cnt << ": " << boarding_cnt << endl;
		}
		else
		{
			int num(0), boarding_cnt(0);
			for( int i=0; i<start_cnt; i++ )
			{
				int add_num(0), add_cnt(0);
				while( add_num+groups[num] <= max_seat_num )
				{
					add_num += groups[num];
					if( ++num > max_group_num-1 )	num = 0;
					if( ++add_cnt >= max_group_num )	break;
				}
				boarding_cnt += add_num;
			}
			fout << "Case #" << cnt << ": " << boarding_cnt << endl;
		}
		cnt++;
	}

	return 0;
}