#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxn 1100

int p[maxn];

char s[maxn],ss[maxn];

int i,j,n,m,ans,now;

inline void make(){
	int step=1;
	for(i=0;i<m;i++){
		step*=(i+1);
		p[i]=i;
	}
	while(step--){
		for(i=0;i<n;i+=m){
			for(j=0;j<m;j++)ss[i+j]=s[i+p[j]];
		}
		i=0;
		char last=-1;
		now=0;
		while(i<n){
			if(ss[i]!=last){
				last=ss[i];
				now++;
			}
			i++;
		}
		if(now<ans)ans=now;
		next_permutation(p,p+m);
	}
}

int main(){
	int ii,nn;
	scanf("%d",&nn);
	for(ii=1;ii<=nn;ii++){
		printf("Case #%d: ",ii);
		scanf("%d",&m);
		gets(s);
		gets(s);
		n=strlen(s);
		
		ans=n;
		make();
		printf("%d\n",ans);
	}
	return 0;
}
