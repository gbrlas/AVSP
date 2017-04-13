#include <fstream>
#include <string>
using namespace std;

char smallestLabel (int x, int y, int data[][100], char label[][100], int H, int W, int& ch)
{
	int smallest_x, smallest_y, smallest;

	smallest_x = x;
	smallest_y = y;
	smallest = data[x][y];

	if (y != 0)
	{
		if (data[x][y-1] < smallest)
		{
			smallest_x = x;
			smallest_y = y-1;
			smallest = data[x][y-1];
		}
	}

	if (x != 0)
	{
		if (data[x-1][y] < smallest)
		{
			smallest_x = x-1;
			smallest_y = y;
			smallest = data[x-1][y];
		}
	}

	if (x != W-1)
	{
		if (data[x+1][y] < smallest)
		{
			smallest_x = x+1;
			smallest_y = y;
			smallest = data[x+1][y];
		}
	}

	if (y != H-1)
	{
		if (data[x][y+1] < smallest)
		{
			smallest_x = x;
			smallest_y = y+1;
			smallest = data[x][y+1];
		}
	}

	if (smallest_x == x && smallest_y == y)
	{
		if (label[x][y] == 0)
		{
			label[x][y] = ch;
			ch++;
		}
	}
	else if (label[smallest_x][smallest_y] != 0)
	{
		label[x][y] = label[smallest_x][smallest_y];
	}
	else
	{
		label[x][y] = smallestLabel (smallest_x, smallest_y, data, label, H, W, ch);
	}

	return label[x][y];
}

int main ()
{
	// Generic File Instantiations
	ifstream input;
	ofstream output;
	
	string inputname, outputname;
	
	inputname = "watersheds_input.in";
	outputname = "watersheds_output.out";
	input.open (inputname.c_str ());
	output.open (outputname.c_str ());
	
	// Input Read & Initializations
	int T; // number of maps
	input >> T;

	int data_array[100][100];
	char label_array[100][100];
	int H, W, alt;
	int ch, x, y;

	// Read Maps
	for (int i = 1; i <= T; i++)
	{
		input >> H >> W;
		output << "Case #" << i << ":" << endl;

		ch = 'a';

		for (y = 0; y < H; y++)
		{
			for (x = 0; x < W; x++)
			{
				label_array[x][y] = 0;
			}
		}

		for (y = 0; y < H; y++)
		{
			for (x = 0; x < W; x++)
			{
				input >> alt;
				data_array[x][y] = alt;
			}
		}

		for (y = 0; y < H; y++)
		{
			for (x = 0; x < W; x++)
			{
				smallestLabel (x, y, data_array, label_array, H, W, ch);
			}
		}

		for (y = 0; y < H; y++)
		{
			for (x = 0; x < W; x++)
			{
				if (label_array[x][y] == 0)
				{
					label_array[x][y] = ch;
					ch++;
				}
			}
		}

		for (y = 0; y < H; y++)
		{
			for (x = 0; x < W; x++)
			{
				output << label_array[x][y] << " ";
			}
			output << endl;
		}
	}

	input.close();
	output.close();
	return 0;
}