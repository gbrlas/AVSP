#include <stdio.h>

int main()
{
	int button,nxtargto,nxtargtb,i,j,k,nocase,count,poso,posb,pos,turn,caset,flag;
	char input;
	int o[100],b[100],time[100];
	scanf("%d",&nocase);
	for(caset=1;caset<=nocase;caset++)
	{
		time[caset-1]=0;
		flag=0;
		scanf("%d",&button);
		for(k=0;k<100;k++)
		{
			o[k]=0;
			b[k]=0;
		}
		
		for(k=0;k<button;k++)
		{
			getchar();
			scanf("%c",&input);
			getchar();
			scanf("%d",&pos);
			if(input == 'O')
			{
				o[k] = pos;
			}
			else b[k] = pos;
		}
		j=0;
		i=0;
		while(o[j]==0 && j<100)
		{
			j++;
		}
		if(j<100)
		nxtargto=o[j];
		while(b[i]==0 && i<100)
		{
			i++;
		}
		if(i<100)
		nxtargtb = b[i];
		poso=1;
		posb=1;
		if(i ==100) nxtargtb = posb;
		if(j ==100) nxtargto = poso;
		if(i<j) turn = 1 ;else turn = 0;
		while(button!=0)
		{
			time[caset-1]++;
			if(posb<nxtargtb)
			{
				posb++;
			}
			else if(posb>nxtargtb)
			{
				posb--;
			}
			else if(posb == nxtargtb && turn == 1)
			{
				button--;
				i++;
				while(b[i]==0 && i<100)
				{
					i++;
				}
				if(i<100)
				nxtargtb = b[i];
				if(i<j) turn = 1 ;else turn = 0;
				flag=1;
			}
				
			if(poso<nxtargto)
			{
				poso++;
			}
			else if(poso>nxtargto)
			{
				poso--;
			} 
			else if(poso == nxtargto && turn == 0 && flag==0)
			{
				button--;
				j++;
				while(o[j]==0 && j<100)
				{
					j++;
				}
				if(j<100)
				nxtargto=o[j];
				if(i<j) turn = 1 ;else turn = 0;
				
			}	
			flag=0;	
		}
		
	}
	for(caset=1;caset<=nocase;caset++)
	{
		printf("Case #%d: %d\n",caset,time[caset-1]);
	}
}
