#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

#define MAXL 105
#define RAIDES "abcdefghijklmnopqrstuvwxyz"

using namespace std;

struct taskas
{
	bool ar;
	float sk;
	string s;
	int taip;
	int ne;
} t[MAXL];
int maxt = 0;
string visas;
map<string, bool> m[MAXL];


int skaitom (int pos, int nr)
{
	pos = visas.find_first_of("(", pos);
	int sk = visas.find_first_not_of(" ", pos+1);
	int sk_pb = visas.find_first_of(" ", sk+1);
	int kiek = sk_pb - sk;
	t[nr].sk = atof(visas.substr(sk,kiek).c_str());
	if (visas.find_first_of(RAIDES, sk_pb-1) < visas.find_first_of(")", sk_pb-1))
	{
 		t[nr].ar = true;
 		
		int pr = visas.find_first_of(RAIDES, sk_pb+1);
		int pb = visas.find_first_not_of(RAIDES, pr+1);
		kiek = pb - pr;
 		t[nr].s = visas.substr(pr, kiek);
 		
 		maxt++;
 		t[nr].taip = maxt;
 		sk_pb = skaitom(sk_pb-1, maxt);
 		maxt++;
 		t[nr].ne = maxt;
 		sk_pb = skaitom(sk_pb-1, maxt);
 	} else {
 		t[nr].ar = false;
 	};

	return sk_pb;
}

float einame (int nr, int gyv)
{
	if (!t[nr].ar)
	{
		return (t[nr].sk);
	} else {
		if (m[gyv].count(t[nr].s)>0)
		{
			return (t[nr].sk * einame(t[nr].taip, gyv));
		} else {
			return (t[nr].sk * einame(t[nr].ne, gyv));
		}
	}
	
}

int main ()
{
	ifstream fin("A.in");
	ofstream fout("A.out");
	int T;
	string line;
	string srch;
	fin >> T;
	
	for (int t=1; t<=T; t++)
	{
	
		fout << "Case #" << t << ":" <<  endl;
		cout << "Case #" << t << ":" <<  endl;
		
		int L;
		visas = "";
		fin >> L;
		getline(fin, line);
		for (int l=0; l<L; l++)
		{
			getline(fin, line);
			//cout << line << endl;		
			visas += line;
		}
		
		maxt = 1;
		skaitom(0, 1);
		
		
		fin >> L;
		getline(fin, line);
		for (int l=0; l<L; l++)
		{
			//getline(fin, line);
			m[l].clear();
			fin >> line;
			int j;
			fin >> j;
   			for (int i=0; i<j; i++)
      		{
        		fin >> line;
        		m[l][line] = true;
         	} 

			
			double rez = einame (1, l);
			cout << setprecision (7) << fixed  << rez  << endl;
			fout << setprecision (7) << fixed  << rez  << endl;
			
		}

	}

	fout.close();
	cin.get();
	return 0;
}
