#pragma once
#pragma once
#include "ITest.h"


class Snapper: public ITest
{
public:
	Snapper(void);
	~Snapper(void);


	int run(){

		string name="C:\\A-small-attempt3.in";

		int t=0;

		FILE *fp=fopen(name.c_str(),"r");
		fscanf(fp,"%u",&t);
		FILE *fpout=fopen("C:\\res.txt","w");

		for(int i=0;i<t;i++)
		{

			unsigned int n,k;
			fscanf(fp,"%d %d",&n,&k);

			

			bool ison=true;
			for(int j=0;j<n;j++)
			{
			    if( !(k & (1<<j)))
				{
					ison=false;
					break;
				}
			}
			if(ison)
				fprintf(fpout,"Case #%d: ON\n",i+1);
			else
				fprintf(fpout,"Case #%d: OFF\n",i+1);
			
		}

		fclose(fp);
		fclose(fpout);

		return 0;

	}

};
