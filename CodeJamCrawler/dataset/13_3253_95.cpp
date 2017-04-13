#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

typedef long long ll;

int t;
int cnt[10000001];
ll num[10000001];
int main(void){
	int cntt=0;
	for(ll i=1;i<=10000001;i++){
		stringstream ss2;
		ss2 << i;
		string str3,str4;
		ss2 >> str4;
		str3=str4;
		reverse(str3.begin(),str3.end());
		ll j=i*i;
		if(str3==str4){
			stringstream ss;
			ss << j;
			string str,str2;
			ss >> str;
			str2=str;
			reverse(str.begin(),str.end());
			if(str==str2){
				cntt++;
			}
		}
		cnt[i]=cntt;
		num[i]=j;
	}
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		int vl,vr;
		vl=lower_bound(num,num+10000001,a)-num;
		vr=upper_bound(num,num+10000001,b)-num;
		int cntr=cnt[vr-1]-cnt[vl-1];
		printf("Case #%d: %d\n",test,cntr);
	}
	return 0;
}