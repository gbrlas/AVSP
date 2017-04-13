#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,f,k,cnt,w,m,n,t,d,q=0;
	char c,x,v;
	scanf("%d",&t);
	while( t-- ) {
		d=0;q++;w=0;
		char a[5][5];
		for( i = 0; i < 4; i ++) {
			f=0,cnt=0;
			scanf("%s",a[i]);
			c=a[i][0];
			for(j=0;j<4;j++) {
				if(c!='.' && (a[i][j]==c || a[i][j]=='T'))
					cnt++;
				if(a[i][j]=='.')
					d=1;
			}
			if(cnt==4)
				w=1,x=c;
		}
		if(w==1)
			printf("Case #%d: %c won\n",q,x);
		if( w==0 ) {
			for(i=0;i<4;i++) {
				x=a[0][i],cnt=0;
				for(j=0;j<4;j++) {
					if(a[j][i]==x || a[j][i]=='T')
						cnt++;
					if(a[j][i]=='.')
						break;
				}
				if(cnt==4) {
					w=1;printf("Case #%d: %c won\n",q,x);break;
				}
			}
		}
		if(w==0) {
			c=a[0][0];cnt=0;
			for(i=0;i<4;i++) {
				if(a[i][i]==c || a[i][i] == 'T')
					cnt++;
				if(a[i][i]=='.')
					break;
			}
			if(cnt==4){
				w=1;printf("Case #%d: %c won\n",q,c);}
		}
		if(w==0) {
			c=a[0][3];m=3;cnt=0;
			for(i=0;i<4;i++,m--) {
				if(c == a[i][m] || a[i][m] == 'T')
					cnt++;
				if(a[i][m]=='.')
					break;
			}
			if(cnt==4){
				w=1;printf("Case #%d: %c won\n",q,c);}
		}
		if(w==0 && d==0)
			printf("Case #%d: Draw\n",q);
		if(w==0 && d==1)
			printf("Case #%d: Game has not completed\n",q);
	}
	return 0;
}

