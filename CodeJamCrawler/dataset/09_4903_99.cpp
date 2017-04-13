#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int n;
string is;
string rs("welcome to code jam");//19
vector<vector<int> >dpmap;

int main() {
	ifstream fin("jam.in");
	ofstream fout("jam.out");
	
	fin>>n>>ws;
	//cout<<"before loop"<<endl;
	for (int ncase=0; ncase<n; ncase++) {
		getline(fin,is,'\n');
		//cout<<is<<endl;
		dpmap.clear();
		dpmap.resize(is.length());
		for(int i=0; i<is.length(); i++)
			dpmap[i].resize(19,0);
		for (int i=0; i<is.length(); i++) {
			if (is[i] == rs[0]) {
				dpmap[i][0] = 1;
			}
			for (int j=1; j<19; j++) {
				if (is[i] == rs[j]) {
					int sum=0;
					for (int k=0; k<i; k++)
						sum+=dpmap[k][j-1];
					dpmap[i][j] = sum%10000;
					//cout<<ncase<<" map "<<i<<" "<<j<<" "<<dpmap[i][j]<<endl;
				}
			}
		}
		fout<<"Case #"<<ncase+1<<": ";
		fout.fill('0');
		fout.width(4);
		int sum=0;
		for (int k=0; k<is.length(); k++)
			sum+=dpmap[k][18];
		sum = sum%10000;
		fout<<sum;
		
		//cout<<"res="<<is.length()-1<<" 18 "<<sum<<endl;
		fout.fill(' ');
		fout.width(0);
		fout<<endl;
	}
	return 0;
}
