#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int main(){
	vector <lint> out;int n,i,j;
	cin>>n;
	for(i=0;i<n;i++){
		int a;cin>>a;string s;lint ret=0;
		for(j=0;j<22;j++){
			s+=((a%10)+'0');a/=10;
		}
		reverse(s.begin(),s.end());next_permutation(s.begin(),s.end());
		for(j=0;j<s.size();j++) ret=ret*10+(s[j]-'0');
		out.pb(ret);
	}
	for(i=0;i<n;i++) cout<<"Case #"<<i+1<<": "<<out[i]<<'\n';
	return 0;
}
