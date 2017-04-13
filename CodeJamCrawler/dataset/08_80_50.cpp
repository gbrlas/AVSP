#include<iostream>
#include<fstream>
#include<cstring>
#include<map>

using namespace std;

int main(){
	int noCases = 0;
	cin >> noCases;
//	cout << "noCases: " << noCases << endl; 
	ofstream fout("output");

	for(int i=0; i<noCases; i++ ){
		int noTrainsAB=0;
		int noTrainsBA=0;

		int turnAround =0;
		cin >> turnAround;
		cout << "turnAround: " << turnAround << endl;
	
		int noAB, noBA;	
		cin >> noAB >> noBA;
		cout << "noAB: " << noAB << " noBA: " << noBA <<endl;
		int noNet = noAB + noBA;

		int timeTable[noAB+noBA][4];
		for(int j=0; j<noAB; j++){
			int hour, min;
			char colon;

			cin >> hour >> colon >> min;
			cout << hour << " " << colon << " " << min << endl;
			timeTable[j][0] = hour*60 + min;
                        cin >> hour >> colon >> min;
                        cout << hour << " " << colon << " " << min << endl;
			timeTable[j][1] = hour*60 + min+turnAround;
			timeTable[j][2] = 0;
			timeTable[j][3] = 0;	
			}	
		for(int j=noAB; j<noNet; j++){
			int hour,min;
			char colon;
			cin >> hour >> colon >> min;
                        cout << hour << " " << colon << " " << min << endl;
			timeTable[j][0] = hour*60 + min;
			cin >> hour >> colon >> min;
                        cout << hour << " " << colon << " " << min << endl;
			timeTable[j][1] = hour*60 + min+turnAround;
			timeTable[j][2] = 1;
                	timeTable[j][3] = 0;
			}

		cout << "Input Sanitized" << endl;
		int temp[1][4];
		for(int k1=0; k1<noNet; k1++){
			for(int k2=k1+1; k2<noNet; k2++){
				if(timeTable[k2][0] < timeTable[k1][0]){
					for(int k3=0;k3<4;k3++)
						temp[0][k3] = timeTable[k2][k3];
                                        for(int k3=0;k3<4;k3++)
                                                timeTable[k2][k3] = timeTable[k1][k3];
                                        for(int k3=0;k3<4;k3++)
                                                timeTable[k1][k3] = temp[0][k3];

					}
				}
			}
		cout << "Array Sorted" << endl;		

		int currJourney = 0;
		bool done = false;
		while(!done){
			done = true;
		
			for(int j=0; j<noNet; j++){
				cout << j << " " << timeTable[j][3] << endl;
				if(!timeTable[j][3]){
					currJourney = j;
					timeTable[currJourney][3] = 1;
					if(timeTable[currJourney][2] == 0) ++noTrainsAB;
					else ++noTrainsBA;
					break;
					} 
				}
			
			for(int j=0; j<noNet; j++){
				if(timeTable[j][3] != 1){
					if(timeTable[currJourney][1] <= timeTable[j][0] && 
					   timeTable[currJourney][2] != timeTable[j][2]){
						currJourney = j;
						timeTable[j][3] = 1;
						}
					}
				}

			for(int j=0; j<noNet; j++)
				done &= timeTable[j][3];	

				cout << "done value: " << done << endl;
			}

		fout << "Case #" << i+1 << ": " << noTrainsAB << " " << noTrainsBA << endl;
		}

	return 0;
	}
