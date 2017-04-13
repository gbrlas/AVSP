// GCJ_QB.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<string> 
#include<iostream> 
#include<fstream> 
#include<sstream> 
#include<vector>
#include<iomanip>

typedef unsigned int uint;
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	uint T;
	double C,F,X;

	ifstream infile("dataB.in");
	ofstream OF("outputB.txt");

	infile>>T;

	for(uint icase=0;icase<T;icase++){
		infile>>C>>F>>X;
		double rate=2.0;
		double time=0.0;

		while(true){

			double time_to_new_farm=C/rate;
			double additional_time_to_win=X/rate;
			double time_with_new_farm=X/(rate+F);

			if(additional_time_to_win>(time_to_new_farm+time_with_new_farm)){
				rate+=F;
				time+=time_to_new_farm;
			}else{
				time+=additional_time_to_win;
				OF<<"Case #"<<icase+1<<": "<<setprecision(16)<<time<<endl;
				break;
			}
		}
	}

	infile.close();
	OF.close();

	return 0;
}

