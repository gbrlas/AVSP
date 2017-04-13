#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<double,double> joft;

const int maxn= 1010;
double b[maxn];
double e[maxn];
double w[maxn];
vector<joft> ans;

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		double x,s,r,t,n;
		cin>>x>>s>>r>>t>>n;
		double elap = 0;
		double cur = 0;
		double tot = 0;
		ans.clear();
		for(int i=0;i<n;i++) {
			cin>>b[i]>>e[i]>>w[i];
			//reach to corridor
			tot+=b[i]-cur;
			elap += (b[i]-cur)/s;
			cur = b[i];

			ans.push_back(joft(s+w[i],e[i]-cur));
			elap += (e[i]-cur)/(s+w[i]);
			cur = e[i];
		}

		//reach to the end of the corridor
		tot+=x-cur;
		ans.push_back(joft(s,tot));
		elap += (x-cur)/s;
		cur = x;
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++) {
			double temp = min(t,ans[i].second/(ans[i].first-s+r));
			elap -= (temp*(ans[i].first-s+r))/ans[i].first;
			elap += temp;
			t-= temp;		
		}
		cout<<"Case #"<<tn+1<<": "<<fixed<<setprecision(7)<<elap<<endl;
	}
}
