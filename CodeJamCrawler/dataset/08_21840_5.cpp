/* 
 * File:   Train.cpp
 * Author: root
 *
 * Created on July 17, 2008, 7:01 PM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N; // Number Of Test Cases

int T[100]; //Turnaround time

int NA[100]; //Number Of Trips From A To B
int NB[100]; //Number Of Trips From B To A

int countTestCases; //To Count The Number Of Test Cases

int departureQA[100][100];
int arrivalQA[100][100];
int NTA[100]; //Number Of Trains From A

int departureQB[100][100];
int arrivalQB[100][100];
int NTB[100]; //Number Of Trains From A

void ReadInput();
void ProcessInput();
void WriteOutput();

int main()
{

    
	ReadInput();
	ProcessInput();
	WriteOutput();
	return 0;

}

void ReadInput()
{
	int temp, count = 0;
	ifstream indata; // indata is like cin
	indata.open("B-small-attempt0.in", ios::in); // opens the file
		
    if(!indata)
    {
		cerr << "Error: file could not be opened" << endl;
      		exit(1);
    }

	indata >> N;
	
	while ( countTestCases != N )
	{

		indata >> T[countTestCases];
		indata >> NA[countTestCases];
		indata >> NB[countTestCases];
		
		count = 0;

		
		while ( (!indata.eof()) && (count != NA[countTestCases]) )
		{
			indata >> temp;
			departureQA[countTestCases][count] = temp;
			indata >> temp;
			arrivalQB[countTestCases][count] = temp;
			count ++;
			
		}

		count = 0;
	
		while ( (!indata.eof()) && (count != NB[countTestCases]) )
		{
			indata >> temp;
			departureQB[countTestCases][count] = temp;
			indata >> temp;
			arrivalQA[countTestCases][count] = temp;
			count ++;
		}
		
		countTestCases ++;
		   
	}
    cout << "After Reading " << endl;   
    for(int i = 0; i != N; i++)
    {
            for(int j = 0; j != NA[i]; j++) 
                    cout << "Test Case ------>" << i+1 << "\t" <<"DepartureQA ------>" << departureQA[i][j]  << endl; 
    }
    for(int i = 0; i != N; i++)
    {
            for(int j = 0; j != NB[i]; j++) 
                    cout << "Test Case ------>" << i+1 << "\t" <<"DepartureQB ------>" << departureQB[i][j]  << endl; 
    }
        
    for(int i = 0; i != N; i++)
    {
            for(int j = 0; j != NB[i]; j++) 
                    cout << "Test Case ------>" << i+1 << "\t" <<"ArrivalQA ------>" << arrivalQA[i][j]  << endl; 
    }
    
    for(int i = 0; i != N; i++)
    {
            for(int j = 0; j != NA[i]; j++) 
                    cout << "Test Case ------>" << i+1 << "\t" <<"ArrivalQB ------>" << arrivalQB[i][j]  << endl; 
    }
    
}

void ProcessInput()
{
	int count = 0;
	
    for(int i = 0; i < N; i ++)
    {
                sort(departureQA[i], departureQA[i]+NA[i]);
        	sort(arrivalQA[i], arrivalQA[i]+ NB[i]);
        	sort(departureQB[i], departureQB[i]+NB[i]);
        	sort(arrivalQB[i], arrivalQB[i]+ NA[i]);
    }
        	
    cout << "After Sorting " << endl; 
    for(int i = 0; i < N; i++)
    {
            for(int j = 0; j < NA[i]; j++) 
                    cout << "Test Case ------>" << i+1 << "\t" <<"DepartureQA ------>" << departureQA[i][j]  << endl; 
    }
    for(int i = 0; i < N; i++)
    {
            for(int j = 0; j < NB[i]; j++) 
                    cout << "Test Case ------>" << i+1 << "\t" <<"DepartureQB ------>" << departureQB[i][j]  << endl; 
    }
        
    for(int i = 0; i < N; i++)
    {
            for(int j = 0; j < NB[i]; j++) 
                    cout << "Test Case ------>" << i+1 << "\t" <<"ArrivalQA ------>" << arrivalQA[i][j]  << endl; 
    }
    
    for(int i = 0; i < N; i++)
    {
            for(int j = 0; j < NA[i]; j++) 
                    cout << "Test Case ------>" << i+1 << "\t" <<"ArrivalQB ------>" << arrivalQB[i][j]  << endl; 
    }
	
	
	
    for( int TestCaseNum = 0; TestCaseNum != N; TestCaseNum ++)
    {
        int i = 0;
	    int j = 0;
        while( count != NA[TestCaseNum] )
    	{
    		count ++;
    		if((departureQA[TestCaseNum][i] < arrivalQA[TestCaseNum][j] + T[TestCaseNum]) || (arrivalQA[TestCaseNum][j] == 0))
    		{
    			NTA[TestCaseNum] ++;
    			i ++;
    			continue ;
    		}
    		else
    		{
    			j ++;
    			i ++;
    		}
    	}
        cout << "TestCase : " << TestCaseNum << "\t" << "NTA = " <<NTA[TestCaseNum] <<endl; 
    	count = i = j = 0;
    
    	while( count != NB[TestCaseNum] )
    	{
    		count ++;
    		if((departureQB[TestCaseNum][i] < (arrivalQB[TestCaseNum][j] + T[TestCaseNum])) || (arrivalQB[TestCaseNum][j] == 0))
    		{
    			NTB[TestCaseNum] ++;
    			i ++;
    			continue ;
    		}
    		else
    		{
    			j ++;
    			i ++;
    		}
    	}
    	cout << "TestCase : " << TestCaseNum << "\t" << "NTB = " <<NTB[TestCaseNum] << endl;
        count = 0;
     }
}

void WriteOutput()
{

	ofstream outdata;
	outdata.open("output.txt", ios::app);
	
	for(int i = 0; i < N; i++)
	{
            if( outdata.is_open())
        	{
        		outdata << "Case #" << i+1 << ":  " << NTA[i] << " " << NTB[i] << endl;
        	}
    }
	outdata.close();

}

