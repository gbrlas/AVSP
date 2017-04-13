#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ofstream fout ("b.out");
ifstream fin ("b.in");
int T;
int levelRecs[1000][2];
bool completed[1000][3];
int nlevels;

int main () {
	fin >> T;
	for(int j=1; j<= T; j++){
		fin >> nlevels;
		for(int i=0;i<nlevels;i++){
			fin >> levelRecs[i][0] >> levelRecs[i][1];
			completed[i][1] = false;
			completed[i][2] = false;
		}
		int stars = 0;
		bool found = true;
		int count = 0;
		while(stars < nlevels*2){
			count++;
			int bestOne, bestOneVal = -1;
			found = false;
			for(int i=0;i<nlevels;i++){
				if(stars >= levelRecs[i][1] && completed[i][2] == false){
					bestOne = i;
					found = true;
					break;
				}
				if(stars >= levelRecs[i][0] && completed[i][1] == false && completed[i][2] == false){
					found = true;
					if(bestOneVal < levelRecs[i][1]){
						bestOneVal = levelRecs[i][1];
						bestOne = i;
					}
				}
			}
			if(!found)
				break;
			if(stars >= levelRecs[bestOne][1]){
				stars += 2;
				if(completed[bestOne][1])
					stars--;
				completed[bestOne][1] = true;
				completed[bestOne][2] = true;
			}
			else if(stars >= levelRecs[bestOne][0]){
				stars += 1;
				completed[bestOne][1] = true;
			}
		}
		if(stars == nlevels*2)
			fout << "Case #" << j << ": " << count << endl;
		else
			fout << "Case #" << j << ": " << "Too Bad" << endl;
	}
}