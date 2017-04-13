#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
long long  T,N,res,val,ans;
vector< long long > V;
cin>>T;
for(int i=1; i <= T; i++){
	cin>>N;
	V.clear();
	val=0;
	ans=0;
	for(int j=0; j < N; j++){
	cin>>res;
	val=val^res;
	ans+=res;
	V.push_back(res);
	}
	if(val!=0){
		cout<<"Case #"<<i<<": "<<"NO"<<"\n";
	}
	else{
		sort(V.begin(),V.end());
		cout<<"Case #"<<i<<": "<<ans-V[0]<<"\n";
	}
	
}
return 0;
}
