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
	
	file.close();
	return contenu;
}


char mm[200];

long long convert(string res, int base)
{
	if( base == 1 )
		++base;
	
	int resres = 0;
	for(int i = res.size() - 1; i >= 0; --i)
	{
		if( res[i] <= '9' )
			resres += (long long)pow((double)base, (double)res.size() - 1 - i)*(res[i]-'0');
		else
			resres += (long long)pow((double)base, (double)res.size() - 1 - i)*(mm[res[i]-'a']-'0');
	}

	return resres;
}

int main()
{
	ofstream file("out.txt");
	vector<string> contenu = readFile("in.txt");
	
	int c = 0;

	for(int i=0; i < 100; ++i)
	{
		mm[i+'a'] = 10 + i;
		if( (i + 'a') == 'z' )
			break;
	}

	


	for(int i=1; i < contenu.size(); ++i)
	{
		char tab[100];

		for(int i=0; i < 100; ++i)
			tab[i] = -1;

		string str = contenu[i];
		
		int a = 0;
		
		string res = "";

		char curr = '0';
		for(int j=0; j < str.size(); ++j)
		{
			if( j != 0 )
			{
				if( !a && (tab[str[j]-'0'] == -1))
				{
					res += '0';
					tab[str[j]-'0'] = '0';
					a = 1;
				}
				else
				{
					if( tab[str[j]-'0'] == -1 )
					{
						if( curr == '9' )
							curr = 'a';
						else
							++curr;

						res += curr;

						tab[str[j]-'0'] = curr;
					}
					else
					{
						res += tab[str[j]-'0'];

					}
				}
			}
			else
			{
				if( tab[str[j]-'0'] == -1 )
				{
						if( curr == '9' )
							curr = 'a';
						else
							++curr;

						res += curr;

						tab[str[j]-'0'] = curr;
				}
				else
				{
						res += tab[str[j]-'0'];

				}
			}

		}

		char min = 'z' + 1;
		char max = '0' - 1;

		int base = -1;
		for(int j=0; j < res.size(); ++j)
		{
			if( res[j] < min )
				min = res[j];
			if( res[j] > max )
				max = res[j];
		}
		

		if( max >= 'a' )
			base = (max - 'a') +  (min - '0') + 2 ;
		else
			base = max - min + 1;

		long long resres = convert(res,base);

		string myr;
		stringstream out;
		out << resres;
		out >> myr;
		file << "Case #" << i <<": " << myr << endl;
	}

	file.close();
	return 0;
}