// try.cpp : Defines the entry point for the console application.
//

#include<math.h>
#include<stdio.h>
#include<iostream> 

using namespace std;

void findpathandlabel(char *start,int matrix[][101],char label[][101],int row,int col,int i,int j);

void getthesmallestneighbour(int matrix[][101],int row,int col,int i,int j,int *ni,int* nj)
{
	int min=matrix[i][j];
	int elem = matrix[i][j];
	*ni = *nj =-1;
	
	if((i-1)>=0 && matrix[i-1][j]<min)
	{ min = matrix[i-1][j]; *ni = i-1;*nj = j; }

	if((j-1)>=0 && matrix[i][j-1]<min)
	{ min = matrix[i][j-1]; *ni = i;*nj = j-1; }

	if((j+1)<col && matrix[i][j+1]<min)
	{ min = matrix[i][j+1]; *ni = i;*nj = j+1; }

	if((i+1)<row && matrix[i+1][j]<min)
	{ min = matrix[i+1][j]; *ni = i+1;*nj = j; }


}	



void calculate(int matrix[][101],char label[][101],int row,int col)
{
		char start = 'a'-1;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(label[i][j] == '-')
				{
					findpathandlabel(&start,matrix,label,row,col,i,j);
				}
			}
		}
}
	
void findpathandlabel(char *start,int matrix[][101],char label[][101],int row,int col,int i,int j)
{
	int ni = -1,nj = -1;
	int endi=i,endj=j;
	getthesmallestneighbour(matrix,row,col,i,j,&ni,&nj);
	
	while((ni!= -1 && nj!= -1))
	{
		endi = ni;endj= nj;
		if(label[endi][endj]!='-')  break;
		getthesmallestneighbour(matrix,row,col,endi,endj,&ni,&nj);
	}

	if(ni == -1 && nj == -1)
	{
			(*start)++;
			int starti= i,startj =j;
			while(starti!=endi || startj!=endj)
			{
				label[starti][startj] = *start;
				getthesmallestneighbour(matrix,row,col,starti,startj,&starti,&startj);
			}
			label[starti][startj] = *start;
	}
	else
	{
		char labelvalue = label[endi][endj];
		int starti= i,startj =j;
		while(starti!=endi || startj!=endj)
		{
			label[starti][startj] = labelvalue;
			getthesmallestneighbour(matrix,row,col,starti,startj,&starti,&startj);
		}
	}
}
				
int main(int argc,char* argv[])
{
	int noofinputs,row,col,value;
	cin>>noofinputs;
	
	for(int i=0;i<noofinputs;i++)
	{
		cin>>row;
		cin>>col;
		int matrix[101][101];
		char label[101][101];
		for(int j=0;j<row;j++)
			for(int k=0;k<col;k++)
			{
				cin>>value;
				matrix[j][k] = value;
				label[j][k] = '-';
			}
		calculate(matrix,label,row,col);
		cout<<"Case #"<<i+1<<":"<<endl;
		for(int j=0;j<row;j++)
		{
			for(int k=0;k<col;k++)
			{
				cout<<label[j][k]<<" ";
			}
			cout<<endl;
		}
	}	
	return 0;
}


