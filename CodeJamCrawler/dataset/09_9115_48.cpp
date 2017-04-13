#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#define MAXQ 105
#define MAXP 10005

using namespace std;

int main ()
{
	ifstream fin("C.in");
	ofstream fout("C.out");

	int kal[MAXQ];

	int T;
	fin >> T;
	
	for (int t=1; t<=T; t++)
	{
		fout << "Case #" << t << ": ";
		cout << "Case #" << t << ": ";
		int n, q;
		fin >> n >> q;
		for (int i=0; i<q; i++)
		{
			fin >> kal[i];
		}
		
		int minm = 1000001;
		
		
		do
		{
		/*
			for (int i=0; i<q; i++)
				cout << kal[i] << " ";
			cout << endl;
		*/
			
			// -----
			int m = 0;
			bool yra[MAXP];
			for (int i=0; i<n; i++)
				yra[i] = true;
			
			for (int i=0; i<q; i++)
			{
				int z = kal[i]-2;
				while (z >= 0 && yra[z])
				{
					m++;
					z--;
				};
				//cout << m << " ";
				z = kal[i];
				while (z < n && yra[z])
				{
					m++;
					z++;
				};
				//cout << m << endl;
				//m = 0;
				yra[kal[i]-1] = false;
			};
			minm = min(minm, m);
   			
			// -----
			
		} while (next_permutation(kal, kal+q));
		
		cout << minm << endl;
		fout << minm << endl;
	}

	fout.close();
	cin.get();
	return 0;
}
