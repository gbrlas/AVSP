#include <stdio.h>

//#include "DataTypes.h"

#define LF				0x0A	//Line Feed
#define SP				0x20	

#define HMAX	100
#define WMAX	100


//IMPORTANT! = Should not be unsigned
#define MAP_TYPE 	 int

#define HOME			row][col
#define NORTH_NEIGH		row-1][col
#define WEST_NEIGH		row][col-1
#define EAST_NEIGH		row][col+1
#define SOUTH_NEIGH		row+1][col


unsigned int totalMaps, mapHeight, mapWidth,  row, col, startNodeRow, startNodeCol, parsedNodesRow[HMAX*WMAX], parsedNodesCol[HMAX*WMAX], parsedNodesCtr;

MAP_TYPE mapData[HMAX][WMAX];

unsigned char mapLabel[HMAX][WMAX];


MAP_TYPE calcSmallest( MAP_TYPE, MAP_TYPE, MAP_TYPE, MAP_TYPE, int *);
void initMapLabels();

void vFileParseError()
{
	printf("\nFile Error!\n");
}



int main()
{	
	
	unsigned char ucInFileName[] = {"B-large.in"};
	unsigned char ucOutFileName[] = {"B-large.out"};
	
	FILE *pstInFile, *pstOutFile;

	pstInFile = fopen( ucInFileName, "r" );
	pstOutFile = fopen( ucOutFileName, "w" );


	//Counters
	unsigned int mapCtr = 0;
	
	MAP_TYPE smallestVal;
	
	unsigned char anotherSinkFound;
	
	int index, i;
	
	unsigned char nextChar, toBeAssigned;
	int row, col;



	//Read T
	fscanf( pstInFile, "%d", &totalMaps );
	
	if( fgetc(pstInFile) != LF )
	{
		vFileParseError();
		return 1;
	}
	
	//Start parsing maps
	while( mapCtr < totalMaps )
	{
		fscanf( pstInFile, "%d", &mapHeight );
		
		if( fgetc(pstInFile) != SP )
		{
			vFileParseError();
			return 1;
		}
		
		fscanf( pstInFile, "%d", &mapWidth );
		
		if( fgetc(pstInFile) != LF )
		{
			vFileParseError();
			return 1;
		}
		
		//Parse map data
		
		for( row = 0; row < mapHeight; row++ )
		{
			for( col = 0; col < mapWidth; col++ )
			{
				fscanf( pstInFile, "%d", &mapData[row][col] );
				fgetc( pstInFile );	// This will either be a space or a line-feed
			}
		}
		
		
		
		initMapLabels();
		
		nextChar = 'a';		
		
		//Processing the root start node - first row, first column
		
		
		for( startNodeRow = 0; startNodeRow < mapHeight; startNodeRow++ )
		{
			
			for( startNodeCol = 0; startNodeCol < mapWidth; startNodeCol++ )
			{
				row = startNodeRow, col = startNodeCol;
				
				anotherSinkFound = 0;
				parsedNodesCtr = 0;
				
				toBeAssigned = nextChar;				
				
				if( mapLabel[startNodeRow][startNodeCol] == 0 )	//if the start node is not already labelled
				{
					
					parsedNodesRow[0] = startNodeRow;
					parsedNodesCol[0] = startNodeCol;	
					parsedNodesCtr = 1;
					
					do
					{
						index = 4;	//default
						
						smallestVal = calcSmallest( 
												(row == mapHeight - 1 ? -1 : mapData[SOUTH_NEIGH]),
												(col == mapWidth - 1 ? -1 : mapData[EAST_NEIGH]), 
												(col == 0 ? -1 : mapData[WEST_NEIGH]), 
												(row == 0 ? -1 : mapData[NORTH_NEIGH]), 
												&index );
						if( smallestVal == -1 )
							break;
						
						if( smallestVal < mapData[HOME] )
						{
							anotherSinkFound = 1;
							if( index == 0 )	//south
							{
								if( mapLabel[SOUTH_NEIGH] != 0 )	//if label is already assigned
								{
									toBeAssigned = mapLabel[SOUTH_NEIGH];
									break;
								}
								else
								{
									row = row + 1;	//now, coordinates are changed to that of the South node
									
								}	
							}
							else if( index == 1 )	//east
							{	
								if( mapLabel[EAST_NEIGH] != 0 )	//if label is already assigned
								{
									toBeAssigned = mapLabel[EAST_NEIGH];
									break;
								}
								else
								{
									col = col + 1;	//now, coordinates are changed to that of the east node
									
								}
							}
							else if( index == 2 )	//west
							{
								if( mapLabel[WEST_NEIGH] != 0 )	//if label is already assigned
								{
									toBeAssigned = mapLabel[WEST_NEIGH];
									break;
								}
								else
								{
									col = col - 1;	//now, coordinates are changed to that of the west node
									
								}
							}
							else if( index == 3 )	//north
							{
								if( mapLabel[NORTH_NEIGH] != 0 )	//if label is already assigned
								{
									toBeAssigned = mapLabel[NORTH_NEIGH];
									break;
								}
								else
								{
									row = row - 1;	//now, coordinates are changed to that of the north node
									//hopefully, not possible
									
								}
							}
								
							parsedNodesRow[parsedNodesCtr] = row;
							parsedNodesCol[parsedNodesCtr] = col;
							parsedNodesCtr++;
						}
						else
						{
							anotherSinkFound = 0;	//no neighbour had a smaller elevation
						}
						
					} while( anotherSinkFound == 1 );
					
					for( i = 0; i < parsedNodesCtr; i++)
					{
						mapLabel[parsedNodesRow[i]][parsedNodesCol[i]] = toBeAssigned;
					}
					
					if( toBeAssigned == nextChar )
						nextChar++;
				}
			}
			
		}	
		
		fprintf( pstOutFile, "Case #%d:\n", mapCtr + 1 );
		
		for( row = 0; row < mapHeight; row++ )
		{
			for( col = 0; col < mapWidth; col++ )
			{
				fprintf( pstOutFile, "%c", mapLabel[row][col]);
				if( col != mapWidth - 1 )
					fprintf( pstOutFile, " ");

			}
			fprintf( pstOutFile, "\n");
		}
		
		mapCtr++;
	}


	
	
	fclose( pstOutFile );
	fclose( pstInFile );
		
	return  0;
}

MAP_TYPE calcSmallest( MAP_TYPE val0, MAP_TYPE val1, MAP_TYPE val2, MAP_TYPE val3, int *index)
{
	MAP_TYPE smallest = -1;
	
	if( val0 != -1 )
	{
		smallest = val0;		
		*index = 0;
	}
	else if( val1 != -1 )
	{
		smallest = val1;
		*index = 1;
	}
	else if( val2!= -1 )
	{
		smallest = val2;
		*index = 2;
	}
	else if (val3!=-1)	
	{
		*index = 3;
		return val3;
	}
	
	if( val1!=-1 && val1 <= smallest )
	{
		smallest = val1;
		*index = 1;
	}
	if( val2!=-1 && val2 <= smallest )
	{
		smallest = val2;
		*index = 2;
	}
	if( val3!=-1 && val3 <= smallest )
	{
		smallest = val3;
		*index = 3;
	}
	
	return smallest;
	
}

void initMapLabels()
{
	int i, j;
	
	for( i=0; i<mapHeight; i++)
		for( j = 0; j <mapWidth; j++)
			mapLabel[i][j] = 0;
}
