// hila4321 gmail.com

#include <iostream>
#include <fstream>

using namespace std;

//unsigned long = 1073741824 > max(k) = 10^8

void main()
{
	// GENERATE EXP. OF 2.
	unsigned long exp[31];
	exp[0] = 1;
	exp[1] = 2;
	
	for (int i = 2; i<31; i++)
		exp[i] = 2*exp[i-1];

	// the i-device is lighten up every 2^i steps, starting from -1.
	// so if (k== n*(2^i) -1) for some integer n, then the light is on.

	int T,N;
	unsigned long K;

	ifstream input("A-large.in");
	ofstream output("A-large.out"); 

	input >> T;
	for (int i=1; i<=T; i++)
	{
		input >> N;
		input >> K;

		output << "Case #" << i << ": ";
		if (((K+1)%(exp[N]))==0)
			output << "ON" << endl;
		else output << "OFF" << endl;
	}
	input.close();
	output.close();	
}