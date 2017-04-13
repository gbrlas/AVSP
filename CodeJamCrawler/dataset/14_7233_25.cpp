#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

double findCurrentAnswer(double elapsedTime,float cookiesPerSec,float X) {
	return elapsedTime + (double)X/cookiesPerSec;
}

int main() {
	int T;
	scanf("%d",&T);
	int testCase = 0;
	while(T--) {
		testCase++;
		float C,F,X;
		scanf("%f",&C);
		scanf("%f",&F);
		scanf("%f",&X);
		double prevAnswer = X/2.0;
		double elapsedTime = C/2.0;
		float cookiesPerSec = F+2.0;
		double currentAnswer = findCurrentAnswer(elapsedTime,cookiesPerSec,X);
		while(currentAnswer<=prevAnswer) {
			prevAnswer = currentAnswer;
			double additionalTime = C/cookiesPerSec;
			elapsedTime += additionalTime;
			cookiesPerSec += F;
			currentAnswer = findCurrentAnswer(elapsedTime,cookiesPerSec,X);
		}
		string colon = ": ";
		printf("Case #%d: %.7f\n",testCase,prevAnswer);
	}
	return 0;
}
