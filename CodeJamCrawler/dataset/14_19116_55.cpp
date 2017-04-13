// GCJ_QC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string> 
#include<iostream> 
#include<fstream> 
#include<sstream> 
#include<vector>
#include<list>
#include<iomanip>
#include<algorithm>
typedef unsigned int uint;
using namespace std;
class MS;
uint play_WAR(vector<double> A, vector<double> B);

int _tmain(int argc, _TCHAR* argv[])
{

	uint T;
//	uint R,C,M;

	ifstream infile("D.in");
	ofstream OF("outputD.txt");
	vector<double> Naomi,Ken;
	uint N;
	infile>>T;
	double buf;
	for(uint icase=0;icase<T;icase++){
		Naomi.resize(0);
		Ken.resize(0);
		infile>>N;
		for(uint i=0;i<N;i++){
			infile>>buf;
			Naomi.push_back(buf);
		}
		for(uint i=0;i<N;i++){
			infile>>buf;
			Ken.push_back(buf);
		}
		sort(Naomi.begin(),Naomi.end());
		sort(Ken.begin(),Ken.end());
		uint Nwins=play_WAR(Naomi,Ken);
		uint Kwins=play_WAR(Ken,Naomi);



		OF<<"Case #"<<icase+1<<": "<<N-Kwins<<" "<<Nwins<<endl;		
	}

	infile.close();
	OF.close();

	return 0;
}

uint play_WAR(vector<double> A, vector<double> B){ //A,B sorted, player B plays optimally, return player A wins
	if(A.size()!=B.size()) {cerr<<"not equal"<<endl; throw;}
	uint Awin=0;
	while(A.size()){
		for(uint ib=0;ib<B.size();ib++){
			if(B[ib]>A[0]){
				B.erase(B.begin()+ib);
				A.erase(A.begin());
				break;
			}
			if(ib==B.size()-1){
				B.erase(B.begin());
				A.erase(A.begin());
				Awin++;
			}
		}
	}
	return Awin;
}



