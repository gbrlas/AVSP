#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

typedef std::vector< std::vector<int> > Table ;

class Trick {

private:
	int firstRow;
	int secondRow;

	std::vector<int> possibleCards;

	Table firstTable;
	Table secondTable;

public:

	//values passed in should be 0-based (-1 before passing)
	Trick(int firstRow, int secondRow, Table firstTable, Table secondTable) :
		firstRow(firstRow), secondRow(secondRow), firstTable(firstTable), secondTable(secondTable)
	{
		possibleCards = firstTable[firstRow];
		
		std::cout << toString();
	}

	Trick()
	{

	}

	std::string checkTheMagic()
	{
		int theCard = -1;
		bool isInRow = false;
		bool hasMultipleInRow = false;
		for (int i = 0; i < 4; ++i)
		{
			int currCard = secondTable[secondRow][i];
			//std::cout << "Current check: " << currCard;
			if (std::find(possibleCards.begin(), possibleCards.end(), currCard) != possibleCards.end())
			{
				if (!isInRow)
				{
					isInRow = true;
					theCard = currCard;
				}
				else
				{
					hasMultipleInRow = true;
				}
			}
		}
		if (!isInRow)
		{
			return "Volunteer cheated!";
		}
		else if (isInRow && hasMultipleInRow)
		{
			return "Bad magician!";
		}
		else
		{
			return std::to_string(theCard);
		}
	}

	std::string toString()
	{
		std::stringstream ss;
		ss << "First row: " << firstRow << std::endl;
		ss << "First table: " << std::endl;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				ss << firstTable[i][j] << " ";
			}
			ss << std::endl;
		}
		ss << std::endl;

		ss << "Second row: " << secondRow << std::endl;
		ss << "Second table: " << std::endl;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				ss << secondTable[i][j] << " ";
			}
			ss << std::endl;
		}
		ss << std::endl;
		return ss.str();
	}


};

int main()
{
	int numTricks;
	
	std::ofstream outputFile("output.txt");
	std::ifstream inputFile("actual.txt");
	std::string currLine;

	inputFile >> numTricks;
	std::vector<Trick> tricks;

	for (int i = 0; i < numTricks; i++)
	{
		int firstRow, secondRow;
		Table firstTable, secondTable;
		firstTable.resize(4);
		secondTable.resize(4);

		inputFile >> firstRow;
		for (int j = 0; j < 4; ++j)
		{
			firstTable[j].resize(4);
			for (int k = 0; k < 4; ++k)
			{
				inputFile >> firstTable[j][k];
			}
		}
		inputFile >> secondRow;
		for (int j = 0; j < 4; ++j)
		{
			secondTable[j].resize(4);
			for (int k = 0; k < 4; ++k)
			{
				inputFile >> secondTable[j][k];
			}
		}

		tricks.push_back( Trick(firstRow-1, secondRow-1, firstTable, secondTable));
	}
	inputFile.close();
	
	for (int i = 0; i < numTricks; ++i)
	{
		outputFile << "Case #" << i+1 << ": " << tricks[i].checkTheMagic() << std::endl;
	}

	outputFile.close();
}