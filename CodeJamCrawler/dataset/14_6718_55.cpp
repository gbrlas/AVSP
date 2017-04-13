#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;

int main() {
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int t;
	cin>>t;
	for(int index=1;index<=t;index++) {
		set<int> first;
		int firstRow;
		int secondRow;
		int tmp;
		cin>>firstRow;
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				cin>>tmp;
				if(i==firstRow-1) {
					first.insert(tmp);
				}
			}
		}
		cin>>secondRow;
		int count = 0;
		int res=0;
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				cin>>tmp;
				if(i==secondRow-1) {
					if(first.find(tmp)!=first.end()) {
						count++;
						res = tmp;
					}
				}
			}
		}
		cout<<"Case #"<<index<<": ";
		if(count==0) {
			cout<<"Volunteer cheated!"<<endl;
		}else if(count==1) {
			cout<<res<<endl;
		}else {
			cout<<"Bad magician!"<<endl;
		}
	}
}
