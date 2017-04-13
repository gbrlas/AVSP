#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

char fi(vector<string>& v, string str)
{
	for(int i=0; i < v.size(); ++i)
	{
		if( v[i].substr(0,2) == str )
			return v[i][2];
	}

	return ' ';
}

int main(int argc, char* argv[])
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w+", stdout);
	
	int T;
	cin >> T;
	for(int l=0; l < T; ++l)
	{
		int C;
		cin >> C;
		
		vector<string> com;

		for(int j = 0; j < C; ++j)
		{
			string temp;
			cin >> temp;
			com.push_back(temp);
		}

		int D;
		cin >> D;

		vector<string> op;

		for(int j = 0; j < D; ++j)
		{
			string temp;
			cin >> temp;
			op.push_back(temp);
		}

		int N;
		cin >> N;

		string word;
		cin >> word;

		string res;
		res += word[0];

		bool ff = false;
		for(int i=1; i < word.size(); ++i)
		{
			if( (int)res.size() == 0 )
			{
				res += word[i];
				continue;
			}

			string temp;
			temp += res[(int)res.size()-1];
			temp += word[i];
			
			char gg = fi(com, temp);
			if( gg != ' ')
			{
				res[(int)res.size()-1] = gg;
				continue;
			}

			temp.clear();
			temp += word[i];
			temp += res[(int)res.size()-1];

			gg = fi(com, temp);
			if( gg != ' ' )
			{
				res[(int)res.size()-1] = gg;
				continue;
			}

			ff = false;
			for(int j=0; j < (int)res.size(); ++j)
			{
				string rem1, rem2;
				rem1 += word[i];
				rem1 += res[j];

				rem2 += res[j];
				rem2 += word[i];

				bool fff = false;
				for(int k=0; k < op.size(); ++k)
				{
					
					if( op[k] == rem1 || op[k] == rem2 )
					{
						res.clear();
						fff = true;
						break;
					}
				}
				if( fff )
				{
					ff = true;
					break;
				}
			}

			if( ff )
			{
				continue;
			}

			
			res += word[i];
			
		}
		
		if( res.size() == 0 )
			cout << "Case #" << (l+1) << ": " << "[]" << endl;
		else
		{
			string res2="[";
			for(int i=0; i < res.size(); ++i)
			{
				if( i == (int)res.size()-1 )
					res2+=res[i];
				else
				{
					res2+=res[i];
					res2+=", ";
				}
			}
			res2+="]";
			cout << "Case #" << (l+1) << ": " << res2 << endl;
		}

		
	}
	
	return 0;
}