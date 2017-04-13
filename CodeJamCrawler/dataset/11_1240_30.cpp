#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <utility>

using namespace std;


#define llong long long 
const double pi = acos(-1.0);

const int N = 10005;
string a[N];
string b[105];
int n,m;
int  ok[N];
int mark[N];


int solve(int t,string y){
	int i,j,k;
	int ans = 0;
	for(i = 0;i<n;i++){
		if(a[i].size()==a[t].size())ok[i] = 1;
		else ok[i] = 0;
	}
	memset(mark,0,sizeof(mark));
	for(i = 0;i<y.size();i++){
		for(j = 0;j<a[t].size();j++){
			if(!mark[a[t][j]-'a'])break;
		}
		if(j==a[t].size())break;
		for(j = 0;j<n;j++){
			if(ok[j] && a[j].find(y[i])!=string::npos){
				break;
			}
		}
		if(j==n)continue;
		if(a[t].find(y[i])!=string::npos){
			mark[y[i]-'a'] = 1;
			for(j = 0;j<n;j++){
				if(!ok[j])continue;
				for(k = 0;k<a[t].size();k++){
					if(a[j][k]==y[i] && a[t][k]!=y[i] || a[j][k]!=y[i] && a[t][k]==y[i]){
						ok[j] = 0;
					}
				}
			}
		}else{
			ans++;
			for(j = 0;j<n;j++){
				if(ok[j] && a[j].find(y[i])!=string::npos){
					ok[j] = 0;
				}
			}
		}
	}
	return ans;
}
int main(){
	//freopen("in.txt","r",stdin);
	freopen("B-small-attempt3.in","r",stdin);
	freopen("out.txt","w",stdout);
	
	int i,j,k,t,nc = 0;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i = 0;i<n;i++)cin>>a[i];
		for(i = 0;i<m;i++)cin>>b[i];
		cout<<"Case #"<<++nc<<":";
		for(i = 0;i<m;i++){
			string ans;
			int tmax = -1;
			for(j = 0;j<n;j++){
				int tmp = solve(j,b[i]);
				if(tmax<tmp){
					ans = a[j];
					tmax = tmp;
				}
			}
			cout<<" "<<ans;
		}
		cout<<endl;
	}
	return 0;
}