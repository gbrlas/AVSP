#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int getit(long long N, int PD, int PG)
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
	int h = 100;
	while (PD%2==0 && h%2==0) {
		PD /= 2;
		h /= 2;
	}
	while (PD%5==0 && h%5==0) {
		PD /= 5;
		h /= 5;
	}
	if (h <= N)
		return 1;
	return 0;
}
int main(void)
{
	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
		long long N, PD, PG;
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
