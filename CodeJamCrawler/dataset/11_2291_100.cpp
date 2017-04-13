#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

typedef pair<char,char> joft;

int main()
{
	int t;
	cin >> t;
	for(int tn=1;tn<=t;tn++) {
		int c,d,n;
		map<joft,char> comb;
		set<joft> opps;
		cin>>c;
		for(int i=0;i<c;i++) {
			string s;
			cin>>s;
			comb[joft(s[0],s[1])]=s[2];
			comb[joft(s[1],s[0])]=s[2];
		}
		cin>>d;
		for(int i=0;i<d;i++) {
			string s;
			cin>>s;
			opps.insert(joft(s[0],s[1]));
			opps.insert(joft(s[1],s[0]));
		}
		cin>>n;
		vector<char> list;
		for(int i=0;i<n;i++) {
			char c;
			cin>>c;
			list.push_back(c);
			while( list.size() > 1 && comb.find(joft(list.back(),list[list.size()-2])) != comb.end() ) {
					char res = comb[joft(list.back(),list[list.size()-2])];
					list.pop_back();
					list.pop_back();
					list.push_back(res);
			}
			for(int i=0;i<list.size()-1;i++) {
				if(opps.find(joft(list[i],list.back())) != opps.end()) {
					list.clear();
					break;
				}
			}
		}
		cout<<"Case #"<<tn<<": [";
		for(int i=0;i<list.size();i++) {
			if(i>0)
				cout<<", ";
			cout<<list[i];
		}
		cout<<']'<<endl;
	}
}
