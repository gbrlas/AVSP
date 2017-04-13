// gcj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
//#include "conio.c"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//ifstream input_data;
	//input_data.open("a.in");

	int T;
	fflush(stdin);
	cin >> T;
	//cout << T;
	char text[] = "yhesocvxduiglbkrztnwjpfmaq";
//	text[26]= '\0';

	for (int i=0;i<T;i++)
	{
		string G;
		string H;
		fflush(stdin);
		getline(cin, G);
		//cout << G << endl;
		//fflush(stdin);
		//getline(cin, H);
		//cout << H << endl;

		cout <<"Case #" << i+1 << ": ";
		
			for(int j=0;j<G.size();j++)
		{
			char aa;
			////char aa = getc();
			//cin >> aa;
			//cout << aa;
			aa = G[j];
			if(aa == ' ')
				cout << ' ';
			else
				cout << text[aa -'a'];

		}

		cout << endl;
	}

//	cout << text << endl;
	return 0;
}

