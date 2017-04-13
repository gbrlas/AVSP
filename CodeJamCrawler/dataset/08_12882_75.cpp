#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN=210;

int turnT;
int na,nb,n;
int ansA,ansB;
int a[MAXN][2];
bool g[MAXN][MAXN];
bool flag[MAXN];
int inDeg[MAXN];

int readTime()
{
	int h,m;
	scanf("%d:%d",&h,&m);
	return h*60+m;
}

void solve()
{
	memset(inDeg,0,sizeof(inDeg));
	memset(g,0,sizeof(g));
	memset(flag,0,sizeof(flag));

	for(int i=0;i<na;i++)
		for(int j=0;j<i;j++) if(a[j][0]>a[i][0]) {
			swap(a[i][0],a[j][0]);
			swap(a[i][1],a[j][1]);
		}
	for(int i=na;i<n;i++)
		for(int j=na;j<i;j++) if(a[j][0]>a[i][0]) {
			swap(a[i][0],a[j][0]);
			swap(a[i][1],a[j][1]);
		}

	for(int i=0;i<na;i++)
		for(int j=na;j<n;j++) {
			if(a[i][1]+turnT<=a[j][0]) {
				g[i][j]=1;
				inDeg[j]++;
			}
			else if(a[j][1]+turnT<=a[i][0]) {
				g[j][i]=1;
				inDeg[i]++;
			}
		}

	ansA=ansB=0;
	
	bool done;
	do {
		done=1;
		for(int i=0;i<n;i++) {
			if(flag[i]) continue;
			if(inDeg[i]>0) continue;

			if(i<na) ansA++; else ansB++;
			done=0;

			int u=i;
			while(1) {
				flag[u]=1;

				int next=-1;
				for(int v=0;v<n;v++) if(!flag[v] && g[u][v]) {
					inDeg[v]--;
					if(next<0) next=v;
				}
				if(next<0) break;
				u=next;
			}
		}
	} while(!done);
}

int main()
{
	int T;
	scanf("%d",&T);
	
	for(int casen=1;casen<=T;casen++) {
		printf("Case #%d: ",casen);

		scanf("%d",&turnT);
		scanf("%d%d",&na,&nb);
		n=na+nb;
		for(int i=0;i<n;i++) {
			a[i][0]=readTime();
			a[i][1]=readTime();
		}

		solve();
		printf("%d %d\n",ansA,ansB);
	}

	return 0;
}
