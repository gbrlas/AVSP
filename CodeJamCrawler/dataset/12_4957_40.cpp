/*
 * problem-c_main.cpp
 *
 *  Created on: Apr 14, 2012
 *      Author: Robert
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <map>

using namespace std;

int numOfDigits(int num);

int main(int argc, char **argv)
{
	if(argc <= 2)
	{
		cout << "Usage: ./problem-c <input file> <output file>" << endl;
		return -1;
	}

	string defaultInputDir = "ProblemC/inputs/";
	string defaultOutputDir = "ProblemC/outputs/";

	string inputFilename = defaultInputDir + argv[1], outputFilename = defaultOutputDir + argv[2], line;
	ifstream inputFile(inputFilename.c_str());
	ofstream outputFile(outputFilename.c_str());

	int T, A, B, n, m, counter = 0;

	if(inputFile.is_open())
	{
		if(inputFile.good())
		{
			getline(inputFile, line);
			T = atoi(line.c_str());
			cout << "T: " << T << endl;

			for(int i = 0; i < T; i++)
			{
				getline(inputFile, line);
//				cout << line << endl;

				stringstream ss1(line);
				ss1 >> A >> B;

				int bufferLength = numOfDigits(A) * 2 + 1;
				char buffer[bufferLength];
				memset(buffer, 0, bufferLength);

				map<string, int> map;

				for(int n = A; n <= B; n++)
				{
					// if only 1 digit in i, we can simply skip
					if(numOfDigits(n) == 1)
						continue;

					stringstream ss;
					ss << n;
					string number = ss.str();

					for(int j = 1; j <= number.length() - 1; j++)
					{
						string aString = number.substr(number.length() - j) + number.substr(0, number.length() - j);

						if(aString[0] == '0')
						{
							continue;
						}

						m = atoi(aString.c_str());
						if(n < m && m <= B)
						{
							sprintf(buffer, "%d%d", n, m);
							string s(buffer);

							// only increment counter at null - to avoid duplicate
							if(map[s] == 0)
							{
								map[s] = 1;
								counter++;
							}
						}
					}
				}

//				cout << "Counter: " << counter << endl;
				if(outputFile.is_open())
				{
					outputFile << "Case #" << i + 1 << ": " << counter << endl;
				}

				counter = 0;
			}
		}

		inputFile.close();
	}

	return 0;
}

int numOfDigits(int num)
{
	return (int) num / 10 + 1;
}
