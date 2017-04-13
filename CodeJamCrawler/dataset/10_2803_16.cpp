#include <iostream>
#include <fstream>
using namespace std;

#define INPUT_PATH "Bacteria.inp"
#define OUTPUT_PATH "Bacteria.out"


int C,R;
int map[101][101];
int mapSizeX,mapSizeY;


void main()
{
	ifstream input;
	input.open(INPUT_PATH);

	ofstream output;
	output.open(OUTPUT_PATH);
	input >> C;
	for (int i=0; i< C; i++)
	{
		input >> R;
		mapSizeX = 0;
		mapSizeY = 0;
		int a,b,c,d;
		for (int j=0; j<R; j++)
		{
			input >> a >> b >> c >> d;
			for (int k =b; k < d+1; k++)
				for (int l=a; l<c+1; l++)
					map[k][l] = 1;
			if (a>mapSizeX) mapSizeX = a;
			if (c>mapSizeX) mapSizeX = c;
			if (b>mapSizeY) mapSizeY = b;
			if (d>mapSizeY) mapSizeY = d;
		}
		bool die = false;
		int count = 0;
		while (!die)
		{
			die = true;
			for (int x = mapSizeY; x>0; x--)
				for (int y=mapSizeX; y>0; y--)
				{
					if (map[x][y] == 1 && map[x-1][y] != 1 && map[x][y-1]!=1)
					{
						map[x][y] =0;
						die = false;
					}
					if (map[x][y] != 1 && map[x-1][y] == 1 && map[x][y-1]==1)
					{
						map[x][y] =1;
						die = false;
					}
				}
			if (!die) count ++;
		}
		output << "Case #" << i+1<< ": " << count << endl;

	}
	input.close();
	output.close();

}