#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int l,n,d;

char words[5000][16];
string pat;
bool cpat[16][32];

int main() {
	ifstream fin("alang.in");
	ofstream fout("alang.out");
	//cerr<<"begin"<<endl;
	fin>>l>>d>>n;
	for (int i=0; i<d; i++) {
		for (int j=0; j<l; j++) {
			fin>>words[i][j];
			//cerr<<words[i][j];
		}
		//cerr<<endl;
	}
	for (int i=0; i<n; i++) {
		fin>>pat;
		for (int j=0; j<15; j++)
			for (int k=0; k<32; k++)
				cpat[j][k] = false;
		int cc = 0;
		int cp = 1;
		for (int j=0; j<pat.length(); j++) {
			if (pat[j] == '(')
				cp = 0;
			if (pat[j] == ')')
				cp = 1;
			if ((pat[j] >= 'a') && (pat[j] <= 'z'))
				cpat[cc][pat[j]-'a'] = true;
			cc+=cp;
		}
		int wm = 0;
		for (int j=0; j<d; j++) {
			bool wmt = true;
			for (int k=0; k<l; k++) {
				if (!cpat[k][words[j][k]-'a']) {
					wmt = false;
					break;
				}
			}
			if (wmt)
				wm++;
		}
		fout<<"Case #"<<i+1<<": "<<wm<<endl;
	}
	fin.close();
	fout.close();
}
