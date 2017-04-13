#include<iostream>
#include<stdio.h>
#include<string.h>
int L,D,N;
char word[5000][20];
bool avail[15][26];
int ans,cnt;
char ch;
bool dfs(int j,int i) {
	if(i==L) {
	    return true;
	}
	if(!avail[i][word[j][i]-'a']) return false;
	return dfs(j,i+1);
}
int main() {
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d%d%d",&L,&D,&N);
	for(int i=0;i<D;i++)
		scanf("%s",word[i]);
	getchar();
	for(int i=1;i<=N;i++){
		cnt=0;
	        memset(avail,0,sizeof(avail));  
		while(ch=getchar(),ch!='\n')
		{
			if(ch=='(')
			{
				while(ch=getchar(),ch!=')')
					avail[cnt][ch-'a']=1;
			}
			else avail[cnt][ch-'a']=1;
			cnt++;
		}
		if(cnt<L) printf("Case #%d: 0\n",i);
		else {
		   ans=0;
		   for(int j=0;j<D;j++)
		   if(dfs(j,0)) ans++;
		   printf("Case #%d: %d\n",i,ans);
		}
	}
	return 0;
}
