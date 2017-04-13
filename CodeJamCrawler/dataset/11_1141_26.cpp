#include "libfns.h"

struct walkway
{
	double length;
	double speed;
};

bool ltWalkway(walkway w1, walkway w2)
{
	return w1.speed<w2.speed;
}

int main(int argc, char* argv[])
{
	FILE* inF, *outF;
	getFiles(argc,argv,inF,outF);
	tokenizer t(inF);
	t.setSEPS(" \t\n");

	int cases = atoi(t.getToken());

	for(int i=1; i<=cases;++i)
	{
		double totalTime = 0.0;
		std::deque<walkway> walkways;
		int X = atoi(t.getToken());
		double S = atoi(t.getToken());
		double R = atoi(t.getToken());
		double T = atoi(t.getToken());
		int N = atoi(t.getToken());
		int B[100];
		int E[100];
		double W[100];
		double RegularDistance = X;
		for(int n = 0; n < N; ++n)
		{
			B[i] = atoi(t.getToken());
			E[i] = atoi(t.getToken());
			W[i] = atoi(t.getToken());
			walkway x;
			x.length = E[i] - B[i];
			x.speed = W[i];

			walkways.push_back(x);
			RegularDistance -= (E[i] - B[i]);
		}
		walkway stopped;
		stopped.length = RegularDistance;
		stopped.speed = 0;
		walkways.push_back(stopped);
		std::sort(walkways.begin(),walkways.end(),ltWalkway);

		std::deque<walkway>::iterator itr = walkways.begin();
		while(itr!=walkways.end())
		{
			//how far can we run at this speed?
			double runDist = (itr->speed + R)*T;
			double runTime = 0.0;
			if(runDist >= itr->length)
			{
				runTime = itr->length / (itr->speed + R);
			}
			else
			{
				runTime = runDist / (itr->speed + R);
				totalTime += (itr->length - runDist) / (itr->speed + S);
			}
			totalTime += runTime;
			T -= runTime;
			itr++;
		}

		fprintf(outF,"Case #%d: %f\n",i,totalTime);
	}
	fclose(outF);
	fclose(inF);
	return 0;
}
