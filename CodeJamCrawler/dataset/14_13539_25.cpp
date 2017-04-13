#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;
int main() {
	int T;
	cin>>T;
	for (int k = 1; k <= T; k++) {
		int c1;
		int c2;
		set<int> s1;
		set<int> s2;
		cin>>c1;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++) {
				int x;
				cin>>x;
				if (i == c1)
					s1.insert(x);
			}
		cin>>c2;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++) {
				int x;
				cin>>x;
				if (i == c2 && s1.find(x) != s1.end())  
					s2.insert(x);
			}
		cout<<"Case #"<<k<<": ";
		if (s2.size() == 1) {
			cout<<*(s2.begin())<<endl;
		} else if (s2.size() ==  0) {
			cout<<"Volunteer cheated!"<<endl;
		} else {
			cout<<"Bad magician!"<<endl;
		}
	}
}