#include <stdio.h>
#include <string.h>

int main(){
	int T, s=0, i, len;
	char define[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	char in[150];
	FILE* ft= fopen("outfile.txt","w");;

	scanf("%d", &T);
	fflush(stdin);
	while(s < T){
		gets(in);
		
		len = strlen(in);
		fprintf(ft, "Case #%d: ",s+1);
		for(i = 0; i < len; i++){
			if(in[i] == ' ') fprintf(ft,"%c", ' ');
			else{
				fprintf(ft,"%c", define[in[i]-'a']);
			}
		}
		s++;
		fprintf(ft, "\n");
	}
	fclose(ft);
	return 0;
}


	