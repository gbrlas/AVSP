#include <fstream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int t; fin >> t;
	for(int cas = 1; cas <= t; cas++)
	{
		int N; fin >> N;
		int S; fin >> S;
		int P; fin >> P;
		int R = 0;
		for(int g = 0; g < N; g++)
		{
			int score; fin >> score;
			int min = score/3;
			int rem = score%3;
			if(min >= P) R++;
			else if(min == P-1 && rem > 0) R++;
			else if(min != 0 && min == P-1 && rem == 0 && S > 0){R++;S--;}
			else if(min == P-2 && rem > 1 && S > 0){R++;S--;}
		}
		fout << "Case #" << cas << ": " << R << endl;
	}
	return 0;
}