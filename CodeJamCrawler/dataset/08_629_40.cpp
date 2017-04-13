#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//freopen("in.txt","r",stdin);
	int t,a,n;
	cin>>t;
	for(int o=0;o<t;o++) {
		cin>>n;
		vector<int> v1,v2;
		for(int i=0;i<n;i++) {
			cin>>a;
			v1.push_back(a);
		}
		for(int i=0;i<n;i++) {
			cin>>a;
			v2.push_back(a);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		long long res=0;
		for(int i=0;i<n;i++)
			res+=v1[i]*v2[n-i-1];
		cout<<"Case #"<<(o+1)<<": "<<res<<endl;
	}
	return 0;
}


