#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <fstream>


using namespace std;

int possibilite(int debut,int b, int nombre[9],string& s, int dejavu[9])
{


	stringstream ss;
	ss << debut;
	s = ss.str();
	int size = s.size();
	int possibilite = 0;
	for (int i = 0; i < size; i += 1)
	{
		nombre[i]=s[i]-'0';
	}
	for (int i = 1; i < size; i += 1)
	{
		bool vu = false;
		int resultat = 0;
		for (int j = 0; j < size; j += 1)
		{
			resultat = resultat + nombre[(i+j) % size]*(pow(10,size-j-1));
			if (resultat > b)
			{
				break;
			}
		}
		for (int k = 0; k < i-1; k += 1)
		{
			if (dejavu[k] == resultat)
			{
				vu = true;
			}
		}
		dejavu[i] = resultat;
		if ( debut < resultat && resultat <= b && vu == false)
		{
			possibilite++;
		}
	}
	return possibilite;
}

int main (int argc, char const* argv[])
{
     string const nomFichier("C:/test/scores.txt");
    string const aa("C:/test/CC");
    ifstream monFlux(aa.c_str());
    ofstream monFluxo(nomFichier.c_str());

	int T;
	int dejavu[9];
	monFlux >> T;
	int nombre[9];
	string s;
	for (int i = 0; i < T; i += 1)
	{
		int a;
		int b;
		int resultat= 0;
		monFlux >> a >> b;
		for (int j = a; j < b; j += 1)
		{
			resultat = resultat + possibilite(j,b,nombre,s,dejavu);
		}
		monFluxo << "Case #" << i+1 << ": " << resultat << endl;
	}
	return 0;
}
