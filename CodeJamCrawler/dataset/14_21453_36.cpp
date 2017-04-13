/*
 * main.cpp
 *
 *  Created on: 12-04-2014
 *      Author: piotrek
 */

#include <iostream>
#include <math.h>
#include <iomanip>

class CookieProblem
{
	double FarmCost;
    double FarmIncome;
    double TotalCookies;

public:
    void Start()
    {
    	int problemCount=0;
    	std::cin>>problemCount;
    	for(int i=0; i<problemCount; i++)
    	{
    		ReadInput();
    		double ans=Calculate(INFINITY, 2, 0);
    		std::cout<<std::setprecision(7)<<"Case #"<<i+1<<": "<<ans<<std::endl;
    	}
    }

    void ReadInput()
    {
    	std::cin>>FarmCost;
    	std::cin>>FarmIncome;
    	std::cin>>TotalCookies;
    }

    double Calculate(double BestTime, double currentGrow, double currentTime)
    {
    	double currentBest=TotalCookies/currentGrow+currentTime;
    	if(BestTime<currentBest)
    		return BestTime;
    	else
    	{
    		return Calculate(currentBest, currentGrow+FarmIncome, currentTime+FarmCost/currentGrow);
    	}
    }
};

int main(int argc, char **argv)
{
	CookieProblem Cp;
	Cp.Start();
	return 0;
}
