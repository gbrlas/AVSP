#include <stdio.h>

int ca[500];
int cb[500];
int cc[500];
int da[500];
int db[500];

int main() {
	int t, n, it, i, j, c, ic, d, id, len, done;
	char s[200];
	char res[200];
	scanf("%d", &t);
	for(it=1;it<=t;it++) {
		scanf("%d", &c);
		for(ic=0;ic<c;ic++) {
			scanf("%s", s);
			ca[ic]=s[0];
			cb[ic]=s[1];
			cc[ic]=s[2];
		}
		scanf("%d", &d);
		for(ic=0;ic<d;ic++) {
			scanf("%s", s);
			da[ic]=s[0];
			db[ic]=s[1];
		}
		scanf("%d", &n);
		scanf("%s", s);
		
		len=0;
		for(i=0;i<n;i++){
			res[len]=s[i];
			len++;
			res[len]='\0';
			done=0;
			/*printf("res=%s\n", res);*/
			if(2<=len) {
				for(ic=0;ic<c && !done;ic++) {
					if(
						(res[len-1]==ca[ic] && res[len-2]==cb[ic])
						||
						(res[len-1]==cb[ic] && res[len-2]==ca[ic])
					) {
						res[len-2]=cc[ic];
						len--;
						res[len]='\0';
						done=1;
					}
				}
			}
			for(id=0;id<d && !done;id++) {
				if(res[len-1]==da[id]) {
					for(j=0;j<len-1 && !done;++j) {
						if(res[j]==db[id]) {
							len=0;
							res[len]='\0';
							done=1;
						}
					}
				} else
				if(res[len-1]==db[id]) {
					for(j=0;j<len-1 && !done;++j) {
						if(res[j]==da[id]) {
							len=0;
							res[len]='\0';
							done=1;
						}
					}
				}
			}
		}
		printf("Case #%d: [", it);
		for(j=0;j<len-1; j++) {
			printf("%c, ", res[j]);
		}
		if(1<=len)
			printf("%c", res[len-1]);
		printf("]\n");
	}
	return 0;
}
