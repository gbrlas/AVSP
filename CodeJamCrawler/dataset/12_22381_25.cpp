#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int getIntFromFile(ifstream &); //Function to get a line from a file and convert it to an int.
string intToString(int);
int stringToInt(string);
int numberOfNumbers(int, int);

int main()
{
	ifstream fin;
	fin.open("input.in");

	ofstream fout;
	fout.open("output.txt");

	int testCases = getIntFromFile(fin); //Get the number of test cases, and fin is ready ready at the next line.
	
	for (int i = 0; i < testCases; i++)
	{
		string result = "";
		string input;
		getline(fin, input);

		istringstream pricesStream(input);
		int lower;
		int upper;
		pricesStream >> lower;
		pricesStream >> upper;

		result = intToString(numberOfNumbers(lower,upper));

		fout << "Case #" << i + 1 << ": " << result << endl;
	}

	fin.close();
	fout.close();
	return 0;
}

int getIntFromFile(ifstream & fin)
{
	int result;
	string s;
	getline(fin,s);
	istringstream convert(s);
	convert >> result;
	return result;
}

string intToString(int x)
{
	string result;
	char temp[256];
	_itoa_s(x,temp,255,10);
	result=temp;
	return result;
}

int stringToInt(string s)
{
	return atoi(s.c_str());
}

int numberOfNumbers(int lower, int upper)
{
	int result = 0;
	for (int currentLow = lower; currentLow <= upper; currentLow++)
	{
		string recycled = intToString(currentLow);
		int length = recycled.length();
		for (int j = 0; j < length - 1; j++)
		{
			recycled = recycled.substr(recycled.length() - 1, 1) + recycled.substr(0, recycled.length() - 1);
			if (stringToInt(recycled) > currentLow
				&& stringToInt(recycled) <= upper)
			{
				result++;
			}
		}
	}
	return result;
}