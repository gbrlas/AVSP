#include"macro.h"

int dp[10010][2];
int g[10010], c[10010];
int val[10010];
int m,v;
bool isLeaf(int n) {
	return n>((m-1)/2);
}

int left(int n) {
	return 2*n;
}

int right(int n) {
	return 2*n+1;	
}
int rec(int node, int desired) {
	//printf("%d %d\n", node, desired);
	if (dp[node][desired]!=-1) return dp[node][desired];


	if (isLeaf(node)) {		
		if (val[node]==desired)
			return 0;
		else
			return inf;
	}

	int answer = inf;
	

	// use original settings
	if (g[node]==1) {

		if (desired == 1)  {
			int t1 = rec(left(node),1);
			int t2 = rec(right(node), 1);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2);
		} else {
			int t1 = rec(left(node), 0);
			int t2 = rec(right(node), 1);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2);
			
			t1 = rec(left(node), 1);
			t2 = rec(right(node), 0);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2);


			t1 = rec(left(node), 0);
			t2 = rec(right(node), 0);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2);
		}

	} else {
		if (desired == 1) {
			int t1 = rec(left(node),1);
			int t2 = rec(right(node), 1);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2);

			t1 = rec(left(node), 0);
			t2 = rec(right(node), 1);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2);

			t1 = rec(left(node), 1);
			t2 = rec(right(node), 0);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2);
		} else {
			int t1 = rec(left(node),0);
			int t2 = rec(right(node), 0);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2);
		}
	}
	
	if (c[node]==0) {
		
		dp[node][desired] = answer;
		//printf("%d %d: answer=%d\n", node, desired, answer);
		return answer;
	}


	
	if (g[node]==1) { // change to OR

		if (desired == 1) {
			int t1 = rec(left(node),1);
			int t2 = rec(right(node), 1);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2 + 1);

			t1 = rec(left(node), 0);
			t2 = rec(right(node), 1);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2 + 1);

			t1 = rec(left(node), 1);
			t2 = rec(right(node), 0);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2 + 1);

		} else {
			
			int t1 = rec(left(node),0);
			int t2 = rec(right(node), 0);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2 + 1);

		}

	} else { // change to AND

		if (desired == 1)  {
			int t1 = rec(left(node),1);
			int t2 = rec(right(node), 1);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2 + 1);
		} else {
			int t1 = rec(left(node), 0);
			int t2 = rec(right(node), 1);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2 + 1);
			
			t1 = rec(left(node), 1);
			t2 = rec(right(node), 0);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2 + 1);


			t1 = rec(left(node), 0);
			t2 = rec(right(node), 0);
			if (t1!=inf&&t2!=inf) 
				answer = min(answer, t1+t2 + 1);
		}
	}

	//printf("%d %d: answer=%d\n", node, desired, answer);
	dp[node][desired] = answer;
	return answer;
}
int solve() {	
	scanf("%d %d",&m,&v);
	
	memset(dp,-1,sizeof(dp));


	for(int i=1; i<=(m-1)/2; i++) 
		scanf("%d %d",&g[i],&c[i]);
	
	for(int i=(m-1)/2+1; i<=m; i++) 
		scanf("%d",&val[i]);

	int answer=rec(1, v);

	return answer;
}
int main() {
	freopen("A-large.in","r",stdin);
	freopen("Alarge.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	FOR(i,1,t)  {		
		int answer = solve();				
		
		if (answer!=inf)
			cout<<"Case #"<<i<<": "<<answer<<endl;
		else
			cout<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}
