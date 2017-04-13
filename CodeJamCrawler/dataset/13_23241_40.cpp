#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
enum
{
	MAX_VALUE_LENGTH=102
};

int numberOfFairSquare(double a, double b);
bool checkFair(double n);
double checkSquare(double n);

void main()
{
	ifstream inStream;
	ofstream outFile("output.txt");
	int numTestCases;							

	inStream.open("C-small-attempt0.in");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed. \n";
		exit(1);
	}
	inStream>>numTestCases;						//number of test cases
	for(int t=1;t<=numTestCases;t++)
	{
		double A,B;
		inStream>>A>>B;
		outFile<<"Case #"<<t<<": "<<numberOfFairSquare(A,B)<<endl;
	}
	outFile.close();
	inStream.close();
}

int numberOfFairSquare(double a, double b)
{
	int count=0;
	for(double i=a;i<=b;i++)
	{
		if(checkFair(i) && checkSquare(i) && checkFair(checkSquare(i)))
		{
			count++;
		}
	}
	return count;
}

bool checkFair(double n)
{
	char str[MAX_VALUE_LENGTH];
	int i;
	for(i=0;n!=0;i++)
	{
		str[i]='0'+ int(n-(floor(n/10)*10));	//translation for characters
		n=floor(n/10);
	}
	if(i==1)									//character is only one						
	{
		return true;
	}
	if(i%2==1)									// character's count is odd Number
	{
		int left=i/2-1;
		int right=i/2+1;
		for(int j=0;j<int(i/2);j++)
		{
			if(str[left+j]!=str[right+j])
			{
				return false;
			}
		}
	}
	else										// character's count is  Number
	{
		int left=i/2-1;
		int right=i/2;
		for(int j=0;j<i/2;j++)
		{
			if(str[left+j]!=str[right+j])
			{
				return false;
			}
		}
	}
	return true;
}

double checkSquare(double n)
{
	if(floor(sqrt(n))==sqrt(n))
		return sqrt(n);
	return 0;
}