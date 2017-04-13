#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char line[50];
char patt[50]="welcome to code jam";
int len;
int ans;
int dep;
void dfs(int i,int cnt) {
	if(cnt==len) {
		ans++;
		return;
	}
	if(i==dep) return;
	if(line[i]==patt[cnt])dfs(i+1,cnt+1);
	dfs(i+1,cnt);
}
	
int main(){
	int n;
	len=strlen(patt);	
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		gets(line);
		ans=0;
		dep=strlen(line);
		dfs(0,0);
	    printf("Case #%d: %04d\n",i,ans%10000);
	}
	return 0;
}
		
		
