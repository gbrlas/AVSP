#include "libfns.h"

typedef fraction<__int64> frac64;
typedef Matrix<frac64> Matrix64;

int main(int argc, char* argv[])
{
	FILE* inF, *outF;
	getFiles(argc,argv,inF,outF);
	tokenizer t(inF);
	t.setSEPS(" \t\n");

	int cases = atoi(t.getToken());

	for(int i=1; i<=cases;++i)
	{
		int N = atoi(t.getToken()); //numteams

		char *season = new char[N*N];
		double *wins = new double[N];
		double *loss = new double[N];
		double *wp   = new double[N];
		double *owp  = new double[N];
		double *oowp = new double[N];

		
		for(int n=0; n<N; ++n)
		{
			loss[n]=0.0;
			wins[n] = 0.0;
			char* record = t.getToken();
			for(int g=0; g<N; ++g)
			{
				season[n*N+g] = record[g];
				if(record[g] == '1')
				{
					wins[n]+=1.0;
				}
				else if(record[g] == '0')
				{
					loss[n]+=1.0;
				}
			}
			wp[n] = wins[n]/(wins[n] + loss[n]);
		}

		for(int n=0; n<N; ++n)
		{
			double numOpps=0.0;
			double totalOWP = 0.0;
			for(int opp=0; opp<N; ++opp)
			{
				char result=season[n*N+opp];
				if('1' == result)
				{
					totalOWP+= (wins[opp])/(wins[opp]+loss[opp]-1);
					numOpps+=1.0;
				}
				else if('0' == result)
				{
					totalOWP+= (wins[opp]-1)/(wins[opp]+loss[opp]-1);
					numOpps+=1.0;
				}
			}
			owp[n] = totalOWP/numOpps;
		}

		for(int n=0; n<N; ++n)
		{
			double numOpps=0.0;
			double totalOOWP = 0.0;
			for(int opp=0; opp<N; ++opp)
			{
				char result=season[n*N+opp];
				if('.' != result)
				{
					totalOOWP+= owp[opp];
					numOpps+=1.0;
				}
			}
			oowp[n] = totalOOWP/numOpps;
		}

		fprintf(outF,"Case #%d:\n",i);
		for(int n=0; n<N; ++n)
		{
			fprintf(outF,"%f\n",0.25*wp[n] + 0.5*owp[n] + 0.25*oowp[n]);
		}


		delete[] season;
		delete[] wp;
		delete[] wins;
		delete[] loss;
		delete[] owp;
		delete[] oowp;
	}
	fclose(outF);
	fclose(inF);
	return 0;
}
