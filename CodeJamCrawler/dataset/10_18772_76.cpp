#include<stdio.h>
FILE *fin;
FILE *fout;
int g[1000];
int money[1000];
int next[1000];
int sum;
int cmoney[1000];
int smoney[1000];
int visited[1000];
main(int argc, char**argv)
{
	fin=fopen(argv[1],"r");
	fout=fopen(argv[2],"w");
	int t;
	fscanf(fin,"%d",&t);
	int tt;
	int r,k,n;
	for(tt=0;tt<t;tt++)
	{
		fscanf(fin,"%d %d %d",&r,&k,&n);
		int i;
		for(i=0;i<n;i++)
		{
			cmoney[i]=smoney[i]=next[i]=visited[i]=0;
			fscanf(fin,"%d", g+i);
		}
		int tn=0;
		for(i=0;i<n;i++)
		{
			int co=i;
			int counter=0;
			sum = g[co];
			while(sum<=k&&counter<n)
			{
				co=(co+1)%n;
				counter++;
				sum+=g[co];
			}
			money[i]=sum-g[co];
			next[i]=co;
			//printf("next[%d]=%d\n",i,next[i]);
		}
		int c=1;
		cmoney[0]=money[0];
		smoney[0]=0;
		smoney[1]=cmoney[0];
		visited[0]=1;
		tn=next[0];
		while(!visited[tn])
		{
			c++;
			cmoney[c-1]=money[tn];
			smoney[c]=smoney[c-1]+cmoney[c-1];
			visited[tn]=c;
			tn=next[tn];
			//printf("tn=%d\n",tn);
		}
		c++;
		cmoney[c-1]=money[tn];
		//printf("cmoney[%d]=%d\n",c-1,cmoney[c-1]);
		smoney[c]=smoney[c-1]+cmoney[c-1];
		//printf("circle starts at %d\n",visited[tn]);
		if(r<=visited[tn])
		{
			fprintf(fout,"Case #%d: %d\n", tt+1,smoney[r]);
		}
		else
		{
			int rq=(r-visited[tn])/(c-visited[tn]);
			int rr=(r-visited[tn])%(c-visited[tn]);
			int circle,base;
			base=smoney[visited[tn]];
			circle=smoney[c]-smoney[visited[tn]];
			/*
			printf("rq=%d\n",rq);
			printf("rr=%d\n",rr);
			printf("base=%d\n",base);
			printf("circle=%d\n",circle);
			*/
			fprintf(fout,"Case #%d: %d\n", tt+1,base+
					rq*circle+(smoney[visited[tn]+rr]-base));
		}
	}
	fclose(fin);
	fclose(fout);
}
