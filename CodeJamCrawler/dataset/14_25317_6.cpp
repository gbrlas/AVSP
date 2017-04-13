#include "../../ZKR4X/lib/gstring.h"


int main()
{
	QFile fileIn("in.txt");

	if(!fileIn.open(QIODevice::ReadOnly)) return 1;

	GString in = QString(fileIn.readAll());
	fileIn.close();

	QFile fileOut("out.txt");
	if(!fileOut.open(QIODevice::WriteOnly | QIODevice::Truncate)) return 2;
	QTextStream out(&fileOut);

	int N, T, grid[4][4], answers[4];
	in >> N;

	for(int i = 1; i <= N; i++)
	{
		in >> T;
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++) {
			in >> grid[j][k];
		}

		int possibilities[4];
		memcpy(possibilities, grid[T-1], 16);

		in >> T;
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++) {
			in >> grid[j][k];
		}

		std::cout << possibilities[0] << " " << possibilities[1];
		
		int sol = -1;
		for(int j = 0; j < 4; j++) {
			for(int k = 0; k < 4; k++) {
				if(grid[T-1][j] == possibilities[k])
					if(sol == -1)
						sol = possibilities[k];
					else{
						sol = -2;
						j = 4;
						break;
					}
			}
		}
		out << "Case #" << i << ": ";
		if(sol == -2)
			out << "Bad magician!";
		else if(sol == -1)
			out << "Volunteer cheated!";
		else
			out << sol;
		out << "\n";

	}



	fileOut.close();
	

	return 0;
}
