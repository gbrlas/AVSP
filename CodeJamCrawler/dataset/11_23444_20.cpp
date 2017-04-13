#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//	Google Code Jam 2011
//	Problem A. Bot Trust
//	Solution by Guillermo Croppi.
//	PD: I loved portal 2!
	

int main() {

	int blue, orange, buttons, pushed;
	int dblue, dorange;
	int aux, scont, ocont, bcont, lb, lo;;
	int caso=0,caso2=1;
	char seq[5000];
	char robotseq[5000]={""};
	int o[5000];
	int b[5000];
	int time;
	char * token, whopush;
	FILE * fp, * gp;
	
	freopen("A-small-attempt2.in","r",stdin);
	gp = fopen("output-portalcoop-gc2.out","w+");
//	Debug...
//	freopen("test.txt","r+",stdin);
	
	scanf("%d ",&caso);
	while(caso--){
		gets(seq);
		
		scont=0; ocont=0; bcont=0;
		
		token = strtok(seq," ");
		buttons = atoi(token);
		
		while(token != NULL){
			
			token = strtok(NULL," ");
			if(token==NULL) break;
			
			if (*token == 'O'){
				robotseq[scont++]=*token;
				token = strtok(NULL," ");
				o[ocont++]=atoi(token);
			}
			else{
				robotseq[scont++]=*token;
				token = strtok(NULL," ");
				b[bcont++]=atoi(token);
			}
		}
		lb=bcont;
		lo=ocont;
		
		bcont=0; ocont=0; scont=0;
		time=0;
		
		orange=1;
		dorange=o[ocont++];
		blue=1;
		dblue=b[bcont++];
		
	
		whopush=robotseq[scont++];
		pushed=0;
//		Debug...
/*		printf("  Seq   |   O   |   B   |  D O  |  D B  |   S   \n");*/
		while (pushed != buttons){
			switch(whopush){
			case 'O':
				if (orange==dorange) {
					if(ocont<=lo) {
						dorange=o[ocont++]; pushed++;
						whopush=robotseq[scont++];
					}
					
					if(blue < dblue) blue++;
					else if(blue > dblue) blue--;
					time++;
				}
				else{
					if(orange < dorange) orange++;
					else if (orange > dorange) orange--;
					
					if(blue < dblue) blue++;
					else if(blue > dblue) blue--;
					time++;
				}
				break;
			case 'B':
				if (blue==dblue) {
					if(bcont<=lb) {
					dblue= b[bcont++]; pushed++;
					whopush=robotseq[scont++];
					}
					
					if(orange < dorange) orange++;
					else if (orange > dorange) orange--;
					time++;
				}
				else{
					if(orange < dorange) orange++;
					else if (orange > dorange) orange--;
					if(blue < dblue) blue++;
					else if(blue > dblue) blue--;
					time++;
				}
				break;
			}
//			Debug...
//			printf("  %3c   |  %3d  |  %3d  |  %3d  |  %3d  |  %3d   ",whopush,orange,blue,dorange,dblue,time);
//			printf("\n");
		}
		
		fprintf(gp,"Case #%d: %d\n",caso2++,time);
//			Debug...
//		printf("Case #%d: %d\n",caso2++,time);
//		system("pause");
	}
	fclose(gp);
	return 0;
}

