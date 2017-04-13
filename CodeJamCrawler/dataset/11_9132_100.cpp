#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<stdio.h>
using namespace std;

#define SMALL
#define LARGE

char combine[128][128];
int opposed[128][128];

int main()	{

	freopen("2.in","r",stdin);
	
#ifdef SMALL	
	freopen("2_small.in","r",stdin);
	freopen("2_small.out","w",stdout);
#endif

#ifdef LARGE	
	freopen("2_large.in","r",stdin);
	freopen("2_large.out","w",stdout);
#endif
	
	int tc;
	cin>>tc;
	for(int tt=1; tt<=tc; tt++)	{

		memset(combine, 0, sizeof(combine));
		memset(opposed, 0, sizeof(opposed));
		
		int c, d, n;

		string s;

		cin>>c;
		for(int i=0;i<c;i++) {
			cin>>s;
			combine[s[0]][s[1]] = s[2];
			combine[s[1]][s[0]] = s[2];
		}

		cin>>d;
		for(int i=0;i<d;i++) {
			cin>>s;
			opposed[s[0]][s[1]] = 1;
			opposed[s[1]][s[0]] = 1;
		}
		
		cin>>n;
		cin>>s;
		vector<char> v;
		for(int i=0;i<n;i++) {
			if(v.size() >= 1) {
				if(combine[s[i]][v.back()]) {
					char c = v.back();
					v.erase(v.end()-1);
					v.push_back(combine[s[i]][c]);
					continue;
				}
			}
			for(int j=0;j<v.size();j++)
				if(opposed[s[i]][v[j]]) {
					v.clear();
					goto NEXT;
				}
			v.push_back(s[i]);
NEXT:;
		}
		cout<<"Case #"<<tt<<": [";
		for(int i=0;i<v.size();i++) {
			if(i) cout<<", ";
			cout<<v[i];
		}
		cout<<"]"<<endl;
	}
	

	return 0;
}
