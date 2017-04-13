#include <iostream>
#include <sstream>
#include <fstream>
#include "math.h"

using namespace std;

int main(int argc, char **argv)
{
	string s = argv[1];
	ifstream comingFlow(s.data());
	ofstream fichier("output.sol", ios::out | ios::trunc);
	int nbInst;
	string line;
    getline(comingFlow, line);
	stringstream str;
    str << line;
    str >> nbInst;
	for(int i=0;i<nbInst;i++)
	{
		getline(comingFlow, line);
		int n;
		int k;
		stringstream str2;
		str2 << line;
		str2 >> n;
		str2 >> k;
		cout << n << endl;
		int cycle = (int)(pow((double)2,n));
		cout << cycle << endl;
		if((k%cycle)==(cycle-1))
		{
			fichier << "Case #" << (i+1) << ": ON" << endl;
		}
		else
		{
			fichier << "Case #" << (i+1) << ": OFF" << endl;
		}
	}
	return 0;
}