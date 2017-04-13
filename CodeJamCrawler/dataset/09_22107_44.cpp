#include<cstdio>
#include<vector>
using namespace std;

vector<int>v;

void go(){
	int n=v.size();
	//for(int i=0; i<n; i++) printf("%d ",v[i]);
	int res=0;
	for(int i=0; i<n; i++){
		int first=-1;
		for(int j=0; j<v.size(); j++){
			if(v[j]<=i){
				first=j;
				break;
			}
		}
		res+=first;
		for(int j=first; j+1<v.size(); j++)
			v[j]=v[j+1];
		v.pop_back();
	}
	printf("%d\n", res);
}

char buf[101];
main(){
	int t; scanf("%d",&t);
	for(int a=1; a<=t; a++){
		v.clear();
		int n; scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%s",buf);
			int k=-1;
			for(int j=0; j<n; j++)
				if(buf[j]=='1') k=j;
			v.push_back(k);
		}
		printf("Case #%d: ", a);
		go();
	}
}
