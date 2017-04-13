#include <fstream>
#include <vector>
using namespace std;

int main()
{
	int T;
	ifstream input("A-small-attempt0.in");
	ofstream output("output.txt");
	input >> T;
	for(int i = 0; i < T; i++)
	{
		int cards1[4], cards2[4];
		vector<int> possiblecards;
		int row;
		input >> row;
		for(int j = 0; j < 4; j++)
		{
			int temp;
			if(j == row - 1) input >> cards1[0] >> cards1[1] >> cards1[2] >> cards1[3];
			else input >> temp >> temp >> temp >> temp;
		}
		input >> row;
		for(int j = 0; j < 4; j++)
		{
			int temp;
			if(j == row - 1) input >> cards2[0] >> cards2[1] >> cards2[2] >> cards2[3];
			else input >> temp >> temp >> temp >> temp;
		}
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++)
				if(cards1[j] == cards2[k]) possiblecards.push_back(cards1[j]);
		output << "Case #" << i + 1 << ": ";
		if(possiblecards.size() == 0) output << "Volunteer cheated!";
		else if(possiblecards.size() > 1) output << "Bad magician!";
		else output << possiblecards[0];
		output << '\n';
	}
	input.close();
	output.close();
	return 0;
}
