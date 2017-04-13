#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main () {
	freopen("input.txt","r",stdin);		
	freopen("output.txt","w",stdout);
	int t,i,j,k,l;
	scanf("%d",&t);
	for(i=1;i<=t;i++) {
		int a,b,ans=0;
		scanf("%d %d",&a,&b);
		char s[20];
		int chk[10];
		int chkk=0;
		itoa(a,s,10);
		int len=strlen(s);
		int div=(int)pow((long double)10,len-1);
		for(j=a;j<=b;j++) {
			for(k=0;k<=9;k++) chk[k]=0;
			int temp=j;
			for(k=1;k<len;k++) {
				temp=(temp/div)+(temp%div)*10;
				int chk2=0;
				for(l=0;l<chkk;l++) {
					if (chk[l]==temp) chk2=1;
				}
				if (a<=temp && b>=temp && chk2==0 && temp!=j) {
					ans++;
					chk[chkk++]=temp;	
				}
			}
			chkk=0;
		}
		ans/=2;
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}