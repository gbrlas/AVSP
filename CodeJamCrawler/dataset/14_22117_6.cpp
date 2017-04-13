#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>

#define N 4

void inisMassive(int* iOMass)
{
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			std::cin >> iOMass[i*N + j];
		}
	}
}

int main()
{

	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);

	int countOfTests, string_number;
	
	std::cin >> countOfTests;
	
	int *inputMass;

	inputMass = new int[N*N];

	int *currentMass = new int[N];

	int matchCount = 0, find_number = 0;

	for(int i = 0; i < countOfTests; ++i)
	{
		matchCount = 0;

		std::cin >> string_number;
		inisMassive(inputMass);

		for(int j = 0; j < N; j++)
		{
			currentMass[j] = inputMass[(string_number-1)*N + j];
		}

		std::cin >> string_number;

		inisMassive(inputMass);

		for(int k = 0; k < N; ++k)
		{
			int findNumber = currentMass[k];

			for(int j = 0; j < N; j++)
			{
				if( findNumber == inputMass[(string_number-1)*N + j] )
				{
					matchCount++;
					find_number = findNumber;
					break;
				}
			}
		}

		if( matchCount == 1 )
			std::cout <<"Case #" << i+1 << ": "<< find_number<<std::endl;
		else if( matchCount > 1 )
			std::cout <<"Case #" << i+1 << ": "<< "Bad magician!"<<std::endl;
		else if( matchCount == 0 )
			std::cout <<"Case #" << i+1 << ": "<< "Volunteer cheated!"<<std::endl;
	}

	return 0;
}