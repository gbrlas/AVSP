#pragma once
#include "ITest.h"

class ThemePark: public ITest
{
public:
	ThemePark(void);
	~ThemePark(void);


	int run()
	{

		string name="C:\\C-small-attempt0.in";

		int t=0;

		FILE *fp=fopen(name.c_str(),"r");
		fscanf(fp,"%u",&t);
		FILE *fpout=fopen("C:\\res.txt","w");

		for(int i=0;i<t;i++)
		{
          long long R=0,k=0,N=0;

		  fscanf(fp,"%ld %ld %ld",&R,&k,&N);

		  vector<long long > vec;

		  for(int j=0;j<N;j++)
		  {
			  long long tmp=0;
		      fscanf(fp,"%ld ",&tmp);
			  vec.push_back(tmp);
		  }
          
		  long long sum=0;
		  long long nowg=0;
		  
		 
		  for(int a=0;a<R;a++){
               long long nowp=0;
			   long long group=0;
			   while(true){
				  nowp+=vec[nowg];
                  group++;
				  if(nowp<=k&&group<=N)
				  { 
					  nowg++;					 
				      nowg=nowg%N;
				  }
				  else
				  {
					  nowp-=vec[nowg];
					  sum+=nowp;
					  break;
				  }
			   }			  
		  }
		  fprintf(fpout,"Case #%d: %ld\n",i+1,sum);			
		}


		fclose(fp);
		fclose(fpout);
		return 0;

	}

	
};
