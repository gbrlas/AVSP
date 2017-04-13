#include<iostream>
#include<set>
#include<vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int a;
		cin >> a;
		set<int> s1;
		set<int> s2;
		for (int i=1;i<=4;i++) {
			for(int j=0;j<4;j++) {
				int tmp;
				cin>>tmp;
				if (i==a)
					s1.insert(tmp);
			}
		}
		cin >> a;
		for (int i=1;i<=4;i++) {
			for(int j=0;j<4;j++) {
				int tmp;
				cin>>tmp;
				if (i==a)
					s2.insert(tmp);
			}
		}
		vector<int> ans (4);
		vector<int>::iterator it = set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),ans.begin());
		ans.resize(it-ans.begin());
		if (ans.size()==1) {
			cout<<"Case #"<<tn+1<<": "<<ans[0]<<endl;
		} else if (ans.size()>1) {
			cout<<"Case #"<<tn+1<<": Bad magician!"<<endl;
		} else {
			cout<<"Case #"<<tn+1<<": Volunteer cheated!"<<endl;
		}
	}
}

