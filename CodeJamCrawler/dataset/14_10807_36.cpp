#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{


	string line;
	ifstream myfile ("A-small-attempt2.in");
	ofstream outfile ("A-small.out");
	
	if (myfile.is_open() && outfile.is_open())
	{
		
		getline(myfile, line);

		int numTest;
		numTest = atoi(line.c_str());


		for (int i = 0; i < numTest; i++)
		{

			int possiveis[4];
		 	
		 	for (int j = 0; j < 2; j++)
		 	{
		 		int cards[4][4];

		 		getline(myfile, line);
		 		int resp;

		 		resp = atoi(line.c_str());

		 		for (int k = 0; k < 4; k++)
		 		{
		 			getline(myfile, line);

		 			int posLine = 0;

		 			for (int l = 0; l < 4; l++)
		 			{

		 				string itemLido;

		 				if (line.at(posLine) == ' ')
						{
							posLine++;
						}

						while(line.at(posLine) != ' ') 
						{

							itemLido += line.at(posLine);
							
							posLine++;

							if (posLine == line.size())
							{
								break;
							}
						}
		 				
		 				cards[k][l] = atoi(itemLido.c_str());
		 			}
		 		}

		 		if (j == 0)
		 		{
		 			for (int l = 0; l < 4; l++)
			 		{

			 			possiveis[l] = cards[resp-1][l];

			 			
			 		}

		 		}
		 		else{

					for (int l = 0; l < 4; l++)
			 		{

			 			int temIgual = 0;

			 			for (int k = 0; k < 4; k++)
			 			{
			 				if (possiveis[l] == cards[resp-1][k])
				 			{
				 				temIgual++;
				 				break;
				 			}
			 			}

			 			if (temIgual == 0)
			 			{
			 				possiveis[l] = 0;
			 			}

			 			

			 		}

		 		}
		 		



		 	}


		 	int qtdCards = 0, position;

		 	for (int l = 0; l < 4; l++)
	 		{
	 			// cout << possiveis[l] << " ";	

	 			if (possiveis[l] != 0)
	 			{
	 				qtdCards++;



	 				if (qtdCards == 1)
	 				{
	 					position = l;
	 				}
	 			}

	 		}

	 		if (qtdCards > 1)
	 		{
	 			outfile << "Case #" << i+1 << ": Bad magician!" << endl;
	 		}
	 		else if (qtdCards == 0)
	 		{
	 			outfile << "Case #" << i+1 << ": Volunteer cheated!" << endl;
	 		}
	 		else {
	 			outfile << "Case #" << i+1 << ": " << possiveis[position] << endl;
	 		}


		} 

	

	}

	myfile.close();
	outfile.close();

	return 0;
}