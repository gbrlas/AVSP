#include <cstring>
#include <iostream>
#include <iomanip>
#define REP(i,n) for(int i = 0;i<n;i++)

using namespace std;

char wel[] = "welcome to code jam";
int len=19;

int tab[1000][30];

int main() {
	int N;
	cin >> N;
	string s;
	cin.ignore();
	REP(i,N) {
		getline(cin,s);
		int d=s.size();
		REP(j,len) tab[0][j]=0;
		REP(j,d) {
			REP(k,len) {
				tab[j+1][k]=tab[j][k];
				if(s[j]==wel[k] && k-1>=0) tab[j+1][k]+=tab[j][k-1];
				if(s[j]==wel[k] && k==0) tab[j+1][k]+=1;
			}
		}
		cout << "Case #" << i+1 << ": " << setfill('0') << setw(4) << tab[d][len-1] << endl;
	}
	return 0;
}
