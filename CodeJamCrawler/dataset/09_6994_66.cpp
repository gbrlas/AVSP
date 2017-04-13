#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#define MAXD 5000
#define MAXL 30
#define MAXDIG 30
#define MAXLEN 10000
/* recebe como parâmetro a expressão regular e o input para
 * tentar casar */

char dic[MAXD][MAXL];
int casa(regex_t *reg,int id)
{

    //printf("\nb %s",dic[id]);

	if ((regexec(reg, dic[id], 0, (regmatch_t *)NULL, 0)) == 0){
		//	printf("Casou\n");
		return 1;
	}
	else{
	    	//printf("ñ Casou\n");
		return 0;
	}
}


int main(){

	regex_t reg;
	int i,j,k;
	int L;
	int D;
	int N;
	int count;
    char str[MAXLEN];


	scanf("%d%d%d",&L,&D,&N);

	for(i=0;i<D;i++)
	    scanf("%s",dic[i]);
    for(k=0;k<N;k++){
        int len;
        count=0;
        scanf("%s",str);
        len=strlen(str);
        for(j=0;j<len;j++){
            if(str[j]=='(')
                str[j]='[';
            else if(str[j]==')')
                str[j]=']';
        }
       // printf("\n%s",str);
        if (regcomp(&reg , str, REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
        }
        for(j=0;j<D;j++){
            count+=casa(&reg,j);
        }
        printf("Case #%d: %d\n",k+1,count);
    }
}

