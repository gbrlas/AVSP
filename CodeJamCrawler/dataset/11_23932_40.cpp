#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cctype>
#include<queue>
#include<cstring>
using namespace std;

char buf[101];
int n;

void go(int pos, long long r){
	if(pos==n){
		long long x = sqrt(r);
		if(x*x==r){
			printf("%s\n",buf);
		}
		return;
	}
	if(buf[pos]=='1'){
		go(pos+1, 2LL*r+1);
	} else if(buf[pos]=='0'){
		go(pos+1, 2LL*r);
	} else {
		buf[pos]='1';
		go(pos+1, 2LL*r+1);
		buf[pos]='0';
		go(pos+1, 2LL*r);
		buf[pos]='?';
	}
}

void solve(){
	scanf("%s", buf);
	n = strlen(buf);
	go(0, 0);
}

main(){
	int T;
	scanf("%d",&T);
	for(int testcase=1; testcase<=T; testcase++){
		printf("Case #%d: ",testcase);
		solve();
	}
	return 0;
}
