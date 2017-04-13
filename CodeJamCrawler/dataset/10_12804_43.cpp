#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main () {

	int iCasesT = 0;
	int iSnapperN = 0;
	int iSnapTimesK = 0;

	fstream fileInput ("A-small-attempt0.in", fstream::in);
	fstream fileOutput ("A-small-attempt0.out", fstream::out);

	fileInput >> iCasesT;
	for (int i=0; i<iCasesT; i++)
	{
		fileInput >> iSnapperN >> iSnapTimesK;

		int iOnPow = pow(2.0f, iSnapperN);
		int iMod = iSnapTimesK % iOnPow;
		if (iMod == iOnPow -1)
		{
			fileOutput << "Case #" << i+1 << ": " << "ON" << endl;
		}
		else
		{
			fileOutput << "Case #" << i+1 << ": " << "OFF" << endl;
		}
	}

	fileInput.close();
	fileOutput.close();

	return 0;
}