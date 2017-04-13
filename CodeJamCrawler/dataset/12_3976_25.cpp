// CodeJam2012.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int digits(int num)
{
	int res=0;
	int tempNum=num;
	if(tempNum<10)return 1;
	else
	{
		res =1;
		while(tempNum/10 >=1)
		{
			tempNum=tempNum/10;
			res++;
		}
		return res;
	}
}
int slide(int num, int slideDigit)
{
	int numOfDigit = digits(num);
	int left = num/(pow(10.0f,slideDigit));
	int right = (num % (int)pow(10.0f,slideDigit)) ;
	int temp = left + (right* pow(10.0f,numOfDigit-slideDigit));

	return temp;
}
int countRecycledNumber(int A, int B)
{
	int count=0;
	int digit = digits(A);
	int slidenum;
	//outputFile << "process : " << A << " to " << B << "\n";
	//outputFile << "digits : " << digit << "\n";
	for(int i=A;i<=B;i++)
	{
		//outputFile << "check " << i<< "\n";
		for(int k=1;k<digit;k++)
		{
			slidenum = slide(i,k);
			//outputFile << "slide " << k <<": " << slidenum<< "\n";
			if(slidenum <=B && slidenum >=A && slidenum != i)
			{
					count++;
					//outputFile << "found \n";
			}
			else
			{
				//outputFile << "not found\n";
			}
		}
	}
	//outputFile << "1 9 : " << count << "\n";
	return count/2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ofstream outputFile;
	ifstream inputFile;
	int numberOfCase;

	inputFile.open("C-small-attempt0.in");
	outputFile.open("debug02.out");

	inputFile >> numberOfCase;

	int A,B;
	for(int i=0;i<numberOfCase;i++)
	{
		inputFile >> A;
		inputFile >> B;
		outputFile << "Case #"<< i+1 << ": " << countRecycledNumber(A,B);
		if(i<numberOfCase-1) outputFile << "\n";
	}
	inputFile.close();
	outputFile.close();

	return 0;
}

