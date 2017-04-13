#include <fstream>

using namespace std;

int main()
{
	ifstream fin("B-large.in");
	ofstream fout("out.txt");
	int t; fin >> t;
	char b[101][101], mi[101], mj[101];
	for(int c = 1; c <= t; c++)
	{
		fout << "Case #" << c << ": ";
		int si,sj;fin >> si;fin >> sj;
		int p;
		for(int i = 0; i < si; i++){ mi[i] = 0 ;}
		for(int j = 0; j < sj; j++){ mj[j] = 0; }
		for(int i = 0; i < si; i++){
			for(int j = 0; j < sj; j++){
				fin >> p; b[i][j] = p;
				if(mi[i] < p) mi[i] = p;
				if(mj[j] < p) mj[j] = p;
			}
		}
		bool yes = true;
		for(int i = 0; i < si && yes; i++){
			for(int j = 0; j < sj; j++){
				if(b[i][j] != mi[i] && b[i][j] != mj[j]) {yes = false; break;}
			}
		}
		if(yes) fout << "YES" << endl;
		else fout << "NO" << endl;
	}
	fin.close();
	fout.close();
	return 0;
}