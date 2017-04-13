#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

int power(int a, int b)
{
	if (b==0) return 1;
 	int ats=a;
    for (int n=b; n>1; n--) ats*=a;
    return ats;
}


int main ()
{
	ifstream fin("A.in");
	ofstream fout("A.out");
	string sk;
	map<char, int> s;

	int T;
	fin >> T;
	
	for (int t=1; t<=T; t++)
	{
		s.clear();
		fin >> sk;
		bool pirmas = true;
		bool antras = false;
		int maxas = 2;
		for (int i=0; i<sk.length(); i++)
		{
			//cout << i << ": " << sk.at(i) << endl;
			if (s.count(sk.at(i))==0)
			{
				if (pirmas)
				{
					s[sk.at(i)] = 1;
					pirmas = false;
					antras = true;
				} else if (antras) {
					s[sk.at(i)] = 0;
     				antras = false;				
				} else {
					s[sk.at(i)] = maxas;
     				maxas++;		
				}
			} else {
							
			}
			//cout << i << ": " << s[sk.at(i)] << endl;
		}
		//cout << maxas << endl;
		int ats = 0;
		for (int i=0; i<sk.length(); i++)
		{
			ats += s[sk.at(sk.length()-i-1)]*power(maxas,i);
			//cout << s[sk.at(sk.length()-i-1)] << " " << (s[sk.at(sk.length()-i-1)]*power(maxas,i)) << " " << power(maxas,i) << endl;
		}		
		
		fout << "Case #" << t << ": " <<  ats << endl;
		cout << "Case #" << t << ": " <<  ats << endl;
		//cout << endl;
	}

	fout.close();
	cin.get();
	return 0;
}
