#include <fstream>
#include <cstdlib>
#include <string>
#include <memory>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream fin("r1b.in");
ofstream fout("r1b.out");

int main()
{
	int N;
	int cases = 0;
	fin >> N;
	while (N--)
	{
		string ans;
		string T;
		fin >> T;
		T = "0" + T;
		next_permutation(T.begin(), T.end());
		while (T[0] == '0') T=T.substr(1);
		fout << "Case #" << ++cases << ": " << T << endl;
	}
	return 0;
}