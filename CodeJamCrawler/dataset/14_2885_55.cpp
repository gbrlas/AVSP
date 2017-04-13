#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getans(const vector<double> &a, const vector<double> &b) {
	int ans = 0;
	int total = 0;
	int i=0, j=0;
	while(i<a.size() && j<b.size()) {
		if (a[i]<b[j]) {
			i++;
			if (total>0) {
				total--;
				ans++;
			}

		} else {
			j++;
			total++;
		}
	}

	while(i<a.size()) {
		if (total>0) {
			total--;
			ans++;
		}
		i++;
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int n;
		cin>>n;
		vector<double> a;
		vector<double> b;
		for(int i=0;i<n;i++) {
			double tmp;
			cin>>tmp;
			a.push_back(tmp);
		}
		for(int i=0;i<n;i++) {
			double tmp;
			cin>>tmp;
			b.push_back(tmp);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		cout << "Case #"<<tn+1<<": "<<getans(a,b)<<' '<<n-getans(b,a)<<endl;
	}
}
