#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int main(void)
{
	ifstream fin("ksL.in");
	ofstream fout("A_Large.out");
	int in;
	fin >> in;
	int n = 0;
	int k = 0;
	vector <bool> bank;
	for ( int i = 0 ; i < in ; i ++)
	{
		fin >> n >> k;
		if (((int)(k - (pow(2,n) -1))% (int)(pow(2,n))))
			fout << "Case #" << i + 1 << ":" << " OFF" << endl;
		else
			fout << "Case #" << i + 1 << ":" << " ON" << endl;
	}
	
}