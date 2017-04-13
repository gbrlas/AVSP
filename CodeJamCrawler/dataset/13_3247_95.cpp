#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

typedef long long ll;

int t;
ll cnt[4];
ll num[4];
int main(void){
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		ll a,b;
		int cnt=0;
		scanf("%lld%lld",&a,&b);
		for(ll i=1;i<=100;i++){
			stringstream ss2;
			ss2 << i;
			string str3,str4;
			ss2 >> str4;
			str3=str4;
			reverse(str3.begin(),str3.end());
			ll j=i*i;
			if(a<=j && j<=b && str3==str4){
				stringstream ss;
				ss << j;
				string str,str2;
				ss >> str;
				str2=str;
				reverse(str.begin(),str.end());
				if(str==str2){
					cnt++;
				}
			}
		}
		printf("Case #%d: %d\n",test,cnt);
	}
	return 0;
}