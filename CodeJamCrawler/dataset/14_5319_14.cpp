#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

double time(double C, double F, double X, int n)
{
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		result += C / (2 + i*F);
	}
	result += (X / (2 + n*F));
	return result;
}

int main()
{
	ifstream fin("B-small-attempt0.in");
	ofstream fout("B-small-attempt0.out");

	int T = 0;
	fin >> T;
	for (int t = 1; t <= T; t++)
	{
		double C, F, X;
		fin >> C >> F >> X;
		int n = 0;
		double preresult = 999999999999;
		double curresult = 0;
		while (true)
		{
			curresult = time(C, F, X, n);
			if (curresult > preresult) break;
			preresult = curresult;
			n++;
		}
		fout << "Case #";
		fout << t;
		fout << ": ";
		fout << setiosflags(ios::fixed) << setprecision(7) << preresult << endl;
	}

	return 0;
}