#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <list>
using namespace std;

map< string, string > comb;
list< char > opp[30];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		comb.clear();
		for(int i=0; i<=26; i++) opp[i].clear();
		string s;
		int C;
		cin>>C;
		for(int i=0; i<C; i++){
			cin>>s;
			string tmp = s.substr(0,2);
			comb[tmp] = s[2];
			reverse(tmp.begin(),tmp.end());
			comb[tmp] = s[2];
		}
		int D;
		cin>>D;
		for(int i=0; i<D; i++){
			cin>>s;
			opp[s[0]-'A'].push_back(s[1]);
			opp[s[1]-'A'].push_back(s[0]);
		}
		int N;
		cin>>N;
		cin>>s;
		string cur;
		for(int i=0; i<N; i++){
			cur+=s[i];
			if(cur.length()==1) continue;
			map< string, string>::iterator iter;
			string tmp = cur.substr(cur.length()-2,2);
			while((iter=comb.find(tmp))!=comb.end()){
				cur = cur.substr(0,cur.length()-2)+iter->second;
				if(cur.length()==1) break;
				tmp = cur.substr(cur.length()-2,2);
			}
			if(cur.length()==1) continue;
			for(list<char>::iterator it = opp[cur[cur.length()-1]-'A'].begin(); it!=opp[cur[cur.length()-1]-'A'].end(); it++){
				int z = cur.find(*it);
				if(z>=0){ cur=""; break;}
			}
		}
		cout<<"Case #"<<testnum+1<<": [";
		for(int i=0; i<cur.length(); i++){
			if(i>0) cout<<", ";
			cout<<cur[i];
		}
		cout<<"]"<<endl;
	}
	return 0;
}
