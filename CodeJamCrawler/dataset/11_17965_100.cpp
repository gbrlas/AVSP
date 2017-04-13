#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int cc;
	cin>>cc;
	string t;
	for(int c=1;c<=cc;++c) {
		int n, d, sum = 0, exor = 0, mind = INT_MAX;
		cin>>n;
		for(int i=0;i<n;++i) {
			cin>>d;
			sum += d;
			exor ^= d;
			mind = min(mind,d);
		}
		cout<<"Case #"<<c<<": ";
		if(exor==0) cout<<sum-mind<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
