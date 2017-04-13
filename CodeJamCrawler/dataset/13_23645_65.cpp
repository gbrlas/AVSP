#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int i,j,k,n,m,t,q=0;
	scanf("%d",&t);
	while(t--) {q++;
		scanf("%d%d",&m,&n);
		int a[m+1][n+1],b[m][n];
		for(i=0;i<m;i++) {
			k=0;
			for(j=0;j<n;j++) {
				a[i][j]=10;
				scanf("%d",&b[i][j]);
				if(k<b[i][j])
					k=b[i][j];
			}
			a[i][j]=k;
		}
		for(i=0;i<n;i++) {
			k=0;
			for(j=0;j<m;j++) {
				if(k<b[j][i])
					k=b[j][i];
			}
			a[j][i]=k;
		}
		for(i=0;i<m;i++) {
			for(j=0;j<n;j++) {
				if(a[i][j]>a[i][n])
					a[i][j]=a[i][n];
			}
		}
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				if(a[j][i]>a[m][i])
					a[j][i]=a[m][i];
			}
		}
		k=0;
		for(i=0;i<m;i++) {
			for(j=0;j<n;j++) {
				if(b[i][j]!=a[i][j])
					k=1;
			}
			a[i][j]=k;
		}
		if(k==0)
			printf("Case #%d: YES\n",q);
		else 
			printf("Case #%d: NO\n",q);
			
	}
	return 0;
}
