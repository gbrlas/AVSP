//** Testing file

#include <iostream>

#include "Utility.h"
#include <time.h>

int main(int argc, char* argv[])
{
time_t ltime_start;
time( &ltime_start );
std::cout << ltime_start << std::endl;
	//Assume the input file name as "Input_1.txt"
	//char *FilePath = "input_sample.txt";
	char *FilePath = "A-small-attempt0.in";
	//char *FilePath = "input_large.txt";
	//Read the input file
	FileParser parser;
	parser.Parse(FilePath);

	//Get the result
	Algorithm algo(parser);
	FileWriter writer(parser.N);
	int i = 0;
	int MatchingWords;
	for (i = 0; i < parser.N; i++)
	{
		algo.GetMatchingWordCount(parser.ppTestCases[i], MatchingWords);
		writer.SetResult(i + 1, MatchingWords);
	}
	
	//Output the result
	writer.Write();

//std::cout<<"Hello Codejam!";
//char line[100];
//std::cin.getline(line, 100);
time_t ltime_end;
time( &ltime_end );
std::cout << ltime_end << std::endl;
std::cout << "Time taken: " << ltime_end - ltime_start << std::endl;
	return 0;
}

