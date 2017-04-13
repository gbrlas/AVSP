#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<set>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
#define mp make_pair

int main(){
	int per[] = {1,2,4,5,10,20,25,50,100};
  int t;
	cin>>t;
	for(int cases=0;cases<t;cases++){
		int n,pd,pg;
		bool possible = true;
		PII today = mp(-1,-1),total= mp(-1,-1);
		cin>>n>>pd>>pg;
		for(int i=0;i<9;i++){
			if(pd%per[i]==0 && 100/per[i]<=n){
				today = mp(pd/per[i],100/per[i]);
			}
		}
		if(today.first == -1) possible = false;
		if(pd != pg && (pg == 100 || pg == 0) )
			possible = false;
		printf("Case #%d: ",cases+1);
		if(possible)
			printf("Possible\n");
		else
			printf("Broken\n");
	}

  return 0;
}
