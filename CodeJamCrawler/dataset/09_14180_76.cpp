#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
	char buf[1024];
	char buf2[1024];

	char **words;
	char **cases;
	char **master;
	int l, n, d;
	int i,j,k,x,r,y;
	int offset,offset2;
	int open;
	int openings;

	int offsets[256];
	char charset[256][256];
	char repeat[256][256];
	char invert[256][256];

	int alpha[26];
	int bInvert[256];


	int bFound;

	int count;
	int nenum;

	int bRepeat;
	int rep;

	scanf("%d %d %d", &l, &d, &n);

	words=malloc(4*d);
	cases=malloc(4*n);
	master=malloc(4*d);

	for(i=0;i<d;i++){
		scanf("%s", buf);
		buf[strlen(buf)]=0;
		words[i]=malloc(strlen(buf)+2);
		master[i]=malloc(strlen(buf)+2);
		memset(words[i], 0, strlen(buf)+2);
		memset(master[i], 0, strlen(buf)+2);
//		strcpy(words[i], buf);
		strcpy(master[i], buf);
	}

	for(i=0;i<n;i++){
		scanf("%s", buf);
		buf[strlen(buf)]=0;
		cases[i]=malloc(strlen(buf)+2);
		memset(cases[i], 0, strlen(buf)+2);
		strcpy(cases[i], buf);
	//	dumpcode(cases[i], strlen(cases[i])+2);
	}

//printf("Input done.============\n");

	for(i=0;i<d;i++){
	//	printf("words: %s = %d\n", words[i], strlen(words[i]));
	}

	for(i=0;i<n;i++){
	//	printf("cases: %s =%d\n", cases[i], strlen(cases[i]));
	//	dumpcode(cases[i], strlen(cases[i])+2);
	}

//printf("=======================\n");
	//for each case, enumerate
	for(i=0;i<n;i++){
//printf("Case #%d-------------\n", i+1);
		//initialize
		for(j=0;j<256;j++){
			memset(charset[j], 0, 256);
			//memset(repeat[j], 0, 256);
		}
		rep=0;
		memset(buf, 0, 1024);
		offset=0;
		k=0;

		openings=0;

		//grab () and replace with *
		for(j=0;j<strlen(cases[i]);j++){
//printf("j: %d = %c\n", j, cases[i][j]);
			if(cases[i][j]=='('){
//printf("DEBUG: Opening\n");
				open=TRUE;
				offset2=0;
				openings++;
			}
			else if(cases[i][j]==')'){
//printf("DEBUG: Closing\n");
				offset++;
				buf[k++]='*';
				open=FALSE;
			}
			else if(open==TRUE){
//printf("To charset: %c\n", cases[i][j]);
				charset[offset][offset2++]=cases[i][j];
			}
			else if(open==FALSE){
//printf("To buf %c\n", cases[i][j]);
				buf[k++]=cases[i][j];
			}
			else{
			//	printf("Never come here again\n");
			}
		}
		
		buf[k]=0;

		//now go one by one
		
		//calculate total enumeration
		for(j=0,nenum=1;j<offset;j++){
			nenum*=strlen(charset[j]);
//printf("charset #%d: %s\n", j, charset[j]);
//printf("multiplying %d\n", strlen(charset[j]));
		}


//copy words from master
for(j=0;j<d;j++){
	strcpy(words[j], master[j]);
}

	//elimination
		for(j=0, offset=0;j<strlen(buf);j++){

			for(x=0;x<d;x++){

			//	printf("Word #%d: %s\n", x+1, words[x]);
				if(strlen(words[x])<=0)
					continue;

				else if(buf[j]=='*'){
			//		printf("process *\n");
					bFound=FALSE;
		//printf("Charset[%d]::%s\n", offset, charset[offset]);
					for(y=0;y<strlen(charset[offset]);y++){

		//printf("Comparing %c with %c in %s\n", words[x][j], charset[offset][y], words[x]);
						if(words[x][j]==charset[offset][y]){
						//	printf("Safe\n");
							bFound=TRUE;
							break;
						}
					}
					if(bFound==FALSE){
					//	printf("eliminating %s\n", words[x]);
						words[x][0]=0;
					}
				}
				else{
				//	printf("process single\n");
//printf("Single Comparing %c with %c in %s\n", words[x][j], buf[j], words[x]);
					if(words[x][j]!=buf[j]){

						//printf("eliminating %s\n", words[x]);
						words[x][0]=0;
					}
				}
			}
			if(buf[j]=='*')
				offset++;
		}


		count=0;
		for(j=0;j<d;j++){
			if(strlen(words[j])>0)
				count++;
		}

		printf("Case #%d: %d\n", i+1, count);	
	}

}