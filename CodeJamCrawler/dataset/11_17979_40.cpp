#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int cc;
	cin>>cc;
	for(int cid=1;cid<=cc;++cid) {
		int n;
		cin>>n;
		vector <string> s(n);
		double ans[111]={0},owp[111]={0};
		for(int i=0;i<n;++i) cin>>s[i];
		for(int i=0;i<n;++i) {
			int win = 0, total = 0;
			for(int j=0;j<n;++j)
				if(s[i][j]!='.') {
					++total;
					if(s[i][j]=='1') ++win;
				}
			ans[i] = .25*double(win)/double(total);
		}
		for(int i=0;i<n;++i) {
			int nopp = 0;
			for(int j=0;j<n;++j)
				if(s[i][j]!='.') {
					++nopp;
					int win = 0, total = 0;
					for(int k=0;k<n;++k)
						if(s[j][k]!='.'&&k!=i) {
							++total;
							if(s[j][k]=='1') ++win;
						}
					owp[i] += double(win)/double(total);
				}
			owp[i] /= (double)nopp;
			ans[i] += .5*owp[i];
		}
		for(int i=0;i<n;++i) {
			int nopp = 0;
			double total = 0;
			for(int j=0;j<n;++j)
				if(s[i][j]!='.') {
					total += owp[j];
					++nopp;
				}
			ans[i] += .25*total/double(nopp);
		}
		cout<<"Case #"<<cid<<":"<<endl;
		for(int i=0;i<n;++i) cout<<ans[i]<<endl;
	}
	return 0;
}
