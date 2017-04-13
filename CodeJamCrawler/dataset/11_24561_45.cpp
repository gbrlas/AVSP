#include <stdio.h>
#include <stdlib.h>
int min(const int a,const int b){
	if (a<b)
		return a;
	else
		return b;
}
int max(const int a,const int b){
	if (a>b)
		return a;
	else
		return b;
}

int main(){
	int t,n;
	FILE * in = fopen("bot.in","r");
	FILE *out = fopen("bot.out","w");
	fscanf(in, "%d", &t);
	char c[101];
	int pos[101];
	for (int test = 1; test <= t; test++){
		fscanf(in, "%d ",&n);
		int b1 = 1, b2 = 1;
		int t1 = 0, t2 = 0;
		int time = 0;
		int dt;
		int i;
		for (i = 0; i<n; i++) {
			fscanf(in, "%c %d ",&(c[i]) ,&(pos[i]));
			printf("%c,%d\n",c[i],pos[i]);
		}
		c[n]='Q';
		pos[n]=pos[n-1];
		
		for (i = 0; i<n; i++){
			if (c[i] == 'O') {
				if (time == t1)
					dt = 1+ abs(pos[i] - b1);
				else {
					dt = max(1+abs(pos[i] - b1), t2-t1+1);
				}
				t1 +=dt;
				b1 = pos[i];
			} else {
				if (time == t2)
					dt = 1+ abs(pos[i] - b2);
				else {
					dt = max(1+abs(pos[i] - b2), t1-t2+1);
				}
				t2 +=dt;
				b2 = pos[i];
			}
			time =max(t1,t2);
		}
		
		fprintf(out,"Case #%d: %d\n",test , time);
	}
	fclose(in);
	fclose(out);
}
