// GCJ2-Cookie.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

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

		int ans1 = atoi(data.c_str());
		int arrange1[4][4];
		
		for (int j=0; j<4; j++)
		{
			getline(infile, data);

			size_t col1End = data.find_first_of(' ');
			int e1 = atoi((data.substr(0, col1End)).c_str());

			size_t col2End = data.find_first_of(' ', col1End + 1);
			int e2 = atoi((data.substr(col1End + 1, col2End)).c_str());

			size_t col3End = data.find_first_of(' ', col2End + 1);
			int e3 = atoi((data.substr(col2End + 1, col3End)).c_str());

			size_t col4End = data.find_first_of(' ', col3End + 1);
			int e4 = atoi((data.substr(col3End + 1, col4End)).c_str());

			//cout << e1 << e2 << e3 << e4 << endl;
			arrange1[j][0] = e1;
			arrange1[j][1] = e2;
			arrange1[j][2] = e3;
			arrange1[j][3] = e4;
		}
		
		getline(infile, data);

		int ans2 = atoi(data.c_str());
		int arrange2[4][4];
		for (int j=0; j<4; j++)
		{
			getline(infile, data);

			size_t col1End = data.find_first_of(' ');
			int e1 = atoi((data.substr(0, col1End)).c_str());

			size_t col2End = data.find_first_of(' ', col1End + 1);
			int e2 = atoi((data.substr(col1End + 1, col2End)).c_str());

			size_t col3End = data.find_first_of(' ', col2End + 1);
			int e3 = atoi((data.substr(col2End + 1, col3End)).c_str());

			size_t col4End = data.find_first_of(' ', col3End + 1);
			int e4 = atoi((data.substr(col3End + 1, col4End)).c_str());

			//cout << e1 << e2 << e3 << e4 << endl;
			arrange2[j][0] = e1;
			arrange2[j][1] = e2;
			arrange2[j][2] = e3;
			arrange2[j][3] = e4;
		}

		int numberOfMatches = 0;
		int answer = 0;
		for (int j=0; j <4; j++)
		{
			for (int k=0; k<4; k++)
			{
				if (arrange1[ans1-1][j] == arrange2[ans2-1][k])
				{
					numberOfMatches++;
					answer = arrange1[ans1-1][j];
				}
			}
		}

		outfile << "Case #" << i + 1 << ": " ;
		if (numberOfMatches == 0)
		{
			outfile << "Volunteer cheated!" << endl;
		}
		else if (numberOfMatches > 1)
		{
			outfile << "Bad magician!" << endl;
		}
		else
		{
			outfile << answer << endl;
		}
	}

	infile.close();
	outfile.close();
	return 1;
}

