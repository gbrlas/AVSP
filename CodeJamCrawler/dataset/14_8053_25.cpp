#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

#define RoundOff(x, dig) (floor((x) * pow(10,dig) + 0.5) / pow(10,dig))

const double GAIN_COOKIE_PER_SECOND = 2.0;

struct FarmInfo
{
	int myFarmCnt;
	double costFarm;
	double farmProduct;
	double takeTime;
};

double getTakeTime(FarmInfo &fInfo, double upToCookies)
{		
	double time = 0.0;
	for(int i=0; i<fInfo.myFarmCnt; i++){
		time += fInfo.costFarm / (GAIN_COOKIE_PER_SECOND + (fInfo.farmProduct * i));
	}
	time += upToCookies / (GAIN_COOKIE_PER_SECOND + (fInfo.farmProduct * fInfo.myFarmCnt));
	
	//return floor(time*1000000+0.5)/1000000;
	//return floor(time * pow(10.0, 7.0)+0.5) / pow(10.0, 7.0);
	return time;
}

int main () 
{	
	ifstream readFile;
	readFile.open("B-small-attempt5.in");
	readFile >> fixed >> setprecision(8);
	
	ofstream writeFile("resultB5.txt");
	writeFile << fixed << setprecision(7);
	
	int totalTest;
	readFile >> totalTest;
	
	for(int caseNum=1; caseNum<=totalTest; caseNum++){
		writeFile << "Case #" << caseNum << ": ";
		
		double c, f, x;
		readFile >> c >> f >> x;
		
		int farmCnt = 0;
		FarmInfo farmInfo1;
		farmInfo1.myFarmCnt = farmCnt;
		farmInfo1.costFarm = c;
		farmInfo1.farmProduct = f;
		farmInfo1.takeTime = getTakeTime(farmInfo1, x);
		
		vector<FarmInfo> farms;
		farms.push_back(farmInfo1);
		
		while(true){
			
			FarmInfo tempInfo;
			tempInfo.myFarmCnt = ++farmCnt;
			tempInfo.costFarm = c;
			tempInfo.farmProduct = f;
			tempInfo.takeTime = getTakeTime(tempInfo, x);
			
			farms.push_back(tempInfo);
			
			if( farms[farmCnt-1].takeTime < farms[farmCnt].takeTime ){
				writeFile << farms[farmCnt-1].takeTime << endl;
				break;
			}
		}
	
	}
	
	readFile.close();
	writeFile.close();
	return 0;
}
