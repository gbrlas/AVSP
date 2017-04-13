/*
 * main.c
 *
 *  Created on: Apr 12, 2014
 *      Author: george
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *in,*out;
	int a[4][4],b[4][4],i,n,j,x,k,nr,t,y;

	in=fopen("A-small-attempt1.in","r");
	out=fopen("A-small-attempt1.out","w");

	if(in==0){

		fprintf(stderr,"Error input!");
		exit(EXIT_FAILURE);
	}
	if(out==0){

			fprintf(stderr,"Error output!");
			exit(EXIT_FAILURE);
		}
	fscanf(in,"%d",&n);

	for(k=1;k<=n;k++){

		fscanf(in,"%d",&x);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++){
			fscanf(in,"%d",&a[i][j]);
			}
		}

	fscanf(in,"%d",&y);

	for(i=0;i<4;i++){

		for(j=0;j<4;j++){

			fscanf(in,"%d",&b[i][j]);
		}
	}


	nr=0;
	for(i=0;i<4;i++)
	{

		for(j=0;j<4;j++){

			if(a[x-1][i]==b[y-1][j]){
				++nr;
				t=a[x-1][i];
			}
			}
	}

	if(nr==1){
		fprintf(out,"\tCase #%d: %d\n",k,t);
	}
	else{
		if(nr>1)
			fprintf(out,"\tCase #%d: Bad magician!\n",k);

		else
		{
			fprintf(out,"\tCase #%d: Volunteer cheated!\n",k);
		}
	}
	}

	fclose(in);
	fclose(out);
	return 0;
}
