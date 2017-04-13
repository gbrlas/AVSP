#include<iostream>
#include<string>

using namespace std;


int mem[10005][10005];
bool v[10005];

int solve(int a,int b){
	int i,ans,k;
	ans = INT_MAX;
	if(a>b) return 0;

	if(mem[a][b]!=-1)return mem[a][b];

	for(i=a;i<=b;i++){
		if(v[i]){
			k = solve(a,i-1)+solve(i+1,b)+b-a;
			if(k<ans)
				ans = k;
		}
	}
	if(ans!=INT_MAX)
		mem[a][b] = ans;
	else
		ans = 0;
	return ans;
}

int main(){

	int P,Q,k,i,cs,CSN;
	scanf("%d",&CSN);
	
	freopen("out.out","w",stdout);
	/*
	cout<<"10000 100"<<endl;
	for(i=1;100*i<=10000;i++)
		cout<<i*100<<endl;
	return 0;
	*/

	for(cs=1;cs<=CSN;cs++){
		printf("Case #%d: ",cs);
		scanf("%d%d",&P,&Q);
		memset(v,0,sizeof(v));
		for(i=0;i<Q;i++){
			scanf("%d",&k);
			v[k] = 1;
		}
		memset(mem,-1,sizeof(mem));

		printf("%d\n",solve(1,P));
	}
}