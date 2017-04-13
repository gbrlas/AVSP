#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1000010;

int dis[maxn];

int main()
{
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int l,n,c;
		long long t;
		cin>>l>>t>>n>>c;
		for(int i=0;i<c;i++)
			cin>>dis[i];
		for(int i=c;i<n;i++)
			dis[i] = dis[i-c];
		long long total = 0;
		for(int i=0;i<n;i++)
			total+=2*dis[i];
		int sum = 0;
		int lim = t/2;
		int ind;
		for(ind=0;ind<n;ind++) {
			sum+=dis[ind];
			if(sum>=lim) {
				dis[ind] = sum-lim;
				break;
			}
		}
		sort(dis+ind,dis+n);
		int mins = 0;
		for(int i=n-1,j=0;i>=ind && j<l;i--,j++) {
			mins+=dis[i];
		}
		total-=mins;
		cout<<"Case #"<<tn+1<<": "<<total<<endl;


	}
}
