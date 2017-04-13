//Problem Magic Trick 


#include<iostream>
#include<string>
#include<fstream> 
#include<stdio.h>
#include<cmath>


using namespace std; 

int main()
{
    string line;
    int numberoftc;
	ifstream myfile("C:\\Users\\Shrumang\\downloads\\a.in");
	ofstream myfileoutput("c:\\users\\shrumang\\downloads\\output.in");
	if(myfile.is_open())
	{
		myfile>>numberoftc; 
		int first_question,second_question, test_case_no =1; 
		int arr1[4][4],arr2[4][4];
		int answer;	
		
		while(myfile.good() && test_case_no<=numberoftc)
		{
			myfile>>first_question;
				
			for (int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					myfile>>arr1[i][j];	
				}
			}
			myfile>>second_question;
			for (int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					myfile>>arr2[i][j];
					cout<<arr2[i][j]<<" ";
				}
				cout<<"\n";
			}
			int count =0;
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{	
					if(arr1[first_question-1][i] == arr2[second_question-1][j])
					{
						count = count + 1; 
						answer = arr1[first_question-1][i];
					}
				}
			}
			if (count == 0)
			{
				myfileoutput<<"Case #"<<test_case_no<<": Volunteer cheated!\n";
			} 
			else if(count > 1)
			{
				myfileoutput<<"Case #"<<test_case_no<<": Bad magician!\n";
			}
			else 
			{
				myfileoutput<<"Case #"<<test_case_no<<": "<<answer<<"\n";
			}
	       
			test_case_no +=1;
		}
		myfile.close();
		myfileoutput.close();
    }
    return 0; 
} 

