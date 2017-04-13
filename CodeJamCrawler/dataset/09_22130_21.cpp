#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

char poly[200];
char buf[100];
int d;
vector<string>act;

int mod = 10009;
int val[100];

int evaluate(){
	int res=0, tmp=1;
	for(int i=0; i<d; i++){
		if(poly[i]=='+'){res+=tmp; tmp=1; continue;}
		tmp*=val[ poly[i]-'a' ];
		tmp%=mod;
	}
	res+=tmp;
	return res%mod;
}

void add(string s, int v){
	for(int i=0; i<s.size(); i++) val[s[i]-'a']+=v;
}

int algo(int first, int k, vector<string>&dict){
	int res=0;
	if(k==0){
		return evaluate();
	}
	for(int i=0; i<dict.size(); i++){
		add(dict[i],1);
		res+=algo(i+1, k-1, dict);
		res%=mod;
		add(dict[i],-1);
	}
	return res;
}

void go(int Case){
	for(int i=0; i<100; i++) val[i]=0;
	vector<string>dict;
	printf("Case #%d: ",Case);
	int n,k;
	scanf("%s %d",poly, &k);
	d=strlen(poly);
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%s",buf);
		dict.push_back(string(buf));
	}
	sort(dict.begin(),dict.end());
	for(int t=1; t<=k; t++){
		printf("%d ", algo(0, t, dict));
	}
	printf("\n");
}

main(){
	int t; scanf("%d",&t);
	for(int C=1; C<=t; C++){
		go(C);
	}
	return 0;
}
