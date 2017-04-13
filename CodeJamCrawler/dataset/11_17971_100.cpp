#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int cc;
	cin>>cc;
	for(int c=1;c<=cc;++c) {
		int n, ans = 0;
		cin>>n;
		for(int i=1;i<=n;++i) {
			int t;
			cin>>t;
			if(t!=i) ++ans;
		}
		cout<<"Case #"<<c<<": "<<ans<<".000000"<<endl;
	}
	return 0;
}
