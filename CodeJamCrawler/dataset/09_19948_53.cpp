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

int diri[]={-1,0,0,1};
int dirj[]={0,-2,2,0};

char last = 'a';

char check(int ii, int j, vector<string>& res, vector<string>& basin )
{
	int mini = -1, minj = -1;
	int min = 100;

	for(int k=0; k < 4; ++k)
	{
		if( (ii + diri[k]) >= 0 && (ii + diri[k]) < basin.size() && (j + dirj[k]) >= 0 && (j + dirj[k]) < basin[ii].size()  )
		{
			if( basin[ii + diri[k]][j + dirj[k]] < basin[ii][j] && basin[ii + diri[k]][j + dirj[k]] < min )
			{
				mini = 	ii + diri[k];
				minj =  j + dirj[k];
				min = basin[ii + diri[k]][j + dirj[k]];				
			}
		
		}
	}

	if( mini == -1 )
		return 'A';
	else if( res[mini][minj] != 'A' )
		return res[mini][minj];
	else
		return check(mini,minj, res, basin);
}

void solve(int ii, int j, vector<string>& res, vector<string>& basin)
{
	int mini = -1, minj = -1;
	int min = 100;

	for(int k=0; k < 4; ++k)
	{
		if( (ii + diri[k]) >= 0 && (ii + diri[k]) < basin.size() && (j + dirj[k]) >= 0 && (j + dirj[k]) < basin[ii].size()  )
		{
			if( basin[ii + diri[k]][j + dirj[k]] < basin[ii][j] && basin[ii + diri[k]][j + dirj[k]] < min )
			{
				mini = 	ii + diri[k];
				minj =  j + dirj[k];
				min = basin[ii + diri[k]][j + dirj[k]];				
			}
		
		}
	}
	
	if( mini != -1 && minj != - 1)
	{
		if( res[mini][minj] == 'A' )
		{
			if( res[ii][j] == 'A' )
			{
				char car = check(mini,minj, res, basin);
				if( car == 'A') 
				{
					++last;
					res[ii][j] = last;
				}
				else
				{
					res[ii][j] = car; 
				}
			}

			res[mini][minj] = res[ii][j];
			solve(mini, minj, res, basin);
		}
		else
		{
			res[ii][j] = res[mini][minj];
		}
	}
	if( mini == -1 && minj == -1)
	{
		if( res[ii][j] == 'A')
		{
			++last;
			res[ii][j] = last;
		}
	}
}

int main()
{
	ofstream file("out.txt", ios::out | ios::trunc );
	vector<string> contenu = readFile("in.txt");

	int cas = 0;
	for(int i=1; i < contenu.size(); ++i)
	{
		++cas;
		int h, w;
		sscanf(contenu[i].c_str(), "%d %d", &h, &w);
		
		vector<string> basin;

		++i;
		int tt = i;

		for(; i < h + tt; ++i)
		{
			basin.push_back(contenu[i]);
		}

		--i;

		vector<string> res(basin);

		for(int j=0; j < res.size(); ++j)
		{
			for(int k=0; k < res[j].size(); k+=2)
				res[j][k] = 'A';
		}

		res[0][0]='a';

		last = 'a';	
		for(int ii=0; ii < basin.size(); ++ii)
		{
			

			for(int j=0; j < basin[ii].size(); j+=2)
			{
				solve(ii,j,res,basin);
			}
		}

		file << "Case #" << cas << ":" << endl;
		for(int j=0; j < res.size(); ++j)
		{
			file << res[j];
			if( i != contenu.size() - 1 || j != res.size()-1 )
				file << endl;
		}
		
	}

	file.close();
	return 0;
}