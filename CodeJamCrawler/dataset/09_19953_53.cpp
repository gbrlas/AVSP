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
	ofstream file("cout.txt", ios::out | ios::trunc );
	vector<string> contenu = readFile("cin.txt");
	
	string welcome="welcome to code jam";



	for(int i=1; i < contenu.size(); ++i)
	{
		long long dp[20][550];
		memset(dp, 0, sizeof(dp) );
		
		for(int j=0; j < contenu[i].size(); ++j)
			if( contenu[i][j] == welcome[welcome.size()-1] )
				dp[welcome.size()-1][j] = 1;

		for(int k = welcome.size() - 2; k >= 0; --k)
		{
			for(int j=0; j < contenu[i].size(); ++j)
			{
				if( contenu[i][j] == welcome[k] )
				{
					for(int l=j+1; l < contenu[i].size(); ++l)
					{
						if( contenu[i][l] == welcome[k+1] )
							dp[k][j] += dp[k+1][l];
					}
				}
			}
		}

		long long res = 0;

		for(int j=0; j < contenu[i].size(); ++j)
		{
			if( contenu[i][j] == welcome[0] )
				res += dp[0][j];
		}

		string str="";
		stringstream out;
		out << res;
		out >> str;
		
	
		string strstr = "0000";
		if( str.size() < 4 )
			strstr += str;
		else
			strstr += str.substr(str.size()-4,4);
		
		strstr = strstr.substr(strstr.size()-4,4);

		file << "Case #" << i << ": " << strstr;

		if( i != contenu.size() - 1 )
			file << endl;
		
	}

	return 0;
}