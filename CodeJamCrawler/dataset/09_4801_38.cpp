#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>
#include <set>

using namespace std;

int main()
{
	int T; 
	ifstream in; 
	ofstream out;
	in.open("A-large.in");
//	in.open("A-small.in");
	out.open("A.out");
	in >> T; 

	for(int i = 1; i <= T; i++ )
	{
		string str, ret;
		int check[300], cnt = 0;
		vector<pair<char, char> > match;
		memset(check, 0, sizeof(check));
		in >> str;

		if( str.size() == 1 ) out << "Case #" << i << ": " << 1 << endl, cout << "Case #" << i << ": " << 1 << endl;
		else
		{

		for(int a = 0; a < str.size(); a++ )
		{
			if( check[str[a]] == 0 )
			{
				if( match.size() == 0 ) 
				match.push_back(make_pair('1', str[a])); 
				else if( match.size() == 1 )
					match.push_back(make_pair('0', str[a]));
				else match.push_back(make_pair('0' + match.size(), str[a]));
			}
			check[str[a]] = 1;
		}

		for(int a = 0; a < 300; a++ )
			if( check[a] == 1 ) cnt++;

		long long tmp;

		for(int a = 0; a < str.size(); a++ )
			for( int b = 0; b < match.size(); b++ )
			{
				if( match[b].second == str[a] ) 
					ret += match[b].first;
			}
//			sort(ret.begin()+1, ret.end());

			long long sum = 0;
			if( cnt == 1 ) cnt = 2;
		for(int a = 0; a < ret.size(); a++ )
		{
			if( a != 0 ) sum *= cnt;
			sum += ret[a] - '0';
		}

		cout << "Case #" << i << ": " << sum << endl;
		out << "Case #" << i << ": " << sum << endl;
		}
	}

	return 0;
}