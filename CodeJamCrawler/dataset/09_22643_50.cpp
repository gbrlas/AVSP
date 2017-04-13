#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	char input[65];
	for(int t=1;t<=T;t++) {
		scanf(" %[^\n]",input);
		int len = strlen(input);
		set<int> s;
		for(int i=0;i<len;i++)
			s.insert(input[i]);
		int base = s.size();
		map<int,int> mp;
		mp[input[0]] = 1;
		int i;
		for(i=1;i<len && input[i]==input[0];i++);
		if(i<len) {
			mp[input[i]] = 0;
			int cnt = 2;
			for(int j=i+1;j<len;j++){
				if(mp.find(input[j]) == mp.end()) {
					mp[input[j]] = cnt++;
				}
			}
		}
		if(base==1) base=2;
		long long int ans = 0, mul = 1;
		for(i=len-1;i>=0;i--) {
			ans += mul*mp[input[i]];
			mul *= base;
		}
		printf("Case #%d: %lld\n",t,ans);
	}
	return 0;
}
