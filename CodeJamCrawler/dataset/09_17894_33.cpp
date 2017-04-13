#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
 FILE *fpin=fopen("A-large.in","r"), *fpout=fopen("output1.txt","w");
 char c,*words,cw,cp;
 char *patterns[500], pattern[1000],*p;	//2d array to store the test-case patterns
 int L,D,N,w,a,w1,a1,i, j, len, inbrace, charmatched, wordunmatched, numwords;

 //initialize data
 fscanf(fpin,"%d%d%d",&L,&D,&N);
 fscanf(fpin,"%c",&c);

 //import the input valid words from the input file
 words=(char*)malloc((sizeof(char))*D*L);
 for(w=0;w<D;w++){
  for(a=0;a<L;a++){
   fscanf(fpin,"%c",words+L*w+a); /* printf("%d %d %c\n",w,a,*(words+L*w+a));*/
  }
  //fscanf(fpin,"%c",&c);
  fscanf(fpin,"%c",&c);
 }//fpin now at the beginning of 1st test-case pattern 
 
 //import test-ase patterns into array
 for(i=0;i<N;i++){
	fscanf(fpin,"%s",pattern);
	len=strlen(pattern);
	p=(char*)malloc(len+1);
	strcpy(p,pattern);
	patterns[i]=p;
}
/* for(i=0;i<N;i++) printf("%s\n",patterns[i]);*/
 
 //analysis
 for(i=0;i<N;i++){	//for each test case pattern 
	numwords = 0;
	for(w=0;w<D;w++){	//checking against each given possible word
		j=0;
		wordunmatched = 0;
		for(a=0;a<L;a++){	//checking gainst each letter of the possible word
			cw = *(words+L*w+a);/*fprintf(fpout,"cw = %c",cw);*/
			inbrace=0;
			do{	
				cp=*(patterns[i]+j); /*fprintf(fpout," cp=%c ", cp);*/j++;
				if(cp=='('){ /*fprintf(fpout,"inbrace\n");*/inbrace = 1; continue; }
				if(!inbrace && cp==cw ) { /*fprintf(fpout,"outbrace, matched %c %c\n",cw,cp)*/;break; }	//character matched
				if(!inbrace && cp!=cw ) { /*fprintf(fpout,"outbrace, unmatched %c %c\n",cw,cp)*/;wordunmatched = 1; break; }	//character not matched
				if(inbrace && cp==cw){/*fprintf(fpout,"inbrace, matched %c %c\n",cw,cp);*/
					while(*(patterns[i]+j)!=')') j++;
					j++;
					break;
				}	//character within braces matched,skip remaining characters in that pair of braces
				if(inbrace && cp!=cw) { /*fprintf(fpout,"inbrace, unmatched %c %c\n",cw,cp);*/ 
					if(cp!=')') continue;
					else wordunmatched = 1; break; 
				}
				if(cp==')') {wordunmatched = 1; break; }
			}while(cp!='\0');
			if(wordunmatched) break;
		}
		if(!wordunmatched) numwords++;	//this word is matched with a patern in the test-case
/*		fprintf(fpout,"w=%d a=%d numwords = =%d\n",w,a,numwords);*/
	}//all words checked against this test-pattern case #n
	fprintf(fpout,"Case #%d: %d\n",i+1,numwords);
}

 fclose(fpin);fclose(fpout);
return 0;
}
