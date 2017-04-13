#include<iostream>
#include<string>

using namespace std;

int L,D,N,mem[5100];
char dic[5005][20],s[400];
void match(int a,int b,int k){
	int i,j,num;
	for(i=0;i<D;i++){
		num = 0;
		for(j=a;j<=b;j++)
			if(s[j]==dic[i][k])
				num++;

		if(k==0)mem[i]=1;
		mem[i]*=num;
	}
}

int main(){

	freopen("in.txt","r",stdin);
	freopen("out.out","w",stdout);

	int i,j,t,cs,cnt,ans;

	scanf("%d%d%d",&L,&D,&N);
	for(i=0;i<D;i++)
		scanf("%s",dic[i]);
	for(cs=1;cs<=N;cs++){

		ans = 0;

		printf("Case #%d: ",cs);
		scanf("%s",s);
		cnt = 0;
		for(i=0;i<strlen(s);i++){
			if(s[i]=='('){
				for(j=i+1;j<strlen(s);j++)
					if(s[j]==')'){
						match(i+1,j-1,cnt);
						i = j;
						break;
					}
					cnt++;
			}else{
				match(i,i,cnt);
				cnt++;
			}
		}
		for(i=0;i<D;i++)
			ans += mem[i];
		printf("%d\n",ans);
	}
	return 0;
}