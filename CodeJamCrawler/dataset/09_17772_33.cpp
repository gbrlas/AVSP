#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned int uint;

const uint MAX_MAP_WIDTH = 100;
const uint MAX_MAP_HEIGHT = 100;
static uint altitudes[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];
static char basinLabels[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];
char curBasinLabel = 'a';
uint numMaps = 0;
uint mapWidth = 0;
uint mapHeight = 0;

char inspectCell(uint rowIndex, uint colIndex)
{
	if ( basinLabels[rowIndex][colIndex] == 0 )
	{	// Need to figure out cell label.
		uint lowerCellRowIndex = rowIndex;
		uint lowerCellColIndex = colIndex;
		uint lowestAltitude = altitudes[rowIndex][colIndex];
		
		// Check North neighbor.
		if ( rowIndex > 0 && altitudes[rowIndex - 1][colIndex] < lowestAltitude )
		{
			lowerCellRowIndex = rowIndex - 1;
			lowerCellColIndex = colIndex;
			lowestAltitude = altitudes[rowIndex - 1][colIndex];
		}

		// Check West neighbor.
		if ( colIndex > 0 && altitudes[rowIndex][colIndex - 1] < lowestAltitude )
		{
			lowerCellRowIndex = rowIndex;
			lowerCellColIndex = colIndex - 1;
			lowestAltitude = altitudes[rowIndex][colIndex - 1];
		}

		// Check East neighbor.
		if ( colIndex < mapWidth - 1 && altitudes[rowIndex][colIndex + 1] < lowestAltitude )
		{
			lowerCellRowIndex = rowIndex;
			lowerCellColIndex = colIndex + 1;
			lowestAltitude = altitudes[rowIndex][colIndex + 1];
		}

		// Check South neighbor.
		if ( rowIndex < mapHeight - 1 && altitudes[rowIndex + 1][colIndex] < lowestAltitude )
		{
			lowerCellRowIndex = rowIndex + 1;
			lowerCellColIndex = colIndex;
			lowestAltitude = altitudes[rowIndex + 1][colIndex];
		}
		
		if ( lowerCellRowIndex == rowIndex && lowerCellColIndex == colIndex )
		{	// No lower neighbor.  Cell is sink.
			basinLabels[rowIndex][colIndex] = curBasinLabel;
			curBasinLabel++;
		} else
		{	// Recurse to lower altitude neighbor.
			basinLabels[rowIndex][colIndex] = inspectCell(lowerCellRowIndex, lowerCellColIndex);
		}
	}
	
	return basinLabels[rowIndex][colIndex];
}

int main (int argc, char * const argv[]) 
{
	if ( argc != 2 ) return -1;
	
	ifstream fileIn(argv[1], ifstream::in);
	
	if ( fileIn.good() == false ) return -1;
		
	fileIn >> numMaps;
	
	for ( uint mapIndex = 0; mapIndex < numMaps; mapIndex++ )
	{
		curBasinLabel = 'a';
		fileIn >> mapHeight >> mapWidth;
		
		// Populate altitudes and clear labels.
		for ( uint rowIndex = 0; rowIndex < mapHeight; rowIndex++ )
		{
			for ( uint colIndex = 0; colIndex < mapWidth; colIndex++ )
			{
				fileIn >> altitudes[rowIndex][colIndex];
				basinLabels[rowIndex][colIndex] = 0;
			}
		}
		
		for ( uint rowIndex = 0; rowIndex < mapHeight; rowIndex++ )
		{
			for ( uint colIndex = 0; colIndex < mapWidth; colIndex++ )
			{
				inspectCell(rowIndex, colIndex);
			}
		}
		
		cout << "Case #" << mapIndex + 1 << ":" << endl;
		for ( uint rowIndex = 0; rowIndex < mapHeight; rowIndex++ )
		{
			for ( uint colIndex = 0; colIndex < mapWidth; colIndex++ )
			{
				cout << basinLabels[rowIndex][colIndex] << ' ';
			}
			cout << endl;
		}
	}
	
	fileIn.close();
    return 0;
}
