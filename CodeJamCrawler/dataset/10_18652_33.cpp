
//	problem a

#include<cstdio>
#include<cstring>
#include<algorithm>

int Dec2Bin(int Dec,
			bool* Det){
	int i=0;
	while(Dec){
		Det[i]=(bool)(Dec&1);
		Dec>>=1;
		i++;
	}
	return i;
}

bool CheckConnect(int len,
				  bool* bin,
				  int n){
	if(n>len)
		return false;
	for(int i=0;i<n;i++)
		if(!bin[i])
			return false;
	if(len)
		return true;
	else
		return false;
}

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t,n,k;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		bool bin[32];
		scanf("%d%d",&n,&k);
		int l=Dec2Bin(k,bin);
		printf("Case #%d: %s\n",i+1,CheckConnect(l,bin,n)?"ON":"OFF");
	}
	return 0;
}