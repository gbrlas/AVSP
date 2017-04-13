#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int ans;
int n,m;
int g[101];

int getcoin(int *used,int l){
	int tmp[1000]={0};
	for(int i=0;i<n;i++)tmp[i]=1;
	for(int j=0;j<m;j++)if(used[j]==1){tmp[g[j]]=0;}
	int ret=0;
	for(int i=g[l]-1;i>=0;i--){
		if(tmp[i])ret++;
		else break;
	}
	for(int i=g[l]+1;i<n;i++){
		if(tmp[i])ret++;
		else break;
	}
	return ret;
}

void getans(int num,int *used,int total){
	if(num==m){
		//cout<<total<<endl;
		if(total<ans)ans=total;
		return;
	}
	else{
		for(int i=0;i<m;i++){
			if(used[i]==0){
				used[i]=1;
				//for(int h=0;h<m;h++)cout<<used[h]<<" ";cout<<endl;
				getans(num+1,used,total+getcoin(used,i));
				used[i]=0;
			}
		}
	}
	return;
}

int main(){
	int tn;cin>>tn;
	for(int ttt=0;ttt<tn;ttt++){
		ans=10000000;
		cin>>n>>m;
		for(int i=0;i<m;i++){cin>>g[i];g[i]--;}
		sort(g,g+m);
		int used[100]={0};
		getans(0,used,0);
		cout<<"Case #"<<(ttt+1)<<": "<<ans<<endl;
	}
}
