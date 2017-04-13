//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "string.h"

void composdata(int b[],int n)
{
	int j,temp,k,up;//s1统计比较次数
	up=0;
	while (up<n)
	{
		for(k=n,j=n-1;j>up;j--)
		{
			if(b[j]<b[j-1])
			{
				temp=b[j];
				b[j]=b[j-1];
				b[j-1]=temp;
				k=j;
			}
		}
		up=k;
	}
}
//
void main()
{
	int casenum=0,pnum=0,knum=0,lnum=0,i,j,k,m,outdata,interval;
	int *parray;
	char instr=0;
	FILE *fp,*fout;

	fp=fopen("e:\\input.txt","rb");
	fout=fopen("e:\\output.txt","wb");
	//read case num
	fread(&instr,sizeof(char),1,fp);
	//while(instr!='\r') 
	while(instr!='\n') 	
	{
		casenum=casenum*10+instr-'0';
		fread(&instr,sizeof(char),1,fp);
	}
	//fread(&instr,sizeof(char),1,fp);//read 0x0a

	for(m=1;m<=casenum;m++)
	{
		//read pnum
		pnum=0;	
		fread(&instr,sizeof(char),1,fp);
		//while(instr!='\r') 
		while(instr!=' ')
		{
			pnum=pnum*10+instr-'0';
			fread(&instr,sizeof(char),1,fp);
		}
		//fread(&instr,sizeof(char),1,fp);//read 0x0a
		//fread(&instr,sizeof(char),1,fp);//read 0x20

		//read knum
		knum=0;	
		fread(&instr,sizeof(char),1,fp);
		//while(instr!='\r') 
		while(instr!=' ')
		{
			knum=knum*10+instr-'0';
			fread(&instr,sizeof(char),1,fp);
		}
		//fread(&instr,sizeof(char),1,fp);//read 0x0a
		//fread(&instr,sizeof(char),1,fp);//read 0x20

		//read lnum
		lnum=0;	
		fread(&instr,sizeof(char),1,fp);
		//while(instr!='\r') 
		while(instr!='\n')
		{
			lnum=lnum*10+instr-'0';
			fread(&instr,sizeof(char),1,fp);
		}
		//fread(&instr,sizeof(char),1,fp);//read 0x0a
		
		//read lnum data
		parray=(int *)malloc(lnum*4);
		i=0;
		while(i<lnum)
		{
			j=0;	
			fread(&instr,sizeof(char),1,fp);
			//while(instr!='\r') 
			while((instr!=' ')&&(instr!='\n'))
			{
				j=j*10+instr-'0';
				fread(&instr,sizeof(char),1,fp);
			}
			//fread(&instr,sizeof(char),1,fp);//read 0x0a
			parray[i++]=j;
		}
		composdata(parray,lnum);
		outdata=0;
		k=lnum-1;
		i=1;
		while((i<=pnum)&&(k>=0))
		{
			j=0;
			while((j<knum)&&(k>=0))
			{
				outdata+=parray[k--]*i;
				j++;
			}
			i++;
		}

		if(k>0)
		{
			fprintf(fout,"Case #%d: %s\r\n",m,"impossible");
		}
		else
		{
			//printf("Case #%d:%d\n",i+1,switch_times);
			fprintf(fout,"Case #%d: %d\r\n",m,outdata);
		}

	}
	fclose(fp);
	fclose(fout);

}
//