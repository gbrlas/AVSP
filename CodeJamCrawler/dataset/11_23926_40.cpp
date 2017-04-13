#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cctype>
#include<queue>
using namespace std;

const int N = 1003;
const int S = 10003;
int t[S];

void solve(){
	int n;
	scanf("%d",&n);
	if(n==0){
		printf("0\n");
		return;
	}
	for(int i=0; i<S; i++) t[i]=0;
	for(int i=0; i<n; i++){
		int a;
		scanf("%d",&a);
		t[a]++;
	}
	multiset<int>s;
	int res = S;
	for(int i=0; i<S; i++){
		while(t[i]>s.size()){
			s.insert(i);
		}
		while(t[i]<s.size()){
			int b = *s.begin();
			res = min(res, i-b);
			s.erase(s.begin());
		}
	}
	printf("%d\n",res);
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
