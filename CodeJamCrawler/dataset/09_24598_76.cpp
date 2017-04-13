
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

char *msg = "welcome to code jam";

unsigned int Calculate (const char *input, int i, int j, unsigned int len)
{
	if (j == strlen (msg)) {		
		return 1;
	}	

	unsigned int sum = 0;
	for (unsigned int k = i; k < len; k ++)
	{
		if (input[k] == msg[j])
		{
			sum += Calculate (input, k + 1, j + 1, len);
		}		
	}
	return sum;
}

int main (int argc, char *argv[])
{
	fstream infile ("C-small-attempt1.in",ios::in);
	fstream outfile ("Output.txt",ios::out);

	std::string line;
	int count = 0;
	unsigned int result = 0;
	char *input = "welcome to codejam";

	infile >> count;
	getline (infile, line);

	for (int i = 0; i < count; i++)
	{		
		getline (infile, line);
		result = Calculate(line.c_str(), 0, 0, line.length());
		outfile << "Case #" << i + 1 << ": " << (result / 1000) % 10 << 
								(result / 100) % 10 << (result / 10) % 10 << result % 10 << endl;
	}	

	outfile.close();
	infile.close();
}