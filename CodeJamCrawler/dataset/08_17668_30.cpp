//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "string.h"

typedef struct server_name
{
	char name[110];
	struct server_name *next;
}SERVER_name;


void main()
{
	int casenum=0,snum=0,qnum=0,switch_times=0,i,j,k;
	char instr=0;
	char tempstr[110];
	FILE *fp,*fout;
	SERVER_name *pnew,*pold,*pf,*pc,namearray[100];
	int noshowsnum;

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

	for(i=0;i<casenum;i++)
	{
		switch_times=0;
		//read server num
		snum=0;	
		fread(&instr,sizeof(char),1,fp);
		//while(instr!='\r') 
		while(instr!='\n')
		{
			snum=snum*10+instr-'0';
			fread(&instr,sizeof(char),1,fp);
		}
		//fread(&instr,sizeof(char),1,fp);//read 0x0a
		pnew=NULL;
		pold=NULL;
		for(j=0;j<snum;j++)
		{
			namearray[j].next=pnew;
			pnew=&namearray[j];
			//read server name
			k=0;
			fread(&instr,sizeof(char),1,fp);
			//while(instr!='\r') 
			while(instr!='\n')
			{
				pnew->name[k++]=instr;
				fread(&instr,sizeof(char),1,fp);
			}
			//fread(&instr,sizeof(char),1,fp);//read 0x0a
			pnew->name[k]=0;
		}
		//read qurey num
		qnum=0;	
		fread(&instr,sizeof(char),1,fp);
		//while(instr!='\r')
		while(instr!='\n')
		{
			qnum=qnum*10+instr-'0';
			fread(&instr,sizeof(char),1,fp);
		}
		//fread(&instr,sizeof(char),1,fp);//read 0x0a

		//read qurey name
		noshowsnum=snum;
		for(j=qnum;j>=noshowsnum;j--)
		{
			//read qurey name
			k=0;
			fread(&instr,sizeof(char),1,fp);
			//while(instr!='\r') 
			while(instr!='\n')
			{
				tempstr[k++]=instr;
				fread(&instr,sizeof(char),1,fp);
			}
			//fread(&instr,sizeof(char),1,fp);//read 0x0a
			tempstr[k]=0;
			pf=pnew;
			pc=pnew;
			while(pc!=NULL)
			{
				if(strcmp(pc->name,tempstr)==0)
				{
					noshowsnum--;
					if(pc==pnew)
					{
						pnew=pc->next;
						pc->next=pold;
						pold=pc;
						//pf=pnew;
						//pc=pnew;
						if(pnew==NULL)
						{
							pnew=pold->next;
							pold->next=NULL;
							switch_times++;
							noshowsnum=snum-1;
						}
					}
					else
					{
						pf->next=pc->next;
						pc->next=pold;
						pold=pc;
						//pc=pf->next;
					}
					break;
				}
				pf=pc;
				pc=pc->next;
			}
		}
		while(j>0)
		{
			//read rest qurey name
			do 
			{
				fread(&instr,sizeof(char),1,fp);
			}while(instr!='\n');//while(instr!='\r');
			//fread(&instr,sizeof(char),1,fp);//read 0x0a
			j--;
		}

		//printf("Case #%d:%d\n",i+1,switch_times);
		fprintf(fout,"Case #%d: %d\r\n",i+1,switch_times);
	}
	fclose(fp);
	fclose(fout);

}
