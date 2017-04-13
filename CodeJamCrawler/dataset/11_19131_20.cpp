#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int getit(int N, int PD, int PG)
{
	if (PG == 100) {
		if (PD == 100)
			return 1;
		else
			return 0;
	}
	if (PG == 0) {
		if (PD != 0)
			return 0;
		else
			return 1;
	}
	for (int i=1; i<=N; i++) {
		if ((PD*i)%100 == 0)
			return 1;
	}
	return 0;
}
int main(void)
{
	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
		int N, PD, PG;
		cin>>N>>PD>>PG;
		int pos = getit(N,PD,PG);
		string s;
		if (pos == 0)
			s = "Broken";
		else
			s = "Possible";
		cout<<"Case #"<<i<<": "<<s<<endl;
	}
}
