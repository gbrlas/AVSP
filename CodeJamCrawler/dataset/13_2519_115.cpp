#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> ans;

int ispalid(long long a) {
	vector<int> d;
	while(a>0) {
		d.push_back(a%10);
		a/=10;
	}
	for(int i=0,j=d.size()-1;i<j;i++,j--)
		if(d[i]!=d[j])
			return false;
	return true;
}

int main() {
	int t;
	for(long long i=1;i<=10000000;i++) {
		if(ispalid(i) && ispalid(i*i)) {
			ans.push_back(i*i);	
		}
	}
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		long long a,b;
		cin>>a>>b;
		int out = upper_bound(ans.begin(),ans.end(),b)-lower_bound(ans.begin(),ans.end(),a);
		cout<<"Case #"<<tn+1<<": "<<out<<endl;
	}
}
