#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <algorithm>

#define for1(i,a,b) for(i=a;i<=b;i++)
#define for2(i,a,b) for(i=a;i>=b;i--)
#define max(a,b) (a>b)?(a):(b)
#define min(a,b) (a<b)?(a):(b)

using namespace std;

const int maxn=256;

int n,t,tot;
char q[maxn];
char f1[maxn][maxn];
bool f2[maxn][maxn];

int main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	scanf("%d",&t);
	int i,j,k;
	char c1,c2,c3;
	bool flag;
	for1(i,1,t){
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		tot=0;
		scanf("%d ",&n);
		for1(j,1,n){
			scanf("%c%c%c ",&c1,&c2,&c3);
			f1[c1][c2]=c3;
			f1[c2][c1]=c3;
		}
		scanf("%d ",&n);
		for1(j,1,n){
			scanf("%c%c ",&c1,&c2);
			f2[c1][c2]=true;
			f2[c2][c1]=true;
		}
		scanf("%d ",&n);
		for1(j,1,n){
			scanf("%c",&q[++tot]);
			flag=true;
			while (tot>1 && flag){
				flag=false;
				while (f1[q[tot]][q[tot-1]]!=0){
					q[tot-1]=f1[q[tot]][q[tot-1]];
					tot--;
					flag=true;
				}
				for1(k,1,tot-1)
					if (f2[q[tot]][q[k]]){
						tot=0;
						break;
					}
			}
		}
		printf("Case #%d: [",i);
		if (tot!=0)putchar(q[1]);
		for1(j,2,tot)printf(", %c",q[j]);
		puts("]");
	}
	return 0;
}
