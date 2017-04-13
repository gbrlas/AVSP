#include<stdio.h>
int h[105][105];
typedef long long in64;
bool ispad(in64 n){
	char num[105];
	int j,i;
	for(i=0;n;i++){
		num[i]=n%10;
		n/=10;
	}
	for(j=0,i--;j<i;j++,i--){
		if(num[i]!=num[j])break;
	}
	if(j>=i)return true;
	return false;
}
in64 nexti(in64 n){
	in64 ans=0,t=1;
	while(n){
		ans+=t*(n%3);
		n/=3;
		t*=3;
	}
	return ans;
}
#include<vector>
using namespace std;
vector<in64>vec;
int main(){
	int t,ca=1,i,j,n,m;
	in64 num,a,b;
	for(in64 k=1;(num=nexti(k))<=10000000;k++){
		if(ispad(num)&& ispad(num*num)){
		//	printf("%lld -> %lld\n",k,num*num);
			vec.push_back(num*num);
		}
	}
//	printf("%d\n",vec.size());
	scanf("%d",&t);
	for(ca=1;ca<=t;ca++)
	{
		scanf("%lld%lld",&a,&b);
		for(num=0,i=0;i<vec.size();i++){
			if(vec[i]>=a && vec[i]<=b){
				num++;
			//	printf("%d -> %lld\n",i,vec[i]);
			}
		}
		printf("Case #%d: %lld\n",ca,num);
	}
	return 0;
}
