#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{

	int t;
	
	double currentCookies;
	double cookiesRequired;
	double farmCost;
	double farmRate;

	double currentTime;
	double currentRate;

	double answer;

	cin >> t;

	for(int ct=1;ct<=t;ct++)
	{

		cin >> farmCost;
		cin >> farmRate;
		cin >> cookiesRequired;

		currentTime = 0;

		if(farmCost >= cookiesRequired)
		{
			answer = (cookiesRequired/2);
		}


		else
		{
			currentRate = 2;
			while(1)
			{
				currentCookies = 0;

				currentTime += (farmCost/currentRate);
				currentCookies = farmCost;

				if(((cookiesRequired-currentCookies)/currentRate) < (cookiesRequired/(currentRate + farmRate)))
				{
					answer = (currentTime + ((cookiesRequired-currentCookies)/currentRate));
					break;
				}

				currentRate += farmRate;

			}
		}

			
		cout<<"Case #"<<ct<<": "<<std::setprecision(7)<<std::fixed<<answer<<endl;

	}
}