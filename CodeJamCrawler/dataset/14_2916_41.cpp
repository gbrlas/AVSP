#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int n,x;
		cin>>n>>x;
		vector<int> sz;
		for(int i=0;i<n;i++) {
			int temp;
			cin>>temp;
			sz.push_back(temp);
		}
		sort(sz.begin(),sz.end());
		int i = sz.size()-1;
		int j = 0;
		int ans = 0;
		for(;i>j;i--) {
			if (sz[i]+sz[j]<=x)
				j++;
			ans++;
		}
		if (i==j)
			ans++;
		cout<< "Case #"<<tn+1<<": "<<ans<<endl;
	
	}


}
