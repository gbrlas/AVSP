#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

char ch[111];
int id[111];

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int cc;
	cin>>cc;
	for(int c=1;c<=cc;++c) {
		cout<<"Case #"<<c<<": ";
		int n, ans = 0;
		vector <int> pos[2];
		pos[0].push_back(1);
		pos[1].push_back(1);
		cin>>n;
		for(int i=0;i<n;++i) {
			cin>>ch[i]>>id[i];
			int robot = (ch[i]=='O')?0:1;
			pos[robot].push_back(id[i]);
		}
		int cur[2]={0,0};
		for(int i=0;i<n;++i) {
			int robot = (ch[i]=='O')?0:1;
			while(pos[robot][cur[robot]]!=id[i]) {
				++ans;
				if(pos[robot][cur[robot]]<id[i]) ++pos[robot][cur[robot]];
				else --pos[robot][cur[robot]];
				if(cur[1-robot]+1<pos[1-robot].size()) {
					if(pos[1-robot][cur[1-robot]]<pos[1-robot][cur[1-robot]+1]) ++pos[1-robot][cur[1-robot]];
					else if(pos[1-robot][cur[1-robot]]>pos[1-robot][cur[1-robot]+1]) --pos[1-robot][cur[1-robot]];
				}
			}
			++ans;
			++cur[robot];
			if(cur[1-robot]+1<pos[1-robot].size()) {
				if(pos[1-robot][cur[1-robot]]<pos[1-robot][cur[1-robot]+1]) ++pos[1-robot][cur[1-robot]];
				else if(pos[1-robot][cur[1-robot]]>pos[1-robot][cur[1-robot]+1]) --pos[1-robot][cur[1-robot]];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
