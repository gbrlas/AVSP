#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>rel;
#define mp(a,b) make_pair(a,b)
const int inf = 10000000;
map< pair<int,int>, int> M;

int go(int a, int b){
	if(b<=a) return 0;
	int t=lower_bound(rel.begin(), rel.end(), a) - rel.begin();
	if(t==rel.size() || rel[t]>b) return M[ mp(a,b) ]=0;
	if(M.count( mp(a,b) )!=0) return M[ mp(a,b) ];
	int ans=inf;
	while( t<rel.size() && rel[t]<=b ){
		int temp=b-a + go(a, rel[t]-1) + go(rel[t]+1,b);
		if(temp<ans) ans=temp;
		t++;
	}
	return M[ mp(a,b) ] = ans;
}

main(){
	int t; scanf("%d",&t);
	for(int C=1; C<=t; C++){
		M.clear();
		int res=0;
		int p,q;
		scanf("%d %d",&p, &q);
		rel.clear();
		for(int i=0; i<q; i++){
			int temp;
			scanf("%d",&temp);
			rel.push_back(temp);
		}
		res=go(1,p);
		printf("Case #%d: %d\n", C, res);
	}
}
