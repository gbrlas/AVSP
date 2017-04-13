//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "string.h"

typedef struct stime
{
	char hh;
	char mm;
	struct stime *next;
}Stime;

int timecmp(Stime *phead,Stime *pnode,char tt)
{
	int h1,h2,m1,m2;
	h1=phead->hh;
	m1=phead->mm;
	h2=pnode->hh;
	m2=pnode->mm;
	m1+=tt;
	if(m1>=60)
	{
		m1-=60;
		h1++;
	}
	else if(m1<0)
	{
		m1+=60;
		h1--;
	}
	if(h1<h2)
	{
		return 1;
	}
	else if(h1==h2)
	{
		if(m1<m2)
		{
			return 1;
		}
		else if(m1==m2)
		{
			return 0;
		}
	}
	return -1;
}

Stime *deletestruct1(Stime *phead,Stime *pnode,int *num,int tv)
{
	Stime *pout,*pf,*pc;
	if(phead==NULL)
	{
		return NULL;
	}
	pout=phead;
	pf=phead;
	pc=phead;
	while(pc!=NULL)
	{
		if(timecmp(pnode,pc,tv)>=0)
		{
			(*num)--;
			if(pout==pc)
			{
				pout=pc->next;
			}
			else
			{
				pf->next=pc->next;
			}
			return pout;
		}		
		pf=pc;
		pc=pc->next;
	}
	return pout;
}

Stime *deletestruct2(Stime *phead,Stime *pnode,int *num,int tv)
{
	Stime *pout,*pf,*pc;
	if(phead==NULL)
	{
		return NULL;
	}
	pout=phead;
	pf=phead;
	pc=phead;
	while(pc!=NULL)
	{
		if(timecmp(pnode,pc,tv)<=0)
		{
			if((pc->next==NULL)||(timecmp(pnode,pc->next,tv)>=0))
			{
				(*num)--;
				if(pout==pc)
				{
					pout=pc->next;
				}
				else
				{
					pf->next=pc->next;
				}
				return pout;
			}
		}				
		pf=pc;
		pc=pc->next;
	}
	return pout;
}

Stime *insertstruct(Stime *phead,Stime *pnode)
{
	Stime *pout,*pf,*pc;
	if(phead==NULL)
	{
		return pnode;
	}
	pout=phead;
	pf=phead;
	pc=phead;
	while(pc!=NULL)
	{
		if(timecmp(pnode,pc,0)>=0)
		{
			if(pout==pc)
			{
				pnode->next=pc;
				pout=pnode;
			}
			else
			{
				pf->next=pnode;
				pnode->next=pc;
			}
			return pout;
		}
		pf=pc;
		pc=pc->next;
	}
	pf->next=pnode;
	pnode->next=pc;
	return pout;
}

void main()
{
	int casenum=0,Anum=0,Bnum=0,switch_time=0,i,j;
	char instr=0;
	FILE *fp,*fout;
	Stime *pinnew,*poutnew,inarray[100],outarray[100],tin,tout;

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
		//read time interval
		switch_time=0;
		fread(&instr,sizeof(char),1,fp);
		//while(instr!='\r') 
		while(instr!='\n') 	
		{
			switch_time=switch_time*10+instr-'0';
			fread(&instr,sizeof(char),1,fp);
		}
		//fread(&instr,sizeof(char),1,fp);//read 0x0a

		//read A lines 
		Anum=0;	
		fread(&instr,sizeof(char),1,fp);
		while(instr!=' ')
		{
			Anum=Anum*10+instr-'0';
			fread(&instr,sizeof(char),1,fp);
		}
		
		//read B lines 
		Bnum=0;	
		fread(&instr,sizeof(char),1,fp);
		//while(instr!='\r') 
		while(instr!='\n')
		{
			Bnum=Bnum*10+instr-'0';
			fread(&instr,sizeof(char),1,fp);
		}
		//fread(&instr,sizeof(char),1,fp);//read 0x0a

		pinnew=NULL;
		poutnew=NULL;
		//read A time
		for(j=0;j<Anum;j++)
		{
			//read in hh
			fread(&instr,sizeof(char),1,fp);
			inarray[j].hh=instr-'0';
			fread(&instr,sizeof(char),1,fp);
			inarray[j].hh=inarray[j].hh*10+instr-'0';
			fread(&instr,sizeof(char),1,fp);//read :
			//read in mm
			fread(&instr,sizeof(char),1,fp);
			inarray[j].mm=instr-'0';
			fread(&instr,sizeof(char),1,fp);
			inarray[j].mm=inarray[j].mm*10+instr-'0';

			inarray[j].next=NULL;
			
			fread(&instr,sizeof(char),1,fp);//read 0x20

			//read out hh
			fread(&instr,sizeof(char),1,fp);
			outarray[j].hh=instr-'0';
			fread(&instr,sizeof(char),1,fp);
			outarray[j].hh=outarray[j].hh*10+instr-'0';
			fread(&instr,sizeof(char),1,fp);//read :
			//read out mm
			fread(&instr,sizeof(char),1,fp);
			outarray[j].mm=instr-'0';
			fread(&instr,sizeof(char),1,fp);
			outarray[j].mm=outarray[j].mm*10+instr-'0';

			outarray[j].next=NULL;

			//fread(&instr,sizeof(char),1,fp);//read 0x0d
			fread(&instr,sizeof(char),1,fp);//read 0x0a

			pinnew=insertstruct(pinnew,&inarray[j]);
			poutnew=insertstruct(poutnew,&outarray[j]);
		}
		
		//read B time
		for(j=Bnum;j>0;j--)
		{
			//read in hh
			fread(&instr,sizeof(char),1,fp);
			tin.hh=instr-'0';
			fread(&instr,sizeof(char),1,fp);
			tin.hh=tin.hh*10+instr-'0';
			fread(&instr,sizeof(char),1,fp);//read :
			//read in mm
			fread(&instr,sizeof(char),1,fp);
			tin.mm=instr-'0';
			fread(&instr,sizeof(char),1,fp);
			tin.mm=tin.mm*10+instr-'0';
			
			fread(&instr,sizeof(char),1,fp);//read 0x20

			//read out hh
			fread(&instr,sizeof(char),1,fp);
			tout.hh=instr-'0';
			fread(&instr,sizeof(char),1,fp);
			tout.hh=tout.hh*10+instr-'0';
			fread(&instr,sizeof(char),1,fp);//read :
			//read out mm
			fread(&instr,sizeof(char),1,fp);
			tout.mm=instr-'0';
			fread(&instr,sizeof(char),1,fp);
			tout.mm=tout.mm*10+instr-'0';

			//fread(&instr,sizeof(char),1,fp);//read 0x0d
			fread(&instr,sizeof(char),1,fp);//read 0x0a

			pinnew=deletestruct1(pinnew,&tout,&Anum,switch_time);
			poutnew=deletestruct2(poutnew,&tin,&Bnum,-switch_time);
		}

		//printf("Case #%d: %d %d\n",i+1,Anum,Bnum);
		fprintf(fout,"Case #%d: %d %d\r\n",i+1,Anum,Bnum);
	}
	fclose(fp);
	fclose(fout);

}
