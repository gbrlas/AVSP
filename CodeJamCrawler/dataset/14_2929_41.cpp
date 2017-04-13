#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int n;
		cin>>n;
		vector<int> num;
		for(int i=0;i<n;i++) {
			int temp;
			cin>>temp;
			num.push_back(temp);
		}
		int ans = 0;
		for(int i=0;i<n;i++) {
			int index = min_element(num.begin(), num.end()) - num.begin();
			if (index > num.size()-1-index)
				ans+= num.size()-1-index;
			else
				ans+=index;
			num.erase(num.begin()+index);
		}
		cout<<"Case #"<<tn+1<<": "<<ans<<endl;
	}

}
