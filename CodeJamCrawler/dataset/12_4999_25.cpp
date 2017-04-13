#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int T = 0;
	const int MAX_CHARS = 101;
	char letter[MAX_CHARS];
	ifstream input;
	ofstream output;
	// Open input file
	input.open("Input.txt");
	output.open("Output.txt");

	input >> T;
	input.ignore(numeric_limits<streamsize>::max(), '\n' );

	for (int i = 0; i < T; i++)
	{
		input.getline(letter, MAX_CHARS, '\n');
		output << "Case #" << i+1 << ": ";
		for (int i = 0; i < MAX_CHARS; i++)
		{
			if (letter[i] == ' ')
				output << ' ';
			else if (letter[i] == 'a')
				output << 'y';
			else if (letter[i] == 'b')
				output << 'h';
			else if (letter[i] == 'c')
				output << 'e';
			else if (letter[i] == 'd')
				output << 's';
			else if (letter[i] == 'e')
				output << 'o';
			else if (letter[i] == 'f')
				output << 'c';
			else if (letter[i] == 'g')
				output << 'v';
			else if (letter[i] == 'h')
				output << 'x';
			else if (letter[i] == 'i')
				output << 'd';
			else if (letter[i] == 'j')
				output << 'u';
			else if (letter[i] == 'k')
				output << 'i';
			else if (letter[i] == 'l')
				output << 'g';
			else if (letter[i] == 'm')
				output << 'l';
			else if (letter[i] == 'n')
				output << 'b';
			else if (letter[i] == 'o')
				output << 'k';
			else if (letter[i] == 'p')
				output << 'r';
			else if (letter[i] == 'q')
				output << 'z';
			else if (letter[i] == 'r')
				output << 't';
			else if (letter[i] == 's')
				output << 'n';
			else if (letter[i] == 't')
				output << 'w';
			else if (letter[i] == 'u')
				output << 'j';
			else if (letter[i] == 'v')
				output << 'p';
			else if (letter[i] == 'w')
				output << 'f';
			else if (letter[i] == 'x')
				output << 'm';
			else if (letter[i] == 'y')
				output << 'a';
			else if (letter[i] == 'z')
				output << 'q';
			letter[i] = '0';
		}
		output << endl;
	}
	input.close();
	output.close();

	return 0;
}