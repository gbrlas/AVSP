#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#define ilg 20
#define MAXL 505

using namespace std;

int main ()
{
	ifstream fin("C.in");
	ofstream fout("C.out");
	
	char f[ilg+1] = "#welcome to code jam"; 
	int m[ilg];
	char eil[MAXL];
	
	int T;
	fin >> T;

	fin.getline (eil, MAXL);
	
	for (int t=1; t<=T; t++)
	{
		fin.getline (eil, MAXL);
		int c = 0;
		
		for (int i=0; i<ilg; i++)
			m[i] = 0;
		m[0] = 1;
		
		while (eil[c] != '\0')
		{
			for (int i=ilg; i>0; i--)
			{
				if (f[i] == eil[c])
    			{
       				m[i] = (m[i] + m[i-1])%10000;
           		}
			}
			c++;
		}
		fout << "Case #" << t << ": " << setfill('0') << setw(4) << m[ilg-1] << endl; 
	}

	fout.close();
	return 0;
}

