#include<stdio.h>
int main () {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,i,j;
	scanf("%d",&t);
	for(i=1;i<=t;i++) {
		int n,s,p,sp=0,ans=0;
		int a[150];
		scanf("%d %d %d",&n,&s,&p);
		for(j=1;j<=n;j++) scanf("%d",&a[j]);
		for(j=1;j<=n;j++) {
			int temp1,temp2; // temp1 = no surprise, temp2 = surprise
			if (a[j]==0) temp1=temp2=0;
			else if (a[j]%3==0) {
				temp1=a[j]/3;
				temp2=temp1+1;
			}
			else if (a[j]%3==1) {
				temp1=a[j]/3+1;
				temp2=temp1;
			}
			else {
				temp1=a[j]/3+1;
				temp2=temp1+1;
			}
			if (temp1>=p) ans++;
			else if (temp2>=p) sp++;
		}
		if (sp>=s) ans+=s;
		else ans+=sp;
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}