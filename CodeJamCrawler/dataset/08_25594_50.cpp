// traintime.cpp : définit le point d'entrée pour l'application console.
//

//#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Plan{
	int depHours;
	int depMin;
	int arrHours;
	int arrMin;
};

bool depComp(Plan *p1,Plan *p2){
	if(p1->depHours<p2->depHours)
		return true;
	if(p1->depHours==p2->depHours && p1->depMin<p2->depMin)
		return true;
	return false;
}

bool arrComp(Plan *p1,Plan *p2){
	if(p1->arrHours<p2->arrHours)
		return true;
	if(p1->arrHours==p2->arrHours && p1->arrMin<p2->arrMin)
		return true;
	return false;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int i,j,numCases,turnTime,numAtoB,numBtoA;
	string tmpString;
	ifstream ifs ( "input.txt" , ifstream::in );
	ofstream ofs ( "output.txt" , ofstream::out );
	ifs >> numCases;

	vector<Plan*> plansAB;
	vector<Plan*> plansBA;
	vector<Plan*> plansDepAB;
	vector<Plan*> plansArrAB;
	vector<Plan*> plansDepBA;
	vector<Plan*> plansArrBA;

	for(i=0;i<numCases;i++){
		int neededA =0,neededB=0;
		plansAB.clear();
		plansBA.clear();
		ifs >> turnTime;
		ifs >> numAtoB;
		ifs >> numBtoA;
		int trainsAtA = 0,trainsAtB=0;

		for(j=0;j<numAtoB;j++){
			Plan *p = new Plan();
			ifs >> tmpString;
			p->depHours = atoi(&tmpString[0]);
			p->depMin = atoi(&tmpString[3]);
			ifs >> tmpString;
			p->arrHours = atoi(&tmpString[0]);
			p->arrMin = atoi(&tmpString[3]) + turnTime;
			if(p->arrMin >= 60){
				p->arrMin-=60;
				p->arrHours++;
			}
			plansAB.push_back(p);
		}
		
		for(j=0;j<numBtoA;j++){
			Plan *p = new Plan();
			ifs >> tmpString;
			p->depHours = atoi(&tmpString[0]);
			p->depMin = atoi(&tmpString[3]);
			ifs >> tmpString;
			p->arrHours = atoi(&tmpString[0]);
			p->arrMin = atoi(&tmpString[3]) + turnTime;
			if(p->arrMin >= 60){
				p->arrMin-=60;
				p->arrHours++;
			}
			plansBA.push_back(p);
		}

		sort(plansAB.begin(),plansAB.end(),depComp);
		plansDepAB.assign(plansAB.begin(),plansAB.end());
		sort(plansAB.begin(),plansAB.end(),arrComp);
		plansArrAB.assign(plansAB.begin(),plansAB.end());
		sort(plansBA.begin(),plansBA.end(),depComp);
		plansDepBA.assign(plansBA.begin(),plansBA.end());
		sort(plansBA.begin(),plansBA.end(),arrComp);
		plansArrBA.assign(plansBA.begin(),plansBA.end());

		for(int hours = 0; hours<24;hours++){
			for(int min = 0;min<60;min++){
				if(!plansArrAB.empty()){
					while(plansArrAB[0]->arrHours == hours && plansArrAB[0]->arrMin == min){
						trainsAtB++;
						plansArrAB.erase(plansArrAB.begin());
						if(plansArrAB.empty())
							break;
					}
				}
				if(!plansArrBA.empty()){
					while(plansArrBA[0]->arrHours == hours && plansArrBA[0]->arrMin == min){
						trainsAtA++;
						plansArrBA.erase(plansArrBA.begin());
						if(plansArrBA.empty())
							break;
					}
				}
				if(!plansDepAB.empty()){
					while(plansDepAB[0]->depHours == hours && plansDepAB[0]->depMin == min){
						trainsAtA--;
						plansDepAB.erase(plansDepAB.begin());
						if(plansDepAB.empty())
							break;
					}
				}
				if(!plansDepBA.empty()){
					while(plansDepBA[0]->depHours == hours && plansDepBA[0]->depMin == min){
						trainsAtB--;
						plansDepBA.erase(plansDepBA.begin());
						if(plansDepBA.empty())
							break;
					}
				}
				if(trainsAtA < 0){
					neededA-= trainsAtA;
					trainsAtA = 0;
				}
				if(trainsAtB < 0){
					neededB-=trainsAtB;
					trainsAtB = 0;
				}
			}
		}
		ofs << "Case #" << i+1 << ": " << neededA << " " << neededB << endl;
	}

	ifs.close();
	ofs.close();
	return 0;
}

