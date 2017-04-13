#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	int L, D, N; 
	ifstream in;
	ofstream out;
	in.open("A-large.in");
	out.open("A-small.txt");
	string str, str1;
	char buf[10000];

	in.getline(buf, 10000, '\n');
	sscanf(buf,"%d %d %d", &L, &D, &N);
	vector<string> src, dat;
	vector<string> input;

	for(int a = 0; a < D; a++ )
	{
		in.getline(buf, 10000, '\n');
		src.push_back(buf);
	}

	sort(src.begin(), src.end());
	str.clear();
	
	for( int i = 1; i <= N; i++ )
	{
		dat = src;
		int start = 0;
		in.getline(buf, 10000, '\n');
		for( int a = 0; a < strlen(buf); a++ )
		{
			if( start )
			{
				if( buf[a] == ')' )
				{
					start = 0;
					input.push_back(str);
				}
				else
				{
					str += buf[a];
				}
			}
			else
			{
				if( buf[a] == '(' )
				{
					str.clear();
					start = 1;
				}
				else
				{
					str = buf[a];
					input.push_back(str);
					str.clear();
				}
			}
		}

		vector<string> tmp, ret;
		for(int a = 0; a < L; a++ )
		{
			for( int b = 0; b < input[a].size(); b++ )
			{
				for( int c = 0; c < dat.size(); c++ )
				{
					if( dat[c][a] == input[a][b] ) 
					{
						tmp.push_back(dat[c]);
					}
				}
			}
			dat = tmp;
			tmp.clear();
		}
		cout << "Case #" << i <<":" << " " << dat.size() << endl;
		out << "Case #" << i <<":" << " " << dat.size() << endl;
		input.clear();
	}

	return 0;
}