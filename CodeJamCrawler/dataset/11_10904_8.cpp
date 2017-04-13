#include<stdio.h>

int main()
{

	FILE* inp;
	FILE* out;
	inp = fopen("inp.txt","r");
	out = fopen("out.txt","w");
	int T,N,r,i,j,k;
	
	char table[10][10];
	long double WParr[10];
	long double OWParr[10];
	long double OOWParr[10];
	long double RPIarr[10];
	int winsarr[10];
	int dotsarr[10];
	int wins,dots;
	char w; //waste character used for gobbling up whitespaces
	fscanf(inp,"%d",&T);
	r=T;
	while(T)
	{
		fscanf(inp,"%d",&N);
		fscanf(inp,"%c",&w);
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				fscanf(inp,"%c",&table[i][j]);
			}
				fscanf(inp,"%c",&w);
		}
		//debug
	/*
			for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				printf("%c",table[i][j]);
			}
			printf("\n");
		}
		*/
		//WP calculation
		for(i=0;i<N;i++)
		{
			wins=0;dots=0;
			for(j=0;j<N;j++)
			{
				if(table[i][j]=='.')
				dots++;
				else if(table[i][j]=='1')
				wins++;
			}
			WParr[i]=((long double)wins/(N-dots));
			winsarr[i]=wins;
			dotsarr[i]=dots;
		}
		//OWP calculation
		long double OWPsum;
		int temp;
		for(i=0;i<N;i++)
		{
			OWPsum=0;
			temp=0;
			for(j=0;j<N;j++)
			{ 	
				
				
				
					if(table[j][i]=='1')
					OWPsum+=(long double)(winsarr[j]-1)/(N-1-dotsarr[j]);
					if(table[j][i]=='0')
					OWPsum+=(long double)(winsarr[j])/(N-1-dotsarr[j]);
					if(table[j][i]=='.')
					temp++;
				
			}
			OWParr[i]=OWPsum/(N-temp);
		}
		//OOWP
		long double OOWPsum;
		for(i=0;i<N;i++)
		{
			OOWPsum=0;
			for(j=0;j<N;j++)
			{
				if(j==i||table[j][i]=='.')
				continue;
				else 
				OOWPsum+=OWParr[j];
			}
			OOWParr[i]=(OOWPsum/(N-dotsarr[i]));
		}
		 fprintf(out,"Case #");
		fprintf(out,"%d",r-T+1);
		fprintf(out,": \n");
		//RPI calc
		for(k=0;k<N;k++)
		{
			RPIarr[k] = (1.0/4.0)*WParr[k]+(1.0/2.0)*OWParr[k]+(1.0/4.0)*OOWParr[k];
			fprintf(out,"%Lf\n",RPIarr[k]);
		}
		//debug
		
	      
		
		T--;
	}
	fclose(inp);
	fclose(out);
}
