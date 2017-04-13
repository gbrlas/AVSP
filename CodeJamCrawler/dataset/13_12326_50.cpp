#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
static fstream ofile("A1_result",ios::app);
static string status[4] = {"X won","O won","Draw","Game has not completed"};  


char compute_score(char** chess,int &empty)
{
	char obj;
	for(int row= 0; row< 4; row++)   //row
	{
		obj = chess[row][0];
		if(obj == '.')
		{
			empty = 1;
			continue;
		}
		int count = 0;
		if(chess[row][0]==obj||chess[row][0]=='T')
			count++;
		else if(chess[row][0] == '.')
		{
			empty = 1;
			continue;
		}
		if(chess[row][1]==obj||chess[row][1]=='T')
			count++;
		else if(chess[row][1] == '.')
		{
			empty = 1;
			continue;
		}
		if(chess[row][2]==obj||chess[row][2]=='T')
			count++;
		else if(chess[row][0] == '.')
		{
			empty = 1;
			continue;
		}
		if(chess[row][3]==obj||chess[row][3]=='T')
			count++;
		else if(chess[row][0] == '.')
		{
			empty = 1;
			continue;
		}

		if(count == 4)
		{
			return obj;
		}
	}
	for(int col= 0; col< 4; col++)   //col
	{
		obj = chess[0][col];
		if(obj == '.')
			continue;
		int count = 0;
		if(chess[0][col]==obj||chess[0][col]=='T')
			count++;
		if(chess[1][col]==obj||chess[1][col]=='T')
			count++;
		if(chess[2][col]==obj||chess[2][col]=='T')
			count++;
		if(chess[3][col]==obj||chess[3][col]=='T')
			count++;
		if(count == 4)
		{
			return obj;
		}
	}

	obj = chess[0][0];
	if(obj != '.')
	if((chess[0][0]==obj||chess[0][0]=='T')
		&&(chess[1][1]==obj||chess[1][1]=='T')
		&&(chess[2][2]==obj||chess[2][2]=='T')
		&&(chess[3][3]==obj||chess[3][3]=='T'))
	{
		return obj;
	}

	obj = chess[0][3];
	if(obj != '.')
	if((chess[0][3]==obj||chess[0][3]=='T')
		&&(chess[1][2]==obj||chess[1][2]=='T')
		&&(chess[2][1]==obj||chess[2][1]=='T')
		&&(chess[3][0]==obj||chess[3][0]=='T'))
	{
		return obj;
	}

	return 'N';
}

void output_result(char** chess , int case_count)
{
	int score_x = 0;
	int score_o = 0;
	int empty = 0;
	char obj = 'X';
	obj = compute_score(chess,empty);

	if(obj == 'X')
		ofile<<"Case #"<<case_count<<": "<<status[0]<<endl;
	else if(obj == 'O')
		ofile<<"Case #"<<case_count<<": "<<status[1]<<endl;
	else if(empty == 0)
		ofile<<"Case #"<<case_count<<": "<<status[2]<<endl;
	else
		ofile<<"Case #"<<case_count<<": "<<status[3]<<endl;
}


void main()
{
	FILE *fp;
	fp = fopen("A-small-attempt1.in","r");
	//fp = fopen("test.txt","r");
	int num_case;
	char N[5];
	fstream ifile ("A-small-attempt1.in",ios::in);
	ifile>>num_case;
	int case_count = 1;
	while(!feof(fp) || case_count<= num_case)
	{
		char **chess = new char*[4];
		for(int temp=0; temp < 4; temp++)
		{
			chess[temp] = new char[4];
		}
		fgets(N,5,fp);
		int count = 0;
		for(;count<4;count++)
		{
			fgets(chess[count],5,fp);
			//cout<<chess[count]<<endl;
			fgets(N,5,fp);
		}		
		output_result(chess,case_count);
		case_count++;

	}
	fclose(fp);
}
