/*
 * main.cpp
 *
 *  Created on: 12-04-2014
 *      Author: piotrek
 */

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>

class saperProblem
{
	int Rows;
	int Columns;
	int Mines;
public:
	void start()
	{
		int problemCount=0;
		std::cin>>problemCount;
		for(int i=0; i<problemCount; i++)
		{
			ReadInput();
			std::cout<<"Case #"<<i+1<<":"<<std::endl;
			if(false==Solve(Rows, Columns, Mines, 0, 0))
				std::cout<<"Impossible"<<std::endl;
		}
	}

    void ReadInput()
    {
    	std::cin>>Rows;
    	std::cin>>Columns;
    	std::cin>>Mines;
    }

    bool Solve(int Rows, int Columns, int Mines, int ignoredRows, int ignoredColumns)
    {
    	if( (this->Mines-(this->Rows*this->Columns) )==-1)
    	{
    		PrintWithOne();
    		return true;
    	}
    	//std::cout<<Rows<<" "<<Columns<<" "<<Mines<<std::endl;
    	if( RectangularSolve(Rows, Columns, Mines, ignoredRows, ignoredColumns) )
    		return true;
    	if ( Rows>2 && Solve(Rows-1, Columns, Mines-Columns, ignoredRows+1, ignoredColumns) )
    		return true;
    	if ( Columns>2 && Solve(Rows, Columns-1, Mines-Rows, ignoredRows, ignoredColumns+1 ) )
    		return true;
    	return false;
    }

    bool RectangularSolve(int Rows, int Columns, int Mines, int ignoredRows, int ignoredColumns)
    {
    	int rectRow=0;
    	int rectCol=0;
    	int addon=0;
    	if(Mines==0)
    		goto LoopOver;

    	for(rectRow=1; rectRow<=Rows-2; rectRow++)
		{
			for(rectCol=1; rectCol<=Columns-2; rectCol++)
			{
				if( Mines / (rectRow*rectCol) == 1 && Mines % (rectRow*rectCol) == 0)
				{
					goto LoopOver;
				}
				if( Mines / (rectRow*rectCol) == 1 && Mines % (rectRow*rectCol) == 1 && rectRow<=Rows-3)
				{
					addon=1;
					goto LoopOver;
				}
			}
		}
    	return false;

    	LoopOver: ;
    	Print(ignoredRows, ignoredColumns,rectRow, rectCol, addon);
    	return true;
    }
    void Print(int ignoredRows, int ignoredColumns, int rectRow, int rectCol, int addon)
    {
    	std::string Out[Rows];

    	for(int i=0; i<ignoredRows; i++)
    		Out[i]=std::string(Columns, '*');
    	for(int i=ignoredRows; i<Rows; i++)
    	    Out[i]=std::string(ignoredColumns, '*')+std::string(Columns-ignoredColumns, '.');

    	for(int i=ignoredRows; i< ignoredRows+rectRow; i++)
    	{
    		for(int j=ignoredColumns; j< ignoredColumns+rectCol; j++)
    		{
    			Out[i][j]='*';
    		}
    	}
    	if(addon==1)
    	{
    		Out[ignoredRows+rectRow][ignoredColumns]='*';
    	}
    	Out[Rows-1][Columns-1]='c';

    	for(int i=0; i<Rows; i++)
    		std::cout<<Out[i]<<std::endl;
    }
    void PrintWithOne()
    {
    	std::string Out[Rows];
    	for(int i=0; i<Rows; i++)
    		Out[i]=std::string(Columns, '*');

    	Out[Rows-1][Columns-1]='c';
		for(int i=0; i<Rows; i++)
			std::cout<<Out[i]<<std::endl;
    }
};

int main(int argc, char **argv)
{
	saperProblem SP;
	SP.start();
	return 0;
}
