#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

const int MAXN=110;
const int MAXM=1010;
const int INF=999999999;

int n,m;
map<string,int> id;
int b[MAXM];
char buf[200];
int f[MAXM][MAXN];

int com(int x,int y)
{
	if(x<0) return 0;
	int &res=f[x][y];
	if(res!=-1) return res;

	res=INF;
	for(int i=0;i<n;i++) {
		if(x>0 && b[x-1]==i) continue;
		int w=com(x-1,i);
		if(i!=y) w++;
		res<?=w;
	}
	return res;
}

int solve()
{
	memset(f,-1,sizeof(f));
	int res=INF;
	for(int i=0;i<n;i++) if(b[m-1]!=i) res<?=com(m-1,i);
	return res;
}

int main()
{
	int T;

	scanf("%d",&T);
	for(int casen=1;casen<=T;casen++) {
		scanf("%d",&n);
		fgets(buf,200,stdin);
		for(int i=0;i<n;i++) {
			fgets(buf,200,stdin);
			string s;
			s=buf;
			id[s]=i+1;
		}
		scanf("%d",&m);
		fgets(buf,200,stdin);
		for(int i=0;i<m;i++) {
			fgets(buf,200,stdin);
			string s;
			s=buf;
			b[i]=id[s];
			if(b[i]==0) printf("ERROR\n");
			b[i]--;
		}

		printf("Case #%d: %d\n",casen,solve());
	}

	return 0;
}

