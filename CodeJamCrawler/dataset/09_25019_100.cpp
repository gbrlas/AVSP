#include<iostream>
#include<string>
#include<cmath>

using namespace std;


int base;

__int64 mypow(int k){
	if(k==0)
		return 1;
	else
		return base*mypow(k-1);
}
int main(){
	freopen("out.out","w",stdout);
	__int64 ans;
	int match[200];
	int i,len,cs,CSN,cnt;
	char s[70];

	scanf("%d",&CSN);

	for(cs=1;cs<=CSN;cs++){
		printf("Case #%d: ",cs);

		scanf("%s",s);
		base = 2;
		cnt = 0;
		ans = 0;
		memset(match,-1,sizeof(match));

		len = strlen(s);

		match[s[0]-'0'] = 1;
		for(i=1;i<len;i++){
			if(match[s[i]-'0']==-1){
				if(cnt==1){
					cnt++;
				}
				match[s[i]-'0'] = cnt++;
			}
		}
		for(i=0;i<len;i++)
			if(match[s[i]-'0']!=-1 && match[s[i]-'0']+1>base)
				base = match[s[i]-'0']+1;

		for(i=0;i<len;i++){
			ans += match[s[i]-'0']*mypow(len-i-1);
		}
		printf("%I64d\n",ans);
	}

}