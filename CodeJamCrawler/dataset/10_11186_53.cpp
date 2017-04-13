#pragma once
#include "ITest.h"

class FairWarning :  public ITest
{
public:
	FairWarning(void);
	~FairWarning(void);



	long long getMax(long long a,long long b)
	{
		long long r;
		if(b==0)
			return a;
		else 
		{
			r=a%b;
			return getMax(b,r);
		}
	}


	int run(){

		string name="C:\\B-small-attempt1.in";

		int t=0;

		FILE *fp=fopen(name.c_str(),"r");

		//ifstream inf;//(name.c_str(),ios::in);
		//inf.open(name.c_str(),ios::in);
		fscanf(fp,"%d",&t);
		//inf>>t;

		FILE *fpout=fopen("C:\\res.txt","w");

		for(int i=0;i<t;i++)
		{

			vector<long long > vec;
			int num;
			//inf>>num;
			fscanf(fp,"%d",&num);
			for(int j=0;j<num;j++)
			{
				unsigned __int64 tmp=0;
				char buff[32];
				fscanf(fp,"%s", buff);
				//inf >>tmp;
				sscanf(buff,"%I64u",&tmp);

				tmp=(unsigned __int64)_atoi64(buff);

				if (errno == ERANGE)
				{
					printf("Overflow condition occurred.\n");
				}

				int len=strlen(buff);
				//for(int k=0;k<len;k++)

				vec.push_back(tmp);
			}

			vector<long long > vecsbb;
			for(int j=0;j<num-1;j++)
				for(int k=j+1;k<num;k++)
				{
					if(vec[j]>vec[k])
						vecsbb.push_back(vec[j]-vec[k]);
					else
						vecsbb.push_back(vec[k]-vec[j]);
				}

				long long T=0;

				if(vecsbb.size()==1)
					T=vecsbb[0];
				else {
					for(int j=0;j<vecsbb.size()-1;j++)
						for(int k=j+1;k<vecsbb.size();k++)
						{
							long long tmp=getMax(vecsbb[j],vecsbb[k]);
							if(tmp>T)
								T=tmp;

						}

				}


               long long y=0;
				if(T==0)
				{
					y=0;		

				}else {
					for(int j=0;j<num;j++)
					{

						long long  a=vec[j]/T;

						long long c=vec[j]%T;
						if(c==0)
							continue;
						a++;
						long long b=a*T;
						long long yi=b-vec[j];
						if(yi>y)
							y=yi;			
					}
				}		
				fprintf(fpout,"Case #%d: %ld\n",i+1,y);

		}


		fclose(fp);
		fclose(fpout);



		return 0;
	}



};
