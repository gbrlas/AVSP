#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	cout.precision(7);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);


	string line;
	ifstream myfile ("B-small-attempt3.in");
	ofstream outfile ("B-small.out");
	// ofstream outfile ("A.out");

	outfile.precision(7);
	outfile.setf(ios::fixed);
	outfile.setf(ios::showpoint);
	
	if (myfile.is_open() && outfile.is_open())
	{

		
		
		getline(myfile, line);

		int numTest;
		numTest = atoi(line.c_str());


		for (int i = 0; i < numTest; i++)
		{			

			double C, F, X;

			getline(myfile, line);

			int posLine = 0;

			for (int k = 0; k < 3; k++) //separar os itens
			{
				string itemLido;

				if (line.at(posLine) == ' ')
				{
					posLine++;
				}

				while(line.at(posLine) != ' ') //enquanto o char for != " "
				{

					itemLido += line.at(posLine);

					// cout << itemLido << " _" ;
					
					posLine++;

					if (posLine == line.size())
					{

						break;
					}
				}

				if (k == 0)
				{
					C = atof(itemLido.c_str());
				}
				else if (k == 1)
				{
					F = atof(itemLido.c_str());
				}
				else if (k == 2)
				{
					X = atof(itemLido.c_str());
				}


				

			}

			double rate = 2;


			double melhorTempo = (X  ) / rate;
			double tempoFazenda = 0;
			double tempoEncontrado = 0 ;

			double tempo = 0;


			while(melhorTempo > tempoEncontrado){

				tempoFazenda += C / (rate );

				rate += F;

				tempoEncontrado = (X ) / (rate);

				tempoEncontrado += tempoFazenda;
				


				if (melhorTempo > tempoEncontrado)
				{
					melhorTempo = tempoEncontrado;
					tempoEncontrado = 0;
				}

			}
					
			
			outfile << "Case #" << i + 1 << ": " << melhorTempo << endl;


		} 

	

	}

	myfile.close();
	outfile.close();

	return 0;
}