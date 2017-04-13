#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
static fstream ofile("B_result",ios::app);
void output_result(int row, int col, int *p, int case_num)
{
	int *max_row = new int[row];
	int *max_col = new int[col];
	
	for(int i=0; i<row; i++)
	{
		int max = p[i*col];
		for(int j=0; j<col; j++)
		{
			if(max< p[i*col+j])
				max = p[i*col+j];
		}
		max_row[i] = max;
	}

	for(int i=0; i<col; i++)
	{
		int max = p[i];
		for(int j=0; j<row; j++)
		{
			if(max< p[j*col+i])
				max = p[j*col+i];
		}
		max_col[i] = max;
	}
	
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(p[i*col+j]<max_row[i]&&p[i*col+j]<max_col[j])
			{
				ofile<<"Case #"<<case_num<<": NO"<<endl;
				return;
			}
		}
	}
	ofile<<"Case #"<<case_num<<": YES "<<endl;
}


void main()
{
   
	fstream ifile("B-large.in",ios::in);
	int NUM = 0;         //the total number of  test cases
	int N = 1;        
	int M = 0;         

	ifile>>NUM;
	int case_count = 1;
	while(!ifile.eof() && case_count<= NUM)
	{
		int count = 0;
		ifile>>N;
		ifile>>M;
		int *p = new int[M*N];
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				ifile>>p[i*M+j];
			}
		}
		output_result(N,M,p,case_count);
		case_count++;
	}
}