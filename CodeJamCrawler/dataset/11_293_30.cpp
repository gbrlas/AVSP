#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int n,m,maxs,ans,tot,len,ch,tmp,ct;
string sa[10010],sb[110];
char z;
int f[10010][30],num[10010][30],g[10010],h[27];

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int t=0,tt; scanf("%d",&tt);
	while (++t<=tt) {
		printf("Case #%d:",t);
		scanf("%d%d",&n,&m);
		for (int i=0; i<n; i++) cin>>sa[i];
		for (int i=0; i<m; i++) cin>>sb[i];
		for (int i=0; i<n; i++) {
			f[i][0]=sa[i].size();
			for (int j=1; j<=26; j++) {
				z=j-1+'a'; f[i][j]=0; num[i][j]=0;
				for (int k=0; k<f[i][0]; k++) {f[i][j]*=10; if (sa[i][k]==z) {++f[i][j]; ++num[i][j];} } 
			}
		}
		for (int ca=0; ca<m; ca++) {
			maxs=-1; len=sb[ca].size();
			for (int i=0; i<n; i++) {
				tot=0; tmp=0; memset(h,0,sizeof(h));
				for (int j=0; j<n; j++) {
					if (i==j) continue;
					if (f[i][0]==f[j][0]) {
						g[++tot]=j;
						for (int k=1; k<=26; k++) h[k]+=num[j][k];
					}
				}
				if (tot!=0) {
				for (int j=0; j<len; j++) {
					ch=sb[ca][j]-'a'+1;
					if ((h[ch]!=0)||(num[i][ch]!=0)) {
						if (h[ch]==0) break;
						if (num[i][ch]==0) {
							++tmp; ct=tot;
							for (int k=ct; k>0; k--) {
								if (f[g[k]][ch]!=0) {
									for (int l=1; l<=26; l++) h[l]-=num[g[k]][l];
									g[k]=g[tot--];
								}
							}
							if (tot==0) break;
						}else {
							ct=tot;
							for (int k=ct; k>0; k--) {
								if (f[g[k]][ch]!=f[i][ch]) {
									for (int l=1; l<=26; l++) h[l]-=num[g[k]][l];
									g[k]=g[tot--];
								}
							}
							if (tot==0) break;
						}
					}
				}
				}
				if (maxs<tmp) {
					maxs=tmp; ans=i;
				}
			}
			cout<<' '<<sa[ans];
		}
		printf("\n");
	}
	return 0;
}

