#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxn 1100


char names[110][110];

char q[maxn][110];

int p[maxn];

bool match[110][maxn];

bool pp[maxn][maxn];

int i,j,n,m;

inline void make(){
	
	int ans=0,nowmax=0,now=0;
	for(i=1;i<=m;i++){
		for(j=i;j<=m;j++)if(pp[i][j])if(j>nowmax)nowmax=j;
		if(now<i)now=nowmax,ans++;
	}
	if(ans>0)
	printf("%d\n",ans-1);
	else printf("0\n");
}

int main(){
	int ii,nn;
	scanf("%d",&nn);
	for(ii=1;ii<=nn;ii++){
		printf("Case #%d: ",ii);
		scanf("%d",&n);
		gets(names[0]);
		for(i=1;i<=n;i++)gets(names[i]);
		scanf("%d",&m);
		gets(names[0]);
		for(i=1;i<=m;i++)gets(q[i]);
		memset(match,0,sizeof(match));
		memset(pp,0,sizeof(pp));
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)match[i][j]=(strcmp(names[i],q[j])==0);
		for(i=1;i<=n;i++){
			int last=0;
			for(j=1;j<=m;j++)if(match[i][j]){
				pp[last+1][j-1]=1;
				last=j;
			}
			pp[last+1][m]=1;
		}
		make();
	}
	return 0;
}