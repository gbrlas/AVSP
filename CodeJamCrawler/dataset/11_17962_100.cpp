#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char g[333][333];
bool h[333][333];

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int cc;
	cin>>cc;
	string t;
	for(int c=1;c<=cc;++c) {
		memset(h,0,sizeof(h));
		memset(g,0,sizeof(g));
		int nc,nd,n;
		cin>>nc;
		for(int i=0;i<nc;++i) {
			cin>>t;
			g[t[0]][t[1]] = g[t[1]][t[0]] = t[2];
		}
		cin>>nd;
		for(int i=0;i<nd;++i) {
			cin>>t;
			h[t[0]][t[1]] = h[t[1]][t[0]] = true;
		}
		cin>>n>>t;
		string s="";
		for(int i=0;i<n;++i) {
			if(s.size()==0) s+=t[i];
			else {
				if(g[t[i]][s[s.size()-1]]>0) s[s.size()-1] = g[t[i]][s[s.size()-1]];
				else {
					bool flag = false;
					for(int j=0;j<s.size();++j)
						if(h[t[i]][s[j]]) {
							flag = true;
							break;
						}
					if(flag) s = "";
					else s += t[i];
				}
			}
		}
		cout<<"Case #"<<c<<": [";
		if(s.size()==0) cout<<"]"<<endl;
		else {
			cout<<s[0];
			for(int i=1;i<s.size();++i) cout<<", "<<s[i];
			cout<<"]"<<endl;
		}
	}
	return 0;
}
