#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <list>
#include <atlimage.h>

using namespace std;


/*typedef struct point
{
	int x;
	int y;
} POINT;
*/


typedef pair<POINT,BYTE> Sink;

bool operator<(const POINT& s1, const POINT& s2)
{
	if(s1.x < s2.x)
		return true;
	else if(s1.x == s2.x)
		return (s1.y < s2.y);
	else
		return false;
}

typedef map<POINT,BYTE> Pound;

void flow_water(CImage &altitud_map,CImage& water_map,int x,int y,BYTE& label,Pound &pound)
{
	BYTE north = 255;
	BYTE east = 255;
	BYTE west = 255;
	BYTE south = 255;
	BYTE center = 0;
	BYTE minor = 0;
	BYTE water_cell;
	int dir; //1 north 2 west 3 east 4 south 0 none
	POINT point;

	if(x>=0 && y>=0 && x<altitud_map.GetWidth() && y<altitud_map.GetHeight())
	{
		center = altitud_map.GetPixel(x,y);
		water_cell = water_map.GetPixel(x,y);
		if((water_cell < label) && (water_cell != COLORREF(0)))
			label = water_cell;
		point.x = x;
		point.y = y;
		pound.insert(Sink(point,label));
	}
	else
		return;
	if((y-1)>=0 && x>=0 && x<altitud_map.GetWidth() && (y-1)<altitud_map.GetHeight())
		north = altitud_map.GetPixel(x,y-1);
	if(y>=0 && (x+1)>=0 && (x+1)<altitud_map.GetWidth() && y<altitud_map.GetHeight())
		east = altitud_map.GetPixel(x+1,y);
	if((x-1)>=0 && y>=0 && (x-1)<altitud_map.GetWidth() && y<altitud_map.GetHeight())
		west = altitud_map.GetPixel(x-1,y);
	if((y+1)>=0 && x>=0 && x<altitud_map.GetWidth() && (y+1)<altitud_map.GetHeight())
		south = altitud_map.GetPixel(x,y+1);
	minor = center;
	dir = 0;
	if(north<minor)
	{
		dir = 1;
		minor = north;
	}
	if(west<minor)
	{
		dir = 2;
		minor = west;
	}
	if(east<minor)
	{
		dir = 3;
		minor = east;
	}
	if(south<minor)
	{
		dir = 4;
		minor = south;
	}
	switch(dir)
	{
		case 1:flow_water(altitud_map,water_map,x,y-1,label,pound);
			break;
		case 2:flow_water(altitud_map,water_map,x-1,y,label,pound);
			break;
		case 3:flow_water(altitud_map,water_map,x+1,y,label,pound);
			break;
		case 4:flow_water(altitud_map,water_map,x,y+1,label,pound);
			break;
		default:break;
	}
}


int main()
{
	int i,j,k,num_total_cases;
	int H,W;
	BYTE label,previous_label;
	unsigned cell;
	CImage altitud_map;
	CImage water_map;
	COLORREF water_cell;
	Pound pound;
	map<POINT,BYTE>::iterator it;
			
	FILE *inFile,*outFile;
	
	if( (inFile  = fopen( "B-small.in", "r" )) == NULL )
	  printf( "The file 'data' was not opened\n" );
	else
	  printf( "The file 'data' was opened\n" );
	
	if( (outFile  = fopen( "B-small.out", "w" )) == NULL )
	  printf( "The file 'data' was not opened\n" );
	else
	  printf( "The file 'data' was opened\n" );

	fscanf(inFile,"%d",&num_total_cases);
	//printf("%d Num Cases \n",num_total_cases);

	for(k=0;k<num_total_cases;k++)
	{
		fscanf(inFile,"%d %d",&H,&W);

		if(!altitud_map.IsNull())
			altitud_map.Destroy();
		if(!water_map.IsNull())
			water_map.Destroy();
		
		altitud_map.Create(W,H,32);
		water_map.Create(W,H,32);

		label = 1;

		for(i=0;i<H;i++)
		{
			for(j=0;j<W;j++)
			{
				fscanf(inFile,"%u",&cell);
				altitud_map.SetPixel(j,i,COLORREF(cell));
			}
		}

		for(i=0;i<H;i++)
		{
			for(j=0;j<W;j++)
			{
				water_cell = water_map.GetPixel(j,i);
				pound.clear();
				if(water_cell == COLORREF(0))
				{
					previous_label = label;
					flow_water(altitud_map,water_map,j,i,label,pound);
					for(it=pound.begin();it != pound.end();it++)
					{ 
						water_map.SetPixel(it->first.x,it->first.y,label);
					}
					if(previous_label == label)
						label = label + 1;
					else
						label = previous_label;
				}
			}
		}
		//printf("Case #%d:\n",k+1);
		fprintf(outFile,"Case #%d:\n",k+1);

		for(i=0;i<H;i++)
		{
			for(j=0;j<W;j++)
			{
				//printf("%u ",unsigned(water_map.GetPixel(j,i)));
				fprintf(outFile,"%c ",char(water_map.GetPixel(j,i)+96));
			}
			printf("\n");
			fprintf(outFile,"\n");
		}
				
		
	}
	fclose(inFile);
	fclose(outFile);
	
	return 1;
}
