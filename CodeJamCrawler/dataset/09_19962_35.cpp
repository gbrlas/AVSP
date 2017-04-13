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

		sort(str.begin(), str.end());

		int d0 = 0;
		for(int j=0; j < str.size(); ++j)
		{
			if( str[j] != '0' )
			{
				++d0;
				if( d0 > 1 )
					break;
			}
		}

		if( d0 == 1 && str.size() != 1 )
		{
			file << "Case #" << i << ": " << contenu[i]+'0' << endl; 
			continue;
		}

		string res = "";
		bool next = false;
		do
		{
			if( next )
			{
				res = str;
				break;
			}

			if( str == contenu[i] )
				next = true;

		}while(next_permutation(str.begin(),str.end()));

		if( res.size() == 0 )
		{
			sort( str.begin(), str.end() );
			
			res += str[0];
			res += '0';
			for(int j=1; j < str.size(); ++j)
			{
				res+=str[j];
			}
		}
		
		if( res[0] == '0')
		{
			
			int n = 0;
			for(int j=0; j < res.size(); ++j)
			{
				if( res[j] != '0')
				{
					n = j;
					break;
				}
			}

			res = res.substr(n,res.size()-n);

			string nres="";
			nres+=res[0];

			for(int j=0; j < n; ++j)
				nres+='0';
			
	

			for(int j=1; j < res.size(); ++j)
				nres += res[j];

			file << "Case #" << i << ": " << nres << endl; 
		}
		else
			file << "Case #" << i << ": " << res << endl; 
	}

	file.close();
	return 0;
}