#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>

using namespace std;

int main()
{
	double bestSoFar,cstart=0, c,f,x,houseTime,accum = 2,htmp,wtmp;
	int cases;
	string ifile = "B-large.in",ofile= "output.txt";
	stringstream ss;
	ifstream input;
	input.open(ifile);
	input>>cases;
	ss<<std::fixed;
	for( int round = 1 ; round<=cases ; ++round )
	{
		cstart=0;
		accum=2;
		input>>c>>f>>x;
		bestSoFar = x/accum;
		while (true)
		{
			houseTime = c/accum;
			htmp = cstart+houseTime+(x/(accum+f));
			wtmp = (x/accum)+cstart;
			if (wtmp<htmp)
			{
				if(wtmp<bestSoFar)bestSoFar=wtmp;
				break;
			}
			if(htmp>bestSoFar)break;
			accum+=f;
			cstart+=houseTime;
			bestSoFar = htmp;
		}
		ss<<"Case #"<<round<<": "<<setprecision(7)<<bestSoFar<<"\n";
	}
	input.close();
	ofstream output;
	output.open(ofile);
	output<<ss.rdbuf();
	output.flush();
	output.close();
	return 0;
}