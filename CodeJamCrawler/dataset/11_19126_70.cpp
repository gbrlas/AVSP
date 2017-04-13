#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
using namespace std;

vector<char> getit(map<string,char> combine, set<string> opposed, string elements)
{
	/*
	cout<<"combine:"<<endl;
	for (map<string,char>::iterator it=combine.begin(); it!=combine.end(); it++) {
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<"opposed:"<<endl;
	for (set<string>::iterator it=opposed.begin(); it!=opposed.end(); it++)
		cout<<*it<<endl;
	cout<<"end"<<endl;
	*/
	vector<char> cur;
	int N = elements.length();
	for (int i=0; i<N; i++) {
		char c = elements[i];
		cur.push_back(c);
		if (cur.size() == 1)
			continue;
		string s(cur.end()-2, cur.end());
		if (s[0] > s[1])
			swap(s[0], s[1]);
		if (combine.find(s) != combine.end()) {
			cur.pop_back();
			cur.pop_back();
			cur.push_back(combine[s]);
		} else {
			for (int j=0; j<cur.size()-1; j++) {
				string s = string(1, cur[j]) + string(1, c);
				if (s[0] > s[1])
					swap(s[0], s[1]);
				if (opposed.count(s) != 0) {
					cur.clear();
					break;
				}
			}
		}
	}
	return cur;
}
int main(void)
{
	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
		int C,D,N;
		char R; int P;
		map<string,char> combine;
		set<string> opposed;
		cin>>C;
		string s;
		for (int j=0; j<C; j++) {
			cin>>s;
			string key = s.substr(0, 2);
			if (key[0] > key[1])
				swap(key[0], key[1]);
			combine[key] = s[2];
		}
		cin>>D;
		for (int j=0; j<D; j++) {
			cin>>s;
			if (s[0] > s[1])
				swap(s[0], s[1]);
			opposed.insert(s);
		}
		cin>>N;
		cin>>s;
		cout<<"Case #"<<i<<": [";
		vector<char> res = getit(combine, opposed, s);
		for (int j=0; j<res.size(); j++) {
			if (j>0)
				cout<<", ";
			cout<<res[j];
		}
		cout<<"]"<<endl;
	}
}
