// GCJ2-Cookie.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;

	infile.open("input.txt");
	if (!infile)
	{
		cout << "File could not be opened";
		return 1;
	}

	outfile.open("output.txt");
	if (!outfile)
	{
		cout << "File could not be opened";
		return 1;
	}

	string data;
	getline(infile, data);

	int numberOfTestCase = atoi(data.c_str());
	cout << "Debug: total testcase : " << numberOfTestCase << endl;
	for (int i = 0; i < numberOfTestCase; i++)
	{
		getline(infile, data);

		size_t farmCostEnd = data.find_first_of(' ');
		double farmCost = atof((data.substr(0, farmCostEnd)).c_str());
		
		size_t rateEnd = data.find_first_of(' ', farmCostEnd + 1);
		double rateIncrement = atof((data.substr(farmCostEnd + 1, rateEnd)).c_str());

		double targetCookieCount = atof((data.substr(rateEnd + 1)).c_str());
		
		double initialRate = 2.0f;
		double previousBestTime = targetCookieCount / initialRate;
		double currentRate = initialRate;

		double timeToBuyFarm = 0.0f;
		while (1)
		{
			timeToBuyFarm += farmCost / currentRate;
			currentRate += rateIncrement;

  			double totalTimeTaken = timeToBuyFarm + (targetCookieCount / currentRate);
			if (totalTimeTaken < previousBestTime)
			{
				previousBestTime = totalTimeTaken;
			}
			else
			{
				break;
			}
		}

		outfile << "Case #" << i + 1 << ": " ;
		outfile << std::setprecision(7) << previousBestTime << endl;
	}

	infile.close();
	outfile.close();
	return 1;
}

