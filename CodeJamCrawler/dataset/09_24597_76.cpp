
#include <fstream>
#include <iostream>

using namespace std;

bool getShortestNeighbour (int **inputarr, int height, int width, int x, int y, int &nx, int &ny)
{
	bool flag = false;
	int max = 0;
	int minx = -1, miny = -1;

	if (x > 0)
	{
		if ((inputarr[x][y] - inputarr[x - 1][y]) > max)
		{
			flag = true;
			max = inputarr[x][y] - inputarr[x - 1][y];
			minx = x-1; miny = y;
		}		
	}

	if (y > 0)
	{
		if ((inputarr[x][y] - inputarr[x][y - 1]) > max)
		{
			flag = true;
			max = inputarr[x][y] - inputarr[x][y - 1];
			minx = x; miny = y-1;
		}		
	}

	if (y < width - 1)
	{
		if ((inputarr[x][y] - inputarr[x][y + 1]) > max)
		{
			flag = true;
			max = inputarr[x][y] - inputarr[x][y + 1];
			minx = x; miny = y + 1;
		}
	}

	if (x < height - 1)
	{
		if ((inputarr[x][y] - inputarr[x + 1][y]) > max)
		{
			flag = true;
			max = inputarr[x][y] - inputarr[x + 1][y];
			minx = x+1; miny = y;
		}
	}
	
	nx = minx; ny = miny;
	return flag;

}
void CalculateMap (int **inputarr, char **outarr, int height, int width)
{
	char currentchar = 'a';

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (outarr[i][j] == '$')
			{				
				int m = i, n = j;
				int nm = 0, nn = 0;

				while (1)
				{					
					if (getShortestNeighbour (inputarr, height, width, m, n, nm, nn))
					{
						if (outarr[nm][nn] != '$')
						{
							outarr[i][j] = outarr[nm][nn];
							break;
						}
						else
						{
							m = nm; n = nn;
						}
					}
					else
					{
						outarr[i][j] = currentchar;
						outarr[m][n] = currentchar;
						currentchar ++;
						break;
					}
				}
			}
		}
	}
}

// entry point
int main (int argc, char *argv[])
{
	fstream infile("B-large.in", ios::in);
	fstream outfile("Output.txt", ios::out);

	int count = 0;
	int height = 0, width = 0;

	infile >> count;

	for (int iter = 0; iter < count; iter ++) 
	{
		infile >> height >> width;

		char **outarr = 0;
		int **inputarr = 0;

		outarr = new char*[height];
		inputarr = new int*[height];

		for (int i = 0; i < height; i++)
		{
			outarr[i] = new char[width];
			inputarr[i] = new int[width];
		}


		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++) 
			{
				infile >> inputarr[i][j];
				outarr[i][j] = '$';
			}
		}
		CalculateMap (inputarr, outarr, height, width);

		outfile << "Case #" << iter + 1<< ":" << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{				
				outfile << outarr[i][j];
				if (j < width-1)
					outfile << " ";
			}
			outfile << endl;
		}

	}

	outfile.close();
	infile.close();
}