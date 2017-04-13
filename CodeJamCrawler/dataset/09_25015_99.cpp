#include<iostream>
#include<string>
#define BASE 10000

using namespace std;

int N,cnt[505][3],ans;
char s[505];
const char ob[20] = "welcome to code jam";
                  // 0123456789012345678
                  // elcomew elcome to code jam
const int loc[26] = { 17,-1,-1,13,-1,-1,-1,-1,-1,16,-1,2,-1,-1,-1,-1,-1,-1,-1,8,-1,-1,0,-1,-1,-1 };
                   //  a  b  c  d  e  f  g  h  i  j  k  l m  n  o  p  q  r  s t  u  v w  x  y  z
const int pl[20] = {0,0,0,0,0,1,0,0,1,1,1,1,0,2,2,0,0,1};
                 // 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8

void solve(int k){
	int i,j;
	if(s[k]=='m'){
		cnt[k][1] = 1;
		for(i=k+1;i<strlen(s);i++){
			if(s[i]=='e')
				cnt[k][0]+=cnt[i][1];
		}
	}
	else if(s[k]=='c'){
		for(i=k+1;i<strlen(s);i++){
			if(s[i]=='o'){
				cnt[k][0]+=cnt[i][0];
				cnt[k][1]+=cnt[i][2];	
			}
		}
	}
	else if(s[k]=='o'){
		for(i=k+1;i<strlen(s);i++){
			if(s[i]=='m')
				cnt[k][0]+=cnt[i][0];
			else if(s[i]==' ')
				cnt[k][1]+=cnt[i][1];
			else if(s[i]=='d')
				cnt[k][2]+=cnt[i][0];
		}
	}
	else if(s[k]==' '){
		for(i=k+1;i<strlen(s);i++){
			if(s[i]=='t')
				cnt[k][0]+=cnt[i][0];
			else if(s[i]=='c')
				cnt[k][1]+=cnt[i][1];
			else if(s[i]=='j')
				cnt[k][2]+=cnt[i][0];
		}
	}
	else if(s[k]=='e'){
		for(i=k+1;i<strlen(s);i++){
			if(s[i]=='l')
				cnt[k][0]+=cnt[i][0];	
			else if(s[i]==' '){
				cnt[k][1]+=cnt[i][0];
				cnt[k][2]+=cnt[i][2];
			}
		}
	}
	else{

		for(i=k+1;i<strlen(s);i++){
			if(s[i]==ob[loc[s[k]-'a']+1])
				cnt[k][0]+=cnt[i][pl[loc[s[k]-'a']]];
		}
		if(s[k]=='w')
			ans += cnt[k][0]%BASE;
	}

	cnt[k][0] %= BASE;
	cnt[k][1] %= BASE;
	cnt[k][2] %= BASE;

}

int main()
{
	int i,cs;
	freopen("in.txt","r",stdin);
	freopen("out.out","w",stdout);

	scanf("%d\n",&N);
	for(cs=1;cs<=N;cs++){
		memset(cnt,0,sizeof(cnt));
		printf("Case #%d: ",cs);
		gets(s);
		ans = 0;
		for(i=strlen(s)-1;i>=0;i--)
			solve(i);
		ans%=BASE;
		if(ans>=1000){
			printf("%d\n",ans);
			continue;
		}
		if(ans>=100){
			printf("0%d\n",ans);
			continue;
		}
		if(ans>=10){
			printf("00%d\n",ans);
			continue;
		}
		printf("000%d\n",ans);
	}

}

