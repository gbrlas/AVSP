#include<iostream>
using namespace std;
int N,K;
int main(){
//	freopen("ACM.txt","r",stdin);
//	freopen("ACM.out","w",stdout);
	int T,cas = 1;
	cin>>T;
	while(T--){
		cin>>N>>K;
		N = (1<<N)-1;
		if((N&K)==N)
			printf("Case #%d: ON\n",cas++);
		else printf("Case #%d: OFF\n",cas++);
	}
	return 0;
}