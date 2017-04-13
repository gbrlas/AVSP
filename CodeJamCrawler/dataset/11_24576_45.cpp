#include <stdio.h>
#include <strings.h>

int main(){
	FILE *in = fopen("magica.in","r");
	FILE *out = fopen("magica.out","w");
	int t;
	fscanf(in,"%d", &t);
	for (int test = 1; test<=t; test++) {
		int comb;
		fscanf(in, "\n%d ",&comb);
		int i;
		char c[37][3];//combinations
		for (i = 0; i< comb; i++) {
			fscanf(in,"%c%c%c ", &(c[i][0]),&(c[i][1]),&(c[i][2]));
			//printf("%c%c%c\n",c[i][0],c[i][1],c[i][2]);
		}
		
		int d;
		char o[29][3];//opposities
		fscanf(in,"%d ",&d);
		for (i = 0;i<d;i++) {
			fscanf(in,"%c%c ",&(o[i][0]),&(o[i][1]));
			//printf("%c%c\n",o[i][0],o[i][1]);
		}
		int n;
		fscanf(in,"%d ",&n);
		char s[110];
		char ch;
		int len =0;
		for (i=0; i<n; i++) {
			fscanf(in, "%c", &ch);
			if (len != 0) {
				int j,t;
				bool bbb;
				do {
					bbb =false;
					for (j =0; j<comb; j++){
						if ((s[len-1]==c[j][0] && ch == c[j][1]) || (s[len-1] == c[j][1] && ch == c[j][0])){
							len--;
							ch = c[j][2];
							bbb = true;
							break;
						}
					}
				}while (bbb && len);
				if (len!=0) {
					for (t =0;t<d;t++){
						for (j =0;j<len;j++){
							if ((ch == o[t][0] && s[j]==o[t][1])||(ch == o[t][1] && s[j] == o[t][0])){
								len = 0;
								goto label;
							}
						}
					}
				}
			}
			s[len] = ch;
			len++;
label:;
		}
		fprintf(out,"Case #%d: [",test);
		for (i=0; i<len-1; i++)
			fprintf(out,"%c, ",s[i]);
		if (len)
			fprintf(out,"%c",s[len-1]);
		fprintf(out,"]\n");	
	}
	
	fclose(in);
	fclose(out);
}
