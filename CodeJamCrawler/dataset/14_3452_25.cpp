#include "stdafx.h"

using namespace std;


double C,F,X;
double eps = 0.0001;
std::fstream instream;
std::fstream outstream;

double process(){
	
	instream >> C >> F >> X;
	int n = 0;

	double current_slope = 2.0;
	double spent_time_to_achieve_current_slope = 0;
	double min_time = X / current_slope;

	while (spent_time_to_achieve_current_slope < min_time){
		min_time = min(min_time, spent_time_to_achieve_current_slope + (X / current_slope));
		spent_time_to_achieve_current_slope += (C / current_slope);
		current_slope += F;
	}
	return min_time;
	
}

int _tmain(int argc, _TCHAR* argv[])
{	

	instream.open("B-small-attempt0.in", std::fstream::in);

	outstream.open("saida.txt", std::fstream::out);

	int T;
	//instream.fixed =
	instream.precision(10);
	outstream.precision(10);
	instream >> T;

	for (int teste_case = 1; teste_case <= T; teste_case++) 
		outstream << "Case #" << teste_case << ": " << process() << endl;
	
	instream.close();
	outstream.close();
	return 0;
}

