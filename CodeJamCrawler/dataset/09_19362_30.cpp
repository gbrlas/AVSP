#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <list>
//#include <atlimage.h>

using namespace std;

int f_numJams(string main_text,string substring)
{
	char first_ch;
	int pos;
	int num_times = 0;
	if(substring.length() == 0 || main_text.length() == 0)
		return 0;
	first_ch = substring[0];
	if(substring.length() == 1)
	{
		substring = "";
	}
	else
		substring = substring.substr(1);
	while((pos = main_text.find(first_ch)) != -1 && pos<main_text.length())
	{
		if(substring.compare("") == 0)
			num_times++;
		if(pos < main_text.length()-1)
		{
			main_text = main_text.substr(pos+1);
			num_times = num_times + f_numJams(main_text,substring);
		}
		else
			main_text = "";
		num_times = num_times % 10000;
	}
	return num_times;
}


int main()
{
	int i,j,k,num_total_cases,num_times;

	char L[1000],letter;
	string L_s;
	
	FILE *inFile,*outFile;
	
	if( (inFile  = fopen( "C-small.in", "r" )) == NULL )
	  printf( "The file 'data' was not opened\n" );
	else
	  printf( "The file 'data' was opened\n" );
	
	if( (outFile  = fopen( "C-small.out", "w" )) == NULL )
	  printf( "The file 'data' was not opened\n" );
	else
	  printf( "The file 'data' was opened\n" );

	fscanf(inFile,"%d",&num_total_cases);
	fscanf(inFile,"%c",&letter);
	
	for(k=0;k<num_total_cases;k++)
	{ 
		num_times = 0;

		fscanf(inFile,"%c",&letter);
		i=0;
		L[i] = '\0';
		while(letter != '\n' || letter == 'EOF')
		{
			L[i] = letter;
			i++;
			fscanf(inFile,"%c",&letter);
		}
		L[i] = '\0';

		L_s = L;

		num_times = f_numJams(L_s,"welcome to code jam");

		fprintf(outFile,"Case #%d: ",k+1);
		if(num_times<1000)
			fprintf(outFile,"0"); 
		if(num_times<100)
			fprintf(outFile,"0"); 
		if(num_times<10)
			fprintf(outFile,"0");
		fprintf(outFile,"%d\n",num_times);
	}
	fclose(inFile);
	fclose(outFile);
	
	return 1;
}
