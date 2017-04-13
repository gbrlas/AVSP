#include <fstream>
using namespace std;

void ReadFile(char* filename, char* destination);
void Read(char* source, char* dest);

int main()
{
	ReadFile("B-small-attempt2.in", "Aout.txt");
	Read("B-small-attempt2.in", "Yout.txt");
	return 0;
}

void ReadFile(char* filename, char* destination)
{
	ifstream in;
	ofstream out;
	in.open(filename);
	out.open(destination);

	int T, N, S, p, r;

	in >> T;

	for(int i = 1; i <= T; i++)
	{
		in >> N >> S >> p;
		r = 0;
		for(int j = 1; j <= N; j++)
		{
			int Score, x, y;
			in >> Score;

			x = Score/3;
			y = Score%3;
			if(x >= p)
				r++;
			else if(x == p-1 && y > 0)
				r++;
			else if(x != 0 && x == p-1 && y == 0 && S > 0)
			{
				r++;
				S--;
			}
			else if(x == p-2 && y > 1 && S > 0)
			{
				r++;
				S--;
			}
		}
		out << "Case #" << i << ": " << r;
		if(i != T)
			out << endl;
	}
}

void Read(char* source, char* dest)
{
	ifstream fin(source);
	ofstream fout(dest);
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
}