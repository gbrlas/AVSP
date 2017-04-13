#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back

char g[200][200];
int n;
double a[200],b[200],c[200];
int w[200],t[200];
int main(){
	int T,ti=0;
	for (scanf("%d",&T);T--;){
		printf("Case #%d:\n",++ti);
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%s",g[i]);
		for (int i=0;i<n;i++){
			int nw=0,nt=0;
			for (int j=0;j<n;j++) if (g[i][j]!='.') {
				nt++;
				if (g[i][j]=='1') nw++;
			}
			w[i]=nw;t[i]=nt;
			a[i]=nw/(double)nt;
		}
		for (int i=0;i<n;i++){
			double s=0,nt=0;
			for (int j=0;j<n;j++) if (g[i][j]!='.') {
				nt+=1;
				int nt=t[j]-1;
				int nw=w[j];
				if (g[i][j]=='0') nw--;
				s+=nw/(double)nt;
			}
			b[i]=s/nt;
		}
		for (int i=0;i<n;i++){
			double s=0,nt=0;
			for (int j=0;j<n;j++) if (g[i][j]!='.') {
				nt+=1;
				s+=b[j];
			}
			c[i]=s/nt;
			printf("%.10f\n",0.25*a[i]+0.5*b[i]+0.25*c[i]);
		}
	}
    return 0;
}
