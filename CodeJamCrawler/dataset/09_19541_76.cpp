#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct CellNode
{
	char Basin;
	int Altitude;
	int NeighPres[4] ;//North , West, East, South
	struct CellNode *Neigh[4];//address of negithbours.
};
void SpreadCell(struct CellNode *, int );

void OutFlow(struct CellNode *Cell, char BasinValue)
{
	int FlowRef;
	FlowRef = LowDirection(Cell);
	if(FlowRef == -1)
		return;

	if(Cell->Neigh[FlowRef]->Basin == 0 )
	{
		Cell->Neigh[FlowRef]->Basin = BasinValue;
		SpreadCell(Cell->Neigh[FlowRef],BasinValue);
	}
}


void InFlow(struct CellNode *Cell, char BasinValue)
{
	int i;
	int FlowRef;
	for(i=0;i<4;i++)
	{
		if(Cell->NeighPres[i] != 1)
			continue;
		
		if(Cell->Neigh[i]->Basin == 0)
		{
			FlowRef = LowDirection(Cell->Neigh[i]);
			if(FlowRef == -1)
				continue;

			if(Cell == Cell->Neigh[i]->Neigh[FlowRef])
			{
				Cell->Neigh[i]->Basin = BasinValue;
				SpreadCell(Cell->Neigh[i],BasinValue);
			}

		}
	}
}

void SpreadCell(struct CellNode *Cell, char BasinValue)
{
	OutFlow(Cell, BasinValue);
	InFlow(Cell, BasinValue);
}

int LowDirection(struct CellNode *Cell)
{
	int i, shortest, ref;
	shortest = Cell->Altitude;
	ref = -1;
	
	for(i=0;i<4;i++)
	{
		if(Cell->NeighPres[i] == 1)
		{
			if(Cell->Neigh[i]->Altitude < shortest)
			{

				shortest = Cell->Neigh[i]->Altitude;
				ref = i;
			}
		}
	}
	return ref;
}

void Aware(struct CellNode Cells[100][100], int H, int W)
{
	int i,j;
	int northI, westJ, eastJ, southI;
			//Make each cell aware of neighbouring cell.
		
		for(i=0;i<H;i++)
		{
			for(j=0;j<W;j++)
			{
				northI = i-1;
				westJ = j - 1;
				eastJ = j + 1;
				southI = i+ 1;
				
				if (northI >= 0 )
				{
					Cells[i][j].NeighPres[0] = 1;
					Cells[i][j].Neigh[0] = &(Cells[northI][j]) ;
				}

				if(westJ >= 0)
				{
					Cells[i][j].NeighPres[1] = 1;
					Cells[i][j].Neigh[1] = &(Cells[i][westJ]) ;
				}

				if(eastJ < W)
				{
					Cells[i][j].NeighPres[2] = 1;
					Cells[i][j].Neigh[2] = &(Cells[i][eastJ]) ;
				}

				if(southI < H)
				{
					Cells[i][j].NeighPres[3] = 1;
					Cells[i][j].Neigh[3] = &(Cells[southI][j]) ;
				}

			}
		}
}

void main()
{
	FILE *fpIn, *fpOut;
	char Tempchar, BasinValue;
	int FlowRef;
	
	int H,W, i,j,k,num;
	
	struct CellNode Cells[100][100];

	fpIn = fopen("B-large.in","r");
	if(fpIn==0)
	{
		puts("Cannot Open file.");
		getche();
		exit();
	}

	fpOut = fopen("Large-WaterSheds-Output.in","w");
	if(fpOut ==0)
	{
		puts("Cannot Open file.");
		getche();
		exit();
	}

	fscanf(fpIn,"%d%c",&num,&Tempchar);
	for(i=1;i<=num;i++)
	{
		fscanf(fpIn,"%d%c%d%c",&H,&Tempchar,&W,&Tempchar);
		//Fill Values in each Cell
		for(j=0;j<H;j++)
		{
			for(k=0;k<W;k++)
			{
				fscanf(fpIn, "%d%c",&(Cells[j][k].Altitude),&Tempchar );
				Cells[j][k].Basin = 0;
				Cells[j][k].NeighPres[0] = 0;//assume no flow to North
				Cells[j][k].NeighPres[1] = 0;//no flow to west
				Cells[j][k].NeighPres[2] = 0;//no flow to east
				Cells[j][k].NeighPres[3] = 0;//no flow to south
			}
		}

		Aware(Cells, H,W);
		
		

		BasinValue = 'a';
		
		
		for(j=0;j<H;j++)
		{
			for(k=0;k<W;k++)
			{
				if(Cells[j][k].Basin == 0)
				{
					Cells[j][k].Basin = BasinValue;
					SpreadCell(&(Cells[j][k]), BasinValue);
					BasinValue++;
				}
			}
		}

	fprintf(fpOut,"%s%d%c\n","Case #",i,':');
	for(j=0;j<H;j++)
	{
		for(k=0;k<W;k++)
		{
			fputc(Cells[j][k].Basin ,fpOut);
			fputc(' ',fpOut);
		}
		fputc('\n',fpOut);
	}

	}//Case LOOP

	
	


	fclose(fpIn);
	fclose(fpOut);
	printf("Done.");
	getche();
}
