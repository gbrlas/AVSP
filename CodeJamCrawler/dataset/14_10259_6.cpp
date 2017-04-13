// googlejam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string str;
	int n;
	fstream dataFile("d:/test1.txt", ios::in);
	fstream outFile("d://out1.txt", ios::out);

	dataFile >> n;
	
	for (int caseID = 1; caseID <= n; caseID++) {

		outFile << "Case #"<< caseID <<": ";

		int numSet[17];
		for (int i=0; i<=16; i++) numSet[i]=0;

		int k;
		string tmpStr;
		int ans = 0;

		for (int times = 0; times < 2; times++) {
		
			dataFile >> k;
	
			for (int i=0; i < k; i++) getline(dataFile, tmpStr);
			int card;
			for (int i=0; i < 4; i++) {
				dataFile >> card;
				numSet[card]++;

			}
			for (int i=0; i <= 4-k; i++) getline(dataFile, tmpStr);
		}		
	
		int i;
		for (i=1; i <= 16; i++)
			if (numSet[i] == 2) 
				if (ans == 0) 	ans = i;
				else {
					outFile<<"Bad magician!";
					break;
				}
		if (ans == 0) outFile<<"Volunteer cheated!";
		else if (i > 16) outFile << ans;

		outFile << endl;
	}

	outFile.close();

	//cin.ignore(1);
	return 0;
}

