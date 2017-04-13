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

vector<int> pris;

int total;
int totlacells;


int main()
{
	ofstream file("out.txt");
	vector<string> contenu = readFile("in.txt");

	int test = 0;
	for(int i=1; i < contenu.size(); ++i)
	{
		++test;
		int p, q;
		stringstream out;
		out << contenu[i];
		out >> p >> q;
		++i;
		
		totlacells = p;
		total = (1 << 31 ) -1;
		


		out.clear();
		out << contenu[i];
	
		pris.clear();

		int temp;
		while( out >> temp )
		{
			pris.push_back(temp);
		}

		vector<int> cells(10010);
	
		
		
		int myres = (1<<31) - 1;
		do
		{
			fill(cells.begin(), cells.end(), 1);
			
			int res = 0;
			for(int j=0; j < pris.size(); ++j)
			{
				cells[pris[j]] = 0;
				
				for(int i = pris[j]-1; i > 0; --i)
				{
					if( cells[i] )
						++res;
					else
						break;
				}

				for(int i= pris[j] + 1; i <= totlacells; ++i)
				{	
					if( cells[i] )
						++res;
					else
						break;
				}
			}

			if( res < myres )
				myres = res;
		}while(next_permutation(pris.begin(), pris.end()));


		file << "Case #" << test <<": " << myres << endl;
	}

	file.close();
	return 0;
}