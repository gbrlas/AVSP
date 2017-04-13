#include <fstream>

using namespace std;

int main()
{
	ifstream fin("C-small-attempt0.in");
	ofstream fout("out.txt");
	int t; fin >> t;
	for(int c = 1; c <= t; c++)
	{
		fout << "Case #" << c << ": ";
		int a,b;fin >> a;fin >> b;
		int count = 0;
		if(a <= 1 && b >= 1) count++;
		if(a <= 4 && b >= 4) count++;
		if(a <= 9 && b >= 9) count++;
		if(a <= 121 && b >= 121) count++;
		if(a <= 484 && b >= 484) count++;
		fout << count << endl;
	}
	fin.close();
	fout.close();
	return 0;
}