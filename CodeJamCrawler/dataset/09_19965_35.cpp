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

int main()
{
	ofstream file("out.txt");
	vector<string> contenu = readFile("in.txt");

	for(int i=1; i < contenu.size(); ++i)
	{
		string str = contenu[i];

		bool ff = false;
		for(int j=str.size()-2; j >= 0; --j)
		{
			int f = false;
			for(int k=str.size()-1; k > j; --k )
			{
				if( str[j] < str[k] )
				{
					char temp = str[j];
					str[j] = str[k];
					str[k] = temp;

					for(int l=j+1; l < str.size(); ++l)
					{
						for(int m=l+1; m < str.size(); ++m)
						{
							if( str[l] > str[m] )
							{
								char tt = str[l];
								str[l] = str[m];
								str[m] = tt;
							}
						}
					}
					
					f = true;
					break;
				}
			}

			if( f) 
			{
				ff = true;
				break;
			}
		}
		
		if(!ff)
		{
			str+='0';
			sort(str.begin(), str.end());

			int n = 0;
			for(int j=0; j < str.size(); ++j)
			{
				if( str[j] == '0')
					++n;
				else
					break;
			}

			str = str.substr(n, str.size()-n);

			string nres="";
			nres+=str[0];

			for(int j=0; j < n; ++j)
				nres += '0';

			for(int j=1; j < str.size(); ++j)
				nres += str[j];

			file << "Case #" << i << ": " << nres << endl;
		}
		else
			file << "Case #" << i << ": " << str << endl;
	}

	file.close();
	return 0;
}