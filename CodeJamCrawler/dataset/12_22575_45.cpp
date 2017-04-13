#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
string NumberToString ( T Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}

unsigned StringToNumber ( const string &Text )//Text not by const reference so that the function can be used with a 
{                               //character array as argument
	stringstream ss(Text);
	unsigned result;
	return ss >> result ? result : 0;
}

string shift_digit ( string number )
{
	string temp1 = number;
	char temp2 = *temp1.rbegin();
	
	temp1.erase(temp1.end()-1);

	temp1 = temp2 + temp1;
	
	return temp1;
}

int main()
{
	ifstream input;
	ofstream output;

	string inputname = "input.txt";
	string outputname = "output.txt";

	input.open(inputname.c_str());
	output.open(outputname.c_str());

	unsigned T;
	input >> T;

	for (unsigned t = 0; t < T; t++)
	{
		unsigned A, B;
		unsigned temp;
		input >> A >> B;
		unsigned count = 0;

		for (unsigned n = A; n < B; n++)
		{
			string A_str = NumberToString(n);
			unsigned shifted;

			for (unsigned b = 0; b < A_str.length(); b++)
			{
				A_str = shift_digit(A_str);
				shifted = StringToNumber(A_str);

				if (shifted > n && shifted <= B)
				{
					count++;
				}
			}
		}

		output << "Case #" << t+1 << ": " <<  count << endl;
	}


	return 0;
}