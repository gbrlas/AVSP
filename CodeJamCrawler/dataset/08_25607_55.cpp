#include <cmath>
#include <iostream>
#include <fstream>

#define PI 3.14159265

using namespace std;

double areaOfString(double x1, double x2, double R)
{
	double a1 = asin(x1/R);
	double a2 = asin(x2/R);
	
	double s2 = R*R*(sin(2*a2)/4+a2/2);
	double s1 = R*R*(sin(2*a1)/4+a1/2);
	
	return s2-s1;
}

//case 0 -> 15;
//case 1 -> 7;
//case 2 -> 3;
//case 3 -> 5;
//case 4 -> 1;
//case 5 -> 0;

int coverCase(double x, double y, double g, double R)
{
	bool LL, RL, LT, RT;
	LL = (x*x + y*y < R*R);
	RL = ((x+g)*(x+g) + y*y < R*R);
	LT = (x*x + (y+g)*(y+g) < R*R);
	RT = ((x+g)*(x+g) + (y+g)*(y+g) < R*R);
	
	return LL + RL*2 + LT*4 + RT*8;
	 
}

double areaSec(double x, double y, double g, double R, int scase)
{
	
	if(scase == 15)
		return (g*g);
		
	if(scase == 7)
	{
		double x1 = sqrt(R*R - (y+g)*(y+g));
		return g*(x1-x) + areaOfString(x1, x+g, R) - (x+g-x1)*y;
	}
	
	if(scase == 3)
	{
		return areaOfString(x, x+g, R) - g*y;
	}
	
	if(scase == 5)
	{
		double x1 = sqrt(R*R - (y+g)*(y+g));
		double x2 = sqrt(R*R - y*y);
		
		return g*(x1-x) + areaOfString(x1, x2, R) - (x2-x1)*y;
	}
	
	if(scase == 1)
	{
		double x1 = sqrt(R*R - y*y);
		return areaOfString(x, x1, R) - (x1-x)*y;
	}
	
	if(scase == 0)
		return 0;

	return 0;
}

// g > 0
double areaSpace(double R, double r, double g, double t, int K)
{
	// quater K-1 space
	double x = r;
	double total = 0;
	
	for(int kxi = 1; kxi <=K; kxi++)
	{
		//each column
		int kyi = 1;
		double y = r;
		for(;kyi<=K; kyi++)
		{
			int scase = coverCase(x, y, g, R);
			if(scase == 0) // outside
				break;
			
			total+=areaSec(x, y, g, R, scase);
			
			y+=g+2*r;
		}
		
		x+=g+2*r;
	}
	
	total = total * 4;
	return total;
}

int main(int argc, char * argv[])
{
	int testN, testi;
	fstream input(argv[1]);
	
	input >> testN;
	for(testi = 0; testi<testN; testi++)
	{	
		//for each case
		double Fly, R, T, sr, G;
		input >> Fly >> R >> T >> sr >> G;
		
		//number of string
		int K;
		double x = 0;
		if(sr > R-T)
			K = 0;
		else
		{
			K = 1;
			for(x= sr+G; x+2*sr <= R-T; x+= 2*sr+G)
				K++;
		}
		
		//ajust
		T+=Fly;
		sr+=Fly;
		G-=2*Fly;
		
		double pro = 0;
		if(G <= 0)
			pro = 1;
		else
		{
			double space;
			if(K > 0)
				space= areaSpace(R-T, sr, G, T, K);
			else
				space = PI*(R-T)*(R-T);	//no string;

			pro = 1 -  space/(PI*R*R);
		}
			
			
		printf("Case #%d: %f\n", testi+1, pro);
	
	}/*test N*/
	
	return 0;
}