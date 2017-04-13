#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <fstream>

using namespace std;


vector<string> readFile(string fileName)
{
	ifstream file(fileName.c_str(), ios::in);

	vector<string> contenu;
	string line="";

	while( getline(file,line) )
		contenu.push_back(line);
	
	return contenu;
}

int main()
{
	ofstream file("out.txt", ios::out | ios::trunc );
	vector<string> contenu = readFile("in.txt");


	int l, d, n;
	stringstream out;
	out << contenu[0];
	out >> l >> d >> n;

	vector<string> words;

	int i = 1;
	for(; i <= d; ++i)
	{
		words.push_back(contenu[i]);
	}
	
	vector<string> pattern;

	int tt = i;
	for(; i < n + tt; ++i)
	{
		pattern.push_back(contenu[i]);
	}

	vector< vector<string>  > tokens;

	for(i=0; i < pattern.size(); ++i)
	{
		vector<string> temp;

		bool o = false;
		string str = "";
		for(int j=0; j < pattern[i].size(); ++j)
		{
			if( !o )
			{
				if( pattern[i][j] != '(' )
				{
					string patemp;
					stringstream out;
					out << pattern[i][j];
					out >> patemp;
					temp.push_back(patemp);
				}
				else 
					o = true;
			}
			else
			{
				if( pattern[i][j] != ')' )
				{
					str += pattern[i][j];
				}
				else
				{
					//cout << str << endl;
					temp.push_back(str);
					str = "";
					o = false;
				}
			}
		}

		tokens.push_back( temp );
	}


	int cas = 1;
	for(i=0; i < tokens.size(); ++i)
	{
		int res = 0;
		for(int j=0; j < words.size(); ++j)
		{
			int res_temp = 0;
			for(int k=0; k < words[j].size(); ++k)
			{
				for(int m=0; m < tokens[i][k].size(); ++m)
				{
					if( tokens[i][k][m] == words[j][k] )
					{
						++res_temp;
						break;
					}
				}
			}

			if( res_temp == l )
				++res;
		}
		
		file << "Case #" << cas << ": " << res;
		if( i != tokens.size() - 1 )
			file << endl;
		++cas;	
	}

	file.close();
	return 0;
}