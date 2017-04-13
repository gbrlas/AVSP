#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

const int MAX = 40;
int n;

int main()	{
	
	freopen("A-small-attempt2.in","rt",stdin);
	freopen("a_small3.out","wt",stdout);
	
	int t,cnt=1;
	cin>>t;
	while(t--)	{
		cin>>n;
		string s;
		vector<int> arr(n);
		for(int i=0;i<n;i++) {
			cin>>s;
			int j;
			for(j=n-1;j>=0;j--) if(s[j]=='1') break;
			arr[i]=j;
		}
		//for(int i=0;i<n;i++) cout<<arr[i]<<endl;
		int ans=0;
		for(int i=0;i<n;i++)	{
			int j;
			for(j=0;j<arr.size();j++)	{
				if(arr[j]<=i) break; 
			}
			ans+=j;
			arr.erase(arr.begin()+j);
		}
		cout<<"Case #"<<cnt++<<": "<<ans<<endl;
	}

	return 0;
}